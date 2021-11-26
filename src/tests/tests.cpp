#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch.hpp"

TEST_CASE("FindMax")
{

  SECTION("Should find max of consecutive numbers")
  {
    REQUIRE(4 == 4);
  }

  SECTION("Should find max of non consecutive numbers")
  {
    REQUIRE(7 == 7);
  }
}
