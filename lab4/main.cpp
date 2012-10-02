#include "BST.h"

int main() {
	
	//create the tree
	BST testTree;
	testTree.insert(54);
	testTree.insert(22);
	testTree.insert(17);
	testTree.insert(41);
	testTree.insert(36);
	testTree.insert(30);
	testTree.insert(74);
	testTree.insert(76);
	testTree.insert(26);
	testTree.insert(27);
	testTree.insert(45);
	testTree.insert(82);
	
	cout << endl;
	cout << "Ricky to the rescue:" << endl;

	cout << "printing postorder: ";
	testTree.postOrder();
	cout << endl;
	cout <<"Answer:             17 27 26 30 36 45 41 22 82 76 74 54  ";
	cout << endl;

	cout << "Stacey saves the day" << endl;
	cout << "printing inorder: ";
	testTree.inOrder();
	cout << endl;
	cout<< "Answer:           17 22 26 27 30 36 41 45 54 74 76 82";
	cout << endl;
	cout << endl;

	cout << "printing preorder: ";
	testTree.preOrder();
	cout << endl;
	cout <<"Answer:            54 22 17 41 36 30 26 27 45 74 76 82";
	cout << endl;
	cout << endl;
	
	////////////////////////////////////////////
	// ----extra ----- tests
	/*

	cout << "Super Stacey's Removing Recursion" << endl;

	cout << "printing preorder: ";
	testTree.preOrderNonrec();
	cout << endl;
	cout <<"Answer:            54 22 17 41 36 30 26 27 45 74 76 82";
	cout << endl;
	cout << endl;

	cout << "printing inorder: ";
	testTree.inOrderNonrec();
	cout << endl;
	cout<< "Answer:           17 22 26 27 30 36 41 45 54 74 76 82";
	cout << endl;
	cout << endl;

	cout << "Quiet down, Quinn's in Town" << endl;
	cout << "printing levelorder: ";
	testTree.levelOrder();
	cout << endl;
	cout <<"Answer:              54 22 74 17 41 76 36 45 82 30 26 27";
	cout << endl;
	cout << endl;
	*/
	//////////////////////////////////////////////////
	
	
	return 0;
}
