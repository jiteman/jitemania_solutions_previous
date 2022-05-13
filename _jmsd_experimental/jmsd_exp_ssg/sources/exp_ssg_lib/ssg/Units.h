#pragma once


#include "MyFuns.h"
#include "st.h"

#include <memory.h>


//////параметры юнитов/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define SOLDAOUTFIELD 0.1f  //ускорение юнита от краёв поля(чтобы за пределы не особо уходил)

#define SOLDA 0.005f  //ускорение юнита

#define SOLDTREN 0.9f  //замедление
#define SOLDGIPTREN 0.8f
#define SOLDMAXVELSQ 0.04f

#define MANSIZE 1  //размер юнита
#define MANSIZESQ 1 //квадрат размера юнита
#define MANREACHTARGET 0.3f // квадрат точности прибытия юнита
#define MANSIZE_DOUBLE_AND_SQ 4//  (MANSIZE*2)^2
#define PUSHKOEF 0.035f// сила отталкивания
#define SMALLNAV 0.4f //чем меньше, тем точнее навигация - не переборщи, а то не сдвинется
#define SMALLNAV3 0.02f //чем меньше, тем точнее навигация - для стрельбы
#define SMALLNAV2 0.01f //чем меньше, тем точнее навигация
#define SMALLVEL 0.001f //скорость-остановка

#define ANG_VAL_NUM 5//число чкоростей поворота юнита (в рад.: 0.5 1 2 4 8)

#define FORMKOEF 2 //построение солдат в прямоугольник
#define FORMSPREAD 3 //расстояние между рядами
#define MAN_LOOK_DIST 200 //радиус обзора юнита
#define MAN_LOOK_DIST_SQR 10000 //квадрат радиуса обзора юнита


#define MAX_DEFENDER_DIST 30


#define MAXSLD 20000
#define UNIT_TYPES 6//число типов юнитов
#define DEAD_SLD_NUM 1000// Мах кол-во трупов юнитов на карте

//////параметры карты/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#define FIELDSIZEX 1024
//#define FIELDSIZEY 1024//размеры поля в клетках
//#define KLET_SIZE 4//размер клетки
//#define TOKLETSIZE(a) (int(a)>>2)

#define FIELDSIZEX 800
#define FIELDSIZEY 800//размеры поля в клетках
#define KLET_SIZE 6//размер клетки
#define TOKLETSIZE(a) (int(a)/KLET_SIZE)

#define OUT_FIELD 64//значение границы поля
#define SCROLLDIST 1  //


struct sld_dead
{
	tka pos;
	char ang;
	char type;//&7 игрок(первые 3 бита) остальное - тип юнита

};
struct sld
{
	tka pos,nav,vel;
	__int16 a;
	__int16 enemy;
	__int16 group_id;
	stek<tka>way;//маршрут движения(промеж.)

	char pl;//&7 игрок(первые 3 бита)...&8-защита, &16-всегда атакует &32-не двигается
	char type;
	unsigned char zar;//перезарядка
	char life;//жизни



};

extern sld Units[MAXSLD];// юниты
extern sld_dead DeadUnits[DEAD_SLD_NUM];//трупы юнитов
extern int Current_dead;

extern st<int>**QUNid;
//extern char **QUNex;// - наличие игроков
extern char QUNex[FIELDSIZEX][FIELDSIZEY];

extern size_t UnitsNum;

extern unsigned int GameTime;

extern int SelInfo[UNIT_TYPES];//хранение числа выделенных юнитов различных типов
extern int UnInfo[PLAYERS_NUM][UNIT_TYPES];//хранение числа юнитов различных типов


extern unsigned char Zarad[UNIT_TYPES];//время перезарядки
extern unsigned char Attack[UNIT_TYPES];//атака
extern unsigned char Defend[UNIT_TYPES];//защита от ближней атаки
extern unsigned char MissDefend[UNIT_TYPES];//защита от снаряда
extern unsigned char ObserveDist[UNIT_TYPES];//1/2 стороны квадрата обзора в поиске врагов
extern unsigned char Velocity[UNIT_TYPES];//скорость



void InitUnits();
void UnInitUnits();
void DeleteUnit(int i);
int AddUnit(tka pos,char pl,char type,tka send);

void CurrectTPoint(tka*t,tka from,tka to);

void CutRoute(sld*s);
void CorrectRoute(sld*s);

void MoveSld();


void MoveCheck(sld*s);

void UpdateDefenders();
tka CalcCenter(st<int> *s);
tka CalcCenterG(st<int> *s);
//void CurrectTPoint(tka*t,tka*from);

//возвращает id юнита, ближайшего к точке c из клетки (ii,jj); поиск идёт в радиусе rad клеток, ищется юнит игрока из фильтра pl_filter
int Look(int ii,int jj,tka& c,int rad,char pl_filter);

void MakeAlert(int eni,st<int> *tmpst);

void FullClearField();
