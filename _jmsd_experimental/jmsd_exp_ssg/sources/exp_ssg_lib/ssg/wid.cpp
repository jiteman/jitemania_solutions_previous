#include "wid.h"

#include "Polygon.h"
#include "MainGl.h"
#include "Sound.h"
#include "Graph2d.h"
#include "Game.h"
#include "DrawPolygon.h"
#include "Filer.h"
#include "sock.h"
#include "GUI.h"

#include "myfuns.h"

#include <process.h>


wid** wdj=0;
int cur_wdj=0,cur_wdj_id=0;
char *wid_num=0;
void wid::InitDefaultData()
{
	data[0]=1;
}
wid::wid(char ntype,int nx,int ny,int nw,int nh,std::string ntext,int n_id)
{
	InitDefaultData();
	set(ntype,nx,ny,nw,nh,ntext,n_id);
}
void wid::set(char ntype,int nx,int ny,int nw,int nh,std::string ntext,int n_id)
{
	type=ntype;
	x=nx;
	y=ny;
	w=nw;
	h=nh;
	text=ntext;
	id=n_id;
}

wid::wid(const wid& a)
{
	set(a.type,a.x,a.y,a.w,a.h,a.text,a.id);
	memcpy(data,a.data,WID_DATA_SIZE);
}
wid& wid::operator=(const wid& a)
{
	set(a.type,a.x,a.y,a.w,a.h,a.text,a.id);
	memcpy(data,a.data,WID_DATA_SIZE);
	return *this;
}

bool wid::GetEnable()
{
	return ((data[0]&1)==1);
}

void  wid::SetEnable(bool en)
{
	if(en)data[0]|=1; else data[0]&=~1;

}

void wid::SetIntVal(int val)
{
	switch(type)
	{
	case 3:text[0]=val?'V':' ';
		break;
	case 4:text[0]=val;
		break;
	case 5:
		text[ 0 ] = -std::max( std::min( val, GetListSize( text.c_str() ) - 1 ), 0 ) - 1;
		break;
	}
}
int wid::GetIntVal()
{
	switch(type)
	{
	case 3:return (text[0]=='V');
		break;
	case 4:return text[0];
		break;
	case 5:
		return absF(text[0])-1;
		break;
	}
	return 0;
}


void NewForm()
{
	AddElem((wid*)0,&wdj);
	AddElem((char)0,&wid_num);
}

void NewWid(wid www) {
	int n = VectorSize( wdj ) - 1;

	if ( www.type == 5 ) {
		if ( www.text.empty() ) {
			www.text = " ";
		}

		www.text[ 0 ] = -1;
	}

	wid *old = wdj[ n ];
	wid_num[ n ]++;
	wdj[ n ] = new wid[ wid_num[ n ] ];

	int i = 0;

	for ( ; i < wid_num[ n ] - 1; i++ ) {
		wdj[ n ][ i ] = old[ i ];
	}

	wdj[ n ][ i ] = www;

	if ( old ) {
		delete[] old;
	}
}
void SetWidText(int id, std::string& txt)
{
	for(int i=wid_num[cur_wdj]-1;i>=0;i--)
		if(wdj[cur_wdj][i].id==id)
		{
			wdj[cur_wdj][i].text=txt;
			break;
		}
}

#define MENU_FORM_W 430  //ширина формы
#define MENU_FORM_U 150  //отступ формы сверху
#define MENU_FORM_B 60  //отступ вехней кнопки от верхнего края формы
#define MENU_BUTT_W 400	 //ширина кнопок
#define MENU_BUTT_H 40   //высота кнопок
#define MENU_BUTT_D 20   //расстояние между кнопками

void NewMenuForm(int nm,std::string* menu_strings)
{
	int j=1;
	NewForm();
	NewWid(wid(1,(WIDTH-MENU_FORM_W)/2,MENU_FORM_U,MENU_FORM_W,MENU_FORM_B+(MENU_BUTT_D+MENU_BUTT_H)*nm,menu_strings[0]));
	for(;j<=nm;j++)
	{
		NewWid(wid(0,(WIDTH-MENU_BUTT_W)/2,MENU_FORM_U+MENU_FORM_B+(MENU_BUTT_D+MENU_BUTT_H)*(j-1),MENU_BUTT_W,MENU_BUTT_H,menu_strings[j],j-1));
	}

}


