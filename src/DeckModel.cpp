/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: DeckModel.cpp
* Date Created: 16/10/2021
*/
#include <DeckModel.h>
DeckModel::DeckModel() {
  //constructor
}

void DeckModel::shuffle() {
  for(int i = 0; i < deck.size(); i++) {

  }
}

void DeckModel::addcard(CardModel* c) {
  deck.push_back(c);
}
