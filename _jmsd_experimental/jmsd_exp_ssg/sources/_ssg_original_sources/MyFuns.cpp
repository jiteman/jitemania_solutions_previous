#include "MyFuns.h"


int sqrtMem[(1<<SQRT_MEM_VAL)];
unsigned my_seed=1;

// пересечение линий v*t1 и d+u*t2
tka LinesCross(tka v,tka u,tka d)
{
	return v*((d.y*u.x-d.x*u.y)/(u.x*v.y-u.y*v.x));
}

// void tka::GetCosSinWith(tka& t,tka& cs)
// {
// 	float ll=sqrt(t.getLengthSquare()*getLengthSquare());
// 	if(!ll)return;
// 	cs.x=scalar(t)/ll;
// 	cs.y=vect(t)/ll;
// 
// }

unsigned MyRand()
{
	my_seed*=1234567891;
	my_seed^=my_seed<<8;
	my_seed++;
	return my_seed;
}

float KVAZIL( const tka &a, const tka &b ) {
	return ::abs( a.getX() - b.getX() ) + ::abs( a.getY() - b.getY() );
}