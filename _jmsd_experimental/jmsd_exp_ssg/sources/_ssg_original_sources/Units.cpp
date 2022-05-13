#include "Units.h"

#include "Ai.h"
#include "Animation.h"
#include "Sound.h"
#include "Menu.h"
#include "Control.h"
#include "Group.h"
#include "Game.h"
#include "Polygon.h"
#include "Zamer.h"
#include "Diplomation.h"
#include "Missiles.h"
#include "Bases.h"

#include "jmsf/ShortReal.h"
#include "jmsf/stdal/stdal_stl.h"


sld Units[MAXSLD];// юниты

sld_dead DeadUnits[DEAD_SLD_NUM];//трупы юнитов
int Current_dead=0;//текущий труп - он будет заменён новым

st<int>**QUNid;
char QUNex[FIELDSIZEX][FIELDSIZEY];// - наличие игроков (первые 8 бит)
int UnitsNum;

int SelInfo[UNIT_TYPES];//хранение числа выделенных юнитов различных типов
int UnInfo[PLAYERS_NUM][UNIT_TYPES];//хранение числа юнитов различных типов

float my_sin[ANG_VAL_NUM],my_cos[ANG_VAL_NUM],my_cos2[ANG_VAL_NUM];

unsigned char Zarad[UNIT_TYPES]=      {35,  100, 12 , 80, 100, 40};//время перезарядки
unsigned char Attack[UNIT_TYPES]=     {20 , 45 , 15 , 6 ,  6,   6};//атака
unsigned char Defend[UNIT_TYPES]=     {3  , 6 ,  5  , 2 ,  2,   0};//защита от ближней атаки
unsigned char MissDefend[UNIT_TYPES]= {14 , 15 , 18 , 10 , 2 ,  0};//защита от снаряда
unsigned char ObserveDist[UNIT_TYPES]={5  , 5  , 5  , 8  , 7 ,  12};//1/2 стороны квадрата обзора в поиске врагов
unsigned char Velocity[UNIT_TYPES]=   {5  , 3  , 14 , 5  , 3 ,  11};//скорость движения

short CorrectRoutePeriod[UNIT_TYPES]=  {200  , 300  , 60 , 200  , 300 ,  140};//период обновления маршрута

void InitUnits()
{
	   int i,j;
	   UnitsNum=0;
	   
	   for(i=0;i<ANG_VAL_NUM;i++)
	   {
		   my_sin[i]=((float)sin((1<<i)*(PI_180*0.5)));
		   my_cos[i]=((float)cos((1<<i)*(PI_180*0.5)));
		   my_cos2[i]=my_cos[i]*my_cos[i];
	   }
	   

	   //Units=new sld[MAXSLD];
	   
	   for(i=0;i<MAXSLD;i++)
	   {
		   (Units+i)->life=0;

	   }
	   
	 //  QUNex=new char*[FIELDSIZEX];
	   //for(i=0;i<FIELDSIZEX;i++) QUNex[i]=new char[FIELDSIZEY];

	   memset(QUNex,0,FIELDSIZEX*FIELDSIZEY);
/*
	   for(i=0;i<FIELDSIZEX;i++)
		   for(j=0;j<FIELDSIZEY;j++)
		   {
			   QUNex[i][j]=0;
		   }
*/
	   QUNid=new st<int>*[FIELDSIZEX];
	   for(i=0;i<FIELDSIZEX;i++) 
	   {
		   QUNid[i]=new st<int>[FIELDSIZEY];
		   for(j=0;j<FIELDSIZEY;j++) 
			   QUNid[i][j].beg=0;
	   }
	   

       global_formations=new Formation[MAX_FORMATIONS];
	   
	   

}

void UnInitUnits()
{
	int i,j;
	for(i=0;i<MAXSLD;i++)Units[i].way.renull();
	delete[]global_formations;
	

	for(i=0;i<FIELDSIZEX;i++)
	{
		for(j=0;j<FIELDSIZEY;j++)
		{
		   QUNid[i][j].renull();
		   QUNex[i][j]=0;
		}
		delete[]QUNid[i];
	}
	
	delete[]QUNid;
}

