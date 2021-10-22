/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File:InterfaceUI.h
* Date Created: 16/10/2021
*/
#ifndef INTERFACEUI_H
#define INTERFACEUI_H

#include<iostream>
#include <string>
#include <FiveCrownsController.h>

class InterfaceUI {
 public:
   /** This function asks for the user name.
   * @ param string is used as an input for the user name.
   */
   std:: string askForUserName();
   /**
   * This function displays a welcoe Message to the user.
   */
   void WelcomeMessage();
   /**
   * This function asks user for their choice when playing the game.
   */
   void askChoice();
   /**
   * This function displays the game menu to the user.
   */
   void displayMenu();
   /**
   * This function displays the state of the game to the user.
   */
   void displayState();
   /**
   * This function displays a goodbye message to the user.
   */
   void byeMessage();
};
#endif
