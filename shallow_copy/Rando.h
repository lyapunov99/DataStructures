//
//  Rando.h
//
//  Created by Ming Chow on 10/19/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#ifndef poc_Rando_h
#define poc_Rando_h

using namespace std;

class Rando
{
public:
    Rando(int n);
    void setValue (int loc, int newVal);
    void print();
    ~Rando();
private:
    int *list;
    int size;
};

#endif
