/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: CardModel.cpp
* Date Created: 16/10/2021
*/
#include "./include/CardModel.h"

void Card::setScoreValue(int scoreValue) {
  this->scoreValue = scoreValue;
}

int Card::getScoreValue() {
  return this->scoreValue;
}

void Card::setRank(int r) {
  rank = r
}

void Card::setSuit(Suits s) {
  suit = s
}
