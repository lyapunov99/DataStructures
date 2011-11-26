//
//  main.cpp
//  lab10
//
//  COMP 15: Data Structures
//  Tufts University Department of Computer Science
//

#include <iostream>
#include "Assoc.h"

using namespace std;

int main (int argc, const char * argv[])
{
    Assoc presidents;
    presidents["Monaco"] = "Anthony";
    presidents["Clinton"] = "Bill";
    presidents["Bush"] = "Dubya";
    presidents["Bacow"] = "Larry";
    cout << presidents["Clinton"] << endl;
    presidents["Clinton"] = "Sax player";
    cout << presidents["Bacow"] << endl;
    cout << presidents["Bush"] << endl;
    cout << presidents["Monaco"] << endl;
    cout << presidents["Clinton"] << endl;
    return 0;
}

