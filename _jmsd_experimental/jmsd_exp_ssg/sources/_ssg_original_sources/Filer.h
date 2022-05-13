#pragma once


#include "temporary_windows_include.h"

#include "jmsf/stdal/stdal_stl.h"


class CFile
{
private:
	HANDLE hfile;
public:
	DWORD Read(LPVOID buf, DWORD num);
	DWORD Write(LPVOID buf, DWORD num);
	DWORD GetLength();
	bool Open(std::string fn,DWORD type);
	CFile(){hfile=0;}
	CFile(std::string fn,DWORD type);
	void Close();
};

bool LoadGame(std::string fn);
void SaveGame(std::string fn);


void SaveSetings();
void LoadSetings();

/*
void StoW(std::wstring &dest, const std::string &src);
std::wstring StoW(const std::string &src);
void WtoS(std::string &dest, const std::wstring &src);
std::string WtoS(const std::wstring &src);
*/

void GetFiles(std::string& res, std::string type);
