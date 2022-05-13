#include "SendRecv.h"

#include "GUI.h"
#include "sock.h"
#include "Zamer.h"
#include "Order.h"
#include "NetWork.h"

#include <process.h>


bool pock_exch_is=false;


void MySend( char *bf, const int num ) {
	int nm;
	int sm = 0;

	if ( !is_online ) return;

	do {
		nm=send(my_sock,bf+sm,num-sm,0);

		if ((nm==0)||(nm==SOCKET_ERROR))
		{
		   //printf("Error send:  Player %d quit!\n",i);
		   //PlayerExit(i);
			global_onScreenMessages.AddElToBeg(MyMessage("Ошибка отправки"));
			ClearSock();
		   return;
		}else sm+=nm;
	}while(sm!=num);
}
void MyRecv(char* bf,int num)
{
	int nm,sm=0;
	if(!is_online)return;
	do
	{
//		Sleep((int)(400*RND01)+520);
		nm=recv(my_sock,bf+sm,num-sm,0);

		if ((nm==0)||(nm==SOCKET_ERROR))
		{
		   //printf("Error recv:  Player %d quit!\n",i);
		   //PlayerExit(i);
			global_onScreenMessages.AddElToBeg(MyMessage("Ошибка получения"));
			ClearSock();
		   return;
		}else sm+=nm;
	}while(sm!=num);
}

void SendPocket(char* bf,int num)
{
	//PackObj(bf,&num);
	MySend((char*)&num,sizeof(num));
	if(num>0)MySend(bf,num);
}
int RecvPocket(char* bf)
{
	int num;
	MyRecv((char*)&num,sizeof(num));
	if(num>0)MyRecv(bf,num);
	if(!is_online)return 0;
	return num;
}

char* RecvPocket(int* num)
{
	int nm;
	char* bf=0;
	MyRecv((char*)&nm,sizeof(nm));
	if(nm>0)
	{
		bf=new char[nm];
		MyRecv(bf,nm);
	}
	*num=nm;
	return bf;
}

void PocketExchange( void * /*v*/)
{
	BB(27);
	pock_exch_is=true;


	while(global_OrdMan.RecvOrders()){}
	SendOrders();
	while(global_OrdMan.RecvOrders()){}


	MyRecv((char*)&ServParams,sizeof(ServParams));

	pock_exch_is=false;
	BB1(27);

	_endthread();
}
