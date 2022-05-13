#pragma once



extern char status;//статус человека-игрока: &8- показ инфо  &16-пауза &1-правим базы &32-выбрано меню &128-показать дипломатию 2-не принимать перемирия

#define here(i,j) ((i)>=0&&(j)>=0&&(i)<MapW&&(j)<MapH)

#define PLAYER_IS_HERE(pl) (PlHere&(1<<(pl)))
#define GAME_TIMERS_NUM 4// число внутреигровых таймеров
struct NewGameParams
{
	bool war_fog;
	unsigned char PlNum,map_size,poly_num,bases_num,cmp,MY_PLAYER;
	unsigned seed;

	void Accept();
	void Store();
};
struct GameConfig
{
	unsigned char PlNum,MY_PLAYER,map_size,poly_num,screen,bases_num,sound_val,music_val,steps_per_frame,ScrollSpeed;
	bool show_tracks,shadows_on,lifebar_on;
	float BackColor[3];
	float PolyColor[3];

};
/*
struct PlayerParams
{
	int money;
};
*/
extern GameConfig MyConf;
extern NewGameParams nGameParams;

extern int MapW,MapH;
extern bool Warfog_is, FixSpeed;
extern char comp,PlHere;

//extern bool Building_is;
//extern int Build_start;
extern int Building;

//extern PlayerParams PlParams[8];

void revansh();
void UpdateWiner();



void ClearGame();
void NewGame();
void prepare();

void GameStep();
