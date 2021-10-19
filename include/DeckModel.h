/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: DeckModel.h
* Date Created: 16/10/2021
*/
#ifndef DECKMODEL_H
#define DECKMODEL_H
#include <CardModel.h>
#include <vector.h>
#include <cstdlib>
Class DeckModel {
public:
  DeckModel();
  void shuffle();
  void addCard(CardModel* c);
private:
  vector <CardModel*> deck;
};