void UnInitWDJ()
{
	int i,n=(int)VectorSize(wdj);
	for(i=0;i<n;i++)
		delete[] wdj[i];
	delete[] wdj;
	delete[] wid_num;
	wdj=0;
	wid_num=0;

}
bool PointInWDJ(int x,int y,wid* www)
{
	return (x>www->x && y>www->y && x<www->x+www->w && y<www->y+www->h);

}

wid* GetWDJ(int x,int y)
{
	int i,n;
	wid*www;
	if(cur_wdj==-1)return 0;

	n=wid_num[cur_wdj];
	www=wdj[cur_wdj]+n;

	for(i=n;i;i--)
	{
		www--;
		//if(www->type==0)
		if(www->GetEnable())
		if(PointInWDJ(x,y,www))
			return www;
	}
	return 0;
}
int GetListSize(const char* s)
{
	int i,n=strlen(s)-1,res=1;
	for(i=0;i<n;i++)
		if(s[i]==';')res++;
	return res;
}
std::string GetListCurItem(const char* s)
{
	int i,n=strlen(s)-1,res=absD(*s)-1;
	std::string ss;
	for(i=1;i<n;i++)
	{

		if(s[i]==';'){if(!res)break;res--;}
		else
		if(!res)ss.push_back(s[i]);
	}
	return ss;
}

void StandardWidAction(wid *www)
{
	int tmpi,n;

	if(www->type!=1 && www->type!=2)PlayWavFile(std::string("click"));

	switch(www->type)
	{

	case 3:
		www->text[0]=(www->text[0]=='V')?' ':'V';
		break;
	case 4:
		www->text[0]=(((int)mPos.x-www->x-www->h)*100)/(www->w-2*www->h);
		if(www->text[0]<0)www->text[0]=0;
		if(www->text[0]>100)www->text[0]=100;

		break;
	case 5:
		if(!www->text[0])break;
		n=GetListSize(www->text.c_str()+1);

		if((char)www->text[0]>0)
		{
			tmpi=((mPos.y-www->y)*(n+1))/www->h;
			if(tmpi)www->text[0]=tmpi;

			www->h/=1+n;
		}
		else
		{
			www->h*=1+n;
		}
		www->text[0]=-www->text[0];



	break;
	default:
		return;
	}

}

wid* GetWDJ(int id)
{
	int i,n;
	wid*www;
	if(cur_wdj==-1)return 0;

	n=wid_num[cur_wdj];
	www=wdj[cur_wdj]+n;

	for(i=n;i;i--)
	{
		www--;
		if(www->id==id)
			return www;
	}
	return 0;
}

void SendChar( char const ch ) {
	if ( cur_wdj_id == -1 ) return;


	wid *www = ::GetWDJ( cur_wdj_id );

	switch ( www->type ) {
		case 6:
			if ( ch == 8 ) {
				if ( www->text.size() ) {
					www->text.resize( www->text.size() - 1 );
				}

				break;
			}

			if ( ( ch >= '0' && ch <= '9' ) || ( ch >= 'A' && ch <= 'Z' ) || ch == 32 ) {
				www->text.push_back( ch );
			}

			break;
	}
}

