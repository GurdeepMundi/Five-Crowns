/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: DeckModel.cpp
* Date Created: 16/10/2021
*/
#include <DeckModel.h>
DeckModel::DeckModel() {
  //constructor
}
/* need some more work here
vector<int> numbers;
    srand(time(0));
    //numbers.insert(numbers.begin() + 0, 2);
    //cout << numbers.at(0);
    int rnd;
    for (int i = 0; i < 10; i++) {
        rnd = rand()%((numbers.size() == 0)? 1:numbers.size());
        cout << rnd;
        numbers.insert(numbers.begin() + rnd, i);
    }
    cout<< numbers.at(0);
    /*
    for (int i; i < numbers.size(); i++) {
        cout << numbers.at(i) << endl;
    }*/

void DeckModel::shuffle() {
  /*vector <CardModel*> buffer;
  srand(deck.at(1));
  for(int i = 0; i < deck.size(); i++) {
    //insert this element at a random location in buffer
    buffer.insert(buffer.begin() + (rand()%buffer.size()), deck.at(i));
  }
}*/

void DeckModel::addcard(CardModel* c) {
  deck.push_back(c);
}
