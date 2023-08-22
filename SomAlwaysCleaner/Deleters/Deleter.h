#ifndef DELETER_H
#define DELETER_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <filesystem>

#include "../Time/Time.h"
#include "../Files/Files.h"
#include "../Notifications/Notification.h"

const std::string CONFIGNAME = "config";

/*
Список ошибок:
0 - Очистка удачна
1 - Не удалось открыть папку
-1 - Не удалось удалить файл
2 - Папка пуста
*/
int cleanDirectory(const std::string& directory_path, int year = 0, int month = 0, int day = 7);

//bool deleteFileFromJson(const std::string& file, const std::string& config_path = "");


#endif /*!DELETER_H*/