void CloseWids()
{
	int i,n;
	wid*www;
	if(cur_wdj==-1)return;

	n=wid_num[cur_wdj];
	www=wdj[cur_wdj]+n;

	for(i=n;i;i--)
	{
		www--;
		switch(www->type)
		{
		case 5:
			if(www->text[0]>0)
			{
				n=GetListSize(www->text.c_str()+1);
				www->h/=1+n;
				www->text[0]=-www->text[0];
			}
			break;
		}
	}

}
void UpdateWidData()
{
	//static std::string txt_size[]={"маленький","средний","большой","огромный"};
	//static std::string txt_num[]={"мало","нормально","много","очень много"};

//		std::string tmp;
	int i;
	if(cur_wdj==-1)return;
	CloseWids();
	switch(cur_wdj)
	{
	case 2:
		GetWDJ(10)->SetIntVal(MyConf.map_size);
		GetWDJ(11)->SetIntVal(MyConf.poly_num);
		GetWDJ(12)->SetIntVal(MyConf.bases_num);
		GetWDJ(13)->SetIntVal(MyConf.PlNum-2);
		GetWDJ(14)->SetIntVal(MyConf.MY_PLAYER);
	break;
	case 4://графика
		GetWDJ(4)->SetIntVal(MyConf.screen);
		for(i=0;i<3;i++)
			{
				GetWDJ(10+i)->SetIntVal(int(BackColor[i]*100));
				GetWDJ(13+i)->SetIntVal(int(PolyColor[i]*100));
			}

	break;
	case 5:
		GetWDJ(10)->SetIntVal(MyConf.sound_val);
		GetWDJ(11)->SetIntVal(MyConf.music_val);
	break;
	case 6://настройки игры
	break;
	case 7:
		GetFiles( &GetWDJ( 4 )->text, ".str" );
		GetWDJ(0)->SetEnable(GetWDJ(4)->text[0]!=0);

	break;
	case 8:
		GetFiles( &GetWDJ( 4 )->text, ".str" );


	break;
	case 10:// Скорость игры
		GetWDJ(10)->SetIntVal(FixSpeed);
		GetWDJ(14)->SetIntVal(MyConf.steps_per_frame-1);

	break;
	case 11:// отображение
		GetWDJ(5)->SetIntVal(MyConf.show_tracks);
		GetWDJ(6)->SetIntVal(MyConf.shadows_on);
		GetWDJ(7)->SetIntVal(MyConf.lifebar_on);

	break;
	}
}
void GoToWDJ(int i)// если i==-2, то переход к пред. форме
{
	static int prev_wdj[MAX_WDJ_HISTORY], cid=0;
	if(i==-2)
	{
		cur_wdj=prev_wdj[cid];
		cid--;
		if(cid==-1)cid=MAX_WDJ_HISTORY;
	}else
	{
		cid++;
		if(MAX_WDJ_HISTORY==cid)cid=0;
		prev_wdj[cid]=cur_wdj;
		cur_wdj=i;
	}
	cur_wdj_id=-1;
	UpdateWidData();
}
void ActWid()
{
	int i;

	wid *www=GetWDJ(mPos.x,mPos.y);
	if(!www)return;
	int cw=www->id;
	cur_wdj_id=www->id;




	StandardWidAction(www);


	switch(cur_wdj)
	{
	case 0:
		switch(cw)
		{
		case 0:GoToWDJ(9);
			break;
		case 1:GoToWDJ(7);
			//{LoadGame();cur_wdj=-1;status&=~16;}
			break;
		case 2:GoToWDJ(3);
			break;
		case 3:SendMessage(global_hWnd,WM_CLOSE,0,0);
			break;
		}
		break;
	case 1:
		switch(cw)
		{
		case 0:status&=~16;GoToWDJ(-1);
			break;
		case 1:GoToWDJ(8);
			//{SaveGame();cur_wdj=-1;status&=~16;}
			break;
		case 2:GoToWDJ(7);
			//{LoadGame();cur_wdj=-1;status&=~16;}
			break;
		case 3:GoToWDJ(3);
			break;
		case 4:GoToWDJ(0);
			break;
		case 5:SendMessage(global_hWnd,WM_CLOSE,0,0);
			break;
		}
		break;
	case 2:
		switch(cw)
		{
		case 0:
			MyConf.map_size=GetWDJ(10)->GetIntVal();
			MyConf.poly_num=GetWDJ(11)->GetIntVal();
			MyConf.bases_num=GetWDJ(12)->GetIntVal();
			MyConf.PlNum=GetWDJ(13)->GetIntVal()+2;
			MyConf.MY_PLAYER=GetWDJ(14)->GetIntVal();
			Warfog_is=GetWDJ(105)->GetIntVal()?true:false;

			if(sock_init)
			{
				sock_init=4;
				GoToWDJ(-2);
			}
			else
			{
				NewGame();GoToWDJ(-1);status&=~16;
			}
			break;
		case 1:if(sock_init){sock_init=7;GoToWDJ(-2);}else GoToWDJ(-2);
			break;

		}
		break;
	case 3:// настройки
		switch(cw)
		{
		case 0:GoToWDJ(4);
			break;
		case 1:GoToWDJ(5);
			break;
		case 2:GoToWDJ(6);
			break;
		case 3:GoToWDJ(-2);
			break;
		}
		break;
	case 4://графические опции
		switch(cw)
		{
		case 102:
			GoToWDJ(11);
			break;
		case 0:
			if(MyConf.screen!=GetWDJ(4)->GetIntVal()) ChangeResolution(GetWDJ(4)->GetIntVal());
			for(i=0;i<3;i++)
			{
				MyConf.BackColor[i]=BackColor[i];
				MyConf.PolyColor[i]=PolyColor[i];
			}
			GoToWDJ(-2);
			break;
		case 1:GoToWDJ(-2);
			for(i=0;i<3;i++)
			{
				BackColor[i]=MyConf.BackColor[i];
				PolyColor[i]=MyConf.PolyColor[i];
			}
			break;
		}
		if(cw>=10 && cw<=12)BackColor[cw-10]=0.01f * GetWDJ(cw)->GetIntVal();
		if(cw>=13 && cw<=15)PolyColor[cw-13]=0.01f * GetWDJ(cw)->GetIntVal();
		//glClearColor((float)BackColor[0],(float)BackColor[1],(float)BackColor[2],1);
		break;
	case 5:// звук
		switch(cw)
		{
		case 0:
			MyConf.sound_val=GetWDJ(10)->GetIntVal();
			MyConf.music_val=GetWDJ(11)->GetIntVal();
		case 1:GoToWDJ(-2);
			SetEffectsVolume(MyConf.sound_val/100.0f);
			SetMusucVolume(MyConf.music_val/100.0f);
			break;
		case 10:
			SetEffectsVolume(GetWDJ(10)->GetIntVal()/100.0f);
			break;
		case 11:
			SetMusucVolume(GetWDJ(11)->GetIntVal()/100.0f);
			break;

		}
		break;
	case 6:// игровые опции
		switch(cw)
		{
		case 0:
			MyConf.ScrollSpeed=GetWDJ(11)->GetIntVal();
			GoToWDJ(-2);
			break;
		case 1:GoToWDJ(-2);
			break;
		case 2:GoToWDJ(10);
			break;
		}
		break;
	case 7:// Загрузить


		switch(cw)
		{
		case 0:
			//if(GetWDJ(4)->text.size()==1)break;
			if(LoadGame(GetListCurItem(GetWDJ(4)->text.c_str())+std::string(".str")))
			{ GoToWDJ(-1); status&=~16; }
			break;
		case 1:
			GoToWDJ(-2);
			break;
		}
		break;
	case 8:// Сохранить


		switch(cw)
		{
		case 0:
			if(GetWDJ(5)->text.size())
			{
				SaveGame(GetWDJ(5)->text+std::string(".str"));
				GoToWDJ(-1);
				status&=~16;
			}
			break;
		case 1:
			GoToWDJ(-2);
			break;
		case 4:
			GetWDJ(5)->text=GetListCurItem(GetWDJ(4)->text.c_str());
			break;
		}
		break;
	case 9:// новая игра


		switch(cw)
		{
		case 0:
			GoToWDJ(2);
			break;
		case 1://if(InitSockC()) {NewGame();GoToWDJ(-1);status&=~16;}
			ClearSock();
			hInitSockThread=(HANDLE)_beginthread(InitSockC,0,0);
			//sock_is_inited=true;
			GoToWDJ(12);
			GetWDJ(9)->text=LSTRING("Connecting to server...","Соединение с сервером...");
			//cur_wdj=prev_wdj;
			break;
		case 2:
			GoToWDJ(-2);
			break;
		}
		break;
	case 10:// Скорость игры
		switch(cw)
		{
		case 0:
			FixSpeed=GetWDJ(10)->GetIntVal()?true:false;

			MyConf.steps_per_frame=1+GetWDJ(14)->GetIntVal();
			GoToWDJ(-2);
			break;
		case 1:GoToWDJ(-2);
			break;
		}
		break;
	case 11:// отображение
		switch(cw)
		{
		case 0:
			MyConf.show_tracks=GetWDJ(5)->GetIntVal()?true:false;
			MyConf.shadows_on=GetWDJ(6)->GetIntVal()?true:false;
			MyConf.lifebar_on=GetWDJ(7)->GetIntVal()?true:false;

			GoToWDJ(-2);
			break;
		case 1:GoToWDJ(-2);
			break;
		}
		break;
	case 12:// соединение с сервером
		switch(cw)
		{
		case 0:
			ClearSock();
		//	GoToWDJ(-2);
			break;
		}
		break;
	}

}
void InitWDJ()
{
	std::string main_menu[]={LSTRING("main menu","главное меню"),LSTRING("New game","Новая игра"),LSTRING("Saved game","Сохранённая игра"),LSTRING("Settings","Настройки"),LSTRING("Exit","Выход")};
	std::string game_menu[]={LSTRING("gamr menu","игровое меню"),LSTRING("Back to game","Назад к игре"),LSTRING("Save game","Сохранить"),LSTRING("Load game","Загрузить"),LSTRING("Settings","Настройки"),LSTRING("Exit to main menu","Выйти в главное меню"),LSTRING("Exit to Windows","Выйти из игры")};
	std::string opt_menu[]={LSTRING("settings","настройки"),LSTRING("Graphic","Графика"),LSTRING("Sound","Звук"),LSTRING("Game","Игра"),LSTRING("Back","Назад")};
	std::string new_game[]={LSTRING("new game","новая игра"),LSTRING("Single","Одиночная"),LSTRING("Multiplayer","По сети"),LSTRING("Back","Назад")};
	//std::string new_game[]={"новая игра","Одиночная","По локальной сети","Назад"};

	NewMenuForm(4,main_menu);
	NewMenuForm(6,game_menu);

	NewForm();//2
	NewWid(wid(1,50,100,WIDTH-100,300,LSTRING("New game settings","Параметры новой игры")));

	NewWid(wid(0,WIDTH/2+10,360,150,30,LSTRING("Play","Играть"),0));
	NewWid(wid(0,WIDTH/2-160,360,150,30,LSTRING("Cancel","Отмена"),1));
	NewWid(wid(5,270,300,150,30,"#2;3;4;5;6;7;8;",13));
	NewWid(wid(5,270,250,150,30,LSTRING("#few;standard;many;max;","#мало;нормально;много;очень много;"),12));
	NewWid(wid(5,270,200,150,30,LSTRING("#few;standard;many;max;","#мало;нормально;много;очень много;"),11));
	NewWid(wid(5,270,150,150,30,LSTRING("#small;medium;large;huge;","#маленький;средний;большой;огромный;"),10));

	NewWid(wid(2,70,150,200,30,LSTRING("Map size","Размер карты")));
	NewWid(wid(2,70,200,200,30,LSTRING("Polygons","Препятствия")));
	NewWid(wid(2,70,250,200,30,LSTRING("Bases","Базы")));
	NewWid(wid(2,70,300,200,30,LSTRING("Players number","Число игроков")));

	NewWid(wid(2,WIDTH/2,    200,100,30,LSTRING("War fog","Туман войны")));
	NewWid(wid(3,WIDTH/2+150,200,30,30,"V",105));
	NewWid(wid(2,WIDTH/2,    150,100,30,LSTRING("Your color","Ваш цвет")));
	NewWid(wid(5,WIDTH/2+150,150,50,30,"#1;2;3;4;5;6;7;8;",14));

	NewMenuForm(4,opt_menu);//3


	NewForm();//графические опции//4
	NewWid(wid(1,50,100,WIDTH-100,400,LSTRING("Graphic settings","Настройки графики")));

	NewWid(wid(0,WIDTH/2+10,460,150,30,"OK",0));
	NewWid(wid(0,WIDTH/2-160,460,150,30,LSTRING("Cancel","Отмена"),1));

	NewWid(wid(2,215,230,250,25,LSTRING("Background color","Цвет фона")));
	NewWid(wid(2,470,230,250,25,LSTRING("Polygon color","Цвет препятствий")));

	NewWid(wid(2,100,270,100,25,LSTRING("Red:","Красный:")));
	NewWid(wid(4,215,270,250,25,"9",10));
	NewWid(wid(2,100,310,100,25,LSTRING("Green:","Зелёный:")));
	NewWid(wid(4,215,310,250,25,"9",11));
	NewWid(wid(2,100,350,100,25,LSTRING("Blue","Синий:")));
	NewWid(wid(4,215,350,250,25,"9",12));

	NewWid(wid(4,470,270,250,25,"9",13));
	NewWid(wid(4,470,310,250,25,"9",14));
	NewWid(wid(4,470,350,250,25,"9",15));


	NewWid(wid(5,300,180,150,25,"#default;1280x1024;1024x768;1280x768;800x600;",4));
	NewWid(wid(2,100,180,150,25,LSTRING("Screen resolution","Разрешение экрана")));
	NewWid(wid(0,500,180,200,25,LSTRING("Show/Hide settings","Отображение"),102));


	NewForm();//Звуковые опции//5
	NewWid(wid(1,50,100,WIDTH-100,300,LSTRING("Sound settings","Настройки звука")));

	NewWid(wid(0,WIDTH/2+10,360,150,30,"OK",0));
	NewWid(wid(0,WIDTH/2-160,360,150,30,LSTRING("Cancel","Отмена"),1));

	NewWid(wid(4,WIDTH/2+5,150,250,25,"9",10));
	NewWid(wid(2,WIDTH/2-210,150,200,25,LSTRING("Effects volume","Громкость эффектов")));
	NewWid(wid(4,WIDTH/2+5,200,250,25,"9",11));
	NewWid(wid(2,WIDTH/2-210,200,200,25,LSTRING("Music volume","Громкость музыки")));

	NewForm();//Игровые опции//6
	NewWid(wid(1,50,100,WIDTH-100,300,LSTRING("Game settings","Настройки игры")));

	NewWid(wid(0,WIDTH/2+10,360,150,30,"OK",0));
	NewWid(wid(0,WIDTH/2-160,360,150,30,LSTRING("Cancel","Отмена"),1));


	NewWid(wid(4,WIDTH/2+25,150,250,25,"9",11));
	NewWid(wid(2,WIDTH/2-220,150,200,25,LSTRING("Scroll speed","Скорость прокрутки экрана")));
	NewWid(wid(0,WIDTH/2-200,200,200,30,LSTRING("Game speed","Скорость игры"),2));

	NewForm();//Загрузка игры//7
	NewWid(wid(1,50,100,WIDTH-100,300,LSTRING("Game loading","Загрузка игры")));

	NewWid(wid(0,WIDTH/2+10,360,150,30,LSTRING("Load","Загрузить"),0));
	NewWid(wid(0,WIDTH/2-160,360,150,30,LSTRING("Cancel","Отмена"),1));

	NewWid(wid(2,WIDTH/2-240,180,200,25,LSTRING("Saved games:","Список сохранённых игр:")));
	NewWid(wid(5,WIDTH/2+20,180,250,25,"",4));


	NewForm();//Сохранение игры//8
	NewWid(wid(1,50,100,WIDTH-100,300,LSTRING("Game saving","Сохранение игры")));

	NewWid(wid(0,WIDTH/2+10,360,150,30,LSTRING("Save","Сохранить"),0));
	NewWid(wid(0,WIDTH/2-160,360,150,30,LSTRING("Cancel","Отмена"),1));
	NewWid(wid(2,WIDTH/2-210,180,200,25,LSTRING("Enter game's name:","Введите имя игры:")));
	NewWid(wid(2,WIDTH/2-230,210,200,25,LSTRING("or else choose from list:","Или выберите из списка:")));
	NewWid(wid(6,WIDTH/2,180,250,25,"",5));
	NewWid(wid(5,WIDTH/2,210,250,25,"",4));

	NewMenuForm(3,new_game);//новая игра//9

	NewForm();//Скорость//10
	NewWid(wid(1,WIDTH/2-200,100,400,200,LSTRING("Game speed","Скорость игры")));

	NewWid(wid(0,WIDTH/2+10,260,150,30,"OK",0));
	NewWid(wid(0,WIDTH/2-160,260,150,30,LSTRING("Cancel","Отмена"),1));

	NewWid(wid(2,WIDTH/2-150,150,250,25,LSTRING("Limit speed","Ограничить скорость")));
	NewWid(wid(3,WIDTH/2+140,150,30,25,"V",10));
	NewWid(wid(2,WIDTH/2-160,200,230,25,LSTRING("Game speed-up","Ускорение игры")));
	NewWid(wid(5,WIDTH/2+130,200,50,30,"#1;2;3;4;5;6;7;8;9;10;11;12;13;",14));

	NewForm();//Отображение//11
	NewWid(wid(1,50,100,WIDTH-100,300,LSTRING("Show/Hide settings","Настройки отображения")));

	NewWid(wid(0,WIDTH/2+10,360,150,30,"OK",0));
	NewWid(wid(0,WIDTH/2-160,360,150,30,LSTRING("Cancel","Отмена"),1));

	NewWid(wid(2,WIDTH/2-200,140,200,20,LSTRING("Unit's routes","Маршруты юнитов")));
	NewWid(wid(3,WIDTH/2+65,140,30,20,"V",5));
	NewWid(wid(2,WIDTH/2-200,170,200,20,LSTRING("Shadows","Тени")));
	NewWid(wid(3,WIDTH/2+65,170,30,20,"V",6));
	NewWid(wid(2,WIDTH/2-200,200,200,20,LSTRING("Unit's health-bar","Здоровье юнитов")));
	NewWid(wid(3,WIDTH/2+65,200,30,20,"V",7));

	NewForm();//Соединение с сервером//12
	NewWid(wid(1,WIDTH/2-200,HEIGHT/2-100,400,200,LSTRING("Multiplayer game","Сетевая игра")));

	NewWid(wid(2,WIDTH/2-150,HEIGHT/2-50,300,30,"...",9));

	NewWid(wid(0,WIDTH/2-100,HEIGHT/2,200,30,LSTRING("Cancel","Отменить"),0));
}
