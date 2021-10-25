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
  /**Used to assign a score value to card
  *@param scoreValue score value of the card
  */
  void setScoreValue(int scoreValue);
  /**Used to get score value of the card
  */
  int getScoreValue();
  /**Used to set the rank (number) of the card
  *@param r rank of the card
  */
  void setRank(int r);
  /**Used to set the suit of the card
  *@param s suit of the card
  */
  void setSuit(Suits s);
 private:
int rank;
int scoreValue;
bool isWild;
Suits suit;
};
#endif
