//
//  Elem.h
//  A simple interface for a key-value mapping (or word-definition); key and value are strings
//  lab10
//
//  COMP 15: Data Structures
//  Tufts University Department of Computer Science
//

#ifndef Assoc_Elem_h
#define Assoc_Elem_h

#include <iostream>

using namespace std;

// Class invariant: next is NULL or defined

class Elem 
{ 
public:
    Elem *next;
    string key;
    string value;
    
    // Definition: creates a string key - string value mapping
    // Precondition: key, value, and next are undefined
    // Postcondition: next is null
    Elem();

    // Definition: creates a string key - string value mapping
    // Precondition: key, value, and next are undefined
    // Postcondition: next is null; key is defined
    Elem(string key);
};

#endif
