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
������ ������:
0 - ������� ������
1 - �� ������� ������� �����
-1 - �� ������� ������� ����
2 - ����� �����
*/
int cleanDirectory(std::string directory_path);

std::vector<FILETIME> getFileTime(std::string file);


#endif /*!DELETER_H*/