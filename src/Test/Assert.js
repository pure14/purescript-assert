/* global exports */
"use strict";

// module Test.Assert

// | Throws a runtime exception with the specified message when the boolean
// | value is false.
//
// foreign import assert' :: forall e. String -> Boolean -> Eff (assert :: ASSERT | e) Unit
//
exports["assert'"] = function (message) {
  return function (success) {
    return function () {
      if (!success) throw new Error(message);
      return {};
    };
  };
};

exports.checkThrows = function (fn) {
  return function () {
    try {
      fn();
      return false;
    } catch (e) {
      if (e instanceof Error) return true;
      var err = new Error("Threw something other than an Error");
      err.something = e;
      throw err;
    }
  };
};
