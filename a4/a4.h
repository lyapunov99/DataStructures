#include <iostream>

using namespace std;

// Total directions one can try from each room
#define DIRS  6

// Directions in which we can try to go. 
#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3
#define UP    4
#define DOWN  5

// Goodies in each room
#define EXIT 1
#define GOLD 2
#define SWORD 4
#define SPHINX 8

class Room
{
 public:
  int contents;      // contents of this room: from above.
  int number;        // this room's number: between 0 and rooms-1.
  int marker;        // marker for you to use: initially 0.
  Room *dirs[DIRS];  // where other rooms are.
  Room(int n = 0)
    {
      number = n;
      contents = 0;
      marker = 0;
      for (int i = 0; i < DIRS; i++) {
	dirs[i] = NULL;
      }
    }

  int gold()
  {
    return (contents & GOLD) != 0;
  }
  
  int exit() 
  {
    return (contents & EXIT) != 0;
  }

  int sword()
  {
    return (contents & SWORD) != 0;
  }

  int sphinx()
  {
    return (contents & SPHINX) != 0;
  }

  void print()
  {
    cout << "Room " << number << " is at address " << this <<" and has"; 
    if (gold()) {
      cout << " Gold";
    }
    if (exit()) {
      cout << " Exit";
    }
    if (sword()) {
      cout << " Sword";
    }
    if (sphinx()) {
      cout << " Sphinx";
    }
    cout << "(marker " << marker << ")" << endl;
  }
}; 

// Description: Your routine is passed a starting position and a number of rooms.
// Precondition: start and rooms are defined
void quest(Room *start, int rooms); 

// Description: You call this routine to actually move between rooms.
// Precondition: dir is defined
// Postcondition: returns 1 if you can move to the room, 0 if not
int go(int dir);
