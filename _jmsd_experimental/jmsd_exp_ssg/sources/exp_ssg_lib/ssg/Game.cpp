#include "Game.h"

#include "Bases.h"
#include "GUI.h"
#include "Polygon.h"
#include "Ai.h"
#include "Menu.h"
#include "Missiles.h"
#include "Group.h"
#include "Warfog.h"
#include "Control.h"
#include "Network.h"
#include "Diplomation.h"
#include "MainGl.h"
#include "Graph2d.h"
#include "remSnd.h"
#include "Sound.h"
#include "Wid.h"
#include "SendRecv.h"
#include "Animation.h"

#include "Zamer.h"

#include "sock.h"
#include "myfuns.h"


GameConfig MyConf;
NewGameParams nGameParams;

char comp=~0,PlHere=~0;
char status=8;//статус человека-игрока: &8- показ инфо  &16-пауза &128-показать дипломатию 2-не принимать перемирия
int MapW,MapH;
bool Warfog_is=false, FixSpeed=true;

//PlayerParams PlParams[8];

//bool Building_is=0;
//int Build_start=1000;
int Building=0;

unsigned int GameTime=0;


void revansh() {
	PlHere = ~0;
	MyConf.PlNum = 8;
	global_onScreenMessages.AddElToBeg( MyMessage( LSTRING( "Reinforcement..", "Пришло подкрепление" ) ) );

	for ( size_t p = 0; p < PLAYERS_NUM; p++ ) {
		tka const tmp = RandFreeTka();

		for ( size_t i = 0; i < REVANSH_NUM / PLAYERS_NUM; i++ ) {
			AddUnit( tmp, ( char ) p | 16, i % UNIT_TYPES, tka( 0, 0 ) );
		}
	}

}
/*
void KillAllUnits(char pl)
{
	int i=0;
	sld*sldp=Units;
	for(;i<MAXSLD;i++,sldp++)
		if(sldp->life)
			if((sldp->pl&7)==pl)
				DeleteUnit(i);

}

void UpdateWiner()
{
	int i,c=0,k;
	char bs=0,tmpc=1;
	base*bp=Bases;
	for(i=0;i<BasesNum;i++,bp++)
		if(bp->pl!=-1)
		{
			bs|=MyPow2(bp->pl);
	//		if(PlHere&(~bs))return;
		}
	for(i=0;i<8;i++,tmpc=tmpc<<1)
		if(PlHere&tmpc)
			if(!(bs&tmpc))
			{
				if(i==MyConf.MY_PLAYER)
				{
					mes.AddElToBeg(MyMessage("Ты проиграл."));
					if(!is_online){revansh();return;}
				}
				else
					mes.AddElToBeg(MyMessage(std::string("Игрок")+IntToString(i)+std::string(" проиграл."),i));
				KillAllUnits(i);
				PlHere&=~tmpc;
			}

	tmpc=1;
	for(i=0;i<8;i++,tmpc=tmpc<<1)
		if(PlHere&tmpc){c++;k=i;}
	if(c==1)
	{
		if(k==MyConf.MY_PLAYER)
			mes.AddElToBeg(MyMessage("Ты победил!!!"));
		else
			mes.AddElToBeg(MyMessage("Игрок победил.",k));
		PlHere&=~tmpc;
	}

	if(c<=1)
	{
		revansh();
	}
}

*/

void UpdateWiner() {
	int sm = 0;
	int k = 0;

	char tmpc = 1;

	for ( size_t i = 0; i < 8; i++, tmpc = tmpc << 1 ) {
		if ( PlHere & tmpc ) {
			if ( !score[ i ] ) {
				if ( i == MyConf.MY_PLAYER ) {
					global_onScreenMessages.AddElToBeg( MyMessage( LSTRING( "You lose.", "Ты проиграл." ) ) );

					if ( !is_online ) {
						revansh();
						return;
					}
				} else {
					global_onScreenMessages.AddElToBeg(
						MyMessage( ::std::string( LSTRING( "Player ", "Игрок " ) ) + IntToString( i ) + ::std::string( LSTRING( " lose.", " проиграл." ) ), i ) );
				}

				PlHere &= ~tmpc;
			} else {
				sm++;
				k = i;
			}
		}
	}

	if ( sm == 1 ) {
		if ( k == MyConf.MY_PLAYER ) {
			global_onScreenMessages.AddElToBeg( MyMessage( LSTRING( "You win!!!", "Ты победил!!!" ) ) );
		} else {
			global_onScreenMessages.AddElToBeg(
				MyMessage( ::std::string( LSTRING( "Player ", "Игрок " ) ) + IntToString( k ) + ::std::string( LSTRING( " wins.", " победил." ) ), k ) );
		}
	}

	if ( sm <= 1 ) {
		revansh();
	}
}

