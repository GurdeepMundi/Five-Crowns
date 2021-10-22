/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: InterfaceUI.cpp
* Date Created: 16/10/2021
*/
#include <InterfaceUI.h>

std::string InterfaceUI::askForUserName() {
  std::string UserName;

  std::cout << "Please Enter Your Name" << std::endl;
  std::cin >> UserName;
  //setName(UserName);
}

void InterfaceUI::WelcomeMessage() {
  std::cout << "Welcome to Five Crowns" << std::endl;
}

void InterfaceUI::askChoice() {}

void InterfaceUI::displayMenu() {}

void InterfaceUI::displayState() {}

void InterfaceUI::byeMessage() {
  // if endgame Function is called display this message
  std::cout << "Thank you for Playing  Goodbye" << std::endl;
}
