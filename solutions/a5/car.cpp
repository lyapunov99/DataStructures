#include "car.h"

Car::Car() {   // default cars are of length 2 and are not red
  isRed=false;
  length=2;
}

void Car::setxy(int x, int y) { 
  xcoord=x; 
  ycoord=y; 
}
  
void Car::setOrient(char orient) { 
  orientation=orient;
}
  
void Car::setLength(int len) { 
  length=len;
}

void Car::setRed(bool red) { 
  isRed=red;
}

void Car::setDisplayChar(char dchar) { 
  displayChar=dchar;
}

void Car::printCar() { 
  cout << "position is (" << xcoord << "," << ycoord << ")\n"; 
  cout << "orientation is " << orientation << endl; 
  cout << "length is " << length <<endl; 
  if (isRed) { 
    cout << "and car is Red\n";
  }
  else {
    cout << "and it is not Red\n"; 
  }
}

char Car::getOrient(){ 
  return orientation; 
}

char Car::getDisplayChar(){ 
  return displayChar;
}


int Car::getX() { 
  return xcoord; 
}

int Car::getY() { 
  return ycoord; 
}

int Car::getLength() { 
  return length; 
}
