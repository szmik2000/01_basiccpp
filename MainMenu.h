#pragma once

#include "TimeTableManager.h"

class MainMenu
{
public:
	MainMenu(TimeTableManager timeTableManager) : mTimeTableManager(timeTableManager) {}
	void OpenMainMenu();
private:
	void AddToTimetable();
	TimeTableManager& mTimeTableManager;
	
};

