#include "Group.h"

#include "Units.h"
#include "Polygon.h"
#include "Diplomation.h"
#include "Control.h"
#include "Game.h"


Group global_groups[ MAX_GROUPS_NUM ];
int temp_i;

void Act_setId( int *i ) {
	( Units + *i )->group_id = temp_i;
}

/*
void UnGroup(int* i)
{
	Group* gg=Grp+*i;
	temp_i=-1;
	DoForEach(gg->un.beg,Act_setId);
	if(sel.beg)
		sel.GetLast()->next=gg->un.beg;
	else
		sel.beg=gg->un.beg;
	gg->un.beg=0;

}*/

void Group::UnGroup()
{
	if(!un.beg)return;
	temp_i=-1;

	DoForEach(un.beg,Act_setId);

//	if(((Units+un.beg->v)->pl&7)==MyConf.MY_PLAYER)
//	{}
	un.renull();
}

void Group::CorrectRoute() {
	tka cc = ::CalcCenter( &un );
	tka tmpt;
	sld *sldp1 = Units + un.beg->v;
	sld *sldp;
	el< tka > *group_way;
	el< int > *tmp = un.beg->next;
	float ml = sldp1->pos.getLengthSquare( cc );
	float ll;
	int kk = un.beg->v;

	while ( tmp ) {
		sldp = Units + tmp->v;
		ll = sldp->pos.getLengthSquare( cc );

		if ( ml > ll ) {
			sldp1 = sldp;
			ml = ll;
			kk = tmp->v;
		}

		tmp = tmp->next;
	}

	if ( sldp1->way.beg ) {
		::CorrectRoute( sldp1 );
	}

	group_way = sldp1->way.top;
	cc = sldp1->pos;
	tmp = un.beg;

	while ( tmp ) {
		if ( tmp->v != kk ) {
			sldp = Units + tmp->v;

			if ( sldp->way.beg ) {
				tmpt=sldp->way.beg->v;

				if ( ::LineCrossSomething( sldp->pos, tmpt ) ) {
					sldp->way.renull();
					sldp->way.AddEl( tmpt );

					if ( group_way ) {
						::CopyElements< tka >( &sldp->way.top, group_way );
					}

					if ( !( sldp->way.top->v == cc ) ) {
						sldp->way.AddEl( cc );
					}

					::CorrectRoute( sldp );
				}
			}
		}

		tmp = tmp->next;
	}
	//CopyElements<tka>(&(Units+tmp->v)->way.beg,group_way);

}
/*
void Group::CorrectRoute()
{
	tka tmpt,cc;
	sld *sldp1=Units+un.beg->v,*sldp;
	el<tka>* group_way;
	el<int>* tmp=un.beg->next;
	int tmpi=0;
	if(sldp1->way.beg)
		::CorrectRoute(sldp1);
	group_way=sldp1->way.top;
	cc=sldp1->pos;

	while(tmp)
	{
		sldp=Units+tmp->v;

		if(sldp->way.beg)
		{
			tmpt=sldp->way.beg->v;
			if(LineCrossSomething(sldp->pos,tmpt))
			{
				sldp->way.renull();
				sldp->way.AddEl(tmpt);
				if(group_way)
					CopyElements<tka>(&sldp->way.top,group_way);
				if(!(sldp->way.top->v==cc))
					sldp->way.AddEl(cc);
				::CorrectRoute(sldp);

			}
		}
		tmpi++;
		if(tmpi==4)
		{
			cc=sldp->pos;
			tmpi=0;
		}
		tmp=tmp->next;
	}


}*/

void UpdateGroups()
{
	int i=0;
	while(i!=MAX_GROUPS_NUM)
	{
		UpdateGroup(i);
		i++;
	}
}
void UpdateGroup(int id)
{
	Group*gg=(global_groups+id);
	st_iterator<int> it(&(gg->un));
	sld* sldp;
	while(!it.IsDone())
	{
		sldp=Units+*it.GetCurrent();
		if(sldp->group_id!=id)
			it.DeleteCur();
		else
			it.Next();
	}

}


