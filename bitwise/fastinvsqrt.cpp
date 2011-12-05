#include <iostream>

using namespace std;

float InvSqrt (float x)
{
  float xhalf = 0.5f * x;

  int i = *(int*)&x; // get bits for floating value
  i = 0x5f3759df - (i>>1); // gives initial guess y0
  x = *(float*)&i; // convert bits back to float
  x = x * (1.5f - xhalf * x * x); // Newton step, repeating increases accuracy
  return x;
}

int main()
{
  float n = 3.0;
  float result = InvSqrt(n);
  cout << "The inverse square root of " << n << " is " << result << endl;
  return 0;
}
