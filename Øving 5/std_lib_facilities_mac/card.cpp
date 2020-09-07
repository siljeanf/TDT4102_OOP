//
//  card.cpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 05/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "card.hpp"

//bruker switch istedenfor map

string suitToString(Suit suit) {
    
    return suitMap.at(suit);
}


string rankToString(Rank rank) {
    
    return rankMap.at(rank);
}

//teori
//fordeler ved å bruke symboler: mer oversiktlig og lettere å hente ut når de har indekser som er logiske

string toString (cardStruct card) {
    
    string card_type = suitToString (card.s);
    
    string card_number = rankToString(card.r);
    
    return card_number + " of " + card_type + '\n';
    
}

string toStringShort(cardStruct card) {
    
    Suit suit = card.s;
    Rank rank = card.r;
    
    string color = suitToString(suit).substr(0, 1);
    return color + to_string( static_cast<int>(rank) );
}


Card::Card(): valid {false} { //default konstruktøren skal returnere false/0
}
// :valid{0} initialiserer medlemsverdien

Card::Card(Suit suit, Rank rank): s{suit}, r{rank}, valid{true} { // konstruktøren initialiserer medlemsvariablene
}

Suit Card::suit() {
    return s;
}

Rank Card::rank() {
    return r;
}

bool Card::isValid() {
    return valid;
}

string Card::toString() {
    if (isValid() == true) {
    string card_type = suitToString (s);
    string card_number = rankToString(r);
        return card_number + " of " + card_type + '\n'; }
    else {
        return "Ugyldig kort \n";
    }
}

string Card::toStringShort() {
    string card_type = suitToString(s).substr(0, 1);
    string card_number = rankToString(r);
    
    
    if (isValid() == true) {
        return card_number + " of " + card_type + '\n'; }
    else {
        return "Ugyldig kort \n";
    }
}

// teori
// vi bruker her heller klasse en struct fordi da kan vi definere funksjonene i klassen og dermed slippe å hele tiden referere til structen, men heller bruke enkle forkortelser som er initialisert i konstruktøren



