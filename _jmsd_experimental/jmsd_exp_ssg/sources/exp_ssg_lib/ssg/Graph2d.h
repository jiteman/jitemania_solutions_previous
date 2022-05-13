#pragma once


#include "Textures.h"
#include "myfuns.h"

//#include "Units.h"

#include "SFML/Graphics.hpp"


struct sld;
extern int ababua,fps;

extern tka mPos;
extern char MouseOnBase;//мышь над базой
extern char SCROLLSPEED;  // скорость прокрутки экрана
//static	GLuint KrugList;//для рисования круга - для тумана войны

extern float PLColor[8][3];

void GoToTkaOnMap(tka ps);

//void DrawQ(int i,int j);

void glMYLine( float x1, float y1, float x2, float y2 );
void glMYRectangle ( float x1, float y1, float x2, float y2 );

void DrawQuad ( float x, float y, float x1, float y1 );
void DrawQuad ( float x, float y, float x1, float y1,float txt_size );
void DrawQuad2 ( float x, float y, float x1, float y1,float tx1, float ty1,float tx2, float ty2 );

// void DrawQuad2 ( float x, float y, float x1, float y1, int txi1, int tyi1, int txi2, int tyi2, TextureImage &txt );
void DrawQuad2 ( float x, float y, float x1, float y1, int txi1, int tyi1, int txi2, int tyi2, ::sf::Texture const &txt );

void DrawQuad( int x, int y, int x1, int y1 );
void DrawQuad( int x, int y, int x1, int y1, float txt_size );
void DrawQuad2( int x, int y, int x1, int y1, float tx1, float ty1, float tx2, float ty2 );

//void DrawQuad2 ( int x, int y, int x1, int y1, int txi1, int tyi1, int txi2, int tyi2, TextureImage &txt );
void DrawQuad2( int x, int y, int x1, int y1, int txi1, int tyi1, int txi2, int tyi2, ::sf::Texture const &txt );

void DrawButton( float x, float y, float w, float h, std::string text, int style );
bool MouseOnButton( float x, float y, float w, float h );

void DrawQuadSimple( float x, float y, float x1, float y1 );

//void DrawArrow(float x1,float y1,float x2,float y2);
//void DrawCursor();
//void DrawSelection();
//void DrawBases();
//void DrawBackground();

void MyDisplay();


bool IsHere( const tka &t, float size );

void SetVSync(bool sync);
