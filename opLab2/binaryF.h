#ifndef OPLAB2_BINARYF_H
#define OPLAB2_BINARYF_H

#endif //OPLAB2_BINARYF_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>

struct patient {
    std::string surname;
    std::string lastVisit;
    std::string nextVisitTime;
};

void userInputToFile(std::string fileName); //вводимо інформацію

void readFile(std::string fileName); //читаємо файл

void deletePatients(std::string fileName); //видаляємо пацієнтів, час прийому яких минув

void dividePatients(std::string fileName, std::string secondaryPatients, std::string patients); //розділяємо пацієнтів на два файли: вторинні хворі та решта