//
//  Assoc.h
//  An interface for a string-to-string associative array
//  lab10
//
//  COMP 15: Data Structures
//  Tufts University Department of Computer Science
//

#ifndef Assoc_Assoc_h
#define Assoc_Assoc_h

#define HASHES 10007

#include <iostream>
#include "Elem.h"

using namespace std;

class Assoc
{
private:
    Elem **heads; // the hash table
    int numElems; // number of elements (key-value pairs) in associative array
    
    // Description: generates a hash value for a key string
    // Precondition: key is defined
    // Postcondition: returns an integer >= 0 that is in range of hash table size
    unsigned int hash(string key);
    
public:
	// Description: instantiates associative array of string key-string value mappings
	// Precondition: associative array is undefined
	// Postcondition: number of elements in associative array is 0
    Assoc();
    
    // Description: adds string key to associative array with corresponding string value
    // Precondition: associative array is defined, key is defined
    // Postconditions: returns string value if string key exists in associative array or add new key-value element to associative array
    string &operator[] (const string &key);
    
    // Description: destroys associative array from memory
    // Precondition: associative array is defined
    // Postcondition: associative array is eliminated from memory
    ~Assoc();
};

#endif
