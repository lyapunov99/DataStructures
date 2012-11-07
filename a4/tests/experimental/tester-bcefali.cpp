#include <iostream>
#include "a4.h"
#include <time.h>
#include <list>
#include <cstdlib>

using namespace std;

#define ROOMS 100
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
//         sphinx
//  ^      ^      ^           |
//  v      v      v           v
//  6 <--> 7 <--> 8           S
//  sword         exit

int pickRanDir(Room&);
int pickRanDir(Room& room) {
	list<int> L;
	for (int i=0; i<DIRS; i++) {
		if (room.dirs[i] == NULL)
			L.push_front(i);
	}
	if (L.size() == 0)
		return -1;
	int ran = rand()%L.size();
	for (int i=0; i<ran; i++)
		L.pop_front();
	return L.front();
}

int placeContents(int);
int placeContents(int v) {
	int i;
	bool full = true;
	while (full) {
		i = rand()%(ROOMS-1)+1;
		full = dungeon[i].contents != 0;
	}
	dungeon[i].contents |= v;
	//cout << "Placed " << v << " at " << i << endl;
	return i;
}

int main (/*int argc, char **argv*/)
{
  sword = 0;
	srand(time(NULL));
	for (int i=0; i<ROOMS; i++) {
		dungeon[i].number = i;
		dungeon[i].contents = 0;
		for (int j=0; j<DIRS; j++) {
			dungeon[i].dirs[j] = NULL;
		}
		
		if (i>0) {
			int con;
			int dir = -1;
			while (dir == -1) {
				con = rand()%i;
				dir = pickRanDir(dungeon[con]);
			}
			dungeon[con].dirs[dir] = &dungeon[i];
			dungeon[i].dirs[rand()%DIRS] = &dungeon[rand()%i];
		}
	}
	int goldcount = rand()%(ROOMS/2);
	int exit = placeContents(EXIT);
	placeContents(SPHINX);
	placeContents(SWORD);
	for (int i=0; i<goldcount; i++)
		placeContents(GOLD);
	
	//cout << "Exit is in " << exit << endl;
	now = &dungeon[exit]; // Set the starting room
  quest(&dungeon[exit],ROOMS); // Calls YOUR quest function
  if (now == &dungeon[exit]) { // Check if the final move is the exit
    int done = true;
    int room = 0;
    while (done && room < ROOMS) {
      if (dungeon[room].contents != 0) {
				//cout << "Room " << room << " had " << dungeon[room].contents << endl;
  			//	for (int i=0; i<DIRS; i++)
				//		cout << "Is neighbor " << i << " null? " << (dungeon[exit].dirs[i] == NULL) << endl;
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
  	//for (int i=0; i<DIRS; i++)
		//	cout << "Is neighbor " << i << " null? " << (dungeon[exit].dirs[i] == NULL) << endl;
	}
  return 0;
}
