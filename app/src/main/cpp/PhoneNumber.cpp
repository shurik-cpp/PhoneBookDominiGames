//
// Created by shurik on 18.05.2023.
//

#include "PhoneNumber.h"

#include <sstream>

std::ostream& operator<<(std::ostream& ostream, const PhoneNumber& number) {
    ostream << number.AsString();
    return ostream;
}

PhoneNumber::PhoneNumber(const uint64_t number) {
    ParseNumber(std::to_string(number));
}

PhoneNumber::PhoneNumber(const std::string& number) {
    // Отсеиваем не цифровые символы
    std::string num;
    for (const auto& it : number)
        if (it >= '0' && it <= '9')
            num += it;
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
    std::stringstream stream;
    if (!country.empty())
        stream << '+' << country;
    if (!region.empty())
        stream << '(' << region << ')';
    if (!number_part1.empty())
        stream << number_part1;
    if (!number_part2.empty())
        stream << '-' << number_part2 << '-' ;

    stream <<  number_part3;

    return stream.str();
}

void PhoneNumber::ParseNumber(const std::string& number) {
    // TODO: Переделать парсер номера!
    if (number.size() == 11) {
        for (int i = 0; i < 2; ++i) {
            number_part3 += number[number.size() - 2 + i];
        }
        for (int i = 0; i < 2; ++i) {
            number_part2 += number[number.size() - 4 + i];
        }
        for (int i = 0; i < 3; ++i) {
            number_part1 += number[number.size() - 7 + i];
        }
        for (int i = 0; i < 3; ++i) {
            region += number[number.size() - 10 + i];
        }
        country += number[0];
    }
    else {
        number_part3 = number;
    }
}