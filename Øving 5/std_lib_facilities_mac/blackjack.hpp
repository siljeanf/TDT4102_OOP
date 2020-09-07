//
//  blackjack.hpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 08/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef blackjack_hpp
#define blackjack_hpp
#include "std_lib_facilities.h"
#include <stdio.h>
#include "cardDeck.hpp"
#include "card.hpp"


const map < Rank, int > RankIntMap {
        {Rank :: two, 2},
        {Rank :: three, 3},
        {Rank :: four, 4},
        {Rank :: five, 5},
        {Rank :: six, 6},
        {Rank :: seven, 7},
        {Rank :: eight, 8},
        {Rank :: nine, 9},
        {Rank :: ten, 10},
        {Rank :: jack, 10},
        {Rank :: queen, 10},
        {Rank :: king, 10},
        {Rank :: ace, 11}}; //ess skal være 11 eller 1


class BlackJack {
private:
    CardDeck deck; // kortstokken i hvert spill
    int cardsP = 0;
    int cardsD = 0;
    int numCardsP = 0;
    int numCardsD = 0;
    
public:
    void playBlackJack();
    int sumCardsPlayer( int rankValue);
    int sumCardsDealer (int rankValue);
    int cardValue( Card card);
    vector <int> cardsPlayer();
    vector <int> cardsDealer();
    int sumCards();
};


//Blackjack starter med å skrive ut de to første kortene til spilleren + et av delaerns kort til skjermen. Så må han gi summen av kortene og be brukeren bestemme om han vil trekke et nytt kort.
// brukeren kan trekke et nytt kort så mange ganger han vil, men så fort summen av verdien på kortene overstiger 17 så taper han.
// dealeren må ha kort med verdi 17 eller mer.

#endif /* blackjack_hpp */

//sumCardsplayer
//sumCardsDealer
//CardValue
