#include "Time.h"

CleanerStringDateTime normaliseStringTime(const FILETIME* pFT, bool bSeconds, bool bDate, bool bTime, bool bLongDate, bool bMilliSec, LCID Locale)
{
    CleanerStringDateTime formattedDateTime;

    SYSTEMTIME st;
    FileTimeToSystemTime(pFT, &st);

    if (bDate)
    {
        DWORD dwDateFlags = bLongDate ? DATE_LONGDATE : DATE_SHORTDATE;
        int dateStrLen = GetDateFormat(Locale, dwDateFlags, &st, nullptr, nullptr, 0);
        if (dateStrLen > 0)
        {
            std::string sDate(dateStrLen, '\0');
            GetDateFormatA(Locale, dwDateFlags, &st, nullptr, &sDate[0], dateStrLen);
            formattedDateTime.push_back(sDate);
        }
    }

    if (bTime)
    {
        DWORD dwTimeFlags = 0;
        if (!bSeconds)
        {
            dwTimeFlags |= TIME_NOSECONDS;
        }
        int timeStrLen = GetTimeFormat(Locale, dwTimeFlags, &st, nullptr, nullptr, 0);
        if (timeStrLen > 0)
        {
            std::string sTime(timeStrLen, '\0');
            GetTimeFormatA(Locale, dwTimeFlags, &st, nullptr, &sTime[0], timeStrLen);
            if (bMilliSec)
            {
                formattedDateTime.push_back(formatMilliseconds(st.wMilliseconds, true));
            }
            formattedDateTime.push_back(sTime);
        }
    }

    return formattedDateTime;
}

CleanerDateTime normaliseTime(const FILETIME* pFT, bool bSeconds, bool bDate, bool bTime, bool bLongDate, bool bMilliSec, LCID Locale)
{

    CleanerDateTime formattedDateTime{};

    SYSTEMTIME st;
    FileTimeToSystemTime(pFT, &st);

    if (bDate)
    {
        DWORD dwDateFlags = bLongDate ? DATE_LONGDATE : DATE_SHORTDATE;
        int dateStrLen = GetDateFormat(Locale, dwDateFlags, &st, nullptr, nullptr, 0);
        if (dateStrLen > 0)
        {
            std::string sDate(dateStrLen, '\0');
            GetDateFormatA(Locale, dwDateFlags, &st, nullptr, &sDate[0], dateStrLen);
            //formattedDateTime.push_back(sDate);
            formattedDateTime.tm_year = st.wYear - 1900;
            formattedDateTime.tm_mon = st.wMonth - 1;
            formattedDateTime.tm_mday = st.wDay;
        }
    }

    if (bTime)
    {
        DWORD dwTimeFlags = 0;
        if (!bSeconds)
        {
            dwTimeFlags |= TIME_NOSECONDS;
        }
        int timeStrLen = GetTimeFormat(Locale, dwTimeFlags, &st, nullptr, nullptr, 0);
        if (timeStrLen > 0)
        {
            std::string sTime(timeStrLen, '\0');
            GetTimeFormatA(Locale, dwTimeFlags, &st, nullptr, &sTime[0], timeStrLen);
            if (bMilliSec)
            {
                //formattedDateTime.push_back(formatMilliseconds(st.wMilliseconds, true));
                formattedDateTime.milisecnds = st.wMilliseconds;
            }
            //formattedDateTime.push_back(sTime);
            formattedDateTime.tm_hour = st.wHour;
            formattedDateTime.tm_min = st.wMinute;
            formattedDateTime.tm_sec = st.wSecond;
        }
    }

    return formattedDateTime;
}

std::string formatMilliseconds(int milliseconds, bool includeLabel)
{
    if (!includeLabel) 
    {
        return std::to_string(milliseconds);
    }
    return std::to_string(milliseconds) + " ms";
}

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

//CleanerFileTimes getFileTimeFromConfig(const std::string& file, const std::string& config_file)
//{
//    FILETIME creationTime, writeTime, accessTime, addedTime;
//    std::string file_name = file;
//
//    Json::JsonParcer parcer;
//    Json::JsonValue* files_data = parcer.ParseFile(config_file);
//
//    if (files_data == nullptr)
//    {
//        std::cerr << "config didnt found" << std::endl;
//        return CleanerFileTimes();
//    }
//
//    for (auto file_dir : (*files_data)["filesInDirectory"]->get_value_list())
//    {
//        if (file_dir->is_exist(file_name))
//        {
//            addedTime.dwHighDateTime = (*(*(*file_dir)[file_name])["addedDateTime"])["dwHighDateTime"]->to_int();
//            addedTime.dwHighDateTime = (*(*(*file_dir)[file_name])["addedDateTime"])["dwHighDateTime"]->to_int();
//
//            writeTime.dwHighDateTime = (*(*(*file_dir)[file_name])["writeTime"])["dwHighDateTime"]->to_int();
//            writeTime.dwHighDateTime = (*(*(*file_dir)[file_name])["writeTime"])["dwHighDateTime"]->to_int();
//
//            creationTime.dwHighDateTime = (*(*(*file_dir)[file_name])["creationTime"])["dwHighDateTime"]->to_int();
//            creationTime.dwHighDateTime = (*(*(*file_dir)[file_name])["creationTime"])["dwHighDateTime"]->to_int();
//
//            accessTime.dwHighDateTime = (*(*(*file_dir)[file_name])["accessTime"])["dwHighDateTime"]->to_int();
//            accessTime.dwHighDateTime = (*(*(*file_dir)[file_name])["accessTime"])["dwHighDateTime"]->to_int();
//        }
//    }
//
//    CleanerFileTimes result{ creationTime , writeTime ,accessTime ,addedTime };
//
//    delete files_data;
//    return result;
//}

CleanerStringDateTime getStringSystemDateTime()
{
    // current date/time based on current system
    time_t now = time(0);

    tm ltm{};
    localtime_s(&ltm, &now);

    CleanerStringDateTime result;
    result.push_back(std::to_string(ltm.tm_mday) + '.' + (((1 + ltm.tm_mon) >= 9) ? std::to_string(1 + ltm.tm_mon) : '0' + std::to_string(1 + ltm.tm_mon)) + '.' + std::to_string(1900 + ltm.tm_year));
    result.push_back(std::to_string(ltm.tm_hour) + ':' + std::to_string(ltm.tm_min) + ':' + std::to_string(ltm.tm_sec));

    return result;
}

CleanerDateTime getSystemDateTime()
{
    // current date/time based on current system
    time_t now = time(0);

    tm ltm{};
    localtime_s(&ltm, &now);

    return ltm;
}

bool checkIsFileBeingDeleted(CleanerDateTime& time, CleanerDateTime& period)
{
    CleanerDateTime systemTime = getSystemDateTime();

    if (systemTime.tm_year - time.tm_year > period.tm_year)
    {
        return true;
    }
    else if (systemTime.tm_mon - time.tm_mon > period.tm_mon)
    {
        return true;
    }
    else if (systemTime.tm_mday - time.tm_mday >= period.tm_mday)
    {
        return true;
    }

    return false;
}

CleanerTime::CleanerTime(tm time)
{
    this->milisecnds = 0;
    this->tm_hour = time.tm_hour;
    this->tm_isdst = time.tm_isdst;
    this->tm_mday = time.tm_mday;
    this->tm_min = time.tm_min;
    this->tm_mon = time.tm_mon;
    this->tm_sec = time.tm_sec;
    this->tm_wday = time.tm_wday;
    this->tm_yday = time.tm_yday;
    this->tm_year = time.tm_year;
}
