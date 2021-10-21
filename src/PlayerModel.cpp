/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: PlayerModel.cpp
* Date Created: 16/10/2021
*/
#include <PlayerModel.h>
#include <CardModel.h>
#include <string>
#include <vector>
#include "DeckModel.h"

void PlayerModel::setName(std::string n) {
  this->name = n;
}

std::string PlayerModel::getname() {
  return this->name;
}

void PlayerModel::discard(int d) {
  // code here
}

// void PlayerModel::sort() {
//  // code here
// }

void PlayerModel::draw() {
//  hand.push_back(this deck->deck.back());
  //this deck->deck.pop_back();
}

std::vector<CardModel*> PlayerModel::makeRun() {
  // code here
}

std::vector<CardModel*> PlayerModel::makeBook() {
  // code here
}
