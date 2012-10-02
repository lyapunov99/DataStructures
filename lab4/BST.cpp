#include "BST.h"

BST::BST()
{
	root = NULL;	
}

void BST::insert(int v)
{
	insert(root, v);
}

void BST::insert(BSTNode* &root, int v)
{
	//empty tree
	if(root == NULL) {
		root = new BSTNode;
		root->value = v;
		root->left = NULL;
		root->right = NULL;
	}
	
	else if(v < root->value) {
		insert(root->left, v);
	}
	
	else if(v > root->value) {
		insert(root->right, v);
	}
	
	else {
		cout << "Duplicate ignored" << endl;
	}
}

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


void BST::levelOrder()
{
	levelOrder(root);	
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


void BST::levelOrder(BSTNode* root)
{
	//Do this if you have time
}


