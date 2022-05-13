#pragma once

#include "Order.h"


class tka;

extern st<int> sel;
extern st<int> selB;
extern st<int> GrpSel;

extern float dscale;

extern float SCALE; 
extern bool SelIs;
extern bool SelIsR;

extern tka curpos;// текущий центр экрана
extern tka omL;//для мышки - хранить коорд. угла прямоугольника
extern tka omR;//для мышки - задать направление построения //правая кнопка мыши


long MOUSEX();
long MOUSEY();
tka MOUSETKA();

// #define MOUSEX ((mPos.x-WIDTH/2)/SCALE+curpos.x)
// #define MOUSEY ((mPos.y-HEIGHT/2)/SCALE+curpos.y)
// #define MOUSETKA (tka(float(mPos.x-WIDTH/2),float(mPos.y-HEIGHT/2))/SCALE+curpos)


void SelectArea(tka t1,tka t2,bool addU);
void SelectAreaB(tka t1,tka t2,bool addU);

void SendGroups(st<int>*gst,tka t1,tka t2,bool add);
void SendSelectedUnits(tka t1,tka t2,bool add=false);
void SendUnits(st<int>*sel1,int num,tka t1,tka t2,bool add,float FormKoef,float FormSpread);
void SelectAllUnits(char filt,bool add);

void ChangeScale(float ns, bool toCursor);
void CorrectCurPos();
void MouseProc();


void UnSelect();
void UpdateSelInfo();
void GroupSelected();
void DeleteSelection();
bool SelectGroup(int id);

void DoPlAction(Order*ord);
