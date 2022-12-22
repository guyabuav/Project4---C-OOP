#pragma once
#include "DataFile.h"

class Folder : public AD_File
{


public:
	DataFile** DF;
	Folder** Fold;
	string path;
	static Folder folder;
	int NumofDf;
	int NumOfFold;
	Folder(string FileName, string path);
	Folder();
	const Folder& operator=(const Folder& newfolder); // operator = constructor
	string getFullPath();
	void addFileToArray(const DataFile& df)throw(string);
	void addFileToArray(const Folder& fold)throw(string);
	Folder(const Folder& fold)throw(string);
	Folder(const Folder& fold, string path);
	void mkfile(string NameOfFile, string FileData);
	void mkDir(string FolderName);
	void dir();
	Folder cd(string path);
	string recursive(string path);

};