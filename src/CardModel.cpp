/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: CardModel.cpp
* Date Created: 16/10/2021
*/
#include <CardModel.h>

void CardModel::setScoreValue(int scoreValue) {
  this->scoreValue = scoreValue;
}

int CardModel::getScoreValue() {
  return this->scoreValue;
}

void CardModel::setRank(int r) {
  this->rank = r;
}

void CardModel::setSuit(Suits s) {
  this->suit = s;
}

Suits CardModel::getSuit() {
  return this->suit;
}

int CardModel::getRank() {
  return rank;
}

void CardModel::setWildStatus(bool newStatus) {
  this->isWild = newStatus;
}

bool CardModel::isWildStatus() {
  return this->isWild;
}
