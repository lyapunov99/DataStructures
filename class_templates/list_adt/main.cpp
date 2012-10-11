#include <iostream>
#include "List.h"

using namespace std;

int main()
{
  List<string> simpleList;
  
  simpleList.push("Tom");
  simpleList.push("Dick");
  simpleList.push("Harry");
  simpleList.push("Bobo");
  cout << simpleList.get(2) << endl;
  return 0;
}
