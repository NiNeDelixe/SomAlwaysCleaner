#ifndef DELETER_H
#define DELETER_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <filesystem>

#include "../Time/Time.h"


std::vector<std::string> getFilesInDirectory(std::string directory_path);


/*
Список ошибок:
0 - Очистка удачна
1 - Не удалось открыть папку
-1 - Не удалось удалить файл
2 - Папка пуста
*/
int cleanDirectory(std::string directory_path);

std::vector<FILETIME> getFileTime(std::string file);


#endif /*!DELETER_H*/