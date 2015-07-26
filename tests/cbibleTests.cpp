/*
 * Copyright Tim Hawes 2015
 */

#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "include/catch.hpp"

#include "../src/SwordFuncs.hpp"

TEST_CASE( "Tests for SwordFuncs", "[SwordFuncs]" ) {

  SwordFuncs *sw = new SwordFuncs("KJV");
  SECTION ( "Testing SwordFuncs" ) {
    REQUIRE( sw->parseInput(const_cast<char *>("Gen 1:1")) ==
             " 1 In the beginning God created the heaven and the earth.");
    REQUIRE( sw->modname() == "KJV" );
    REQUIRE( sw->currentRef() == "Genesis 1:1" );
    REQUIRE( sw->currentText() ==
             " 1 In the beginning God created the heaven and the earth.");
    REQUIRE( sw->lookup("Rom 8:28") == " 28 And we know that all things work together for good to them that love God, to them who are the called according to his purpose.");
    REQUIRE( sw->currentRef() == "Romans 8:28" );
  }
  free(sw);
}
