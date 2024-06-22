#include "LocalSave.h"
#include "MainMenu.h"
#include <iostream>

extern std::wstring g_fullAppDataPath;

int main()
{
    LocalSave::Load();
    std::wcout << L"XXXXXXXXXXXXXXXXXXXXXXXXX\n\n\n" << g_fullAppDataPath << L"XXXXXXXXXXXXXXXXXXXXXXXXX\n\n\n";
    MainMenu::OpenMainMenu();
    

    
}
