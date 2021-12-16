// Copyright 2021-2022 Lawrence Livermore National Security, LLC and other
// croquis Project Developers. See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: MIT

#ifndef _CROQUIS_UTIL_YGM_TESTS_HPP
#define _CROQUIS_UTIL_YGM_TESTS_HPP

#include <croquis/util/tests.hpp>

#include <ygm/detail/ygm_ptr.hpp>

template <typename T>
ygm::ygm_ptr<T> _make_ygm_ptr(T &t) {
  return ygm::ygm_ptr<T>(&t);
}

/**
 * Functor wrapping _make_ygm_ptr
 */
template <typename T>
struct make_ygm_ptr_functor_t {
  typedef ygm::ygm_ptr<T> ptr_t;

  make_ygm_ptr_functor_t() {}

  template <typename... Args>
  ptr_t operator()(Args... args) {
    sptrs.push_back(std::make_unique<T>(args...));
    return _make_ygm_ptr<T>(*(sptrs.back()));
  }

  static constexpr std::string name() { return "ygm::ygm_ptr"; }

 private:
  std::vector<std::unique_ptr<T>> sptrs;
};

#endif