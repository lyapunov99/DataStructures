//
//  CharTree.h
//  CharBinaryTree
//
//  Created by Ming Chow on 10/20/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#ifndef CharBinaryTree_CharTree_h
#define CharBinaryTree_CharTree_h

struct TreeNode
{
    char letter;
    TreeNode *left;
    TreeNode *right;
};

/*
 * Class invariant: is a tree
 */

class CharTree
{
public:
    CharTree();
    void buildRoot(char someChar);
    TreeNode* getRoot();
    bool isEmpty();
    ~CharTree();
private:
    TreeNode *root;
};
#endif
