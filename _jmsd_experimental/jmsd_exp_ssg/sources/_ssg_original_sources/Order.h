#pragma once


#include "st.h"
#include "myfuns.h"


class Pocket;

struct Order
{

	char type, prm,pl,prm2;
	//type: 
		//0-SendU prm=add
		//1-SendB 
		//2-SendG prm=add
		//3-SetU prm: 0-group   1-Del 2-status(prm2=filter)
		//4-SetG prm: 0-ungroup 1-Del 2-status(prm2=filter)
		//5-PlAction prm:  0-GlobalGroup 1-TryBuildUnits

	st<int> sl;
	tka pos, nav;
	
	void SetDefault();
	Order(){SetDefault();}
	Order(Pocket& pc);
	Order(char ntype,st<int>*nsl,tka t1,tka t2,char nprm);
	Order(char ntype,st<int>*nsl,char nprm,char nprm2=0);
	Order(char ntype,char nprm,char nprm2=0);
	
	
	void Pack(Pocket& pc);
	void UnPack(Pocket& pc);
};

class OrderManager
{
public:
	char cur_ord;
	stek<Order*> ord_in;
	stek<Order*> ord_out[2];

	OrderManager();
	//void DoOrdIn();
	void DoOrdOut();
	void DoOrders();
	void renull();

	void SwapOut();
	void AddOrder(Order* nord);
	bool RecvOrders();

};

extern OrderManager global_OrdMan;

void SetStatusU(st<int>*sl,char prm,char prm2);
void SetStatusG(st<int>*sl,char prm,char prm2);
