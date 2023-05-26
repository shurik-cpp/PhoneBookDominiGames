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
    static PhoneBook* GetInstance();

    void AddPerson(const std::string& name, const uint64_t number);
    void AddPerson(const Person& person);
    std::vector<Person> GetPersonsByName(const std::string& name) const;
    const std::vector<Person>& GetAllData() const;
    void PrintAllItems() const;
    int GetPersonsCount();
    Person GetPersonById(const size_t id) const;

private:
    static PhoneBook* p_book;
    explicit PhoneBook() noexcept;
    ~PhoneBook();

    // TODO: Оптимизировать
    bool IsFindedIgnoreCase(std::string str, std::string substr) const;

    std::vector<Person> data;
};


#endif //PHONEBOOKDOMINIGAMES_PHONEBOOK_H
