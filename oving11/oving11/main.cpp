//
//  main.cpp
//  oving11
//
//  Created by Silje Anfindsen on 23/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#include <iostream>
#include "iteratorer.hpp"
#include "Person.hpp"
#include "Templates.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {

    vector<string> vec{"Lorem", "ipsum", "dolor", "sit", "Amet", "Consectetur"};
    set<string> s{ "hei","aa", "ok", "hade"};
    reverseIterator(vec);
    iteratorVec(vec);
    
    iteratorSet(s); //set skriver ut alfabetisk
    reverseIteratorSet(s);
    
    replaceVec(vec,"Lorem", "Latin");
    iteratorVec(vec);
    replaceSet(s, "hei", "hallo");
    iteratorSet(s);
    
    Person p{"Silje", "Anfindsen"};
    //cout << p;
    
    Person p1{"Anna", "Hansen"};
    Person p2{"Justin", "Bieber"};
    Person p3{"Annelen", "Schmidt"};
    
    list <Person> plist{p,p1,p2};
    p1.insertOrdered(plist, p3);
    
    for ( auto i:plist){
        cout << i;
    }

    int b = 2;
    int c = 1;
    cout <<maximum(b,c)<< endl;
    
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    vector<int> a{1, 2, 3, 4, 5, 6, 7};
    shuffle(a); // Resultat, rekkefølgen i a er endret.
    
    for ( auto& i : a) {
        cout << i << " ";
    }
    cout << endl;
}
