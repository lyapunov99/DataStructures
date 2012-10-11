#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Card {
  int value;
  int suite;
};

void printCard (Card c);

void printCard (Card c)
{
  switch (c.value) {
  case 11:
    cout << "J";
    break;
  case 12:
    cout << "Q";
    break;
  case 13:
    cout << "K";
    break;
  case 14:
    cout << "A";
    break;
  default:
    cout << c.value;
    break;
  }
  switch (c.suite) {
  case 1:
    cout << " Spade" << endl;
    break;
  case 2:
    cout << " Heart" << endl;
    break;
  case 3:
    cout << " Club" << endl;
    break;
  case 4:
    cout << " Diamond" << endl;
    break;
  }
}

int main()
{
  vector <Card> deck;
  for (int suite = 1; suite <= 4; suite++) {
    for (int val = 2; val <= 14; val++) {
      Card c;
      c.value = val;
      c.suite = suite;
      deck.push_back(c);
    }
  }
  srand(time(NULL));
  random_shuffle(deck.begin(), deck.end());
  for (int count = 0; count < 5; count++) {
    printCard(deck[count]);
  }
  return 0;
}
