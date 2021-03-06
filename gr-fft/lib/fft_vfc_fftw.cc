/* -*- c++ -*- */
/*
 * Copyright 2004,2007,2008,2010,2012 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "fft_vfc_fftw.h"
#include <gnuradio/io_signature.h>
#include <math.h>
#include <string.h>

namespace gr {
namespace fft {

fft_vfc::sptr
fft_vfc::make(int fft_size, bool forward, const std::vector<float>& window, int nthreads)
{
    return gnuradio::get_initial_sptr(
        new fft_vfc_fftw(fft_size, forward, window, nthreads));
}

fft_vfc_fftw::fft_vfc_fftw(int fft_size,
                           bool forward,
                           const std::vector<float>& window,
                           int nthreads)
    : sync_block("fft_vfc_fftw",
                 io_signature::make(1, 1, fft_size * sizeof(float)),
                 io_signature::make(1, 1, fft_size * sizeof(gr_complex))),
      d_fft_size(fft_size),
      d_fft(fft_size, forward, nthreads)
{
    if (!set_window(window))
        throw std::runtime_error("fft_vfc: window not the same length as fft_size");
}

void fft_vfc_fftw::set_nthreads(int n) { d_fft.set_nthreads(n); }

int fft_vfc_fftw::nthreads() const { return d_fft.nthreads(); }

bool fft_vfc_fftw::set_window(const std::vector<float>& window)
{
    if (window.empty() || window.size() == d_fft_size) {
        d_window = window;
        return true;
    } else
        return false;
}

int fft_vfc_fftw::work(int noutput_items,
                       gr_vector_const_void_star& input_items,
                       gr_vector_void_star& output_items)
{
    const float* in = (const float*)input_items[0];
    gr_complex* out = (gr_complex*)output_items[0];

    unsigned int output_data_size = output_signature()->sizeof_stream_item(0);

    int count = 0;

    while (count++ < noutput_items) {

        // copy input into optimally aligned buffer
        if (!d_window.empty()) {
            gr_complex* dst = d_fft.get_inbuf();
            for (unsigned int i = 0; i < d_fft_size; i++) // apply window
                dst[i] = in[i] * d_window[i];
        } else {
            gr_complex* dst = d_fft.get_inbuf();
            for (unsigned int i = 0; i < d_fft_size; i++) // float to complex conversion
                dst[i] = in[i];
        }

        // compute the fft
        d_fft.execute();

        // copy result to output stream
        memcpy(out, d_fft.get_outbuf(), output_data_size);

        in += d_fft_size;
        out += d_fft_size;
    }

    return noutput_items;
}

} /* namespace fft */
} /* namespace gr */
