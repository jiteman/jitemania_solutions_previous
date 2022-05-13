#pragma once


#include "st.h"


struct Diplomation
{
   char d[8];
   void SetAll(char vl){for(int i=0;i<8;i++)d[i]=vl&(~(1<<i));}
   Diplomation(){SetAll(0);}
   void Draw(int x0,int y0,int h);
   void UpdateUnits();

   void MakeEnemies(char p1,char p2)
   {
	   if(p1==p2)return;
	   d[p1]|=(1<<p2);
	   d[p2]|=(1<<p1);
   }
   void MakeFriends(char p1,char p2)
   {
	   d[p1]&=~(1<<p2);
	   d[p2]&=~(1<<p1);
   }

   inline bool AreEnemies( const char p1, const char p2 ) {
	   return ( d[ p1 ] & ( 1 << p2 ) ) != 0;
   }
};

extern Diplomation global_diplomation;

void AddSortedIntSt( st< int > *to, st< int > *from );
