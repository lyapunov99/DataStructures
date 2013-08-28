#ifndef CAR_DEF
#include "car.h"
#endif

#ifndef BOARD_DEF
#include "board.h"
#endif

#include <iostream>
#include <fstream>
#define HORIZ 'h'
#define VERT 'v' 

int main(int argc, char* argv[]) {

  Car first, second, third; 
  char car2move, dir; 
  bool done = false; 

  // deal with command line arguments
  string inputstring;
  if (argc == 1) { 
    inputstring  = "input6.txt"; 
  }
  else if (argc != 3) { 
    cout << "Wrong arguments:  cartest -f inputfile.txt" << endl;
    exit (0); 
  }
  else {
    inputstring = argv[2]; 
  }

  Board myboard(inputstring); 
  myboard.printBoard();
  int nmoves = 0;

  while (!done) { 
    cout << "Type the letter of the car you want to move, and its direction\n"; 
    cin >> car2move >> dir; 
    if (dir == 'q') { 
      done=true; 
    } 
    else { 
      if ( myboard.move(car2move,dir) ) { 
	nmoves++; 
      }
      myboard.printBoard();
      if (myboard.checkDone()) { 
	cout << endl << endl; 
	cout << "You won the game!  Congratulations!\n";
	cout << "You took " << nmoves << " moves\n"; 
	done = true; 
      }
    }
  }
}
