#include <gtest/gtest.h>

#include "../src/calculator.h"
#include <vector>
#include <string>

TEST(TestSuccess, Success) {
  Calculator calculator;

  std::vector<std::vector<std::string>> good_cases {
  {"2 + 2", "4"},
  {"1 + 2 * 3", "7"},
  {"1 + 5 * 3 / 2", "8"},
  {"1", "1"},
  {"2 +- 2", "0"},
  {"2-3*4*2+1--2+-5/2", "-21"},
  };

  for (auto x : good_cases)
      EXPECT_EQ(std::stoi(x[1]), calculator.calc(x[0]));
}

TEST(TestException, Exception) {
  Calculator calculator;

  std::vector<std::string> bad_cases = {
  "",
  "1 --",
  "1 + -",
  "12 2",
  "1/0",
  "3 + a"
  };

  for (auto x : bad_cases)
      EXPECT_ANY_THROW(calculator.calc(x));
}

