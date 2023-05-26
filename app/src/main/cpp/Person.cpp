//
// Created by shurik on 18.05.2023.
//

#include "Person.h"

std::ostream& operator<<(std::ostream& ostream, const Person& person) {
    ostream << person.Name << "\t" << person.Number;
    return ostream;
}

void to_json(nlohmann::json& j, const Person& p) {
    j = nlohmann::json{{"Name", p.Name}, {"Number", p.Number.AsString()}};
}