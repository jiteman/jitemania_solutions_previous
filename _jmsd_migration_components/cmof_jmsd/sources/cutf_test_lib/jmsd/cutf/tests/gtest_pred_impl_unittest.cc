#include "gtest/gtest.h"
#include "gtest/gtest-spi.h"

#include "gtest/Assertion_result.hin"
#include "gtest/Message.hin"


#include <iostream>


// A user-defined data type.
struct Bool {
  explicit Bool(int val) : value(val != 0) {}

  bool operator>(int n) const { return value > Bool(n).value; }

  Bool operator+(const Bool& rhs) const { return Bool(value + rhs.value); }

  bool operator==(const Bool& rhs) const { return value == rhs.value; }

  bool value;
};

// Enables Bool to be used in assertions.
std::ostream& operator<<(std::ostream& os, const Bool& x) {
  return os << (x.value ? "true" : "false");
}

// Sample functions/functors for testing unary predicate assertions.

// A unary predicate function.
template <typename T1>
bool PredFunction1(T1 v1) {
  return v1 > 0;
}

// The following two functions are needed because a compiler doesn't have
// a context yet to know which template function must be instantiated.
bool PredFunction1Int(int v1) {
  return v1 > 0;
}
bool PredFunction1Bool(Bool v1) {
  return v1 > 0;
}

// A unary predicate functor.
struct PredFunctor1 {
  template <typename T1>
  bool operator()(const T1& v1) {
    return v1 > 0;
  }
};

// A unary predicate-formatter function.
template <typename T1>
::jmsd::cutf::AssertionResult PredFormatFunction1(const char* e1,
                                             const T1& v1) {
  if (PredFunction1(v1))
    return ::jmsd::cutf::AssertionResult::AssertionSuccess();

  return ::jmsd::cutf::AssertionResult::AssertionFailure()
      << e1
      << " is expected to be positive, but evaluates to "
      << v1 << ".";
}

// A unary predicate-formatter functor.
struct PredFormatFunctor1 {
  template <typename T1>
  ::jmsd::cutf::AssertionResult operator()(const char* e1,
                                      const T1& v1) const {
    return PredFormatFunction1(e1, v1);
  }
};

// Tests for {EXPECT|ASSERT}_PRED_FORMAT1.

class Predicate1Test : public ::jmsd::cutf::Test {
 protected:
  void SetUp() override {
    expected_to_finish_ = true;
    finished_ = false;
    n1_ = 0;
  }

  void TearDown() override {
    // Verifies that each of the predicate's arguments was evaluated
    // exactly once.
    EXPECT_EQ(1, n1_) <<
        "The predicate assertion didn't evaluate argument 2 "
        "exactly once.";

    // Verifies that the control flow in the test function is expected.
    if (expected_to_finish_ && !finished_) {
      FAIL() << "The predicate assertion unexpactedly aborted the test.";
    } else if (!expected_to_finish_ && finished_) {
      FAIL() << "The failed predicate assertion didn't abort the test "
                "as expected.";
    }
  }

  // true if and only if the test function is expected to run to finish.
  static bool expected_to_finish_;

  // true if and only if the test function did run to finish.
  static bool finished_;

  static int n1_;
};

bool Predicate1Test::expected_to_finish_;
bool Predicate1Test::finished_;
int Predicate1Test::n1_;

typedef Predicate1Test EXPECT_PRED_FORMAT1Test;
typedef Predicate1Test ASSERT_PRED_FORMAT1Test;
typedef Predicate1Test EXPECT_PRED1Test;
typedef Predicate1Test ASSERT_PRED1Test;

// Tests a successful EXPECT_PRED1 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED1Test, FunctionOnBuiltInTypeSuccess) {
  EXPECT_PRED1(PredFunction1Int,
               ++n1_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED1 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED1Test, FunctionOnUserTypeSuccess) {
  EXPECT_PRED1(PredFunction1Bool,
               Bool(++n1_));
  finished_ = true;
}

// Tests a successful EXPECT_PRED1 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED1Test, FunctorOnBuiltInTypeSuccess) {
  EXPECT_PRED1(PredFunctor1(),
               ++n1_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED1 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED1Test, FunctorOnUserTypeSuccess) {
  EXPECT_PRED1(PredFunctor1(),
               Bool(++n1_));
  finished_ = true;
}

// Tests a failed EXPECT_PRED1 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED1Test, FunctionOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED1(PredFunction1Int,
                 n1_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED1 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED1Test, FunctionOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED1(PredFunction1Bool,
                 Bool(n1_++));
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED1 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED1Test, FunctorOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED1(PredFunctor1(),
                 n1_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED1 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED1Test, FunctorOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED1(PredFunctor1(),
                 Bool(n1_++));
    finished_ = true;
  }, "");
}

// Tests a successful ASSERT_PRED1 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED1Test, FunctionOnBuiltInTypeSuccess) {
  ASSERT_PRED1(PredFunction1Int,
               ++n1_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED1 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED1Test, FunctionOnUserTypeSuccess) {
  ASSERT_PRED1(PredFunction1Bool,
               Bool(++n1_));
  finished_ = true;
}

// Tests a successful ASSERT_PRED1 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED1Test, FunctorOnBuiltInTypeSuccess) {
  ASSERT_PRED1(PredFunctor1(),
               ++n1_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED1 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED1Test, FunctorOnUserTypeSuccess) {
  ASSERT_PRED1(PredFunctor1(),
               Bool(++n1_));
  finished_ = true;
}

// Tests a failed ASSERT_PRED1 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED1Test, FunctionOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED1(PredFunction1Int,
                 n1_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED1 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED1Test, FunctionOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED1(PredFunction1Bool,
                 Bool(n1_++));
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED1 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED1Test, FunctorOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED1(PredFunctor1(),
                 n1_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED1 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED1Test, FunctorOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED1(PredFunctor1(),
                 Bool(n1_++));
    finished_ = true;
  }, "");
}

