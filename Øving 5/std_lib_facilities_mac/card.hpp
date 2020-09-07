//
//  card.hpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 05/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef card_hpp
#define card_hpp

#include <stdio.h>
#include "std_lib_facilities.h"

enum class Suit { clubs, diamonds, hearts, spades};

const map < Suit, string > suitMap {
    {Suit :: clubs, "Clubs"},
    {Suit :: diamonds, "Diamonds"},
    {Suit :: hearts,  "Hearts"},
    {Suit :: spades, "Spades"}};


enum class Rank { two=2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

const map < Rank, string > rankMap {
    {Rank :: two, "Two"},
    {Rank :: three, "Three"},
    {Rank :: four, "Four"},
    {Rank :: five, "Five"},
    {Rank :: six, "Six"},
    {Rank :: seven, "Seven"},
    {Rank :: eight, "Eight"},
    {Rank :: nine, "Nine"},
    {Rank :: ten, "Ten"},
    {Rank :: jack, "Jack"},
    {Rank :: queen, "Quenn"},
    {Rank :: king, "King"},
    {Rank :: ace, "Ace"} } ;


string suitToString(Suit suit);

string rankToString( Rank rank);

struct cardStruct{Suit s; Rank r;}; //en struct er en samling av variabler

string toString (cardStruct card);

string toStringShort(cardStruct card);

class Card { //kan inneholde funksjoner
    private:
    Suit s; Rank r; bool valid;
    
    public:
    Card(); //default konstruktør
    Card(Suit suit, Rank rank); //konstruktør
    
    Suit suit(); //definerer medlemsfunksjonen suit som skal returnere kortets farge
 
    Rank rank(); //skal returnere kortets verdi
    
    bool isValid(); //skal returnere true eller 1 dersom kortet har både farge og tall
    
    string toString(); // skal returnere en string som representerer kortet evnt "ugyldig kort"
    
    string toStringShort();
};


#endif /* card_hpp */
