#include "Deleter.h"



int cleanDirectory(const std::string& directory_path, int year, int month, int day)
{
    std::string direcotry;
    if (directory_path != "")
    {
        direcotry = directory_path + '\\';
    }


    std::vector<std::filesystem::path> files = getFilesInDirecotry(direcotry);

    if (files.size() == 1)
    {
        if (files[0] == "")
        {
            startNotification(L"Не удалось открыть папку", L"Ошибка удаления", L"Не удалось открыть папку");
            return 1;
        }
    }
    if (files.empty())
    {
        //startNotification(L"Не удалось открыть папку", L"Ошибка удаления", L"Не удалось открыть папку");
        std::cerr << "Folder is empty" << std::endl;
        return 2;
    }
    
    CleanerDateTime period{};
    period.tm_year = year;
    period.tm_mon = month;
    period.tm_mday = day;

    for (auto& file : files)
    {
        CleanerFileTimes time = getFileTime(direcotry + file.filename().string());

        CleanerDateTime tife = normaliseTime(&time[0], true, true, true, false, false, LOCALE_USER_DEFAULT);

        uintmax_t status{};
        bool delete_json_file = false;

        if (checkIsFileBeingDeleted(tife, period))
        {
            status = std::filesystem::remove_all(direcotry + file.filename().string());

            std::cout << "File " << file.string() <<  " is deletet" << std::endl;

            /*delete_json_file = deleteFileFromJson(file.filename().string(), config_dir + CONFIGNAME + ".json");

            if (delete_json_file == false)
            {
                std::cerr << "error in deleteng in json" << std::endl;
            }*/
        }
        else
        {
            std::cout << "File " << file.string() << " is continued" << std::endl;
            continue;
        }


        if (status == false)
        {
            startNotification(L"Не удалось удалить файл", L"Ошибка удаления", L"Не удалось удалить файл");
            return -1;
        }
    }
    return 0;
}

//bool deleteFileFromJson(const std::string& file, const std::string& config_path)
//{
//    Json::JsonParcer parcer;
//    Json::JsonValue* files_data = parcer.ParseFile(config_path);
//
//    for (auto file_dir : (*files_data)["filesInDirectory"]->get_value_list())
//    {
//        if (file_dir->is_exist(file))
//        {
//            file_dir->deleteValue(file);
//            //file_dir->get_value_list().cle
//        }
//    }
//    files_data->SaveJsonToFile(config_path, 4);
//
//    delete files_data;
//    return true;
//}


