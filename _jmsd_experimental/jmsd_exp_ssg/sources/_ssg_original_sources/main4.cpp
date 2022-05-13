#include "Menu.h"
#include "Control.h"
#include "Wid.h"
#include "Graph2d.h"
#include "Bases.h"
#include "Sound.h"
#include "MainGl.h"
#include "Game.h"
#include "Group.h"
#include "GUI.h"
#include "Ai.h"
#include "remSnd.h"
#include "Polygon.h"
#include "Filer.h"
#include "vbo.h"
#include "Report.h"

#include "Zamer.h"

#include "sock.h"

#include "temporary_windows_include.h"

#include "sss.h"


LRESULT CALLBACK WndProc( HWND hWnd, unsigned int Message, WPARAM wParam, LPARAM lParam ) {
	switch ( Message ) { // Тип сообщения
		case WM_RBUTTONDOWN:
			if ( ::ActMenu( 1 ) ) {
				break;
			}

			//status&=~5;
			omR = MOUSETKA();		
			SelIsR = 1;
			break;

		case WM_MOUSEWHEEL:
			if ( cur_wdj == -1 ) {
				dscale = ( float )( int( wParam ) > 0 ? 0.15f : -0.15f );
			}

			break;

		case WM_RBUTTONUP:
			if ( !SelIsR ) {
				break;
			}

			SelIsR = 0;
			::SendSelectedUnits( MouseOnBase == -1 ? omR : ( Bases + MouseOnBase )->pos, MOUSETKA(), wParam == MK_CONTROL );
			//SetBasesSend(MOUSETKA);		
			break;
  //  case WM_MOUSEMOVE:


//		curx=((mPos.x-WIDTH /2+KLET_SIZE*5))/KLET_SIZE;
//		cury=((-mPos.y+HEIGHT /2+KLET_SIZE*5))/KLET_SIZE;


//	break;
		case WM_LBUTTONDOWN:
			if ( cur_wdj != -1 ) {
				::ActWid();
			} else {
				if ( ::ActMenu( 0 ) ) {
					::PlayWavFile( std::string( "click" ) );
					break;				
				}

				omL = ::MOUSETKA();
				SelIs = 1;
			}
			
			break;

		case WM_LBUTTONUP:
			if ( !SelIs ) {
				break;
			}

			SelIs = 0;

			if ( wParam != MK_CONTROL ) {
			   ::SelectArea( omL, ::MOUSETKA(), wParam == MK_SHIFT );

			   if ( !sel.beg && !GrpSel.beg ) {
					::SelectAreaB( omL, ::MOUSETKA(), wParam == MK_SHIFT );
			   }
			} else {
				tka tmpt = ( omL + ::MOUSETKA() ) * 0.5f;
				::ChangeScale( 1 / ::minF( ( ::absF( ::MOUSEX() - omL.x ) / WIDTH ) , ::absF( ::MOUSEY() - omL.y ) / HEIGHT ), false );
				::GoToTkaOnMap(tmpt);
			
				/*float ns=minF((WIDTH*SCALE)/(absF(omx-curx-mPos.x)+1),(HEIGHT*SCALE)/(absF(omy-cury-mPos.y)+1));
				if(ns>30)ns=30;
				curx=(int)(((curx+minF(omx-curx,int(mPos.x)))*ns)/SCALE);
     			cury=(int)(((cury+minF(omy-cury,int(mPos.y)))*ns)/SCALE);

				SCALE=ns;*/
			}
			
			break;

    case WM_KEYDOWN:
//		tmp_info=(int)wParam;

		if(wParam==115){SendMessage(hWnd,WM_DESTROY,0,0);break;}
		if(cur_wdj!=-1)
		{
			SendChar((char)wParam);
			break;
		}


		/*
		if(wParam==13)
		{
			mess="";
			status^=64;
			break;
		}

		
		if(status&64){if(wParam==8)mess.resize(mess.size()-1);else mess.push_back((char)(wParam));break;}
*/
		if(wParam==27)
		{
			if(cur_wdj==-1)
			{
				status|=16;
				cur_wdj=1;
			}

			break;
		}
		if(wParam>='0'&&wParam<='0'+UNIT_TYPES){SelectAllUnits(wParam-'0',true);break;}
//		if(wParam>='0'&&wParam<='0'+UNIT_TYPES){SelectGroup(wParam-'0');break;}

		if((int)wParam == 46)
			{ DeleteSelection();}
/*		{
			if(sel.beg)
				OrdMan.AddOrder(new Order(3,&sel,1));
			if(GrpSel.beg)
				OrdMan.AddOrder(new Order(4,&GrpSel,1));
		
		}*/
		

		if(wParam=='G')		
		{
			if(sel.beg)
				global_OrdMan.AddOrder(new Order(3,&sel,0));
			else
				global_OrdMan.AddOrder(new Order(5,0));

			//if(sel.beg) GroupSelected();else AutoCreateGroup(MyConf.MY_PLAYER);			
			break;		
		}

		if ( wParam == 'B' ) {
			if ( !Building ) {
				global_OrdMan.AddOrder( new Order( 5, 1 ) );
			}
		}

		if(wParam=='U')
		{
			if(GrpSel.beg)
				global_OrdMan.AddOrder(new Order(4,&GrpSel,0));
		//	DoForEach(GrpSel.beg,UnGroup);UpdateGroups();UpdateSelInfo();
			break;
		}
		//if(wParam=='H'){if(sel.beg)(Units+sel.beg->v)->pos.x+=2;break;}
		//if(wParam=='O')		{		Pocket pc;		PackGameContent(pc);		UnPackGameContent(pc);		}
		if(wParam=='Q'){dscale=0.15f;break;}
		if(wParam=='A'){dscale=-0.15f;break;}
		if(wParam=='Z'){dscale=-1;break;}
		if(wParam=='I'){status^=8;break;}
		if(wParam=='S'){GoToWDJ(10);break;}
		
		
		
		if(wParam==113){GoToWDJ(8);break;}
		if(wParam==114){GoToWDJ(7);break;}
		
		
		if ( wParam == 32 ) {
			if ( sel.beg ) {
				::GoToTkaOnMap( ( Units + sel.beg->v )->pos );
			} else {
				if ( GrpSel.beg ) {
					::GoToTkaOnMap( ( Units + ( global_groups + GrpSel.beg->v )->un.beg->v )->pos );
				} else {
					if ( selB.beg ) {
						::GoToTkaOnMap( ( Bases + selB.beg->v )->pos );
					} else {
						global_onScreenMessages.renull();
					}
				}
			}
			
			break;	
		}

		if ( wParam == 'D' ) {
			status ^= 128;
			break;
		}
		
		if ( is_online ) {
			break;
		}

		if ( wParam == 'P' ) {
			/*if(!status2)*/
			status ^= 16;
			break;
		}

		if ( wParam == 112 ) {
			FixSpeed = !FixSpeed;
			break;
		}

		if ( wParam == 116 ) {
			Warfog_is = !Warfog_is;
			break;
		}

		if ( wParam == 'F' ) {
			status ^= 2;

			if (status & 2 ) {
				global_onScreenMessages.AddElToBeg( MyMessage( LSTRING( "I will fight alone!", "Мне не нужны союзники. Пошли все на..." ) ) );
			} else {
				global_onScreenMessages.AddElToBeg( MyMessage( LSTRING( "I agree to have friends", "Эй! Если что - я союзник." ) ) );
			}
			
			::UpDateEnemy();
			break;
		}

		if ( wParam == 'R' ) {
			revansh();
		}

	break;	    

	case WM_CREATE:
		OnCreate(hWnd);
		
	break;

	case WM_DESTROY:
		
		//UnInitUnits();
	case WM_CLOSE:		
		global_uninitializeSoundSubsystem();

		//::CloseHandle(map_inserter_thread);
//		for(id=0;id<PlNum;id++)
//			if(PlHere&(1<<id))
//			closesocket (s[id]);
//		WSACleanup ();

		ClearSock();
		UnInitWDJ();
		UnInitUnits();
		UnInitPoly();
		SaveSetings();

		vbo.UnInitVBO();
		ChangeDisplaySettings(NULL, 0);
		wglMakeCurrent(hDC,NULL);
		wglDeleteContext(hRC);
		ReleaseDC(hWnd,hDC);
		
		
	OpenRpt();
	ZZZ.WriteReport();
	CloseRpt();


		PostQuitMessage(0);
		
	break;
	case WM_SIZE:
	ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));
	break;

	default:
		return (DefWindowProc(hWnd, Message, wParam, lParam));
	}

	return 0;
}

