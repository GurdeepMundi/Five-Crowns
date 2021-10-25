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
#include <algorithm>
#include <functional>

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
  if (isValidRun(cardAddresses)) {
    //sorting the vector because removing the card higher in address doesn't
    //cards at the front
    std::sort(cardAddresses.begin(), cardAddresses.end(), std::greater<int>());
    for (int ob : cardAddresses) {
      hand.removeCard(ob);
    }
  }
}

void PlayerModel::makeBook(std::vector<int> cardAddresses) {

}
//Gurdeep working on this fucntion
bool PlayerModel::isValidRun(std::vector<int> cardAddresses) {
  //this vector will be containing the cards that the user wants to lay
  //as a run
  std::vector <CardModel*> cardsUnderInspection;
  //populating the vector cardsUnderInspection
  for (int ob : cardAddresses) {
    cardsUnderInspection.push_back(hand.getCardAt(ob));
  }
  //sorting the vector by rank to support further operations
  for (int i = 0; i < cardsUnderInspection.size()-1; i++) {
    CardModel* temp = cardsUnderInspection.at(i);
    for (int j = i+1; j < cardsUnderInspection.size(); j++) {
      //compare with every card next to it
      if (cardsUnderInspection.at(i)->getRank() > \
      cardsUnderInspection.at(j)->getRank()) {
        //swap if current card is smaller than next one
        cardsUnderInspection.at(i) = cardsUnderInspection.at(j);
        cardsUnderInspection.at(j) = temp;
      }
    }
    delete temp;
  }
  //putting the wildcarsds in front of the vector
  for (int i = 0; i< cardsUnderInspection.size(); i++) {
    if (cardsUnderInspection.at(i)->isWildStatus()) {
      CardModel* temp = cardsUnderInspection.at(i);
      cardsUnderInspection.erase(cardsUnderInspection.begin() + i);
      cardsUnderInspection.insert(cardsUnderInspection.begin(), temp);
      delete temp;
    }
  }
  //checking if the run is possible
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
