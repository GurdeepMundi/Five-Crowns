/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File:PlayerModel.h
* Date Created: 16/10/2021
*/
#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <CardModel.h>
#include <string>
#include <vector>
/***
*this is the parent class of all of the players
*/
class PlayerModel {
 public:
  /**This function sets the name of the player
  *@param n this will be the player's name
  */
  void setName(std::string n);
  /**This function can be used to get the player's name
  */
  std::string getname();
  /**This function used to remove a card from the user's hand and put to
  *the discard pile
  *@param d this is the card to be removed from hand
  */
  virtual void discard(int d) = 0;
  /**This function is used to draw a card from the draw pile
  */
  void draw(CardModel<deck>);
  /** sort function might not be implemented
  *void sort();
  *This function lets the user make a run (lay 3 or more consecutive cards
  *from same suit)
  */
  std::vector<CardModel*> makeRun();
  /**This function lets the user make a book (3 or more cards of same rank)
  */
  std::vector<CardModel*> makeBook();

 private:
  std::vector <CardModel*> deck;
  /**
  *@ Vector to store information about the players hand
  */
  std::vector<CardModel*> hand;
  /**
  *@ variable score is used to track accumulated score
  */
  int score;
  /**
  *@ string to store the name of the player
  */
  std::string name;///name of the player
};

#endif
