#ifndef OPLAB4_CLASS_H
#define OPLAB4_CLASS_H

#include <iostream>
#include <cmath>

class Polynomial {
    double coef[4];
public:
    Polynomial();                                       //конструктори
    Polynomial(double a, double b, double c, double d);
    Polynomial(const Polynomial& p);

    double getCoef(int i);       //гетер

    double calculateAtPoint(double x);       //для обчислення значення в точці

    Polynomial operator+(const Polynomial &p) const;      //перевантажений оператор '+'
    Polynomial operator*(const Polynomial &p) const;      //перевантажений оператор '*'
};

#endif //OPLAB4_CLASS_H
