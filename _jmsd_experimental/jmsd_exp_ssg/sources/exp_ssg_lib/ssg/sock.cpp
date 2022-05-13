#include "sock.h"

#include "GUI.h"
#include "Filer.h"
#include "Game.h"
#include "SendRecv.h"
#include "Wid.h"
#include "Network.h"

#include <process.h>


HANDLE hInitSockThread=0;

SOCKET my_sock;
bool is_online=0,waiting_for_first_player=0;
char sock_init=0;
// #pragma comment(lib,"Ws2_32.lib")

void ClearSock()
{
	if(!is_online)return;
	is_online=false;
	global_onScreenMessages.AddElToBeg(MyMessage(LSTRING("Connection break","Соединение прервано")));

	closesocket(my_sock);
	WSACleanup ();
}

void InitSockC( void * /*v*/ )
{
	int error;
	// Setup WinSock
	WSADATA w;
	sockaddr_in you;
	sock_init=4;

    char a[]="127.0.0.1                 ";

	CFile file;
	if(file.Open("ServerIP.txt",OPEN_EXISTING))
	{
		file.Read(a,file.GetLength());
		file.Close();
	}else
	{
		global_onScreenMessages.AddElToBeg(MyMessage(LSTRING("ServerIP.txt didn't found.","ServerIP.txt не найден.")));
		sock_init=3;
		_endthread();
	}

	//mes.AddElToBeg(MyMessage("Запрос к серверу"));
	ClearSock();
	error = WSAStartup (0x0202,&w);
	if (error)
	{
		global_onScreenMessages.AddElToBeg(MyMessage(LSTRING("Error: need for 2.2 socket version","Ошибка: Нужна версия сокетов: 2.2")));
		sock_init=3;
		_endthread();
	}
	if (w.wVersion!=0x0202)
	{
		global_onScreenMessages.AddElToBeg(MyMessage(LSTRING("Error: wrong socket version","Ошибка: Не та версия сокетов")));
		WSACleanup ();
		sock_init=3;
		_endthread();
	}

	my_sock = socket (AF_INET,SOCK_STREAM,0); // create socket




	// connect to server
	you.sin_family = AF_INET;
	you.sin_port = htons (5555);	// RPSS port is 5555
	you.sin_addr.s_addr = inet_addr (a);

	if (connect(my_sock,(LPSOCKADDR)&you,sizeof(you))==SOCKET_ERROR)
	    if (WSAGetLastError()==WSAEWOULDBLOCK)
		{

			connect(my_sock,(LPSOCKADDR)&you,sizeof(you));
			//mes.AddElToBeg(MyMessage("Есть соединение с сервером."));

		}else
		{
			global_onScreenMessages.AddElToBeg(MyMessage(LSTRING("Unable to connect to server","Не удалось соединиться с сервером")));
			sock_init=3;
			_endthread();

		}
	//mes.AddElToBeg(MyMessage("Ожидаем подключения остальных игроков"));

	is_online=true;
//	MyDisplay();
//	SwapBuffers(hDC);


	sock_init=6;
	if(!RecvPocket((char*)&nGameParams))
	{
		sock_init=1;
		while(sock_init==1 || sock_init==5)
			Sleep(500);
		if(sock_init==7){sock_init=3;ClearSock();_endthread();}
		nGameParams.Store();
		MySend((char*)&nGameParams,sizeof(nGameParams));
		sock_init=6;
		RecvPocket((char*)&nGameParams);
	}



//	char ccc;	RecvPocket(&ccc);



	if(is_online)
	{
		sock_init=2;
	}else
		sock_init=3;

	_endthread();
}
void InitSockProc()
{
	switch(sock_init)
	{
	case 1:
		sock_init=5;
		GoToWDJ(2);
		break;
	case 2:
		sock_init=0;
		net_time=NET_TIME;
		NewGame();GoToWDJ(-1);status&=~16;
		break;
	case 3:
		sock_init=0;
		GoToWDJ(-2);
		break;
	case 6:
		GetWDJ(9)->text=LSTRING("Waiting for other players...","Ждём других игроков...");
		sock_init=4;
		break;
	}
}
