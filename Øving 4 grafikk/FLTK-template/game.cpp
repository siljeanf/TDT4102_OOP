//
//  game.cpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 31/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "game.hpp"
#include "tests.hpp"
#include "masterVisual.hpp"

void playMastermind() {
    
    int runde = 0;
    constexpr int win_w = 400;
    constexpr int win_h = 600;
   
    constexpr int size = 4;
    constexpr int letters = 6;
    // bruker her constexpr og ikke const fordi vi har verdien til size og letters her og nå.
    string code = randomizeString('A',( 'A' + letters-1), size);
    string guess = "";
    
    //grafikk
    MastermindWindow mwin{Point{900, 20}, win_w, win_h, "Mastermind"};
    addGuess(mwin, code, size, 'A', runde);
    mwin.wait_for_button();
    
    int riktig_gjett = checkCharactersAndPosition(guess, code);
    int antall = 0;
    int maks = 10;
    while (riktig_gjett < size and antall < maks) {
        guess = readInputToString('A', 'A' + letters-1, size);
        int riktig_b = checkCharacters(guess, code);
        riktig_gjett = checkCharactersAndPosition(guess, code);
        cout << "antall riktige bokstaver: " << riktig_b << '\n';
        cout << "antall riktige bokstaver på riktig sted: " << riktig_gjett << '\n';
        antall += 1;
        
        addGuess(mwin, guess, size, 'A', runde);
        addFeedback(mwin, riktig_gjett, riktig_b, size, runde);
        mwin.wait_for_button();
    }
    
        if (riktig_gjett == 4) {
            cout << "GRATULERER MED SEIEREN!\n";
        }
        else {
            cout << "Dessverre, du fikk ikke dette til. \n";
        }
}

//returnerer hvor mange riktige bokstaver spilleren har på hver plass
int checkCharactersAndPosition(string guess, string code) {
    int antall_riktige = 0;
    for (int i=0; i< guess.length(); ++i){
        if (guess[i] == code[i]) {
            antall_riktige += 1;
        }
    } return antall_riktige;
}

int checkCharacters(string guess, string code) {
    int antall = 0;
    for (int i = 0; i< code.length(); ++i) {
        antall += countChar(guess, code[i]);
    }
    return antall;
}
