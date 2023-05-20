//
// Created by shurik on 18.05.2023.
//

#include <sstream>
#include "PhoneBook.h"

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


PhoneBook::PhoneBook() noexcept {
    // Минимальное количество записей - 20
    const size_t numbersCount = RandomNumber(20, 100);
    for (size_t i = 0; i < numbersCount; ++i) {
        size_t randomNameIndex = RandomNumber(0, names.size() - 1);
        data.emplace_back(
                Person{
                    names[randomNameIndex],
                    RandomNumber(79000000000, 79999999999)
                });
    }
}

void PhoneBook::AddPerson(const std::string& name, const uint64_t number) {
    data.emplace_back(Person{name, number});
}

std::vector<Person> PhoneBook::GetPersonsByName(const std::string& name) const {
    std::vector<Person> result;
    for (const auto& it : data) {
        // Ищем по части имени
        size_t pos = it.Name.find(name);
        if (pos != std::string::npos)
            result.emplace_back(it);
    }
    return result;
}

void PhoneBook::PrintAllItems() const {
    for (const auto& it : data) {
        std::cout << it << std::endl;
    }
}

std::string PhoneBook::GetFirstItem() {
    std::stringstream stream;
    stream << data[0];
    return stream.str();
}
