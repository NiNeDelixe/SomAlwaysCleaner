#ifndef DELETER_H
#define DELETER_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <filesystem>

#include "../Time/Time.h"
#include "../Files/Files.h"

/*
������ ������:
0 - ������� ������
1 - �� ������� ������� �����
-1 - �� ������� ������� ����
2 - ����� �����
*/
int cleanDirectory(std::string directory_path);


#endif /*!DELETER_H*/