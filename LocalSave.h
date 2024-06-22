#pragma once

#include <string>

class LocalSave
{
	
public:	
	enum class SaveStates
	{
		NOT_FOUND_CREATED,
		NOT_FOUND_ERROR,
		FOUND_LOADED,
		FOUND_ERROR
	};
	static SaveStates Load();
};