void DeleteUnit(int i)
{
	sld* dead_unit=Units+i;
	sld_dead* tr=(DeadUnits+Current_dead);

	AddAnimation(new PMonAnim(Units[i]));

	//делаем трупег
	tr->pos=dead_unit->pos;
	tr->ang=(dead_unit->a%720)/4;
	tr->type=(dead_unit->pl&7)|(dead_unit->type<<3);
	Current_dead++;
	if(Current_dead==DEAD_SLD_NUM)
		Current_dead=0;

	PlayWavFile(std::string("death_")+IntToString(dead_unit->type),dead_unit->pos);

	dead_unit->life=0;
	if(sel.Delete(i))//убираем юнита из выделения
		SelInfo[dead_unit->type]--;
	if(dead_unit->group_id!=-1)
	{
		(global_groups+dead_unit->group_id)->un.DelEl(i);
		GroupCheck(global_groups+dead_unit->group_id);

		if(!(global_groups+dead_unit->group_id)->un.beg)	
			GrpSel.DelEl(dead_unit->group_id);
		dead_unit->group_id=-1;
	}
	dead_unit->way.renull();
	UnitsNum--;
	UnInfo[dead_unit->pl&7][dead_unit->type]--;

	

	
		 
}
int ChooseBestPlace(char pl)
{
	int i=(pl*MAXSLD)/ std::max( MyConf.PlNum, unsigned char( 2 ) );
	if(i>=MAXSLD)i=0;
	sld* sldp=Units+i;
	while(sldp->life)
	{
		sldp++;
		i++;
		if(i==MAXSLD){i=0;sldp=Units;}
	}
		
	return i;
}
int AddUnit(tka pos,char pl,char type,tka send)
{
	int i=0;
	if(UnitsNum==MAXSLD)return -1;
	i=ChooseBestPlace(pl&7);//for(i;(Units+i)->life;i++);
	sld* new_unit=Units+i;	   
	UnitsNum++;
	
	
	new_unit->group_id=-1;
	new_unit->pl=pl;
	new_unit->type=type;
	new_unit->pos=pos;
	new_unit->life=100;
	new_unit->a=0;
	new_unit->enemy=-1;
	new_unit->nav.setBoth(1,0);
	new_unit->vel.setBoth(RND11,RND11);
	//new_unit->vel.set(0,0);
	new_unit->way.renull();
	if(send.x)new_unit->way.AddEl(send);
	new_unit->zar=0;
	   
	UnInfo[pl&7][type]++;


//	JoinUnitAuto(i);

//	if(COMPUTER_AI(pl)&&type!=2&&type!=5)new_unit->pl|=8;

	return i;
}
void CutRoute(sld*s)
{
	int n=0,i=1;
	el<tka>*tmpt=s->way.top->next;
	tka ttt;
	while(tmpt)
	{
		if(tmpt->next)if(tmpt->next->v==tmpt->v){break;}
		if(!LineCrossSomething(s->pos,tmpt->v))
		{
			
			n=i;

		}
		
		tmpt=tmpt->next;
		i++;

	}
	if(!n)
	{
		tmpt=s->way.top->next;
		if(tmpt)
			if(s->pos.getLengthSquare(s->way.top->v)<70)
			{
				
				ttt=tmpt->v-s->way.top->v;
				ttt*=(10.0f/KVAZIL(tmpt->v,s->way.top->v));
				ttt+=s->way.top->v;
				if(!LineCrossSomething(s->pos,ttt))
					n=1;

					//s->way.top->v=ttt;
			}
			//if( scalar(s->way.top->v-s->pos,tmpt->v-s->way.top->v)<-1)n=1;

	}
	while(n)
	{
		s->way.DeleteEl();
		n--;
	}

}
void CorrectRoute(sld*s)
{
	
	int pp,i=1,n=0,k=0;
//	float kf;
	bool zn = false, fff, cr = true, ccr;
	tka ttt=s->way.top->v,ttt2,ttt3,ttt4;
	tka*ppp,*trup;
	//el<tka>*tmpt=s->way.top->next;
	stek<tka>tmpst;

	BB(16);

	BB(40);
	//tka tmpt;
	CutRoute(s);
	BB1(40);

	

	
	if(LineCrossSomething(s->pos,ttt,&pp/*,&tmpt*/))
	{
		
		ppp=TPoly[pp]; 
		trup=Poly[pp];
		n=TLNUM(ppp);
		ttt4=PolyCent[pp]-s->pos;
		if((ttt-s->pos).getVectorProduction(ttt4)<0)zn=1;
		
		ttt2=*ppp-s->pos;
		cr = LineCrossSomething(s->pos,*ppp);
		for(i=1;i<n;i++)
		{
			ttt3=ppp[i]-s->pos;
			fff=0;
			if(zn)
			{
				if((ttt3).getVectorProduction(ttt4)<0)
			    if((ttt2).getVectorProduction(ttt3)>0)fff=1;
			}else
			{
				if((ttt3).getVectorProduction(ttt4)>0)
				if((ttt2).getVectorProduction(ttt3)<0)fff=1;
			}
			ccr=LineCrossSomething(s->pos,ppp[i]);
			if((fff && !ccr) || cr)
		    {k=i;ttt2=ttt3;}
			
			if(!ccr)cr=0;
		
		}
		
		/*
		
		for(k=0;k<n;k++)
			if(!LineCrossSomething(tmpt,ppp[k]))
				break;
		*/		
		if(k==n)k=0;
		if(!zn)zn=-1;
		//tmpst.AddElToBeg(tmpt);
		for(i=0;i<n;i++)
		{
			tmpst.AddElToBeg(ppp[k]);
			if(!LineCrossPoly(&ttt,ppp+k,trup,1))
			{
				
				tmpst.beg->next=s->way.top;
				s->way.top=tmpst.top;
				tmpst.top=0;
				CutRoute(s);
				break;
			}
			k+=zn;
			if(k==-1)k=n-1;else if(k==n)k=0;


		}
	}
	BB1(16);

}
/*
void ClearField()
{
	sld *tmp=Units;
	int i,j,ii,jj;
	st<int> **iii1=QUNid, *iii2;
	BB(50);
	for(i=0;i<MapW;i++,iii1++)
		for(j=0,iii2=*iii1;j<MapH;j++,iii2++)
	        iii2->renull();
	BB1(50);
	BB(51);
	memset(QUNex,0,FIELDSIZEX*FIELDSIZEY);
	BB1(51);
	BB(52);
	for(i=0;i<=LastUnit;i++,tmp++)
		if(tmp->life)
		{
			ii=TOKLETSIZE(tmp->pos.x);
			jj=TOKLETSIZE(tmp->pos.y);
			if(here(ii,jj))
			{
				(QUNid[ii]+jj)->AddEltoBeg(i);
				QUNex[ii][jj]|=MyPow2(tmp->pl&7);
			}
		}
	BB1(52);

}*/
void ClearField()
{
	static int clearx=0,cleary=0;
	int i=(MapW*MapH)/100;
	do
	{
    	clearx++;
		if(clearx>=MapW){clearx=0;cleary++;if(cleary>=MapH)cleary=0;}   /// очистка поля от мусора
	    QUNex[clearx][cleary]=0;
	    (QUNid[clearx]+cleary)->renull();
		i--;
	}
	while(i);

}

