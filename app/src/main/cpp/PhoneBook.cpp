//
// Created by shurik on 18.05.2023.
//

#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include "PhoneBook.h"
#include "StringConverter.h"


uint64_t RandomNumber(const uint64_t min, const uint64_t max) {
    static bool doOnce = true;
    if (doOnce) {
        doOnce = false;
        // Установим начальную точку генерирования последовательности относительно time(NULL)
        srand(time(NULL));
    }
    return min + rand() % (max - min + 1);
}

const std::vector<std::string> names = {
        "Аарон",
        "Абрам",
        "Август",
        "Августа",
        "Аврора",
        "Агап",
        "Агапия",
        "Аделаида",
        "Богдан",
        "Борис",
        "Буратино",
        "Вилен",
        "Вилена",
        "Вилли",
        "Вилора",
        "Вильгельм",
        "Габриэлла",
        "Гавриил",
        "Гаврила",
        "Гай",
        "Гайдар",
        "Даниэла",
        "Дания",
        "Данна",
        "Данута",
        "Даньяр",
        "Ева",
        "Евангелина",
        "Евгений",
        "Евгения",
        "Кир",
        "Кира",
        "Кирилл",
        "Кирилла",
        "Клавдий",
        "Наталья",
        "Натан",
        "Нателла",
        "Наум",
        "Нева",
        "Павел",
        "Памела",
        "Панкрат",
        "Патрисия",
        "Станимир",
        "Станислав",
        "Станислава",
        "Стелла",
        "Степан",
        "Ульяна",
        "Умар",
        "Урсула",
        "Федор",
        "Федосей",
        "Федот",
        "Фекла"
};

PhoneBook* PhoneBook::p_book = nullptr;

PhoneBook* PhoneBook::GetInstance() {
    if (!p_book)
        p_book = new PhoneBook();
    return p_book;
}

PhoneBook::~PhoneBook() {
    if (p_book) {
        delete p_book;
        p_book = nullptr;
    }
}

PhoneBook::PhoneBook() noexcept {
    // Минимальное количество записей - 20
    const size_t numbersCount = RandomNumber(20, 100);
    for (size_t i = 0; i < numbersCount; ++i) {
        size_t randomNameIndex = RandomNumber(0, names.size() - 1);
        data.emplace_back(
                Person{
                        names[randomNameIndex],
                        RandomNumber(79000000000u, 79999999999u)
                });
    }
}

void PhoneBook::AddPerson(const std::string& name, const uint64_t number) {
    data.emplace_back(Person{name, number});
}

bool PhoneBook::IsFindedIgnoreCase(const std::string& str, const std::string& substr) const {
    std::wstring wstr = StringConverter::UtfToWstring(str);
    std::wstring wsubstr = StringConverter::UtfToWstring(substr);
    StringConverter::CyrillicToLowerCase(wstr);
    StringConverter::CyrillicToLowerCase(wsubstr);
    return wstr.find(wsubstr) != std::wstring::npos;
}

std::vector<Person> PhoneBook::GetPersonsByName(const std::string& name) const {
    std::vector<Person> result;
    for (const auto& it : data) {
        // Ищем по части имени
        if (IsFindedIgnoreCase(it.Name, name))
            result.emplace_back(it);
    }
    return result;
}

const std::vector<Person>& PhoneBook::GetAllData() const {
    return this->data;
}

void PhoneBook::PrintAllItems() const {
    for (const auto& it : data) {
        std::cout << it << std::endl;
    }
}

int PhoneBook::GetPersonsCount() {
    return data.size();
}

Person PhoneBook::GetPersonById(const size_t id) const {
    if (id > data.size() - 1 || data.empty()) {
        std::stringstream stream;
        stream << "Wrong index. Max index is: " << data.size() - 1;
        throw std::runtime_error(stream.str());
    }

    return data[id];
}