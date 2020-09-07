//
//  utilities.cpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 29/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "utilities.hpp"


int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
    startValue += increment; }
    return startValue;
}


void incrementByValueNumTimesRef(int &startValue, int &increment, int &numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

void swapNumbers( int &a,int &b) {
    int now = a;
    a = b;
    b = now;
}

void randomizeVector( vector <int> &vr, int n ) {
    for (int i=0; i<(n+1); ++i ){
        int tilfeldig_tall = rand() % (100+1);
        vr.push_back(tilfeldig_tall);
    }
}

void sortVector(vector <int> &A) {
    int i = 1;
    while (i < (A.size()) ) {
        int j = i;
        while ( j>0 && A[j-1] > A[j]) {
            swapNumbers(A[j], A[j-1]);
            j -= 1;
        }
        i += 1;
    }
}

int medianOfVector(vector <int> vr) {
    int lengde = vr.size();
    if (vr.size() % 2 == 0) { //partall
        return (vr[(lengde/2)+1]+vr[(lengde/2)+1] )/2;
    }else   {
        return vr[lengde/2];
    }
}

    
string randomizeString(char lower, char upper, int antall) {
    string str;

    for (int i =0; i< antall; ++i){
        char d = lower + rand() % ((upper+1) - lower); //printer ut random tall også utfor grensene
        str += d;
        //char c = lower + (n - 1) ;
        //
    }
    return str;
}

string readInputToString(char lower, char upper, int n) {
    string str="";
    char b;
    cout << "Skriv inn " << n << " bokstaver mellom " << lower << " og " << upper << ": \n" ;
    while (str.length() < n) {
        cin >>b;
        if (isalpha(b) and (lower<b<upper)) {
    // sjekker om input er alfanumeriske tegn + innenfor grenser
    // vilkårlig om vi har store eller små bokstaver
        str += toupper(b);
        }}
    return str;
}


int countChar(string str, char letter) {
    int antall = 0;
    for (int i = 0; i< str.size(); ++i){
        if (letter == str[i]) {
            antall +=1;
        }
    }return antall;
}

