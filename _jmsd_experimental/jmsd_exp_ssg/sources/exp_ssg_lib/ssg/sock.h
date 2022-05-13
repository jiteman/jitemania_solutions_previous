#pragma once



#include <winsock.h>
#include <stdio.h>


extern SOCKET my_sock;
extern bool is_online;
extern char sock_init; //0-вне функции InitSockC 1-ожидаем ввода первого игрока 2-успешное завершение 3-неудачное завершение 4-в процессе 5-игрок начал ввод 6-ждём других игроков 7-игрок отменил ввод

extern HANDLE hInitSockThread;
void InitSockProc();
void InitSockC(void*v);
void ClearSock();

/*
#define WM_SOCKET	WM_USER+1	// Socket Windows MyMessage



#include <winsock2.h>
#include <stdio.h>
//#include <st.h>
static char buf[SIZE_OF_POCKET];
BOOL SeeTka(tka&);
static SOCKET s[7];
static sockaddr_in you;	// Server's attributes
void MyDisplay();
struct MyUpdation
{
	tka pos,to;
	char l,pl,tp;
	int id;
    MyUpdation(){}
};
static stek<MyUpdation> mup;

void MakeUpUpUp()
{
	sld*sp;
	int n=-1;///////////////////////////////////////////////// bad
	el<MyUpdation>*tmpp;
	stek<MyUpdation>newmup;
UpdateAgain:
	tmpp=mup.top;
	while(tmpp)
	{
		
		if(n!=-1&&(SeeTka(tmpp->v.pos)||SeeTka((Units+tmpp->v.id)->pos)))
		{newmup.AddEl(tmpp->v);n++;}
		else
		{
		   sp=(Units+tmpp->v.id);
		   sp->pos=tmpp->v.pos;
		   sp->life=tmpp->v.l;
		   sp->pl=tmpp->v.pl;
		   sp->type=tmpp->v.tp;
		   sp->way.renull();
		   sp->way.AddEl(tmpp->v.to);
		}
		tmpp=tmpp->next;
		
	}
	mup.renull();
	mup.top=newmup.top;
	mup.beg=newmup.beg;
	newmup.top=0;
	newmup.beg=0;

	if(n>1000){n=-1;goto UpdateAgain;}

	///
	//tmpp=mup.top;
	//nnnn=0;
	//while(tmpp){nnnn++;tmpp=tmpp->next;}
}*/

