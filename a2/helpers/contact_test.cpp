//
//  contact_test.cpp
//  Simple test program for the Contact ADT
//
//  Created by Ming Chow on 10/2/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#include <iostream>
#include "Contact.h"

using namespace std;

int main (int argc, const char * argv[])
{
    Contact *c = new Contact("Ming", "Chow", "mchow@cs.tufts.edu");
    cout << c->getFirstName() << " " << c->getLastName() << endl;
    email *addresses = c->getEmailAddresses();
    c->addEmailAddress("ming.chow@tufts.edu");
    while (addresses != NULL) {
        cout << addresses->value << endl;
        addresses = addresses->next;
    }
    delete c;
    return 0;
}