// Tests a successful EXPECT_PRED_FORMAT1 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT1Test, FunctionOnBuiltInTypeSuccess) {
  EXPECT_PRED_FORMAT1(PredFormatFunction1,
                      ++n1_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT1 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT1Test, FunctionOnUserTypeSuccess) {
  EXPECT_PRED_FORMAT1(PredFormatFunction1,
                      Bool(++n1_));
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT1 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT1Test, FunctorOnBuiltInTypeSuccess) {
  EXPECT_PRED_FORMAT1(PredFormatFunctor1(),
                      ++n1_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT1 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT1Test, FunctorOnUserTypeSuccess) {
  EXPECT_PRED_FORMAT1(PredFormatFunctor1(),
                      Bool(++n1_));
  finished_ = true;
}

// Tests a failed EXPECT_PRED_FORMAT1 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT1Test, FunctionOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT1(PredFormatFunction1,
                        n1_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT1 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT1Test, FunctionOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT1(PredFormatFunction1,
                        Bool(n1_++));
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT1 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT1Test, FunctorOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT1(PredFormatFunctor1(),
                        n1_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT1 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT1Test, FunctorOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT1(PredFormatFunctor1(),
                        Bool(n1_++));
    finished_ = true;
  }, "");
}

// Tests a successful ASSERT_PRED_FORMAT1 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT1Test, FunctionOnBuiltInTypeSuccess) {
  ASSERT_PRED_FORMAT1(PredFormatFunction1,
                      ++n1_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT1 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT1Test, FunctionOnUserTypeSuccess) {
  ASSERT_PRED_FORMAT1(PredFormatFunction1,
                      Bool(++n1_));
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT1 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT1Test, FunctorOnBuiltInTypeSuccess) {
  ASSERT_PRED_FORMAT1(PredFormatFunctor1(),
                      ++n1_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT1 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT1Test, FunctorOnUserTypeSuccess) {
  ASSERT_PRED_FORMAT1(PredFormatFunctor1(),
                      Bool(++n1_));
  finished_ = true;
}

// Tests a failed ASSERT_PRED_FORMAT1 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT1Test, FunctionOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT1(PredFormatFunction1,
                        n1_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT1 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT1Test, FunctionOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT1(PredFormatFunction1,
                        Bool(n1_++));
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT1 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT1Test, FunctorOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT1(PredFormatFunctor1(),
                        n1_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT1 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT1Test, FunctorOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT1(PredFormatFunctor1(),
                        Bool(n1_++));
    finished_ = true;
  }, "");
}
// Sample functions/functors for testing binary predicate assertions.

// A binary predicate function.
template <typename T1, typename T2>
bool PredFunction2(T1 v1, T2 v2) {
  return v1 + v2 > 0;
}

// The following two functions are needed because a compiler doesn't have
// a context yet to know which template function must be instantiated.
bool PredFunction2Int(int v1, int v2) {
  return v1 + v2 > 0;
}
bool PredFunction2Bool(Bool v1, Bool v2) {
  return v1 + v2 > 0;
}

// A binary predicate functor.
struct PredFunctor2 {
  template <typename T1, typename T2>
  bool operator()(const T1& v1,
                  const T2& v2) {
    return v1 + v2 > 0;
  }
};

// A binary predicate-formatter function.
template <typename T1, typename T2>
::jmsd::cutf::AssertionResult PredFormatFunction2(const char* e1,
                                             const char* e2,
                                             const T1& v1,
                                             const T2& v2) {
  if (PredFunction2(v1, v2))
    return ::jmsd::cutf::AssertionResult::AssertionSuccess();

  return ::jmsd::cutf::AssertionResult::AssertionFailure()
      << e1 << " + " << e2
      << " is expected to be positive, but evaluates to "
      << v1 + v2 << ".";
}

// A binary predicate-formatter functor.
struct PredFormatFunctor2 {
  template <typename T1, typename T2>
  ::jmsd::cutf::AssertionResult operator()(const char* e1,
                                      const char* e2,
                                      const T1& v1,
                                      const T2& v2) const {
    return PredFormatFunction2(e1, e2, v1, v2);
  }
};

// Tests for {EXPECT|ASSERT}_PRED_FORMAT2.

class Predicate2Test : public ::jmsd::cutf::Test {
 protected:
  void SetUp() override {
    expected_to_finish_ = true;
    finished_ = false;
    n1_ = n2_ = 0;
  }

  void TearDown() override {
    // Verifies that each of the predicate's arguments was evaluated
    // exactly once.
    EXPECT_EQ(1, n1_) <<
        "The predicate assertion didn't evaluate argument 2 "
        "exactly once.";
    EXPECT_EQ(1, n2_) <<
        "The predicate assertion didn't evaluate argument 3 "
        "exactly once.";

    // Verifies that the control flow in the test function is expected.
    if (expected_to_finish_ && !finished_) {
      FAIL() << "The predicate assertion unexpactedly aborted the test.";
    } else if (!expected_to_finish_ && finished_) {
      FAIL() << "The failed predicate assertion didn't abort the test "
                "as expected.";
    }
  }

  // true if and only if the test function is expected to run to finish.
  static bool expected_to_finish_;

  // true if and only if the test function did run to finish.
  static bool finished_;

  static int n1_;
  static int n2_;
};

bool Predicate2Test::expected_to_finish_;
bool Predicate2Test::finished_;
int Predicate2Test::n1_;
int Predicate2Test::n2_;

typedef Predicate2Test EXPECT_PRED_FORMAT2Test;
typedef Predicate2Test ASSERT_PRED_FORMAT2Test;
typedef Predicate2Test EXPECT_PRED2Test;
typedef Predicate2Test ASSERT_PRED2Test;

// Tests a successful EXPECT_PRED2 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED2Test, FunctionOnBuiltInTypeSuccess) {
  EXPECT_PRED2(PredFunction2Int,
               ++n1_,
               ++n2_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED2 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED2Test, FunctionOnUserTypeSuccess) {
  EXPECT_PRED2(PredFunction2Bool,
               Bool(++n1_),
               Bool(++n2_));
  finished_ = true;
}

// Tests a successful EXPECT_PRED2 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED2Test, FunctorOnBuiltInTypeSuccess) {
  EXPECT_PRED2(PredFunctor2(),
               ++n1_,
               ++n2_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED2 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED2Test, FunctorOnUserTypeSuccess) {
  EXPECT_PRED2(PredFunctor2(),
               Bool(++n1_),
               Bool(++n2_));
  finished_ = true;
}

