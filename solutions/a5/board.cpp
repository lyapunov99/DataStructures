#include "board.h"
#define BOARD_DEF 1
#define EXITROW 3
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

// create a default board with no cars 
Board::Board(){
  ncars=0;
  clearDisplay();
}


// create a board by reading car positions from a file
Board::Board(string fname){
  ifstream fin; 
  int xval, yval, len; 
  char dir; 

  ncars=0;
  clearDisplay(); 

  fin.open(fname.c_str());
  if (fin.fail()) { 
    cout << "couldnt read data from "<<fname<<endl; 
    exit(1);
  }

    // read the lines from the file
    // at each line, create a car and populate display
    // and update ncars
    // create display character that matches position in list

  while (!fin.eof()) { 
    fin >> xval >> yval >> dir >> len; 

    if (fin.fail()) {   // either eof or corrupt
      if (!fin.eof()){ 
	cout << "input file " << fname << " corrupted\n"; 
	return;
      }
      else { // at end of file
	// make last car red if it is in line 3 and horizontal 
	int lastcar = ncars-1; 
	if (cars[lastcar]->getOrient() == 'h' && 
	    cars[lastcar]->getY() == EXITROW) {

	  cars[lastcar]->setRed(true); 
	  cars[lastcar]->setDisplayChar('*');
	  int redX = cars[lastcar]->getX(); 
	  display[redX][EXITROW] = '*'; 
	  display[redX+1][EXITROW] = '*'; 
	  return;
	}
	else { 
	  cout << "last car isn't at 0 3\n"; 
	}
      }
    }
    // else, input was okay; try to create new car
    if (! createCar(xval, yval, dir, len) ) {
      cout << "Couldn't create car " << xval << yval << dir << len <<endl; 
      return; 
    }
  }    

}


bool Board::checkDone() { 
  // return true if got * car into pos 4, 3

  Car* starcar = cars[ncars-1]; 
  if (starcar->getX() == 4 && starcar->getY() == 3) { 
    return true; 
  }
  return false; 
}


bool Board::move(char carID, char dir) { 

  int carindex; 
  bool result;
  if (carID=='*') { 
    carindex=ncars-1; 
  }
  else { 
    // can map characters back by subtracting ASCII_BASE
    carindex = static_cast<int>(carID) - ASCII_BASE; 
  }
  
  //  cout << "This is car number " << carindex << endl; 
  //  cout << "Moving it " << dir << endl;

  switch (dir) { 
  case 'u':
    result = moveUp(carindex); 
    break;
  case 'd':
    result = moveDown(carindex); 
    break; 
  case 'l': 
    result = moveLeft(carindex);
    break; 
  case 'r': 
    result = moveRight(carindex); 
    break;
  default: 
    cout << "Didn't understand your requested direction to move (" << dir << ")\n"; 
    return false; 
  }
  return result; 
}


void Board::printBoard() { 
  int i, j; 
  for (j = BSIZE-1; j >= 0; j--) {
    cout << "------------------------" << endl;
    for (i = 0; i<BSIZE; i++) {
      cout << " " << display[i][j] << " |" ; 
    }
    cout << endl; 
  }
    cout << "------------------------" << endl;
}

// private functions

bool Board::createCar( int xval, int yval, char dir, int len) { 
  if (xval < 0 || xval >= BSIZE || yval < 0 || yval >= BSIZE) { 
    return false; 
  }
  if (len < 2 || len > 3) { 
    return false; 
  }
  if (dir != 'h' && dir != 'v') {
    return false; 
  }
  Car*  mycar = new Car; 
  mycar->setxy(xval,yval); 
  mycar->setOrient(dir); 
  mycar->setLength(len);
  mycar->setRed(false); // fix this later if it's the last line in file
  cars[ncars]=mycar; 

  // set display character
  char dchar = static_cast<char>(ASCII_BASE + ncars); 
  mycar->setDisplayChar( dchar);

  // update display, report conflicts if needed
  // put the new car into the display and check conflicts
  int myx, myy; 
  myx = xval; 
  myy = yval;
  for (int i =0; i < mycar->getLength(); i++) { 
    if (dir == 'h') { 
      myx=xval+i; 
    }
    else {  // vertical, change y
      myy=yval+i;
    }
    if (display[myx][myy] != ' ') { 
      cout << "tried to write over an existing display char\n"; 
    }
    else { 
      display[myx][myy] = dchar; 
    }
  }

  ncars++; 
  return true; 
}


