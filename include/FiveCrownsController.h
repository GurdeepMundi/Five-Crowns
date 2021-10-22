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

class FiveCrownsController {
 public:
  void endGame();
  void setUpGame();
  void dealCards();
  void callHelp();
  PlayRound(int roundNumber);
  void calcScore(int roundNumber);

};
#endif
  
