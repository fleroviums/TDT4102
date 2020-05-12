#pragma once
#include <ostream>

class Matrix {
	int rows, columns;
	// double * data; // Enkeltpeker: Langt array
	double **data;  // Dobbeltpeker: Array av array
public:

	Matrix();
	explicit Matrix(int N); // Explicit er ikke del av pensum, men vi trenger det for aa faa oppforselen vi onsker
	Matrix(int rows, int columns, double fill = 0.0);
	Matrix(const Matrix & rhs);
	~Matrix();

	Matrix & operator=(Matrix rhs);

	void invalidate();
	bool isValid() const;

	int getRows() const { return rows; }
	int getColumns() const { return columns; }

	// Merk: 0-indeksert, istedenfor 1-indeksert som i matematikken
	double & at(int row, int column) {
		return data[row][column]; // Dobbeltpeker
		// return data[row*columns + column]; // Enkeltpeker
	}

	// Merk: 0-indeksert, istedenfor 1-indeksert som i matematikken
	const double & at(int row, int column) const {
		return data[row][column]; // Dobbeltpeker
		//return data[row*columns + column]; // Enkeltpeker
	}

	// Merk: 0-indeksert, istedenfor 1-indeksert som i matematikken
	void set(int row, int column, double value) {
		at(row, column) = value;
	}

	// Merk: 0-indeksert, istedenfor 1-indeksert som i matematikken
	double get(int row, int column) const {
		return at(row, column);
	}

	// Valgfri oppgave
	double* operator[](int row) {
		//return &data[row*columns]; // Enkeltpeker
		return data[row]; // Dobbeltpeker
	}

	Matrix & operator +=(const Matrix & rhs);
	Matrix operator +(const Matrix & rhs) const;

	// Valgfrie oppgaver
	Matrix & operator -=(const Matrix & rhs);		// Binary -(minus) and assign
	Matrix operator -(const Matrix & rhs) const;	// Binary -(minus)
	Matrix operator-() const;						// Unary -(minus)

	Matrix & operator *=(const Matrix & rhs);
	Matrix operator *(const Matrix & rhs) const;
	Matrix operator*(double rhs) const;
	Matrix & operator*=(double rhs);
};

std::ostream & operator<<(std::ostream & out, const Matrix & elem);

// Valgfri oppgave
Matrix operator*(double lhs, const Matrix & rhs); // Multipliser med en double p� venstre side
