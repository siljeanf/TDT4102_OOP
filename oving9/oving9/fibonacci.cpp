//
//  fibonacci.cpp
//  oving9
//
//  Created by Silje Anfindsen on 12/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#include "fibonacci.hpp"

void fillInFibonacciNumbers(int result[], int length) {

    result[0] = 0;
    result[1] = 1;
    for(int i = 2; i < length; i++) {
        int temp1 = result[i-2]; //henter de to forrige element i rekka
        int temp2 = result[i-1];
        result[i] = temp1 + temp2;
    }
}

void printArray(int arr[], int length) {
    
    for (int i=0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void createFibonacci() {
    int length;
    std::cout << "angi hvor mange til som skal genereres: ";
    std::cin >> length;
    
    int *arr = new int[length] {};
    fillInFibonacciNumbers(arr, length);
    
    printArray(arr, length);
    
    //frigjør minnet
    delete[] arr;
    arr = nullptr;
    
    // 1. Spør brukeren hvor mange tall som skal genereres
    // 2. Alloker minne til en tabell som er stor nok til tallrekka
    // 3. Fylle tabellen med fillInFibonacciNumbers()
    // 4. Skriv ut resultatet til skjerm med printArray()
    // 5. Frigjør minnet du har reservert
}

