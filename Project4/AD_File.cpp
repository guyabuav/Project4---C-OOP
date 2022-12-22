#define _CRT_SECURE_NO_WARNINGS
#include "AD_File.h"


void AD_File::setFileName(string FileName) throw(string)
{
	if (empty(FileName)) {
		this->FileName = "RandomName";
		// How to give index for the name? where i need to put the static int definition?
	}
	else {
		string ForbiddenTavs = "/\\:*?><|";
		size_t Checker = (FileName.find_first_of(ForbiddenTavs));
		if (Checker != string::npos) { //  If occurence founded
			string s = "A file name cant conatin any of the following  characters  \\ : * ? < > |";
			throw s;
		}
		this->FileName = FileName;
	}
}

void AD_File::setTime()
{ //current date/time based on current system
	time_t now = time(0);
	this->lastUpadateTime = localtime(&now);
}




string AD_File::getTime() const {
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", lastUpadateTime);
	return buf;
}

AD_File::AD_File(string FileName) { // Constructor 
	this->setFileName(FileName);
	this->setTime();
}

bool AD_File::operator==(const AD_File& file) { // Compare between 2 Files Name 
	return (this->FileName == file.FileName);
}

AD_File::AD_File():FileName("Random_AD_FileName") { // Empty constuctor
	this->setTime();
}; 

