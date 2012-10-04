#include "BST.h"

BST::BST()
{
	root = NULL;	
}

void BST::insert(int v)
{
	insert(root, v);
}


// void BST::insert(BSTNode* &root, int v)
//
// Written and compiled for you in BSTinsert.o 
//

// public functions, written for you

void BST::inOrder()
{
	inOrder(root);
}

void BST::preOrder()
{
	preOrder(root);
}

void BST::postOrder()
{	
	postOrder(root);
}


void BST::inOrderNonrec()
{
	inOrderNonrec(root);
}

void BST::preOrderNonrec()
{
	preOrderNonrec(root);
}




//
// private functions:  YOU WRITE THESE
//

void BST::inOrder(BSTNode* root)
{

// YOUR CODE HERE
	
}


void BST::preOrder(BSTNode* root)
{

//YOUR CODE HERE
	
}


void BST::postOrder(BSTNode* root)
{

//YOUR CODE HERE

}


void BST::inOrderNonrec(BSTNode* root)
{
	//Do this if you have time
}


void BST::preOrderNonrec(BSTNode* root)
{
	//Do this if you have time
}




