#pragma once
#include "AD_File.h"

class DataFile : public AD_File
{
public:
	string Data;
	DataFile(string FileName, string Data);
	DataFile();
	bool operator==(const DataFile& file);
	int getSize();
};

