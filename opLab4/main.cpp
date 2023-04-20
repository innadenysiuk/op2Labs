#include "functions.h"

int main() {
    Polynomial P1 = inputPolynomial();
    Polynomial P2 = Polynomial();
    Polynomial P3(P2);

    double x;
    std::cout << "Введіть точку x: ";
    std::cin >> x;

    std::cout << "P1: " << std::endl;
    printPolynomial(P1);
    std::cout << "P2: " << std::endl;
    printPolynomial(P2);
    std::cout << "P3: " << std::endl;
    printPolynomial(P3);

    Polynomial P4 = P1 + P2;
    Polynomial P5 = P2 * P3;

    std::cout << "P4: " << std::endl;
    printPolynomial(P4);
    std::cout << "P5: " << std::endl;
    printPolynomial(P5);

    std::cout << "Значення P4 в точці х: " << P4.calculateAtPoint(x)<< std::endl;
    std::cout << "Значення P5 в точці х: " << P5.calculateAtPoint(x)<< std::endl;
    return 0;
}
