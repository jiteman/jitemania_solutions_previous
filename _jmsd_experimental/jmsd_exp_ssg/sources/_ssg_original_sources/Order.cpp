#include "Order.h"

#include "Game.h"
#include "Diplomation.h"
#include "Packer.h"
#include "Network.h"
#include "Units.h"
#include "Group.h"
#include "Control.h"
#include "Menu.h"


OrderManager global_OrdMan;

void Order::SetDefault() {
	prm = 0;
	pl = MyConf.MY_PLAYER;
}

Order::Order(char ntype,char nprm,char nprm2)
{
	SetDefault();
	type=ntype;
	prm=nprm;
	prm2=nprm2;
}
Order::Order(Pocket& pc)
{
	SetDefault();
	UnPack(pc);
}

Order::Order(char ntype,st<int>*nsl,char nprm,char nprm2)
{
	SetDefault();
	type=ntype;
	prm=nprm;
	prm2=nprm2;

	AddSortedIntSt(&sl,nsl);	
}

Order::Order(char ntype,st<int>*nsl,tka t1,tka t2,char nprm)
{
	SetDefault();
	type=ntype;
	prm=nprm;
//	CopyElements(&sl,nsl->beg);
//	sl.AddStDBL(nsl->beg);
	AddSortedIntSt(&sl,nsl);
	
	pos=t1;
	nav=t2;
}

void Order::Pack( Pocket &pc ) {
	pc.PushBack(type);
	pc.PushBack(pl);
	
	if(sl.beg)PackSel(pc,&sl);
	if(type<=2)
	{
		pc.PushBack(pos);
		if(type!=1)
		{
			pc.PushBack(nav);
			pc.PushBack(prm);
		}
	}else
	{
		pc.PushBack(prm);
		pc.PushBack(prm2);
	}
	

}
void Order::UnPack(Pocket&pc)
{
	pc.PopFront(type);
	pc.PopFront(pl);
	
	if(type<5)UnPackSel(pc,&sl);
	if(type<=2)
	{
		pc.PopFront(pos);
		if(type!=1)
		{
			pc.PopFront(nav);
			pc.PopFront(prm);
		}
	}else
	{
		pc.PopFront(prm);
		pc.PopFront(prm2);
	}
	

	
}

void OrderManager::AddOrder(Order* nord)
{
	ord_out[cur_ord].AddElToBeg(nord);

}


bool OrderManager::RecvOrders()
{
	Pocket pc;
	pc.Recv();


	if(pc.GetNum())
	{
		do
		{
			ord_in.AddElToBeg(new Order(pc));
		}while(pc.GetNum());
		return true;
	}else
		return false;

	

}
void OrderManager::renull()
{
	ord_in.renull();
	ord_out[0].renull();
	ord_out[1].renull();

}
OrderManager::OrderManager()
{
	cur_ord;
}
void OrderManager::SwapOut()
{
	cur_ord=!cur_ord;
}

void OrderManager::DoOrdOut()
{
	DoForEach( ord_out[ !cur_ord ].top, DoOrder );
	ord_out[!cur_ord].renull();
}
/*
void OrderManager::DoOrdIn()
{
	DoForEach(ord_in.top,DoOrder);
	ord_in.renull();
}
*/
void OrderManager::DoOrders()
{
	int i;
	el<Order*>*tmp;
	if(ord_in.top)ord_in.beg=ord_out[!cur_ord].top;
	else ord_in.top=ord_out[!cur_ord].top;
	
	for(i=0;i<8;i++)
	{
		tmp=ord_in.top;
		while(tmp)
		{
			if(tmp->v)
			if(i==tmp->v->pl)
			{
				DoOrder(&tmp->v);
			}
			tmp=tmp->next;
		}

	}
	ord_in.renull();
	ord_out[!cur_ord].top=0;

}

void DeleteUnit(int* id)
{
	DeleteUnit(*id);
}

void UnGroup( int *id ) {
	Group *gg = global_groups + *id;

	if ( GrpSel.Exists( *id ) ) {
		sel.AddStDBL( gg->un.beg );
	}

	gg->UnGroup();
}

void DeleteGroup(int* id)
{
	Group*gg=(global_groups+*id);
	while(gg->un.beg)DeleteUnit(gg->un.beg->v);
	
}
void SetStatusU(st<int>*sl,char prm,char prm2)
{
	switch(prm)
	{
	case 0:	GroupUnits(sl);
			//UpdateGroups();
			//UpdateSelInfo();
		break;
	case 1:	DoForEach(sl->beg,DeleteUnit);
		break;
	case 2:	SetStatusU(sl,prm2);
		break;
	}
}
void SetStatusG(st<int>*sl,char prm,char prm2)
{
	
	switch(prm)
	{
	case 0:	DoForEach(sl->beg,UnGroup);
			UpdateGroups();
			UpdateSelInfo();
		break;
	case 1:	DoForEach(sl->beg,DeleteGroup);
		break;
	case 2:	SetStatusG(sl,prm2);
		break;
	}
}