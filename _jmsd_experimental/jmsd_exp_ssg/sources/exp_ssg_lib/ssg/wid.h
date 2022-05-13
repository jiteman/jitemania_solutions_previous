#pragma once


#include <string>

#define WID_DATA_SIZE 1
#define MAX_WDJ_HISTORY 10

class wid
{
public:

	std::string text;
	int x,y,w,h,id;
	char type;
//0 - кнопка
//1 - форма
//2 - статич. текст
//3 - флаг
//4 - ползунок
//5 - выпадающий список
//6 - окно ввода текста

	char data[WID_DATA_SIZE];
//&1 - enable


	void set(char ntype,int nx,int ny,int nw,int nh,std::string ntext,int n_id);
	void InitDefaultData();
	wid(void){InitDefaultData();}


	wid(char ntype,int nx,int ny,int nw,int nh,std::string ntext,int n_id=-1);
	wid(const wid& a);
	wid& operator=(const wid& a);

	void Draw();

	int GetIntVal();
	void SetIntVal(int val);

	bool GetEnable();
	void  SetEnable(bool en);


};


extern wid** wdj;
extern int cur_wdj, cur_wdj_id;
extern char *wid_num;

void UpdateWidData();

void GoToWDJ(int i);// если i==-2, то переход к пред. форме

void ActWid();
void CloseWids();
void InitWDJ();
void UnInitWDJ();

bool PointInWDJ(int x,int y,wid* www);

wid* GetWDJ(int x,int y);
wid* GetWDJ(int id);

void SendChar(char ch);

int GetListSize(const char* s);
std::string GetListCurItem(const char* s);
