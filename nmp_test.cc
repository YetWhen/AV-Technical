#include <gtest/gtest.h>
#include "main.cpp"

// Demonstrate some basic assertions.
TEST(nmp_test, BasicAssertions) {
  // Expect two strings not to be equal.
  ASSERT_EQ (5000, testerFunction());
}

