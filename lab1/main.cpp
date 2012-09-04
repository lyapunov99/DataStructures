//
//  main.cpp
//  LL
//
//  Created by Ming Chow.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#include <iostream>
#include "SortedList.h"

using namespace std;

int main (int argc, const char * argv[])
{
    SortedList list;
    bool done = false;
    int entry, option;
    
    while (!done) {
        cout << "1. Insert" << endl;
        cout << "2. Remove First" << endl;
        cout << "3. Remove Last" << endl;
        cout << "4. Print" << endl;
        cout << "5. Quit" << endl;
        cin >> option;
        
        switch (option) {
            case 1:
                cout << "Enter integer:" << endl;
                cin >> entry;
                list.insert(entry);
                break;
            case 2:
                list.removeFirst();
                break;
            case 3:
                list.removeLast();
                break;
            case 4:
                list.print();
                break;
            default:
                done = true;
        }
    }
    return 0;
}

