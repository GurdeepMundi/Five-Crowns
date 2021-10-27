/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: AllModel.cpp
* Date Created: 16/10/2021
*/
#include <AIModel.h>
#include <random>

void AIModel::discard(int d) {
  // Seed with a real random value, if available
  std::random_device r;
  // random number between 0 to size of hand -1
  std::default_random_engine rn(r());
  std::uniform_int_distribution<int> uniform_dist(0, hand->getSize());
  int randomNumber = uniform_dist(rn);
  hand->removeCard(randomNumber);
}
