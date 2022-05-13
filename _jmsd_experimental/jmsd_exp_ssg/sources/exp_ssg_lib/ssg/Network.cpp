#include "NetWork.h"

#include "Order.h"
#include "Control.h"
#include "Bases.h"
#include "Packer.h"
#include "SendRecv.h"
#include "Zamer.h"
#include "SafeFloat.h"

#include <process.h>


short net_time, net_cnt;
ServerMessage ServParams;
ClientMessage ClientParams, ClientParamsTMP;//ClientParams-это будет отправлено серверу    ClientParamsTMP-это заполняем по ходу игры и копируем перед отправкой в первую структуру


void DoOrder(Order** ord)
{
//	Pocket pc;
//	(*ord)->Pack(pc);
//	Order ooo(pc),*oooo=(*ord);
//	(*ord)=&ooo;

	switch((*ord)->type)
	{
		case 0:
			SendUnits(&(*ord)->sl,(*ord)->sl.GetNum(),(*ord)->pos,(*ord)->nav,(*ord)->prm != 0, 2, 4);
			break;
		case 1:
			SetBasesSend(&(*ord)->sl,(*ord)->pos);
			break;
		case 2:
			SendGroups(&(*ord)->sl,(*ord)->pos,(*ord)->nav,(*ord)->prm != 0 );
			break;
		case 3:
			SetStatusU(&(*ord)->sl,(*ord)->prm,(*ord)->prm2);
			break;
		case 4:
			SetStatusG(&(*ord)->sl,(*ord)->prm,(*ord)->prm2);
			break;
		case 5:
			DoPlAction(*ord);
			break;
	}
//	(*ord)=oooo;

	(*ord)->sl.renull();
	delete *ord;
	*ord=0;
}

void SendOrders()
{
	Pocket pc(sizeof(int),500);
	el<Order*>*tmp=global_OrdMan.ord_out[!global_OrdMan.cur_ord].top;

	pc.PushBack(ClientParams);

	while(tmp)
	{
		tmp->v->Pack(pc);
		tmp=tmp->next;
	}
	pc.PushFront(pc.GetNum());

	MySend(pc.GetBytes(),pc.GetNum());
	//OrdMan.ord.renull();
}
void MakeDataExchange()
{
//	RecvOrders();
//	SendOrders();
//	RecvOrders();
	BB(28);
	global_OrdMan.DoOrders();


	global_OrdMan.SwapOut();
	BB1(28);


	_beginthread(PocketExchange,0,0);

}
//обрабатываем сообщение от сервера + готовим окончательное сообщение клиента
void PrepareClientMessage()
{
	net_time=ServParams.net_time;

	switch(ServParams.prm1)
	{
	case 0:ClientParamsTMP.game_summ=SafeGame(0,1000);
		break;
	case 1:ClientParamsTMP.game_summ=SafeGame(1,2);
		break;
	case 2:SendGameContent();
		break;
	case 3:RecvGameContent();
		break;

	}

	//////
	memcpy(&ClientParams,&ClientParamsTMP,sizeof(ClientParams));
	ClientParamsTMP.prm=0;
}
