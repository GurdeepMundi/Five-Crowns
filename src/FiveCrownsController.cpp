/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: FiveCrownsController.cpp
* Date Created: 16/10/2021
*/
#include <FiveCrownsController.h>
#include <CardModel.h>
#include <DeckModel.h>

void FiveCrownsController::endGame() {
  exit(0);
}

void FiveCrownsController::MakeDeck() {
  CardModel* tempCard = new CardModel();
  //enum Suits {CLUBS, HEARTS, SPADES, DIAMONDS, STARS};
  //Suits Object;

  for (int i = 3; i < 14; i++) {
    for (int j = 1; j < 6; j++) {
      switch (j) {
        case 1:
        tempCard->setSuit(CLUBS);
        break;

        case 2:
        tempCard->setSuit(HEARTS);
        break;

        case 3:
        tempCard->setSuit(SPADES);
        break;

        case 4:
        tempCard->setSuit(DIAMONDS);
        break;

        case 5:
        tempCard->setSuit(STARS);
        break;
      }
      tempCard->setRank(i);
      tempCard->setScoreValue(i);
      deck->addCard(tempCard);
    }
  }
  for (int k = 1; k < 4; k++) {
    //Object = CLUBS;
    tempCard->setRank(50);
    tempCard->setSuit(CLUBS);
    tempCard->setScoreValue(50);
  }
  delete tempCard;
}

void FiveCrownsController::printDeck() {
  for(int i = 0; i < 58; i++) {
    std::cout << deck->getCardAt(i)->getRank() << std::endl;
  }
}

void FiveCrownsController::setUpGame() {
//  currentView->WelcomeMessage();
  //Players.at(0)->setName(currentView->askForUserName());
  MakeDeck();
  MakeDeck();
  printDeck();
}

void dealCards() {}

void callHelp() {
  UserModel* temp = new UserModel();
  temp->help();
  delete temp;
}

void FiveCrownsController::PlayRound(int roundNumber) {}

void FiveCrownsController::calcScore(int roundNumber) {}

void FiveCrownsController::playGame() {}
