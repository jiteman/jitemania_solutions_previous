#include "Control.h"

#include "Units.h"
#include "Game.h"
#include "Bases.h"
#include "Group.h"
#include "Graph2d.h"
#include "MainGl.h"
#include "Wid.h"


st<int> sel;
st<int> selB;
st<int> GrpSel;


tka curpos(111,111);// текущий центр экрана
tka omL;//для мышки - хранить коорд. угла прямоугольника
tka omR;//для мышки - задать направление построения //правая кнопка мыши
float dscale=0;

float SCALE=10; 

bool SelIs = false;
bool SelIsR = false;


long MOUSEX() {
	return ( mPos.getX() - WIDTH / 2 ) / SCALE + curpos.getX();
}

long MOUSEY() {
	return ( mPos.getY() - HEIGHT / 2 ) / SCALE + curpos.getY();
}

tka MOUSETKA() {
	return tka( float( mPos.getX() - WIDTH / 2 ), float( mPos.getY() - HEIGHT / 2 ) ) / SCALE + curpos;
}


void SelectArea( tka t1, tka t2, bool addU ) {	
	if ( t1.getX() > t2.getX() ) {
        const float temp = t1.getX();
        t1.setX( t2.getX() );
        t2.setX( temp );
    }
    
//    swap(t1.getX(),t2.getX());

	if ( t1.getY() > t2.getY() ) {
        const float temp = t1.getY();
        t1.setY( t2.getY() );
        t2.setY( temp );
    }

//    swap(t1.getY(),t2.getY());

	int ax=int(t1.getX()-MANSIZE)/KLET_SIZE,bx=int(t2.getX()+MANSIZE)/KLET_SIZE,ay=int(t1.getY()-MANSIZE)/KLET_SIZE,by=int(t2.getY()+MANSIZE)/KLET_SIZE  ,i,j;
	sld*sldp;
	el<int> *ss;
	if(!addU)
	{
		UnSelect();
	}
	
	if(ax<0)ax=0;
	if(ay<0)ay=0;
	if(bx>=MapW)bx=MapW-1;
	if(by>=MapH)by=MapH-1;
	
	for(i=ax;i<=bx;i++)
		for(j=ay;j<=by;j++)
		{
            ss=QUNid[i][j].beg;
			while( ss != nullptr ) {
				sldp=Units+ss->v;
				if(sldp->life && (sldp->pl&7)==MyConf.MY_PLAYER)
					if(sldp->pos.getX()>=t1.getX()-MANSIZE&&sldp->pos.getY()>=t1.getY()-MANSIZE&&sldp->pos.getX()<=t2.getX()+MANSIZE&&sldp->pos.getY()<=t2.getY()+MANSIZE)
					{
						if(sldp->group_id==-1)
						{
							if(sel.AddEl(ss->v))
								SelInfo[sldp->type]++;
						}
						else
							GrpSel.AddEl(sldp->group_id);
					}
				ss=ss->next;
			}
		}
		
}

