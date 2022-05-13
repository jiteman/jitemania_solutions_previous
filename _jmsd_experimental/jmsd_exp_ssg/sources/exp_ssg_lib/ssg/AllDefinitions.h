#pragma once

//#include "myfuns.h"

//////математика/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define HALF_PI 1.570796326
#define PI 3.141592653f
#define DOUBLE_PI 6.283185307f
#define PI_180 0.017453292
#define SQRT2 1.41421356
#define SQRT3 1.7320508f
#define SMALLEST_FLOAT 0.000001f
#define absD(a) ((a<0)?(-(a)):(a))
#define sgnD(a) ((a<0)?(-1):1)
#define NOTNULL(a) ((a)?a:0.000001f)


//#define KVAZIL(a,b) (abs((a).x-(b).x)+abs((a).y-(b).y))  //расстояние (почти)


#define SQRT_MEM_VAL 8//число итераций для вычисления корня (2^SQRT_MEM_VAL - размер массива для хранения квадратов)
#define MY_RAND_MAX 0xFFFFFFFF
#define RND01 (((float)MyRand())/MY_RAND_MAX)
#define RND11 (((float)((int)(MyRand()-(MY_RAND_MAX>>1))))/(MY_RAND_MAX>>1))
#define MyPow2(i) (1<<(i))

//#define POLY_TEXTURE_NUM 6 ///кол-во текстур для многоугольников
#define LENG_SQR_DEF(x,y) ((x)*(x)+(y)*(y))

#define glMYLine2(x1,y1,x2,y2) glBegin(GL_LINES);glColor4f(0,0,0,0.5f);glVertex2f(x1,y1);glColor4f(1,1,1,0.5f);glVertex2f(x2,y2);glEnd();

//#define MENU_TXT_H 25
//туман войны///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#define KRUG_RES 32//качестао круга
#define DRAW_KRUG(x,y,r) {glPushMatrix();	glTranslated(x,y,0);	glScaled(r,r,r);	glCallList(KrugList);	glPopMatrix();}
#define MAX_FOGS 140//
#define FOG_DIST 220
#define FOG_LOOK_DIST 32000
#define FOG_LOOK_SPEED 1000
#define FOG_LOOK_DIV 0.01

*/
//////параметры игры/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PLAYERS_NUM 8
#define REVANSH_NUM 3000
