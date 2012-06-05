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

    if (l->contains("Poo")) {
      cout << "\nPoo was found" << endl;
    }
    else {
      cout << "\nPoo was not found" << endl;
    }

    if (l->contains("Harry")) {
      cout << "\nHarry was found" << endl;
    }
    else {
      cout << "\nHary was not found" << endl;
    }

    cout << "\nRemoving Dick..." << endl;
    l->remove(1);
    l->print();

    cout << "\nRemoving last element..." << endl;
    l->remove(l->size() - 1);
    l->print();

    cout << "\nThe second element in the list is " << l->get(1) << endl;

    cout << "\nThe 99th element in the list is " << l->get(99) << endl;

    delete l;
    return 0;
}
