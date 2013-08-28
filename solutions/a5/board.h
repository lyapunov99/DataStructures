#include<fstream>
#ifndef CAR_DEF
#include "car.h"
#endif
#define MAXCARS 18
#define BSIZE 6
#define ASCII_BASE 97
using namespace std; 


// a board has an array of up to 18 cars
// 
class Board {
 public: 
  Board();
  Board(string fname);
  bool move(char carID, char dir); // return true if move successful, false ow
  bool checkDone(); // return true if * car is at exit point
  void printBoard(); 

 private:
  Car* cars[MAXCARS];  // store an array of pointers to cars
  int ncars;         // how many cars in this game
  char display[BSIZE][BSIZE];  // goes from 0 to BSIZE-1

  // used in Board(string filename) to create cars
  // 
  bool createCar(int xval, int yval, char dir, int len); 

  // used in both constructors to set display to empty
  void clearDisplay(); 

  // used in move(char carID, char dir) to actually make the moves
  bool moveUp(int carindex); 
  bool moveDown(int carindex); 
  bool moveLeft(int carindex); 
  bool moveRight(int carindex); 
};
