#pragma once
class TimeHourMinute
{
public:
	TimeHourMinute() : hour(0), minute(0) {}
	TimeHourMinute(int hour, int minute);
	int GetHour() const;
	int GetMinute() const;
	void SetHour(int hour);
	void SetMinute(int minute);
private:
	int hour;
	int minute;
};

class TimeDayMonthYear
{
public:
	TimeDayMonthYear(int day, int month, int year);
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	
private:
	bool IsLeapYear(int year) const;
	int DaysInMonth(int year, int month) const;
	void ValidateDay();
	int day;
	int month;
	int year;
};

