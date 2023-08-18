#include "Deleter.h"

std::vector<std::string> getFilesInDirectory(std::string directory_path)
{
    std::string folder_path = directory_path;
    std::vector<std::string> file_names;

    std::filesystem::path dir_path(folder_path);

    if (std::filesystem::exists(dir_path) && std::filesystem::is_directory(dir_path)) 
    {
        for (const auto& entry : std::filesystem::directory_iterator(dir_path)) 
        {
            if (std::filesystem::is_regular_file(entry)) 
            {
                file_names.push_back(entry.path().filename().string());
            }
            if (std::filesystem::is_directory(entry))
            {
                file_names.push_back(entry.path().filename().string());
            }
        }
    }
    else 
    {
        std::cerr << "Не удалось открыть папку." << std::endl;
        return std::vector<std::string>();
    }


    return file_names;
}

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

std::vector<FILETIME> getFileTime(std::string file)
{
    FILETIME creationTime, writeTime, accessTime;
    
    WIN32_FIND_DATAA findFileData;
    HANDLE fileHandle = FindFirstFileA(file.c_str(), &findFileData);

    if (fileHandle != INVALID_HANDLE_VALUE) 
    {
        creationTime = findFileData.ftCreationTime;
        writeTime = findFileData.ftLastWriteTime;
        accessTime = findFileData.ftLastAccessTime;

        FindClose(fileHandle);
    }
    else 
    {
        std::cerr << "Не удалось открыть файл." << std::endl;
    }

    std::vector<FILETIME> ret = { creationTime, writeTime, accessTime };
    return ret;
}
