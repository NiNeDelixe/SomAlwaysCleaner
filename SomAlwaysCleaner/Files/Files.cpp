#include "Files.h"

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