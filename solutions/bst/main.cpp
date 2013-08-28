//
//  main.cpp
//  For Lab 7: Binary Search Tree (BST)
//

#include <iostream>
#include <fstream>
#include "BST.h"

using namespace std;

int main (int argc, const char * argv[])
{
  string word;
  BST bst;
  bool done = false;
  bool found = false;
  ifstream infile;
  infile.open("randomized.txt");
  while (infile) {
    infile >> word;
    if (word != "") {
      bst.insert(word);
    }
  }
  infile.close();
  /*infile.open("randomized.txt");
    
  if(infile.eof())
    {
      cout << "returning false" << endl;
      infile.close();
      return false;
    }
  else
    {
      cout << "it's open" << endl;
      while(!infile.eof())
	{
	  string toAdd;
	  infile >> toAdd;
	  //insert(toAdd);
	  cout << toAdd << endl;
	}
      infile.close();
      cout << "and closed" << endl;
      return true;
      }*/

  // The following should display "Loaded 235887 words."
  cout << "Loaded " << bst.size() << " words."<< endl; 
  cout << "Height of tree: " << bst.height() << endl;
  
  while (!done) {
    cout << "Enter word to search:" << endl;
    cin >> word;
    found = false;
    found = bst.find(word);
    if (found) {
      cout << "Word was found" << endl;
    }
    else {
      cout << "Word was not found" << endl;
    }
    cout << "Would you like to rerun this program? [Y or N]" << endl;
    cin >> word;
    if (word == "n" || word == "N") {
      done = true;
    }
  }
  return 0;
}
