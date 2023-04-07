#include "functions.h"

void input(int &n, Person *pers) {
    std::cout << "Enter information about person." << std::endl;
    std::string nm, sn, fn, bd;
    char continueOrNot = ' ';
    while (continueOrNot != 'N') {
        std::cout << "- - - - - - - - - - - - - - - -" << std::endl;
        std::cout << "Enter name:" << std::endl;
        std::cin >> nm;
        std::cout << "Enter surname:" << std::endl;
        std::cin >> sn;
        std::cout << "Enter fathername:" << std::endl;
        std::cin >> fn;
        std::cout << "Enter date of birth(DD-MM-YYYY):" << std::endl;
        std::cin >> bd;
        pers[n].setName(nm);
        pers[n].setSurname(sn);
        pers[n].setFatherName(fn);
        pers[n].setDateOfBirth(bd);
        std::cout << "- - - - - - - - - - - - - - - -" << std::endl;
        n++;
        std::cout << "Continue?(Y/N)" << std::endl;
        std::cin >> continueOrNot;
    }
}

void luckyDays(int &n, Person *pers) {
    std::cout << "- - - - - People who were born on lucky days - - - - -" << std::endl;
    bool found = false;
    for (int i = 0; i < n; i++) {
        int day = stoi(pers[i].getDateOfBirth().substr(0, 2));
        int month = stoi(pers[i].getDateOfBirth().substr(3, 2));
        int year = stoi(pers[i].getDateOfBirth().substr(6));
        int daySum = 0, monthSum = 0, yearSum = 0, m;
        while(day > 0) {
            m = day % 10;
            daySum += m;
            day = day / 10;
        }
        while(month > 0) {
            m = month % 10;
            monthSum += m;
            month = month / 10;
        }
        while(year > 0) {
            m = year % 10;
            yearSum += m;
            year = year / 10;
        }
        int divDay = daySum % 7;
        int divMonth = monthSum % 7;
        int divYear = yearSum % 7;
        if (divDay == divMonth && divMonth == divYear) {
            std::cout << pers[i].getName() << std::endl;
            std::cout << pers[i].getSurname() << std::endl;
            std::cout << pers[i].getFatherName() << std::endl;
            std::cout << pers[i].getDateOfBirth() << std::endl;
            std::cout << "- - - - - - - - - - - - - - - - - " << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No persons were born on lucky days." << std::endl;
    }
}