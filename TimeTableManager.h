#pragma once

#include "Time.h"
#include "rapidjson/document.h"
#include <string>
#include <vector>

class TimeTableManager
{
private:
	struct Event
	{
		Event() {}
		/*Event(const std::string& n, const TimeHourMinute& b, const TimeHourMinute& e)
			: name(n), begin(b), end(e) {}*/

		std::string name;
		std::string begin;
		std::string end;
		/*TimeHourMinute begin;
		TimeHourMinute end;*/

	};
	struct Day
	{
		Day() {}
		/*TimeDayMonthYear date;*/
		std::string date;
		std::vector<Event> events;
	};
/*
Format for the timetable file:
{
	//date: 
	DD/MM/YYYY
	//events 
	{
		//eventID1
		{
			name: "first"
			begin: XX:XX
			end: XX:XX
		},
		...
	}
}
*/
public:
	TimeTableManager() {}
	bool ParseTimeTable();
	bool WriteTimeTable() const;
	bool AddDay();
	bool GetDay(TimeDayMonthYear time);
	void ReadDocument(rapidjson::Document& document);
	void WriteDocument(rapidjson::Document& document);
	void GetDayFromUser(Day& aDay);
	void GetEventFromUser(Event& aEvent);
private:
	std::vector<Day> mDays;
};

