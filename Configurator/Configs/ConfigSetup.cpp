#include "ConfigSetup.h"

CleanerFileTimes getFileTime(const std::string& file)
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
        return std::vector<FILETIME>();
    }

    std::vector<FILETIME> ret = { creationTime, writeTime, accessTime };
    return ret;
}

void createTemplateConfigFile(const std::string& path_directory)
{
    std::string direcotry;
    if (path_directory != "")
    {
        direcotry = path_directory + '\\';
    }
    std::ofstream config_file_stream(direcotry + CONFIGNAME + ".json");
    config_file_stream << std::setw(4) << JSONTEMPLATE << std::endl;
    config_file_stream.close();
}

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

Json::JsonValue* configureFiles(std::vector<std::filesystem::path> files_paths)
{
    Json::JsonParcer parcer;
    Json::JsonValue* returnet_json_files = parcer.ParseJson(JSONTEMPLATE);

    int i = -1;
    for (std::filesystem::path& file : files_paths)
    {
        ++i;

        CleanerFileTimes time = getFileTime(file.string());

        std::string name = file.filename().string();
        std::string name_key = file.filename().string();

        if ((*(*returnet_json_files)["filesInDirectory"])[0]->is_exist("NAME"))
        {
            (*(*returnet_json_files)["filesInDirectory"])[0]->changeKey("NAME", name_key);
        }
        else
        {
            name_key = "\"" + name_key + "\"";
            Json::JsonValue* new_json = parcer.ParseJson(R"({
            )" + name_key + R"(: {
                "accessTime": {
                    "dwHighDateTime": 0,
                    "dwLowDateTime": 0
                },
                "creationTime": {
                    "dwHighDateTime": 0,
                    "dwLowDateTime": 0
                },
                "writeTime": {
                    "dwHighDateTime": 0,
                    "dwLowDateTime": 0
                },
                "addedDateTime": {
                    "dwHighDateTime": 0,
                    "dwLowDateTime": 0
                }
            }
        })");
            
            (*returnet_json_files)["filesInDirectory"]->add_value(new_json);
        }

        (*(*(*(*(*(*returnet_json_files)["filesInDirectory"])[i])[name])["creationTime"])["dwLowDateTime"]) = static_cast<unsigned int>(time[0].dwLowDateTime);
        (*(*(*(*(*(*returnet_json_files)["filesInDirectory"])[i])[name])["creationTime"])["dwHighDateTime"]) = static_cast<unsigned int>(time[0].dwHighDateTime);

        (*(*(*(*(*(*returnet_json_files)["filesInDirectory"])[i])[name])["writeTime"])["dwLowDateTime"]) = static_cast<unsigned int>(time[1].dwLowDateTime);
        (*(*(*(*(*(*returnet_json_files)["filesInDirectory"])[i])[name])["writeTime"])["dwHighDateTime"]) = static_cast<unsigned int>(time[1].dwHighDateTime);

        (*(*(*(*(*(*returnet_json_files)["filesInDirectory"])[i])[name])["accessTime"])["dwLowDateTime"]) = static_cast<unsigned int>(time[2].dwLowDateTime);
        (*(*(*(*(*(*returnet_json_files)["filesInDirectory"])[i])[name])["accessTime"])["dwHighDateTime"]) = static_cast<unsigned int>(time[2].dwHighDateTime);

        FILETIME added_time{};
        added_time.dwLowDateTime = 0;
        added_time.dwHighDateTime = 0;
        SYSTEMTIME lt;
        GetLocalTime(&lt);
        SystemTimeToFileTime(&lt, &added_time);

        (*(*(*(*(*(*returnet_json_files)["filesInDirectory"])[i])[name])["addedDateTime"])["dwLowDateTime"]) = static_cast<unsigned int>(added_time.dwLowDateTime);
        (*(*(*(*(*(*returnet_json_files)["filesInDirectory"])[i])[name])["addedDateTime"])["dwHighDateTime"]) = static_cast<unsigned int>(added_time.dwHighDateTime);
    }
    

    return returnet_json_files;
}

void saveJsonInConfig(Json::JsonValue* data, const std::string& config_directory)
{
    std::string direcotry;
    if (config_directory != "")
    {
        direcotry = config_directory + '\\';
    }
    //std::ofstream config_file_stream(direcotry + '\\' + CONFIGNAME + ".json");
    ////config_file_stream << std::setw(4) << data << std::endl;
    //config_file_stream.close();
    data->SaveJsonToFile(direcotry + CONFIGNAME + ".json", 4);
}

bool startConfigurateCleaner(const std::string& path_directory, const std::string& config_directory)
{
    std::cout << "Creatin template config file" << std::endl;
    createTemplateConfigFile(config_directory);

    std::cout << "gets files in folder" << std::endl;
    std::vector<std::filesystem::path> files_in_directory = getFilesInDirecotry(path_directory);

    std::cout << "configurateings files" << std::endl;
    Json::JsonValue* files_json_to_save = configureFiles(files_in_directory);
        
    std::cout << "saving config" << std::endl;
    saveJsonInConfig(files_json_to_save, config_directory);

    return true;
}
