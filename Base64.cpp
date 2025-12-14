////////////////////////////////////////////////////////////////////////////
//	Модуль 		: Base64.cpp
//	Автор		: Янтилин Нурсолтан Раилевич
//	Описание    : Механизм кодирования
//  Тестирование и доработка : Джапбаров Ислам Темирбудатович
////////////////////////////////////////////////////////////////////////////

#include "Base64.h"
#include <sstream>
#include <iterator>
#include <algorithm>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>

std::string Base64::encode(const std::string& input) {
    using namespace boost::archive::iterators;

    if (input.empty()) return "";

    std::string result;
    result.reserve(((input.size() + 2) / 3) * 4); // Резервирует память для результата

    // Преобразует 8-битные символы в 6-битные группы
    typedef base64_from_binary<transform_width<const char*, 6, 8>> Base64Encoder;

    std::copy(
        Base64Encoder(input.data()),
        Base64Encoder(input.data() + input.size()),
        std::back_inserter(result)
    );

    // Рассчитывает, сколько нужно символов '=', чтобы длина результата была кратна 4
    size_t padding = (3 - input.size() % 3) % 3;
    result.append(padding, '=');

    return result;
}

std::string Base64::decode(const std::string& input)
{
    using namespace boost::archive::iterators;

    typedef transform_width<binary_from_base64<const char*>, 8, 6> Base64Decoder;

    std::stringstream os;

    // Игнорируем символы '='
    size_t size = input.size();
    while (size > 0 && input[size - 1] == '=')
        --size;

    std::copy(
        Base64Decoder(input.c_str()),
        Base64Decoder(input.c_str() + size),
        std::ostream_iterator<char>(os)
    );

    return os.str();
}

std::string Base64::cleanBase64(const std::string& input) {
    std::string result;
    bool foundEquals = false;

    for (char c : input) {
        // Разрешаем только валидные символы base64
        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') ||
            c == '+' || c == '/') {
            if (!foundEquals) {
                result += c;
            }
        }
        // '=' разрешен только в конце
        else if (c == '=' && !foundEquals) {
            foundEquals = true;
            result += c;
        }
        // '=' после другого '=' или невалидный символ - игнорируем
    }

    return result;
}

// Добавляет символы '=' для выравнивания длины строки до кратной 4
// Исправление для уже существующего кода Base64
std::string Base64::padBase64(const std::string& input) {
    std::string result = input;
    while (result.length() % 4 != 0) {
        result += '=';
    }
    return result;
}