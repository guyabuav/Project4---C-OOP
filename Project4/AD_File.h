#pragma once
#include <string>
#include <iostream>
#include <ctime>
#pragma warning( disable : 4290 )

using namespace std;

class AD_File
{
	string FileName;
	tm* lastUpadateTime;

public:	
	string getFileName() const { return this->FileName; }
	void setFileName(string FileName)throw(string);
	void setTime();
	string getTime()const;
	AD_File(string FileName); // Constructor
	AD_File(); // Empty Constuctor
	bool operator==(const AD_File &file);

};

