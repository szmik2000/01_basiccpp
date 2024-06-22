#include "MainMenu.h"

#include <iostream>

void MainMenu::OpenMainMenu()
{
    std::cout << "Welcome to your sweet time tracking device!\n";
    std::cout << "Do you want to check your timetable? - Press \"1\"\n";
    std::cout << "Do you want to edit your timetable? - Press \"2\"\n";
    std::cout << "MAKE YOUR CHOICE!     -   ";

    int chosen;
    std::cin >> chosen;

    switch (chosen)
    {
    case 1:
        mTimeTableManager.parseTimeTable();
    case 2:
        AddToTimetable();
    default:
        break;
    }
}

void MainMenu::AddToTimetable()
{
}
