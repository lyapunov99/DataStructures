//
//  SortedList.h
//  LL
//
//  Created by Ming Chow.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#ifndef LL_SortedList_h
#define LL_SortedList_h

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SortedList
{
public:
    SortedList();
    void insert (int v);
    void removeFirst();
    void removeLast();
    bool isEmpty();
    void print();
    ~SortedList();
private:
    Node *head;
};

#endif
