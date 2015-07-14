///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Assert.hh
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Assert FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Test_Assert_FFI_HH
#define Test_Assert_FFI_HH

#include "Purescript/Purescript.hh"

namespace Test_Assert {
  using namespace PureScript;

  inline auto assert_prime_(string message) {
    return [=](bool success) {
      return [=]() {
        if (!success) throw runtime_error(message);
      };
    };
  }

}

#endif // Test_Assert_FFI_HH
