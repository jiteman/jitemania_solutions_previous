#pragma once

#include "myfuns.h"


#define MAX_FOG_NUM 1000
#define FOG_VIS_RAD 280
#define FOG_DIST 170
#define FOG_GROW_SPEED 40
#define WARFOG_TIME 50

#define FOG_CIRC_NUM 32 //число точек в круге
#define FOG_SMOOTH_KOEF 1.5f


struct fog_krug {

	tka pos;
	float rad;
	bool grow;

};


void ClearFog();
void DrawKrug(tka c,float rad);
void DrawWarfog();
void DrawWarfog2();
void UpdateWarfog();
void GrowWarfog();
