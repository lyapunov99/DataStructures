#include <iostream>

using namespace std;

int* foo()
{
  static int count;
  count = 18;
  cout << "Value of local variable count: " << count << endl;
  cout << "Address of local variable count: " << &count << endl;
  return &count;
}

int main()
{
  int *d;
  d = foo();
  cout << "Address of d: " << d << endl;
  cout << "Value of d: " << *d << endl;
}