// Tests a failed EXPECT_PRED2 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED2Test, FunctionOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED2(PredFunction2Int,
                 n1_++,
                 n2_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED2 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED2Test, FunctionOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED2(PredFunction2Bool,
                 Bool(n1_++),
                 Bool(n2_++));
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED2 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED2Test, FunctorOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED2(PredFunctor2(),
                 n1_++,
                 n2_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED2 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED2Test, FunctorOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED2(PredFunctor2(),
                 Bool(n1_++),
                 Bool(n2_++));
    finished_ = true;
  }, "");
}

// Tests a successful ASSERT_PRED2 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED2Test, FunctionOnBuiltInTypeSuccess) {
  ASSERT_PRED2(PredFunction2Int,
               ++n1_,
               ++n2_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED2 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED2Test, FunctionOnUserTypeSuccess) {
  ASSERT_PRED2(PredFunction2Bool,
               Bool(++n1_),
               Bool(++n2_));
  finished_ = true;
}

// Tests a successful ASSERT_PRED2 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED2Test, FunctorOnBuiltInTypeSuccess) {
  ASSERT_PRED2(PredFunctor2(),
               ++n1_,
               ++n2_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED2 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED2Test, FunctorOnUserTypeSuccess) {
  ASSERT_PRED2(PredFunctor2(),
               Bool(++n1_),
               Bool(++n2_));
  finished_ = true;
}

// Tests a failed ASSERT_PRED2 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED2Test, FunctionOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED2(PredFunction2Int,
                 n1_++,
                 n2_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED2 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED2Test, FunctionOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED2(PredFunction2Bool,
                 Bool(n1_++),
                 Bool(n2_++));
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED2 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED2Test, FunctorOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED2(PredFunctor2(),
                 n1_++,
                 n2_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED2 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED2Test, FunctorOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED2(PredFunctor2(),
                 Bool(n1_++),
                 Bool(n2_++));
    finished_ = true;
  }, "");
}

// Tests a successful EXPECT_PRED_FORMAT2 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT2Test, FunctionOnBuiltInTypeSuccess) {
  EXPECT_PRED_FORMAT2(PredFormatFunction2,
                      ++n1_,
                      ++n2_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT2 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT2Test, FunctionOnUserTypeSuccess) {
  EXPECT_PRED_FORMAT2(PredFormatFunction2,
                      Bool(++n1_),
                      Bool(++n2_));
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT2 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT2Test, FunctorOnBuiltInTypeSuccess) {
  EXPECT_PRED_FORMAT2(PredFormatFunctor2(),
                      ++n1_,
                      ++n2_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT2 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT2Test, FunctorOnUserTypeSuccess) {
  EXPECT_PRED_FORMAT2(PredFormatFunctor2(),
                      Bool(++n1_),
                      Bool(++n2_));
  finished_ = true;
}

// Tests a failed EXPECT_PRED_FORMAT2 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT2Test, FunctionOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT2(PredFormatFunction2,
                        n1_++,
                        n2_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT2 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT2Test, FunctionOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT2(PredFormatFunction2,
                        Bool(n1_++),
                        Bool(n2_++));
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT2 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT2Test, FunctorOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT2(PredFormatFunctor2(),
                        n1_++,
                        n2_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT2 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT2Test, FunctorOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT2(PredFormatFunctor2(),
                        Bool(n1_++),
                        Bool(n2_++));
    finished_ = true;
  }, "");
}

// Tests a successful ASSERT_PRED_FORMAT2 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT2Test, FunctionOnBuiltInTypeSuccess) {
  ASSERT_PRED_FORMAT2(PredFormatFunction2,
                      ++n1_,
                      ++n2_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT2 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT2Test, FunctionOnUserTypeSuccess) {
  ASSERT_PRED_FORMAT2(PredFormatFunction2,
                      Bool(++n1_),
                      Bool(++n2_));
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT2 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT2Test, FunctorOnBuiltInTypeSuccess) {
  ASSERT_PRED_FORMAT2(PredFormatFunctor2(),
                      ++n1_,
                      ++n2_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT2 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT2Test, FunctorOnUserTypeSuccess) {
  ASSERT_PRED_FORMAT2(PredFormatFunctor2(),
                      Bool(++n1_),
                      Bool(++n2_));
  finished_ = true;
}

// Tests a failed ASSERT_PRED_FORMAT2 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT2Test, FunctionOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT2(PredFormatFunction2,
                        n1_++,
                        n2_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT2 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT2Test, FunctionOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT2(PredFormatFunction2,
                        Bool(n1_++),
                        Bool(n2_++));
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT2 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT2Test, FunctorOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT2(PredFormatFunctor2(),
                        n1_++,
                        n2_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT2 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT2Test, FunctorOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT2(PredFormatFunctor2(),
                        Bool(n1_++),
                        Bool(n2_++));
    finished_ = true;
  }, "");
}
// Sample functions/functors for testing ternary predicate assertions.

// A ternary predicate function.
template <typename T1, typename T2, typename T3>
bool PredFunction3(T1 v1, T2 v2, T3 v3) {
  return v1 + v2 + v3 > 0;
}

// The following two functions are needed because a compiler doesn't have
// a context yet to know which template function must be instantiated.
bool PredFunction3Int(int v1, int v2, int v3) {
  return v1 + v2 + v3 > 0;
}
bool PredFunction3Bool(Bool v1, Bool v2, Bool v3) {
  return v1 + v2 + v3 > 0;
}

// A ternary predicate functor.
struct PredFunctor3 {
  template <typename T1, typename T2, typename T3>
  bool operator()(const T1& v1,
                  const T2& v2,
                  const T3& v3) {
    return v1 + v2 + v3 > 0;
  }
};

// A ternary predicate-formatter function.
template <typename T1, typename T2, typename T3>
::jmsd::cutf::AssertionResult PredFormatFunction3(const char* e1,
                                             const char* e2,
                                             const char* e3,
                                             const T1& v1,
                                             const T2& v2,
                                             const T3& v3) {
  if (PredFunction3(v1, v2, v3))
    return ::jmsd::cutf::AssertionResult::AssertionSuccess();

  return ::jmsd::cutf::AssertionResult::AssertionFailure()
      << e1 << " + " << e2 << " + " << e3
      << " is expected to be positive, but evaluates to "
      << v1 + v2 + v3 << ".";
}

