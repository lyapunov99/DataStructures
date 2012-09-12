#include <iostream>
#include "dog.h"

using namespace std;

Dog::Dog()
{
	age = 0;
}

string Dog::bark()
{
	return name + " says ARF!";
}

string Dog::bark (string something)
{
	return name + " says " + something;
}

void Dog::setName (string name)
{
	this->name = name;
}

string Dog::getName()
{
	return name;
}

Dog::~Dog()
{
	cout << "Good bye cruel world!" << endl;
}
