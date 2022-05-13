#pragma once



#include "Units.h"

//////параметры баз/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX_BASE 40//max кол-во баз
#define BASE_SIZE 8//размер баз
#define BASE_OTST 10//ближе к краю карты базы не строить
#define GROW_TIME 2000
#define UPDATE_TIME 50
#define DEFEND_TIME 300

#define BASE_STATES_NUM 1
#define BASE_LEVEL_NUM 5

struct base
{
	tka pos,send;
	char pl;
	unsigned int level;
	void UpdatePL();
//	void BuildUnits();
//	void TryUpgrade();
//	void MakeAction(int id);
};

extern base Bases[ MAX_BASE ];//базы
extern size_t BasesNum;
//extern int BaseUpgradeCost[BASE_LEVEL_NUM-1];
//extern int Building;

void SetBasesSend(st<int>*sl,tka snd);
void DeleteBase(int i);
void AddBase( const tka &pos, char pl );
void UpDateBases();
void GrowBases();

bool TryBuildUnits(char pl);
