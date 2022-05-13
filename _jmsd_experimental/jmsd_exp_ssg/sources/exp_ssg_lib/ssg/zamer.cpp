#include "zamer.h"

#include "Report.h"


#include "include_Windows.h"

#include <timeapi.h>


Zamer ZZZ;



void zamer_timeBeginPeriod( unsigned int const period ) {
	timeBeginPeriod( period );
}

void Zamer::EndBlock(int i)
{
	if(i>=0 && i<MAX_ZBLOCKS)
	if((blocks+i)->start)
	{
		(blocks+i)->val=((blocks+i)->val*(blocks+i)->num+timeGetTime()-(blocks+i)->start)/((blocks+i)->num+1);
		(blocks+i)->num++;
		(blocks+i)->start=0;
	}
}

void Zamer::StartBlock(int i)
{
	if(i>=0 && i<MAX_ZBLOCKS)
		if(!(blocks+i)->start)
			(blocks+i)->start=timeGetTime();
}

Zamer::Zamer()
{
	::std::memset( counter, 0, sizeof( counter[ 0 ] ) * MAX_COUNTERS );
}

void Zamer::WriteReport()
{
	int i,sz=0,j;
	std::string nm[MAX_ZBLOCKS];
	nm[0]="Messages";
	nm[1]="GameStep";
	nm[2]="Display";
	nm[3]="GameStep.MoveSld";
	nm[4]="Looking";
	nm[5]="Pushing";
	nm[6]="Action";
	nm[7]="MoveCheck";

	nm[8]="Display.MapOb.Back";
	nm[9]="Display.MapOb";
	nm[10]="Display.MapOb.Bases";
	nm[11]="Display.MapOb.Units";
	nm[12]="Display.MapOb.Anim";
	nm[13]="Display.MapOb.Poly";
	nm[14]="Display.MapOb.Select";
	nm[15]="Display.GUI";
	nm[16]="CurrectRoute";
	nm[17]="AI";
	nm[18]="Display.MapOb.Units.Kill";
	nm[19]="Display.MapOb.Units.Unit";
	nm[20]="Display.MapOb.Units.Miss";
	nm[21]="Display.WarFog";
	nm[22]="GameStep.Anim";
	nm[23]="GameStep.Other";
	nm[24]="GameStep.FlyMiss";

	nm[25]="GameStep.MoveSld.Clear";

	nm[26]="Display.WarFog.circ";
	nm[27]="PocketExchange";
	nm[28]="OrdersMulti";
	nm[29]="OrdersSingle";
	nm[30]="SafeGame";

	PutString("-------------");
	PutEnter();

	for(i=0;i<MAX_ZBLOCKS;i++)
		if(blocks[i].num)
		if(sz<(int)nm[i].size())sz=int(nm[i].size());

	for(i=0;i<MAX_ZBLOCKS;i++)
		if(blocks[i].num)
	{
		PutInt(i);
		PutChar1(9);
		PutString(nm[i]);
		for(j=sz-nm[i].size();j>=0;j--)
			PutChar1(' ');
		PutChar1(9);
		PutFloat(blocks[i].val);
		PutChar1(9);
		PutChar1(9);
		PutDW(blocks[i].num);
		PutEnter();
	}


	PutString("-------------");
	PutEnter();
	for(i=0;i<MAX_COUNTERS;i++)
	{
		PutInt(i);
		PutChar1(9);
		PutDW(counter[i]);
		PutEnter();
	}


	PutString("-------------");
	PutEnter();

}

