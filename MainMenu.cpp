#include "MainMenu.h"

#include <iostream>

void MainMenu::OpenMainMenu()
{
    mTimeTableManager.parseTimeTable();
    std::cout << "Welcome to your sweet time tracking device!\n";
    while (true) 
    {
        std::cout << "\n\n-----------------------------------------------------\n";
        std::cout << "\nDo you want to check your timetable? - Press \"1\"\n";
        std::cout << "Do you want to edit your timetable? - Press \"2\"\n";
        std::cout << "Exit - Press \"0\"\n";
        std::cout << "MAKE YOUR CHOICE!     -   ";

        int chosen;
        std::cin >> chosen;

        switch (chosen)
        {
        case 0:
            return;
        case 1:
            mTimeTableManager.writeTimeTable();
        case 2:
            AddToTimetable();
        default:
            break;
        }
    }
}

void MainMenu::AddToTimetable()
{
}
