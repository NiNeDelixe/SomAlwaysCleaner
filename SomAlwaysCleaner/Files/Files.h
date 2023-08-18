#ifndef FILES_H
#define FILES_H

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

#include <nlohmann/json.hpp>


using json = nlohmann::json;

std::vector<std::string> getFilesInDirectory(std::string directory_path);

#endif /*!FILES_H*/