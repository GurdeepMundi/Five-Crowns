#include <DeckModel.h>
#include <CardModel.h>
#include <PlayerModel.h>
#include <UserModel.h>
#include <FiveCrownsController.h>
#include <iostream>
#include <InterfaceUI.h>

int main(int argc, char **argv) {
  FiveCrownsController A; //= new FiveCrownsController();
  InterfaceUI* aView = new InterfaceUI();
  A.setUpGame();
  return 0;
}
