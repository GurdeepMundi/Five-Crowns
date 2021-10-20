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

class PlayerModel {
 public:
  void setName(std::string n);
  std::string getname();
  virtual void discard(int d) = 0;
  void draw();
  // void PlayerModel::sort();
  std::vector<CardModel*> makeRun();
  std::vector<CardModel*> makeBook();

 private:
  std::vector<CardModel*> hand;
  int score;
  std::string name;
};

#endif
