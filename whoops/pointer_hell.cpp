#include <iostream>

using namespace std;

struct email
{
  string value;
  string description;
  email *next;
};

int main()
{
  email *head;
  head->value = "therock@knowyourrole.com";
  head->next = NULL;
  return 0;
}
