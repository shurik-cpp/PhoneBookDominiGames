//
// Created by shurik on 18.05.2023.
//

#include "Person.h"

std::ostream& operator<<(std::ostream& ostream, const Person& person) {
    ostream << person.Name << "\t" << person.Number;
    return ostream;
}

using Json = nlohmann::json;
void to_json(Json& j, const Person& p) {
    j = Json{{"name", p.Name}, {"phone", p.Number.AsString()}};
}