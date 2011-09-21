//
//  Rect.h (the interface)
//
//  Created by Ming Chow on 9/21/11.
//

#ifndef classes_Rect_h
#define classes_Rect_h

#include <iostream>

using namespace std;

/*
 * Class invariant: length >= 0, width >= 0
 */

class Rect
{
private:
    // Identifying information
    string id;
    
    // Dimensions
    int length;
    int width;
    
    // Position
    int x;
    int y;
    
public:
    // Constructors: three varieties
    Rect();
    Rect(int length, int width);
    Rect(int length, int width, int x, int y);
    
    // Precondition: length and width are legitimate
    // Postcondition: result >= 0
    int getArea();

    // Precondition: length and width are legitimate
    // Postcondition: result >= 0
    int getPerimeter();
    
    // Precondition: length and width are legitimate
    // Postcondition: result >= 0
    double getDiagonal();
    
    // Precondition: length and width are legitimate
    // Postcondition: if length = width, return true, else fase
    bool isSquare();
    
    // Precondition: x is defined
    // Postcondition: returns x
    
    int getX();
    
    // Precondition: y is defined
    // Postcondition: returns y
    int getY();
    
    // Precondition: x is defined
    void setX(int newX);
    
    // Precondition: y is defined
    void setY(int newY);
    
    // Precondition: length is defined; length >= 0
    // Postcondition: returns length
    int getLength();
    
    // Precondition: width is defined; width >= 0
    // Postcondition: returns width
    int getWidth();
    
    // Precondition: length is defined
    // Postcondition: length >= 0
    void setLength (int newLength);
    
    // Precondition: width is defined
    // Postcondition: width >= 0
    void setWidth (int newWidth);
    
    // Precondition: id is defined
    // Postcondition: returns id
    string getId();
    
    // Precondition: id is defined
    void setId (string id);
    
    ~Rect();
};

#endif
