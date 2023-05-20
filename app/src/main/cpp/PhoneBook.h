//
// Created by shurik on 18.05.2023.
//

#ifndef PHONEBOOKDOMINIGAMES_PHONEBOOK_H
#define PHONEBOOKDOMINIGAMES_PHONEBOOK_H

#include <map>
#include <vector>
#include <iostream>
#include "Person.h"

class PhoneBook {
public:
    explicit PhoneBook() noexcept;

    void AddPerson(const std::string& name, const uint64_t number);
    std::vector<Person> GetPersonsByName(const std::string& name) const;
    void PrintAllItems() const;
    std::string GetFirstItem();

private:
    std::vector<Person> data;
};


#endif //PHONEBOOKDOMINIGAMES_PHONEBOOK_H