void SelectAreaB(tka t1,tka t2,bool addU)
{
	int i;
	
	if ( t1.getX() > t2.getX() ) {
        const float temp = t1.getX();
        t1.setX( t2.getX() );
        t2.setX( temp );
    }

//    swap(t1.getX(),t2.getX());

	if ( t1.getY() > t2.getY() ) {
        const float temp = t1.getY();
        t1.setY( t2.getY() );
        t2.setY( temp );
    }
    
//    swap(t1.getY(),t2.getY());

	if(!addU)
	{
		UnSelect();
	}
	for(i=0;i<BasesNum;i++)
		if((Bases+i)->pl==MyConf.MY_PLAYER)
			if((Bases+i)->pos.getX()>t1.getX()&&(Bases+i)->pos.getY()>t1.getY()&&(Bases+i)->pos.getX()<t2.getX()&&(Bases+i)->pos.getY()<t2.getY())
				selB.AddEl(i);
}
void SendGroups(st<int>*gst,tka t1,tka t2,bool add)
{
	el<int> *tmp=gst->beg;
	tka cc, cs,nv=t2-t1;
	bool fl=false;
	Group* gg;
	if(tmp)
	{
		cc=CalcCenterG(gst);
		if(tmp->next)
		{
			if ( !nv.getX() && !nv.getY() ) {
                nv = t2-cc;
                
                if ( !nv.getX() && !nv.getY() )
                    nv.setX( 1 );
            }
			
			gg=(global_groups+tmp->v);
			if(!gg->nav.getX() && !gg->nav.getY())			{	gg->nav=nv;	}

            const CosinusAndSinus cosinusAndSinus = nv.getCosSinWith( gg->nav );
			nv.setBoth( cosinusAndSinus.cosinus, cosinusAndSinus.sinus );
				
			fl=true;
		}
	}
	while(tmp)
	{
		gg=global_groups+tmp->v;
		if(gg->un.beg)
		{
			gg->pos-=cc;
			if(fl)gg->pos.rotate(-cs.y,cs.x);
			gg->pos+=t1;
			gg->nav=nv;
			gg->GoOnCurPos(add);
			//SendUnits(&gg->un,gg->un.GetNum(),t1,t2,add, 1, 3);
		}
		tmp=tmp->next;
	}
}

void SendSelectedUnits(tka t1,tka t2,bool add) {
	if(sel.beg)global_OrdMan.AddOrder(new Order(0,&sel,t1,t2,add));
	if(selB.beg)global_OrdMan.AddOrder(new Order(1,&selB,t2,t2,add));
	if(GrpSel.beg)global_OrdMan.AddOrder(new Order(2,&GrpSel,t1,t2,add));

	
}

void SendUnits(st<int>*sel1,int num,tka t1,tka t2,bool add,float FormKoef,float FormSpread) {	
	if(!sel1->beg)return;
	int i,j,k,numFront=int(sqrtInt(int(num*FormKoef)));
	
	tka tp,tf;
	el<int>*sl=sel1->beg;

	sld*ss;
	if(numFront<=0)numFront=1;
	
	tf=t2-t1;

	if(tf.getLengthSquare()<1)
	{
		tf=t1-CalcCenter(sel1);
		if(tf.x==0&&tf.y==0)tf.y=1;
	}
	
	tf.normalize();
	
	tp.setBoth(tf.y,-tf.x);
	i=0;k=0;
	while(i<num)
	{
		j=1;
		while(j<=numFront && i<num)
		{
			ss=Units+sl->v;
			sl=sl->next;
			

		    if(!add)
		    {
			    ss->way.renull();
		    }
            ss->way.AddElToBeg(t1+tp*(float)((1-2*(j%2))*FormSpread*(j/2))-tf*(float)((1-2*(k%2))*(FormSpread*(k/2+0.5f))));
			//FitTkaToTka(&ss->way.beg->v,t1);
			CurrectTPoint(&ss->way.beg->v,ss->pos,t1);
			if(add)ss->way.AddElToBeg(ss->way.beg->v);
		    ss->enemy=-1;

			
		    i++;
			j++;
		}
		k++;
	}
	
}
void SelectAllUnits(char filt,bool add)
{
	int i;
	char tp;
	sld* sldp=Units;
	if(!add)
	{
		UnSelect();
	}
	for(i=0;i<UNIT_TYPES;i++)SelInfo[i]=0;
	for(i=0;i<MAXSLD;i++,sldp++)
		if(sldp->life)
	{
		tp=sldp->type;
		if(((sldp->pl&7)==MyConf.MY_PLAYER)&&(!filt||filt==tp+1))
		{
			if(sldp->group_id==-1)
				sel.AddEl(i);		//SelInfo[tp]++;
			else
				GrpSel.AddEl(sldp->group_id);
		}

	}
	UpdateSelInfo();

}
void CorrectCurPos()
{
	if(curpos.getX()<=0)curpos.setX(0);
	if(curpos.getY()<=0)curpos.setY(0);
	if(curpos.getX()>=MapW*KLET_SIZE)curpos.setX((float)MapW*KLET_SIZE );
	if(curpos.getY()>=MapH*KLET_SIZE)curpos.setY((float)MapH*KLET_SIZE );
			

}
void ChangeScale(float ns, bool toCursor)
{
	if(ns>40.0f) ns=40.0f;
	if(ns<0.1f) ns=0.1f;

	if(toCursor)
	{
		curpos.x+=(((ns)*(mPos.getX()-WIDTH/2 ))/SCALE-mPos.getX()+WIDTH/2 )/ns;
		curpos.y+=(((ns)*(mPos.getY()-HEIGHT/2))/SCALE-mPos.getY()+HEIGHT/2)/ns;
	}
	SCALE=ns;
	CorrectCurPos();
}
void MouseProc()
{
	if(dscale)
	{
		ChangeScale(SCALE*(1+dscale), true);
		dscale*=0.8f;
		if(absD(dscale)<0.01f)dscale=0;
	}
    POINT position;
	GetCursorPos(&position);
    mPos.setBoth( position.x, position.y );
	if(cur_wdj==-1)
	{
		if(mPos.getX()<=SCROLLDIST)curpos.x-=MyConf.ScrollSpeed/SCALE;
		if(mPos.getY()<=SCROLLDIST)curpos.y-=MyConf.ScrollSpeed/SCALE;
		if(mPos.getX()>=WIDTH-SCROLLDIST)curpos.x+=MyConf.ScrollSpeed/SCALE;
		if(mPos.getY()>=HEIGHT-SCROLLDIST)curpos.y+=MyConf.ScrollSpeed/SCALE;
		CorrectCurPos();
	}
}

