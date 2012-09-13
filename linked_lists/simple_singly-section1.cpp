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

  // Add initial element to list
  head = new Node;
  head->city = "Boston";
  head->next = NULL;

  // Adding new city to beginning of list
  Node *newNode = new Node;
  newNode->city = "Las Vegas";
  newNode->next = head;
  head = newNode;
  
  // Add new city to end of list
  head->next->next = new Node;
  head->next->next->city = "Moscow";
  head->next->next->next = NULL;

  // Add another city to the end of list
  Node *iter;
  iter = head;
  while (iter->next != NULL) {
    iter = iter->next;
  }
  iter->next = new Node;
  iter->next->city = "Tokyo";
  iter->next->next = NULL;

  // Print all the cities
  iter = head;
  while (iter != NULL) {
    cout << iter->city << " => ";
    iter = iter->next;
  }
  cout << endl;

  // Delete the entire list
  while (head != NULL) {
    iter = head->next;
    delete head;
    head = iter;
  }
  return 0;
}
