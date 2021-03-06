/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh
* File: InterfaceUI.cpp
* Date Created: 16/10/2021
*/
#include <InterfaceUI.h>
#include <iostream>
#include <string>
#include <vector>

std::string InterfaceUI::askForUserName() {
  std::string UserName;
  std::cout << "Please Enter Your Name:" << std::endl;
  std::cin >> UserName;
  return UserName;
}

void InterfaceUI::WelcomeMessage() {
  std::cout << "Welcome to Five Crowns!\n"
  << "It ain't over till the Kings go Wild!" << std::endl;
}

int InterfaceUI::askChoice() {
  int choice;
  std::cout << "What would you like to do?\n" << \
  "1 - Discard\n2 - Make Run\n3 - Make Book\n4 - Help\n5 - exit\n" << std::endl;
  std::cin >> choice;
  return choice;
}

int InterfaceUI::askDiscard() {
  int choice;
  std::cout << "Please enter the position of the card"
  " you would like to discard:" << std::endl;
  std::cin >> choice;
  return choice;
}

std::vector<int> InterfaceUI::askRun() {
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
    for (int i = 0; i < runSize; i++) {
      std::cin >> cardPos;
      run.push_back(cardPos);
    }
    return run;
  }
}

std::vector<int> InterfaceUI::askBook() {
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
    for (int i = 0; i < bookSize; i++) {
      std::cin >> cardPos;
      book.push_back(cardPos);
    }
    return book;
  }
}

bool InterfaceUI::askGoOut() {
  char c;
  do {
    std::cout << "Would you like to go out? (Y/N)" << std::endl;
    std::cin >> c;
    if (c == 'y' || c == 'Y') {
      return true;
    } else if (c == 'n' || c == 'N') {
      return false;
    } else {
      std::cout << "Invalid Input" << std::endl;
    }
  } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
  return false;
}

void InterfaceUI::displayHelp() {
  std::cout << "The objective of Five Crowns"
  << " is to finish with the lowest score at the end of 11 rounds.\n"
  << "Each round, players are dealt the amount of cards\n"
  << "corresponding with the round number,\n"
  << "starting at three and ending at thirteen.\n"
  << "A turn consists of drawing a card,\n"
  << "Going Out by playing Books and Runs,\n"
  << "and discarding a card.\n"
  << "To Go Out, all of your cards must be able to be played\n"
  << "into Books or Runs, with one card left to be discarded.\n"
  << "A Book consists of a three or more cards of the same value.\n"
  << "Eg. Six of Clubs, Six of Hearts, Six of Clubs\n"
  << "A Run consists of three or more consecutive cards of the same suit.\n"
  << "Eg. Four of Spades, Five of Spades, Six of Spades\n"
  << "Wild cards can be to represent any card in a Book or Run.\n"
  << "A card is Wild if its value matches the number of the round,\n"
  << "starting with Threes in the first round\n"
  << "and ending with Kings in the Eleventh.\n"
  << "Jokers are always Wild.\n"
  << "Once a player goes out, the remaining players have one more turn\n"
  << "to play as many Books or Runs as they can and discard a card.\n"
  << "Any remaining cards are counted as points against the player.\n"
  << "Wild cards are worth 20 points, Jokers are worth 50 points,\n"
  << "and every other card is worth its value.\n"
  << "(Jacks = 11, Queens = 12, Kings = 13)\n"
  << "Play continues until all 11 rounds are complete."
  << "The player with the lowest score wins";
}

void InterfaceUI::byeMessage() {
  // if endgame Function is called display this message
  std::cout << "Thank you for Playing! Goodbye!" << std::endl;
}

int InterfaceUI::askDraw() {
  int input;
  do {
    std::cout << "Do you want to draw from the draw pile (1)"
    << " or discard pile (2) ? " << std::endl;
    std::cin >> input;
    if (input != 1 && input != 2) {
      std::cout << "Invalid Input." << std::endl;
    }
  } while (input != 1 && input != 2);
  return input;
}

void InterfaceUI::showHand(DeckModel* h) {
  std::cout << std::endl << "Your hand looks like this: " << std::endl;
  for (int i = 0; i < h->getSize(); i++) {
    std::cout << i << " ";
    switch (h->getCardAt(i)->getRank()) {
      case 11: std::cout << "Jack";
      break;
      case 12: std::cout << "Queen";
      break;
      case 13: std::cout << "King";
      break;
      case 50: std::cout << "Joker";
      break;
      default: std::cout << h->getCardAt(i)->getRank();
    }
    std::cout << " of ";
    switch (h->getCardAt(i)->getSuit()) {
      case 0: std::cout << "Clubs";
      break;
      case 1: std::cout << "Hearts";
      break;
      case 2: std::cout << "Spades";
      break;
      case 3: std::cout << "Diamonds";
      break;
      case 4: std::cout << "Stars";
      break;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void InterfaceUI::displayCard(CardModel* t) {
  switch (t->getRank()) {
    case 11: std::cout << "Jack";
    break;
    case 12: std::cout << "Queen";
    break;
    case 13: std::cout << "King";
    break;
    case 50: std::cout << "Joker";
    break;
    default: std::cout << t->getRank();
  }
  std::cout << " of ";
  switch (t->getSuit()) {
    case 0: std::cout << "Clubs";
    break;
    case 1: std::cout << "Hearts";
    break;
    case 2: std::cout << "Spades";
    break;
    case 3: std::cout << "Diamonds";
    break;
    case 4: std::cout << "Stars";
    break;
  }
  std::cout << " was discarded." << std::endl;
}
