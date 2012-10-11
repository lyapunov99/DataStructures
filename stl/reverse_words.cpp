#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
  string word;
  stack <string> list;
  int listSize = 0;
  ifstream infile("/usr/share/dict/words");
  while (infile) {
    infile >> word;
    list.push(word);
  }
  infile.close();
  listSize = list.size();
  while (!list.empty()) {
    cout << list.top() << endl;
    list.pop();
  }
  cout << "Total number of words in the file: " << listSize << endl;
  return 0;
}
