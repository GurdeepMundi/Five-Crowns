/*
* CPSC 3720 Fall 2021 - Group K - Five Crowns
* Sahil Devnani, Gurdeep Singh, Muhammad Saleh <sahil.devnani@Uleth.ca>
* File: DeckModel.cpp
* Date Created: 16/10/2021
*/
#include <DeckModel.h>
#include <vector>
#include <random>
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
/*
    //seed witha real random value, if available
    std::random_device r;
    //e1 is our random engine
    std::default_random_engine e1(r());

    int rnumber;
    for (int i = 0; i< 10 ; i++) {
        //giving the range of numbers
        std::uniform_int_distribution<int> uniform_dist(0, i);
        rnumber = uniform_dist(e1);
        std::cout << e1;
    }*/

void DeckModel::shuffle() {
  std::vector <CardModel*> buffer;
  int insertPosition;
  //seed witha real random value
  std::random_device r;
  std::default_random_engine e1(r());
  for (int i = 0; i < deck.size(); i++) {
    std::uniform_int_distribution<int> uniform_dist(0, buffer.size());
    insertPosition = uniform_dist(e1);
    //insert this element at a random location in buffer
    buffer.insert(buffer.begin() + insertPosition, deck.at(i));
  }
  deck = buffer;
}

void DeckModel::addCard(CardModel* c) {
  deck.push_back(c);
}

void DeckModel::removeCard(int p) {
  for (int i = p-1; i < (deck.size()); i++) {
    deck[i] = deck[i+1];
  }
  deck.pop_back();
}
