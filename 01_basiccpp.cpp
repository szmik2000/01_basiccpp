#include "LocalSave.h"
#include "MainMenu.h"

int main()
{
    LocalSave::Load();
    TimeTableManager timeTableManager;
    MainMenu mainMenu(timeTableManager);
    mainMenu.OpenMainMenu();
}
