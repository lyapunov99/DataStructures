#include "Dog.h"

int main(int argc, char *argv[])
{
	Dog *d = new Dog();
	d->setName("Barney");
	cout << d->bark() << endl;
	//delete d;
	return 0;
}
