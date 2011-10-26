#include <iostream>
#include "CharTree.h"

using namespace std;

void appendLeft(TreeNode *ptr, char someChar);
void appendRight(TreeNode *ptr, char someChar);
TreeNode *getLeft(TreeNode *ptr);
TreeNode *getRight(TreeNode *ptr);

void appendLeft(TreeNode *ptr, char someChar)
{
    ptr->left = new TreeNode;
    ptr->left->letter = someChar;
    ptr->left->left= NULL;
    ptr->left->right = NULL;
}

void appendRight(TreeNode *ptr, char someChar)
{
    ptr->right = new TreeNode;
    ptr->right->letter = someChar;
    ptr->right->left= NULL;
    ptr->right->right = NULL;    
}

TreeNode *getLeft(TreeNode *ptr)
{
    return ptr->left;
}

TreeNode *getRight(TreeNode *ptr)
{
    return ptr->right;
}

char getLetter(TreeNode *ptr)
{
    return ptr->letter;
}

int main (int argc, const char * argv[])
{
    CharTree tree;
    
    // Build tree
    tree.buildRoot('r');
    appendRight(tree.getRoot(), 'T');
    appendLeft(tree.getRoot(), 'h');
    appendLeft(getLeft(tree.getRoot()), 'C');
    appendRight(getLeft(tree.getRoot()), 'a');
    appendRight(getRight(tree.getRoot()), 'e');
    appendLeft(getRight(getRight(tree.getRoot())), 'r');
    appendRight(getRight(getRight(tree.getRoot())), 'e');
    
    // Prints "CharTree"
    cout << getLetter(getLeft(getLeft(tree.getRoot())));
    cout << getLetter(getLeft(tree.getRoot()));
    cout << getLetter(getRight(getLeft(tree.getRoot())));
    cout << getLetter(tree.getRoot());
    cout << getLetter(getRight(tree.getRoot()));
    cout << getLetter(getLeft(getRight(getRight(tree.getRoot()))));
    cout << getLetter(getRight(getRight(getRight(tree.getRoot()))));
    cout << getLetter(getRight(getRight(tree.getRoot()))) << endl;
    
    return 0;
}
