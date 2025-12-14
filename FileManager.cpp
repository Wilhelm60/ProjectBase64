#include "FileManager.h"
#include <fstream>

std::string FileManager::read(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Файл не найден: " + path);
    }
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

void FileManager::write(const std::string& path, const std::string& text) {
    std::ofstream file(path, std::ios::binary);
    file << text;
}
