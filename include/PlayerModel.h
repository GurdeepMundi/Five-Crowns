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
#include <DeckModel.h>
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
  /**This function used to remove a card from the user's hand so that it can be
  *put on the discard pile
  *@param d address of the card to be removed from the hand
  */
  virtual void discard(int d) = 0;
  /**This function is used to draw a card from the draw pile
  */
  void draw(CardModel* c);
  /* sort function might not be implemented
  *void sort();*/
  /**This function lets the user make a run (lay 3 or more consecutive cards
  *from same suit)
  */
  void makeRun(std::vector<int> cardAddresses);
  /**This function lets the user make a book (3 or more cards of same rank)
  */
  void makeBook(std::vector<int> cardAddresses);
  /**checks if the run is valid
  * \returns true if the cards given meet requirements to make a run
  *\retval <false> wrong combination of cards
  */
  bool isValidRun(std::vector<int> cardAddresses);
  bool isValidBook(std::vector<int> cardAddresses);

 private:
  std::vector <CardModel*> deck;
  /**
  *@ Vector to store information about the players hand
  */
  DeckModel hand;
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
