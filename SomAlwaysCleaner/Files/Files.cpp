#include "Files.h"

std::vector<std::filesystem::path> getFilesInDirecotry(const std::string& path_directory)
{
    std::string folder_path = path_directory;
    std::vector<std::filesystem::path> file_names;

    std::filesystem::path dir_path(folder_path);

    if (std::filesystem::exists(dir_path) && std::filesystem::is_directory(dir_path))
    {
        for (const auto& entry : std::filesystem::directory_iterator(dir_path))
        {
            if (std::filesystem::is_regular_file(entry))
            {
                file_names.push_back(entry.path());
            }
            if (std::filesystem::is_directory(entry))
            {
                file_names.push_back(entry.path());
            }
        }
    }
    else
    {
        std::cerr << "Не удалось открыть папку." << std::endl;
        file_names.push_back("");
        return file_names;
    }


    return file_names;
}