int CreateGroup(el<int>* beg)
{

	int i;
	if(!beg)return -1;
	Group* tmpgrp=global_groups;
	for(i=0;i<MAX_GROUPS_NUM;i++,tmpgrp++)
		if(!tmpgrp->un.beg)break;

	if(i==MAX_GROUPS_NUM)return -1;
	temp_i=i;

	tmpgrp->un.AddStDBL(beg);
	DoForEach(tmpgrp->un.beg,Act_setId);
//	tmpgrp->pos=CalcCenter(&tmpgrp->un);
//	tmpgrp->nav=tmpgrp->pos+tka(1,0);
//	tmpgrp->GoOnCurPos(0);


	UpdateGroup(i);
	return i;

}
/*
void DeleteGroup(int id)
{
	if(id>MAX_GROUPS_NUM)return;
	(Grp+id)->UnGroup();
}
*/
/*
void JoinFromGroups(st<int>*ss)
{
	st<int> ggg;
	el<int>*tmp=ss->beg,*tmpg;
	int tmpi;
	while(tmp)
	{
		tmpi=(Units+tmp->v)->group_id;
		if(tmpi!=-1)	ggg.AddEl(tmpi);
		tmp=tmp->next;
	}
	tmpg=ggg.beg;
	while(tmpg)
	{
		tmp=(Grp+tmpg->v)->un.beg;
		while(tmp)
		{
			ss->AddEl(tmp->v);
			tmp=tmp->next;
		}
		tmpg=tmpg->next;
	}

}*/

int GetGroupsNum()
{
	int i=0,res=0;
	Group* gg=global_groups;
	while(i!=MAX_GROUPS_NUM)
	{
		if(gg->un.beg)
			res++;
		gg++;
		i++;
	}
	return res;
}

void DeleteAllGroups()
{
	int i=0;
	Group* gg=global_groups;
	while(i!=MAX_GROUPS_NUM)
	{
		gg->un.renull();
		gg++;
		i++;
	}

}
void GroupCheck(Group* g)
{
	if(g->un.GetNum()<MIN_NUM_IN_GROUP)
	{
		g->UnGroup();
	}
}
void GroupLook(Group* g)
{
	tka c;
	int ii,jj,en;
	sld* sldp;

	if(!g)return;
	if(!g->un.beg)return;
	sldp=(Units+g->un.beg->v);

	if(!(sldp->pl&16))return;
	c=CalcCenter(&g->un);
	ii=TOKLETSIZE(c.x);
	jj=TOKLETSIZE(c.y);


	en=Look(ii,jj,c,2+ObserveDist[sldp->type],global_diplomation.d[sldp->pl&7]);
	if(en!=-1)	MakeAlert(en,&g->un);
}


void GroupCorrectRoute( Group *g ) {
	if ( g == nullptr ) return;

	tka tmpt;
	el< tka > *g_way = nullptr;
	bool fl = true;

	el< int > *ss = g->un.beg;

	while ( ss ) {
		sld *sldp = Units + ss->v;

		if ( fl ) {
			CorrectRoute( sldp );
			tmpt = sldp->pos;
			g_way = sldp->way.top;
			fl = false;
		} else {
			if ( LineCrossSomething( sldp->pos, tmpt ) ) {
				fl = true;
				continue;
			} else {
				sldp->way.renull();
				CopyElements( &sldp->way.beg, g_way );
				sldp->way.AddEl( tmpt );

			}
		}

		ss = ss->next;
	}
}

void Group::GoOnCurPos( const bool add ) {
	::SendUnits( &un, un.GetNum(), pos, nav + pos, add, 1, 3 );
}

int JoinUnitAuto(int id)
{
	int mn = MAX_NUM_IN_GROUP;
	int n = 0;
	int k = -1;
	sld *sldp = Units + id;
	sld *sldp2 = nullptr;
	Group *gg = global_groups;
	Group *mg = nullptr;

	for( int i=0; i < MAX_GROUPS_NUM; i++, gg++ ) {
		if(gg->un.beg) {
			sldp2=Units+gg->un.beg->v;
			if(!((sldp2->pl^sldp->pl)&7))
				if(sldp2->type==sldp->type)
				{
					n=gg->un.GetNum();

					if(mn>n){mn=n;k=i;mg=gg;}
				}


		}
	}

	if(k!=-1)
	{
		sldp->group_id=k;
		mg->un.AddEltoBeg(id);
		mg->GoOnCurPos(0);
	}

	return k;

}

