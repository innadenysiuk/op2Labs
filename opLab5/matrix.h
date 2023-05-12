#ifndef OPLAB5_MATRIX_H
#define OPLAB5_MATRIX_H

#include <iostream>
#include <iomanip>

class TMatrix {
protected:
    double** matrix;
    int size;
public:
    explicit TMatrix(int n);

    void readMatrix();
    void printMatrix();

    virtual double determinant() = 0;
    virtual double sumOfElements() = 0;

    virtual ~TMatrix();
};

class squareMatrix2 : public TMatrix {
public:
    squareMatrix2() : TMatrix(2) {}

    double determinant() override;
    double sumOfElements() override;
};

class squareMatrix3 : public TMatrix {
public:
    squareMatrix3() : TMatrix(3) {}

    double determinant() override;
    double sumOfElements() override;
};



#endif //OPLAB5_MATRIX_H
