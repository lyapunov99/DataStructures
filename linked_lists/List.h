//
//  List.h
//  List
//
//  Created by Ming Chow on 5/30/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#ifndef List_List_h
#define List_List_h

#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node *next;
};

// Class invariant: ????

class List
{
private:
    Node *head;
public:
    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    List();

    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    void add (string str);

    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    void remove (int index);

    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    string get (int index);
    
    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    bool isEmpty();
    
    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    int size();
    
    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    void reverse();
    
    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    bool contains(string str);

    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    void clear();
    
    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    void print();
    
    // Description: ????
    // Precondition: ????
    // Postcondition: ????
    ~List();
};

#endif
