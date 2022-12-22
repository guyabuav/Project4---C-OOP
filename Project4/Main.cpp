#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DataFile.h"
#include "Folder.h"
#include "AD_File.h"
using namespace std;

// MISSINGS -
// add try&catch for copy constructor of Folder

//Working - 
//AD_File - constructors, set&get functions, throw in setfilename, operator== (ALL WORKING)
//DataFile - constructor, operator ==, getsize, setfilename(throw) (ALL WORKING)
//Folder - constructors, getfilepath, addforarray, mkdir, mkfile, dir //copy con is not working+ cD(?)

int main() {
	bool flag = false;
	while (!flag) {
		try {
			Folder foldertest = Folder(" ", " ");
			string str1, str2, str3, str4, str5, str6, str7, str8, str9, str10, str11, str12;
			cout << "Please enter folder names 1-4" << endl;
			cin >> str1 >> str2 >> str3 >> str4 >> str5;
			cout << "Please enter DataFile names and data 5-8 , 9-12" << endl;
			cin >> str5 >> str6 >> str7 >> str8 >> str9 >> str10 >> str11 >> str12;
			foldertest.folder.mkDir(str1);
			foldertest.folder.mkDir(str2);
			foldertest.folder.mkDir(str3);
			foldertest.folder.mkDir(str4);
			foldertest.folder.mkDir(str5);
			foldertest.folder.mkfile(str5, str6);
			foldertest.folder.mkfile(str7, str8);
			foldertest.folder.mkfile(str9, str10);
			foldertest.folder.mkfile(str11, str12);
			flag = true;
			foldertest.dir();
		}
		catch (string emsg) {
			cout << "Error happened" << endl << emsg << endl;
		}
		if (!flag) {
			cout << "Please try to add different file" << endl;
		}
	}

}

	/*bool flag = false;
	while (!flag) {
		try
		{
			test5.setFileName(stro);
			flag = true;
			cout << test5.getFileName() << endl;
		}
		catch (string emsg)
		{
			cout << "Error happened" << endl << emsg << endl;
		}
		if (!flag) {
			cout << "Please ReEnter your data" << endl;
		}

	}*/

