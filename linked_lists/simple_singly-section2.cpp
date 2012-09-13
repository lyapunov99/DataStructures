#include <iostream>

using namespace std;

struct Node
{
  string city;
  Node *next;
  Node *prev;
};

int main()
{
  Node *head; // pointer to the beginning of list
  head = NULL;
  
  // Add Boston to list, first element
  head = new Node;
  head->city = "Boston";
  head->next = NULL;
  head->prev = NULL;

  // Add Louisville to end of list
  Node *newNode = new Node;
  newNode->city = "Louisville";
  newNode->next = NULL;
  newNode->prev = head;
  head->next = newNode;
  /*
    Another way to write this is:
    head->next = new Node;
    head->next->city = "Louisville";
    head->next->next = NULL;
  */

  // Add new city to end of list
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new Node;
  temp->next->city = "Oslo";
  temp->next->next = NULL;

  // Add Vegas to beginning of list
  Node *newHead = new Node;
  newHead->next = head;
  newHead->city = "Las Vegas";
  head = newHead;

  // Delete Louisville
  temp = head;
  Node *temp2; // thing previous
  while (temp->city != "Louisville") {
    temp2 = temp;
    temp = temp->next;
  }
  temp2->next = temp->next;
  delete temp;

  // Print out all the cities
  temp = head;
  while (temp != NULL) {
    cout << temp->city << endl;
    temp = temp->next;
  }

  // Delete the entire list
  temp = head;
  while (head != NULL) {
    head = head->next;
    delete temp;
    temp = head;
  }
  return 0;
}
