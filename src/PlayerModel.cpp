/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: PlayerModel.cpp
* Date Created: 16/10/2021
*/
#include <PlayerModel.h>
#include <CardModel.h>
#include <DeckModel.h>
#include <string>
#include <vector>

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
//  // code here😏
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
//Gurdeep working on this fucntion
bool PlayerModel::isValidRun(std::vector<int> cardAddresses) {
  std::vector <CardModel*> cardsUnderInspection;
  for (int ob : cardAddresses) {
    cardsUnderInspection.push_back(hand.getCardAt(ob));
  }
  // sort cardsUnderInspection
  //wildcards go to front
  //then

  for (int i = 0; i < cardAddresses.size() -1; i++) {
    if (cardsUnderInspection.at(i)->getSuit() \
    != cardsUnderInspection.at(i+1)->getSuit()) {
      if (!cardsUnderInspection.at(i)->isWildStatus()) {
        return false;
      } else if (cardsUnderInspection.at(i)->getRank() \
      != cardsUnderInspection.at(i + 1)->getRank()) {
        return false;
      }
    }
  }
  return true;
}
bool PlayerModel::isValidBook(std::vector<int> cardAddresses) {
  // code here
}
