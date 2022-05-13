#pragma once


#include <string>


class CFile;
extern CFile global_file;

void CloseRpt();
void OpenRpt();

void PutChar1(char ch);
void PutString(std::string s);
void PutInt(int i);
void PutDW( unsigned long i );
void PutEnter();
void PutFloat(float val);

void ClearReport();
