#pragma once
#include <iostream>
#include <ctime>
#include <utility>
using namespace std;

class Matrix{
    private:
        double **matrix; // Velger ** metoden her da jeg er mer komfortabel med implementasjonen:))
        int rows;
        int columns;
    public:
        Matrix(); //ulovlig matrise
        Matrix(int nRows, int nColumns);
        explicit Matrix(int nRows);
        ~Matrix(); //Destructor
        Matrix(const Matrix & rhs); // Copy-constructor
        //Get og set
        double get(int row, int col) const;
        void set(int row, int col, double value);
        int getRows() const;
        int getColumns() const;

        bool isValid();
        friend ostream& operator<<(ostream& os, Matrix& m);
        Matrix &operator=(Matrix rhs);
        Matrix &operator+=( Matrix& rhs);
        friend Matrix operator+(Matrix lhs, Matrix& rhs);


};