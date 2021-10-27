/*
* CPSC 3720 Fall 2021
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File:UserModel.h
* Date Created: 16/10/2021
*/
#ifndef USERMODEL_H
#define USERMODEL_H
#include <PlayerModel.h>
class UserModel: public PlayerModel {
 public:
  /** This function is used to discard a card from user's hand
  *@param d address of the card in hand
  */
  void discard(int d);
};
#endif
