#include "MainMenu.h"

#include <iostream>

void MainMenu::OpenMainMenu()
{
    mTimeTableManager.ParseTimeTable();
    std::cout << "Welcome to your sweet time tracking device!\n";
    while (true) 
    {
        std::cout << "\n\n-----------------------------------------------------\n";
        std::cout << "\"1\" - Check your timetable \n";
        std::cout << "\"2\" - Add new day\n"; //TODO: this can be auto generated
        std::cout << "\"3\" - Add new event\n";
        std::cout << "\"4\" - Modify day\n";
        std::cout << "\"5\" - Modify event\n";
        std::cout << "\"0\" - Exit\n";
        std::cout << "MAKE YOUR CHOICE!     -   ";

        int chosen;
        std::cin >> chosen;

        switch (chosen)
        {
        case 0:
            return;
        case 1:
            mTimeTableManager.WriteTimeTable();
            break;
        case 2:
            mTimeTableManager.AddDay();
            break;
        case 2:
            mTimeTableManager.AddEvent();
            break;
        default:
            break;
        }
    }
}
