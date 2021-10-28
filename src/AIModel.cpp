/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: AllModel.cpp
* Date Created: 16/10/2021
*/
#include <AIModel.h>
#include <random>

void AIModel::discard(int d) {
  hand->removeCard(0);
}
