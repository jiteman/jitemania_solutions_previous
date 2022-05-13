#include "Packer.h"

#include "Units.h"
#include "SendRecv.h"

#include <memory.h>


Pocket::Pocket()
	: t_num( 0 ), num( 0 ), start( 0 )
{}

Pocket::Pocket(int front_space,int back_space):num(0)
{
	start=front_space;
	t_num=front_space+back_space;
	arr=new char[t_num];
}

Pocket::Pocket(const Pocket& v)
{
	if(v.num)
	{
		arr=new char[v.num];
		::memcpy(arr,v.arr+v.start,v.num);
	}
	start=0;
	num=v.num;
	t_num=num;
}
Pocket::~Pocket()
{
	Clear();
}
void Pocket::Send()
{
	MySend((char*)&num,sizeof(num));
	MySend(arr+start,num);
}
void Pocket::Recv()
{
	Clear();
	MyRecv((char*)&num,sizeof(num));
	if(!num)return;
	arr=new char[num];
	t_num=num;
	MyRecv(arr+start,num);

}
void Pocket::GrowBack(int d_num)
{
	char *tmp=new char[t_num+d_num];
	if(t_num)
	{
		if(num)	memcpy(tmp+start,arr+start,num);
		delete[]arr;
	}
	arr=tmp;

	t_num+=d_num;
}

void Pocket::GrowFront(int d_num)
{
	char *tmp=new char[t_num+d_num];
	if(t_num)
	{
		if(num)	memcpy(tmp+start+d_num,arr+start,num);
		delete[]arr;
	}
	start+=d_num;
	arr=tmp;
	t_num+=d_num;
}

void Pocket::PushBack( char *dt, const int dt_num ) {
	if ( num + start + dt_num >= t_num ) {
		GrowBack( std::max( dt_num, VECT_GROW_NUM ) );
	}

	::memcpy( arr + num + start, dt, dt_num );
	num += dt_num;
}

bool Pocket::PopFront(char*dt,int dt_num)
{
	if(dt_num>num)return false;
	if(dt)memcpy(dt,arr+start,dt_num);
	num-=dt_num;
	start+=dt_num;
	return true;
}

void Pocket::Clear()
{
	if(t_num)	delete[]arr;
	t_num=0;
	num=0;
	start=0;
}
int Pocket::GetNum()
{
	return num;
}
char* Pocket::GetBytes()
{
	return arr+start;
}



void PackSel(Pocket&pc, st<int>* sl)
{
	char tmpa[MAXSLD/8+1];
	__int16 i,i2=0,i1=32000;
	el<int>*tmpt=sl->beg;
	memset(tmpa,0,MAXSLD/8+1);

	while(tmpt)
	{
		i=tmpt->v;
		if(i<i1)i1=i;
		if(i>i2)i2=i;
		tmpa[i>>3]|=(1<<(i&7));
		tmpt=tmpt->next;
	}

	i1/=8;
	i2/=8;
	pc.PushBack(i1);
	pc.PushBack(i2);
	pc.PushBack(tmpa+i1,i2-i1+1);
}

void UnPackSel(Pocket& pc,st<int>*sl)
{
	char tmpc,*b;
	__int16 i,i1,i2,j,cn;
	pc.PopFront(i1);
	pc.PopFront(i2);
	b=pc.GetBytes();
	cn=i1*8;
	for(i=i1;i<=i2;i++,b++)
	if(*b)
	{

		tmpc=1;

		for(j=0;j<8;j++)
		{
			if((*b)&tmpc){	sl->AddEltoBeg(cn);}

			cn++;
			tmpc=tmpc<<1;
		}

	}else cn+=8;

	pc.PopFront(0,i2-i1+1);
}
