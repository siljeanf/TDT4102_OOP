//
//  Matrix.hpp
//  oving9
//
//  Created by Silje Anfindsen on 12/03/2019.
//  Copyright © 2019 Silje Anfindsen. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <iostream>
#include <utility>
#include <array>

using namespace std;

class Matrix {

private:
    int M; //rad
    int N; //kolonne
    double **arr;

public:
    Matrix(); //default konstruktør
    Matrix(const Matrix & rhs); //kopikonstruktør
    //~Matrix(); //destruktør
    
    //medlemsfunksjoner
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getRows() const;
    int getColumns() const;
    bool isValid() const;
    
    
    //operatorer
    double& operator[](int index);
    Matrix& operator=(Matrix rhs);
    Matrix operator +=(Matrix& m);
    Matrix operator +(Matrix& m);
    friend ostream& operator<< (ostream& os, const Matrix& m);    
};

ostream& operator<< (ostream& os, const Matrix& m);

#endif /* Matrix_hpp */
