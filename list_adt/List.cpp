#include "List.h"
#include <iostream>

using namespace std;

List::List()
{
    currSize = 0;
    capacity = DEFAULT_CAPACITY;
    list = new int[DEFAULT_CAPACITY];
    cout << "I fought the law... (1)" << endl;
}

List::List(int maxCapacity)
{
    currSize = 0;
    capacity = maxCapacity;
    list = new int[capacity];
    cout << "I fought the law... (2)" << endl;
}

void List::add(int elem)
{
    if (currSize < capacity) {
        list[currSize++] = elem;
    }
}

void List::print()
{
    for (int count = 0; count < currSize; count++) {
        cout << list[count] << " ";
    }
    cout << endl;
}

List::~List()
{
    delete [] list;
    cout << "...and the law won." << endl;
}
