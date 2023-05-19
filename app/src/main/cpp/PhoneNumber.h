//
// Created by shurik on 18.05.2023.
//

#ifndef PHONEBOOKDOMINIGAMES_PHONENUMBER_H
#define PHONEBOOKDOMINIGAMES_PHONENUMBER_H


#include <iostream>

class PhoneNumber {
public:
    PhoneNumber(const uint64_t number);
    PhoneNumber(const std::string& number);

    std::string AsString() const;
    uint64_t AsNumber() const;

private:

    std::string country;
    std::string region;
    std::string number_part1;
    std::string number_part2;
    std::string number_part3;

    std::string GetFormatingNumber() const;

    void ParseNumber(const std::string& number);
};

std::ostream& operator<<(std::ostream& ostream, const PhoneNumber& number);


#endif //PHONEBOOKDOMINIGAMES_PHONENUMBER_H
