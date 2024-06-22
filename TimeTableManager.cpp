#include "TimeTableManager.h"
#include "LocalSave.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <iostream>

extern std::wstring g_fullConfigPath;

bool TimeTableManager::parseTimeTable()
{
    days.clear();
    FILE* fp;
    _wfopen_s(&fp, g_fullConfigPath.c_str(), L"r");
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document document;
    document.ParseStream(is);
    if (fp)
    {
        fclose(fp);
    }
    
    for (const auto& item : document.GetArray()) {
        Day day;
        day.date = item["date"].GetString();

        for (const auto& eventJson : item["events"].GetArray()) {
            Event event;
            event.begin = eventJson["begin"].GetString();
            event.end = eventJson["end"].GetString();
            event.name = eventJson["name"].GetString();
            day.events.push_back(event);
        }
        days.push_back(day);
    }
    return true;
}

bool TimeTableManager::writeTimeTable() const
{
    for (auto day : days)
    {
        std::cout << "\n\nDATE: " << day.date;
        for (auto event : day.events)
        {
            std::cout << "\n\n" << event.name;
            std::cout << "\n" << event.begin << " - " << event.end;
        }
    }
    return true;
}


bool TimeTableManager::getDay(TimeDayMonthYear time)
{
	return false;
}
