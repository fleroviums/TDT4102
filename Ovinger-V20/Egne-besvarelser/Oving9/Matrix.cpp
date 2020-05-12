#include "Matrix.h"
// BEGIN KONSTRUKTØRER & DESTRUKTØRER ___________________________________________________
Matrix::Matrix(){ //Default/ulovlig matrise
    matrix = nullptr;
    rows = 0;
    columns = 0;
}
Matrix::Matrix(int nRows, int nColumns){
    rows = nRows; //Brukes bl.a til destruktøren så er nice å ha:)
    columns = nColumns;
    //fyller med 0
    matrix = new double*[nRows]; //Allkokerer rader først og for hver rad allkoerer ant. kolonner
    for(int i=0;i<nRows;++i){
        matrix[i] = new double[nColumns];
        for(int j=0;j<nColumns;++j){
            matrix[i][j] = 0; //Fyller hvert matriseelem med 0
        }
    }

}
Matrix::Matrix(int nRows) : Matrix(nRows, nRows){ //Går det fint å ikke skrive explicit i cpp når den er deklarert med det i h?
    //Hvis jeg har forstått delegerende constructor, har jeg allerede allkoert og satt matrix som 0-matrise nå.
    //Går nå gjennom på nytt og fyller med 1 langs diagonalen
    for(int i=0;i<nRows;++i){
        matrix[i][i] = 1; //[i][i] blir diag.elementer
    }
}
Matrix::~Matrix(){
    for(int c=0;c<columns;++c){
        delete[] matrix[c]; // Sletter arraywise ([]) for hver column
    }
    //Destruktøren vil ikke slette noe i matrix hvis matrix er ugyldig matrise (Matrix()). Tenker det går fint siden vi ikke allkoerte noe minne i default constructor
}
Matrix::Matrix(const Matrix & rhs) : matrix{nullptr}
{
    this->rows = rhs.rows; //Kopier radtall
    this->columns = rhs.columns; //Koper kolonnetall
    this->matrix = new double*[rhs.rows]; // {}?
    for (int i =0;i<this->rows;++i){
        matrix[i] = new double[this->columns]; //{0}?
        for(int j=0;j<this->columns;++j){
            this->matrix[i][j] = rhs.matrix[i][j];
        }
    }
}
// END KONSTRUKTØRER & DESTRUKTØRER ___________________________________________________
// BEGIN GET & SET ___________________________________________________

double Matrix::get(int row, int col) const{
    return matrix[row][col];
}
void Matrix::set(int row, int col, double value){
    matrix[row][col] = value;
}
int Matrix::getRows() const{
    return rows;
}
int Matrix::getColumns() const{
    return columns;
}
// END GET & SET ___________________________________________________


// Sjekker om gyldig matrise
bool Matrix::isValid(){
    if (matrix==nullptr){
        return false;
    }
    else{
        return true;
    }
    //Forsøkte: return !*matrix;
    //Men ble feil siden nullptr ikke peker på 0 tenker jeg
}

// BEGIN OPERATOR OVERLOAD ___________________________________________________
ostream& operator<<(ostream& os, Matrix& m){
    if(!m.isValid()){
        os << "Invalid matrix \n";
    }
    else{
        for(int r=0;r<m.getRows();++r){
            for(int c=0;c<m.getColumns();++c){
                os << m.get(r,c) << '\t'; //Each elem in row r
            }
            os << '\n'; //Newline foreach row
        }
    }
    return os;
}
Matrix & Matrix::operator=(Matrix rhs) {
    swap(rows, rhs.rows);
    swap(columns, rhs.columns);
    swap(matrix, rhs.matrix);
    return *this;
}
Matrix & Matrix::operator+=( Matrix& rhs){
    if (this->isValid() && rhs.isValid() && this->rows == rhs.rows && this->columns == rhs.columns){
        for (int i=0;i<rows;++i){ //Kjører bare hvis matrisene er i samme dimensjon
            for(int j=0;j<columns;++j){
                this->matrix[i][j]+=rhs.get(i,j);
            }
        }
    }
    else{
        this->matrix = nullptr;
    }
    return *this;
}
Matrix operator+(Matrix lhs, Matrix& rhs){ //Usikker på om rhs bør være cbr(&), ble feil når lhs også var det
    lhs += rhs;
    return lhs;
}
