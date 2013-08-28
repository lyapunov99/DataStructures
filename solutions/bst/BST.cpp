//
//  BST.cpp
//  BST
//
//  Created by Ming Chow on 10/30/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#include <iostream>
#include "BST.h"

using namespace std;

BST::BST()
{
    root = NULL;
}

void BST::insert(string word)
{
    if(root != NULL) {
        insert(word, root);
    }
    else {
        root = new Node;
        root->word = word;
        root->left = NULL;
        root->right = NULL;
    }
}

void BST::insert(string word, Node *ptr)
{
    if (word < ptr->word) {
        if(ptr->left != NULL) {
            insert(word, ptr->left);
        }
        else {
            ptr->left = new Node;
            ptr->left->word = word;
            ptr->left->left = NULL;
            ptr->left->right = NULL;
        }
    }
    else if (word > ptr->word) {
        if (ptr->right != NULL) {
            insert(word, ptr->right);
        }
        else {
            ptr->right = new Node;
            ptr->right->word = word;
            ptr->right->left = NULL;
            ptr->right->right = NULL;
        }
    }
}

int BST::size()
{
    return size(root);
}

int BST::size(Node *ptr)
{
    if (ptr == NULL) {
        return 0;
    }
    else {
        return 1 + size(ptr->left) + size(ptr->right);
    }
}

int BST::height()
{
    return height(root);
}

int BST::height(Node *ptr)
{
    if (ptr == NULL) {
        return 0;
    }
    else {
        unsigned int left_height = height(ptr->left);
        unsigned int right_height = height(ptr->right);
        return (left_height > right_height ? left_height : right_height) + 1;
    }
}

bool BST::find (string needle)
{
    return find(needle, root);
}

bool BST::find (string needle, Node *haystack)
{
    if (haystack == NULL) {
        return false;
    }
    /*else if (needle == haystack->word) {
        return true;
    }
    else if (needle < haystack->word) {
        return find(needle, haystack->left);
    }
    else {
        return find(needle, haystack->right);
	}*/
    find(needle, haystack->left);
}

void BST::destroyTree (Node *ptr)
{
    if (ptr != NULL) {
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
    }
}

BST::~BST()
{
    destroyTree(root);
}
