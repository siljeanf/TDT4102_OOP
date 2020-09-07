//
//  dummyTest.hpp
//  oving9
//
//  Created by Silje Anfindsen on 12/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#ifndef dummyTest_hpp
#define dummyTest_hpp

#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;

class Dummy {
public:
    int *num;
    Dummy() {num = new int{0};}
    
    ~Dummy() {delete num;}
    
    Dummy(const Dummy &);
    
    void dummyTest();
    
    Dummy& operator=(Dummy d);
    
};




#endif /* dummyTest_hpp */
