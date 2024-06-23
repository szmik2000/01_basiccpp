#pragma once

#include "Time.h"
#include <string>
#include <vector>

class TimeTableManager
{
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
	bool parseTimeTable();
	bool writeTimeTable() const;
	bool getDay(TimeDayMonthYear time);
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
	std::vector<Day> mDays;
};

