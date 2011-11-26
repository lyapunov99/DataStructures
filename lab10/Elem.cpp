//
//  Elem.cpp
//  Assoc
//
//  Created by Ming Chow on 11/25/11.
//  Copyright (c) 2011 Tufts University. All rights reserved.
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
