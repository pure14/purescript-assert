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

  // | Throws a runtime exception with the specified message when the boolean
  // | value is false.
  //
  // foreign import assert' :: forall e. String -> Boolean -> Eff (assert :: ASSERT | e) Unit
  //
  inline auto assert_prime_(const string& message) {
    return [=](const bool success) {
      return [=]() {
        if (!success) throw runtime_error(message);
        return Prelude::unit;
      };
    };
  }

  //  foreign import checkThrows :: forall e a. (Unit -> a) -> Eff (assert :: ASSERT | e) Boolean
  //
  template <typename A>
  inline auto checkThrows(const fn<Prelude::Unit,A>& f) {
    return [=]() {
      try {
        f(Prelude::unit);
        return false;
      } catch (std::runtime_error&) {
        return true;
      } catch (std::exception&) {
        throw runtime_error("Threw something other than an Error");
      }
    };
  }

}

#endif // Test_Assert_FFI_HH
