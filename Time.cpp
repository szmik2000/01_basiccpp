#include "Time.h"

#include <stdexcept>

TimeHourMinute::TimeHourMinute(int hour, int minute)
{
    if (hour < 0 || hour > 23) 
    {
        throw std::invalid_argument("Hour must be between 0 and 23.");
    }
    if (minute < 0 || minute > 59) 
    {
        throw std::invalid_argument("Minute must be between 0 and 59.");
    }
    this->hour = hour;
    this->minute = minute;
}

int TimeHourMinute::GetHour() const
{
    return hour;
}

int TimeHourMinute::GetMinute() const
{
    return minute;
}

void TimeHourMinute::SetHour(int hour)
{
    if (hour < 0 || hour > 23) 
    {
        throw std::invalid_argument("Hour must be between 0 and 23.");
    }
    this->hour = hour;
}

void TimeHourMinute::SetMinute(int minute)
{
    if (minute < 0 || minute > 59) 
    {
        throw std::invalid_argument("Minute must be between 0 and 59.");
    }
    this->minute = minute;
}

TimeDayMonthYear::TimeDayMonthYear(int day, int month, int year)
{
    if (day < 1)
    {
        throw std::invalid_argument("Day must be at least 1");
    }
    if (month < 1 || month > 12)
    {
        throw std::invalid_argument("Month must be between 1 and 12.");
    }
    if (year < 1920 || year > 2100)
    {
        throw std::invalid_argument("year must be between 1920 and 2100.");
    }
    ValidateDay();
    this->day = day;
    this->month = month;
    this->year = year;
}

int TimeDayMonthYear::GetDay() const
{
    return day;
}

int TimeDayMonthYear::GetMonth() const
{
    return month;
}

int TimeDayMonthYear::GetYear() const
{
    return year;
}

void TimeDayMonthYear::SetDay(int day)
{
    if (day < 1)
    {
        throw std::invalid_argument("Day must be between 1 and 31.");
    }
    this->day = day;
    ValidateDay();
}

void TimeDayMonthYear::SetMonth(int month)
{
    if (month < 1 || month > 12)
    {
        throw std::invalid_argument("Month must be between 1 and 12.");
    }
    this->month = month;
    ValidateDay();
}

void TimeDayMonthYear::SetYear(int year)
{
    if (year < 1920 || year > 2100)
    {
        throw std::invalid_argument("Year must be between 1920 and 2100.");
    }
    this->year = year;
    ValidateDay();
}

bool TimeDayMonthYear::IsLeapYear(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int TimeDayMonthYear::DaysInMonth(int year, int month) const
{
    switch (month) 
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return IsLeapYear(year) ? 29 : 28;
    default:
        throw std::invalid_argument("Invalid month.");
    }
}

void TimeDayMonthYear::ValidateDay() 
{
    if (day < 28)
    {
        return;
    }
    int maxDay = DaysInMonth(year, month);
    if (day > maxDay) 
    {
        // Adjust the day to the last valid day of the month
        day = maxDay;
    }
}