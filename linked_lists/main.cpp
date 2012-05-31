//
//  main.cpp
//  List
//
//  Created by Ming Chow on 5/30/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#include <iostream>
#include "List.h"

using namespace std;

int main(int argc, const char * argv[])
{
    List *l = new List();
    l->add("Tom");
    l->add("Dick");
    l->add("Harry");
    l->add("Doo");
    l->add("Doodoo");
    l->print();
    delete l;
    return 0;
}
