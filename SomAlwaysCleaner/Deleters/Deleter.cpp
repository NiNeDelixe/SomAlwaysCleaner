#include "Deleter.h"



int cleanDirectory(std::string directory_path)
{
    std::vector<std::string> files = getFilesInDirectory(directory_path);

    if (files.size() == 0)
    {
        return 2;
    }
    if (files == std::vector<std::string>())
    {
        return 1;
    }
    

    for (auto& file : files)
    {
        std::vector<FILETIME> time = getFileTime(directory_path + '\\' + file);

        std::vector<std::string> tife = DateTimeStr(&time[0], true, true, true, false, false, LOCALE_USER_DEFAULT);

        uintmax_t status = std::filesystem::remove_all(directory_path + '\\' + file);

        if (status == false)
        {
            return -1;
        }
    }
    return 0;
}


