#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
    char *input;
    cout << "Number of arguments => " << argc << endl;
    for (int count = 0; count < argc; count++) {
        cout << "Argument " << count << " => " << argv[count] << endl;
    }
    return 0;
}
