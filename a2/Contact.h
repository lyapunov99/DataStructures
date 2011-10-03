//
//  Contact.h
//
//  Created by Ming Chow on 10/2/11.
//  Copyright 2011 Tufts University. All rights reserved.
//


#ifndef a2_Contact_h
#define a2_Contact_h

#include <iostream>

using namespace std;

struct email {
    string value; // the e-mail address
    string description; // description for the e-mail address
    email *next;
};

struct telephone {
    string value; // the telephone number
    string description; // description for the telephone number
    telephone *next;
};

class Contact
{
    /*
        Class invariants
        - firstName and lastName are defined
        - Length of emailAddresses and telephoneNumbers >= 0
     */
public:
    // Constructors
    // Post-conditions (for all of the constructors): first name and last name are defined
    Contact(); // Post-conditions: emailAddresses and telephoneNumbers are NULL
    Contact(string firstName, string lastName); // Post-conditions: emailAddresses and telephoneNumbers are NULL
    Contact(string firstName, string lastName, string emailAddress); // Post-condition: telephoneNumbers is NULL
    Contact(string firstName, string lastName, string emailAddress, string telephoneNumber); // Post-conditions: emailAddresses and telephoneNumbers are not empty

    string getFirstName(); // Post-condition: returns first name or ""
    string getLastName(); // Post-condition: returns last name or ""
    void setFirstName(string firstName); // Precondition: firstName is defined
    void setLastName(string lastName); // Precondition: lastName is defined

    // Description: add telephone number for contact
    // Preconditions: telephoneNumbers is NULL or not empty; telephoneNumber is legitimate
    // Post-conditions: telephoneNumbers is not empty; telephone number is added to end of list
    void addTelephoneNumber(string telephoneNumber);

    // Description: remove telephone number for contact
    // Preconditions: telephoneNumbers is NULL or not empty; telephoneNumber is legitimate
    // Post-conditions: telephoneNumber may or may not be removed from telephoneNumbers (as telephoneNumber may not be found)
    void removeTelephoneNumber(string telephoneNumber);
    
    // Description: add e-mail address for contact
    // Preconditions: emailAddresses is NULL or not empty; emailAddress is legitimate
    // Post-conditions: emailAddress is not empty; e-mail address is added to end of list
    void addEmailAddress(string emailAddress);
    
    // Description: remove e-mail address for contact
    // Preconditions: emailAddresses is NULL or not empty; emailAddress is legitimate
    // Post-conditions: emailAddress may or may not be removed from emailAddresses (as emailAddress may not be found)
    void removeEmailAddress(string emailAddress);
    
    // Description: returns list of telephone numbers for contact
    // Precondition: telephoneNumbers is NULL or not empty
    // Post-condition: returns telephoneNumbers
    telephone* getTelephoneNumbers();
 
    // Description: returns list of e-mail addresses for contact
    // Precondition: emailAddresses is NULL or not empty
    // Post-condition: returns emailAddresses
    email* getEmailAddresses();
    
    // Description: deallocates emailAddresses and telephoneNumbers from memory
    // Preconditions: telephoneNumbers is NULL or not empty; emailAddresses is NULL or not empty
    // Post-conditions: telephoneNumbers and emailAddresses are deallocated from memory
    ~Contact();
private:
    string firstName;
    string lastName;
    email *emailAddresses;
    telephone *telephoneNumbers;
};

#endif
