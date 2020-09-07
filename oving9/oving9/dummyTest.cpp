//
//  dummyTest.cpp
//  oving9
//
//  Created by Silje Anfindsen on 12/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#include "dummyTest.hpp"

using namespace std;


void Dummy::dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    cout << "a:" << *a.num << endl;
    cout << "b:" << *b.num << endl;
    cout << "c:" << *c.num << endl;
    
    *b.num = 3;
    *c.num = 5;
    cout << "a:" << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;
    //cin.get();
    // For å hindre at
    // programmet avslutter med en gang
}

//kopikonstruktør
Dummy::Dummy(const Dummy &d) : num{ nullptr } {
    this->num = new int{};
    *num = *d.num;
}

//operator for =
Dummy &Dummy::operator=(Dummy d) {
    // Vi tar inn d som call-by-value
    std::swap(num, d.num);
    // Vi swapper pekere
    return *this;
}