// A ternary predicate-formatter functor.
struct PredFormatFunctor3 {
  template <typename T1, typename T2, typename T3>
  ::jmsd::cutf::AssertionResult operator()(const char* e1,
                                      const char* e2,
                                      const char* e3,
                                      const T1& v1,
                                      const T2& v2,
                                      const T3& v3) const {
    return PredFormatFunction3(e1, e2, e3, v1, v2, v3);
  }
};

// Tests for {EXPECT|ASSERT}_PRED_FORMAT3.

class Predicate3Test : public ::jmsd::cutf::Test {
 protected:
  void SetUp() override {
    expected_to_finish_ = true;
    finished_ = false;
    n1_ = n2_ = n3_ = 0;
  }

  void TearDown() override {
    // Verifies that each of the predicate's arguments was evaluated
    // exactly once.
    EXPECT_EQ(1, n1_) <<
        "The predicate assertion didn't evaluate argument 2 "
        "exactly once.";
    EXPECT_EQ(1, n2_) <<
        "The predicate assertion didn't evaluate argument 3 "
        "exactly once.";
    EXPECT_EQ(1, n3_) <<
        "The predicate assertion didn't evaluate argument 4 "
        "exactly once.";

    // Verifies that the control flow in the test function is expected.
    if (expected_to_finish_ && !finished_) {
      FAIL() << "The predicate assertion unexpactedly aborted the test.";
    } else if (!expected_to_finish_ && finished_) {
      FAIL() << "The failed predicate assertion didn't abort the test "
                "as expected.";
    }
  }

  // true if and only if the test function is expected to run to finish.
  static bool expected_to_finish_;

  // true if and only if the test function did run to finish.
  static bool finished_;

  static int n1_;
  static int n2_;
  static int n3_;
};

bool Predicate3Test::expected_to_finish_;
bool Predicate3Test::finished_;
int Predicate3Test::n1_;
int Predicate3Test::n2_;
int Predicate3Test::n3_;

typedef Predicate3Test EXPECT_PRED_FORMAT3Test;
typedef Predicate3Test ASSERT_PRED_FORMAT3Test;
typedef Predicate3Test EXPECT_PRED3Test;
typedef Predicate3Test ASSERT_PRED3Test;

// Tests a successful EXPECT_PRED3 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED3Test, FunctionOnBuiltInTypeSuccess) {
  EXPECT_PRED3(PredFunction3Int,
               ++n1_,
               ++n2_,
               ++n3_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED3 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED3Test, FunctionOnUserTypeSuccess) {
  EXPECT_PRED3(PredFunction3Bool,
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_));
  finished_ = true;
}

// Tests a successful EXPECT_PRED3 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED3Test, FunctorOnBuiltInTypeSuccess) {
  EXPECT_PRED3(PredFunctor3(),
               ++n1_,
               ++n2_,
               ++n3_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED3 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED3Test, FunctorOnUserTypeSuccess) {
  EXPECT_PRED3(PredFunctor3(),
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_));
  finished_ = true;
}

// Tests a failed EXPECT_PRED3 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED3Test, FunctionOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED3(PredFunction3Int,
                 n1_++,
                 n2_++,
                 n3_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED3 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED3Test, FunctionOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED3(PredFunction3Bool,
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++));
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED3 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED3Test, FunctorOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED3(PredFunctor3(),
                 n1_++,
                 n2_++,
                 n3_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED3 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED3Test, FunctorOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED3(PredFunctor3(),
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++));
    finished_ = true;
  }, "");
}

// Tests a successful ASSERT_PRED3 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED3Test, FunctionOnBuiltInTypeSuccess) {
  ASSERT_PRED3(PredFunction3Int,
               ++n1_,
               ++n2_,
               ++n3_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED3 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED3Test, FunctionOnUserTypeSuccess) {
  ASSERT_PRED3(PredFunction3Bool,
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_));
  finished_ = true;
}

// Tests a successful ASSERT_PRED3 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED3Test, FunctorOnBuiltInTypeSuccess) {
  ASSERT_PRED3(PredFunctor3(),
               ++n1_,
               ++n2_,
               ++n3_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED3 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED3Test, FunctorOnUserTypeSuccess) {
  ASSERT_PRED3(PredFunctor3(),
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_));
  finished_ = true;
}

// Tests a failed ASSERT_PRED3 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED3Test, FunctionOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED3(PredFunction3Int,
                 n1_++,
                 n2_++,
                 n3_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED3 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED3Test, FunctionOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED3(PredFunction3Bool,
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++));
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED3 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED3Test, FunctorOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED3(PredFunctor3(),
                 n1_++,
                 n2_++,
                 n3_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED3 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED3Test, FunctorOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED3(PredFunctor3(),
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++));
    finished_ = true;
  }, "");
}

// Tests a successful EXPECT_PRED_FORMAT3 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT3Test, FunctionOnBuiltInTypeSuccess) {
  EXPECT_PRED_FORMAT3(PredFormatFunction3,
                      ++n1_,
                      ++n2_,
                      ++n3_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT3 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT3Test, FunctionOnUserTypeSuccess) {
  EXPECT_PRED_FORMAT3(PredFormatFunction3,
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_));
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT3 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT3Test, FunctorOnBuiltInTypeSuccess) {
  EXPECT_PRED_FORMAT3(PredFormatFunctor3(),
                      ++n1_,
                      ++n2_,
                      ++n3_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT3 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT3Test, FunctorOnUserTypeSuccess) {
  EXPECT_PRED_FORMAT3(PredFormatFunctor3(),
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_));
  finished_ = true;
}

// Tests a failed EXPECT_PRED_FORMAT3 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT3Test, FunctionOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT3(PredFormatFunction3,
                        n1_++,
                        n2_++,
                        n3_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT3 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT3Test, FunctionOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT3(PredFormatFunction3,
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++));
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT3 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT3Test, FunctorOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT3(PredFormatFunctor3(),
                        n1_++,
                        n2_++,
                        n3_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT3 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT3Test, FunctorOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT3(PredFormatFunctor3(),
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++));
    finished_ = true;
  }, "");
}

