#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX_VALUE 9

int main()
{
	int *winningNums, maxNumbers, count;
	
	srand(time(NULL)); // Initialize random seed
	maxNumbers = 4;
	winningNums = new int[maxNumbers];
	for (count = 0; count < maxNumbers; count++) {
		winningNums[count] = rand() % MAX_VALUE;
		cout << winningNums[count] << " ";
	}
	cout << endl;
	delete winningNums;
	return 0;
}
