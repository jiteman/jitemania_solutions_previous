#pragma once


//#include "Report.h"
#include "Math.h"
//#include "matrix.h"
#include "AllDefinitions.h"

#define maxim(a1,a2) ((a1)<(a2)?(a2):(a1))
#define minim(a1,a2) ((a1)>(a2)?(a2):(a1))




extern int sqrtMem[(1<<SQRT_MEM_VAL)];
extern unsigned my_seed;

inline int sqrtInt(int a)
{
	int i=(1<<(SQRT_MEM_VAL-1)),d=(1<<(SQRT_MEM_VAL-2));
	do
	{
		i+=(sqrtMem[i]<a)?d:(-d);
		d=d/2;
	}while(d);


	return i+1;
}

inline float Func01(float a)
{
	float res=a;
	if(a>1.0f)res=1.0f;else
	if(a<0.0f)res=0.0f;
	return res;
}



inline double sqr(double a);
inline double sqr4(double a);
template<class T>
void swap(T& a,T& b){T tmp=a; a=b; b=tmp;}


template<class T>
T sgn(T a){if(a>0)return 1;if(a<0)return -1;return 0;}
template<class T>
T absF(T a){if(a>0)return a;return -a;}
template<class T>
T maxF(T a,T b){if(a>b)return a;return b;}
template<class T>
T minF(T a,T b){if(a<b)return a;return b;}
template<class T>
T sqrF(T a){return a*a;}
/*
static inline int dtoi(double d)
{
  const double t = d + 6755399441055744.0;
  return *((int *)(&t));
}


double MyPow(double a,int n)
{
	if(n<0)return 0;
	double tmp=a;
	for(int i=1;i<n;i++)tmp*=a;
	return tmp;
}
*/

//void MyDisplay();

struct CosinusAndSinus {
	float cosinus;
	float sinus;
};

class tka {

public:
	tka() {
		x = 0.0;
		y = 0.0;
	}

	tka( const float nx, const float ny ) {
		x = nx;
		y = ny;
	}

// 	void set( const float nx, const float ny ) {
// 		_x = nx;
// 		_y = ny;
// 	}

// 	void add( const float nx, const float ny ) {
// 		_x += nx;
// 		_y += ny;
// 	}

	tka( const tka &other ) {
		x = other.x;
		y = other.y;
	}

	tka &operator =( const tka &other ) {
		if ( this == &other ) return *this;

		x = other.x;
		y = other.y;
		return *this;
	}

	bool operator ==( const tka &other ) const {
		return x == other.x && y == other.y;
	}

	tka &operator +=( const tka &other ) {
		x += other.x;
		y += other.y;
		return *this;
	}

	tka& operator -=( const tka &other ) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	tka &operator *=( const float a ) {
		x *= a;
		y *= a;
		return *this;
	}

	tka &operator /=( const float a ) {
		x /= a;
		y /= a;
		return *this;
	}

	tka operator +( const tka &other ) const {
		tka temp = *this;
		return temp += other;
	}

	tka operator -( const tka &other ) const {
		tka temp = *this;
		return temp -= other;
	}

	tka operator *( const float a ) const {
		tka temp = *this;
		return temp *= a;
	}

	tka operator /( const float a ) const {
		tka temp = *this;
		return temp /= a;
	}

	void rotate( const float sinda, const float cosda ) {
		const float currentX = x;
		const float currentY = y;
		x = currentY * sinda + currentX * cosda;
		y = -currentX * sinda + currentY * cosda;
	}

	float getScalarProduction( const tka &other ) const {
		return other.x * x + other.y * y;
	}

	float getVectorProduction( const tka &other ) const {
		return other.x * y - other.y * x;
	}

	void normalize() {
		float const ll = ::sqrt( x * x + y * y );

		if ( ll == 0 ) return;
		x /= ll;
		y /= ll;
	}

	float getLengthSquare() const {
		return x * x + y * y;
	}

	float getLengthSquare( const tka &other ) const {
		return ( x - other.x ) * ( x - other.x ) + ( y - other.y ) * ( y - other.y );
	}

	float getLength() const {
		return ::sqrt( x * x + y * y );
	}

	CosinusAndSinus getCosSinWith( const tka &other) {//в cs записывает cos и sin угла между вектором *this и вектором t
		const float ll = ::sqrt( other.getLengthSquare() * getLengthSquare() );
		CosinusAndSinus cosinusAndSinus = {};

		if ( ll != 0 ) {
			cosinusAndSinus.cosinus = getScalarProduction( other ) / ll;
			cosinusAndSinus.sinus = getVectorProduction( other ) / ll;
		}

		return cosinusAndSinus;
	}

	float getX() const {
		return x;
	}

	float getY() const {
		return y;
	}

    void setX( const float p_x ) {
        x = p_x;
    }

    void setY( const float p_y ) {
        y = p_y;
    }

    void setBoth( const float p_x, const float p_y ) {
        x = p_x;
        y = p_y;
    }

//private:
//	float _x;
//	float _y;
    float x;
    float y;

};

tka LinesCross(tka v,tka u,tka d);

// inline float scalar(tka& a, tka&b){return a.x*b.x+a.y*b.y;}
// inline float vect(tka&a, tka&b){return a.x*b.y-a.y*b.x;}
unsigned MyRand();

float KVAZIL( const tka &a, const tka &b );
