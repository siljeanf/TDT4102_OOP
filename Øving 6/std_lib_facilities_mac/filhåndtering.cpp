//
//  filhåndtering.cpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 15/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "filhåndtering.hpp"

void countchar( string filnavn ) {
    
    vector <int> counter(26,0);
    string ord;
    
    ifstream filen{filnavn}; //åpner filen iname
    if (!filen) error("kan ikke åpne filen", filnavn);
    
    while (filen >> ord) {
        for (char i: ord) {
            i = tolower(i);
            if (i<= 'z' and i>= 'a'){
                counter[i-'a']++;
            }
        }
    }
    int j = 0;
    for (int i: counter) {
        char bokstav = 'a' + j;
        j++;
        cout << bokstav << "\t" << i << "\n";
    }
}

// legg til et kurs med emnekode og emnenavn i mappen CourseMap
void CourseCatalog::addCourse (string emnekode, string emnenavn) {
    //legger til verdier i en map med funksjonen insert:
    //CourseMap.insert( pair<string,string> ("TDT4110","Informasjonsteknologi grunnkurs") );
    //CourseMap.insert( pair<string, string> ("TDT4102", "Prosedyre- og objektorientert programmering") );
    //CourseMap.insert( pair<string, string> ("TMA4100", "Matematikk 1") );
    CourseMap[emnekode]= emnenavn;
}


//fjern et kurs gitt av emnekoden.
void CourseCatalog::removeCourse(string emnekode) {
    CourseMap.erase(emnekode); }

//finn emnenavnet til et kurs med en gitt emnekode.
string CourseCatalog::getCourse(string emnekode) {
    return CourseMap[emnekode]; }



void CourseCatalog::downloadFile(string filnavn){
    ofstream fil{filnavn}; //oppretter en fil
 
    //skal lagre informasjonen fra map til tekstfil
    for (auto pair : CourseMap) {
        
        fil << pair.first << ':' << pair.second << '\n';
    }
    fil.close();
}

void CourseCatalog::uploadFile(string filnavn) {
    //skal laste inn informasjonen fra en tekstfil
    
    ifstream fil{filnavn}; //åpner filen
 
    if (!fil) error("kan ikke åpne filen", filnavn);
    
    string line;
    string emnekode;
    string emnenavn;
    
while(getline(fil, line)){
        //getline går gjennom hver linje i en fil og returnerer 0 når den ikke har flere linjer i filen å gå gjennom
    stringstream ss(line); //gjør stringen til en stringstream
        
    getline(ss,emnekode, ':'); //leser en linje fra ss til ':' og legger det inn i  emnekode
    getline(ss,emnenavn, '\n'); //leser en linje fra ss til linjeskift og legger det inn i emnenavn
        
        
    cout << emnekode << ':' << emnenavn << endl;
        
    //legger til i map
    CourseCatalog:: addCourse(emnekode, emnenavn);
}
    fil.close();
}


//operator
ostream& operator<< (ostream& os, const CourseCatalog& c) {
    // c = getCourse("TDT4102");
    
    for(auto iter:c.CourseMap){
        os << iter.first << ": " << iter.second << "\n";
    }
    return os;
    
};



