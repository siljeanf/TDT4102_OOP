//
//  tests.cpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 29/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "tests.hpp"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations ;
}


void testVectorSorting() {
    vector <int> percentages;
    randomizeVector(percentages, 10);
    //swapNumbers(percentages[0], percentages[0]);
    sortVector(percentages);
    float median = medianOfVector(percentages);
    cout << "medianen er:" << median << '\n';
    cout << '[';
    for (int i = 0; i<10; ++i) {
        cout << percentages[i] << ',';
    }
    cout << ']' << '\n';
}

void testString() {
    double snitt = 0;
    string grades = randomizeString('A', 'F', 8);
    cout << grades << '\n';
    vector <int> gradeCount(6);

    for (int i=0; i<6; ++i) {
        gradeCount[i] = countChar(grades, ('A'+i));
        //cout << gradeCount[i] << '\n';
    }
    snitt = ( gradeCount[0]*5+gradeCount[1]*4+gradeCount[2]*3+gradeCount[3]*2+gradeCount[4*1] ) /5;
    cout << "snittet er:" << snitt << '\n';

}
