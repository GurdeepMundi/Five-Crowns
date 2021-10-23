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
//Gurdeep working on this fucntion
void PlayerModel::makeRun(std::vector<int> cardAddresses) {
  vector <CardModel*> cardsUnderInspection;
  for(int ob: cardAddresses) {
    cardsUnderInspection.push_back(hand.getCardAt(ob));
  }
  // sort this vector
  //wildcards go to front
  //then

}

void PlayerModel::makeBook(std::vector<int> cardAddresses) {
  // code here
}

bool PlayerModel::isValidRun(std::vector<int> cardAddresses) {
  for(int i = 0; i < cardAddresses.size() -1; i++) {
    if () {

    }
  }
}
bool PlayerModel::isValidBook(std::vector<int> cardAddresses) {
  // code here
}
