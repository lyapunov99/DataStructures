#include <iostream>
#include "Airplane.h"

using namespace std;

int main()
{
  Airplane a = Airplane("777", "BOS", "LAS", "JetBlue", 300);
  cout << a << endl;
  return 0;
}
