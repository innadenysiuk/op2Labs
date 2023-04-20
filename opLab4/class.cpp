#include "class.h"

Polynomial::Polynomial() {
    coef[0] = 1;
    coef[1] = 2;
    coef[2] = 3;
    coef[3] = 4;
}

Polynomial::Polynomial(double a, double b, double c, double d) {
    coef[0] = a;
    coef[1] = b;
    coef[2] = c;
    coef[3] = d;
}

Polynomial::Polynomial(const Polynomial& p) {
    this->coef[0] = p.coef[0];
    this->coef[1] = p.coef[1];
    this->coef[2] = p.coef[2];
    this->coef[3] = p.coef[3];
}

double Polynomial::getCoef(int i) {
    return coef[i];
}

double Polynomial::calculateAtPoint(double x) {
    double result;
    result = this->coef[0] * pow(x, 3) + this->coef[1] * pow(x, 2) + this->coef[2] * x + this->coef[3];
    return result;
}

Polynomial Polynomial:: operator+(const Polynomial &p) const {
    Polynomial result;
    for (int i = 0; i < 4; i++) {
        result.coef[i] = coef[i] + p.coef[i];
    }
    return result;
}

Polynomial Polynomial:: operator*(const Polynomial &p) const {
    Polynomial result;
    for (int i = 0; i < 4; i++) {
        result.coef[i] = coef[i] * p.coef[i];
    }
    return result;
}
