#include <iostream>
#include <fstream>
#include "MyStack.h"

using namespace std;

int main (int argc, const char * argv[])
{
  string word;
  ifstream infile;

  infile.open("words.txt"); // open file

  // Reading file
  while (!infile.eof()) {
    infile >> word;
    if (!infile.eof()) {
      cout << word << endl;
    }
  }
  infile.close();
}
