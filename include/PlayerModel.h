/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File:PlayerModel.h
* Date Created: 16/10/2021
*/
#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include "CardModel"
#include <string>
#include <vector>

Class PlayerModel {
public:
  void PlayerModel::setName(std::string n);
  std::string PlayerModel::getname();
  virtual void PlayerModel::discard(int d);
  void PlayerModel::draw();
  // void PlayerModel::sort();
  std::vector<CardModel*> PlayerModel::makeRun();
  std::vector<CardModel*> PlayerModel::makeBook();

private:
  std::vector<CardModel*> hand;
  int score;
  std::string name;
}
