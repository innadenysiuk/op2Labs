#include "matrix.h"

int main() {
    squareMatrix2 matrix2;
    squareMatrix3 matrix3;

    std::cout << "- - - SQUARE MATRIX 2 - - -" << std::endl;
    matrix2.readMatrix();
    matrix2.printMatrix();
    std::cout << "Determinant: " << matrix2.determinant() << std::endl;
    std::cout << "The sum of matrix elements: " << matrix2.sumOfElements() << std::endl;

    std::cout << "- - - SQUARE MATRIX 3 - - -" << std::endl;
    matrix3.readMatrix();
    matrix3.printMatrix();
    std::cout << "Determinant: " << matrix3.determinant() << std::endl;
    std::cout << "The sum of matrix elements: " << matrix3.sumOfElements() << std::endl;

    double S;
    S = matrix3.sumOfElements() + matrix3.determinant() + matrix2.determinant();
    std::cout << "- - - The result of the expression calculation: - - -" << std::endl;
    std::cout << S << std::endl;
    return 0;
}