// Tests a successful ASSERT_PRED_FORMAT3 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT3Test, FunctionOnBuiltInTypeSuccess) {
  ASSERT_PRED_FORMAT3(PredFormatFunction3,
                      ++n1_,
                      ++n2_,
                      ++n3_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT3 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT3Test, FunctionOnUserTypeSuccess) {
  ASSERT_PRED_FORMAT3(PredFormatFunction3,
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_));
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT3 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT3Test, FunctorOnBuiltInTypeSuccess) {
  ASSERT_PRED_FORMAT3(PredFormatFunctor3(),
                      ++n1_,
                      ++n2_,
                      ++n3_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT3 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT3Test, FunctorOnUserTypeSuccess) {
  ASSERT_PRED_FORMAT3(PredFormatFunctor3(),
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_));
  finished_ = true;
}

// Tests a failed ASSERT_PRED_FORMAT3 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT3Test, FunctionOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT3(PredFormatFunction3,
                        n1_++,
                        n2_++,
                        n3_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT3 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT3Test, FunctionOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT3(PredFormatFunction3,
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++));
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT3 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT3Test, FunctorOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT3(PredFormatFunctor3(),
                        n1_++,
                        n2_++,
                        n3_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT3 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT3Test, FunctorOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT3(PredFormatFunctor3(),
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++));
    finished_ = true;
  }, "");
}
// Sample functions/functors for testing 4-ary predicate assertions.

// A 4-ary predicate function.
template <typename T1, typename T2, typename T3, typename T4>
bool PredFunction4(T1 v1, T2 v2, T3 v3, T4 v4) {
  return v1 + v2 + v3 + v4 > 0;
}

// The following two functions are needed because a compiler doesn't have
// a context yet to know which template function must be instantiated.
bool PredFunction4Int(int v1, int v2, int v3, int v4) {
  return v1 + v2 + v3 + v4 > 0;
}
bool PredFunction4Bool(Bool v1, Bool v2, Bool v3, Bool v4) {
  return v1 + v2 + v3 + v4 > 0;
}

// A 4-ary predicate functor.
struct PredFunctor4 {
  template <typename T1, typename T2, typename T3, typename T4>
  bool operator()(const T1& v1,
                  const T2& v2,
                  const T3& v3,
                  const T4& v4) {
    return v1 + v2 + v3 + v4 > 0;
  }
};

// A 4-ary predicate-formatter function.
template <typename T1, typename T2, typename T3, typename T4>
::jmsd::cutf::AssertionResult PredFormatFunction4(const char* e1,
                                             const char* e2,
                                             const char* e3,
                                             const char* e4,
                                             const T1& v1,
                                             const T2& v2,
                                             const T3& v3,
                                             const T4& v4) {
  if (PredFunction4(v1, v2, v3, v4))
    return ::jmsd::cutf::AssertionResult::AssertionSuccess();

  return ::jmsd::cutf::AssertionResult::AssertionFailure()
      << e1 << " + " << e2 << " + " << e3 << " + " << e4
      << " is expected to be positive, but evaluates to "
      << v1 + v2 + v3 + v4 << ".";
}

// A 4-ary predicate-formatter functor.
struct PredFormatFunctor4 {
  template <typename T1, typename T2, typename T3, typename T4>
  ::jmsd::cutf::AssertionResult operator()(const char* e1,
                                      const char* e2,
                                      const char* e3,
                                      const char* e4,
                                      const T1& v1,
                                      const T2& v2,
                                      const T3& v3,
                                      const T4& v4) const {
    return PredFormatFunction4(e1, e2, e3, e4, v1, v2, v3, v4);
  }
};

// Tests for {EXPECT|ASSERT}_PRED_FORMAT4.

class Predicate4Test : public ::jmsd::cutf::Test {
 protected:
  void SetUp() override {
    expected_to_finish_ = true;
    finished_ = false;
    n1_ = n2_ = n3_ = n4_ = 0;
  }

  void TearDown() override {
    // Verifies that each of the predicate's arguments was evaluated
    // exactly once.
    EXPECT_EQ(1, n1_) <<
        "The predicate assertion didn't evaluate argument 2 "
        "exactly once.";
    EXPECT_EQ(1, n2_) <<
        "The predicate assertion didn't evaluate argument 3 "
        "exactly once.";
    EXPECT_EQ(1, n3_) <<
        "The predicate assertion didn't evaluate argument 4 "
        "exactly once.";
    EXPECT_EQ(1, n4_) <<
        "The predicate assertion didn't evaluate argument 5 "
        "exactly once.";

    // Verifies that the control flow in the test function is expected.
    if (expected_to_finish_ && !finished_) {
      FAIL() << "The predicate assertion unexpactedly aborted the test.";
    } else if (!expected_to_finish_ && finished_) {
      FAIL() << "The failed predicate assertion didn't abort the test "
                "as expected.";
    }
  }

  // true if and only if the test function is expected to run to finish.
  static bool expected_to_finish_;

  // true if and only if the test function did run to finish.
  static bool finished_;

  static int n1_;
  static int n2_;
  static int n3_;
  static int n4_;
};

bool Predicate4Test::expected_to_finish_;
bool Predicate4Test::finished_;
int Predicate4Test::n1_;
int Predicate4Test::n2_;
int Predicate4Test::n3_;
int Predicate4Test::n4_;

typedef Predicate4Test EXPECT_PRED_FORMAT4Test;
typedef Predicate4Test ASSERT_PRED_FORMAT4Test;
typedef Predicate4Test EXPECT_PRED4Test;
typedef Predicate4Test ASSERT_PRED4Test;

// Tests a successful EXPECT_PRED4 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED4Test, FunctionOnBuiltInTypeSuccess) {
  EXPECT_PRED4(PredFunction4Int,
               ++n1_,
               ++n2_,
               ++n3_,
               ++n4_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED4 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED4Test, FunctionOnUserTypeSuccess) {
  EXPECT_PRED4(PredFunction4Bool,
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_),
               Bool(++n4_));
  finished_ = true;
}

