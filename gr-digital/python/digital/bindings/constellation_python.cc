/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/* This file is automatically generated using bindtool */

#include <pybind11/pybind11.h>
#include <pybind11/complex.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/digital/constellation.h>

void bind_constellation(py::module& m)
{
    using constellation    = gr::digital::constellation;
    using constellation_calcdist    = gr::digital::constellation_calcdist;
    using constellation_sector    = gr::digital::constellation_sector;
    using constellation_rect    = gr::digital::constellation_rect;
    using constellation_expl_rect    = gr::digital::constellation_expl_rect;
    using constellation_psk    = gr::digital::constellation_psk;
    using constellation_bpsk    = gr::digital::constellation_bpsk;
    using constellation_qpsk    = gr::digital::constellation_qpsk;
    using constellation_dqpsk    = gr::digital::constellation_dqpsk;
    using constellation_8psk    = gr::digital::constellation_8psk;
    using constellation_8psk_natural    = gr::digital::constellation_8psk_natural;
    using constellation_16qam    = gr::digital::constellation_16qam;


    py::class_<constellation,
               std::shared_ptr<constellation>>(m, "constellation")

        // Constellation is only a base class and cannot be instantiated directly
        // .def(py::init<std::vector<gr_complex>,
        //           std::vector<int>,
        //           unsigned int,
        //           unsigned int,
        //           bool>(),
        //      py::arg("constell"),
        //      py::arg("pre_diff_code"),
        //      py::arg("rotational_symmetry"),
        //      py::arg("dimensionality"),
        //      py::arg("normalize_points") = true)
        // .def(py::init<>())
        // .def(py::init<gr::digital::constellation const&>(), py::arg("arg0"))

        .def("map_to_points",
             &constellation::map_to_points,
             py::arg("value"),
             py::arg("points"))
        .def("map_to_points_v", &constellation::map_to_points_v, py::arg("value"))
        .def("decision_maker", &constellation::decision_maker, py::arg("sample"))
        .def("decision_maker_v", &constellation::decision_maker_v, py::arg("sample"))
        .def("decision_maker_pe",
             &constellation::decision_maker_pe,
             py::arg("sample"),
             py::arg("phase_error"))
        .def("calc_metric",
             &constellation::calc_metric,
             py::arg("sample"),
             py::arg("metric"),
             py::arg("type"))
        .def("calc_euclidean_metric",
             &constellation::calc_euclidean_metric,
             py::arg("sample"),
             py::arg("metric"))
        .def("calc_hard_symbol_metric",
             &constellation::calc_hard_symbol_metric,
             py::arg("sample"),
             py::arg("metric"))
        .def("points", &constellation::points)
        .def("s_points", &constellation::s_points)
        .def("v_points", &constellation::v_points)
        .def("apply_pre_diff_code", &constellation::apply_pre_diff_code)
        .def("set_pre_diff_code", &constellation::set_pre_diff_code, py::arg("a"))
        .def("pre_diff_code", &constellation::pre_diff_code)
        .def("rotational_symmetry", &constellation::rotational_symmetry)
        .def("dimensionality", &constellation::dimensionality)
        .def("bits_per_symbol", &constellation::bits_per_symbol)
        .def("arity", &constellation::arity)
        .def("base", &constellation::base)
        .def("as_pmt", &constellation::as_pmt)
        .def("gen_soft_dec_lut",
             &constellation::gen_soft_dec_lut,
             py::arg("precision"),
             py::arg("npwr") = 1.)
        .def("calc_soft_dec",
             &constellation::calc_soft_dec,
             py::arg("sample"),
             py::arg("npwr") = 1.)
        .def("set_soft_dec_lut",
             &constellation::set_soft_dec_lut,
             py::arg("soft_dec_lut"),
             py::arg("precision"))
        .def("has_soft_dec_lut", &constellation::has_soft_dec_lut)
        .def("soft_dec_lut", &constellation::soft_dec_lut)
        .def("soft_decision_maker",
             &constellation::soft_decision_maker,
             py::arg("sample"));


    py::class_<constellation_calcdist,
               gr::digital::constellation,
               std::shared_ptr<constellation_calcdist>>(m, "constellation_calcdist")

        .def(py::init(&constellation_calcdist::make),
             py::arg("constell"),
             py::arg("pre_diff_code"),
             py::arg("rotational_symmetry"),
             py::arg("dimensionality"),
             py::arg("normalize_points") = true)


        .def(
            "decision_maker", &constellation_calcdist::decision_maker, py::arg("sample"));


    py::class_<constellation_sector,
               gr::digital::constellation,
               std::shared_ptr<constellation_sector>>(m, "constellation_sector")

        // Constellation_sector has pure virtual functions and cannot be instantiated directly
        // .def(py::init<
        //          std::vector<std::complex<float>, std::allocator<std::complex<float>>>,
        //          std::vector<int, std::allocator<int>>,
        //          unsigned int,
        //          unsigned int,
        //          unsigned int>(),
        //      py::arg("constell"),
        //      py::arg("pre_diff_code"),
        //      py::arg("rotational_symmetry"),
        //      py::arg("dimensionality"),
        //      py::arg("n_sectors"))
        // .def(py::init<gr::digital::constellation_sector const&>(), py::arg("arg0"))

        .def("decision_maker", &constellation_sector::decision_maker, py::arg("sample"));


    py::class_<constellation_rect,
               gr::digital::constellation_sector,
               std::shared_ptr<constellation_rect>>(m, "constellation_rect")

        .def(py::init(&constellation_rect::make),
             py::arg("constell"),
             py::arg("pre_diff_code"),
             py::arg("rotational_symmetry"),
             py::arg("real_sectors"),
             py::arg("imag_sectors"),
             py::arg("width_real_sectors"),
             py::arg("width_imag_sectors"));


    py::class_<constellation_expl_rect,
               gr::digital::constellation_rect,
               std::shared_ptr<constellation_expl_rect>>(m, "constellation_expl_rect")

        .def(py::init(&constellation_expl_rect::make),
             py::arg("constellation"),
             py::arg("pre_diff_code"),
             py::arg("rotational_symmetry"),
             py::arg("real_sectors"),
             py::arg("imag_sectors"),
             py::arg("width_real_sectors"),
             py::arg("width_imag_sectors"),
             py::arg("sector_values"));


    py::class_<constellation_psk,
               gr::digital::constellation_sector,
               std::shared_ptr<constellation_psk>>(m, "constellation_psk")

        .def(py::init(&constellation_psk::make),
             py::arg("constell"),
             py::arg("pre_diff_code"),
             py::arg("n_sectors"));


    py::class_<constellation_bpsk,
               gr::digital::constellation,
               std::shared_ptr<constellation_bpsk>>(m, "constellation_bpsk")

        .def(py::init(&constellation_bpsk::make))


        .def("decision_maker", &constellation_bpsk::decision_maker, py::arg("sample"));


    py::class_<constellation_qpsk,
               gr::digital::constellation,
               std::shared_ptr<constellation_qpsk>>(m, "constellation_qpsk")

        .def(py::init(&constellation_qpsk::make))


        .def("decision_maker", &constellation_qpsk::decision_maker, py::arg("sample"));


    py::class_<constellation_dqpsk,
               gr::digital::constellation,
               std::shared_ptr<constellation_dqpsk>>(m, "constellation_dqpsk")

        .def(py::init(&constellation_dqpsk::make))

        .def("decision_maker", &constellation_dqpsk::decision_maker, py::arg("sample"));


    py::class_<constellation_8psk,
               gr::digital::constellation,
               std::shared_ptr<constellation_8psk>>(m, "constellation_8psk")

        .def(py::init(&constellation_8psk::make))


        .def("decision_maker", &constellation_8psk::decision_maker, py::arg("sample"));


    py::class_<constellation_8psk_natural,
               gr::digital::constellation,
               std::shared_ptr<constellation_8psk_natural>>(m,
                                                            "constellation_8psk_natural")

        .def(py::init(&constellation_8psk_natural::make))


        .def("decision_maker",
             &constellation_8psk_natural::decision_maker,
             py::arg("sample"));


    py::class_<constellation_16qam,
               gr::digital::constellation,
               std::shared_ptr<constellation_16qam>>(m, "constellation_16qam")

        .def(py::init(&constellation_16qam::make))

        .def("decision_maker", &constellation_16qam::decision_maker, py::arg("sample"));
}
