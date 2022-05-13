#pragma once

#include <algorithm>


template< class > class st;

struct Order;

template<class T>
void PackObj(char* bf, T* obj)
{

	memcpy(bf,obj,sizeof(*obj));
}
template<class T>
void UnPackObj(char* bf, T* obj)
{
	memcpy(obj,bf,sizeof(*obj));
}
/////////////////////////////////////////////////
#define VECT_GROW_NUM 100

class Pocket
{
public:
	Pocket();
	Pocket(int front_space,int back_space);
	Pocket(const Pocket& v);
	~Pocket();

	void Recv();
	void Send();

	void Clear();
	int GetNum();
	char* GetBytes();

	void PushBack(char*dt,int dt_num);
	bool PopFront(char*dt,int dt_num);

	template<class T>
	void PushBack(T Obj);

	template<class T>
	void PushFront(T Obj);


	template<class T>
	bool PopFront(T& Obj);

private:
	void GrowBack(int d_num);
	void GrowFront(int d_num);
	int num,t_num,start;
	char*arr;


};


template<class T>
void Pocket::PushBack(T Obj)
{
	if ( num + start + ( int )sizeof( T ) >= t_num ) {
		GrowBack( ::std::max( sizeof( T ), size_t( VECT_GROW_NUM ) ) );
	}

	memcpy( arr + num + start, &Obj, sizeof( T ) );
	num += sizeof( T );
}

template<class T>
void Pocket::PushFront(T Obj)
{
	if(start<sizeof(T))
		GrowFront( std::max( sizeof( T ), size_t( VECT_GROW_NUM ) ) );
	else
		start-=sizeof(T);

	memcpy(arr+start,&Obj,sizeof(T));
	num+=sizeof(T);
}

template<class T>
bool Pocket::PopFront(T& Obj)
{
	if(sizeof(T)>num)return false;
	memcpy(&Obj,arr+start,sizeof(T));
	num-=sizeof(T);
	start+=sizeof(T);
	return true;
}

void PackSel(Pocket&pc, st<int>* sl);
void UnPackSel(Pocket& pc,st<int>*sl);

/*
char* PackSendU(int* num,st<int>*sl,tka pos,tka nav,char add);
char* PackSendB(int* num,st<int>*sl,tka pos);
//char* PackSendG(int* num,st<int>*sl,tka pos,tka nav,char add);
char* PackSetU(int* num,st<int>*sl,char prm,char prm2);
//char* PackSetG(int* num,st<int>*sl,char prm,char prm2);
char* PackPlAction(int* num,Order* ord);

void UnPackSendU(char*bf,st<int>*sl,tka& pos,tka&nav,char& add);
void UnPackSendB(char*bf,st<int>*sl,tka& pos);
void UnPackSetU(char*bf,st<int>*sl,char& prm,char& prm2);
void UnPackPlAction(char*bf,Order*ord);
*/
