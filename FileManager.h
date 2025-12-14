////////////////////////////////////////////////////////////////////////////
//	Модуль 		: FileManager.h
//	Автор		: Лавриненко Максим Дмитриевич
//	Описание    : Заголовочный файл для файлового менеджера
////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>

class FileManager {
public:
    static std::string read(const std::string& path);
    static void write(const std::string& path, const std::string& text);
};
