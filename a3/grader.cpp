//
//  grader.cpp
//
//  Created by Ming Chow on 10/31/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sys/time.h>
#include "Airplane.h"
#include "AirplaneLine.h"

using namespace std;

int main (int argc, const char * argv[])
{
    if (argc < 2) {
        cout << "activity.log file is needed" << endl;
        return 1;
    }
    ifstream infile;    
    infile.open(argv[1]);
    if (infile.good()) {
        int maxBucks = 0;
        int bucks = 0;
        double elapsed = 0;
        int numPlanes = 0;
        bool janet = false;
        bool empty = false;
        timeval start, end;
	gettimeofday(&start, NULL);
        AirplaneLine departing;
        AirplaneLine arriving;
	gettimeofday(&end, NULL);
	elapsed += (end.tv_sec - start.tv_sec) * 1000.0;
	elapsed += (end.tv_usec - start.tv_usec) / 1000.0;
        string flightNum, from, dest, descr;
        Airplane temp;
        int numPassengers;
        char opt;
        while (infile) {
            opt = 'X';
            flightNum = "";
            from = "";
            dest = "";
            descr = "";
            numPassengers = -1;
            empty = false;
            infile >> opt;
            switch (opt) {
                case '!':
                    infile >> flightNum >> from >> dest >> descr >> numPassengers;
                    maxBucks += numPassengers;
                    if (from == "BOS") {
                        if (descr == "JANET") {
                            janet = true;
                        }
                        gettimeofday(&start, NULL);
                        departing.enqueue(Airplane(flightNum, from, dest, descr, numPassengers));
                        gettimeofday(&end, NULL);
                        elapsed += (end.tv_sec - start.tv_sec) * 1000.0;
                        elapsed += (end.tv_usec - start.tv_usec) / 1000.0;
                    }
                    else {
                        gettimeofday(&start, NULL);
                        arriving.enqueue(Airplane(flightNum, from, dest, descr, numPassengers));
                        gettimeofday(&end, NULL);
                        elapsed += (end.tv_sec - start.tv_sec) * 1000.0;
                        elapsed += (end.tv_usec - start.tv_usec) / 1000.0;
                    }
                    numPlanes++;
                    break;
                case 'D': // Departing signal
                    gettimeofday(&start, NULL);
                    if (!departing.isEmpty()) {
                        temp = departing.dequeue();
                    }
                    gettimeofday(&end, NULL);
                    elapsed += (end.tv_sec - start.tv_sec) * 1000.0;
                    elapsed += (end.tv_usec - start.tv_usec) / 1000.0;
                    if (!empty) {
                        if (temp.getDescription() != "JANET" && janet) {
                            bucks -= 10000;
                        }
                        else if (temp.getDescription() == "JANET" && janet) {
                            janet = false;
                        }
                        else {
                            bucks += temp.getNumPassengers();
                        }
                    }
                    break;
                case 'A': // Arriving signal
                    gettimeofday(&start, NULL);
                    empty = arriving.isEmpty();
                    if (!empty) {
                        temp = arriving.dequeue();
                    }
                    gettimeofday(&end, NULL);
                    elapsed += (end.tv_sec - start.tv_sec) * 1000.0;
                    elapsed += (end.tv_usec - start.tv_usec) / 1000.0;
                    if (!empty) {
                        bucks += temp.getNumPassengers();
                    }
                    break;
            }
        }
        cout << "$" << bucks << " in " << elapsed << " milliseconds!" << endl;
    }
    else {
        cout << "Bad file!" << endl;
        return 1;
    }
    infile.close();
    return 0;
}
