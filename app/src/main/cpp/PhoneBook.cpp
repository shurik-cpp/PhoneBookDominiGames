//
// Created by shurik on 18.05.2023.
//

#include <sstream>
#include "PhoneBook.h"

long RandomNumber(const long min, const long max) {
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
        std::pair<std::string, size_t> item{
            names[randomNameIndex],
            static_cast<size_t>(std::abs(RandomNumber(79000000000, 79999999999)))
        };
        this->data.insert(item);
    }
}

void PhoneBook::AddPerson(const std::string& name, const int number) {
    this->data.insert(std::pair<std::string, int> {name, number});
}

std::vector<Person> PhoneBook::GetPersonsByName(const std::string& name) const {
    auto it = this->data.find(name);
    std::vector<Person> result;
    if (it != data.end())
        result.emplace_back(it->first, it->second);

    return result;
}

void PhoneBook::PrintAllItems() const {
    for (const auto& it : data) {
        Person person{it.first, it.second};
        std::cout << person << std::endl;
    }
}

std::string PhoneBook::GetFirstItem() {
    std::stringstream ss;
    auto it = data.begin();
    return it->first + it->second.AsString();
}
