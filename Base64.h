////////////////////////////////////////////////////////////////////////////
//	Модуль 		: Base64.h
//	Автор		: Янтилин Нурсолтан Раилевич
//	Описание    : Заголовочный файл для механизма кодирования
////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>

class Base64 {
public:
    std::string encode(const std::string& data);
    std::string decode(const std::string& base64Data);
    std::string cleanBase64(const std::string& input);
    std::string padBase64(const std::string& input);
};