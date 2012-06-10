//
//  Airplane.h
//
//  Created by Ming Chow on 6/10/12.
//  Copyright 2012 Tufts University. All rights reserved.
//

#ifndef a2_airplane_h
#define a2_airplane_h

#include <iostream>
#include <string>

using namespace std;

class Airplane
{
    /*
        Class invariants
        - numPassengers > 0
        - from and destination are three characters long or ""
     */
    
public:
    // The constructors
    Airplane();

    // Post-condition: Airplane is created if origin and destination are 3 letters long!
    Airplane (string flightNum,
              string origin,
              string destination,
              string description,
              int numPassengers);
    
    // Getters
    string getFlightNum(); // Post-condition: Returns the flight number or ""
    string getOrigin(); // Post-condition: Returns the origin or ""
    string getDestination(); // Post-condition: Returns the destination or ""
    string getDescription(); // Post condition: Returns the description or ""
    unsigned int getNumPassengers(); // Post-condition: Returns the number of passengers or 0

    // The comments field is free for you to use
    void setComments (string comments);
    string getComments();
 
    /*
     Displays information on airplane in the following format:
        
        Flight Number => <FLIGHT_NUM>
        Origin => <ORIGIN>
        Destination => <DESTINATION>
        Description => <DESCRIPTION>
        Number of Passengers => <NUM_PASSENGERS>
     
     */
    friend ostream &operator <<(ostream &out, const Airplane &aOut);

private:
    string flightNum;
    string origin;
    string destination;
    string description;
    int numPassengers;
    string comments;
};

#endif
