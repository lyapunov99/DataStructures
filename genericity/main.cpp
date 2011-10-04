//
//  main.cpp
//  Genericity
//
//  Created by Ming Chow on 10/3/11.
//  Copyright 2011 Tufts University. All rights reserved.
//

#include <iostream>
#include "MyQueue.h"
#include "Airplane.h"

using namespace std;

int main (int argc, const char * argv[])
{
    MyQueue<int> q1 = MyQueue<int>();
    MyQueue<Airplane> *q2 = new MyQueue<Airplane>(7);
    MyQueue<string> *q3 = new MyQueue<string>();
    q1.enqueue(13);
    q1.enqueue(41);
    q1.enqueue(23);
    q1.enqueue(37);
    q2->enqueue(Airplane("777", "BOS", "LAS", "JetBlue", 300));
    cout << q1.dequeue() << endl;
    cout << q2->dequeue() << endl;
    q3->enqueue("Tom");
    q3->enqueue("Dick");
    q3->enqueue("Harry");
    q3->enqueue("Human Horn");
    cout << q3->dequeue() << endl;
    delete q3;
    delete q2;
    
    return 0;
}
