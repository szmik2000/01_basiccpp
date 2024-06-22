#include "LocalSave.h"
#include "shlobj_core.h"
#include <filesystem>
#include <stdio.h>
#include "Resource.h"


#include <iostream>
std::wstring g_fullAppDataPath;
std::wstring g_fullConfigPath;

LocalSave::SaveStates LocalSave::Load()
{
    wchar_t path[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path);
    g_fullAppDataPath = path + Resource::filePathDelimiter + Resource::mainProgramName;
    g_fullConfigPath = g_fullAppDataPath + Resource::filePathDelimiter + Resource::configFileName;
    if (!std::filesystem::create_directories(g_fullAppDataPath))
    {
        //return SaveStates::FOUND_LOADED;
    }

    FILE* configFile;
    std::cout <<_wfopen_s(&configFile, g_fullConfigPath.c_str(), L"w");
    if (configFile != NULL)
    {
        fclose(configFile);
    }
    return SaveStates::NOT_FOUND_CREATED;
}
