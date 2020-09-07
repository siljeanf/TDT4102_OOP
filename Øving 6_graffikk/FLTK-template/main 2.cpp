#include "std_lib_facilities.h"
#include <sstream>
#include "filhåndtering.hpp"
#include "temperature.hpp"

// skriver til fil
void skriv_til_fil() {
    ofstream outfile;
    outfile.open("minfil");
    string s;
    cout << "Skriv noen ord til fil: (skriv 'quit' for å avslutte)\n ";
    cin >> s;
    do{
        outfile << s << endl;
        cout << "Skriv noen ord til fil: (skriv 'quit' for å avslutte)\n ";
        cin >> s;
    }while (s!= "quit");
    
    outfile.close();
}

void les_fra_fil() {
    
    string oname = "minFil.txt";
    ifstream ist{oname}; //åpner filen iname
    if (!ist){
        error("kan ikke åpne filen",oname);
    }
     
    //lager ny fil
    ofstream outfile{"kopi_fil.txt"};
    
    //leser linje for linje av åpnet, eksisterende fil
    vector <string> temps;
    string line;
    int counter = 1;
    while (getline(ist, line)) {
        string t;
        string tall;
    
        stringstream ss;
        ss << counter;
        tall = ss.str();
        t = tall + line;
        outfile << t << endl;
        counter += 1;
    }
    outfile.close();
}


int main2(){
   
    //oppgave om grunnloven
    //countchar("grunnlov.txt");
    
    
    //oppgave om emnekoder
    CourseCatalog c;
    c.addCourse("TDT4110","Informasjonsteknologi grunnkurs");
    c.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    c.addCourse("TMA4100", "Matematikk 1");
    
    //oppdaterer key med ny verdi
    c.addCourse("TDT4102", "C++");
    
    cout << c;
    
    c.downloadFile("minKatalog");
    c.uploadFile("minKatalog");
    
    
    //åpner fil
    ifstream temp_file{"temperatures.txt"}; //åpner filen
    
    Temps t;
    temp_file >> t;
    
    cout << "T max:" << t.max << endl;
    temp_file.close();
    
    
    vector <Temps> v = readTemperatures("temperatures.txt");
    cout << v.size()  << endl;
    for (Temps element : v) {
        cout << element.max << " " << element.min << endl;
    }

    return 0;

}

//v[indeks].max
