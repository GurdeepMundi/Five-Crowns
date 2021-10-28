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

DeckModel* PlayerModel::getHand() {
  return this->hand;
}

void PlayerModel::addScore(int s) {
  this->score = this->score + s;
}
// void PlayerModel::sort() {
//  // code here😏
// }
void PlayerModel::draw(CardModel* c) {
  hand->addCard(c);
}

void PlayerModel::makeRun(std::vector<int> cardAddresses) {
  if (isValidRun(cardAddresses)) {
    //sorting the vector because removing the card higher in address doesn't
    //affect cards at the front
    std::sort(cardAddresses.begin(), cardAddresses.end(), std::greater<int>());
    for (int ob : cardAddresses) {
      hand->removeCard(ob-1);
    }
  }
}

void PlayerModel::makeBook(std::vector<int> cardAddresses) {
  if (isValidBook(cardAddresses)) {
    //sorting the vector because removing the card higher in address doesn't
    //affect cards at the front
    std::sort(cardAddresses.begin(), cardAddresses.end(), std::greater<int>());
    for (int ob : cardAddresses) {
      hand->removeCard(ob-1);
    }
  }
}

bool PlayerModel::isValidRun(std::vector<int> cardAddresses) {
  // makes sure run is atleast 3 cards
  if (cardAddresses.size() < 3) {
    return false;
  }
  //this vector will be containing the cards that the user wants to lay
  //as a run
  std::vector <CardModel*> cardsUnderInspection;
  int wildCards = 0;
  //populating the vector cardsUnderInspection
  for (int ob : cardAddresses) {
    cardsUnderInspection.push_back(hand->getCardAt(ob));
  }
  //sorting the vector by scoreValue to support further operations and put
  //wild cards at the back
  for (int i = 0; i < cardsUnderInspection.size()-1; i++) {
    CardModel* temp = cardsUnderInspection.at(i);
    for (int j = i+1; j < cardsUnderInspection.size(); j++) {
      //compare with every card next to it
      if (cardsUnderInspection.at(i)->getScoreValue() > \
      cardsUnderInspection.at(j)->getScoreValue()) {
        //swap if current card is smaller than next one
        cardsUnderInspection.at(i) = cardsUnderInspection.at(j);
        cardsUnderInspection.at(j) = temp;
      }
    }
    delete temp;
  }
  // counting the wildCards
  for (int i = 0; i < cardsUnderInspection.size(); i++) {
    if (cardsUnderInspection.at(i)->isWildStatus()) {
      wildCards = wildCards + 1;
    }
  }
  //checking if the run is possible
  for (int i = 0; i < cardAddresses.size() -1; i++) {
    if ((cardsUnderInspection.at(i)->getSuit() != \
    cardsUnderInspection.at(i+1)->getSuit()) || \
    (cardsUnderInspection.at(i)->getRank() != \
    cardsUnderInspection.at(i+1)->getRank())) {
      if (wildCards < 1) {
        // if next card is invalid and no wilds, return false
        return false;
      } else {
        // if next card is invalid and there are wilds,
        // make the next card in the run,
        // insert it before the next and remove a wild card
        CardModel* temp;
        temp->setRank(cardsUnderInspection.at(i)->getRank()+1);
        temp->setSuit(cardsUnderInspection.at(i)->getSuit());
        temp->setScoreValue(cardsUnderInspection.at(i)->getScoreValue()+1);
        temp->setWildStatus(false);
        cardsUnderInspection.insert(cardsUnderInspection.begin()+i+1, temp);
        cardsUnderInspection.pop_back();
        delete temp;
        wildCards = wildCards - 1;
      }
    } else {}
  }
  return true;
}

bool PlayerModel::isValidBook(std::vector<int> cardAddresses) {
  // makes sure book is atleast 3 cards
  if (cardAddresses.size() < 3) {
    return false;
  }
  //this vector will be containing the cards that the user wants to lay
  //as a book
  std::vector <CardModel*> cardsUnderInspection;
  int cardRank;
  //populating the vector cardsUnderInspection
  for (int ob : cardAddresses) {
    cardsUnderInspection.push_back(hand->getCardAt(ob));
  }
  for (int i = 0; i < cardAddresses.size() ; i++) {
    if (cardsUnderInspection.at(i)->isWildStatus()) {
      continue;
    } else {
      cardRank = cardsUnderInspection.at(i)->getRank();
      break;
    }
  }
  // checking if the book is possible to be made
  for (int i = 0; i < cardAddresses.size() ; i++) {
    if ((cardsUnderInspection.at(i)->isWildStatus()) || \
    (cardsUnderInspection.at(i)->getRank() == cardRank)) {
    } else {
      return false;
    }
  }
  return true;
}
