#ifndef TIME_H
#define TIME_H


#include <string>
#include <Windows.h>
#include <vector>
#include <iostream>


std::vector<std::string> DateTimeStr(const FILETIME* pFT, bool bSeconds, bool bDate, bool bTime, bool bLongDate, bool bMilliSec, LCID Locale);

std::string FormatMilliseconds(int milliseconds, bool includeLabel);

std::vector<FILETIME> getFileTime(std::string file);

#endif /*!TIME_H*/