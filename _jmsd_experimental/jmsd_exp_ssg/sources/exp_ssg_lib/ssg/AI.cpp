#include "AI.h"

#include "Game.h"
#include "Bases.h"
#include "Diplomation.h"
#include "GUI.h"
#include "Menu.h"
#include "sock.h"
#include "Control.h"
#include "Zamer.h"


char enemy;
unsigned int score[ PLAYERS_NUM ];
//int GOOD_F_COST[PLAYERS_NUM];// нормарльная численность формации
int Fnum=0;
Formation *global_formations;
/*
char AttackPriority[UNIT_TYPES*UNIT_TYPES]={2, 7, 4, 3,-10, 4,
											-5, 1, 4, 6, 10, 1,
											-10, -7, 3, 5, 4, 10,
											4, -10, 0, 3, 1, 5,
											10, -10, 2, 6, 4, 6,
											7, -4, -10, 6, 1, 6};
*/

void RenullAI() {
	enemy = 0;
	Fnum = 0;
}

void UpDateEnemy() {
//	unsigned summ = 0;
//	int m = 0;

	int const cost[] = { 1, 4, 5, 2, 4, 8 };

	size_t pl_num = 0;
	size_t pl_bases_num[ 8 ] = {};

	for ( size_t i = 0; i < PLAYERS_NUM; i++ ) {
		if ( PLAYER_IS_HERE( i ) ) {
			pl_num++;
		}

		pl_bases_num[ i ] = 0;
		score[ i ] = 0;

		for ( size_t j = 0; j < UNIT_TYPES; j += 1 ) {
			score[ i ] += UnInfo[ i ][ j ] * cost[ j ];
		}
	}

	if ( !pl_num ) return;

	for ( size_t j = 0; j < BasesNum; j += 1 ) {
		size_t const i = ( Bases + j )->pl;

		if ( i != -1 ) {
//			if((Bases+j)->level)
//				score[(Bases+j)->pl]+=BaseUpgradeCost[(Bases+j)->level-1];
			score[ i ] += 100;
			pl_bases_num[ i ]++;
		}
	}

	size_t k = 0;

	for ( size_t i = 1; i < PLAYERS_NUM; i += 1 ) {
		if ( score[ k ] < score[ i ] ) {
			k = i;
		}

		if ( !Building ) {
			if ( COMPUTER_AI( i ) && pl_bases_num[ i ] > 2 * BasesNum / pl_num ) {
				if ( UnitsNum < 6000 ) {
					Building=GROW_TIME;
					TryBuildUnits( ( char )( ~( 1 << i ) ) );
				}
			}
		}
		//if(score[m]>score[i])m=i;
	}
	//if(is_online){enemy=(char)k;return;}

	unsigned int summ = 0;

	for ( size_t i = 0; i < PLAYERS_NUM; i += 1 ) {
		if ( i != k ) {
			summ += score[ i ];
		}
	}

	if ( summ < score[ k ] ) {
		global_diplomation.SetAll( 0 );

		if ( enemy != ( char )k ) {
			global_onScreenMessages.AddElToBeg(
				MyMessage( std::string( LSTRING( "Player ", "»грок " ) ) +
					IntToString( k ) +
					std::string( LSTRING( " - everyone's enemy"," - враг народа" ) ),
				( char )k ) );
		}
	} else {
		if ( enemy != ( char )k ) {
			global_diplomation.SetAll( unsigned char( 0xFF ) );
		}
	}

	enemy = ( char )k;

	{
 	    for ( size_t i = 0; i < PLAYERS_NUM; i += 1 ) {
			if ( i != k ) {
				//Dipl.MakeFriends(i,m);
				global_diplomation.MakeEnemies( i, enemy );
			}

			if ( !is_online ) {
				if ( status & 2 ) {
					global_diplomation.MakeEnemies( i, MyConf.MY_PLAYER );
				}
			}
		}

	    global_diplomation.UpdateUnits();
	}
}

