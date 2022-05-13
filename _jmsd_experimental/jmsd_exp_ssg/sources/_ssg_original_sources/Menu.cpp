#include "Menu.h"

#include "Control.h"
#include "Units.h"
#include "GUI.h"
#include "Game.h"
#include "Group.h"

#include "st.h"


std::string IntToString(int i)
{
	char buf[6];
	_itoa_s(i,buf,6,10);
	return std::string(buf);
}

bool ActMenu( const bool bt ) {
    int i;
	int ct = 0;
	el< int > *ttt = sel.beg;
	el< int > *ttt1 = GrpSel.beg;
	st< int >nsel;
	char filter;
	char plpl;
	int tp[ UNIT_TYPES ];
	el< int > *tmp = GrpSel.beg;
//	sld* sldp;
//	base* bp;
	i = global_onScreenMessages.GetNum();

	if(!Building)
		if(MouseOnButton(ICON_RAMA,ICON_RAMA,130,ICON_SIZE/2))
			global_OrdMan.AddOrder(new Order(5,1));

	if ( ::MouseOnButton( MES_BOX_X, ( float )( MES_BOX_Y - MES_TXT_STEP * i ), MES_BOX_W, ( float )( MES_TXT_STEP * i ) ) ) {
		global_onScreenMessages.renull();
		return true;
	}

	for(i=0;i<UNIT_TYPES;i++)
		if(SelInfo[i]){tp[ct]=i;ct++;}
	
	/*
	{
		if(!sel.beg)return false;

		if(mPos.x<ICON_RAMA+BASE_STATES_NUM*ICON_SIZE && mPos.x>ICON_RAMA && mPos.y<HEIGHT-ICON_RAMA && mPos.y>HEIGHT-ICON_RAMA-ICON_SIZE )
		{
		
			//plpl=(Bases+ttt->v)->status;
		
			//filter=((1<<(int)((mPos.x-ICON_RAMA)/ICON_SIZE)))^plpl;
			filter=(int)((mPos.x-ICON_RAMA)/ICON_SIZE);
	
			while(ttt)
			{
				bp=(Bases+ttt->v);
				bp->MakeAction(filter);
				ttt=ttt->next;
			}
			return true;
		}
		return false;
	
	}	
	*/

	if(sel.beg)
	if(MouseOnButton((float)(WIDTH-ICON_RAMA-ICON_SIZE*(ct+1)),(float)(HEIGHT-ICON_SIZE-ICON_RAMA+ICON_SIZE/4),ICON_SIZE/2,ICON_SIZE/2))
	{
		global_OrdMan.AddOrder(new Order(3,&sel,0));
		return true;
	}
	

	if(!ct && !GrpSel.beg)return false;
	if(ct)
	if(mPos.x<WIDTH-ICON_RAMA && mPos.x>WIDTH-ICON_RAMA-ICON_SIZE*(ct+1) && mPos.y<HEIGHT-ICON_RAMA && mPos.y>HEIGHT-ICON_RAMA-ICON_SIZE )
	{
		filter=(char)((WIDTH-ICON_RAMA-mPos.x)/ICON_SIZE);
		if(filter<0||filter>=UNIT_TYPES)filter=0;
		filter=tp[filter];
		filter=MyPow2(filter);
		if(bt)filter=~filter;else GrpSel.renull();
    	for(i=0;i<UNIT_TYPES;i++)
	  	   SelInfo[i]=0;
		
		while(ttt)
		{
			
			if((MyPow2((Units+ttt->v)->type)&filter)){nsel.AddEl(ttt->v);SelInfo[(Units+ttt->v)->type]++;}
			ttt=ttt->next;
		}
		
		sel.renull();
		sel.beg=nsel.beg;
		nsel.beg=0;
		
		return true;

	}
	ct=GrpSel.GetNum();
	if(ct)
	{
	if(MouseOnButton((float)(WIDTH-ICON_RAMA-ICON_SIZE*(ct+1)),(float)(HEIGHT-ICON_SIZE*2-2*ICON_RAMA+ICON_SIZE/4),ICON_SIZE/2,ICON_SIZE/2))
	{
		global_OrdMan.AddOrder(new Order(4,&GrpSel,0));
		return true;
	}

	if(mPos.x<WIDTH-ICON_RAMA && mPos.x>WIDTH-ICON_RAMA-ICON_SIZE*(ct+1) && mPos.y<HEIGHT-ICON_SIZE-2*ICON_RAMA && mPos.y>HEIGHT-2*ICON_RAMA-2*ICON_SIZE )
	{
		filter=(char)((WIDTH-ICON_RAMA-mPos.x)/ICON_SIZE);
		if(filter<0||filter>=ct)filter=0;
		i=*GrpSel.GetById(filter);
		if(bt)GrpSel.DelEl(i);
		else
		{
			sel.renull();
			GrpSel.renull();
			GrpSel.AddEl(i);
		}
		UpdateSelInfo();
		return true;

	}
	}
	
	if(mPos.x<ICON_RAMA+3*ICON_SIZE && mPos.x>ICON_RAMA && mPos.y<HEIGHT-ICON_RAMA && mPos.y>HEIGHT-ICON_RAMA-ICON_SIZE )
	{
		if(ttt)
			plpl=(Units+ttt->v)->pl;
		else
			plpl=(Units+(global_groups+GrpSel.beg->v)->un.beg->v)->pl;
		filter=((8<<(int)((mPos.x-ICON_RAMA)/ICON_SIZE)))^(plpl&(8+16+32));


		/*
		while(1)
		{
			while(ttt)
			{
				sldp=(Units+ttt->v);
				sldp->pl&=~(8+16+32);
				sldp->pl|=filter;
				ttt=ttt->next;
			}
			if(!ttt1)break;
			ttt=(Grp+ttt1->v)->un.beg;
			ttt1=ttt1->next;
		}*/
		
		if(sel.beg)global_OrdMan.AddOrder(new Order(3,&sel,2,filter));
		if(GrpSel.beg)global_OrdMan.AddOrder(new Order(4,&GrpSel,2,filter));
		return true;
	}
	return false;

}
void SetStatusU(st<int>*sl,char filter)
{
	el<int>* ttt=sl->beg;
	sld*sldp;
	while(ttt)
	{
		sldp=(Units+ttt->v);
		sldp->pl&=~(8+16+32);
		sldp->pl|=filter;
		ttt=ttt->next;
	}

}
void SetStatusG(st<int>*sl,char filter)
{
	el<int>* ttt1=sl->beg;
//	sld*sldp;
	while(ttt1)
	{
		SetStatusU(&(global_groups+ttt1->v)->un,filter);
		ttt1=ttt1->next;
	}

}