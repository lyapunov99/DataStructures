//
//  BST.h
//
//  Created by Ming Chow
//

#ifndef BST_BST_h
#define BST_BST_h

#include <iostream>

using namespace std;

struct Node {
    string word;
    Node *left;
    Node *right;
};

class BST
{

// Class invariants: number of nodes > 0; the data value of each node in the tree is...
//   ...greater than any data value in its left subtree and...
//   ...less than any data value in its right subtree.

public:
    BST();

    // Description: inserts a word into the tree
    // Precondition: word does not exist in the binary search tree
    // Postcondition: word is added to binary search tree
    void insert(string word);
    
    // Description: returns the number of the nodes in the tree (i.e., words)
    // Postcondition: returns 0 or the number of nodes in the tree
    int size();

    // Description: computes the maximum height of the tree
    // Postcondition: returns 0 if empty tree, else the maximum height of tree
    int height();

    // Description: searches for a given word in the tree, *** case insensitive ***
    // Postcondition: returns true if key in found in tree, otherwise false
    bool find (string needle);

    // Description: deletes a word from the tree, *** case insensitive ***
    // Postcondition: returns true if word is deleted, otherwise false
    bool delete (string word);

    ~BST();
    
private:
    Node *root;
};

#endif
