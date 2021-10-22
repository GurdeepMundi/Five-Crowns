/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File:FiveCrownsController.h
* Date Created: 16/10/2021
*/
#ifndef FIVECROWNSCONTROLLER_H
#define FIVECROWNSCONTROLLER_H

#include <iostream>
#include <vector>
#include <PlayerModel.h>

class FiveCrownsController {
 public:
  void endGame();
  void setUpGame();
  void dealCards();
  void callHelp();
  PlayRound(int roundNumber);
  void calcScore(int roundNumber);
private:
  int roundNumber;
  std::vector<PlayerModel*>Players;
  currentView: interface_UI*;

};
#endif
