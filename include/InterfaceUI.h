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
   std:: string askForUserName();
   void WelcomeMessage();
   void askChoice();
   void displayMenu();
   void displayState();
   void byeMessage();
};
#endif
