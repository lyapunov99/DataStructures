//
//  List.cpp
//  List
//
//  Created by Ming Chow on 5/30/12.
//  Copyright (c) 2012 Tufts University. All rights reserved.
//

#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
    cout << "Constructing list..." << endl;
    head = NULL;
}

void List::add (string str)
{
    Node *newNode;
    newNode = new Node;
    newNode->data = str;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void List::remove (int index)
{
    // To be completed
}

string List::get (int index)
{
    // To be completed
    return "TO BE COMPLETED";
}

bool List::isEmpty()
{
    if (head == NULL) {
        return true;
    }
    return false;
}

int List::size()
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void List::reverse()
{
    // To be completed    
}

bool List::contains(string str)
{
    return false;
}

void List::clear()
{
    // To be completed    
}

void List::print()
{
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

List::~List()
{
    cout << "Destructing list..." << endl;
    while (head != NULL) {
        Node *dump = head;
        head = head->next;
        delete dump;
    }
}
