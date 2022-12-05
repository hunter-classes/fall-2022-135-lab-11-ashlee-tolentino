#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"
#include <string>
#include <cctype>

TEST_CASE("Profile Class"){
  Profile p1;
  CHECK(p1.getUsername() == "");
  CHECK(p1.getFullName() == " (@)");
  p1.setDisplayName("Anna");
  CHECK(p1.getFullName() == "Anna (@)");
  
  Profile p2("ash8", "Ashlee");
  CHECK(p2.getUsername() == "ash8");
  CHECK(p2.getFullName() == "Ashlee (@ash8)");
  p2.setDisplayName("Ash");
  CHECK(p2.getFullName() == "Ash (@ash8)");
}

/*
TEST_CASE("Network Class"){
  
}
*/
