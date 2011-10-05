//
//  sample.cpp
//
//  Created by Ming Chow on 9/21/2011; updated on 10/5/2011
//

#include <iostream>
#include "Rect.h"

using namespace std;

// C/C++ convention to declare signatures of functions
void pointerFun();

Rect doubleRect (Rect r2);

Rect doubleRect(Rect r2)
{
  Rect newRect;
  newRect.length = r2.length * 2;
  newRect.width = r2.width * 2;
  return newRect;
}

void pointerFun()
{
    Rect *r2 = new Rect(10, 20, 5, 7);
    r2->setId("*** rect 2 inside pointerFun() ***");
    cout << "The area of the rectangle 2 is " << r2->getArea() << endl;
    cout << "The permimeter of the rectangle 2 is " << r2->getPerimeter() << endl;
    cout << "The diagonal of the rectangle 2 is " << r2->getDiagonal() << endl;
    cout << "Is rectangle 2 a square? " << r2->isSquare() << endl;
    Rect *r3 = new Rect(8, 8);
    r3->setId("*** rect 3 inside pointerFun() ***");
    cout << "The area of the rectangle 3 is " << r3->getArea() << endl;
    cout << "The permimeter of the rectangle 3 is " << r3->getPerimeter() << endl;
    cout << "The diagonal of the rectangle 3 is " << r3->getDiagonal() << endl;
    cout << "Is rectangle 3 a square? " << r3->isSquare() << endl;
    Rect r4 = *r2 + *r3;
    r4.setId("*** Sum of rectangle 2 and rectangle 3 ***");
    cout << "The area of the rectangle 4 is " << r4.getArea() << endl;
    cout << "The permimeter of the rectangle 4 is " << r4.getPerimeter() << endl;
    cout << "The diagonal of the rectangle 4 is " << r4.getDiagonal() << endl;
    cout << "Is rectangle 4 a square? " << r4.isSquare() << endl;    
    delete r2;
    delete r3;
}

int main (int argc, const char * argv[])
{
    Rect r1 = Rect();
    r1.setWidth(4);
    r1.setLength(7);
    Rect compareRect = Rect(7, 4);
    compareRect.setId("*** A comparison Rect of length = 7 and width = 4 ***");
    if (r1 == compareRect) {
      cout << "*** Rectangle 1 and compareRect are the same shape" << endl;
    }
    else {
      cout << "*** Rectangle 1 and compareRect are different" << endl;
    }
    r1.setId("*** rect 1 inside main ***");
    cout << "The area of the rectangle 1 is " << r1.getArea() << endl;
    cout << "The permimeter of the rectangle 1 is " << r1.getPerimeter() << endl;
    cout << "The diagonal of the rectangle 1 is " << r1.getDiagonal() << endl;
    cout << "Is rectangle 1 a square? " << r1.isSquare() << endl;
    Rect privilegedRect = doubleRect(r1);
    cout << "privilegedRect's width is " << privilegedRect.getWidth() << endl;
    cout << "privilegedRect's height is " << privilegedRect.getLength() << endl;
    pointerFun();
}
