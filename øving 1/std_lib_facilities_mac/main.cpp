// old_hello.cpp
#include "std_lib_facilities.h"


//a) største av to tall
int maxOfTwo(int a, int b) {

    if (a>b) {
        cout << "A is greater than B\n";
        return a;
    } else {
        cout << "B is greater than or equal to A\n";
        return b;
    }
}


//c) fibonacci ( noe feil her)
int fibonacci(int n) {
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers:\n";
    for (int x=1; x < n+1; ++x) {
        cout << x << b << "\n";
        int temp = b;
        b +=a;
        a = temp;
    }
    cout << "----";
    return b;
}
//d) sum av kvadrerte tall
int squareNumberSum(int n) {
    int totalSum = 0;
    for (int i=0; i<n; ++i) {
        totalSum += i*i ;
        cout << i*i <<'\n';
    }
    cout <<totalSum << '\n' ;
    return totalSum;
}

//e) Trekanttall
void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below" << n << ":" << 'n';
    while (acc < n) {
        cout << acc << '\n';
        acc += num;
        num += 1;
        cout << '\n';
    }
}

//primtall 1
bool isPrime(int n) {
    for (int j=2; j<n; ++j) {
        if (n%j == 0){
            return false;
        }
    }
    return true;
}

//g) primtall 2

void naivePrimeNumberSearch(int n) {
    for (int number=2; number <n; ++number) {
        if (isPrime(number)) {
            cout << number << "is a prime\n" ;
        }
    }
}

// h) største nevner mindre enn tallet selv
int findGreatestDivisor(int n) {
    for (int divisor= n-1; divisor>=0; divisor--) {
        if (n%divisor== 0) {
            return divisor;
        }
    }
    return 1;
}

//b main
int main(){
    cout << "Oppgave a)\n";
    cout << maxOfTwo(5,6) << '\n';
    cout << fibonacci(9) << '\n';
    cout << squareNumberSum(9) <<'\n';
    triangleNumbersBelow(9);
    cout <<'\n';
    cout << isPrime(11) <<'\n';
    naivePrimeNumberSearch(11);
    cout << '\n';
    cout << findGreatestDivisor(9);
}

