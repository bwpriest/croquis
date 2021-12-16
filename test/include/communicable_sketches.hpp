// Copyright 2021-2022 Lawrence Livermore National Security, LLC and other
// croquis Project Developers. See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: MIT

#include <croquis/sketch/interface.hpp>

#include <croquis/util/ygm_tests.hpp>

using Dense32CountSketch =
    croquis::sketch::CommunicableCountSketch<croquis::sketch::Dense,
                                             std::int32_t>;

using MapSparse32CountSketch =
    croquis::sketch::CommunicableCountSketch<croquis::sketch::MapSparse32,
                                             std::int32_t>;

using MapPromotable32CountSketch =
    croquis::sketch::CommunicableCountSketch<croquis::sketch::MapPromotable32,
                                             std::int32_t>;

#if __has_include(<boost/container/flat_map.hpp>)
using FlatMapSparse32CountSketch =
    croquis::sketch::CommunicableCountSketch<croquis::sketch::FlatMapSparse32,
                                             std::int32_t>;

using FlatMapPromotable32CountSketch = croquis::sketch::CommunicableCountSketch<
    croquis::sketch::FlatMapPromotable32, std::int32_t>;
#endif

using Dense32FWHT = croquis::sketch::CommunicableFWHT<std::int32_t>;

template <typename T>
using make_ptr_functor_t = make_ygm_ptr_functor_t<T>;