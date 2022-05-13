#include "SafeFloat.h"

#include "Missiles.h"
#include "Units.h"
#include "Zamer.h"
#include "Packer.h"
#include "Bases.h"
#include "Control.h"

#include "myfuns.h"

#include "include_Windows.h"


bool need_replace_float;
int greed_value;


int SafeFloat(float& f)
{
	int res=(int)((f)*greed_value);
	if(need_replace_float)f=res/(float)greed_value;
	return res;
}

int SafeTka( tka &t ) {
	return SafeFloat(t.x)^(SafeFloat(t.y)<<8);
}

int SafeMiss( miss &m ) {
	return SafeTka( m.pos ) ^ SafeTka( m.vel );
}

int SafeSld(sld& s)
{
	return (((SafeTka(s.pos)^SafeTka(s.vel))<<16));
}
int SafeGame(bool replace_float,int greed_val)
{
	int i,res=0;
	sld* sldp=Units;
	need_replace_float=replace_float;
	greed_value=greed_val;

	BB(30);

	miss* mp=ms;

	for(i=0;i<MAXSLD;i++,sldp++)
		if(sldp->life)
			res+=SafeSld(*sldp);
	for(i=0;i<MisNum;i++,mp++)
		res+=SafeMiss(*mp);

	//if(replace_float)	my_seed=res;	else res^=my_seed;

	BB1(30);

	return res;
}

//////////////////////////Packing Game content///////////////////////


void PackZipFloat(float f,Pocket& pc)
{
	short ss=(short)f*10;
	pc.PushBack(ss);
}

void UnPackZipFloat(float& f,Pocket& pc)
{
	short ss;
	pc.PopFront(ss);
	f=ss*0.1f;
}
void PackZipTka(tka t,Pocket& pc)
{
	PackZipFloat(t.x,pc);
	PackZipFloat(t.y,pc);
}
void UnPackZipTka(tka& t,Pocket& pc)
{
	UnPackZipFloat(t.x,pc);
	UnPackZipFloat(t.y,pc);
}
void PackZipSld(sld& s,Pocket& pc)
{
	unsigned char tmpc=0;
	tmpc|=s.pl&7;
	tmpc|=((s.type&7)<<3);
	if(s.life>50)tmpc|=(1<<6);
	if(s.way.top)tmpc|=(1<<7);
	pc.PushBack(tmpc);//pl,type,life,way is
	tmpc=(unsigned char )s.group_id;
	pc.PushBack(tmpc);//group_id
	PackZipTka(s.pos,pc);//pos
	if(s.way.beg)PackZipTka(s.way.beg->v,pc);//way
}
void UnPackZipSld(sld& s,Pocket& pc)
{
	tka ttt;
	char tmpc;
	bool way_is=false;
	pc.PopFront(tmpc);//pl,type,life,way is
	s.pl=(tmpc&7)|16;
	s.type=((tmpc>>3)&7);
	s.life=(tmpc&(1<<6))?100:50;
	s.way.renull();
	if((tmpc&(1<<7)))way_is=true;
	pc.PopFront(tmpc);//group_id
	s.group_id=tmpc;
	UnPackZipTka(s.pos,pc);//pos
	if(way_is)
	{
		UnPackZipTka(ttt,pc);//way
		s.way.AddEl(ttt);
	}

	s.nav.setBoth(1,0);
	s.a=0;
	s.enemy=-1;
	s.vel.setBoth(0,0);
	s.zar=0;
}

void PackZipBase( base &b, Pocket &pc ) {
	unsigned char tmpc=0;
	tmpc|=b.pl&7;
	tmpc|=((b.level&7)<<3);
	if(b.send.x)tmpc|=(1<<7);
	if(b.pl==-1)tmpc|=(1<<6);
	pc.PushBack(tmpc);//pl,type,is send
	if(b.send.x)PackZipTka(b.send,pc);
}
void UnPackZipBase(base& b,Pocket& pc)
{
	unsigned char tmpc;
	pc.PopFront(tmpc);//pl,type,send is
	b.pl=(tmpc&7);
	b.level=((tmpc>>3)&7);
	if((tmpc&(1<<7)))UnPackZipTka(b.send,pc);
	if((tmpc&(1<<6)))b.pl=-1;
}

void PackGameContent( Pocket &pc ) {
	pc.PushBack( my_seed );

	{
		base *bp = Bases;

		for ( size_t i = 0; i < BasesNum; i++, bp++ ) {
			PackZipBase(* bp, pc );
		}
	}

	{
		sld *sldp = Units;

		for ( size_t i = 0; i < MAXSLD; i++, sldp++ ) {
			if ( sldp->life ) {
				PackZipSld( *sldp, pc );
			}
		}
	}

}

void UnPackGameContent( Pocket &pc ) {
	FullClearField();
	my_seed = GameTime + 1;
	MisNum = 0;

	pc.PopFront( my_seed );

	{
		base *bp = Bases;

		for ( size_t i = 0; i < BasesNum; i++, bp++ ) {
			UnPackZipBase( *bp, pc );
		}
	}

	{
		{
			sld *sldp = Units;

			for ( size_t i = 0; i < MAXSLD; i++, sldp++ ) {
				sldp->way.renull();
			}

			::std::memset( Units, 0, MAXSLD * sizeof( sld ) );

		}

		{
			UnitsNum = 0;
			sld *sldp = Units;

			while ( pc.GetNum() )
			{
				UnPackZipSld( *sldp, pc );
				sldp++;
				UnitsNum++;
			}
		}
	}

	UnSelect();
}

void SendGameContent()
{
	Pocket pc;
	PackGameContent(pc);
	pc.Send();
	Sleep(1000);
	UnPackGameContent(pc);

}
void RecvGameContent()
{
	Pocket pc;
	pc.Recv();
	UnPackGameContent(pc);
}
