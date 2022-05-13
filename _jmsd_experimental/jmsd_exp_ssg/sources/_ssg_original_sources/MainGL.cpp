#include "MainGL.h"

#include "Textures.h"
#include "Game.h"
#include "vbo.h"
#include "Polygon.h"
#include "Wid.h"


HGLRC hRC;		// Постоянный контекст рендеринга
HDC hDC;			// Приватный контекст устройства GDI
HWND		hWnd;// Сохранение дискриптора окна	   
DEVMODE dmScreenSettings;			// Режим работы


int WIDTH;
int HEIGHT;
int defWIDTH;
int defHEIGHT;
float BackColor[3];

void Begin2D ( void )
{
  glDisable ( GL_DEPTH_TEST );
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, WIDTH, HEIGHT,0);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
}

void End2D ( void )
{
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  
}


GLvoid ReSizeGLScene(GLsizei Width, GLsizei Height)
{
//	End2D();
//	Begin2D();
}

GLvoid InitGL(GLsizei Width, GLsizei Height)	// Вызвать после создания окна GL
{
	Texture = new CTexture();
 

    LoadGLTextures();	
	glClearColor(0,0,0,0);
	

//	ChangeBackColor(0);

	glDisable(GL_NORMALIZE);

	
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	Begin2D();
	glEnable(GL_TEXTURE_2D);


	//glShadeModel(GL_FLAT);
//	glEnable(GL_LINE_STIPPLE); 
	//glEnable(GL_LINE_SMOOTH);
}

void InitWindow()
{
	DEVMODE tmpd;
	EnumDisplaySettings(0,ENUM_CURRENT_SETTINGS,&tmpd);

	MoveWindow(hWnd,0,0,WIDTH,HEIGHT,0);

	memset(&dmScreenSettings, 0, sizeof(DEVMODE));	// Очистка для хранения установок
	dmScreenSettings.dmSize	= sizeof(DEVMODE);		// Размер структуры Devmode
	dmScreenSettings.dmPelsWidth	= WIDTH;			// Ширина экрана
	dmScreenSettings.dmPelsHeight	= HEIGHT;			// Высота экрана
	dmScreenSettings.dmFields	= DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;	// Режим Пиксела
	
	dmScreenSettings.dmDisplayFrequency=tmpd.dmDisplayFrequency;
	


	ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);	
	OnCreate(hWnd);
}
void SetResolution(char res)
{
	MyConf.screen=res;
	if(MyConf.screen>4)MyConf.screen=0;
	switch(res)
	{
		case 0:WIDTH= defWIDTH;HEIGHT=defHEIGHT;break;
		case 1:WIDTH= 1280;HEIGHT=1024;break;
		case 2:WIDTH= 1024;HEIGHT=768;break;
		case 3:WIDTH= 1280;HEIGHT=768;break;
		case 4:WIDTH= 800;HEIGHT=600;break;
	}
	

}

void ChangeResolution( const char res ) {
	vbo.UnInitVBO();

	if ( global_quantityOfObstacles ) {
		vbo.UnInitPolyVBO();
	}

	SetResolution(res);
	InitWindow();
	UnInitWDJ();
	InitWDJ();
	UpdateWidData();
	Begin2D();
	
//	GenList(PolyList,DrawPoly);
//	GenList(PolyShadowList,DrawPolyShadow);

	vbo.InitVBO();

	if ( global_quantityOfObstacles ) {
		vbo.InitPolyVBO();
	}
}

GLvoid OnCreate( HWND hWnd ) {
	RECT Screen; // используется позднее для размеров окна
	GLuint PixelFormat;
	PIXELFORMATDESCRIPTOR pfd = { sizeof( PIXELFORMATDESCRIPTOR ) };

    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cRedBits = 8;
    pfd.cGreenBits = 8;
    pfd.cBlueBits = 8;
    pfd.cAlphaBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;

	hDC = GetDC( hWnd ); // Получить контекст устройства для окна
	PixelFormat = ChoosePixelFormat( hDC, &pfd );

	// Найти ближайшее совпадение для нашего формата пикселов
	if ( !PixelFormat ) {
		MessageBox( 0, L"Can't Find A Suitable PixelFormat.", L"Error", MB_OK | MB_ICONERROR );
		PostQuitMessage( 0 );
		return;
	}

	if ( !SetPixelFormat( hDC, PixelFormat, &pfd ) ) {
		MessageBox( 0, L"Can't Set The PixelFormat.", L"Error", MB_OK | MB_ICONERROR );
		PostQuitMessage( 0 );
		return;
	}

	hRC = wglCreateContext( hDC );

	if ( !hRC ) {
		MessageBox( 0, L"Can't Create A GL Rendering Context.", L"Error", MB_OK | MB_ICONERROR );
		PostQuitMessage( 0 );
		return;
	}

	if ( !wglMakeCurrent( hDC, hRC ) ) {
		MessageBox( 0, L"Can't activate GLRC.", L"Error", MB_OK | MB_ICONERROR );
		PostQuitMessage( 0 );
		return;
	}

	GetClientRect( hWnd, &Screen );
	InitGL( Screen.right, Screen.bottom );
}
