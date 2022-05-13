#pragma once


#include "Units.h"

//////параметры AI/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define FORMATION_SIZE 200 // размер формации
#define MAX_FORMATIONS 1000 // max число формаций
#define AI_TIME 1000 // период активизации ии
#define COMPUTER_AI( pl ) ( comp & ( 1 << ( pl ) ) )


struct Formation {
	int num;
	sld *first;
	st< int > un;
};

extern char enemy;
extern unsigned int score[ PLAYERS_NUM ];
//extern int GOOD_F_COST[PLAYERS_NUM]; // нормальная численность формации
extern int Fnum;
extern Formation *global_formations;

void UpDateEnemy();
void ActAI();
void RenullAI();
