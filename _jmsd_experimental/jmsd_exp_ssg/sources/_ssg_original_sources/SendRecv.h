#pragma once


extern bool pock_exch_is;

void PocketExchange(void*v);

void MySend(char* bf,int num);
void MyRecv(char* bf,int num);
void SendPocket(char* bf,int num);
int RecvPocket(char* bf);
char* RecvPocket(int* num=0);
