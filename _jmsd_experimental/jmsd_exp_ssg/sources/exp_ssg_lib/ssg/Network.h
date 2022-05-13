#pragma once


#define NET_TIME 20


struct Order;
struct ServerMessage
{
	short net_time;
	char prm1;

};
struct ClientMessage
{
	char prm;// 1& -были тормоза сети
	int game_summ;
};

extern ServerMessage ServParams;
extern ClientMessage ClientParams,ClientParamsTMP;
extern short net_time,net_cnt;


void PrepareClientMessage();

void SendOrders();

void MakeDataExchange();
void DoOrder(Order** ord);
