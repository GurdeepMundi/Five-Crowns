/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: DeckModel.cpp
* Date Created: 16/10/2021
*/
#include <DeckModel.h>
#include <vector>
#include <random>
#include <iostream>
DeckModel::DeckModel() {
  //constructor
}

void DeckModel::shuffle() {
  std::vector <CardModel*> buffer;
  int insertPosition;
  //seed witha real random value
  std::random_device r;
  std::default_random_engine e1(r());
  for (int i = 0; i < deck.size(); i++) {
    std::uniform_int_distribution<int> uniform_dist(0, buffer.size());
    insertPosition = uniform_dist(e1);
    //insert this element at a random location in buffer
    buffer.insert(buffer.begin() + insertPosition, deck.at(i));
  }
  deck = buffer;
}

void DeckModel::addCard(CardModel* c) {
  deck.push_back(c);
}

void DeckModel::removeCard(int p) {
  deck.erase((deck.begin() + p-1));
}

void DeckModel::emptyDeck() {
  deck.clear();
}

CardModel* DeckModel::getCardAt(int cardAddress) {
  return deck.at(cardAddress);
}

CardModel* DeckModel::getTopCard() {
  return this->getCardAt(this->getSize()-1);
}

int DeckModel::getSize() {
  return deck.size();
}

void DeckModel::setWild(int roundNumber) {
  for (int i = 0; i < deck.size(); i++) {
    if (deck.at(i)->getRank() == roundNumber + 2) {
      deck.at(i)->setWildStatus(true);
      deck.at(i)->setScoreValue(20);
    }
  }
}
