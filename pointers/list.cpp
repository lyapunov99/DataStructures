#include <iostream>

using namespace std;

int main()
{
  int *list;
  
  list = new int[10];
  list[0] = 8;
  list[1] = 8;
  list[2] = 8;
  list[3] = 1;
  cout << list[4] << endl;
  delete [] list;
  return 0;
}
