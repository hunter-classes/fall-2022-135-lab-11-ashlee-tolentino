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

TEST_CASE("Network Class"){
  Network n1;
  CHECK(n1.addUser("mario", "Mario") == true);
  CHECK(n1.addUser("luigi", "Luigi") == true);
  CHECK(n1.addUser("mario", "Mario2") == false);
  CHECK(n1.addUser("mario 2", "Mario2") == false);
  CHECK(n1.addUser("mario-2", "Mario2") == false);
  for(int i = 2; i < 20; i++) {
    n1.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i));
  }
  CHECK(n1.addUser("yoshi", "Yoshi") == false);

  Network n2;
  n2.addUser("mario", "Mario");
  n2.addUser("luigi", "Luigi");
  n2.addUser("yoshi", "Yoshi");
  CHECK(n2.follow("mario", "luigi") == true);
  CHECK(n2.follow("yoshi", "luigi") == true);
  CHECK(n2.follow("wario", "mario") == false);
  CHECK(n2.follow("luigi", "wario") == false);
}

