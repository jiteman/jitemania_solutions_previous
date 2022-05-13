#include "MainGL.h"

#include "Textures.h"
#include "Game.h"
#include "vbo.h"
#include "Polygon.h"
#include "Wid.h"


HGLRC global_hRC;		// Постоянный контекст рендеринга
HDC global_hDC;			// Приватный контекст устройства GDI
HWND global_hWnd;// Сохранение дискриптора окна
DEVMODE global_dmScreenSettings;			// Режим работы


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


GLvoid ReSizeGLScene(GLsizei /*Width*/, GLsizei /*Height*/)
{
//	End2D();
//	Begin2D();
}

bool InitGL( GLsizei /*Width*/, GLsizei /*Height*/ )	// Вызвать после создания окна GL
{
//	Texture = new CTexture();


    if ( !LoadGLTextures() ) return false;

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

	return true;
}

void InitWindow()
{
	DEVMODE tmpd;
	EnumDisplaySettings(0,ENUM_CURRENT_SETTINGS,&tmpd);

	MoveWindow(global_hWnd,0,0,WIDTH,HEIGHT,0);

	memset(&global_dmScreenSettings, 0, sizeof(DEVMODE));	// Очистка для хранения установок
	global_dmScreenSettings.dmSize	= sizeof(DEVMODE);		// Размер структуры Devmode
	global_dmScreenSettings.dmPelsWidth	= WIDTH;			// Ширина экрана
	global_dmScreenSettings.dmPelsHeight	= HEIGHT;			// Высота экрана
	global_dmScreenSettings.dmFields	= DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;	// Режим Пиксела

	global_dmScreenSettings.dmDisplayFrequency=tmpd.dmDisplayFrequency;

	ChangeDisplaySettings(&global_dmScreenSettings, CDS_FULLSCREEN);

	OnCreate(global_hWnd);
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

bool OnCreate( HWND hWnd_p ) {
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

	global_hDC = GetDC( hWnd_p ); // Получить контекст устройства для окна
	PixelFormat = ChoosePixelFormat( global_hDC, &pfd );

	// Найти ближайшее совпадение для нашего формата пикселов
	if ( !PixelFormat ) {
		MessageBox( 0, "Can't Find A Suitable PixelFormat.", "Error", MB_OK | MB_ICONERROR );
		PostQuitMessage( 0 );
		return false;
	}

	if ( !SetPixelFormat( global_hDC, PixelFormat, &pfd ) ) {
		MessageBox( 0, "Can't Set The PixelFormat.", "Error", MB_OK | MB_ICONERROR );
		PostQuitMessage( 0 );
		return false;
	}

	global_hRC = ::wglCreateContext( global_hDC );

	if ( !global_hRC ) {
		MessageBox( 0, "Can't Create A GL Rendering Context.", "Error", MB_OK | MB_ICONERROR );
		PostQuitMessage( 0 );
		return false;
	}

	if ( !wglMakeCurrent( global_hDC, global_hRC ) ) {
		MessageBox( 0, "Can't activate GLRC.", "Error", MB_OK | MB_ICONERROR );
		PostQuitMessage( 0 );
		return false;
	}

	RECT Screen;
	::GetClientRect( hWnd_p, &Screen );

	if ( !InitGL( Screen.right, Screen.bottom ) ) {
		MessageBox( 0, "Can't initialize OpenGL infrastructure or load resources.", "Error", MB_OK | MB_ICONERROR );
		PostQuitMessage( 0 );
		return false;
	}

	return true;
}

GLvoid gluOrtho2D( GLdouble const left, GLdouble const right, GLdouble const bottom, GLdouble const top ) {
    return ::glOrtho( left, right, bottom, top, -1, 1 );
}
