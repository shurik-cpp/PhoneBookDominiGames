//
// Created by shurik on 18.05.2023.
//

#include "PhoneNumber.h"
#include <regex>
#include <sstream>

std::ostream& operator<<(std::ostream& ostream, const PhoneNumber& number) {
    ostream << number.AsString();
    return ostream;
}

PhoneNumber::PhoneNumber(const uint64_t number) {
    ParseNumber(std::to_string(number));
}

PhoneNumber::PhoneNumber(const std::string& number) {
    // Отбрасываем не цифровые символы
    std::regex digits_regex("[^0-9]");
    std::string num = std::regex_replace(number, digits_regex, "");
    ParseNumber(num);
}

std::string PhoneNumber::AsString() const {
    return GetFormatingNumber();
}

uint64_t PhoneNumber::AsNumber() const {
    std::string num = country + region + number_part1 + number_part2 + number_part3;
    try {
        uint64_t n = std::stoul(num);
        return n;
    }
    catch (const std::exception& ex) {
        std::cerr << "PhoneNumber::AsNumber(): Bad number." << std::endl;
    }
    return 0;
}

std::string PhoneNumber::GetFormatingNumber() const {
    // TODO: Убрать. Пусть разбирается вьюшка, в каком формате ей выводить номер телефона.
    std::stringstream stream;
    int numberLength = country.size() + region.size() + number_part1.size() + number_part2.size() + number_part3.size();
    if (numberLength == 11) {
        if (!country.empty())
            stream << '+' << country;
        if (!region.empty())
            stream << '(' << region << ')';
        if (!number_part1.empty())
            stream << number_part1;
        if (!number_part2.empty())
            stream << '-' << number_part2 << '-';
        stream << number_part3;
    }
    else
        stream << country << region << number_part1 << number_part1 << number_part2 << number_part3;

    return stream.str();
}

void PhoneNumber::ParseNumber(const std::string& number) {
    // TODO: Убрать от сюда парсер. Хранить только uint64_t.
    if (number.size() == 11) {
        country = number.substr(0, 1);
        region = number.substr(1, 3);
        number_part1 = number.substr(4, 3);
        number_part2 = number.substr(7, 2);
        number_part3 = number.substr(9, 2);
    }
    else
        number_part3 = number;
}