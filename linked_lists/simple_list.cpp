#include <iostream>

using namespace std;

struct Node
{
  string destination;
  Node *next;
};

int main()
{
  Node *head = new Node;
  head->destination = "New York City";
  head->next = NULL;
  
  // Insert a node at head
  Node *nn = new Node;
  nn->destination = "Boston";
  nn->next = head;
  head = nn;

  // Insert a node in the middle of list
  Node *middle = new Node;
  middle->destination = "Hartford";
  middle->next = NULL;
  Node *visitor = head; // we'll keep this pointer variable for traversal purposes
  bool found = false;
  while (!found && visitor != NULL) {
    if (visitor->destination == "Boston") {
      middle->next = visitor->next;
      visitor->next = middle;
      found = true;
    }
    else {
      visitor = visitor->next;
    }
  }

  // Traversing list
  visitor = head;
  while (visitor != NULL) {
    cout << visitor->destination << endl;
    visitor = visitor->next;
  }

  // Delete entire list
  delete visitor;
  while (head != NULL) {
    Node *dump = head;
    head = head->next;
    delete dump;
  }
  return 0;
}
