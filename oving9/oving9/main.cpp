//
//  main.cpp
//  oving9
//
//  Created by Silje Anfindsen on 11/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#include <iostream>
#include "fibonacci.hpp"
#include "Matrix.hpp"
#include "dummyTest.hpp"

int main() {
    // insert code here...
    //createFibonacci();
    Matrix m1(2,3);
    
    Matrix m2(5,5);
    cout << m2 << endl;
    
    Matrix m3{m2};
    cout << m3 << endl;
    
    Matrix m4;
    m4 = m1;
    cout << m4 << endl;
    
    cout << m2.getRows() << endl;
    
    
    //Dummy d;
    //d.dummyTest();

        
    
    return 0;
}
