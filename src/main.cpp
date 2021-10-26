#include <DeckModel.h>
#include <CardModel.h>
#include <PlayerModel.h>
#include <UserModel.h>
#include <FiveCrownsController.h>
#include <iostream>

int main(int argc, char **argv) {
  FiveCrownsController *A = new FiveCrownsController();
  A->setUpGame();
  return 0;
}
