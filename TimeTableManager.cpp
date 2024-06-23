#include "TimeTableManager.h"
#include "LocalSave.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/writer.h"
#include <iostream>

extern std::wstring g_fullConfigPath;

bool TimeTableManager::ParseTimeTable()
{
    mDays.clear();
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
        mDays.push_back(day);
    }
    return true;
}

bool TimeTableManager::WriteTimeTable() const
{
    for (auto day : mDays)
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

bool TimeTableManager::AddDay()
{
    Day newDay;
    GetDayFromUser(newDay);
    rapidjson::Document document;
    ReadDocument(document);

    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
    rapidjson::Value dayObject(rapidjson::kObjectType);
    dayObject.AddMember("date", rapidjson::Value().SetString(newDay.date.c_str(), allocator), allocator);

    rapidjson::Value eventsArray(rapidjson::kArrayType);
    for (const auto& event : newDay.events)
    {
        rapidjson::Value eventObject(rapidjson::kObjectType);
        eventObject.AddMember("begin", rapidjson::Value().SetString(event.begin.c_str(), allocator), allocator);
        eventObject.AddMember("end", rapidjson::Value().SetString(event.end.c_str(), allocator), allocator);
        eventObject.AddMember("name", rapidjson::Value().SetString(event.name.c_str(), allocator), allocator);
        eventsArray.PushBack(eventObject, allocator);
    }
    dayObject.AddMember("events", eventsArray, allocator);
    document.PushBack(dayObject, allocator);

    WriteDocument(document);
    mDays.push_back(newDay);

    return true;
}

void TimeTableManager::GetDayFromUser(Day& aDay)
{
    std::cout << "\n\n Enter date of day (DD/MM/YYYY)    :    ";
    std::cin >> aDay.date;
    std::cout << "\n\n Enter number of events on the given day    :    ";
    int eventCount;
    std::cin >> eventCount;
    for (int i = 0; i < eventCount; i++)
    {
        Event ev;
        aDay.events.push_back(ev);
        GetEventFromUser(aDay.events[i]);
    }
}

void TimeTableManager::GetEventFromUser(Event& aEvent)
{
    std::cout << "\n\n Enter name of event    :    ";
    std::cin >> aEvent.name;
    std::cout << "\n\n Event begins at (XX:XX)    :    ";
    std::cin >> aEvent.begin;
    std::cout << "\n\n Event ends at (XX:XX)    :    ";
    std::cin >> aEvent.end;
}

bool TimeTableManager::GetDay(TimeDayMonthYear time)
{
	return false;
}

void TimeTableManager::ReadDocument(rapidjson::Document& document)
{
    FILE* fp;
    _wfopen_s(&fp, g_fullConfigPath.c_str(), L"r");
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    document.ParseStream(is);
    if (fp) fclose(fp);
}

void TimeTableManager::WriteDocument(rapidjson::Document& document)
{
    FILE* fp;
    _wfopen_s(&fp, g_fullConfigPath.c_str(), L"w");
    char writeBuffer[65536];
    rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
    rapidjson::Writer<rapidjson::FileWriteStream> writer(os);
    document.Accept(writer);
    if (fp)
    {
        fclose(fp);
    }
}
