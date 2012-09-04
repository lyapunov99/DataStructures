//
//  SortedList.cpp
//  LL
//
//  Created by Ming Chow
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#include <iostream>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    head = NULL;
}

void SortedList::insert (int v)
{
	// ????
}

void SortedList::removeFirst()
{
    Node *temp = head;
    if (temp != NULL) {
        Node *dump = temp;
        temp = temp->next;
        delete dump;
        head = temp;
    }
}

void SortedList::removeLast()
{
    Node *temp = head;
    Node *prev;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
}

bool SortedList::isEmpty()
{
    return head == NULL;
}

void SortedList::print()
{
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

SortedList::~SortedList()
{
    while (head != NULL) {
        Node *dump = head;
        head = head->next;
        delete dump;
    }
}
