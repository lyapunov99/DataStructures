#include <iostream>

using namespace std;

class Dog
{
	private:
		bool sex;
		string name;
		int age;
	public:
		Dog();
		string bark();
		string bark (string something);
		void setName (string name);
		string getName();
		~Dog();
};