void ClearGame()
{
	int i,j;
	UnitsNum=0;
	BasesNum=0;
	MisNum=0;
	if(global_quantityOfObstacles)DelPolys();
	DeleteAllGroups();
	ClearFog();
	for(i=0;i<MAXSLD;i++){(Units+i)->way.renull();(Units+i)->life=0;}
	for(j=0;j<UNIT_TYPES;j++)
	{
		SelInfo[j]=0;
	    for(i=0;i<PLAYERS_NUM;i++)
			UnInfo[i][j]=0;
	}
	UnSelect();
	RenullAI();
}

void NewGame()
{
	int i,j,lll,bb;
	int fl;
	tka startpos[PLAYERS_NUM],ttt;


	GameTime=0;
	net_cnt=0;
	ClearGame();

	if(!is_online)
	{
		PlHere=(1<<(MyConf.PlNum-1))-1;
		if(PLAYER_IS_HERE(MyConf.MY_PLAYER)) PlHere|=(1<<(MyConf.PlNum-1));
		else PlHere|=(1<<MyConf.MY_PLAYER);
		comp=~(1<<MyConf.MY_PLAYER);
	}else
	{
		nGameParams.Accept();
		PlHere=((1<<MyConf.PlNum)-1);
		ServParams.net_time=NET_TIME;
		ServParams.prm1=0;
		ClientParamsTMP.game_summ=0;
		ClientParamsTMP.prm=0;
	}
	MapW = (MyConf.map_size+1)*(FIELDSIZEX/4);
	MapH = (MyConf.map_size+1)*(FIELDSIZEY/4);

	global_diplomation.SetAll( static_cast< char >( 0xFF ) );

	DrawButton((float)(WIDTH/2-300),(float)(HEIGHT/2-20),600,40,LSTRING("Creating random map...","Идёт создание случайной карты..."),0);
//	DrawMyText((int)(WIDTH/2-100),(int)(HEIGHT/2-15),200,30,std::string("Идёт создание случайной карты..."),ArialFont);
	SwapBuffers(global_hDC);

	CreateRandPolys();
	//memset(PlParams,0,sizeof(PlayerParams));

	for(i=0;i<(MAX_BASE/4)*(MyConf.bases_num+1);i++)
	{
		do{ttt=RandFreeTka();}while(ttt.x<BASE_OTST||ttt.y<BASE_OTST||ttt.x>MapW*KLET_SIZE-BASE_OTST||ttt.y>MapH*KLET_SIZE-BASE_OTST);
		AddBase(ttt,-1);
	}


	for(i=0;i<PLAYERS_NUM;i++)
	{
//		PlParams[i].money=500;
	if(PLAYER_IS_HERE(i))
	{

		lll=1000;
		do
		{
			fl=0;
			bb=MyRand()%BasesNum;
			startpos[i]=(Bases+bb)->pos;

			for(j=0;j<i;j++)if(abs(startpos[i].x-startpos[j].x)+abs(startpos[i].y-startpos[j].y)<lll)fl=1;
			lll--;
		}while(fl);
		//(Bases+bb)->level=BASE_LEVEL_NUM-1;
		(Bases+bb)->pl=i;

		for(j=0;j<300;j++)AddUnit(startpos[i]+tka(RND11*4,RND11*4),i|16,3,tka(0,0));

	}
	}
	ChangeScale(5,false);
	GoToTkaOnMap(startpos[MyConf.MY_PLAYER]);
	//Build_start=8000;
	//Building_is=0;
	Building=0;
	global_OrdMan.renull();
	FixSpeed=true;

}

