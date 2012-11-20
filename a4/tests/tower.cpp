#include <iostream>
#include "a4.h"

using namespace std;

#define ROOMS 45
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
[0,1,2,
3,4,5,
6,7,8]

[9,10,11,
12,13,14,
15,16,17]

[18,19,20,
21,22,23,
24,25,26]

[27,28,29,
30,31,32,
33,34,35]

[36,37,38,
39,40,41,
42,43,44 (Exit)]
Bidirectional on floor; up direction in left corner; down in middle of room
*/
int main(int argc, char **argv)
{
  for (int i=0; i<ROOMS; i++) {
  	dungeon[i].number=i; 
  }

  // Floor 1
  dungeon[0].dirs[EAST]=&dungeon[1] ; dungeon[1].dirs[EAST]=&dungeon[2] ;
  dungeon[3].dirs[EAST]=&dungeon[4] ; dungeon[4].dirs[EAST]=&dungeon[5] ;
  dungeon[6].dirs[EAST]=&dungeon[7] ; dungeon[7].dirs[EAST]=&dungeon[8] ;
  
  dungeon[1].dirs[WEST]=&dungeon[0] ; dungeon[2].dirs[WEST]=&dungeon[1] ;
  dungeon[4].dirs[WEST]=&dungeon[3] ; dungeon[5].dirs[WEST]=&dungeon[4] ;
  dungeon[7].dirs[WEST]=&dungeon[6] ; dungeon[8].dirs[WEST]=&dungeon[7] ;
  
  dungeon[0].dirs[SOUTH]=&dungeon[3] ; dungeon[1].dirs[SOUTH]=&dungeon[4] ; dungeon[2].dirs[SOUTH] = &dungeon[5];
  dungeon[3].dirs[SOUTH]=&dungeon[6] ; dungeon[4].dirs[SOUTH]=&dungeon[7] ; dungeon[5].dirs[SOUTH] = &dungeon[8];
  
  dungeon[3].dirs[NORTH]=&dungeon[0] ; dungeon[4].dirs[NORTH]=&dungeon[1] ; dungeon[5].dirs[NORTH] = &dungeon[2];
  dungeon[6].dirs[NORTH]=&dungeon[3] ; dungeon[7].dirs[NORTH]=&dungeon[4] ; dungeon[8].dirs[NORTH] = &dungeon[5];
  
  // Floor 2
  dungeon[9].dirs[EAST]=&dungeon[10] ; dungeon[10].dirs[EAST]=&dungeon[11] ;
  dungeon[12].dirs[EAST]=&dungeon[13] ; dungeon[13].dirs[EAST]=&dungeon[14] ;
  dungeon[15].dirs[EAST]=&dungeon[16] ; dungeon[16].dirs[EAST]=&dungeon[17] ;
  
  dungeon[10].dirs[WEST]=&dungeon[9] ; dungeon[11].dirs[WEST]=&dungeon[10] ;
  dungeon[13].dirs[WEST]=&dungeon[12] ; dungeon[14].dirs[WEST]=&dungeon[13] ;
  dungeon[16].dirs[WEST]=&dungeon[15] ; dungeon[17].dirs[WEST]=&dungeon[16] ;
  
  dungeon[9].dirs[SOUTH]=&dungeon[12] ; dungeon[10].dirs[SOUTH]=&dungeon[13] ; dungeon[11].dirs[SOUTH] = &dungeon[14];
  dungeon[12].dirs[SOUTH]=&dungeon[15] ; dungeon[13].dirs[SOUTH]=&dungeon[16] ; dungeon[14].dirs[SOUTH] = &dungeon[17];
  
  dungeon[12].dirs[NORTH]=&dungeon[9] ; dungeon[13].dirs[NORTH]=&dungeon[10] ; dungeon[14].dirs[NORTH] = &dungeon[11];
  dungeon[15].dirs[NORTH]=&dungeon[12] ; dungeon[16].dirs[NORTH]=&dungeon[13] ; dungeon[17].dirs[NORTH] = &dungeon[14];
  
  // Floor 3
  dungeon[18].dirs[EAST]=&dungeon[19] ; dungeon[19].dirs[EAST]=&dungeon[20] ;
  dungeon[21].dirs[EAST]=&dungeon[22] ; dungeon[22].dirs[EAST]=&dungeon[23] ;
  dungeon[24].dirs[EAST]=&dungeon[25] ; dungeon[25].dirs[EAST]=&dungeon[26] ;
  
  dungeon[19].dirs[WEST]=&dungeon[18] ; dungeon[20].dirs[WEST]=&dungeon[19] ;
  dungeon[22].dirs[WEST]=&dungeon[21] ; dungeon[23].dirs[WEST]=&dungeon[22] ;
  dungeon[25].dirs[WEST]=&dungeon[24] ; dungeon[26].dirs[WEST]=&dungeon[25] ;
  
  dungeon[18].dirs[SOUTH]=&dungeon[21] ; dungeon[19].dirs[SOUTH]=&dungeon[22] ; dungeon[20].dirs[SOUTH] = &dungeon[23];
  dungeon[21].dirs[SOUTH]=&dungeon[24] ; dungeon[22].dirs[SOUTH]=&dungeon[25] ; dungeon[23].dirs[SOUTH] = &dungeon[26];
  
  dungeon[21].dirs[NORTH]=&dungeon[18] ; dungeon[22].dirs[NORTH]=&dungeon[19] ; dungeon[23].dirs[NORTH] = &dungeon[20];
  dungeon[24].dirs[NORTH]=&dungeon[21] ; dungeon[25].dirs[NORTH]=&dungeon[22] ; dungeon[26].dirs[NORTH] = &dungeon[23];
  
  // Floor 4
  dungeon[27].dirs[EAST]=&dungeon[28] ; dungeon[28].dirs[EAST]=&dungeon[29] ;
  dungeon[30].dirs[EAST]=&dungeon[31] ; dungeon[31].dirs[EAST]=&dungeon[32] ;
  dungeon[33].dirs[EAST]=&dungeon[34] ; dungeon[34].dirs[EAST]=&dungeon[35] ;
  
  dungeon[28].dirs[WEST]=&dungeon[27] ; dungeon[29].dirs[WEST]=&dungeon[28] ;
  dungeon[31].dirs[WEST]=&dungeon[30] ; dungeon[32].dirs[WEST]=&dungeon[31] ;
  dungeon[34].dirs[WEST]=&dungeon[33] ; dungeon[35].dirs[WEST]=&dungeon[34] ;
  
  dungeon[27].dirs[SOUTH]=&dungeon[30] ; dungeon[28].dirs[SOUTH]=&dungeon[31] ; dungeon[29].dirs[SOUTH] = &dungeon[32];
  dungeon[30].dirs[SOUTH]=&dungeon[33] ; dungeon[31].dirs[SOUTH]=&dungeon[34] ; dungeon[32].dirs[SOUTH] = &dungeon[35];
  
  dungeon[30].dirs[NORTH]=&dungeon[27] ; dungeon[31].dirs[NORTH]=&dungeon[28] ; dungeon[32].dirs[NORTH] = &dungeon[29];
  dungeon[33].dirs[NORTH]=&dungeon[30] ; dungeon[34].dirs[NORTH]=&dungeon[31] ; dungeon[35].dirs[NORTH] = &dungeon[32];
  
  // Floor 4
  dungeon[27].dirs[EAST]=&dungeon[28] ; dungeon[28].dirs[EAST]=&dungeon[29] ;
  dungeon[30].dirs[EAST]=&dungeon[31] ; dungeon[31].dirs[EAST]=&dungeon[32] ;
  dungeon[33].dirs[EAST]=&dungeon[34] ; dungeon[34].dirs[EAST]=&dungeon[35] ;
  
  dungeon[28].dirs[WEST]=&dungeon[27] ; dungeon[29].dirs[WEST]=&dungeon[28] ;
  dungeon[31].dirs[WEST]=&dungeon[30] ; dungeon[32].dirs[WEST]=&dungeon[31] ;
  dungeon[34].dirs[WEST]=&dungeon[33] ; dungeon[35].dirs[WEST]=&dungeon[34] ;
  
  dungeon[27].dirs[SOUTH]=&dungeon[30] ; dungeon[28].dirs[SOUTH]=&dungeon[31] ; dungeon[29].dirs[SOUTH] = &dungeon[32];
  dungeon[30].dirs[SOUTH]=&dungeon[33] ; dungeon[31].dirs[SOUTH]=&dungeon[34] ; dungeon[32].dirs[SOUTH] = &dungeon[35];
  
  dungeon[30].dirs[NORTH]=&dungeon[27] ; dungeon[31].dirs[NORTH]=&dungeon[28] ; dungeon[32].dirs[NORTH] = &dungeon[29];
  dungeon[33].dirs[NORTH]=&dungeon[30] ; dungeon[34].dirs[NORTH]=&dungeon[31] ; dungeon[35].dirs[NORTH] = &dungeon[32];
  
  // Floor 5
  dungeon[36].dirs[EAST]=&dungeon[37] ; dungeon[37].dirs[EAST]=&dungeon[38] ;
  dungeon[39].dirs[EAST]=&dungeon[40] ; dungeon[40].dirs[EAST]=&dungeon[41] ;
  dungeon[42].dirs[EAST]=&dungeon[43] ; dungeon[43].dirs[EAST]=&dungeon[44] ;
  
  dungeon[37].dirs[WEST]=&dungeon[36] ; dungeon[38].dirs[WEST]=&dungeon[37] ;
  dungeon[40].dirs[WEST]=&dungeon[39] ; dungeon[41].dirs[WEST]=&dungeon[40] ;
  dungeon[43].dirs[WEST]=&dungeon[42] ; dungeon[44].dirs[WEST]=&dungeon[43] ;
  
  dungeon[36].dirs[SOUTH]=&dungeon[39] ; dungeon[37].dirs[SOUTH]=&dungeon[40] ; dungeon[38].dirs[SOUTH] = &dungeon[41];
  dungeon[39].dirs[SOUTH]=&dungeon[42] ; dungeon[40].dirs[SOUTH]=&dungeon[43] ; dungeon[41].dirs[SOUTH] = &dungeon[44];
  
  dungeon[39].dirs[NORTH]=&dungeon[36] ; dungeon[40].dirs[NORTH]=&dungeon[37] ; dungeon[41].dirs[NORTH] = &dungeon[38];
  dungeon[42].dirs[NORTH]=&dungeon[39] ; dungeon[43].dirs[NORTH]=&dungeon[40] ; dungeon[44].dirs[NORTH] = &dungeon[41];
  
  // Up
  dungeon[0].dirs[UP] = &dungeon[9];
  dungeon[9].dirs[UP] = &dungeon[18];
  dungeon[18].dirs[UP] = &dungeon[27];
  dungeon[27].dirs[UP] = &dungeon[36];
  
  // Down
  dungeon[13].dirs[DOWN] = &dungeon[4];
  dungeon[22].dirs[DOWN] = &dungeon[13];
  dungeon[31].dirs[DOWN] = &dungeon[22];
  dungeon[40].dirs[DOWN] = &dungeon[31];
  
  // Goodies
  dungeon[44].contents |= EXIT;
  dungeon[36].contents |= SWORD;
  dungeon[11].contents |= SPHINX;
  dungeon[17].contents |= GOLD;
  dungeon[14].contents |= GOLD;
  dungeon[0].contents |= GOLD;
  dungeon[43].contents |= GOLD;
  dungeon[30].contents |= GOLD;
  dungeon[39].contents |= GOLD;
  dungeon[27].contents |= GOLD;
  dungeon[31].contents |= GOLD;
  
  now = &dungeon[4];
  quest(now, ROOMS);
  if (now == &dungeon[44]) {
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
