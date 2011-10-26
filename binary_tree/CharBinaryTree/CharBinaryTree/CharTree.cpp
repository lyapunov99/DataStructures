//
//  CharTree.cpp
//  CharBinaryTree
//
//  Created by Ming Chow on 10/20/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#include "CharTree.h"
#include <iostream>

using namespace std;

CharTree::CharTree()
{
    root = NULL;
}

void CharTree::buildRoot(char someChar)
{
    root = new TreeNode;
    root->letter = someChar;
    root->left = NULL;
    root->right = NULL;
}

TreeNode* CharTree::getRoot()
{
    return root;
}

bool CharTree::isEmpty()
{
    return (root == NULL);
}

CharTree::~CharTree()
{
    delete root;
}
