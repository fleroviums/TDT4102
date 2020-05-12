#include "Matrix.h"

Matrix::Matrix() : rows{ 0 }, columns{ 0 }, data{ nullptr } {
	// Ingenting her
}

Matrix::Matrix(int N) : Matrix{ N, N, 0.0 }
{
	for (int i = 0; i < N; ++i) {
		set(i, i, 1.0); // Identitetsmatrisen
	}
}

Matrix::Matrix(int rows, int columns, double fill)
	: rows{ rows }, columns{ columns }, data{ nullptr }
{
	// Enkeltpeker
	/*data = new double[rows*columns]; // Et langt array med plass til rows*columns elementer
	for ( int i = 0; i < rows*columns; i++) {
		data[i] = fill;
	}*/

	// Dobbeltpeker
	data = new double*[rows]; // Et array med plass til rows arrays (pekere)
	for (int i = 0; i < rows; i++) {
		data[i] = new double[columns]; // Hver rad er et array med plass til columns elementer
		for (int j = 0; j < columns; j++) {
			data[i][j] = fill;
		}
	}
}

Matrix::Matrix(const Matrix & rhs)
	: rows{ rhs.rows }, columns{ rhs.columns }, data{ nullptr }
{
	// Hvis rhs ikke er gyldig, vet vi at rhs.row og columns er 0, derfor har vi en ugyldig matrise og kan stoppe
	if (!rhs.isValid()) {
		return;
	}

	// Enkeltpeker
	/*data = new double[rows*columns];
	for ( int i = 0; i < rows*columns; ++i) {
		data[i] = rhs.data[i];
	}*/

	// Dobbeltpeker
	data = new double*[rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new double[columns];
		for (int j = 0; j < columns; j++) {
			data[i][j] = rhs.data[i][j];
		}
	}
}

Matrix::~Matrix() {
	invalidate();
}

void Matrix::invalidate() {
	// Enkeltpeker
	/*delete [] data;
	data = nullptr;*/

	// Dobbeltpeker
	for (int i = 0; i < rows; i++) {
		delete[] data[i];
		data[i] = nullptr;
	}
	delete[] data;
	data = nullptr;

	rows = 0;
	columns = 0;
}

bool Matrix::isValid() const {
	return data != nullptr;
}

Matrix & Matrix::operator=(Matrix rhs) {
	if (!rhs.isValid()) {
		this->invalidate();
		return *this;
	}

	std::swap(this->data, rhs.data);
	std::swap(this->rows, rhs.rows);
	std::swap(this->columns, rhs.columns);

	return *this;
}

Matrix & Matrix::operator +=(const Matrix & rhs) {
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		invalidate();
	}

	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			this->at(row, column) += rhs.at(row, column);
		}
	}

	return *this;
}

Matrix Matrix::operator+(const Matrix & rhs) const {
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		return Matrix{};
	}
	return Matrix{ *this } += rhs;
}

std::ostream & operator<<(std::ostream & out, const Matrix & elem) {
	if (!elem.isValid()) {
		out << "The matrix is not valid.";
	}
	else {
		for (int row = 0; row < elem.getRows(); ++row) {
			out << "| ";
			for (int column = 0; column < elem.getColumns(); ++column) {
				out << elem.get(row, column) << ' ';
			}
			out << '|' << std::endl;
		}
	}
	return out;
}

// Valgfrie oppgaver
Matrix & Matrix::operator-=(const Matrix & rhs) {
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		invalidate();
	}
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			this->at(row, column) -= rhs.at(row, column);
		}
	}

	return *this;
}

Matrix Matrix::operator-(const Matrix & rhs) const {
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		return Matrix{};
	}
	return Matrix{ *this } -= rhs;
}

Matrix Matrix::operator *(const Matrix & rhs) const {
	if (this->columns != rhs.rows) {
		return Matrix{};
	}

	Matrix temp{ this->rows, rhs.columns };
	for (int row = 0; row < this->rows; ++row) {
		for (int column = 0; column < rhs.columns; ++column) {
			temp.at(row, column) = 0.0;
			for (int i = 0; i < this->columns; ++i) {
				temp.at(row, column) += this->at(row, i) * rhs.at(i, column);
			}
		}
	}
	return temp;

}

Matrix & Matrix::operator *=(const Matrix & rhs) {
	return *this = *this * rhs;
}

Matrix Matrix::operator*(double rhs) const {
	return Matrix{ *this } *= rhs;
}

Matrix operator*(double lhs, const Matrix & rhs) {
	return rhs * lhs;
}

Matrix & Matrix::operator*=(double rhs) {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			this->at(i, j) *= rhs;
		}

	}
	return *this;
}

Matrix Matrix::operator-() const {
	if (!isValid()) {
		return Matrix{};
	}
	return *this * -1.0;
}
