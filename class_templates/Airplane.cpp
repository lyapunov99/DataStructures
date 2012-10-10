//
//  Airplane.cpp
//
//  Created by Ming Chow on 9/10/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#include "Airplane.h"

Airplane::Airplane()
{
    this->flightNum = "";
    this->origin = "";
    this->destination = "";
    this->description = "";
    this->numPassengers = 0;
}

Airplane::Airplane (string flightNum,
                    string origin,
                    string destination,
                    string description,
                    int numPassengers)
{
    if (numPassengers >= 0 && origin.length() == 3 && destination.length() == 3) {
        this->flightNum = flightNum;
        this->origin = origin;
        this->destination = destination;
        this->description = description;
        this->numPassengers = numPassengers;
    }
    else {
        this->flightNum = "";
        this->origin = "";
        this->destination = "";
        this->description = "";
        this->numPassengers = 0;
    }
    this->comments = "";
}

string Airplane::getFlightNum()
{
    return flightNum;
}

string Airplane::getOrigin()
{
    return origin;
}

string Airplane::getDestination()
{
    return destination;
}

string Airplane::getDescription()
{
    return description;
}

unsigned int Airplane::getNumPassengers()
{
    return numPassengers;
}

void Airplane::setComments (string comments)
{
    this->comments = comments;
}

string Airplane::getComments()
{
    return comments;
}

ostream &operator <<(ostream &out, const Airplane &aOut)
{
    out << "Flight Number => " << aOut.flightNum << endl;
    out << "Origin => " << aOut.origin << endl;
    out << "Destination => " << aOut.destination << endl;
    out << "Description => " << aOut.description << endl;
    out << "Number of Passengers => " << aOut.numPassengers;
    return out;
}
