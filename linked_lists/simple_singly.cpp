#include <iostream>

using namespace std;

struct Node
{
  string city;
  Node *next;
};

int main()
{
  Node *head; // pointer to the beginning of list
  head = NULL;
  
  // Add Boston to list, first element
  head = new Node;
  head->city = "Boston";
  head->next = NULL;

  // Add Louisville to end of list
  Node *newNode = new Node;
  newNode->city = "Louisville";
  newNode->next = NULL;
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

  // Print out all the cities
  temp = head;
  while (temp != NULL) {
    cout << temp->city << endl;
    temp = temp->next;
  }

  return 0;
}
