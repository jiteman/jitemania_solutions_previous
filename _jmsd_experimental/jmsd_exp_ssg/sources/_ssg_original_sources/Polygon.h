#pragma once


#include "myfuns.h"

#include <malloc.h>


//////POLY/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define POLY_NUM 1000
#define LNUM(p) (_msize(p))/sizeof(*p)-1
#define TLNUM(p) (_msize(p))/sizeof(*p)
#define MAX_NORMALS_TO_CHECK 6
#define POLY_Q_SIZE 15

#define FLD_NUM 10// число пол€н (место без преп€тствий)
#define FLD_SIZE (KLET_SIZE*FIELDSIZEX/50)//радиус пол€н

extern tka **Poly;
extern int* global_obstacleVerticesQuantities;
extern float* PolyRad;
extern tka**TPoly;
extern tka*PolyCent;
extern size_t global_quantityOfObstacles;
extern tka****Qpoly;
extern int***Qip;


tka RandTka();
tka RandFreeTka();


float DistSQRLineToCirc(tka a,tka l,tka v);
float DistSQRLineToLine(tka a1,tka a2,tka b1,tka b2);
float DistSQRPolyToPoly(tka*p1,tka*p2);

void LinePr(float cx,float cy,float *vx,float *vy);
void LinePr2(float cx,float cy,float *vx,float *vy);


bool LineCrossLine(tka*a1,tka*a2,tka*b1,tka*b2);
bool LineCrossSomething(tka a,tka b,int*ppoly=0, tka*pnt=0);
int LineCrossPoly(tka* a,tka* b,tka*p,bool onetime=0);
bool LineLine2(tka&a1,tka&a2,tka&b1,tka&b2,tka*v0);
int LineCrossPoly2(tka* a,tka* b,tka*p,tka*v0);
bool PolyCrossPoly(tka*p1,tka*p2);
bool LineCrossCirc(float cx,float cy,float x,float y,float *vx,float *vy);


bool InsideTriangle(tka v,tka a,tka b,tka c);
bool TkaInsidePoly(tka a,tka*p);

void PreparePolys();
void CreateRandPolys();
void InitPoly();
void UnInitPoly();
void DelPolys();

template< class A_type >
void transfering_to_vector_AddElem( A_type el, A_type **vector ) {
	int n;
	int mm;

	if ( *vector ) {
		mm = _msize( *vector );
		n = mm / sizeof( A_type );
	} else {
		n = 0;
	}

	A_type *tmpv = new A_type[ n + 1 ];

	tmpv[ n ] = el;

	if ( n ) {
		memcpy( tmpv, *vector, mm );
		delete[] *vector;
	}

	*vector = tmpv;
}

template< class A_type >
bool transfering_to_vector_ExistsElem( A_type el, const A_type *const vector ) {
	size_t n = 0;
	
	if ( vector ) {
		n = transfering_to_vector_VectorSize( vector )
	} else {
		return false;
	}

	for ( size_t i = 0 ; i < n; i += 1 ) {
		if ( vector[ i ] == el ) return true;
	}

	return false;
}

template< class A_type >
size_t transfering_to_vector_VectorSize( const A_type *const vector ) {
	return _msize( vector ) / sizeof( A_type );
}


template< class T >
void AddElem( T el, T **vector ) {
	int n;
	int mm;

	if ( *vector ) {
		mm = _msize( *vector );
		n = mm / sizeof( T );
	} else {
		n = 0;
	}

	T*tmpv=new T[n+1];
	//for(i=0;i<n;i++)tmpv[i]=*(*vector+i);
	tmpv[n]=el;
	if(n)
	{
		memcpy(tmpv,*vector,mm);
		delete[]*vector;
	}
	*vector=tmpv;
}

template<class T>
bool ExistsElem(T el,T*vector)
{
	int n,i;
	
	if(vector)n=_msize(vector)/sizeof(T);else return 0;
	for(i=0;i<n;i++)if(vector[i]==el)return 1;
	return 0;
	
	
}

template<class T>
size_t VectorSize(T*vector)
{
	return _msize(vector)/sizeof(T);
}
