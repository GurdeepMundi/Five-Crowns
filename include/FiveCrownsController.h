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
#include <cstdlib>
#include <PlayerModel.h>
#include <UserModel.h>
#include <InterfaceUI.h>

class FiveCrownsController {
 public:
  /**
  * This function would be called if the user wants to end the game.
  */
  void endGame();
  /**
  * This function is used to setUp/Start the game.
  */
  void setUpGame();
  /**
  * This function is used to dealCards in the game.
  */
  void dealCards();
  /**
  * This function is called when the user requires assitance with the game.
  */
  void callHelp();
  /** This function is used to play a round in the game.
  * @ param roundNumber is used to keep track of the rounds.
  */
  void PlayRound(int roundNumber);
  /** This function is used to calculate score.
  * @ param roundNumber is used and will be taken into consideration
  * when determining the players score.
  */
  void calcScore(int roundNumber);
  /**
  * This function loops through the game 11 times.
  */
  void playGame();
  /**
  * This function implements the deck
  */
  void MakeDeck();

 private:
  /**
  * @ param roundNumber is used to keep track of the rounds.
  */
  int roundNumber;
  /**
  * This is a vector of the Playermodel named Players.
  */
  std::vector<PlayerModel*>Players;
  /**
  * This is used for the currentView.
  */
  FaceUI* currentView;

  DeckModel* deck;
};
#endif
