#pragma once
#include "DataFile.h"
#include <vector>

class Folder : public AD_File
{


public:
	DataFile** DF;
	Folder** Fold;
	string path;
	static Folder root;
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
	static Folder* cd(string path);
	static vector<string> split(string str, char delimiter);

};