//
// Created by shurik on 25.05.2023.
//

#include "StringConverter.h"
#include <unordered_map>

std::wstring StringConverter::UtfToWstring (const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}

std::string StringConverter::WstringToUtf (const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

void StringConverter::CyrillicToLowerCase(std::wstring& wstr) {
    static std::unordered_map<wchar_t, wchar_t> symbols = {
            {L'А', L'а'}, {L'Б', L'б'}, {L'В', L'в'}, {L'Г', L'г'},
            {L'Д', L'д'}, {L'Е', L'е'}, {L'Ё', L'ё'}, {L'Ж', L'ж'},
            {L'З', L'з'}, {L'И', L'и'}, {L'Й', L'й'}, {L'К', L'к'},
            {L'Л', L'л'}, {L'М', L'м'}, {L'Н', L'н'}, {L'О', L'о'},
            {L'П', L'п'}, {L'Р', L'р'}, {L'С', L'с'}, {L'Т', L'т'},
            {L'У', L'у'}, {L'Ф', L'ф'}, {L'Х', L'х'}, {L'Ц', L'ц'},
            {L'Ч', L'ч'}, {L'Ш', L'ш'}, {L'Щ', L'щ'}, {L'Ъ', L'ъ'},
            {L'Ы', L'ы'}, {L'Ь', L'ь'}, {L'Э', L'э'}, {L'Ю', L'ю'},
            {L'Я', L'я'}
    };

    for (wchar_t& it : wstr) {
        if (symbols.count(it))
            it = symbols[it];
    }
}

