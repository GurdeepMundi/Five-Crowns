/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh
* File:AIModel.h
* Date Created: 16/10/2021
*/
#ifndef AIMODEL_H
#define AIMODEL_H
#include<PlayerModel.h>
class AIModel: public PlayerModel {
  /** This function is used to discard a card from user's hand
  *@param d address of the card in hand
  */
  void discard(int d);
};
#endif
