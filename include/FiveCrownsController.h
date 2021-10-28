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
#include <DeckModel.h>

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
  void dealCards(int roundNumber);
  /**
  * This function is called when the user requires assitance with the game.
  */
  void callHelp();
  /** This function is used to play a round in the game.
  * @ param roundNumber is used to keep track of the rounds.
  */
  void playRound(int roundNumber);
  /** This function is used to calculate score.
  * @ param roundNumber is used and will be taken into consideration
  * when determining the players score.
  */
  void calcScore();
  /**
  * This function loops through the game 11 times.
  */
  void playGame();
  /**
  * This function implements the deck
  */
  void makeDeck();
  /** this function can be used to set the current view
  * @ param ui pointer to an InterfaceUI type object
  */
  void setUI(InterfaceUI* ui);

 private:
  InterfaceUI * currentView;
  /**
  * roundNumber is used to keep track of the rounds.
  */
  int roundNumber;
  /**
  * This is a vector of the Playermodel named Players.
  */
  std::vector<PlayerModel*>Players;
  /**
  * This is used for the currentView.
  */
  DeckModel* deck = new DeckModel();
  /**
  * This is used for the discard pile
  */
  DeckModel* discardPile = new DeckModel();
};
#endif
