
//
//  blackjack.cpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 08/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "blackjack.hpp"
#include "cardDeck.hpp"
#include "card.hpp"


//henter ut og returnerer ranken til kortet som trekkes
int BlackJack::cardValue(Card card) {
    int rankValue = RankIntMap.at( card.rank() );
    return rankValue;
}

//summerer verdien og antall kort til dealer. Hvis dealeren får en ess sikrer if-setningen at kortet blir 1 om det er det lureste.
int BlackJack::sumCardsDealer(int rankValue) {
    if (cardsD + rankValue > 21 and rankValue == 11 ) {
        rankValue = 1;}
    
    cardsD += rankValue;
    numCardsD+= 1;
    return cardsD;
    }

// summerer verdien og antall kort til bruker og ber han bestemme om han vil gi ess verdien 11 eller 1.
int BlackJack::sumCardsPlayer(int rankValue){
    if (rankValue == 11){
        cout << "Du har trukket et ess. Vil du gi esset verdien 11 eller 1?\n";
        cin >> rankValue;
    }
    cardsP += rankValue;
    numCardsP += 1;
    return cardsP;
    
}
    
void BlackJack::playBlackJack() {
    
        cout << "Velkommen til Blackjack!\n";
        deck.shuffle(); // stokker kortstokken deck
        Card dealerCard = deck.drawCard(); // trekker et kort til dealeren
        sumCardsDealer(cardValue(dealerCard)); //finner verdien av kortet dealeren trekker.
        cout << "Dealerens første kort er " << dealerCard.toString() << endl;
        
        Card playerCard = deck.drawCard(); //trekker spillerens kort
        cout << "Ditt første kort er " << playerCard.toString() << endl;
        sumCardsPlayer(cardValue(playerCard));
        
        
       //delarens trekker et til kort
        dealerCard = deck.drawCard();
        sumCardsDealer(cardValue(dealerCard));
    
        //gir spilleren et nytt kort
        playerCard = deck.drawCard();
        cout << "Ditt andre kort er " << playerCard.toString() << endl;
        sumCardsPlayer(cardValue(playerCard)); //summerer kortene til spilleren
        cout << "Summen av dine kort er " << cardsP << endl;
        
        if (cardsD < 17){
            dealerCard = deck.drawCard();
            sumCardsDealer(cardValue(dealerCard));
        }
    
        string choice; //spør brukeren om han vil trekke et nytt kort
        cout << "Vil du trekke et nytt kort? Skriv inn 'ja' eller 'nei'.";
        cin >> choice;
        
// sjekker alle mulige scenariorer for at brukeren vinner eller taper overfor dealeren
// gitt at du trekker flere kort så sjekker den ulike scenariorer og sjekker om dealeren må trekke nye kort.
        while (choice == "ja"){
            playerCard = deck.drawCard();
            sumCardsPlayer(cardValue(playerCard));
            cout << "Kortet du trakk er " << playerCard.toString() << endl;
            
            // brukeren taper automatisk når kortene overstiger 21
            if (cardsP > 21){
                cout << "Du har oversteget 21. Beklager, du har tapt!\n";
                return;
            }
            
            // delaren må trekke et nytt kort dersom summen av verdien av kortene er under 17
            cout << "Summen av kortene dine er " << cardsP << endl;
            if (cardsD < 17){
                dealerCard = deck.drawCard();
                sumCardsDealer(cardValue(dealerCard));
            }
            // brukeren kan selv velge om han vil trekke et nytt kort.
            cout << "Vil du trekke et nytt kort? Skriv inn 'ja' eller 'nei'.";
            cin >> choice;
            
        } // while løkke er over
    
    
    // så lenge dealeren har verdi mindre enn 17 trekker han nye kort. Du er ferdig med å trekke kort.
    while (cardsD < 17){
            dealerCard = deck.drawCard();
            sumCardsDealer(cardValue(dealerCard));
        }
    //hvis spilleren har trukket to kort og kortene har verdien 21 samtidig som delaeren har det så taper spilleren
    if (numCardsP == 2 and cardsP == 21){
            if (numCardsD == 2 and cardsD == 21){
                cout << "Du fikk ekte blackjack, men det gjorde også dealer. Beklager, men du har tapt.\n";
                return;
            }
        // hvis dealeren ikke har blackjack, vinner spilleren
            else{
                cout << "Du fikk ekte blackjack. Gratulerer, du har vunnet!";
                return;
            }
        }
    
    // hvis spilleren har kort mindre eller lik 21 og dealeren mer enn 21 så vinner spilleren
        if (cardsP <= 21 and cardsD > 21){
            cout << "Dealer har oversteget 21, mens du er under 21. Gratulerer, du har vunnet!\n";
            return;
            
    // hvis spilleren har kort mindre eller lik 21 samtidig som dealeren har kort mindre enn spilleren eller lik spilleren så vinner spilleren.
        } if (cardsP <= 21){
            if (cardsD < cardsP or cardsD == cardsP){
                cout << "Du har oppnådd en høyere hånd enn dealeren, uten å overstige 21. Gratulerer, du har vunnet!\n";
                return;
            }else{
                cout << "Beklager, du har en lavere hånd enn dealer. Du har tapt.\n";
                return;
            }
        }
    
    // hvis spilleren overstifer 21 så taper han.
    if (cardsP > 21){
            cout << "Du har oversteget 21. Beklager, du har tapt!\n";
            return;
            
        }
        
    }

    
    


    
    
    
    