// Tests a successful EXPECT_PRED4 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED4Test, FunctorOnBuiltInTypeSuccess) {
  EXPECT_PRED4(PredFunctor4(),
               ++n1_,
               ++n2_,
               ++n3_,
               ++n4_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED4 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED4Test, FunctorOnUserTypeSuccess) {
  EXPECT_PRED4(PredFunctor4(),
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_),
               Bool(++n4_));
  finished_ = true;
}

// Tests a failed EXPECT_PRED4 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED4Test, FunctionOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED4(PredFunction4Int,
                 n1_++,
                 n2_++,
                 n3_++,
                 n4_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED4 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED4Test, FunctionOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED4(PredFunction4Bool,
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++),
                 Bool(n4_++));
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED4 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED4Test, FunctorOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED4(PredFunctor4(),
                 n1_++,
                 n2_++,
                 n3_++,
                 n4_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED4 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED4Test, FunctorOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED4(PredFunctor4(),
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++),
                 Bool(n4_++));
    finished_ = true;
  }, "");
}

// Tests a successful ASSERT_PRED4 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED4Test, FunctionOnBuiltInTypeSuccess) {
  ASSERT_PRED4(PredFunction4Int,
               ++n1_,
               ++n2_,
               ++n3_,
               ++n4_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED4 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED4Test, FunctionOnUserTypeSuccess) {
  ASSERT_PRED4(PredFunction4Bool,
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_),
               Bool(++n4_));
  finished_ = true;
}

// Tests a successful ASSERT_PRED4 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED4Test, FunctorOnBuiltInTypeSuccess) {
  ASSERT_PRED4(PredFunctor4(),
               ++n1_,
               ++n2_,
               ++n3_,
               ++n4_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED4 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED4Test, FunctorOnUserTypeSuccess) {
  ASSERT_PRED4(PredFunctor4(),
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_),
               Bool(++n4_));
  finished_ = true;
}

// Tests a failed ASSERT_PRED4 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED4Test, FunctionOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED4(PredFunction4Int,
                 n1_++,
                 n2_++,
                 n3_++,
                 n4_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED4 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED4Test, FunctionOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED4(PredFunction4Bool,
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++),
                 Bool(n4_++));
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED4 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED4Test, FunctorOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED4(PredFunctor4(),
                 n1_++,
                 n2_++,
                 n3_++,
                 n4_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED4 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED4Test, FunctorOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED4(PredFunctor4(),
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++),
                 Bool(n4_++));
    finished_ = true;
  }, "");
}

// Tests a successful EXPECT_PRED_FORMAT4 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT4Test, FunctionOnBuiltInTypeSuccess) {
  EXPECT_PRED_FORMAT4(PredFormatFunction4,
                      ++n1_,
                      ++n2_,
                      ++n3_,
                      ++n4_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT4 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT4Test, FunctionOnUserTypeSuccess) {
  EXPECT_PRED_FORMAT4(PredFormatFunction4,
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_),
                      Bool(++n4_));
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT4 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT4Test, FunctorOnBuiltInTypeSuccess) {
  EXPECT_PRED_FORMAT4(PredFormatFunctor4(),
                      ++n1_,
                      ++n2_,
                      ++n3_,
                      ++n4_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT4 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT4Test, FunctorOnUserTypeSuccess) {
  EXPECT_PRED_FORMAT4(PredFormatFunctor4(),
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_),
                      Bool(++n4_));
  finished_ = true;
}

// Tests a failed EXPECT_PRED_FORMAT4 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT4Test, FunctionOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT4(PredFormatFunction4,
                        n1_++,
                        n2_++,
                        n3_++,
                        n4_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT4 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT4Test, FunctionOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT4(PredFormatFunction4,
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++),
                        Bool(n4_++));
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT4 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT4Test, FunctorOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT4(PredFormatFunctor4(),
                        n1_++,
                        n2_++,
                        n3_++,
                        n4_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT4 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT4Test, FunctorOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT4(PredFormatFunctor4(),
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++),
                        Bool(n4_++));
    finished_ = true;
  }, "");
}

// Tests a successful ASSERT_PRED_FORMAT4 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT4Test, FunctionOnBuiltInTypeSuccess) {
  ASSERT_PRED_FORMAT4(PredFormatFunction4,
                      ++n1_,
                      ++n2_,
                      ++n3_,
                      ++n4_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT4 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT4Test, FunctionOnUserTypeSuccess) {
  ASSERT_PRED_FORMAT4(PredFormatFunction4,
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_),
                      Bool(++n4_));
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT4 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT4Test, FunctorOnBuiltInTypeSuccess) {
  ASSERT_PRED_FORMAT4(PredFormatFunctor4(),
                      ++n1_,
                      ++n2_,
                      ++n3_,
                      ++n4_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT4 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT4Test, FunctorOnUserTypeSuccess) {
  ASSERT_PRED_FORMAT4(PredFormatFunctor4(),
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_),
                      Bool(++n4_));
  finished_ = true;
}

// Tests a failed ASSERT_PRED_FORMAT4 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT4Test, FunctionOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT4(PredFormatFunction4,
                        n1_++,
                        n2_++,
                        n3_++,
                        n4_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT4 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT4Test, FunctionOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT4(PredFormatFunction4,
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++),
                        Bool(n4_++));
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT4 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT4Test, FunctorOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT4(PredFormatFunctor4(),
                        n1_++,
                        n2_++,
                        n3_++,
                        n4_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT4 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT4Test, FunctorOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT4(PredFormatFunctor4(),
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++),
                        Bool(n4_++));
    finished_ = true;
  }, "");
}
// Sample functions/functors for testing 5-ary predicate assertions.

// A 5-ary predicate function.
template <typename T1, typename T2, typename T3, typename T4, typename T5>
bool PredFunction5(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5) {
  return v1 + v2 + v3 + v4 + v5 > 0;
}

// The following two functions are needed because a compiler doesn't have
// a context yet to know which template function must be instantiated.
bool PredFunction5Int(int v1, int v2, int v3, int v4, int v5) {
  return v1 + v2 + v3 + v4 + v5 > 0;
}
bool PredFunction5Bool(Bool v1, Bool v2, Bool v3, Bool v4, Bool v5) {
  return v1 + v2 + v3 + v4 + v5 > 0;
}

