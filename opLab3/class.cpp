#include "class.h"

void Person::setName(std::string str) {
    name = str;
}

void Person::setSurname(std::string str) {
    surname = str;
}

void Person::setFatherName(std::string str) {
    fatherName = str;
}

void Person::setDateOfBirth(std::string str) {
    dateOfBirth = str;
}

std::string Person::getName() {
    return name;
}

std::string Person::getSurname() {
    return surname;
}

std::string Person::getFatherName() {
    return fatherName;
}

std::string Person::getDateOfBirth() {
    return dateOfBirth;
}


