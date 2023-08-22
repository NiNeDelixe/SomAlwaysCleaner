#ifndef FILES_H
#define FILES_H

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>


std::vector<std::filesystem::path> getFilesInDirecotry(const std::string& path_directory);

#endif /*!FILES_H*/