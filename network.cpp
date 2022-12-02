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
#include "network.h"

/**
   Task B & C: This program implements the improved version of the class Network, which will keep the friendship (following) relation between the users.
*/
int Network::findID(std::string usrn) {
  for(int i = 0; i < MAX_USERS; i++)
  {
    if(profiles[i].getUsername() == usrn)
    {
      return i;
    }
  }
  return -1;
}

Network::Network() {
  numUsers = 0;
  for(int r = 0; r < MAX_USERS; r++)
  {
    for(int c = 0; c < MAX_USERS; c++)
    {
      following[r][c] = false;
    }
  }
}

bool Network::addUser(std::string usrn, std::string dspn) {
  int ID = findID(usrn);

  for(int i = 0; i < usrn.length(); i++)
  {
    if(!(isalnum(usrn[i])))
    {
      return false;
    }
  }
  
  if(numUsers < 20 && ID == -1)
  {
    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;
    return true;
  }
  else
  {
    return false;
  }
}

// Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
// return true if success (if both usernames exist), otherwise return false
bool Network::follow(std::string usrn1, std::string usrn2) {
  int ID1 = findID(usrn1);
  int ID2 = findID(usrn2);
  
  if(ID1 != -1 && ID2 != -1)
  {
    following[ID1][ID2] = true;
    return true;
  }
  else
  {
    return false;
  }
}

// Print Dot file (graphical representation of the network)
void Network::printDot() {
  std::cout << "digraph {\n";

  for(int i = 0; i < numUsers; i++)
  {
    std::cout << "  \"@" << profiles[i].getUsername() << "\"\n";
  }
  std::cout << "\n";

  for(int r = 0; r < numUsers; r++)
  {
    for (int c = 0; c < numUsers; c++)
    {
      if(following[r][c] == true)
      {
	std::cout << "  \"@" << profiles[r].getUsername() << "\" -> \"@" << profiles[c].getUsername() << "\"\n";
      }
    }
  }
  std::cout << "}\n";
  
}
