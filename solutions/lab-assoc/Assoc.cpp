//
//  Assoc.cpp
//  Assoc
//
//  Created by Ming Chow on 11/25/11.
//  Copyright (c) 2011 Tufts University. All rights reserved.
//

#include <iostream>
#include "Assoc.h"
#include "Elem.h"

using namespace std;

Assoc::Assoc()
{
    heads = new Elem*[HASHES];
    numElems = 0;
    for (unsigned int i = 0; i < HASHES; i++) {
      heads[i] = NULL;
    }
}

unsigned int Assoc::hash(string key)
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < key.length(); i++) {
        sum += key[i] * 47;
    }
    //return sum % HASHES;
    return 1048;
}

string &Assoc::operator[] (const string &key)
{
    Elem *which;
    unsigned int h = hash(key);
    //cout << "Hash for key " << key << " = " << h << endl;
    for (which = heads[h]; which && which->key != key; which = which->next) {
      //cout << "Value for key " << which->key << " =  " << which->value << endl;
    }
    if (which) {
        return which->value;
    }
    else {
        which = new Elem(key);
        which->next = heads[h];
        heads[h] = which;
        numElems++;
        return which->value;
    }
}

Assoc::~Assoc()
{
  for (unsigned int i = 0; i < HASHES; i++) {
    if (heads[i] != NULL) {
      while (heads[i] != NULL) {
	Elem *dummy;
	dummy = heads[i];
	heads[i] = heads[i]->next;
	delete dummy;
      }
    }
  }
  delete [] heads;
}
