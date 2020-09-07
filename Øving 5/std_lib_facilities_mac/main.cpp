#include "std_lib_facilities.h"
#include "card.hpp"
#include "cardDeck.hpp"
#include "blackjack.hpp"

int main(){
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    /*
    Suit clubs = Suit::clubs;
    
    string s = suitToString(clubs);
    cout << s << '\n';
    
    cardStruct card;
    card.s = Suit::diamonds;
    card.r = Rank::ace;
    
    string t = toString(card);
    cout << t << '\n';
    
    string y = toStringShort(card);
    cout << y << '\n';
    
    //konstruktør
    Card c1;
    cout << c1.toString() << endl;
    Card c2{Suit::diamonds, Rank::ten};
    cout << c2.toString() << endl;
    
    
    //kaller konstruktør
    CardDeck c3;
    c3.print();
    */
    
    BlackJack b;
    b.playBlackJack();
    
    return 0;
}
