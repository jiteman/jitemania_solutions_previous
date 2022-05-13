#include "ssg_Application.h"

#include "ssg/MainGL.h"
#include "ssg/Graph2d.h"
#include "ssg/vbo.h"

#include "ssg/Control.h"

#include "ssg/Sound.h"

#include "ssg/Game.h"

#include "ssg/Filer.h"

#include "ssg/sock.h"

#include "ssg/zamer.h"

#include "event_controller/Event_controller.h"


int ssg_Application() {
	HINSTANCE const the_instance_handler = GetModuleHandle(NULL);

	EnumDisplaySettings(0,ENUM_CURRENT_SETTINGS,&global_dmScreenSettings);
	defWIDTH=global_dmScreenSettings.dmPelsWidth;
	defHEIGHT=global_dmScreenSettings.dmPelsHeight;

	LoadSetings();
	int i,t;
	WNDCLASS	wc; // Структура класса Windows для установки типа окна

	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc		= (WNDPROC) WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= the_instance_handler;
	wc.hIcon			= ::LoadIcon( the_instance_handler, "icon1.ico" );
	wc.hCursor			= ::LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= NULL;
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= "OpenGL WinClass";

	if ( !RegisterClass( &wc ) ) {
		MessageBox( 0, "Failed To Register The Window Class.", "Error", MB_OK | MB_ICONERROR );
		return FALSE;
	}

	global_hWnd = CreateWindow( "OpenGL WinClass", "Str", WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 0, WIDTH, HEIGHT, NULL, NULL,	the_instance_handler, NULL );

	if ( !global_hWnd ) {
		MessageBox( 0, "Window Creation Error.", "Error", MB_OK | MB_ICONERROR );
		return FALSE;
	}

	InitWindow();

	ShowWindow(global_hWnd, SW_SHOW);
	SetCursorPos(WIDTH/2, HEIGHT/2);
//	ShowCursor(1);

	UpdateWindow(global_hWnd);
	SetFocus(global_hWnd);

	SetVSync(1);

	if ( !prepare() ) return 1;

	if ( !vbo.InitVBO() ) return 1;

	zamer_timeBeginPeriod(1);

	ShowCursor(0);

	size_t LastTick[ GAME_TIMERS_NUM ] = {};
	size_t CurTick = 0;
	size_t const TickNum[ GAME_TIMERS_NUM ] = { 1000, 30, 20, 15 };

	for ( ;; ) {
		BB(0);

		MSG msg = {}; // Структура сообщения Windows

		while ( PeekMessage( &msg, NULL, 0, 0, PM_NOREMOVE ) ) {
			if ( GetMessage( &msg, NULL, 0, 0 ) ) {
				TranslateMessage( &msg );
				DispatchMessage( &msg );
			} else {
				return 0;
			}
		}

		BB1(0);

		if ( !( FixSpeed || ( status & ( 16 ) ) ) ) {
			GameStep();
		}

		CurTick = GetTickCount();

		for ( t = 0; t < GAME_TIMERS_NUM; t++ ) {
			if ( CurTick - LastTick[ t ] >= TickNum[ t ] ) {
				LastTick[ t ] = CurTick;

				switch ( t ) {
					case 0:
						fps = ababua;
						ababua = 0;
						break;

					case 1:
						BB( 2 );
						MyDisplay();				// Нарисовать сцену
						BB1( 2 );

						BB( 32 );
						SwapBuffers( global_hDC );			// Переключить буфер экрана
						BB1( 32 );

						if ( sock_init ) {
							InitSockProc();
						}

						break;

					case 2:
						PlayMusic();
						MouseProc();
						break;

					case 3:
						if ( is_online ) {
							GameStep();
						} else if ( !( ( status & ( 16 ) ) || !FixSpeed ) ) {
							for( i = 0; i < MyConf.steps_per_frame; i++ ) {
								GameStep();
							}
						}

						break;

					default:
						break;
				}
			}
		}
	}
}
