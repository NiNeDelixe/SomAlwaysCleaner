#ifndef CONFIGSETUP_H
#define CONFIGSETUP_H

#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <windows.h>
#include <iostream>
//#include <nlohmann/json.hpp>

#include "../Json/Json.h"


//using json = nlohmann::json;

//creationTime, writeTime, accessTime
using CleanerFileTimes = std::vector<FILETIME>;

const std::string JSONTEMPLATE = R"({
    "filesInDirectory": [
        {
            "NAME": {
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
        }
    ]
}
)";

const std::string CONFIGNAME = "config";


CleanerFileTimes getFileTime(const std::string& file);

void createTemplateConfigFile(const std::string& path_directory);

std::vector<std::filesystem::path> getFilesInDirecotry(const std::string& path_directory);

Json::JsonValue* configureFiles(std::vector<std::filesystem::path> files_paths);

void saveJsonInConfig(Json::JsonValue* data, const std::string& config_directory);

bool startConfigurateCleaner(const std::string& path_directory, const std::string& config_directory = "");

#endif /*!CONFIGSETUP_H*/