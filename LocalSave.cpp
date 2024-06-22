#include "LocalSave.h"
#include "shlobj_core.h"
#include <filesystem>
#include <stdio.h>
#include "Resource.h"


#include <iostream>
std::wstring g_fullAppDataPath;
std::wstring g_fullTimeTablePath;
std::wstring g_fullConfigPath;

LocalSave::SaveStates LocalSave::Load()
{
    wchar_t appDataPath[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, appDataPath);
    g_fullAppDataPath = appDataPath + Resource::filePathDelimiter + Resource::mainProgramName;
    g_fullTimeTablePath = g_fullAppDataPath + Resource::filePathDelimiter + Resource::timeTableFileName;
    g_fullConfigPath = g_fullAppDataPath + Resource::filePathDelimiter + Resource::configFileName;
    std::filesystem::create_directories(g_fullAppDataPath);

    FILE* configFile;
    _wfopen_s(&configFile, g_fullTimeTablePath.c_str(), L"w");
    if (configFile != NULL)
    {
        fclose(configFile);
        return SaveStates::FOUND_LOADED;
    }
    return SaveStates::NOT_FOUND_ERROR;
}
