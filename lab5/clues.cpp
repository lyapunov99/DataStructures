#include <iostream>
#include <list>
#include <cstdlib>


using namespace std;
const int messageSize = 5;
const char message2[] = {'c','l','u','e','s'};
const string message1[] = {"Hope", "these", "numbers", "work", "Blue"};


void initialize(list<string> &first, list<char> &second, list<int> &third, list<unsigned long> &fourth)
{
	//create 5 string links in first
	for(int i=0; i < messageSize; i++)
	{
		first.push_front(message1[rand()%5]);
	}
	
	//iterate and add linking at rand2 location
	for(int i = 0; i < messageSize; i++)
	{
		second.push_front(message2[i]);
		second.push_back(message2[i]);
	}
	
	//put random ints in the thrid list
	for(int i = 0; i < messageSize*2; i++)
	{
		third.push_front(rand()%100);
	}

	//put random longs in the last list
	for(int i = 0; i < 100; i++)
	{
		fourth.push_front( ((unsigned long) (rand()*123456789+100000000) % 9000) + 1000);
	}

}

void lottoNumber(list<string> &stringList)
{
	//Seeds a method to get tonights winning number

	//First get the size of the list, call it size
	//Second get a random location within that size

	int size = stringList.size();
	int location = rand()%size;
	list<string>::iterator itr = stringList.begin();

	while(location > 0) {
		itr++;
		location--;
	}

	//The insert function
	list<string>::iterator itr2;
	itr2 = stringList.insert(itr, "clues");
}

unsigned long search(list<string> &first, list<char> &second, list<int> &third, list<unsigned long> &fourth)
{

//Clue 1
//Search the first list (named first) for the string "clues"
//this index will refer to which character in the
//word clues we are looking for 



//Clue 2
//look for the letter found in clue 1 in the second list



//Clue 3
//find the nth number in the integer list counting from the 
//back(n is from clue 2)



//Clue 4
//The value in clue 3 refers to the location of the 
//lotto number, it is the xth largest
//number in the list. To find it sort the list and 
//iterate through it.



//finaly return the number


}


int main() {
	
	//create four lists
	list<string> stringList;
	list<char> charList;
	list<int> intList;
	list<unsigned long> longList;
	
	//use this function to initialize all of them
	initialize(stringList, charList, intList, longList);

	//create an iterator for each list
	list<string>::iterator itS;
	list<char>::iterator itC;
	list<int>::iterator itI;
	list<unsigned long>::iterator itL;
	
	//answer
	unsigned long combination;
	
	//kidnap linky
	lottoNumber(stringList);
	
	
	//PRINT THE LISTS
	
	for (itS=stringList.begin(); itS!=stringList.end(); itS++) { 
			cout << " " << *itS;
	}
	
	cout << endl;
	cout << endl;

	for (itC=charList.begin(); itC!=charList.end(); itC++) {
		cout << " " << *itC;
	}
	
	cout << endl;
	cout << endl;
	
	for (itI=intList.begin(); itI!=intList.end(); itI++) {
		cout << " " << *itI;
	}
	
	cout << endl;
	cout << endl;
	
	for (itL=longList.begin(); itL!=longList.end(); itL++) {
		cout << " " << *itL;
	}
	cout << endl;
	cout << endl;

	//here is the answer
	combination = search(stringList, charList, intList, longList);
	cout << endl;
	cout << endl;
	cout << "Play this number: " << combination << endl;

	return 0;
}
