//
//  Matrix.cpp
//  oving9
//
//  Created by Silje Anfindsen on 12/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#include "Matrix.hpp"

//skal sette pekeren til 0
Matrix:: Matrix() : arr{nullptr} {}


//skal lage en 0-matrise
Matrix:: Matrix(int nRows, int nColumns):M{nRows}, N{nColumns} {
    arr = new double*[nRows]; //bruker * fordi listen skal bestå av pekere
    for (int i = 0; i< nRows; ++i) {
        arr[i] = new double[nColumns];
        for (int j= 0; j<nColumns; ++j){
            arr[i][j] = 0;
        }
    }
}

Matrix:: Matrix(int nRows) : Matrix{nRows, nRows} {
    
    //går gjennom radene (horisontalt)
    for (int i = 0; i < nRows; ++i) {
            arr[i][i] = 1;
        }
}
/*
//destruktør skal slette/frigjør minne
Matrix::~Matrix() {
    for (int i = 0; i < M; i++){
        delete[] arr[i];
        arr[i] = nullptr;
    }
    delete[] arr;
    arr = nullptr;
    M = 0;
    N = 0;
}
*/

//skal hente ut verdien til ett element i matrisen uttrykt ved rad og kolonne
double Matrix::get(int row, int col) const {
    return arr[row][col];
}

//skal sette verdien til et element i matrisen
void Matrix::set(int row, int col, double value) {
    arr[row][col] = value;
}

double& Matrix::operator[] (int i) {
    return arr[i][i];
}

int Matrix::getRows() const{
    return M;
}

int Matrix::getColumns() const {
    return M;
}

bool Matrix::isValid() const {
    if (arr == nullptr) {
        return false;
    }
    else {
        return true;
    }
}
//skal skrive ut hele matrisen på en enkel måte
ostream& operator<< (ostream& os, const Matrix& m) {
    
    for (int i=0; i<m.M; ++i) {
        for (int j=0; j<m.N; ++j) {
            os << m.arr[i][j] << " ";
        }
        os << '\n';
    }
    return os;
}

//Kopikonstruktøren skal sørge for at det blir instansiert en ny matrise av samme størrelse som rhs
//og at alle verdier blir kopiert fra rhs.
//Hvis rhs er en ugyldig matrise skal selvsagt kopien også være en ugyldig matrise.
Matrix::Matrix( const Matrix& rhs)
    : M{rhs.M},N{rhs.N}, arr{nullptr}{
        
        if (!rhs.isValid() ) {return; }
        arr = new double*[M]; //allokerer minne til ny matrise
        for (int i=0; i<M; i++) {
            arr[i] = new double[N];
            for (int j=0; j<N; j++) {
                double value = rhs.get(i,j); //kopierer verdier fra rhs til this
                set(i,j, value); //setter inn kopierte verdier i this
            }
        }
    }

//ønsker å swappe pekere, og gi rhs ny verdi
Matrix &Matrix::operator=(Matrix rhs) { //viktig! ikke ta inn rhs som referanse men heller call by value
   
    swap(this->arr, rhs.arr);
    swap(this->M,rhs.M);
    swap(this->N,rhs.N);// Vi swapper pekere
    return *this; //rhs slettes og da slettes de gamle verdiene til arr automatisk
}

// operatoren skal returnere en ugyldig matrise hvis matrisen er av ulike dimensjoner
Matrix Matrix::operator +=(Matrix& rhs){
    if (N != rhs.N or M != rhs.M) {
        for (int i = 0; i < M; i++){
            delete[] arr[i];
            arr[i] = nullptr;
        delete[] arr;
        for (int j = 0; j<N; j++) {
        arr[i][j] = nullptr;
            return *this;
        }}
    else {
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                rhs.arr[i][j] += arr[i][j];
            }}
        return *this:
    }}


Matrix Matrix::operator +(Matrix& m) {
