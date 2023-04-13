#include "binaryF.h"

void userInputToFile(std::string fileName) {
    patient wp;
    std::ofstream file(fileName,   std::ios::binary);
    if (!file.is_open()) {
        std::cout << "ERROR!" << std::endl;
        return;
    }
    else {
        std::string cont;
        do {
            std::cout << "Enter surname: ";
            std::cin >> wp.surname;
            std::cout << "Enter the date of last visit: ";
            std::cin >> wp.lastVisit;
            std::cout << "Enter the time of next visit: ";
            std::cin >> wp.nextVisitTime;
            file.write(reinterpret_cast<const char*>(&wp), sizeof(wp));
            std::cout << "Continue? (yes/no) : ";
            std::cin >> cont;
        } while (cont == "yes");
    }
    file.close();
}

void readFile(std::string fileName) {
    patient rp;
    std::ifstream file(fileName,   std::ios::binary);
    if (!file.is_open()) {
        std::cout << "ERROR!" << std::endl;
        return;
    }
    else {
        std::cout << "Surname\t\tLast visit\tNext visit" << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - - - - - -" << std::endl;
        while (file.read(reinterpret_cast<char*>(&rp), sizeof(rp))) {
            std::cout << rp.surname << "\t\t" << rp.lastVisit << "\t\t" << rp.nextVisitTime << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    file.close();
}

void deletePatients(std::string fileName) {
    patient dp;
    std::ifstream file(fileName,   std::ios::binary);
    if (!file.is_open()) {
        std::cout << "ERROR!" << std::endl;
        return;
    }
    std::ofstream tFile("temp.dat",   std::ios::binary);
    if (!tFile.is_open()) {
        std::cout << "ERROR!" << std::endl;
        return;
    }
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int hoursSyst = now->tm_hour;
    int minutesSyst = now->tm_min;
    while (file.read(reinterpret_cast<char*>(&dp), sizeof(dp))) {
        int hours = stoi(dp.nextVisitTime.substr(0, 2));
        int minutes = stoi(dp.nextVisitTime.substr(3, 2));
        if (hours > hoursSyst || (hours == hoursSyst && minutes > minutesSyst)) {
            tFile.write(reinterpret_cast<const char*>(&dp), sizeof(dp));
        }
    }
    file.close();
    tFile.close();
    std::remove(fileName.c_str());
    std::rename("temp.dat", fileName.c_str());
}

void dividePatients(std::string fileName, std::string secondaryPatients, std::string patients) {
    patient pp;
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "ERROR!" << std::endl;
        return;
    }
    std::ofstream vFile(secondaryPatients, std::ios::binary);
    if (!vFile.is_open()) {
        std::cout << "ERROR!" << std::endl;
        return;
    }
    std::ofstream rFile(patients, std::ios::binary);
    if (!rFile.is_open()) {
        std::cout << "ERROR!" << std::endl;
        return;
    }
    std::time_t now = std::time(nullptr);
    std::tm systDate = *std::localtime(&now);
    while (file.read(reinterpret_cast<char*>(&pp), sizeof(pp))) {
        std::tm date = {};
        std::istringstream ss(pp.lastVisit);
        ss >> std::get_time(&date, "%d.%m.%Y");
        double diff = std::difftime(std::mktime(&systDate), std::mktime(&date));
        double daysDiff = (((diff / 60) / 60) / 24);
        if (daysDiff <= 10) {
            vFile.write(reinterpret_cast<const char*>(&pp), sizeof(pp));
        }
        else {
            rFile.write(reinterpret_cast<const char*>(&pp), sizeof(pp));
        }
    }
    file.close();
    vFile.close();
    rFile.close();
}