void AutoCreateGroup( const char pl ) {
	sld *sldp = Units;
	int i;
	int k;
	int nm[ UNIT_TYPES ] = {};
	st< int > un[ UNIT_TYPES ];

	if ( pl == MyConf.MY_PLAYER ) {
		::UnSelect();
	}

	for(i=0;i<MAXSLD;i++,sldp++)
		if(sldp->life && !(sldp->pl&8))
		if(sldp->group_id==-1)
			if((sldp->pl&7)==pl)
			{
				un[sldp->type].AddEltoBeg(i);
				nm[sldp->type]++;
				if(nm[sldp->type]==MIN_NUM_IN_GROUP)
				{
					k=CreateGroup(un[sldp->type].beg);
					un[sldp->type].renull();
					nm[sldp->type]=0;

					if(k!=-1 && pl==MyConf.MY_PLAYER) GrpSel.AddEl(k);

				}
			}
	for(i=0,sldp=Units;i<MAXSLD;i++,sldp++)
		if(sldp->life)
		if(sldp->group_id==-1)
			if((sldp->pl&7)==pl)
				JoinUnitAuto(i);

}
void SpreadGroupCenters(st<int>*sl)
{
	el<int>*i;
	Group*gg;
	tka cc,stp(50,0),nv(0,1);
	i=sl->beg;
	if(!i)return;
	cc=(Units+(global_groups+i->v)->un.beg->v)->pos;


	while(i)
	{
		gg=(global_groups+i->v);
		gg->pos=cc;
		gg->nav=nv;
		gg->GoOnCurPos(0);
		cc+=stp;
		//(Grp+i->v)->nav=nv;
		i=i->next;
	}
}
void GroupUnits(st<int>*sl)
{
	st<int> tmpst,gr;
	char type;
	int ii,id;
	st_iterator<int> it;

	while(sl->beg)
	{
		it.AcceptSt(sl);
		tmpst.renull();
		type=(Units+sl->beg->v)->type;
		id=0;
		while(!it.IsDone())
		{
			ii=*it.GetCurrent();
			if(type==(Units+ii)->type)
			{
				tmpst.AddEl(ii);
				it.DeleteCur();
				id++;
				if(id==MAX_NUM_IN_GROUP)break;

			}else
				it.Next();

		}
		id=tmpst.GetNum();
		if(id>=MIN_NUM_IN_GROUP)
		{
			id=CreateGroup(tmpst.beg);
			gr.AddEltoBeg(id);
		}
	}
	UpdateGroups();
	UpdateSelInfo();
	SpreadGroupCenters(&gr);
	//UpdateGroups();
}
/*

void GroupSelected()
{
	st<int> ng, tmpst;
	el<int>*tmp=GrpSel.beg;
	char type;
	int ii,id;
	st_iterator<int> it;



	ng.AddStDBL(sel.beg);
	while(tmp)
	{
		ng.AddStDBL((Grp+tmp->v)->un.beg);
		tmp=tmp->next;
	}
	sel.renull();
	GrpSel.renull();

	while(ng.beg)
	{
		it.AcceptSt(&ng);
		tmpst.renull();
		type=(Units+ng.beg->v)->type;
		id=0;
		while(!it.IsDone())
		{
			ii=*it.GetCurrent();
			if(type==(Units+ii)->type)
			{
				tmpst.AddEl(ii);
				it.DeleteCur();
				id++;
				if(id==MAX_NUM_IN_GROUP)break;

			}else
				it.Next();

		}
		id=tmpst.GetNum();
		if(id>=MIN_NUM_IN_GROUP)
		{
			id=CreateGroup(tmpst.beg);
			if(id!=-1)
				GrpSel.AddEl(id);
		}else
			sel.AddStDBL(tmpst.beg);
	}
	UpdateGroups();
	UpdateSelInfo();

}
*/
/*
bool GroupSelected()
{
	el<int>*tmp=GrpSel.beg;
	st<int> ng;
	unsigned char speed_type=0,tmpc;
	int ii;
	Group* gg;
	st_iterator<int> it(&sel);
	if(sel.beg)
		speed_type=Velocity[(Units+sel.beg->v)->type];
	else
	{
		ii=0;
		while(tmp)
		{
			gg=(Grp+tmp->v);
			tmpc=Velocity[(Units+gg->un.beg->v)->type];
			if(speed_type==0 || speed_type==tmpc)
			{
				speed_type=tmpc;
				ng.AddStDBL(gg->un.beg);
				ii++;
			}
			tmp=tmp->next;
			if(ii<2)return false;
		}
	}


	while(!it.IsDone())
	{
		ii=*it.GetCurrent();
		if(speed_type==Velocity[(Units+ii)->type])
		{
			ng.AddEl(ii);
			it.DeleteCur();

		}else
			it.Next();

	}
	int id=CreateGroup(ng.beg);
	if(id!=-1)
	{
		//GrpSel.renull();
		UpdateGroups();
		GrpSel.AddEl(id);
		UpdateSelInfo();
		return true;
	}
	return false;
}*/
