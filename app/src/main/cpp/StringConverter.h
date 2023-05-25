//
// Created by shurik on 25.05.2023.
//

#ifndef PHONEBOOKDOMINIGAMES_STRINGCONVERTER_H
#define PHONEBOOKDOMINIGAMES_STRINGCONVERTER_H

#include <iostream>
#include <codecvt>
#include <string>

class StringConverter {
public:
    static std::wstring UtfToWstring (const std::string& str);
    static std::string WstringToUtf (const std::wstring& wstr);
    static void CyrillicToLowerCase(std::wstring& wstr);
};



#endif //PHONEBOOKDOMINIGAMES_STRINGCONVERTER_H
