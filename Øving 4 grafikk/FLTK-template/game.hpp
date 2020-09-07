//
//  game.hpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 31/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "std_lib_facilities.h"


void playMastermind();
int checkCharactersAndPosition(string guess, string code);
int checkCharacters(string guess, string code);
#endif /* game_hpp */
