#pragma once


#include "include_Windows.h"

#include "open_gl.h"


extern HGLRC global_hRC;		// Постоянный контекст рендеринга
extern HDC global_hDC;			// Приватный контекст устройства GDI
extern HWND		global_hWnd;// Сохранение дискриптора окна
extern DEVMODE global_dmScreenSettings;			// Режим работы


extern int WIDTH;
extern int HEIGHT;
extern int defWIDTH;
extern int defHEIGHT;
extern float BackColor[3];

void InitWindow();
void ChangeResolution(char res);
void SetResolution(char res);

void Begin2D ( void );
void End2D ( void );

bool InitGL(GLsizei Width, GLsizei Height);
GLvoid ReSizeGLScene(GLsizei Width, GLsizei Height);
bool OnCreate(HWND hWnd);


GLvoid gluOrtho2D( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top );
