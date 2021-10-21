/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: DeckModel.h
* Date Created: 16/10/2021
*/
#ifndef DECKMODEL_H
#define DECKMODEL_H
#include <CardModel.h>
#include <vector>
#include <cstdlib>
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
  *@param c the card to be removed
  */
  void removeCard(CardModel* c);
 private:
std::vector <CardModel*> deck;///will be used to store all the cards
};
#endif
