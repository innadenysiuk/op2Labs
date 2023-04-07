#include "functions.h"

int main() {
    int n = 0;
    Person *pers = new Person[n];
    input(n, pers);
    luckyDays(n, pers);
    delete[] pers;
    return 0;
}