void MakeAlert(int eni,int ii,int jj,int rad,char pl)
{
	int i=ii-rad,j,i1=ii+rad,j0=jj-rad,j1=jj+rad;
	sld *sldp;
	el<int> *ss;
	st<int> *tmpst;
	char plpl=MyPow2(pl);

	if(i<0)i=0;
	if(i1>=MapW)i1=MapW-1;
	if(j0<0)j0=0;
	if(j1>=MapH)j1=MapH-1;
	for(;i<=i1;i++)
		for(j=j0;j<=j1;j++)
			if(QUNex[i][j]&plpl)
			{
				tmpst=QUNid[i]+j;
				ss=tmpst->beg;
				while(ss)
				{
					sldp=Units+ss->v;
					if(sldp->enemy==-1)
					if((sldp->pl&7)==pl && sldp->life)
					{
						sldp->enemy=eni;
					}
					ss=ss->next;
				}
			}
}
void MakeAlert(int eni,st<int> *tmpst)
{
	el<int> *ss=tmpst->beg;
	sld* sldp;
	tka ttt=(Units+eni)->pos;
	while(ss)
	{
		sldp=(Units+ss->v);
		if(sldp->enemy==-1)
		{
			if(!sldp->way.top)sldp->way.AddEl(sldp->pos);

			sldp->enemy=eni;

		//	else
		//	if(sldp->pos.getLengthSquare(ttt)<(GROUP_ALESRT_DIST*GROUP_ALESRT_DIST))
		//		sldp->enemy=eni;
		
			/*
			else
			{
				if(sldp->way.top)
				{
					if(!(sldp->way.top->v==ttt))
						sldp->way.AddEl(ttt);
				}else
				{
					sldp->way.AddElToBeg(ttt);
					sldp->way.AddElToBeg(ttt);
					sldp->way.AddElToBeg(sldp->pos);
					
				}
			}*/
		}
		ss=ss->next;
	}
}
void ClearEnemies()
{
	static int id=0;
	static sld *tmp=Units;
	int i=1000;
	do
	{
		if(id==MAXSLD)
		{
			id=0;
			tmp=Units;
		}
		tmp->enemy=-1;
		id++;
		tmp++;

		i--;
	}
	while(i); 


}
//возвращает id юнита, ближайшего к точке c из клетки (ii,jj); поиск идёт в радиусе rad клеток, ищется юнит игрока из фильтра pl_filter
int Look(int ii,int jj,tka& c,int rad,char pl_filter)
{
	int aa,bb,aa2,bb1,bb2, res=-1;
	float l=1000000,dx;
	el<int>* ss;
	sld* sldp;
	aa=ii-rad;	if(aa<0)aa=0;
	bb1=jj-rad;	if(bb1<0)bb1=0;
	aa2=ii+rad;	if(aa2>=MapW)aa2=MapW-1;
	bb2=jj+rad;	if(bb2>=MapH)bb2=MapH-1;

	for(;aa<=aa2;aa++)
		for(bb=bb1;bb<=bb2;bb++)
			if(QUNex[aa][bb]&pl_filter)
			{
				dx=0;
				ss=(QUNid[aa]+bb)->beg;
				while(ss)
				{
					sldp=Units+ss->v;
					if(sldp->life)
					{
						if(MyPow2(sldp->pl&7)&pl_filter)
						{
							dx=sldp->pos.getLengthSquare(c);
							if(dx<l)
							if(!LineCrossSomething(sldp->pos,c))
							{
								l=dx;
								res=ss->v;
							}
						}
					}
					ss=ss->next;
				}
				if(!dx)QUNex[aa][bb]&=(~pl_filter);
			}
	return res;
}
void CorrectNav(sld* s)
{
	tka nn(0,0);
	short aa=absD(s->a);
	switch(aa%360)
	{
		case 0:nn.setBoth(1,0);break;
		case 60:nn.setBoth(SQRT3*0.5f,0.5f);break;
		case 120:nn.setBoth(0.5f,SQRT3*0.5f);break;
		case 180:nn.setBoth(0,1);break;
		case 240:nn.setBoth(-0.5f,SQRT3*0.5f);break;
		case 300:nn.setBoth(-SQRT3*0.5f,0.5f);break;

	}
	if(aa%720>=360){nn.x=-nn.x;nn.y=-nn.y;}
	if(s->a<0)nn.y=-nn.y;
	s->nav=nn;
}
void MoveSld()
{
	sld *tmp=Units,*sldp;
	el<int> *ss;
	int i,ii,jj,aa,bb,kk;
	float x1,y1,x2,sc,vc,l,dx;//,dy;
	bool fl1 = ( GameTime % 50 ) == 0;
	bool flmv, fl3,fl2,flp/*=((GameTime%100)==0)*/,flpp=((GameTime%4)==0), ishere;
	tka ttt;
	char tmppl,tmppl2,plpl;
	

	if(UnitsNum==0)return;

	BB(3);
	BB(25);
	ClearField();
	if(fl1)ClearEnemies();
	BB1(25);
	
	
/*
	for(i=0;i<LastUnit;i++)
    if((Units+i)->life)
	{
		tmp=*(a->a+i);
		if(here(int(tmp.pos.x)/KLET_SIZE,int(tmp.pos.y)/KLET_SIZE))
			QUNid[int(tmp.pos.x)/KLET_SIZE][int(tmp.pos.y)/KLET_SIZE].renull();
	}
	for(i=0;i<LastUnit;i++)
	if((Units+i)->life)
	{
		tmp=*(a->a+i);
		
		ii=int(tmp.pos.x)/KLET_SIZE;
		jj=int(tmp.pos.y)/KLET_SIZE;
		if(!here(ii,jj))continue;
		
		QUNid[ii][jj].AddEl(i);
		QUNex[ii][jj]|=MyPow2(tmp.pl&7);
	}

*/

//	if(flp)		CorrectGroupsRoute();
		

	//if(GameTime%100==0)	DoForEach(Grp,GroupCorrectRoute,MAX_GROUPS_NUM);
	if(fl1) DoForEach(global_groups,GroupLook,MAX_GROUPS_NUM);

	for(i=0;i<MAXSLD;i++,tmp++)
		if(tmp->life)
		{
			INCR_CNT(0);
			BB(4);


			flp=(((GameTime+i)%CorrectRoutePeriod[tmp->type])==0);

			ii=int(tmp->pos.x)/KLET_SIZE;
			jj=int(tmp->pos.y)/KLET_SIZE;
			ishere=here(ii,jj);
			plpl=tmp->pl&7;
			
			tmppl=MyPow2(plpl);
			tmppl2=global_diplomation.d[plpl];  //~tmppl;

			if(flpp)
			{
				if(tmp->zar<Zarad[tmp->type])	tmp->zar++;
				else 	tmp->zar=Zarad[tmp->type];
			}


			flmv=0;
			fl3=0;
			fl2=0;
			
		    if(tmp->enemy!=-1)
			{
				INCR_CNT(1);

				sldp=(Units+tmp->enemy);
				if(sldp->life &&/* KVAZIL(tmp->pos,sldp->pos)<MAN_LOOK_DIST &&*/!LineCrossSomething(sldp->pos,tmp->pos))
				{
					ttt=sldp->pos;
					flmv=1;
					if(tmp->type>2)fl3=1;
				}else 
				{
					tmp->enemy=-1;
					
					fl2=1;
				}
			}else 
			if(tmp->way.beg)
			{
			
				//if(tmp->group_id==-1)
				if(flp) CorrectRoute(tmp);
				ttt=tmp->way.top->v;
				flmv=1;
			}
			


			
			if((fl1 && (tmp->group_id==-1) && (tmp->enemy==-1 || tmp->type==5)) || fl2)
			{
				INCR_CNT(2);
				if((tmp->pl&16)||(tmp->way.beg==NULL))
				{
					aa=Look(ii,jj,tmp->pos,ObserveDist[tmp->type],tmppl2);
					
					if(aa!=-1)
					{
						tmp->enemy=aa;
						if(!tmp->way.top)tmp->way.AddEl(tmp->pos);
						if(tmp->group_id!=-1)
							MakeAlert(tmp->enemy,&(global_groups+tmp->group_id)->un);
					}
					

				//	if(tmp->group_id!=-1)
				//		if(tmp->enemy!=-1)MakeAlert(tmp->enemy,&(Grp+tmp->group_id)->un);
				}
				
				
			}
	
    	BB1(4);
		////////////////////////////////////////////////////START PUSHIHG
		BB(5);
		if(ishere)
		{
			ss=QUNid[ii][jj].beg;
			aa=0;
			while(ss)
			{
				sldp=(Units+ss->v);
				if((i>ss->v) && sldp->life)
				{
					x1=tmp->pos.x+tmp->vel.x-sldp->pos.x-sldp->vel.x;
					y1=tmp->pos.y+tmp->vel.y-sldp->pos.y-sldp->vel.y;
					l=x1*x1+y1*y1;
					if(l<=MANSIZE_DOUBLE_AND_SQ)
					{
						if(l)
						{
							vc=(tmp->vel.x*x1+tmp->vel.y*y1)/l;
							sc=(sldp->vel.x*x1+sldp->vel.y*y1)/l;
							if(vc<0)
							{
								tmp->vel.x-=x1*vc;
								tmp->vel.y-=y1*vc;
							}
							if(sc<0)
							{
								sldp->vel.x-=x1*sc;
								sldp->vel.y-=y1*sc;
							}

						}
						x1*=PUSHKOEF;
						y1*=PUSHKOEF;
						tmp->vel.x+=x1;
						tmp->vel.y+=y1;
						sldp->vel.x-=x1;
						sldp->vel.y-=y1;

						kk=0;
						if(MyPow2(sldp->pl&7)&tmppl2)
    					{  
							if(tmp->zar==Zarad[tmp->type])
							{
                               sldp->life-=std::max(1,Attack[tmp->type]-Defend[sldp->type]);
							   tmp->zar=0;
							   kk=1;
			    			   
							}
							if(sldp->zar==Zarad[sldp->type])
							{
							   tmp->life-=std::max(1,Attack[sldp->type]-Defend[tmp->type]);
							   sldp->zar=0;
							   kk=1;
							   
							}
							if(sldp->life<=0)DeleteUnit(ss->v);							
							if(tmp->life<=0){DeleteUnit(i);BB1(5);	goto killlabel;}
						
							
						}
						if(kk)PlayWavFile(std::string("attack_")+IntToString(GameTime%6),(Units+i)->pos);

				    	if(aa)break;
						aa++;
			    	}
				}
				ss=ss->next;
			}
		}
		BB1(5);
			
		

		BB(6);
		///////////////////////////////////////////////////END PUSHING

		

		if(flmv)///  если нужно куда-то двигаться
		{
			x1=ttt.x-tmp->pos.x;
		 	y1=ttt.y-tmp->pos.y;
			vc=x1*tmp->nav.y-tmp->nav.x*y1;
			sc=x1*tmp->nav.x+y1*tmp->nav.y;
			l=x1*x1+y1*y1;

			if ( !l ) l = ::jmsf::ShortReal::SHORT_REAL_NORMAL_EPSILON;

			if(sc>0)
			{
				dx=sc*sc/l;
				for(bb=1;bb<ANG_VAL_NUM;bb++)
					if(dx>my_cos2[bb])break;
				bb--;
			}else bb=ANG_VAL_NUM-1;
			aa=(1<<bb);
			if(vc<0) aa=-aa;
				
			tmp->a-=aa;
			tmp->nav.rotate(((vc>=0)?my_sin[bb]:-my_sin[bb]),my_cos[bb]);
			
			if(!(absD(tmp->a)%60))
				CorrectNav(tmp);
			
			x2=vc*vc/l;
			if(sc>0)
			{
		       if(fl3)
			   {
			   	   if(x2<SMALLNAV3 && tmp->zar==Zarad[tmp->type])
				   {
					   switch(tmp->type)
					   {
					   case 3:  AddMiss(tmp->pos,tmp->nav*MISSVEL+tka(RND11,RND11)*(MISSSPREAD),MISSDES+MyRand()%MISSDES,plpl);
						   break;
					   case 4:
							for(aa=0;aa<10;aa++)
								AddMiss(tmp->pos,tmp->nav*MISSVEL+tka(RND11,RND11)*(MISSSPREAD*4),MISSDES+MyRand()%(1+MISSDES/10),plpl);
							break;
					   case 5:  AddMiss(tmp->pos,tka(x1,y1)*(2/(absD(x1)+absD(y1)+1)),MISSDES*2+MyRand()%(1+MISSDES/10),plpl);
						   break;
					   }
					   PlayWavFile(std::string("shoot_")+IntToString(tmp->type),tmp->pos);
					   AddAnimation(new FlashAnim(tmp->pos+tmp->nav,tmp->a/2));
					   tmp->zar=0;
					   
				   }
				   
				   if(tmp->type==5)
				   {
						if(!(tmp->pl&32) && l<6000)
						{
							dx=(0.6f*SOLDA)*Velocity[tmp->type];
							tmp->vel.x-=dx*tmp->nav.x;
							tmp->vel.y-=dx*tmp->nav.y;
						}
				   }
			   }else
				if(x2<SMALLNAV)
				{
					if(!(tmp->pl&32))
					{
 	 					dx=SOLDA*Velocity[tmp->type];
						if(l<100)
						{
							if(Velocity[tmp->type]>5 && tmp->enemy==-1)
							dx*=(l*0.75f+25.0f)/100.0f;
						}
						tmp->vel.x+=dx*tmp->nav.x;
						tmp->vel.y+=dx*tmp->nav.y;
					}
				}
			}

			if(tmp->enemy==-1)
				if(l<=MANREACHTARGET)
					tmp->way.DeleteEl();
			
		}else tmp->vel*=SOLDGIPTREN;
	    if(tmp->vel.x && tmp->vel.y)  ///  движение непосредственно
		{
			MoveCheck(tmp);
			tmp->pos.x+=tmp->vel.x;
			tmp->pos.y+=tmp->vel.y;
			tmp->vel*=SOLDTREN;
			vc=absD(tmp->vel.x)+absD(tmp->vel.y);
    		

			if(vc<SMALLVEL){tmp->vel.x=0;tmp->vel.y=0;}
			if(vc>1){tmp->vel.x=0;tmp->vel.y=0;}
		}
		
		if(ishere)
		{
			QUNid[ii][jj].AddEl(i);
			QUNex[ii][jj]|=tmppl;
		}


////////////////////////////////////////////
		if(tmp->pos.x<1)tmp->vel.x+=SOLDAOUTFIELD;
		if(tmp->pos.x>KLET_SIZE*MapW-1) tmp->vel.x-=SOLDAOUTFIELD;
		if(tmp->pos.y<1)tmp->vel.y+=SOLDAOUTFIELD;
		

	
		
killlabel:
		if(tmp->pos.y>KLET_SIZE*MapH-1) tmp->vel.y-=SOLDAOUTFIELD;		

		////////////////////////////////////////////////////

		BB1(6);
		
	  }
	  
	  BB1(3);
	  
}


