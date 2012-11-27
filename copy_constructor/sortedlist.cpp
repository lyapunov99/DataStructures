
#include "sortedlist.h"


SortedList::SortedList()
{
	head = NULL;
}


void SortedList::removeIth(int i)
{
	int count = 0;
	Node* iter = head;
	Node* toBeDeleted;
	while (count < i-1 && iter!=NULL) 
	{
		iter = iter->next;
		count++;
	}
	if(iter !=NULL)
	{
		toBeDeleted = iter->next;
		if (toBeDeleted!=NULL) 
		{
			iter->next = toBeDeleted->next;
			delete toBeDeleted;
		}
	}
	
}
int SortedList::removeMin()
{
	Node* temp = head;
	int v = temp->data;
	head = head->next;
	delete temp;
	return v;
	
}

int SortedList::removeMax()
{
	Node* iter1 = head;
	
	//notice that this requires that
	//head not be NULL
	Node* iter2 = head->next;
	
	int answer;
	while (iter2->next!=NULL) {
		iter1 = iter1->next;
		iter2 = iter2->next;
	}
	answer = iter2->data;
	iter1->next = NULL;
	delete iter2;
	return answer;
	
}

void SortedList::print()
{
	Node* iterator = head;
	while(iterator != NULL)
	{
		cout << iterator->data << " ";
		iterator = iterator->next;
	}
	cout << endl;
}

bool SortedList::isEmpty()
{
	if(head == NULL)
	{
		return true;
	}
	
	else
	{
		return false;

	}
}


SortedList::~SortedList()
{
	Node* badNode = head;
	while(head != NULL)
	{
		head = head->next;
		delete badNode;
		badNode = head;
	}
	
}

void SortedList::insert(int v)
{

	Node* iter = head;
	
	Node* toBeInserted = new Node;
	toBeInserted->data = v;
	toBeInserted->next = NULL;
	
	if(head == NULL)
	{
		head = toBeInserted;
	}
	
	else if( v < head->data ) {
		toBeInserted->next = head;
		head = toBeInserted;
	}
	
	else 
	{
		while (iter->next!=NULL && iter->next->data < v) 
		{
			iter = iter->next;
		}
		
		//iter now points to the node before the insert
		toBeInserted->next = iter->next;
		iter->next = toBeInserted;
	}
	
}




//copy constrcutor
SortedList::SortedList(SortedList &rhs)
{
	//need to do everthing piece by piece
	
	//start with head as NULL just in case
	//rhs is empty
	head = NULL;
	Node* tail = head;
	Node* iterRHS = rhs.head;
	
	//Only copy if the rhs is not empty
	
	if(iterRHS != NULL)
	{
		//copy the first node
		
		head = new Node;
		head->data = iterRHS->data;
		head->next = NULL;
		
		//add to the end
		tail = head;
		
		//iterate to next to copy from RHS
		iterRHS = iterRHS->next;	
		
		while (iterRHS != NULL) 
		{
			tail->next = new Node;
			tail = tail->next;
			tail->data = iterRHS->data;
			tail->next = NULL;
			iterRHS = iterRHS->next;
			
		}
		tail->next = NULL;		
	}
	
	
}

//=operator overload
const SortedList& SortedList::operator=(const SortedList &rhs)
{
	
	//check to make sure that you don't overwrite yourself
	//with yourself...just in case someone does list1 = list1;
	
	if (this != &rhs) 
	{
	
		//first need to destroy the list if you have
		//one
		
		Node* badNode = head;
		while(head != NULL)
		{
			head = head->next;
			delete badNode;
			badNode = head;
		}
	
		
		
		
		//need to do everthing piece by piece
		//same as the copy constructor
	
	
		Node* tail = head;
		Node* iterRHS = rhs.head;
	
		//Only copy if the rhs is not empty
	
		if(iterRHS != NULL)
		{
			//copy the first node
		
			head = new Node;
			head->data = iterRHS->data;
			head->next = NULL;
		
			//add to the end
			tail = head;
		
			//iterate to next to copy from RHS
			iterRHS = iterRHS->next;	
		
			while (iterRHS != NULL) 
			{
				tail->next = new Node;
				tail = tail->next;
				tail->data = iterRHS->data;
				tail->next = NULL;
				iterRHS = iterRHS->next;
			}
			
			tail->next = NULL;		
		}
	
		//same as before except
	}
	
	return *this;
	//this is a pointer to yourself

}





