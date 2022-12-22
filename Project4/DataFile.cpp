#define _CRT_SECURE_NO_WARNINGS
#include "DataFile.h"

DataFile::DataFile(string FileName, string Data) :AD_File(FileName), Data(Data) {}
DataFile::DataFile() :AD_File("RandomFileName"), Data(" ") {};


bool DataFile::operator==(const DataFile& file) {
	return (this->AD_File::operator==(file) || this->Data== file.Data);
	// Return 0 if both Name and Data is different
}

int DataFile::getSize() {
	return int(this->Data.size()); 
	// Return size of data in Bytes
}

