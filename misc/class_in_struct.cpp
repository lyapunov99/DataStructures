#include <iostream>

using namespace std;

class Item {
public:
  Item();
  Item(string key, string value);
  void setKey(string key);
  void setValue(string value);
  string getKey();
  string getValue();
private:
  string key;
  string value;
};

Item::Item() {
  key = "DUMMY";
  value = "DUMMY";
}

Item::Item(string key, string value) {
  this->key = key;
  this->value = value;
}

void Item::setKey (string key) {
  this->key = key;
}

void Item::setValue (string value) {
  this->value = value;
}

string Item::getKey() {
  return key;
}

string Item::getValue() {
  return value;
}

struct Node {
  Item data;
  Node * next;
};

int main() {
  Node *head = new Node;
  head->data.setKey("foo");
  head->data.setValue("bar");
  cout << head->data.getKey() << endl;
  delete head;
  return 0;
}
