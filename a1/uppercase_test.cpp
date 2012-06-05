#include <iostream>
#include <algorithm>

// See details at http://stackoverflow.com/questions/313970/stl-string-to-lower-case
// The above post details transforming a string to all lowercase.  In this example, to uppercase

using namespace std;

int main()
{
  string str = "Batman";
  transform(str.begin(), str.end(),str.begin(), ::toupper);
  cout << str << endl;
  if (str.compare("Batman")) {
    cout << "No match" <<endl;
  }
  else {
    cout << "MATCH!" << endl;
  }
  if (str.compare("BATMAN")) {
    cout << "Nomatch" <<endl;
  }
  else {
    cout << "MATCH!" <<endl;
  }
  return 0;
}
