#include "LocalSave.h"
#include "shlobj_core.h"
#include <string>

#include <iostream>

LocalSave::SaveStates LocalSave::Load()
{
    wchar_t path[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path);

    std::wcout << L"PLACEHOLDER";
    std::wcout << path;
    std::wcout << L"PLACEHOLDER";

    return SaveStates::FOUND_LOADED;
}
