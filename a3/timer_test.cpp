#include <iostream>
#include <sys/time.h> // for gettimeofday()

using namespace std;

int main()
{
    timeval start, end;
    double elapsedTime;
    string name;
    
    // Start the timer
    gettimeofday(&start, NULL);
    
    // Start of some task to be timed...
    cout << "Enter your name:"<<endl;
    cin >> name;
    
    // Stop timer
    gettimeofday(&end, NULL);
    
    // Compute and print the elapsed time in milliseconds and seconds
    elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0; // sec to ms
    elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0; // us to ms
    cout << "Hello " << name << "!" << endl;
    cout << "Elapsed time (ms): " << elapsedTime << "ms" << endl;
    cout << "Elapsed time (s): " << elapsedTime / 1000.0 << "s" << endl;
    return 0;
}
