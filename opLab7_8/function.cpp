#include "function.h"

Function::Function(double argument)
{
    x = argument;
}

double Function::calculateFunction()
{
    if (x <= 0 || x == 2) {
        throw "Спроба обчислення логарифму від від'ємного числа або від 0";
    }
    return (log(x))/(log(x-2));
}
