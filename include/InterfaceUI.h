/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File:InterfaceUI.h
* Date Created: 16/10/2021
*/
#ifndef INTERFACEUI_H
#define INTERFACEUI_H

#include <iostream>
#include <string>
#include <vector>
#include <PlayerModel.h>

class InterfaceUI {
 public:
  InterfaceUI() {}
  /** This function asks for the user name.
  * @ param string is used as an input for the user name.
  */
  std::string askForUserName();
  /**
  * This function displays a welcome message to the user.
  */
  void WelcomeMessage();
  /**
  * This function asks user for their choice when playing the game.
  */
  int askChoice();
  /**
  * This function asks user which card to discard.
  */
  int askDiscard();
  /**
  * This function asks user to pick the cards in a run.
  */
  std::vector<int> askRun();
  /**
  * This function asks user to pick the cards in a book.
  */
  std::vector<int> askBook();
  /**
  * This function asks user if they would like to go out.
  */
  bool askGoOut();
  /**
  * This function displays the game menu to the user.
  */
  void displayMenu();
  /**
  * This function displays the state of the game to the user.
  */
  void displayState();
  /**
  * This function displays how to play the game to the user.
  */
  void displayHelp();
  /**
  * This function displays a goodbye message to the user.
  */
  void byeMessage();
  /**
  * This function is used by the user when they require help
  */
  void help();
  /**
  * This function is used to ask the user to
  * draw from discard pile or draw pile.
  */
  int askDraw();
  /**
  * This function is used to display hand of the user
  */
  void showHand(DeckModel* h);
};
#endif
