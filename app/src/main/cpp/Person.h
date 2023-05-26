//
// Created by shurik on 18.05.2023.
//

#ifndef PHONEBOOKDOMINIGAMES_PERSON_H
#define PHONEBOOKDOMINIGAMES_PERSON_H

#include <iostream>
#include "PhoneNumber.h"
#include "nlohmann/json.hpp"

struct Person {
public:
    Person(const std::string& name, const PhoneNumber& number)
        : Name(name), Number(number) {}

    std::string Name;
    PhoneNumber Number;

    bool operator<(const Person& other) {
        return this->Name < other.Name;
    }
    bool operator==(const Person& other) {
        return this->Name == other.Name && this->Number.AsNumber() == other.Number.AsNumber();
    }
};

std::ostream& operator<<(std::ostream& ostream, const Person& person);

void to_json(nlohmann::json& j, const Person& p);

#endif //PHONEBOOKDOMINIGAMES_PERSON_H