void UnSelect()
{
	sel.renull();
	selB.renull();
	GrpSel.renull();
	memset(SelInfo,0,UNIT_TYPES*sizeof(int));
}
void UpdateSelInfo()
{
	
	sld* sldp;
	st_iterator<int> it(&GrpSel);
	st_iterator<int> itu(&sel);
	Group* gg;
	memset(SelInfo,0,UNIT_TYPES*sizeof(int));
	
	while(!it.IsDone())
	{
		gg=global_groups+*it.GetCurrent();
		if(!gg->un.beg)
			it.DeleteCur();
		else
			it.Next();
		
	}

	while(!itu.IsDone())
	{
		sldp=Units+*itu.GetCurrent();
		if(sldp->life && sldp->group_id==-1)
		{
			SelInfo[sldp->type]++;
			itu.Next();
		}else
		{
			if(sldp->group_id!=-1)
				GrpSel.AddEl(sldp->group_id);
			itu.DeleteCur();
		}
	}


	
}


bool SelectGroup(int id)
{
	Group* gg=global_groups+id;
	if(!gg->un.beg)return false;
	GrpSel.AddEl(id);
	return true;
}

void DeleteSelection()
{
	if(sel.beg)global_OrdMan.AddOrder(new Order(3,&sel,1));
	if(GrpSel.beg)global_OrdMan.AddOrder(new Order(4,&GrpSel,1));

	/*
	Group* gg;
	while(sel.beg)
		DeleteUnit(sel.beg->v);
	while(GrpSel.beg)
	{
		gg=(Grp+GrpSel.beg->v);
		while(gg->un.beg)
		{
			DeleteUnit(gg->un.beg->v);
			if(!GrpSel.beg)break;
		}
	}
	*/
}


void DoPlAction(Order*ord)
{
	char pl=ord->pl;
	switch(ord->prm)
	{
	case 0:AutoCreateGroup(pl);
		break;
	case 1:Building=GROW_TIME;
		TryBuildUnits((char)(~(1<<(pl&7))));
		break;
	}
}