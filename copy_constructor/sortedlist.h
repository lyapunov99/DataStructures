
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//Here we are using ints, if we did
//a typedef, it would need to be something
//that has an ordering. If it were a user
//defined type (a class or a struct)
//it would need to have a compare
//function.

struct Node 
{
	int data;
	Node* next;
};

class SortedList
{

public:
	SortedList();
	void insert(int value);
	void removeIth(int ith);
	int removeMin();
	int removeMax();
	bool isEmpty();
	void print();
	~SortedList();
	
	//copy constructor
	SortedList(SortedList &rhs);
	
	//=operator overload
	const SortedList& operator=(const SortedList &rhs);
	
private:
	Node* head;
	
};




