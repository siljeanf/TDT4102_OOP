//
//  iteratorer.hpp
//  oving11
//
//  Created by Silje Anfindsen on 23/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#ifndef iteratorer_hpp
#define iteratorer_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include <set>
#include <iterator>
//#include <utility>
#include <algorithm>


using namespace std;

void iteratorVec(vector<string> vec);
void reverseIterator(vector<string> vec);
void replaceVec(vector<string> &v, string old, string replacement);

void iteratorSet(set<string> s);
void reverseIteratorSet(set<string> s);
void replaceSet(set<string> &s, string old, string replacement);



#endif /* iteratorer_hpp */