// A 5-ary predicate functor.
struct PredFunctor5 {
  template <typename T1, typename T2, typename T3, typename T4, typename T5>
  bool operator()(const T1& v1,
                  const T2& v2,
                  const T3& v3,
                  const T4& v4,
                  const T5& v5) {
    return v1 + v2 + v3 + v4 + v5 > 0;
  }
};

// A 5-ary predicate-formatter function.
template <typename T1, typename T2, typename T3, typename T4, typename T5>
::jmsd::cutf::AssertionResult PredFormatFunction5(const char* e1,
                                             const char* e2,
                                             const char* e3,
                                             const char* e4,
                                             const char* e5,
                                             const T1& v1,
                                             const T2& v2,
                                             const T3& v3,
                                             const T4& v4,
                                             const T5& v5) {
  if (PredFunction5(v1, v2, v3, v4, v5))
    return ::jmsd::cutf::AssertionResult::AssertionSuccess();

  return ::jmsd::cutf::AssertionResult::AssertionFailure()
      << e1 << " + " << e2 << " + " << e3 << " + " << e4 << " + " << e5
      << " is expected to be positive, but evaluates to "
      << v1 + v2 + v3 + v4 + v5 << ".";
}

// A 5-ary predicate-formatter functor.
struct PredFormatFunctor5 {
  template <typename T1, typename T2, typename T3, typename T4, typename T5>
  ::jmsd::cutf::AssertionResult operator()(const char* e1,
                                      const char* e2,
                                      const char* e3,
                                      const char* e4,
                                      const char* e5,
                                      const T1& v1,
                                      const T2& v2,
                                      const T3& v3,
                                      const T4& v4,
                                      const T5& v5) const {
    return PredFormatFunction5(e1, e2, e3, e4, e5, v1, v2, v3, v4, v5);
  }
};

// Tests for {EXPECT|ASSERT}_PRED_FORMAT5.

class Predicate5Test : public ::jmsd::cutf::Test {
 protected:
  void SetUp() override {
    expected_to_finish_ = true;
    finished_ = false;
    n1_ = n2_ = n3_ = n4_ = n5_ = 0;
  }

  void TearDown() override {
    // Verifies that each of the predicate's arguments was evaluated
    // exactly once.
    EXPECT_EQ(1, n1_) <<
        "The predicate assertion didn't evaluate argument 2 "
        "exactly once.";
    EXPECT_EQ(1, n2_) <<
        "The predicate assertion didn't evaluate argument 3 "
        "exactly once.";
    EXPECT_EQ(1, n3_) <<
        "The predicate assertion didn't evaluate argument 4 "
        "exactly once.";
    EXPECT_EQ(1, n4_) <<
        "The predicate assertion didn't evaluate argument 5 "
        "exactly once.";
    EXPECT_EQ(1, n5_) <<
        "The predicate assertion didn't evaluate argument 6 "
        "exactly once.";

    // Verifies that the control flow in the test function is expected.
    if (expected_to_finish_ && !finished_) {
      FAIL() << "The predicate assertion unexpactedly aborted the test.";
    } else if (!expected_to_finish_ && finished_) {
      FAIL() << "The failed predicate assertion didn't abort the test "
                "as expected.";
    }
  }

  // true if and only if the test function is expected to run to finish.
  static bool expected_to_finish_;

  // true if and only if the test function did run to finish.
  static bool finished_;

  static int n1_;
  static int n2_;
  static int n3_;
  static int n4_;
  static int n5_;
};

bool Predicate5Test::expected_to_finish_;
bool Predicate5Test::finished_;
int Predicate5Test::n1_;
int Predicate5Test::n2_;
int Predicate5Test::n3_;
int Predicate5Test::n4_;
int Predicate5Test::n5_;

typedef Predicate5Test EXPECT_PRED_FORMAT5Test;
typedef Predicate5Test ASSERT_PRED_FORMAT5Test;
typedef Predicate5Test EXPECT_PRED5Test;
typedef Predicate5Test ASSERT_PRED5Test;

// Tests a successful EXPECT_PRED5 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED5Test, FunctionOnBuiltInTypeSuccess) {
  EXPECT_PRED5(PredFunction5Int,
               ++n1_,
               ++n2_,
               ++n3_,
               ++n4_,
               ++n5_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED5 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED5Test, FunctionOnUserTypeSuccess) {
  EXPECT_PRED5(PredFunction5Bool,
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_),
               Bool(++n4_),
               Bool(++n5_));
  finished_ = true;
}

// Tests a successful EXPECT_PRED5 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED5Test, FunctorOnBuiltInTypeSuccess) {
  EXPECT_PRED5(PredFunctor5(),
               ++n1_,
               ++n2_,
               ++n3_,
               ++n4_,
               ++n5_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED5 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED5Test, FunctorOnUserTypeSuccess) {
  EXPECT_PRED5(PredFunctor5(),
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_),
               Bool(++n4_),
               Bool(++n5_));
  finished_ = true;
}

// Tests a failed EXPECT_PRED5 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED5Test, FunctionOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED5(PredFunction5Int,
                 n1_++,
                 n2_++,
                 n3_++,
                 n4_++,
                 n5_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED5 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED5Test, FunctionOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED5(PredFunction5Bool,
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++),
                 Bool(n4_++),
                 Bool(n5_++));
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED5 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED5Test, FunctorOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED5(PredFunctor5(),
                 n1_++,
                 n2_++,
                 n3_++,
                 n4_++,
                 n5_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED5 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED5Test, FunctorOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED5(PredFunctor5(),
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++),
                 Bool(n4_++),
                 Bool(n5_++));
    finished_ = true;
  }, "");
}

// Tests a successful ASSERT_PRED5 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED5Test, FunctionOnBuiltInTypeSuccess) {
  ASSERT_PRED5(PredFunction5Int,
               ++n1_,
               ++n2_,
               ++n3_,
               ++n4_,
               ++n5_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED5 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED5Test, FunctionOnUserTypeSuccess) {
  ASSERT_PRED5(PredFunction5Bool,
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_),
               Bool(++n4_),
               Bool(++n5_));
  finished_ = true;
}

