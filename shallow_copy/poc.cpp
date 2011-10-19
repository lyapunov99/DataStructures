//
//  main.cpp
//
//  An example of the perils of shallow copying...
//
//  Created by Ming Chow on 10/19/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#include <iostream>
#include "Rando.h"

int main (int argc, const char * argv[])
{
    Rando r1 = Rando(10);
    cout << "\nOutside of block: printing r1..." << endl;
    r1.print();
    
    {
        cout << "\nIn block: copying r1 into r2..." << endl;
        Rando r2 = r1;
        cout << " Memory address of r1 is " << &r1 << endl;
        cout << " Memory address of r2 is " << &r2 << endl;
        cout << "\nIn block: printing r2..." << endl;
        r2.print();
        cout << "\nIn block: modifying number in r2..." << endl;
        r2.setValue(3, -99);
        cout << "\nIn block: printing r1, see if change to r2 takes effect in r1..." << endl;
        r1.print();
        cout << "\nIn block: exiting, going out of scope..." << endl;        
    }
    cout << "Before return..." << endl;
    return 0;
}
