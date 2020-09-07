#include "std_lib_facilities.h"
#include "cmath"

void inputAndPrintInteger(){
    int x = 0;
    
    cout << "skriv inn et tall: \n";
    cin >> x;
    cout << "du skrev:" << x << '\n';
}

int inputInteger() {
    int y = 0;
    cout << "skriv inn et tall: \n";
    cin >> y;
    return y;
}

void inputIntegersAndPrintSum() {
    int x = inputInteger();
    int y = inputInteger();
    int s = x + y;
    cout << "Summen av tallene:" << s << '\n';
}
// inputInteger returner tall slik at det er enklere å hente ut brukerens input

bool isOdd(int n) {
    bool status = true;
        if (n % 2 != 0) {
            return status;
        }
        else {
            status = false;
            return status;
        }
}

void printHumanReadableTime (float sek) {
    int h = sek/(3600);
    int min = (sek/60) - (h*60);
    int s = sek - (h*3600) - (min*60);
    cout << h << "timer," << min << "minutter," << s << "sek. \n";
    
}

void inputIntegerUsingLoopAndPrintSum () {
    int sum = 0;
    int tall = 1;
    while (tall != 0) {
        cout << "Skriv inn et tall: (skriv 0 for å avslutte)";
        cin >> tall;
        sum +=tall;
    }
    cout << "Summen av tallene er:" << sum << '\n' ;
}

// metoden der man skriver 0 for å abslutte bruker while løkke, mens metoden der bruker først angir antall tall og deretter hvilke tall bruker for-løkke.


double inputDouble() {
    double x = 0.0;
    cout << "skriv inn et desimaltall:";
    cin >> x;
    return x;
}

void NOKTilEuro() {
    float NOK = 0;
    float kurs = 9.75;
    while (NOK <= 0) {
        NOK = inputDouble();
    }
    float E = 0;
    E = NOK/kurs;
    cout << NOK << "kr" << "=" << setprecision(2) << E << "€ \n" ;
}
//ønsker å bruke desimaltall for mer nøyaktid oversettelse fra NOK til euro.
//returtypen er void ettersom funksjonen skriver ut en streng.

void gangetabell () {
    int b = b;
    int h = h;
    cout << "Skriv bredden på gangetabellen:";
    cin >> b;
    cout << "skriv lengden på gangetabellen:";
    cin >> h;
    for (int i = 1; i<=h; ++i){
        for (int k = 1; k<=b; ++k){
            cout << i*k << " ";
        }
        cout << '\n';
    }
}

double discriminant(double a,double b,double c) {
    double produkt = (pow(b,2))- (4*a*c);
    return produkt;
}

void printRealRoots (double a,double b,double c) {
    double rot = discriminant (a, b, c);
    if (rot == 0) {
        double x = -b/(2*a);
        vector<double> reelleRøtter(1);
        reelleRøtter[0] = x;
        cout << x <<'\n';
    }
    else if (rot > 0) {
        double x_1 = (-b+sqrt(rot))/(2*a);
        double x_2 = (-b-sqrt(rot))/(2*a);
        cout << "løsningene er:" << x_1 << " og " << x_2 << '\n';
    }
    else {
        cout << "ingen løsning \n";
    }
}

void solveQuadraticEquation() {
    double a = 0;
    double b = 0;
    double c = 0;
    cout << "Skriv inn tre tall i andregradsuttrykket ax^2 + bx + c: \n";
    cout << "a=";
    cin >> a;
    cout << "\n b=";
    cin >> b;
    cout << "\n c=";
    cin >> c;
    return printRealRoots(a, b, c);
}

vector<int> calculateSeries(int lån, int rente, int år) {
    vector<int> innbetalinger (år);
    double gjenstående_lån = lån;
    for (int i=0 ; i>=år; ++i) {
        double avdrag = (lån/(år)) + (rente/100)* (gjenstående_lån);
        innbetalinger[i] = avdrag;
        gjenstående_lån -= lån - (avdrag/år);
    }
    return innbetalinger;
}

 vector<int> calculateAnnuity(int år, int rente, int lån) {
     vector <int> liste(år);
     for (int i=1; i<år; ++i) {
         int innbetaling = lån*(rente/100)/(1- pow(1+(rente/100)) , (-år));
         liste[i] = innbetaling;}
     return liste;
}

void PrintAvdrag() {
    cout << "skriv inn lånet:";
    double lån = 0.0;
    cin >> lån;
    cout << "\nskriv inn antall år du ønsker å betale lånet ned på: ";
    int år = 0;
    cin >> år;
    cout << "\nskriv inn renten:";
    double rente = 0.0;
    cin >> rente;
    
    cout << "År " << "Annuitet " << "Serie " << "Differanse \n";
    for (int i=0; i<år; ++i) {
        double annuitet = calculateAnnuity (år,rente,lån)[i];
        double serie = calculateSeries (år,rente,lån)[i];
        double diff = annuitet - serie;
        cout << år << annuitet << serie << diff << '\n';
    }
}

int main() {
    int svar = -1;
    while (svar != 0) {
        cout << "Velg funksjon: \n" << "0) Avslutt \n" << "1) Summer to tall \n " << "2) Summer flere tall \n " << "3) Konverter NOK til Euro \n" << "4) Gangetabell \n" << "5) Andregradsuttrykk \n" << "6) lån \n" << "Angi valg (0-6):" ;
        cin >> svar;
        switch (svar) {
            case 0:
                cout << "finito\n";
                break;
            case 1:
                inputIntegersAndPrintSum();
                cout << '\n';
                break;
            case 2:
                inputIntegerUsingLoopAndPrintSum ();
                cout << '\n';
                break;
            case 3:
                NOKTilEuro();
                cout << '\n';
                break;
            case 4:
                gangetabell();
                cout << '\n';
                break;
            case 5:
                solveQuadraticEquation();
                cout << '\n' ;
                break;
            case 6:
                PrintAvdrag();
                break;
           default:
                cout << "ugyldig valg\n";
        }
    }
}








