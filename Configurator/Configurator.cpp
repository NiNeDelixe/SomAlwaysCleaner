#include <iostream>
#include "Configs/ConfigSetup.h"

void argcError(int argc, char* argv[], std::string string);

int main(int argc, char* argv[])
{
	//startConfigurateCleaner("Папка_для_очистки");
	if (argc < 2)
	{
		argcError(2, argv, "didnt find folder");
		return 1;
	}
	if (argv[1])
	{
		std::cout << "start Configuraton" << std::endl;
		if (startConfigurateCleaner(argv[1], argv[2]))
		{
			std::cout << "Configuraton completed" << std::endl;
		}
		else
		{
			std::cout << "error" << std::endl;
		}
	}
	else
	{
		argcError(2, argv, "didnt find folder");
		return 1;
	}
	return 0;
}

void argcError(int argc, char* argv[], std::string string)
{
	std::cout << argv[argc] << string << std::endl;
}
