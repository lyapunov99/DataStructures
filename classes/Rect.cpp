//
//  Rect.cpp (the implementation)
//
//  Edit (9/25/2011): Special thanks to A.J. Jenkins (student in COMP 15) for pointing out that I didn't accomodate invariant correctly in constructors
//  Created by Ming Chow on 9/21/2011; updated on 10/5/2011
//

#include <iostream>
#include <math.h> // required for sqrt() and pow() function
#include "Rect.h"

using namespace std;

Rect::Rect()
{
    length = 0;
    width = 0;
    x = 0;
    y = 0;
    id = "";
    cout << "In constructor 1" << endl;
}

Rect::Rect (int length, int width)
{
    if (length >= 0) {
        this->length = length;
    }
    else {
        cout << "Length has to be >= 0" << endl;
        this->length = 0;
    }
    if (width >= 0) {
        this->width = width;
    }
    else {
        cout << "Width has to be >= 0" << endl;
        this->width = 0;
    }
    x = 0;
    y = 0;
    id = "";
    cout << "In constructor 2" << endl;
}

Rect::Rect (int length, int width, int x, int y)
{
    if (length >= 0) {
        this->length = length;
    }
    else {
        cout << "Length has to be >= 0" << endl;
        this->length = 0;
    }
    if (width >= 0) {
        this->width = width;
    }
    else {
        cout << "Width has to be >= 0" << endl;
        this->width = 0;
    }
    this->x = x;
    this->y = y;
    id = "";
    cout << "In constructor 3" << endl;
}

Rect Rect::operator+ (Rect r2)
{
  Rect newRect;
  newRect.length = length + r2.length;
  newRect.width = width + r2.width;
  newRect.x = x;
  newRect.y = y;
  return newRect;
}

bool Rect::operator== (Rect r2)
{
  return ((length == r2.length && width == r2.width) || (length == r2.width && width == r2.length));
}

int Rect::getArea()
{
    return length * width;
}

int Rect::getPerimeter()
{
    return 2 * (length + width);
}

double Rect::getDiagonal()
{
    return sqrt(pow(length,2) + pow(width,2));
}

bool Rect::isSquare()
{
    return length == width;
}

int Rect::getX()
{
    return x;
}

int Rect::getY()
{
    return y;
}

void Rect::setX(int newX)
{
    x = newX;
}

void Rect::setY(int newY)
{
    y = newY;
}

int Rect::getLength()
{
    return length;
}

int Rect::getWidth()
{
    return width;
}

void Rect::setLength(int newLength)
{
    if (newLength >= 0) {
        length = newLength;
    }
    else {
        cout << "Length has to be >= 0" << endl;
    }
}

void Rect::setWidth(int newWidth)
{
    if (newWidth >= 0) {
        width = newWidth;
    }
    else {
        cout << "Width has to be >= 0" << endl;
    }
}

string Rect::getId()
{
    return id;
}

void Rect::setId(string id)
{
    this->id = id;
}

Rect::~Rect()
{
    cout << "Good-bye " << id << "!!!" << endl;
}
