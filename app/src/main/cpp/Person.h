//
// Created by shurik on 18.05.2023.
//

#ifndef PHONEBOOKDOMINIGAMES_PERSON_H
#define PHONEBOOKDOMINIGAMES_PERSON_H


#include <iostream>
#include "PhoneNumber.h"

struct Person {
public:
    Person(const std::string& name, const PhoneNumber& number) : Name(name), Number(number) {}

    std::string Name;
    PhoneNumber Number;

    bool operator<(const Person& other) {
        return this->Name < other.Name;
    }
};

std::ostream& operator<<(std::ostream& ostream, const Person& person);


#endif //PHONEBOOKDOMINIGAMES_PERSON_H