void Board::clearDisplay(){ 
  for (int i = 0; i<BSIZE;i++) { 
    for (int j=0; j<BSIZE; j++) { 
      display[i][j]=' ';
    }
  }
}


bool Board::moveRight( int carindex) { 
  Car* mycar = cars[carindex]; 
  int rightOfCar;
  int myx=mycar->getX();
  int myy=mycar->getY();

  if (mycar->getOrient() == 'v') { 
    cout << "This is a vertical car and cannot move left or right\n"; 
    return false; 
  }

  rightOfCar = myx + mycar->getLength() - 1; // calculate rightmost slot
  if (rightOfCar > BSIZE-2) { // then no room to move right
    cout << "Moving right would move this car off the board\n"; 
    return false; 
  }

  if (display[rightOfCar+1][myy] != ' ') { 
    cout << "There is another car in your way; cannot move right\n"; 
    return false; 
  }
  
  // else, okay to move
  mycar->setxy(myx+1, myy);  // move car position itself
  display[myx][myy]=' ';    // update display
  display[rightOfCar+1][myy] = mycar->getDisplayChar(); 

  return true;
}
  
bool Board::moveLeft( int carindex) { 
  Car* mycar = cars[carindex]; 
  int rightOfCar;
  int myx=mycar->getX();
  int myy=mycar->getY();

  if (mycar->getOrient() == 'v') { 
    cout << "This is a vertical car and cannot move left or right\n"; 
    return false; 
  }

  rightOfCar = myx + mycar->getLength() - 1; // calculate rightmost slot
  if (myx < 1) { // then no room to move left
    cout << "Moving left would move this car off the board\n"; 
    return false; 
  }

  if (display[myx-1][myy] != ' ') { 
    cout << "There is another car in your way; cannot move left\n"; 
    return false; 
  }
  
  // else, okay to move
  mycar->setxy(myx-1, myy);  // move car position itself
  display[rightOfCar][myy]=' ';    // update display
  display[myx-1][myy] = mycar->getDisplayChar(); 

  return true;
}
  
bool Board::moveDown( int carindex) { 
  Car* mycar = cars[carindex]; 
  int topOfCar;
  int myx=mycar->getX();
  int myy=mycar->getY();

  if (mycar->getOrient() == 'h') { 
    cout << "This is a horizontal car and cannot move up or down\n"; 
    return false; 
  }

  topOfCar = myy + mycar->getLength() - 1; // calculate top slot
  if (myy < 1) { // then no room to move down
    cout << "Moving down would move this car off the board\n"; 
    return false; 
  }

  if (display[myx][myy-1] != ' ') { 
    cout << "There is another car in your way; cannot move down\n"; 
    return false; 
  }
  
  // else, okay to move
  mycar->setxy(myx, myy-1);  // move car position itself
  display[myx][topOfCar]=' ';    // update display
  display[myx][myy-1] = mycar->getDisplayChar(); 

  return true;
}


bool Board::moveUp( int carindex) { 
  
  Car* mycar = cars[carindex]; 
  int topOfCar;
  int myx=mycar->getX();
  int myy=mycar->getY();

  if (mycar->getOrient() == 'h') { 
    cout << "This is a horizontal car and cannot move up or down\n"; 
    return false; 
  }

  topOfCar = myy + mycar->getLength() - 1; // calculate top slot
  if (topOfCar > BSIZE-2) { // then no room to move up
    cout << "Moving up would move this car off the board\n"; 
    return false; 
  }

  if (display[myx][topOfCar + 1] != ' ') { 
    cout << "There is another car in your way; cannot move up\n"; 
    return false; 
  }
  
  // else, okay to move
  mycar->setxy(myx, myy+1);  // move car position itself
  display[myx][myy]=' ';    // update display
  display[myx][topOfCar+1] = mycar->getDisplayChar(); 

  return true; 
}
