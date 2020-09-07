//
//  iteratorer.cpp
//  oving11
//
//  Created by Silje Anfindsen on 23/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#include "iteratorer.hpp"
using namespace std;


void iteratorVec(vector<string> vec) {
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void reverseIterator(vector<string> vec) {
    for (vector<string>::reverse_iterator rit = vec.rbegin(); rit!= vec.rend(); rit++ ){
        cout << *rit << " ";
    }
    cout << endl;
}

void replaceVec(vector<string> &v, string old, string replacement) {
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++){
        if (*it == old) { //*it derefererer en peker(iteratoren)
            it = v.erase(it); //erase returnerer en peker
            it = v.insert(it, replacement); //NB: it = må være med!!!
        }
    }
}

void iteratorSet(set<string> s){
    for (set<string>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    }

void reverseIteratorSet(set<string> s) {
    for (set<string>::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
}

void replaceSet(set<string> &s, string old, string replacement){
    for (set<string>::iterator it = s.begin(); it != s.end(); it++){
        if (*it == old){
            it = s.erase(it);
            it =  s.insert(it,replacement);
        }
    }
}

