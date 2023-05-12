#include "matrix.h"

TMatrix::TMatrix(int n) : size(n) {
    matrix = new double*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
    }
}

void TMatrix::readMatrix() {
    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void TMatrix::printMatrix() {
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(10) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double squareMatrix2::determinant() {
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

double squareMatrix2::sumOfElements() {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

double squareMatrix3::determinant() {
    double det;
    det = (matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]))) -
          (matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]))) +
          (matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1])));
    return det;
}

double squareMatrix3::sumOfElements() {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

TMatrix::~TMatrix() {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
