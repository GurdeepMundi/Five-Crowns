/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: FaceUI.cpp
* Date Created: 16/10/2021
*/
#include <InterfaceUI.h>
#include <iostream>
#include <string>
#include <vector>

std::string FaceUI::askForUserName() {
  std::string UserName;
  std::cout << "Please Enter Your Name:" << std::endl;
  std::cin >> UserName;
  return UserName;
}

void FaceUI::WelcomeMessage() {
  std::cout << "Welcome to Five Crowns!" << std::endl;
}

int FaceUI::askChoice() {
  int choice;
  std::cout << "What would you like to do?\n" << \
  "1 - Discard\n2 - Make Run\n3 - Make Book\n4 - Help" << std::endl;
  std::cin >> choice;
  return choice;
}

int FaceUI::askDiscard() {
  int choice;
  std::cout << "Please enter the position of the card"
  " you would like to discard:" << std::endl;
  std::cin >> choice;
  return choice;
}

std::vector<int> FaceUI::askRun() {
  std::vector<int> run;
  int cardPos, runSize;
  std::cout << "Please input the amount of cards in your Run:" << std::endl;
  std::cin >> runSize;
  if (runSize <= 2) {
    std::cout << "Run must be at least 3 cards." << std::endl;
    return run;
  } else {
    std::cout << "Please enter the position of the cards"
    " in your Run one by one:" << std::endl;
    for (int i = 0; i <= runSize; i++) {
      std::cin >> cardPos;
      run.push_back(cardPos);
    }
    return run;
  }
}

std::vector<int> FaceUI::askBook() {
  std::vector<int> book;
  int cardPos, bookSize;
  std::cout << "Please input the amount of cards in your Book:" << std::endl;
  std::cin >> bookSize;
  if (bookSize <= 2) {
    std::cout << "Book must be at least 3 cards." << std::endl;
    return book;
  } else {
    std::cout << "Please enter the position of the cards"
    " in your Book one by one:" << std::endl;
    for (int i = 0; i <= bookSize; i++) {
      std::cin >> cardPos;
      book.push_back(cardPos);
    }
    return book;
  }
}

bool FaceUI::askGoOut() {
  char c;
  do {
    std::cout << "Would you like to go out? (Y/N)" << std::endl;
    std::cin >> c;
    if (c == 'y' || c == 'Y') {
      return true;
    } else if (c == 'n' || c == 'N') {
      return false;
    } else {
      std::cout << "Invalid input" << std::endl;
    }
  } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
}

void FaceUI::displayMenu() {}

void FaceUI::displayState() {}

void FaceUI::displayHelp() {}

void FaceUI::byeMessage() {
  // if endgame Function is called display this message
  std::cout << "Thank you for Playing  Goodbye" << std::endl;
}
