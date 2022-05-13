#include "Bases.h"

#include "Game.h"
#include "Diplomation.h"


base Bases[ MAX_BASE ]; // базы
size_t BasesNum = 0;
//int Building=0;
//int BaseUpgradeCost[BASE_LEVEL_NUM-1]={2,5,10,16};

void SetBasesSend(st<int>*sl,tka snd)
{
	el<int>*tmp=sl->beg;

	while(tmp)
	{
		(Bases+tmp->v)->send=snd;
		tmp=tmp->next;
	}

}


void DeleteBase(int i)
{
	BasesNum--;
	Bases[i]=Bases[BasesNum];


}

void AddBase( const tka &pos, const char pl ) {
	if ( BasesNum == MAX_BASE - 1 ) return;

	base *bp = Bases + BasesNum;

	bp->level = BasesNum % BASE_LEVEL_NUM;
	bp->pl = pl;
	bp->pos = pos;
	bp->send = tka();
	BasesNum++;

}

void base::UpdatePL() {
	int xx = maxF( int( pos.getX() / KLET_SIZE ) - 1, 0 );
	int yy = maxF( int( pos.getY() / KLET_SIZE ) - 1, 0 );
	int i;
	int j;
	int pp;

	char pl1=0,tmpc=1;
	for(i=minF(xx+2,MapW-1);i>=xx;i--)
		for(j=minF(yy+2,MapH-1);j>=yy;j--)
			pl1|=QUNex[i][j];

	if(!pl1 || (pl!=-1 && (pl1&(1<<pl))))return;

	for(pp=0;pp<PLAYERS_NUM;pp++)
	{
		if(tmpc&pl1)
			if(pl==-1||global_diplomation.AreEnemies(pl,pp))
			{
				pl=pp;
				return;
			}
		tmpc=tmpc<<1;
	}


}


void UpDateBases() {
	base *bp = Bases;

	for ( size_t i = 0; i < BasesNum; i++, bp++ ) {
		( bp++ )->UpdatePL();
	}
}

/*
void GrowBases()
{
	int i;
	base* bp=Bases;
	for(i=0;i<BasesNum;i++,bp++)
	{
		PlParams[bp->pl].money+=bp->level*2+1;
		//if(bp->level!=BASE_LEVEL4)bp->level++;else PlParams[bp->pl].money++;
	}

}
*/
/*
void base::BuildUnits()
{
	int j=0,k;
	tka ttt,ttt2;
	base* bp=Bases;
	static char bc[UNIT_TYPES*5]={5 , 0 , 0 , 2 , 0 , 0 ,
							 	  12 , 0 , 0 ,8 , 0 , 0 ,
								  13, 0 , 6 , 9 , 0 , 1 ,
								  20, 0 , 8, 14, 0 , 8 ,
								  20, 10 ,8, 15, 6 , 10  };

	if(pl==-1)return;

	for(j=0;j<UNIT_TYPES;j++)
		for(k=0;k<bc[j+level*UNIT_TYPES];k++)
		{
			AddUnit(pos,pl|16,j,send);

		}

}*/
bool TryBuildUnits(char pl)
{
//	int i,j,k;

	static unsigned char bc[ UNIT_TYPES * 5 ] =
		{
			25,  0,  0,  0,  0, 0,
			25,  0,  0, 15,  0, 0,
			25,  0, 10, 25,  0, 0,
			10,  0, 10, 10,  0, 10,
			10, 10, 10, 10, 10, 10
		};

	base *bp=Bases;

	for ( size_t i = 0; i < BasesNum; i++, bp++ ) {
		if ( bp->pl != -1 ) {
			if ( ( 1 << bp->pl ) & pl ) {
				for ( size_t j = 0 ; j < UNIT_TYPES; j++ ) {
					for ( size_t k = 0; k < bc[ j + bp->level * UNIT_TYPES ]; k++ ) {
						if ( AddUnit( bp->pos, bp->pl | 16, j, bp->send ) == -1 ) {
							return false;
						}
					}
				}
			}
		}
	}

	return true;
}
/*
void base::TryUpgrade()
{
	if(level==BASE_LEVEL_NUM-1)return;
	if(pl!=-1 )
		if(PlParams[pl].money>=BaseUpgradeCost[level])
		{
			PlParams[pl].money-=BaseUpgradeCost[level];
			level++;
		}
}
void base::MakeAction(int id)
{
	switch(id)
	{
	case 0:	TryUpgrade();
		break;
	}
}
*/
