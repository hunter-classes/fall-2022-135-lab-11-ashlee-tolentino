/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab11

This program works with classes and object-oriented programming.
*/

#include <iostream>
#include <string>
#include <cctype>
#include "profile.h"

/**
   Task A: This program implements the class Profile that can store the info about a user of the network.
 */
Profile::Profile(std::string usrn, std::string dspn) {
  username = usrn;
  displayname = dspn;
}

Profile::Profile() {
  username = "";
  displayname = "";
}

std::string Profile::getUsername() {
  return username;
}

std::string Profile::getFullName() {
  std::string result = "";
  result = result + displayname + " (@" + username + ")";
  return result;
}

void Profile::setDisplayName(std::string dspn) {
  displayname = dspn;
}