void MoveCheck(sld*s)
{
	
	int ii,jj,nm=0,n,i;	
	tka**t;

	BB(7);
	ii=int(s->pos.x+s->vel.x)/KLET_SIZE;    
	jj=int(s->pos.y+s->vel.y)/KLET_SIZE;
	
	if(!here(ii,jj))return;
	t=Qpoly[ii][jj];
	if(!t)return;
	
	n=_msize(t)/sizeof(tka*);
	
	
	for(i=0;i<n;)
	{
		if(LineCrossCirc(s->pos.x-t[i]->x,s->pos.y-t[i]->y,(t[i]+1)->x-t[i]->x,(t[i]+1)->y-t[i]->y,&s->vel.x,&s->vel.y))
		{
			nm++;
			if(nm>=MAX_NORMALS_TO_CHECK/2)
			{
				s->vel.x=RND11*0.1f;
				s->vel.y=RND11*0.1f;
				INCR_CNT(8);
			}
			if(nm>MAX_NORMALS_TO_CHECK)
			{
				s->vel.x=0;
				s->vel.y=0;
				INCR_CNT(9);
				BB1(7);
				return;
			}
			i=0;
			continue;

		}else i++;
		
	}
	
	BB1(7);

}	
/*
void DivideUnit(sld* s)
{
	int tmpi;
	tka ttt(0,0);
	if(s->way.top)ttt=s->way.top->v;
	tmpi=AddUnit(s->pos,s->pl,s->type,ttt);
	if(tmpi!=-1)
	{
		s->life=1;
		(Units+tmpi)->life=1;
	}
}
*/

