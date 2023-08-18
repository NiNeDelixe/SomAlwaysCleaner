#ifndef TIME_H
#define TIME_H


#include <string>
#include <Windows.h>
#include <sstream>
#include <vector>

std::vector<std::string> DateTimeStr(const FILETIME* pFT, bool bSeconds, bool bDate, bool bTime, bool bLongDate, bool bMilliSec, LCID Locale);

std::string FormatMilliseconds(int milliseconds, bool includeLabel);

#endif /*!TIME_H*/