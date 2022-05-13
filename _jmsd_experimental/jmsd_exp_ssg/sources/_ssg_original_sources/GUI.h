#pragma once

#include "Graph2d.h"
#include "MainGl.h"

#include "st.h"

#include "jmsf/stdal/stdal_stl.h"


//extern float PLColor[8][3];

// английский/русский текст
#define LSTRING(e,r) e

#define MES_TXT_STEP 30
#define MES_BOX_X 10
#define MES_BOX_W 600
#define MES_BOX_Y (HEIGHT-ICON_SIZE*2)

struct MyMessage
{
	std::string val;
	float col[3];
	MyMessage(){}
	MyMessage(std::string ms){val=ms;col[0]=1;col[1]=1;col[2]=1;}
	MyMessage(std::string ms,char cl){val=ms;col[0]=PLColor[cl][0];col[1]=PLColor[cl][1];col[2]=PLColor[cl][2];}
};
struct FontChar
{
	int x,y;
	char w,h,of1,of2;
};
struct TextureImage;
struct MyFont
{
	FontChar ch[224];
	TextureImage* txt;
};

extern stek< MyMessage > global_onScreenMessages;
extern std::string mess;
extern MyFont ArialFont;

//////параметры меню/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ICON_SIZE 60	//размер иконки юнита
#define ICON_RAMA 10	//отступ иконок от края экрана

extern int tmp_info;

void DrawMes();
void DrawInformation();




void DrawMenu();
void DrawNumber(int x1,int y1,int h,int numb);

void DrawMyText(int x1,int y1,int w,int h,std::string& s, MyFont& fnt = ArialFont);
void DrawMyText(float x1,float y1,float scale,std::string& s, MyFont& fnt = ArialFont);
void DrawMyText(int x1,int y1,float scale,std::string& s, MyFont& fnt = ArialFont);
void DrawMyText(float x1,float y1,float w,float h,std::string& s, MyFont& fnt = ArialFont);

void DrawFrame(float x,float y,float w,float h,int txt=-1);
void DrawFrame(int x,int y,int w,int h,int txt=-1);
void DrawNumber(float x1,float y1,float h,int numb);

void DrawWid();