// Tests a successful ASSERT_PRED5 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED5Test, FunctorOnBuiltInTypeSuccess) {
  ASSERT_PRED5(PredFunctor5(),
               ++n1_,
               ++n2_,
               ++n3_,
               ++n4_,
               ++n5_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED5 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED5Test, FunctorOnUserTypeSuccess) {
  ASSERT_PRED5(PredFunctor5(),
               Bool(++n1_),
               Bool(++n2_),
               Bool(++n3_),
               Bool(++n4_),
               Bool(++n5_));
  finished_ = true;
}

// Tests a failed ASSERT_PRED5 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED5Test, FunctionOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED5(PredFunction5Int,
                 n1_++,
                 n2_++,
                 n3_++,
                 n4_++,
                 n5_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED5 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED5Test, FunctionOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED5(PredFunction5Bool,
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++),
                 Bool(n4_++),
                 Bool(n5_++));
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED5 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED5Test, FunctorOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED5(PredFunctor5(),
                 n1_++,
                 n2_++,
                 n3_++,
                 n4_++,
                 n5_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED5 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED5Test, FunctorOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED5(PredFunctor5(),
                 Bool(n1_++),
                 Bool(n2_++),
                 Bool(n3_++),
                 Bool(n4_++),
                 Bool(n5_++));
    finished_ = true;
  }, "");
}

// Tests a successful EXPECT_PRED_FORMAT5 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT5Test, FunctionOnBuiltInTypeSuccess) {
  EXPECT_PRED_FORMAT5(PredFormatFunction5,
                      ++n1_,
                      ++n2_,
                      ++n3_,
                      ++n4_,
                      ++n5_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT5 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT5Test, FunctionOnUserTypeSuccess) {
  EXPECT_PRED_FORMAT5(PredFormatFunction5,
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_),
                      Bool(++n4_),
                      Bool(++n5_));
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT5 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT5Test, FunctorOnBuiltInTypeSuccess) {
  EXPECT_PRED_FORMAT5(PredFormatFunctor5(),
                      ++n1_,
                      ++n2_,
                      ++n3_,
                      ++n4_,
                      ++n5_);
  finished_ = true;
}

// Tests a successful EXPECT_PRED_FORMAT5 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT5Test, FunctorOnUserTypeSuccess) {
  EXPECT_PRED_FORMAT5(PredFormatFunctor5(),
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_),
                      Bool(++n4_),
                      Bool(++n5_));
  finished_ = true;
}

// Tests a failed EXPECT_PRED_FORMAT5 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT5Test, FunctionOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT5(PredFormatFunction5,
                        n1_++,
                        n2_++,
                        n3_++,
                        n4_++,
                        n5_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT5 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT5Test, FunctionOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT5(PredFormatFunction5,
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++),
                        Bool(n4_++),
                        Bool(n5_++));
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT5 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(EXPECT_PRED_FORMAT5Test, FunctorOnBuiltInTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT5(PredFormatFunctor5(),
                        n1_++,
                        n2_++,
                        n3_++,
                        n4_++,
                        n5_++);
    finished_ = true;
  }, "");
}

// Tests a failed EXPECT_PRED_FORMAT5 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(EXPECT_PRED_FORMAT5Test, FunctorOnUserTypeFailure) {
  EXPECT_NONFATAL_FAILURE({  // NOLINT
    EXPECT_PRED_FORMAT5(PredFormatFunctor5(),
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++),
                        Bool(n4_++),
                        Bool(n5_++));
    finished_ = true;
  }, "");
}

// Tests a successful ASSERT_PRED_FORMAT5 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT5Test, FunctionOnBuiltInTypeSuccess) {
  ASSERT_PRED_FORMAT5(PredFormatFunction5,
                      ++n1_,
                      ++n2_,
                      ++n3_,
                      ++n4_,
                      ++n5_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT5 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT5Test, FunctionOnUserTypeSuccess) {
  ASSERT_PRED_FORMAT5(PredFormatFunction5,
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_),
                      Bool(++n4_),
                      Bool(++n5_));
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT5 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT5Test, FunctorOnBuiltInTypeSuccess) {
  ASSERT_PRED_FORMAT5(PredFormatFunctor5(),
                      ++n1_,
                      ++n2_,
                      ++n3_,
                      ++n4_,
                      ++n5_);
  finished_ = true;
}

// Tests a successful ASSERT_PRED_FORMAT5 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT5Test, FunctorOnUserTypeSuccess) {
  ASSERT_PRED_FORMAT5(PredFormatFunctor5(),
                      Bool(++n1_),
                      Bool(++n2_),
                      Bool(++n3_),
                      Bool(++n4_),
                      Bool(++n5_));
  finished_ = true;
}

// Tests a failed ASSERT_PRED_FORMAT5 where the
// predicate-formatter is a function on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT5Test, FunctionOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT5(PredFormatFunction5,
                        n1_++,
                        n2_++,
                        n3_++,
                        n4_++,
                        n5_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT5 where the
// predicate-formatter is a function on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT5Test, FunctionOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT5(PredFormatFunction5,
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++),
                        Bool(n4_++),
                        Bool(n5_++));
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT5 where the
// predicate-formatter is a functor on a built-in type (int).
TEST_F(ASSERT_PRED_FORMAT5Test, FunctorOnBuiltInTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT5(PredFormatFunctor5(),
                        n1_++,
                        n2_++,
                        n3_++,
                        n4_++,
                        n5_++);
    finished_ = true;
  }, "");
}

// Tests a failed ASSERT_PRED_FORMAT5 where the
// predicate-formatter is a functor on a user-defined type (Bool).
TEST_F(ASSERT_PRED_FORMAT5Test, FunctorOnUserTypeFailure) {
  expected_to_finish_ = false;
  EXPECT_FATAL_FAILURE({  // NOLINT
    ASSERT_PRED_FORMAT5(PredFormatFunctor5(),
                        Bool(n1_++),
                        Bool(n2_++),
                        Bool(n3_++),
                        Bool(n4_++),
                        Bool(n5_++));
    finished_ = true;
  }, "");
}
