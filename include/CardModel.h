/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File:CardModel.h
* Date Created: 16/10/2021
*/
#ifndef CARDMODEL_H
#define CARDMODEL_H

#include <iostream>

enum Suits {CLUBS, HEARTS, SPADES, DIAMONDS, STARS};

class CardModel {
 public:
   // Sahil is working on this
  void setScoreValue(int scoreValue);
  // Sahil is working on this
  int getScoreValue();

  void setRank(int r);
  // Muhammad
  void setSuit(Suits s);
  // Muhammad
 private:
int rank;
int scoreValue;
bool isWild;
Suits suit;

};
#endif
