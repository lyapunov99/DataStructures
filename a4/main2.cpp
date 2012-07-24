#include <iostream>
#include "a4.h"

using namespace std;

#define ROOMS 9
static string dirs[] = {"NORTH", "EAST", "SOUTH", "WEST", "UP", "DOWN"};
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
    cout << "Going in direction " << dirs[dir]<< endl;
    now = now->dirs[dir];
    if (now->gold()) {
      cout << "Got gold!" << endl;
      now->contents &= ~GOLD;
    }
    if (now->exit()) {
      cout << "Got to exit!" << endl;
    }
    return 1;
  }
  else {
    cout << "Can't go in direction " << dir << "(" << dirs[dir] << ")" << endl;
    return 0;
  }
}

// make a really simple maze to test with
//  start
//  0 <--> 1 <--> 2      U    N
//  ^ \__  ^ \__  ^       \__ ^
//  v    \ v    \ v          \|
//  3 <--> 4 <--> 5      W<---*--->E
//  ^ \__  ^ \__  ^           |\__
//  v    \ v    \ v           v   \
//  6 <--> 7 <--> 8           S    D
//(gold)       exit

int main(int argc, char **argv)
{
  for (int i=0; i<ROOMS; i++) dungeon[i].number=i; 
  
  dungeon[0].dirs[EAST ]=&dungeon[1]; // 0 <-> 1 <-> 2
  dungeon[1].dirs[WEST ]=&dungeon[0]; 
  dungeon[1].dirs[EAST ]=&dungeon[2]; 
  dungeon[2].dirs[WEST ]=&dungeon[1]; 
  
  dungeon[3].dirs[EAST ]=&dungeon[4]; // 3 <-> 4 <-> 5
  dungeon[4].dirs[WEST ]=&dungeon[3]; 
  dungeon[4].dirs[EAST ]=&dungeon[5]; 
  dungeon[5].dirs[WEST ]=&dungeon[4]; 
  
  dungeon[6].dirs[EAST ]=&dungeon[7]; // 6 <-> 7 <-> 8
  dungeon[7].dirs[WEST ]=&dungeon[6]; 
  dungeon[7].dirs[EAST ]=&dungeon[8]; 
  dungeon[8].dirs[WEST ]=&dungeon[7]; 
  
  dungeon[0].dirs[SOUTH]=&dungeon[3];	// 0 <-> 3 <-> 6
  dungeon[3].dirs[NORTH]=&dungeon[0];	
  dungeon[3].dirs[SOUTH]=&dungeon[6]; 
  dungeon[6].dirs[NORTH]=&dungeon[3]; 
  
  dungeon[1].dirs[SOUTH]=&dungeon[4];	// 1 <-> 4 <-> 7
  dungeon[4].dirs[NORTH]=&dungeon[1];	
  dungeon[4].dirs[SOUTH]=&dungeon[7]; 
  dungeon[7].dirs[NORTH]=&dungeon[4];	
  
  dungeon[2].dirs[SOUTH]=&dungeon[5];	// 2 <-> 5 <-> 8
  dungeon[5].dirs[NORTH]=&dungeon[2];	
  dungeon[5].dirs[SOUTH]=&dungeon[8]; 
  dungeon[8].dirs[NORTH]=&dungeon[5];	
  
  dungeon[0].dirs[DOWN ]=&dungeon[4]; // 0 <-> 4 <-> 8
  dungeon[4].dirs[UP   ]=&dungeon[0]; 
  dungeon[4].dirs[DOWN ]=&dungeon[8];  
  dungeon[8].dirs[UP   ]=&dungeon[4]; 
  
  dungeon[3].dirs[DOWN ]=&dungeon[7]; // 3 <-> 7 
  dungeon[7].dirs[UP   ]=&dungeon[3]; 
  
  dungeon[1].dirs[DOWN ]=&dungeon[5]; // 1 <-> 5 
  dungeon[5].dirs[UP   ]=&dungeon[1]; 
  
  dungeon[6].contents |= GOLD; 
  dungeon[8].contents |= EXIT; 
  
  now=&dungeon[0]; 
  quest(&dungeon[0],ROOMS);
  if (now==&dungeon[8]) { 
    cout << "you found the exit!\n"; 
  }
  else { 
    cout << "you ended in room "<<now->number<<" and missed the exit!\n"; 
  }
  return 0;
}
