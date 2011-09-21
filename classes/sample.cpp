//
//  sample.cpp
//
//  Created by Ming Chow on 9/21/11.
//

#include <iostream>
#include "Rect.h"

using namespace std;

// C/C++ convention to declare signatures of functions
void pointerFun();

void pointerFun()
{
    Rect *r2 = new Rect(10, 20, 5, 7);
    r2->setId("*** rect 2 inside pointerFun() ***");
    cout << "The area of the rectangle 2 is " << r2->getArea() << endl;
    cout << "The permimeter of the rectangle 2 is " << r2->getPerimeter() << endl;
    cout << "The diagonal of the rectangle 2 is " << r2->getDiagonal() << endl;
    cout << "Is rectangle 2 a square? " << r2->isSquare() << endl;
    delete r2;
    Rect *r3 = new Rect(8, 8);
    r2->setId("*** rect 3 inside pointerFun() ***");
    cout << "The area of the rectangle 3 is " << r3->getArea() << endl;
    cout << "The permimeter of the rectangle 3 is " << r3->getPerimeter() << endl;
    cout << "The diagonal of the rectangle 3 is " << r3->getDiagonal() << endl;
    cout << "Is rectangle 3 a square? " << r3->isSquare() << endl;
    delete r3;
}

int main (int argc, const char * argv[])
{
    Rect r1 = Rect();
    r1.setWidth(4);
    r1.setLength(7);
    r1.setId("*** rect 1 inside main ***");
    cout << "The area of the rectangle 1 is " << r1.getArea() << endl;
    cout << "The permimeter of the rectangle 1 is " << r1.getPerimeter() << endl;
    cout << "The diagonal of the rectangle 1 is " << r1.getDiagonal() << endl;
    cout << "Is rectangle 1 a square? " << r1.isSquare() << endl;
    pointerFun();
}
