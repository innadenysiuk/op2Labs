#include "functions.h"

Polynomial inputPolynomial() {
    double a, b, c, d;
    std::cout << "Введіть коефіцієнти полінома (від старшого до молодшого):\n";
    std::cin >> a >> b >> c >> d;
    return Polynomial(a, b, c, d);
}

void printPolynomial(Polynomial& p) {
    const int DEGREE = 3;
    std::cout << p.getCoef(0) << "x^" << DEGREE;
    int currentDegree = DEGREE - 1;
    for (int i = 1; i <= DEGREE; ++i) {
        const double coeff = p.getCoef(i);
        if (coeff >= 0) {
            std::cout << " + " << coeff;
        }
        else {
            std::cout << " - " << -coeff;
        }
        if (currentDegree > 1) {
            std::cout << "x^" << currentDegree;
        } else if (currentDegree == 1){
            std::cout << "x";
        }
        --currentDegree;
    }
    std::cout << std::endl;
}