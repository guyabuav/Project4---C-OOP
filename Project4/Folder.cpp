#define _CRT_SECURE_NO_WARNINGS
#include "Folder.h"

Folder Folder::folder = Folder("MainFolder", "root");

Folder::Folder(string FileName, string path):AD_File(FileName), path(path), DF(NULL), Fold(NULL) {
	this->NumOfFold = 0;
	this->NumofDf = 0;
};

Folder::Folder() :AD_File(" "), path(" "), DF(NULL), Fold(NULL) {
	this->NumOfFold = 0;
	this->NumofDf = 0;
}


string Folder::getFullPath() {
	string temp = this->path;
	temp.operator+=("/");
	temp.append(this->getFileName());
	return temp;
}

void Folder::addFileToArray(const DataFile& df)throw(string) {
	for (int i = 0; i < this->NumofDf; i++) {
		if (this->DF[i]->DataFile::operator==(df)) {
			string s = "This DataFile is Already Exist!";
			throw s;
		}
		}
		if (this->NumofDf == 0) {
			this->DF = new DataFile*;
			this->DF[NumofDf] = new DataFile();
			*this->DF[NumofDf] = df;
		}
		else {
			DataFile* Temparr;
			Temparr = new DataFile[NumofDf];
			for (int i = 0; i < NumofDf; i++) { // Copy old arr to the new arr with more size (+1)
				Temparr[i] = *this->DF[i];
				delete this->DF[i];
			}
			delete[] this->DF; // Delete old arr
			this->DF = new DataFile * [NumofDf + 1];

			for (int i = 0; i < NumofDf; i++) {
				DF[i] = new DataFile();
				*DF[i] = Temparr[i];
			}
			DF[NumofDf] = new DataFile();
			*DF[NumofDf] = df;
			delete[] Temparr;
	}
	NumofDf++;
}
	


void Folder::addFileToArray(const Folder& fold)throw(string) {
	for (int i = 0; i < this->NumOfFold; i++) {
		if (this->Fold[i]->operator==(fold) && this->Fold[i]->path == fold.path) {
			string s = "This Folder is Already Exist!";
			throw s;
		}
	}
	if (this->NumOfFold == 0) {
		this->Fold = new Folder *;
		this->Fold[NumOfFold] = new Folder();
		*this->Fold[NumOfFold] = fold;
	}
	else {
		Folder* Temparr;
		Temparr = new Folder[NumOfFold];
		for (int i = 0; i < NumOfFold; i++) { // Copy old arr to the new arr with more size (+1)
			Temparr[i] = *this->Fold[i];
			delete this->Fold[i];
		}
		delete[] this->Fold; // Delete old arr
		this->Fold = new Folder * [NumOfFold + 1];

		for (int i = 0; i < NumOfFold; i++) {
			Fold[i] = new Folder();
			*Fold[i] = Temparr[i];
		}
		Fold[NumOfFold] = new Folder();
		*Fold[NumOfFold] = fold;
		delete[] Temparr;
	}
	NumOfFold++;
}

	

Folder::Folder(const Folder& fold)throw(string){
	string temp = "No copy constructor - cant save 2 folders in same path";
	throw temp;
	return;
}

Folder::Folder(const Folder& fold, string path) :path(path) {
		*this = fold;
}

void Folder::mkfile(string NameOfFile, string FileData) {
	DataFile* Tempfile = new DataFile(NameOfFile, FileData);
	this->addFileToArray(*Tempfile);
}

void Folder::mkDir(string FolderName) {
	Folder* Tempfold = new Folder(FolderName, this->path);
	this->addFileToArray(*Tempfold);
}

void Folder::dir() {
	for (int i = 0; i < this->folder.NumofDf; i++) {
		cout << this->folder.DF[i]->getTime() << " " << this->folder.DF[i]->getSize()<< " " << "KB" << " " << this->folder.DF[i]->getFileName() << endl;
	}
	for (int j = 0; j < this->folder.NumOfFold; j++) {
		cout << this->folder.Fold[j]->getTime() << " " << "<DIR>" << " " << this->folder.Fold[j]->getFullPath() << endl;
	}
}
	

const Folder& Folder::operator=(const Folder& newfolder)
{
	if (&newfolder == this) return *this;

	this->setFileName(newfolder.getFileName());
	this->path = newfolder.path;
	this->NumOfFold = newfolder.NumOfFold;
	this->NumofDf = newfolder.NumofDf;

	for (int i = 0; i < this->NumofDf; i++)
		this->DF[i] = NULL;
		this->DF = NULL;

		for (int i = 0; i < this->NumOfFold; i++)
			this->Fold[i] = NULL;
			this->Fold = NULL;

	this->DF = new DataFile * [newfolder.NumofDf];
	this->Fold = new Folder * [newfolder.NumOfFold];

	for (int i = 0; i < newfolder.NumofDf; i++) {
		this->DF[i] = new DataFile();
		*(this->DF[i]) = *(newfolder.DF[i]);
	}

	for (int i = 0; i < newfolder.NumOfFold; i++) {
		this->Fold[i] = new Folder();
		*(this->Fold[i]) = *(newfolder.Fold[i]);
	}
}

Folder Folder::cd(string path) {
	string s = (path.substr(path.find_last_of("/\\") + 1));
	for (int i = 0; i < this->folder.NumOfFold; i++) {
		if (this->folder.Fold[i]->getFileName() == s) return *this->folder.Fold[i];
	}

}


