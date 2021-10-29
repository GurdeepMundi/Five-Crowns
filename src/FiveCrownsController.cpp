/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: FiveCrownsController.cpp
* Date Created: 16/10/2021
*/
#include <FiveCrownsController.h>
#include <CardModel.h>
#include <DeckModel.h>
#include <vector>
#include <UserModel.h>
#include <AIModel.h>
#include <iostream>

void FiveCrownsController::endGame() {
  currentView->byeMessage();
  exit(0);
}

void FiveCrownsController::makeDeck() {
  CardModel* tempCard;
  for (int i = 3; i < 14; i++) {
    for (int j = 1; j < 6; j++) {
      tempCard = new CardModel();
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
      tempCard->setWildStatus(false);
      deck->addCard(tempCard);
    }
  }
  for (int k = 1; k < 4; k++) {
    tempCard = new CardModel();
    tempCard->setRank(50);
    tempCard->setSuit(CLUBS);
    tempCard->setScoreValue(50);
    tempCard->setWildStatus(true);
    deck->addCard(tempCard);
  }
  delete tempCard;
}

void FiveCrownsController::setUpGame() {
  currentView->WelcomeMessage();
  //Adding new Players in the Controller because only two players are allowed
  Players.push_back(new UserModel());
  Players.push_back(new AIModel());
  Players.at(0)->setName("Gurdeep"/*currentView->askForUserName()*/);
  Players.at(1)->setName("DumbAI");
}

void FiveCrownsController::dealCards(int roundNumber) {
  for (int i = 0; i < roundNumber + 2; i++) {
    Players.at(0)->draw(deck->getTopCard());
    deck->removeCard(deck->getSize());
    Players.at(1)->draw(deck->getTopCard());
    deck->removeCard(deck->getSize());
  }
}

void FiveCrownsController::callHelp() {
  currentView->displayHelp();
}

void FiveCrownsController::playRound(int roundNumber) {
  int drawChoice;// discard pile or draw pile
  int choice;//will be used to store if user wants to 1. discard,
  //2. make run, 3. make book, 4. seek help
  int discardChoice;
  makeDeck();
  makeDeck();
  deck->setWild(roundNumber);
  deck->shuffle();
  dealCards(roundNumber);
  discardPile->addCard(deck->getTopCard());
  currentView->displayCard(discardPile->getTopCard());
  deck->removeCard(deck->getSize()-1);
  // turn loop
  while (Players.at(0)->getHand()->getSize() >= 1 && \
  Players.at(1)->getHand()->getSize() >= 1) {
    drawChoice = currentView->askDraw();
    if (drawChoice == 1) {
      Players.at(0)->draw(deck->getTopCard());//draw from Draw pile (deck)
      deck->removeCard(deck->getSize()-1);
    } else if (drawChoice == 2) {
        Players.at(0)->draw(discardPile->getTopCard());
      }
      // turn only ends when card is discarded
      do {
        currentView->showHand(Players.at(0)->getHand());
        choice = currentView->askChoice();
        switch (choice) {
        case 1:
        //discard
        discardChoice = currentView->askDiscard();
        discardPile->addCard(Players.at(0)->getHand()->getCardAt\
        (discardChoice));
        currentView->displayCard(Players.at(0)->getHand()->getCardAt\
        (discardChoice));
        Players.at(0)->discard(discardChoice);
        break;
        case 2:
        // make run
        Players.at(0)->makeRun(currentView->askRun());
        break;
        case 3:
        // make Book
        Players.at(0)->makeBook(currentView->askBook());
        break;
        case 4:
        // help
        callHelp();
        break;
        case 5:
        // exit
        endGame();
        break;
      }
    } while (choice != 1);
    choice = 0;
    // AI turn
    //draw from drawpile
    Players.at(1)->draw(deck->getTopCard());
    deck->removeCard(deck->getSize());
    //try making Book
    if (Players.at(1)->getHand()->getSize() > 2) {
      Players.at(1)->makeBook(tempVector);
    }
    //Discarding a card from AIPlayer
    discardPile->addCard(Players.at(1)->getHand()->getCardAt(0));
    std::cout << "AI player: " << std::endl;
    currentView->displayCard(discardPile->getTopCard());
    Players.at(1)->discard(0);
  }
  //calcScore();
  deck->emptyDeck();
  discardPile->emptyDeck();
  Players.at(0)->getHand()->emptyDeck();
  Players.at(1)->getHand()->emptyDeck();
}

void FiveCrownsController::calcScore() {
  int pScore = 0;
  int cScore = 0;
  for (int i = 0; i < (Players.at(0)->getHand()->getSize()-1); i++) {
    pScore = pScore + (Players.at(0)->getHand()->getCardAt(i)->getScoreValue());
  }
  Players.at(0)->addScore(pScore);
  for (int j = 0; j <= (Players.at(1)->getHand()->getSize()-1); j++) {
    cScore = cScore + (Players.at(1)->getHand()->getCardAt(j)->getScoreValue());
  }
  Players.at(1)->addScore(cScore);
}

void FiveCrownsController::playGame() {
  setUpGame();
  for (int i = 1; i < 12; i++) {
    playRound(i);
  }
  endGame();
}

void FiveCrownsController::setUI(InterfaceUI* ui) {
  currentView = ui;
}
