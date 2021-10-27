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
  /** This function is used to discard.
  *@param d
  */
  void discard(int d);
};
#endif
