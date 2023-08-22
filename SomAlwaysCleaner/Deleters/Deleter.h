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
������ ������:
0 - ������� ������
1 - �� ������� ������� �����
-1 - �� ������� ������� ����
2 - ����� �����
*/
int cleanDirectory(const std::string& directory_path, int year = 0, int month = 0, int day = 7);

//bool deleteFileFromJson(const std::string& file, const std::string& config_path = "");


#endif /*!DELETER_H*/