void UpdateDefenders()
{
	int i,j,k;
	float l,ml;
	char plpl;
	sld* cur_unit=Units;
	base* cur_base;
	for(i=0;i<MAXSLD;i++,cur_unit++)
	if(cur_unit->life)
	{
		if(cur_unit->life<100)
			cur_unit->life++;
		if(cur_unit->pl&8)
		{
			plpl=cur_unit->pl&7;
			ml=32000;
			k=-1;
			for(j=0,cur_base=Bases;j<BasesNum;j++,cur_base++)
				if(plpl==cur_base->pl)
				{
					l=KVAZIL(cur_unit->pos,cur_base->pos);
					if(l<MAX_DEFENDER_DIST)
					{

						
						cur_unit->life+=(100-cur_unit->life)/2;
						//cur_unit->zar=Zarad[cur_unit->type];
						k=-1;
						cur_unit->way.renull();
						if(COMPUTER_AI(plpl))cur_unit->pl|=16;
						break;
					}else
						if(ml>l){ml=l;k=j;}
				}
			if(k!=-1)
	//		if(!cur_unit->way.top)
			{
				cur_unit->way.renull();
				cur_unit->way.AddEl((Bases+k)->pos);
				CorrectRoute(cur_unit);
			}
		}
	}
			
}


tka CalcCenter(st<int> *s)
{
		el<int>*ttp;
		tka cc(0,0);
		int num=0;
		if(s->beg)
		{	
		
			ttp=s->beg;
			while(ttp)
			{
			    cc+=(Units+ttp->v)->pos;
			   	ttp=ttp->next;
				num++;
			}
			cc*=1/float(num);
		}
		return cc;

}

