#pragma once //Защита от многократного включения
#include <string>

class Base64 {
public:
    std::string encode(const std::string& data);
    std::string decode(const std::string& base64Data);
    std::string cleanBase64(const std::string& input);
    std::string padBase64(const std::string& input);
};