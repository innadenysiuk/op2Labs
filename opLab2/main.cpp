#include "binaryF.h"

int main() {
    std::string fileName;
    std::cout << "Enter a file name to create: " << std::endl;
    std::cin >> fileName;
    userInputToFile(fileName);
    std::cout << "- - - - - FILE - - - - -" << std::endl;
    readFile(fileName);
    deletePatients(fileName);
    std::cout << "- - - - - FILE after deleting patients - - - - -" << std::endl;
    readFile(fileName);
    std::string secondaryPatients = "secondaryPatients.dat";
    std::string patients = "patients.dat";
    dividePatients(fileName, secondaryPatients, patients);
    std::cout << "- - - - - FILE with secondary patients - - - - -" << std::endl;
    readFile(secondaryPatients);
    std::cout << "- - - - - FILE with the rest of the patients - - - - -" << std::endl;
    readFile(patients);
    return 0;
}

