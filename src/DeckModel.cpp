/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: DeckModel.cpp
* Date Created: 16/10/2021
*/
#include <DeckModel.h>
#include <vector>
#include <random>
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
  if (deck.size() == 0) {
    break;
  } else if (p == deck.size()-1) {
    deck.pop_back();
  } else {
    for (int i = p; i < (deck.size()); i++) {
      deck[i] = deck[i+1];
    }
    deck.pop_back();
  }
}

void DeckModel::emptyDeck() {
  for (int i = 0; i < (deck.size()); i++) {
    removeCard(i);
  }
}

CardModel* DeckModel::getCardAt(int cardAddress) {
  return deck.at(cardAddress);
}

CardModel* DeckModel::getTopCard() {
  return deck.at(deck.size() - 1);
}

int DeckModel::getSize() {
  return deck.size();
}
