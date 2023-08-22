#ifndef TIME_H
#define TIME_H


#include <string>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>



//creationTime, writeTime, accessTime, addedtime(optional)
using CleanerFileTimes = std::vector<FILETIME>;
//date, time, miliseconds
using CleanerStringDateTime = std::vector<std::string>;




struct CleanerTime : public tm
{
	CleanerTime(tm time);
	CleanerTime() = default;
	int milisecnds;
};

using CleanerDateTime = CleanerTime;


CleanerStringDateTime normaliseStringTime(const FILETIME* pFT, bool bSeconds, bool bDate, bool bTime, bool bLongDate, bool bMilliSec, LCID Locale);

CleanerDateTime normaliseTime(const FILETIME* pFT, bool bSeconds, bool bDate, bool bTime, bool bLongDate, bool bMilliSec, LCID Locale);


std::string formatMilliseconds(int milliseconds, bool includeLabel);

CleanerFileTimes getFileTime(const std::string& file);

//CleanerFileTimes getFileTimeFromConfig(const std::string& file, const std::string& config_file);


CleanerStringDateTime getStringSystemDateTime();

CleanerDateTime getSystemDateTime();


bool checkIsFileBeingDeleted(CleanerDateTime& time, CleanerDateTime& period);

#endif /*!TIME_H*/