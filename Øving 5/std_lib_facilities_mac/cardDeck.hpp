//
//  cardDeck.hpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 05/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef cardDeck_hpp
#define cardDeck_hpp

#include <stdio.h>
#include "card.hpp"

class CardDeck { //kan inneholde funksjoner
private:
    vector <Card> cards; int currentCardIndex;
    void swap(int card1, int card2); 
    
    
public:
    CardDeck(); //default konstruktør
    void print();
    void printShort();
    Card drawCard();
    void shuffle();
};

#endif /* cardDeck_hpp */
