//
//  Rect.cpp (the implementation)
//
//  Created by Ming Chow on 9/21/11.
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
    this->length = length;
    this->width = width;
    x = 0;
    y = 0;
    id = "";
    cout << "In constructor 2" << endl;
}

Rect::Rect (int length, int width, int x, int y)
{
    this->length = length;
    this->width = width;
    this->x = x;
    this->y = y;
    id = "";
    cout << "In constructor 3" << endl;
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
