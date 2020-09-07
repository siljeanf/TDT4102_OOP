//
//  cardDeck.cpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 05/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "cardDeck.hpp"
#include "card.hpp"

CardDeck::CardDeck() : currentCardIndex{0} {
    for (auto pair : suitMap) {
        Suit s = pair.first;
        for (auto npair : rankMap ) {
            Rank r = npair.first;
            Card c{s, r};
            cards.push_back(c);
        }
    }
}

void CardDeck::swap(int card1, int card2) {
    Card temp = cards[card1];
    cards[card1] = cards[card2];
    cards[card2] = temp;
}


void CardDeck::print() {

    for (auto pair : cards) {
        cout << pair.toString() << endl;
    }
}

void CardDeck:: printShort() {
    for (auto pair: cards) {
        cout << pair.toStringShort();
    }
}


void CardDeck::shuffle() {
    for (int card1=0; card1<52; ++card1 ) {
        int card2 = rand() % (51+1);//random vil ta alle tall fra 0 til 51
        swap(card1, card2);
    }
}


Card CardDeck::drawCard () {
    currentCardIndex += 1;
    return cards[currentCardIndex-1];
}