void ActAIFormation( Formation *ff ) {
//	tka vv( 0, 0 );
//	tka tmpt;
	tka tmpt2;
	base *bp = Bases;
	Formation *fp = global_formations;
	float koef = 0;
//	float ll;
	float ml = 999999;

	const char plpl = ff->first->pl & 7;

	if ( !COMPUTER_AI( plpl ) ) return;

	const char tmpc = global_diplomation.d[ plpl ];
	const tka tmpt = ff->first->pos;

	int k = -1;

	{
		for ( size_t i = 0; i < BasesNum; i++, bp++ ) {
			if ( bp->pl == -1 || MyPow2( bp->pl ) & tmpc ) {
				const float ll = KVAZIL( bp->pos, tmpt );

				if ( ml > ll ) {
					ml = ll;
					k = i;
				}
			}
		}
	}

	tka vv;

	for ( int i = 0; i < Fnum; i++, fp++ ) {
		if ( MyPow2( ( fp->first->pl & 7 ) ) & tmpc ) {
			const float ll = KVAZIL( fp->first->pos, tmpt );
			//if(ml<ll*1.5f) continue;

			if ( ll > 500 ) continue;

			koef = ( ff->num - fp->num ) / ( 10 + ll );
			vv += ( fp->first->pos - tmpt ) * koef;
		}
	}

	if ( vv.getX() || vv.getY() ) {
		vv /= ::abs( vv.getX() ) + ::abs( vv.getY() );
		vv *= ( ml < 200 ) ? ml : ( ml * 0.5f );
		tmpt2 = tmpt + vv;
	} else {
		if ( k == -1 ) return;

		tmpt2 = ( Bases + k )->pos;
	}

	if ( tmpt2.getX() < 0 ) {
//		tmpt2.x = 100;
		tmpt2 = tka( 100, tmpt2.getY() );
	}

	if ( tmpt2.getY() < 0 ) {
//		tmpt2.y = 100;
		tmpt2 = tka( tmpt2.getX(), 100 );
	}

	if ( tmpt2.getX() > MapW * KLET_SIZE ) {
//		tmpt2.x = ( float )MapW * KLET_SIZE - 100;
		tmpt2 = tka( ( float )MapW * KLET_SIZE - 100, tmpt2.getY() );
	}

	if ( tmpt2.getY() > MapH * KLET_SIZE ) {
//		tmpt2.y = ( float )MapH * KLET_SIZE - 100;
		tmpt2 = tka( tmpt2.getX(), ( float )MapH * KLET_SIZE - 100 );
	}

	SendUnits( &ff->un, ff->num, tmpt2, tmpt, 0, 1, 3.3f );
}

void ActAI() {
	int i;
	int j;
	sld *cur_unit = Units;
	Formation *fp;

	BB( 17 );

	UpDateEnemy();
	UpdateWiner();
/*
	for(int i=0;i<8;i++)
		if(COMPUTER_AI(i))
			AutoCreateGroup(i);
*/
	Fnum = 0;

	for ( i = 0; i < MAXSLD; i++, cur_unit++ ) {
		if ( cur_unit->life && cur_unit->enemy == -1 ) {
			for ( j = 0, fp = global_formations; j < Fnum; j++, fp++ ) {
				//if(fp->first->type==cur_unit->type)
				if ( !( ( fp->first->pl ^ cur_unit->pl ) & 7 ) ) {
					if ( KVAZIL( cur_unit->pos, fp->first->pos ) < FORMATION_SIZE ) break;
				}
			}

			if ( j == Fnum ) {
				fp->first = cur_unit;
				fp->num = 1;
				fp->un.renull();
				Fnum++;

				if ( Fnum == MAX_FORMATIONS ) break;
			} else {
				fp->num++;
			}

			fp->un.AddEltoBeg( i );
		}
	}


	//tmp_info=Fnum;
	//DoForEach(Grp,ActAIGroup,MAX_GROUPS_NUM);
	DoForEach( global_formations, ActAIFormation, Fnum );

	BB1(17);
}
