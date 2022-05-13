#pragma once


#include "MyFuns.h"


#define ANIMATION_NUM 1000
#define MAX_ANIM_SIZE 5

struct sld;

class Anim
{
public:
	int ang;

	int des;
	tka pos;
	virtual void Draw()=0;

	Anim(){}
	virtual ~Anim(){}
};

class FlashAnim: public Anim
{
public:
	FlashAnim()
	{}

	FlashAnim( tka const &npos, int a );
	virtual void Draw();
};

class PMonAnim: public Anim
{
public:
	float color[4];
	PMonAnim(){}
	PMonAnim(sld& s);
	virtual void Draw();
};

extern Anim* anim[ANIMATION_NUM];
extern int AnimNum;

void ActAnimations();
void DrawAnimations();
void DeleteAnimation(int id);
void AddAnimation(Anim* an);