/*

BOOL InitSockC()
{

	int error;
	//char buf,buf2;


	// Setup WinSock
	WSADATA w;
	error = WSAStartup (0x0202,&w);
	if (error)
	{
		//MyMessageBox (main_window_handle,"Error: You need WinSock 2.2!","Error",MB_OK);
		mes.AddElToBeg(MyMessage("Ошибка: Нужна версия сокетов: 2.2"));
		//PostQuitMyMessage (0);
		
		return 0;
	}
	if (w.wVersion!=0x0202)
	{
		//MyMessageBox (main_window_handle,"Error:  Wrong WinSock version!","Error",MB_OK);
		mes.AddElToBeg(MyMessage("Ошибка: Не та версия сокетов"));
		//PostQuitMyMessage (0);
		
		WSACleanup ();
		return 0;
	}

	*s = socket (AF_INET,SOCK_STREAM,0); // create socket
	// set default IP address to 127.0.0.1 (localhost)
    char a[]="127.0.0.1                 ";
    
	CFile file;
	if(file.Open("ServerIP.txt",CFile::modeRead|CFile::typeBinary))
	{
		file.Read(a,sizeof(char)*file.GetLength());
		file.Close();
	}
	
	

	// connect to server
	you.sin_family = AF_INET;
	you.sin_port = htons (5555);	// RPSS port is 5555
	you.sin_addr.s_addr = inet_addr (a);
	
	if (connect(*s,(LPSOCKADDR)&you,sizeof(you))==SOCKET_ERROR)
	    if (WSAGetLastError()==WSAEWOULDBLOCK)
		{
		
			connect(*s,(LPSOCKADDR)&you,sizeof(you));
			mes.AddElToBeg(MyMessage("Есть соединение с сервером. Ожидаем остальных игроков..."));
		
		}else
		{
		    //sprintf (txtbuffer,"Error: %d",WSAGetLastError());
						//PostQuitMyMessage (0);
			mes.AddElToBeg(MyMessage("Не удалось соединиться с сервером"));
			return 0;
		}
	mes.AddElToBeg(MyMessage("Ожидаем подключения остальных игроков"));
	MyDisplay();
	SwapBuffers(hDC);
    error = recv (*s,buf,6,0);
	if ((error==0)||(error==INVALID_SOCKET))
	{
			//printf("Error:  Player 1 quit!\n");
		mes.AddElToBeg(MyMessage("Сервер отключился"));
		closesocket (*s);
		WSACleanup ();
		return 0;
	}

	//printf("you:%d ",me);
	
	srand((*((UINT*)(buf+2)))&0xFFFF);

	
    
	MY_PLAYER=buf[0];
	PlNum=buf[1]-1;

	comp=buf[4];
	MapSet=buf[5];
	mes.AddElToBeg(MyMessage("Начнём, пожалуй..."));

	WSAAsyncSelect (*s,hWnd,WM_SOCKET,(FD_CLOSE | FD_CONNECT | FD_READ));
	//PlNum=(int)buf;
	status2=2;
	return 1;

} // end Game_Init
BOOL InitSockS()
{
	SOCKET s0;
	int i=0,plnum1, error;

	
	
	

	sockaddr_in me;
	sockaddr you[7];
	int addr_size = sizeof (sockaddr);
	
	plnum1=PlNum;

//	cout << "Rock, Paper, Scissor, Shoot! Advanced Server\n";
//	cout << "By Stefan Hajnoczi\n\n";
	WSADATA w;
	error = WSAStartup (0x0202,&w);
	if (error)
	{
		mes.AddElToBeg(MyMessage("Ошибка: Нужна версия сокетов: 2.2"));
		return 0;
	}
	if (w.wVersion!=0x0202)
	{
		mes.AddElToBeg(MyMessage("Ошибка: Не та версия сокетов"));
		WSACleanup ();
		return 0;
	}

	s0 = socket (AF_INET,SOCK_STREAM,0);

	


	me.sin_family = AF_INET;
	me.sin_port = htons (5555);
	me.sin_addr.s_addr = htonl (INADDR_ANY);
	if (bind(s0,(LPSOCKADDR)&me,sizeof(me))==SOCKET_ERROR)
	{
		//printf("Error:  Unable to bind socket!\n");
		mes.AddElToBeg(MyMessage("Ошибка: сокет не привязывается:("));
		WSACleanup ();
		return 0;
	}
	if (listen(s0,1)==SOCKET_ERROR)
	{
		mes.AddElToBeg(MyMessage("Ошибка: сокет не прослушивается:("));
		WSACleanup ();
		return 0;
	}
	//printf("\nListening for connections...\n");
	mes.AddElToBeg(MyMessage("Ожидание других игроков"));
	MyDisplay();
	SwapBuffers(hDC);
	   
	
	PlHere=0;
	comp=0;
	while (i<PlNum)
	{
		s[i] = accept (s0,&you[i],&addr_size);

		if (s[i]==INVALID_SOCKET)
		{
			
			mes.AddElToBeg(MyMessage("Ошибка соединения с игроком "+(CString)(char)(i+'0')));
			closesocket(s[i]);
		}
		else
		{
			//printf("Player joined%d!\n",i);
			//char buffer=i+1;
			
			//send (s[i],&buffer,1,0);
			mes.AddElToBeg(MyMessage("Игрок "+(CString)(char)(i+'0')+" подсоединился!"));
			PlHere|=(1<<i);
			i++;
		}
		MyDisplay();
		SwapBuffers(hDC);
	}
	
	mes.AddElToBeg(MyMessage("Начнём, пожалуй..."));
	MyDisplay();
	closesocket (s0);
	for(i=PlNum+1;i<=min(PlNum+cmpNum,7);i++)
		SWITCH_AIHUMAN(i);
	
	buf[1]=PlNum+1;
	buf[2]=(unsigned)time( NULL );
	buf[3]=((unsigned)time( NULL ))>>8;
	buf[4]=comp;
	buf[5]=MapSet;
	srand((*((UINT*)(buf+2)))&0xFFFF);
	
	for(i=0;i<PlNum;i++)
	{
		WSAAsyncSelect (s[i],hWnd,WM_SOCKET+i,(FD_CLOSE | FD_CONNECT | FD_READ));
		buf[0]=i+1;
	   error = send (s[i],buf,6,0);
	   if ((error==0)||(error==SOCKET_ERROR))
	   {
	//	   printf("Error:  Player %d quit!\n",i);

		   mes.AddElToBeg(MyMessage("Игрок "+(CString)(char)(i+'0')+" отключился"));
		   closesocket(s[i]);
		   //WSACleanup ();
		   //return;
	   }
	}
	status2=1;
	return 1;
}

tka pReadTka(char*b)
{
	return tka((float)(0xFFFF&*((UINT*)b))*((float)(FIELDSIZEX*KLET_SIZE)/65535.0f),(float)(0xFFFF&*((UINT*)(b+2)))*((float)(FIELDSIZEY*KLET_SIZE)/65535.0f));
}
void pReadSelectU(char *b,st<int>*sl)
{
	char tmpc;
	int i,i1=*((int*)(b))&0xFFFF,i2=*((int*)(b+2))&0xFFFF,j,cn;
	b+=4;
	cn=i1*8;
	for(i=i1;i<=i2;i++)
	{
		tmpc=1;
		
		if(*b)
		for(j=0;j<8;j++)
		{
			if((*b)&tmpc){	sl->AddEl(cn);}
			
			cn++;
			tmpc=tmpc<<1;
		}else cn+=8;
		b++;
	}

}
void pReadSendU(char *b)
{
	char pl=*b&7;
	tka a=pReadTka(b+1),t=pReadTka(b+5);
	st<int>sl; 

	pReadSelectU(b+9,&sl);
	
	
	SendUnits(&sl,sl.GetNum(),a.x,a.y,t.x,t.y);

}

void pReadssU(char *b)
{
	char pl=*b&7,filt=b[1];
	
	st<int>sl; 
	el<int>*ttt;

	pReadSelectU(b+2,&sl);
	ttt=sl.beg;
	
	while(ttt)
	{
		(Units+ttt->v)->pl&=~(8+16);
		(Units+ttt->v)->pl|=filt;
			
			
		ttt=ttt->next;
	}
	

}

void pReadBSending(char*b)
{
	
	int n=b[5],i;
	tka a=pReadTka(b+1);
	b+=6;
	for(i=0;i<n;i++)
	{
		(Bases+*b)->send=a;
		b++;
	}
}


void pWriteTka(char*b,tka t)
{
	float tmp=t.x;
	UINT tmpi;
	if(tmp<0)tmpi=0;else if(tmp>=FIELDSIZEX*KLET_SIZE) tmpi=65535;else 
		tmpi=(UINT)(tmp*(65535.0f/(float)(FIELDSIZEX*KLET_SIZE)));
	*((UINT*)b)=tmpi;
	tmp=t.y;
	if(tmp<0)tmpi=0;else if(tmp>=FIELDSIZEY*KLET_SIZE) tmpi=65535;else 
		tmpi=(UINT)(tmp*((float)65535.0f/(float)(FIELDSIZEX*KLET_SIZE)));
	*((UINT*)(b+2))=tmpi;
	
}
int pWriteUSel(char*b,int may_fill)
{
	char *tmpa=(char*)calloc(MAXSLD/8,1);
	int i,i2=0,i1=MAXSLD;
	el<int>*tmpt=sel.beg;
	
	while(tmpt)
	{
		i=tmpt->v;
		if(i<i1)i1=i;
		if(i>i2)i2=i;
		tmpa[i/8]|=(1<<(i%8));
		tmpt=tmpt->next;
	}
	
	i1/=8;
	i2=i2/8+(i2%8!=0);
	
	*((int*)b)=i1;
	*((int*)(b+2))=i2;
	b+=4;
	for(i=i1;i<=i2;i++)
	{
	
		*b=tmpa[i];
		b++;
		
	}
	


	delete[]tmpa;
	return i2-i1+5;


}

void pWriteBSel(char*b)
{
	el<int>*tmpt=sel.beg;
	*b=sel.GetNum();
	
	while(tmpt)
	{
		b++;
		*b=tmpt->v;
		tmpt=tmpt->next;
	}
}

int pWriteUpdateU(char*b)
{
	static char startU=0;
	int i,ty=0;
	tka ttt;
	sld*s;
	*b=STR_UPDATE_UNITS;
	b[1]=startU;
	s=Units+startU*UPDATE_UN_NUM;
	b++;
	for(i=0;i<UPDATE_UN_NUM;i++)
	{
		b++;
		*b=s->life;
		if(s->life)
		{
			b[1]=s->type;
			b[2]=s->pl;
			if(s->way.beg)ttt=s->way.beg->v;else ttt=s->pos;
			pWriteTka(b+3,s->pos);
			pWriteTka(b+7,ttt);
			b+=10;

		}else ty++;
		s++;
	}

//	b++;
//	*((UINT*)(b))=GameTime;
	startU++;
	if(startU==MAXSLD/UPDATE_UN_NUM)startU=0;
	return 11*UPDATE_UN_NUM-10*ty+2;
}


void pWriteUpdateB(char*b)
{
	int i;
	*b=STR_UPDATE_BASES;
	b++;
	for(i=0;i<BasesNum;i++)
	{
		
		b[0]=(Bases+i)->pl;
		pWriteTka(b+1,(Bases+i)->send);
		
		b[5]=(Bases+i)->med;
		b[6]=*(Bases+i)->inf;
		b+=7;
	}

	*((UINT*)(b))=GameTime;
}

void UpdateSelection()
{
	el<int>*tmp=sel.beg;
	st<int>tmpst;
	BOOL f=0;
	while(tmp)
	{
		if((Units+tmp->v)->life)tmpst.AddEl(tmp->v);else f=1;
		tmp=tmp->next;
	}
	if(f)
	{
		sel.renull();
		sel.beg=tmpst.beg;
		tmpst.beg=0;
	}

}

void pReadUpdateU(char*b)
{
	int i,id;
	tka ttt;
	
	MyUpdation tmpu;
	id=b[1]*UPDATE_UN_NUM;
	//CString ss;	ss.Format("Update %d",b[1]);	mes.AddElToBeg(ss);
	b++;
	for(i=0;i<UPDATE_UN_NUM;i++)
	{
		b++;
		tmpu.l=*b;
		tmpu.id=id;
		id++;
		if(*b)
		{
			tmpu.tp=b[1];
			tmpu.pl=b[2];
			tmpu.pos=pReadTka(b+3);
			tmpu.to=pReadTka(b+7);
			b+=10;

		}
		mup.AddElToBeg(tmpu);
	}
	
	//GameTime=(*((UINT*)(b)))&0xFFFF;
	UpdateSelection();
}

void pReadUpdateB(char*b)
{
    int i;
	
	
	b++;
	for(i=0;i<BasesNum;i++)
	{
		
		(Bases+i)->pl=b[0];
		(Bases+i)->send=pReadTka(b+1);
		
		(Bases+i)->med=b[5];
		*(Bases+i)->inf=b[6];
		b+=7;
	}	
	GameTime=(*((UINT*)(b)))&0xFFFF;
}


void SendUpdation()
{
	int nnn,id;
	if(GameTime%(14*GAME_UPDATE_TIME))
	      nnn=pWriteUpdateU(buf);
	 else
	   {nnn=BasesNum*7+3;pWriteUpdateB(buf);}
	for(id=0;id<PlNum;id++)
	   if(PlHere&(1<<id))
	         send(s[id],buf,nnn,0);
}
void pReadTextMessage(char*buf)
{
	CString sss="Игрок ";
	char cl=POCKET_PLAYER(buf);
	buf++;
	sss+=(CString)(char)('0'+cl);
	sss+=": ";
	do
	{
		sss+=(CString)*buf;
		buf++;
	}
	while(*buf);
	mes.AddElToBeg(MyMessage(sss,cl));

}
*/
