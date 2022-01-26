/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh
* File: DeckModel.h
* Date Created: 16/10/2021
*/
#ifndef DECKMODEL_H
#define DECKMODEL_H
#include <CardModel.h>
#include <vector>
#include <iostream>
#include <ctime>

class DeckModel {
 public:
  DeckModel();
  /**this function will be used to shuffle the deck
  */
  void shuffle();
  /**this function can be used to add a card into the deck
  *@param c the card to be added
  */
  void addCard(CardModel* c);
  /**this function can be used to remove a card from the deck
  *@param p the address of the card to be removed (0 = 1st element)
  */
  void removeCard(int p);
  /**this function can be used to empty the deck
  */
  void emptyDeck();
  /**
  *\returns card stored at the given address in the deck
  *@param cardAddress the address from which the card needs to be retrieved
  * (0= first element)
  */
  CardModel* getCardAt(int cardAddress);
  /**
  *\returns card stored at the top of the deck (or at the end of vector)
  */
  CardModel* getTopCard();
  /**
  *\returns the size of the deck
  */
  int getSize();
  /**this function is used to set all the wild cards for the round
  *@param roundNumber the round corresponding to the wild cards
  */
  void setWild(int roundNumber);

 private:
std::vector <CardModel*> deck;///will be used to store all the cards
};
#endif
