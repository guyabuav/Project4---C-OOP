#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DataFile.h"
#include "Folder.h"
#include "AD_File.h"
using namespace std;

int main() {
	//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE); // FOR MEMO LEAKS //
	//_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	//_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	//_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	//_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	Folder* root = &Folder::root;
	Folder* curr = root;
	bool quit = false; string path;
	string command, p_command;
	char echoStream[256];
	do {
		std::cout << curr->getFullPath() << ">";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> command;
		if (command == "cd") {
			try {
				cin.ignore(1);
				cin >> p_command;
				if (p_command == root->getFileName())
					curr = root;
				else curr = Folder::cd(p_command);
			}
			catch (string emsg) {
				cout << emsg << endl;
			};
			continue;
		}
		if (command == "mkdir") {
			try {
				cin.ignore(1);
				cin >> p_command;
				curr->mkDir(p_command);
			}
			catch (string msg) {
				cout << msg << endl;
				cout << "Please try add folder again with correct name" << endl;
			}
			continue;
		}
		if (command == "dir") {
			curr->dir();
			continue;
		}
		if (command == "echo") {
			cin.ignore(1);
			std::cin.getline(echoStream, 256);
			command = echoStream;
			try {
				curr->mkfile(command.substr(0, command.find('<') - 1), command.substr(command.find('<') + 2));
			}
			catch (string msg) {
				cout << msg << endl;
				cout << "Please enter new file name!" << endl;
			};
			continue;
		}
		if (command == "quit") {
			//_CrtDumpMemoryLeaks(); // FOR MEMORY LEAKS //

			cout << "Program ended" << endl;
			exit(0);
		}
	} while (!quit);
	cout << "The end!" << endl;
}
