#pragma once
//#ifdef _DEBUG // FOR MEMORY LEAKS
//#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
////Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
////allocations to be of _CLIENT_BLOCK type
//#else
//#define DBG_NEW new
//#endif
//#ifdef _DEBUG
//#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#else
//#define new new
//#endif
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
	static Folder* cd(string path)throw (string);
	static vector<string> split(string str, char delimiter);
	~Folder();

};