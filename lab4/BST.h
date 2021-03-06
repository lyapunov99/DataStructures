#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>


using namespace std;


struct BSTNode {
		int value;
		BSTNode* left;
		BSTNode* right;
};



class BST 

{

	public:
	
	void insert(int v);
	void inOrder();
	void preOrder();
	void postOrder();
	BST();
	
	  void inOrderNonrec();
	  void preOrderNonrec();

	
	
	
private:
	
	BSTNode* root;
	
	void insert(BSTNode* &root, int v);
	
	void inOrder(BSTNode* root);
	void preOrder(BSTNode* root);
	void postOrder(BSTNode* root);	

	////////////////////////////////
	//  If you want to go
	//  further, you can write these:
	//
	     void inOrderNonrec(BSTNode* root);
	     void preOrderNonrec(BSTNode* root);
	     
        // and your own version of insert(BSTNode* &root, int v); 
	///////////////////////////////

};
	


