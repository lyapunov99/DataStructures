#include <iostream>
#include "a4.h"

using namespace std;

#define ROOMS 9
static string dirs[] = {"NORTH", "EAST", "SOUTH", "WEST", "UP", "DOWN"};
static int sword;
static Room dungeon[ROOMS]; // whole dungeon
static Room *now; // where I am now. 

void quest(Room *start, int rooms); // your routine

int go (int dir)
{
  if (dir < 0 || dir >= 6) {
    cout << "Can't go in that direction direction " << dir << endl; 
    return 0;
  }
  else if (now->dirs[dir]) {
    cout << "Going in direction " << dirs[dir] << " to room #" << now->dirs[dir]->number << endl;
    now = now->dirs[dir];
    if (now->gold()) {
      cout << "You picked up a piece of gold!" << endl;
      now->contents &= ~GOLD;
    }
    if (now->sword()) {
      cout << "You picked up the sword!" << endl;
      now->contents &= ~SWORD;
      sword = 1;
    }
    if (now->sphinx()) {
      if (sword) {
	cout << "You found the sphinx and killed with your sword!" << endl;
	now->contents &= ~SPHINX;
      }
      else {
	cout << "You found the sphinx but cannot kill it without sword" << endl;
      }
    }
    if (now->exit()) {
      cout << "You found the exit!" << endl;
      now->contents &= ~EXIT;
    }
    return 1;
  }
  else {
    cout << "You cannot go in direction " << dir << "(" << dirs[dir] << ")" << endl;
    return 0;
  }
}

//  start
//  0 <--> 1 <--> 2 (gold)    N
//  ^      ^      ^           ^
//  v      v      v           |
//  3 <--> 4 <--> 5      W<---*--->E
//         (sphinx, gold)
//  ^      ^      ^           |
//  v      v      v           v
//  6 <--> 7 <--> 8           S
//  (sword)         (exit)

int main (int argc, char **argv)
{
  sword = 0;
  for (int i = 0; i < ROOMS; i++) {
    dungeon[i].number = i;
  }
  dungeon[0].dirs[EAST] = &dungeon[1]; // 0 <-> 1 <-> 2
  dungeon[1].dirs[WEST] = &dungeon[0];
  dungeon[1].dirs[EAST] = &dungeon[2];
  dungeon[2].dirs[WEST] = &dungeon[1];
  dungeon[3].dirs[EAST] = &dungeon[4]; // 3 <-> 4 <-> 5
  dungeon[4].dirs[WEST] = &dungeon[3];
  dungeon[4].dirs[EAST] = &dungeon[5];
  dungeon[5].dirs[WEST] = &dungeon[4];
  dungeon[6].dirs[EAST] = &dungeon[7];  // 6 <-> 7 <-> 8
  dungeon[7].dirs[WEST] = &dungeon[6];
  dungeon[7].dirs[EAST] = &dungeon[8];
  dungeon[8].dirs[WEST] = &dungeon[7];
  dungeon[0].dirs[SOUTH] = &dungeon[3]; // 0 <-> 3 <-> 6
  dungeon[3].dirs[NORTH] = &dungeon[0];
  dungeon[3].dirs[SOUTH] = &dungeon[6];
  dungeon[6].dirs[NORTH] = &dungeon[3];
  dungeon[1].dirs[SOUTH] = &dungeon[4]; // 1 <-> 4 <-> 7
  dungeon[4].dirs[NORTH] = &dungeon[1];
  dungeon[4].dirs[SOUTH] = &dungeon[7];
  dungeon[7].dirs[NORTH] = &dungeon[4];
  dungeon[2].dirs[SOUTH] = &dungeon[5]; // 2 <-> 5 <-> 8
  dungeon[5].dirs[NORTH] = &dungeon[2];
  dungeon[5].dirs[SOUTH] = &dungeon[8];
  dungeon[8].dirs[NORTH] = &dungeon[5];
  dungeon[2].contents |= GOLD;
  dungeon[8].contents |= EXIT;
  dungeon[4].contents |= SPHINX;
  dungeon[4].contents |= GOLD;
  dungeon[6].contents |= SWORD;
  now = &dungeon[0];
  quest(&dungeon[0],ROOMS);
  if (now == &dungeon[8]) {
    int done = true;
    int room = 0;
    while (done && room < ROOMS) {
      if (dungeon[room].contents != 0) {
	done = false;
      }
      else {
	room++;
      }
    }
    if (done) {
      cout << "Congratulations! You reached the exit and cleared the maze!" << endl;
    }
    else {
      cout << "You lose! You reached the exit but did not clear the maze." << endl;
    }
  }
  else {
    cout << "You ended in room " << now->number << " and missed the exit!" << endl;
  }
  return 0;
}
