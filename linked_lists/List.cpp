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
  Node *item = new Node;
  item->data = str;
  item->next = NULL;
  if (head == NULL) { // list is empty
    head = item;
  }
  else {
    // add to end of list
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = item;
  }
}

void List::remove (int index)
{
  Node *temp = head;
  int listSize = this->size(); // why am I calling this only once?

  if (index < listSize && index >= 0) {
    if (index == 0) { // remove first element of list
      temp = head;
      head = head->next;
      delete temp;
    }
    else if (index == listSize - 1) { // remove last element of list
      for (int count = 0; count < listSize - 2; count++) {
	temp = temp->next;
      }
      delete temp->next;
      temp->next = NULL;
    }
    else { // remove element somewhere in the middle
      for (int count = 0; count < index - 1; count++) {
	temp = temp->next;
      }
      Node *dummy = temp->next;
      temp->next = temp->next->next;
      delete dummy;
    }
  }
}

string List::get (int index)
{
  Node *temp = head;
  int listSize = this->size();
  if (index < listSize && index >= 0) {
    for (int count = 0; count < index; count++) {
      temp = temp->next;
    }
    return temp->data;
  }
  return "ERROR";
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
  int size = 0;
  Node *temp = head;
  while (temp != NULL) {
    size++;
    temp = temp->next;
  }
  return size;
}

void List::reverse()
{
  // Job interview question...
}

bool List::contains(string str)
{
  Node *temp = head;
  bool found = false;
  
  while (temp != NULL && !found) {
    if (str.compare(temp->data) == 0) {
      found = true;
    }
    else {
      temp = temp->next;
    }
  }
  return found;
}

void List::clear()
{
  while (head != NULL) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
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
  cout << "Destructing list" << endl;
  while (head != NULL) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}
