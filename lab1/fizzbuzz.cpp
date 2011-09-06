// Read this gem: http://www.codinghorror.com/blog/2007/02/why-cant-programmers-program.html

#include <iostream>

using namespace std;

int main()
{
    int fizz, buzz, count;
    
    for (count = 1; count <= 100; count++) {
        fizz = count % 3; // is multiple of 3?
        buzz = count % 5; // is multiple of 5?
        if (fizz == 0 && buzz == 0) {
            cout << "FizzBuzz" << endl;
        }
        else if (fizz == 0) {
            cout << "Fizz" << endl;
        }
        else if (buzz == 0) {
            cout << "Buzz" << endl;
        }
        else {
            cout << count << endl;
        }
    }
    
    return 0;
}
