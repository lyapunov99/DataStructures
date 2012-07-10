//
//  Elem.cpp
//  Assoc
//
//  Created by Ming Chow
//  Copyright (c) 2012 Tufts University. All rights reserved.
//


#include <iostream>
#include "Elem.h"

using namespace std;

Elem::Elem()
{
    next = NULL;
}

Elem::Elem(string key)
{
    next = NULL;
    this->key = key;
}
