#include <iostream>
#include "a4.h"

using namespace std;

#define ROOMS 16
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

/*
 make it two-dimensional and toroidal (like a doughnut) 
  start
  0 <--> 1 <--> 2 <--> 3  U    N
  ^      ^      ^      ^   \__ ^
  v      v      v      v      \|
  4 <--> 5 <--> 6 <--> 7  W<---*--->E
         sphinx
  ^      ^      ^      ^       |\__
  v      v      v      v       v   \
  8 <--> 9 <-->10 <--> 11      S    D
  ^      ^      ^      ^       
  v      v      v      v    
  sword
  12<-->13 <-->14 <--> 15      
                       exit
*/
int main(int argc, char **argv)
{
  for (int i=0; i<ROOMS; i++) dungeon[i].number=i; 
  
  dungeon[0].dirs[EAST ]=&dungeon[1]; dungeon[1].dirs[WEST ]=&dungeon[0]; 
  dungeon[1].dirs[EAST ]=&dungeon[2]; dungeon[2].dirs[WEST ]=&dungeon[1]; 
  dungeon[2].dirs[EAST ]=&dungeon[3]; dungeon[3].dirs[WEST ]=&dungeon[2]; 
  dungeon[3].dirs[EAST ]=&dungeon[0]; dungeon[0].dirs[WEST ]=&dungeon[3]; 
  
  dungeon[4].dirs[EAST ]=&dungeon[5]; dungeon[5].dirs[WEST ]=&dungeon[4]; 
  dungeon[5].dirs[EAST ]=&dungeon[6]; dungeon[6].dirs[WEST ]=&dungeon[5]; 
  dungeon[6].dirs[EAST ]=&dungeon[7]; dungeon[7].dirs[WEST ]=&dungeon[6]; 
  dungeon[7].dirs[EAST ]=&dungeon[4]; dungeon[4].dirs[WEST ]=&dungeon[7]; 
  
  dungeon[8].dirs[EAST ]=&dungeon[9]; dungeon[9].dirs[WEST ]=&dungeon[8]; 
  dungeon[9].dirs[EAST ]=&dungeon[10]; dungeon[10].dirs[WEST ]=&dungeon[9]; 
  dungeon[10].dirs[EAST ]=&dungeon[11]; dungeon[11].dirs[WEST ]=&dungeon[10]; 
  dungeon[11].dirs[EAST ]=&dungeon[8]; dungeon[8].dirs[WEST ]=&dungeon[11]; 
  
  dungeon[12].dirs[EAST ]=&dungeon[13]; dungeon[13].dirs[WEST ]=&dungeon[12]; 
  dungeon[13].dirs[EAST ]=&dungeon[14]; dungeon[14].dirs[WEST ]=&dungeon[13]; 
  dungeon[14].dirs[EAST ]=&dungeon[15]; dungeon[15].dirs[WEST ]=&dungeon[14]; 
  dungeon[15].dirs[EAST ]=&dungeon[12]; dungeon[12].dirs[WEST ]=&dungeon[15]; 
  
  dungeon[0].dirs[SOUTH]=&dungeon[4];	dungeon[4].dirs[NORTH]=&dungeon[0];	
  dungeon[4].dirs[SOUTH]=&dungeon[8]; dungeon[8].dirs[NORTH]=&dungeon[4];	
  dungeon[8].dirs[SOUTH]=&dungeon[12]; dungeon[12].dirs[NORTH]=&dungeon[8];	
  dungeon[12].dirs[SOUTH]=&dungeon[0]; dungeon[0].dirs[NORTH]=&dungeon[12];	
  
  dungeon[1].dirs[SOUTH]=&dungeon[5];	dungeon[5].dirs[NORTH]=&dungeon[1];	
  dungeon[5].dirs[SOUTH]=&dungeon[9]; dungeon[9].dirs[NORTH]=&dungeon[5];	
  dungeon[9].dirs[SOUTH]=&dungeon[13]; dungeon[13].dirs[NORTH]=&dungeon[9];	
  dungeon[13].dirs[SOUTH]=&dungeon[1]; dungeon[1].dirs[NORTH]=&dungeon[13];	
  
  dungeon[2].dirs[SOUTH]=&dungeon[6];	dungeon[6].dirs[NORTH]=&dungeon[2];	
  dungeon[6].dirs[SOUTH]=&dungeon[10]; dungeon[10].dirs[NORTH]=&dungeon[6];	
  dungeon[10].dirs[SOUTH]=&dungeon[14]; dungeon[14].dirs[NORTH]=&dungeon[10];	
  dungeon[14].dirs[SOUTH]=&dungeon[2]; dungeon[2].dirs[NORTH]=&dungeon[14];	
  
  dungeon[3].dirs[SOUTH]=&dungeon[7];	dungeon[7].dirs[NORTH]=&dungeon[3];	
  dungeon[7].dirs[SOUTH]=&dungeon[11]; dungeon[11].dirs[NORTH]=&dungeon[7];	
  dungeon[11].dirs[SOUTH]=&dungeon[15]; dungeon[15].dirs[NORTH]=&dungeon[11];	
  dungeon[15].dirs[SOUTH]=&dungeon[3]; dungeon[3].dirs[NORTH]=&dungeon[15];	
  
  dungeon[1].contents |= GOLD; 
  dungeon[3].contents |= GOLD; 
  dungeon[5].contents |= GOLD; 
  dungeon[6].contents |= GOLD; 
  dungeon[9].contents |= GOLD; 
  dungeon[10].contents |= GOLD; 
  dungeon[11].contents |= GOLD; 
  dungeon[12].contents |= GOLD; 
  dungeon[15].contents |= EXIT;
  dungeon[8].contents |= SWORD;
  dungeon[5].contents |= SPHINX;
  now = &dungeon[0];
  quest(&dungeon[0],ROOMS);
  if (now == &dungeon[15]) {
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
