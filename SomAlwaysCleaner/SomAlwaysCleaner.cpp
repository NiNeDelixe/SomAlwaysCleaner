#include <iostream>
#include "Deleters/Deleter.h"

void argcError(int argc, char* argv[], std::string string);

int main(int argc, char* argv[])
{
    //cleanDirectory("Папка_для_очистки", "", 0, 0, 0);

	if (argc < 2)
	{
		argcError(argc, argv, "didnt find folder");
		return 1;
	}
	if (argv[1])
	{
		std::cout << "start Cleaning" << std::endl;
		int status = cleanDirectory(argv[1], std::stoi(argv[2]), std::stoi(argv[3]), std::stoi(argv[4]));
		if (status == 0)
		{
			std::cout << "Cleaning completed" << std::endl;
		}
		else if (status == 2)
		{
			std::cerr << "Folder is empty" << std::endl;
		}
		else
		{
			std::cerr << "error" << std::endl;
		}
	}
	else
	{
		argcError(argc, argv, "didnt find folder");
		startNotification(L"Не найдена директория", L"Ошибка удаления", L"Не найдена директория");
		return 1;
	}
	return 0;
}

void argcError(int argc, char* argv[], std::string string)
{
	std::cerr << argv[0] << string << std::endl;
}