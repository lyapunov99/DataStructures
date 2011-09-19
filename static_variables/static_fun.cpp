#include <iostream>

using namespace std;

void showstat (int curr)
{
  static int nStatic;
  nStatic += curr;
  cout << "nStatic is " << nStatic << endl;
}

// The purpose of this function is to mess or munge with the memory stack of the program
void fun()
{
  int foo[100];
  int *bar;
  for (int count = 0; count < 100; count++) {
    foo[count] = count * 8;
  }
  bar = foo;
}

int main()
{
  for (int i = 0; i < 5; i++) {
    fun();
    showstat(i);
  }
}
