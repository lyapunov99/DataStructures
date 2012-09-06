#include <iostream>
#include "List.h"

using namespace std;

int main(int argc, const char * argv[])
{
    List l;
    
    l.add(5);
    l.add(9);
    l.add(34);
    l.print();
    return 0;
}
