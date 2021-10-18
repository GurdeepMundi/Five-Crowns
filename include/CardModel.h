/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File:CardModel.h
* Date Created: 16/10/2021
*/
#ifndef CARDMODEL_H
#define CARDMODEL_H

#include <iostream>

class CardModel {
 public:
   // Sahil is working on this
  void getScoreValue(score:int);
  // Sahil is working on this
  int getScoreValue();

  void setRank(rank:int);

  void setSuit(s:suit);
 private:
int rank;
int scoreValue;
bool isWild;

};
#endif
