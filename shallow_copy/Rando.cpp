//
//  Rando.cpp
//
//  Created by Ming Chow on 10/19/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Rando.h"

using namespace std;

Rando::Rando(int n)
{
    cout << "In constructor of Rando" << endl;
    srand(time(NULL));
    if (n > 0) {
        list = new int[n];
        size = n;
    }
    else {
        list = new int[10];
        size = 10;
    }
    for (int i = 0; i < size; i++) {
        list[i] = rand() % 49 + 1; // Generate a number between 1 to 49 (inclusive)
    }
}

void Rando::setValue(int loc, int newVal)
{
    if (loc >= 0 && loc < size) {
        list[loc] = newVal;
    }
}

void Rando::print()
{
    cout << "The magic numbers are ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

Rando::~Rando()
{
    cout << "In destructor of Rando" << endl;
    delete [] list;
}