tka CalcCenterG(st<int> *s)
{
		el<int>*ttp;
		tka cc(0,0);
		int num=0;
		if(s->beg)
		{	
		
			ttp=s->beg;
			while(ttp)
			{
			    cc+=(global_groups+ttp->v)->pos;
			   	ttp=ttp->next;
				num++;
			}
			cc*=1/float(num);
		}
		return cc;

}
void CurrectTPoint(tka*t,tka from,tka to)
{
	if(t->x<1)t->x=1;
	if(t->y<1)t->y=1;
	if(t->x>(float)(MapW*KLET_SIZE)-1)t->x=(float)(MapW*KLET_SIZE)-1;
	if(t->y>(float)(MapH*KLET_SIZE)-1)t->y=(float)(MapH*KLET_SIZE)-1;

	int ii=((int)t->x)/KLET_SIZE,jj=((int)t->y)/KLET_SIZE,*pp,*ppp,i=0,nn,cnt=0;
	tka d=(to-*t)*(10/(KVAZIL(to,*t)+1));
	//if(!here(ii,jj))return;
	if(!Qip[ii][jj]) return;
	pp=Qip[ii][jj];
	nn=TLNUM(pp);
	//d=(PolyCent[pp]-*t)*(-3/(0.1f+KVAZIL(PolyCent[pp],*t)));
	while(1)
	{
		ppp=pp;
		for(i=0;i<nn;i++,ppp++)
			if(LineCrossPoly(t,&from,Poly[*ppp])&1)break;

		if(i==nn || cnt==40)break;
		*t+=d;
		cnt++;
	}
}

void FullClearField()
{
	int i,j;
	for(i=0;i<FIELDSIZEX;i++)
		for(j=0;j<FIELDSIZEY;j++)
		{
			QUNid[i][j].renull();
			QUNex[i][j]=0;
		}
}