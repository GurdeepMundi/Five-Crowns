#include <DeckModel.h>
#include <CardModel.h>
#include <PlayerModel.h>
#include <UserModel.h>
#include <FiveCrownsController.h>
#include <iostream>
#include <InterfaceUI.h>

int main(int argc, char **argv) {
  FiveCrownsController* aGame = new FiveCrownsController();
  InterfaceUI* aView = new InterfaceUI();
  aGame->setUI(aView);
  aGame->playGame();
  delete aView;
  delete aGame;
  return 0;
}
