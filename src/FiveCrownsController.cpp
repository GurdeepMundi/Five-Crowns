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

void FiveCrownsController::endGame() {
  currentView->byeMessage();
  exit(0);
}

void FiveCrownsController::makeDeck() {
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
      tempCard->setWildStatus(false);
      deck->addCard(tempCard);
    }
  }
  for (int k = 1; k < 4; k++) {
    //Object = CLUBS;
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
  Players.at(0)->setName(currentView->askForUserName());
}

void FiveCrownsController::dealCards(int roundNumber) {
  for (int i = 0; i < roundNumber + 2; i++) {
    Players.at(0)->draw(deck->getCardAt(0));
    Players.at(1)->draw(deck->getCardAt(1));
    deck->removeCard(0);
    deck->removeCard(1);
  }
}

void FiveCrownsController::callHelp() {
  currentView->help();
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
  deck->removeCard(deck->getSize()-1);
  // turn loop
  while (Players.at(0)->getHand()->getSize() >= 1 && \
  Players.at(1)->getHand()->getSize() >= 1) {
    drawChoice = currentView->askDraw();
    if (drawChoice == 1) {
      Players.at(0)->draw(deck->getTopCard());
      deck->removeCard(deck->getSize()-1);
    } else if (drawChoice == 2) {
        Players.at(0)->draw(discardPile->getTopCard());
      }
      // turn only ends when card is discarded
      do {
        choice = currentView->askChoice();
        switch (choice) {
        case 1:
        //discard
        discardChoice = currentView->askDiscard();
        discardPile->addCard(Players.at(0)->getHand() \
        ->getCardAt(discardChoice-1));
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
      }
    } while (choice != 1);
    // AI turn
    //draw from drawpile
    Players.at(1)->draw(deck->getTopCard());
    //try making run
    std::vector <int> tempVector = {1, 2, 3};
    if (Players.at(1)->getHand()->getSize() > 2)
    Players.at(1)->makeRun(tempVector);
    //try making Book
    if (Players.at(1)->getHand()->getSize() > 2) {
      Players.at(1)->makeBook(tempVector);
    }
    //Discarding a card from AIPlayer
    discardPile->addCard(Players.at(1)->getHand()->getCardAt(1));
    Players.at(1)->getHand()->removeCard(1);  
  }
  calcScore();
  deck->emptyDeck();
  discardPile->emptyDeck();
  Players.at(0)->getHand()->emptyDeck();
  Players.at(1)->getHand()->emptyDeck();
}

void FiveCrownsController::calcScore() {
  int pScore = 0;
  int cScore = 0;
  for (int i = 0; i < (Players.at(0)->getHand()->getSize()); i++) {
    pScore = pScore + (Players.at(0)->getHand()->getCardAt(i)->getScoreValue());
  }
  Players.at(0)->addScore(pScore);
  for (int j = 0; j < (Players.at(1)->getHand()->getSize()); j++) {
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