int sss_WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	EnumDisplaySettings(0,ENUM_CURRENT_SETTINGS,&dmScreenSettings);
	defWIDTH=dmScreenSettings.dmPelsWidth;
	defHEIGHT=dmScreenSettings.dmPelsHeight;

	LoadSetings();
	int i,t;
	MSG		msg;	// Структура сообщения Windows
	WNDCLASS	wc; // Структура класса Windows для установки типа окна
	DWORD LastTick[GAME_TIMERS_NUM]={0,0,0,0}, CurTick;
	const DWORD TickNum[GAME_TIMERS_NUM]={1000,30,20,15};

	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc		= (WNDPROC) WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInstance;
	wc.hIcon			= ::LoadIcon( hInstance, L"icon1.ico" );
	wc.hCursor			= ::LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= NULL;
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= L"OpenGL WinClass";
	
	if ( !RegisterClass( &wc ) ) {
		MessageBox( 0, L"Failed To Register The Window Class.", L"Error", MB_OK | MB_ICONERROR );
		return FALSE;
	}

	hWnd = CreateWindow( L"OpenGL WinClass", L"Str", WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 0, WIDTH, HEIGHT, NULL, NULL,	hInstance, NULL );
	
	if ( !hWnd ) {
		MessageBox( 0, L"Window Creation Error.", L"Error", MB_OK | MB_ICONERROR ); 
		return FALSE;
	}

	InitWindow();

	ShowWindow(hWnd, SW_SHOW);
	SetCursorPos(WIDTH/2, HEIGHT/2);
//	ShowCursor(1);
	
	UpdateWindow(hWnd);
	SetFocus(hWnd);
   
	SetVSync(1);
	
	prepare();

	
	if(!vbo.InitVBO())return 0;

	timeBeginPeriod(1);



    ShowCursor(0);
	for ( ;; ) {
		BB(0);

		while ( PeekMessage( &msg, NULL, 0, 0, PM_NOREMOVE ) ) {
			if ( GetMessage( &msg, NULL, 0, 0 ) ) {
				TranslateMessage( &msg );
				DispatchMessage( &msg );
			} else {
				return TRUE;
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
						SwapBuffers( hDC );			// Переключить буфер экрана
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
				}
			}
		}	   
	}
}
 