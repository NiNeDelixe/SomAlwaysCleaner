#include "Time.h"

std::vector<std::string> DateTimeStr(const FILETIME* pFT, bool bSeconds, bool bDate, bool bTime, bool bLongDate, bool bMilliSec, LCID Locale)
{
    std::vector<std::string> formattedDateTime;

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
                formattedDateTime.push_back(FormatMilliseconds(st.wMilliseconds, true));
            }
            formattedDateTime.push_back(sTime);
        }
    }

    return formattedDateTime;
}

std::string FormatMilliseconds(int milliseconds, bool includeLabel)
{
    if (!includeLabel) 
    {
        return std::to_string(milliseconds);
    }
    return std::to_string(milliseconds) + " ms";
}