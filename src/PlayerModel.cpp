/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: PlayerModel.cpp
* Date Created: 16/10/2021
*/
#include <PlayerModel.h>
#include <CardModel.h>
#include <string>
#include <vector>
#include "DeckModel.h"

void PlayerModel::setName(std::string n) {
  this->name = n;
}

std::string PlayerModel::getname() {
  return this->name;
}

void PlayerModel::discard(int d) {
  hand.removeCard(d);
}

// void PlayerModel::sort() {
//  // code here
// }

void PlayerModel::draw(CardModel* c) {
  hand.addCard(c);
}

void PlayerModel::makeRun(std::vector<int> cardAddresses) {
  // code here
}

void PlayerModel::makeBook(std::vector<int> cardAddresses) {
  // code here
}

bool PlayerModel::isValidRun(std::vector<int> cardAddresses) {
  // code here
}
void PlayerModel::isValidBook(std::vector<int> cardAddresses) {
  // code here
}
