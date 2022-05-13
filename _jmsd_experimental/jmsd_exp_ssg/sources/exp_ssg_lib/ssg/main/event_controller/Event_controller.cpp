#include "Event_controller.h"


#include "ssg/MainGL.h"
#include "ssg/Graph2d.h"
#include "ssg/vbo.h"

#include "ssg/GUI.h"
#include "ssg/Menu.h"
#include "ssg/wid.h"

#include "ssg/Sound.h"
#include "ssg/remSnd.h"


#include "ssg/Control.h"
#include "ssg/Game.h"

#include "ssg/Bases.h"
#include "ssg/Group.h"
#include "ssg/AI.h"
#include "ssg/Polygon.h"

#include "ssg/Filer.h"

#include "ssg/sock.h"

#include "ssg/Report.h"
#include "ssg/zamer.h"


LRESULT CALLBACK WndProc( HWND hWnd, unsigned int Message, WPARAM wParam, LPARAM lParam ) {
	switch ( Message ) { // Тип сообщения
		case WM_RBUTTONDOWN:
			if ( ::ActMenu( 1 ) ) {
				break;
			}

			//status&=~5;
			omR = ::MOUSETKA();
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
		if ( wParam == 115 ) {
			SendMessage( hWnd, WM_DESTROY, 0, 0 );
			break;
		}

		if ( cur_wdj != -1 ) {
			SendChar( ( char ) wParam );
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
		if ( wParam == 27 ) {
			if ( cur_wdj == -1 ) {
				status |= 16;
				cur_wdj = 1;
			}

			break;
		}

		if ( wParam >= '0' && wParam <= '0' + UNIT_TYPES ) {
			SelectAllUnits( wParam - '0', true );
			break;
		}

		if ( ( int )wParam == 'F' ) {
			DeleteSelection();
		}

		if ( wParam == 'G' ) {
			if ( sel.beg ) {
				global_OrdMan.AddOrder( new Order( 3, &sel, 0 ) );
			} else {
				global_OrdMan.AddOrder( new Order( 5, 0 ) );
			}

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
		{
//			bool const is_created = OnCreate(hWnd);
		}
		break;

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
		wglMakeCurrent(global_hDC,NULL);
		wglDeleteContext(global_hRC);
		ReleaseDC(hWnd,global_hDC);


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

