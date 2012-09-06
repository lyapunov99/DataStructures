#include <iostream>

using namespace std;

int main()
{
  int lottery[4];
  lottery[0] = 3;
  lottery[1] = 7;
  lottery[2] = 2;
  lottery[3] = 5;
  for (int count = 0; count < 4; count++) {
    cout << "Address of lottery[" << count << "] is " << &lottery[count] << endl;
  }
  int *copyOfLottery = lottery;
  cout << endl;
  cout << "&copyOfLottery is " << copyOfLottery << endl;
  cout << endl;
  cout << "The content inside the 3rd slot of copyOfLottery is " << *(copyOfLottery + 3) << endl;
  cout << "The content inside the 2nd slot of copyOfLottery is " << *(copyOfLottery + 2) << endl;
  cout << "The content inside the 1st slot of copyOfLottery is " << *(copyOfLottery + 1) << endl;
  return 0;
}
