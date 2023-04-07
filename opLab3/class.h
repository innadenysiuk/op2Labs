#ifndef OPLAB3_CLASS_H
#define OPLAB3_CLASS_H

#endif //OPLAB3_CLASS_H

#include <iostream>

class Person {
    std::string name, surname, fatherName;
    std::string dateOfBirth;
public:
    void setName(std::string str);           //сетери класу
    void setSurname(std::string str);
    void setFatherName(std::string str);
    void setDateOfBirth(std::string str);

    std::string getName();         //гетери класу
    std::string getSurname();
    std::string getFatherName();
    std::string getDateOfBirth();
};