bool prepare()
{
//	InitKrug();

	for ( int i = 0; i < ( 1 << SQRT_MEM_VAL ); i++ ) {
		sqrtMem[ i ] = i * i;
	}

	//srand( (unsigned)GetTickCount() );
	my_seed = ( unsigned )GetTickCount();

//	for(i=0;i<PLAYERS_NUM;i++)GOOD_F_COST[i]=i*10+50;
	MapW = 100;
	MapH = 100;

	if ( !global_initializeSoundSubsystem() ) return false;

	SetEffectsVolume( MyConf.sound_val / 100.0f );
	SetMusucVolume( MyConf.music_val / 100.0f );

	InitUnits();
    InitPoly();
	InitWDJ();

	status|=16;

	PLColor[0][0]=1.0f;
	PLColor[0][1]=0.0f;
	PLColor[0][2]=0.0f;

	PLColor[1][0]=0.0f;
	PLColor[1][1]=0.5f;
	PLColor[1][2]=0.0f;

	PLColor[2][0]=0.0f;
	PLColor[2][1]=0.2f;
	PLColor[2][2]=1.0f;

	PLColor[3][0]=0.0f;
	PLColor[3][1]=0.8f;
	PLColor[3][2]=0.8f;

	PLColor[4][0]=1.0f;
	PLColor[4][1]=0.0f;
	PLColor[4][2]=1.0f;

	PLColor[5][0]=1.0f;
	PLColor[5][1]=1.0f;
	PLColor[5][2]=0.0f;

	PLColor[6][0]=0.4f;
	PLColor[6][1]=0.4f;
	PLColor[6][2]=0.4f;

	PLColor[7][0]=1.0f;
	PLColor[7][1]=1.0f;
	PLColor[7][2]=1.0f;

	return true;
}

void GameStep()
{

	if(sock_init)return;

	if(is_online)
	{
	if(net_cnt>=net_time)
	{
		if(pock_exch_is)
		{
			//if(!net_time_send_tmp)net_time_send_tmp=net_time;
			ClientParamsTMP.prm|=1;
			return;
		}

		net_cnt=0;

		PrepareClientMessage();

		MakeDataExchange();
	}else net_cnt++;
	}
	BB(1);
	BB(22);


	CurPlay.renull();
	ababua++;
	GameTime++;
	ActAnimations();
	BB1(22);
	MoveSld();
	BB(24);
	FlyMiss();
	BB1(24);
	BB(23);
	if(GameTime%UPDATE_TIME==0)
	{
		UpDateBases();
//		Build_start++;
	}


/*	if(Building_is)
	{
		if(GameTime%GROW_TIME==0)
		{
			if(!TryBuildUnits())Building_is=false;
			if(UnitsNum>9000)Building_is=false;
		}
	}else
	if(Build_start>=UnitsNum)
	{
		Building_is=true;
		Build_start/=2;
	}
*/
	if(Building>0)
	{
		if(Building==1)TryBuildUnits( static_cast< char >( 0xFF ) );
		Building--;
	}

	if(GameTime%DEFEND_TIME==0)UpdateDefenders();
	if(GameTime%AI_TIME==3)
	{
		ActAI();
	}

	if(Warfog_is)
	{
		if(GameTime%WARFOG_TIME==0)UpdateWarfog();
		GrowWarfog();
	}
	BB1(23);

	if(!is_online)
	{
		BB(29);
		global_OrdMan.SwapOut();
		global_OrdMan.DoOrdOut();
		global_OrdMan.SwapOut();
		BB1(29);
	}

	BB1(1);
}
void NewGameParams::Accept()
{
	my_seed=seed;
	Warfog_is=war_fog;
	MyConf.MY_PLAYER=MY_PLAYER;
	MyConf.PlNum=PlNum;
	MyConf.map_size=map_size;
	MyConf.poly_num=poly_num;
	MyConf.bases_num=bases_num;
	comp=cmp;
}
void NewGameParams::Store()
{
	war_fog=Warfog_is;
	seed=my_seed;
	MY_PLAYER=MyConf.MY_PLAYER;
	PlNum=MyConf.PlNum;
	map_size=MyConf.map_size;
	poly_num=MyConf.poly_num;
	bases_num=MyConf.bases_num;
	cmp=comp;
}
