/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh 
* File: UserModel.cpp
* Date Created: 16/10/2021
*/

#include <UserModel.h>

void UserModel::discard(int d) {
    hand->removeCard(d);
}
