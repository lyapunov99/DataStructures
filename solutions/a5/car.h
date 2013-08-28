#define CAR_DEF 1
#include <iostream>
using namespace std; 

// car locations are specified by their lower left corners, 
// and by orientation ("h"=horizontal, "v"=vertical).
// they also have a length and a display character.  
// If red, display char must be "*".
//
class Car { 
 public:  

  Car(); // set to not red and length 2
  void setxy(int x, int y); 
  void setOrient(char orient); 
  void setLength(int len);
  void setRed(bool red); 
  void printCar(); 
  void setDisplayChar(char dchar); 
  int getX(); 
  int getY();
  int getLength(); 
  char getOrient();
  char getDisplayChar(); 

 private: 
  int xcoord, ycoord; 
  char orientation;
  int length; 
  bool isRed; 
  char displayChar; 
};

   
