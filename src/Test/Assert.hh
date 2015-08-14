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

#include "PureScript/PureScript.hh"

namespace Test_Assert {
  using namespace PureScript;

  inline auto assert_prime_(const string& message) {
    return [=](const bool success) {
      return [=]() {
        if (!success) throw runtime_error(message);
	return Prelude::unit;
      };
    };
  }

}

#endif // Test_Assert_FFI_HH
