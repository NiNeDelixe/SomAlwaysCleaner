#ifndef CONFIGSETUP_H
#define CONFIGSETUP_H

#include <string>
#include <filesystem>
#include <vector>

#include <nlohmann/json.hpp>


using json = nlohmann::json;

json configureFiles(std::vector<std::string> files_paths);

#endif /*!CONFIGSETUP_H*/