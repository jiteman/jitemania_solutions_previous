#include "DrawPolygon.h"

#include "Polygon.h"
#include "Textures.h"
#include "Graph2d.h"
#include "vbo.h"

#include "open_gl.h"


float PolyColor[3];


void GenVBOPoly(tka* p,float* arr,int* ind)
{
	int n=LNUM(p),j,k=n,l=0,cnt,ptt=0;
	int vvv[3],nm=0;
	float aaa=RND01*DOUBLE_PI,sinaaa=sin(aaa),cosaaa=cos(aaa);
//	bool fff;
	tka tmpt;
	bool *vv = new bool[ n ];


	for ( j = 0; j < n; j += 1 ) {
		tmpt = *( p + j ) * POLY_TEXT_SCALE;
		tmpt.rotate( sinaaa, cosaaa );		
		arr[ j * 4 ] = ( p + j )->getX();
		arr[ j * 4 + 1 ] = ( p + j )->getY();
		arr[ j * 4 + 2 ] = tmpt.getX();
		arr[ j * 4 + 3 ] = tmpt.getY();
	}

	tka tp,tk;//,old;
//	int kk;
	float d = 3;
    
	for( j = 0; j < n; j += 1 ) {
		vv[ j ] = 0;
	}

	while ( k != 2 ) {			
		cnt = 0;

		do {
			for ( j = 0; j < 3; j += 1 ) {
				vvv[ j ] = ( j == 0 ) ? l : ( vvv[ j - 1 ] + 1 ) % n;
				
				while ( vv[ vvv[ j ] ] ) {
					vvv[ j ] += 1;
					
					if ( vvv[ j ] == n ) {
						vvv[ j ] = 0;
					}
				}
			}
			
			for ( j = 0; j < n; j++ ) {
				if ( j != vvv[ 0 ] && j != vvv[ 1 ] && j != vvv[ 2 ] ) {
					if ( InsideTriangle( *( p + j ), *( p + vvv[ 0 ] ), *( p + vvv[ 1 ] ), *( p + vvv[ 2 ] ) ) ) {
						j = -1;
						break;
					}
				}
			}
					
			if ( j != -1 ) {
				if ( ( *( p + vvv[ 1 ] ) - *( p + vvv[ 0 ] ) ).getVectorProduction( *( p + vvv[ 2 ] ) - *( p + vvv[ 1 ] ) ) < 0 ) {
					break;
				}
			}
				
			l++;
				
			if ( l == n ) {
				l = 0;
			}

			cnt++;
		} while ( cnt != n + 2 );

		vv[vvv[1]]=1;
		l=vvv[2];
		k--;
		if(j!=-1&&cnt!=n+2)
		{
			for(j=0;j<3;j++)
				ind[nm*3+j]=vvv[j];
			nm++;
		}

	}

	delete[] vv;
}

void DrawVboPolys() {
	::glColor3fv( PolyColor );
	::glBindTexture( GL_TEXTURE_2D, TEXTURE_POLY( 0 ).texID );

	int tt = 0;

	for ( int i = 0; i < global_quantityOfObstacles; i += 1 ) {
		if ( IsHere( PolyCent[ i ], PolyRad[ i ] ) ) {
			const int ntt = ( i * POLY_TYPES_NUM ) / ( global_quantityOfObstacles + 1 );

			if ( ntt != tt ) {
				tt = ntt;
				::glBindTexture( GL_TEXTURE_2D, TEXTURE_POLY( tt ).texID );
			}

			const int n = global_obstacleVerticesQuantities[ i ];
			::glBindBufferARB( GL_ARRAY_BUFFER_ARB, vbo._obstacleVertexIdentifiers[ i ] );
			::glVertexPointer( 2, GL_FLOAT, 4 * sizeof( GLfloat ), 0 );
			::glTexCoordPointer( 2, GL_FLOAT, 4 * sizeof( GLfloat ), ( GLvoid * )( 2 * sizeof( GLfloat ) ) );
			::glBindBufferARB( GL_ARRAY_BUFFER_ARB, 0);

			::glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, vbo._obstacleIndexIdentifiers[ i ] );
			::glIndexPointer( GL_UNSIGNED_INT, 0, 0 );
			::glDrawElements( GL_TRIANGLES, 3 * ( n - 2 ), GL_UNSIGNED_INT, 0 );
		}
	}
}

void DrawVboPolyFrames() {
	::glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	::glEnableClientState( GL_COLOR_ARRAY );

	for ( int i = 0; i < global_quantityOfObstacles; i += 1 ) {
		if ( IsHere( PolyCent[ i ], PolyRad[ i ] ) ) {
			const int n = global_obstacleVerticesQuantities[ i ];
			::glBindBufferARB( GL_ARRAY_BUFFER_ARB, vbo._obstacleFrameVertexIdentifiers[ i ] );
			::glVertexPointer( 2, GL_FLOAT, sizeof( float ) * 6, 0 );
			::glColorPointer( 4, GL_FLOAT, sizeof( float ) * 6, ( GLvoid * )( 2 * sizeof( GLfloat ) ) );
			::glBindBufferARB( GL_ARRAY_BUFFER_ARB, 0 );

			::glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, vbo._obstacleFrameIndexIdentifiers[ i ] );
			::glIndexPointer( GL_UNSIGNED_INT, 0, 0 );
			::glDrawElements( GL_TRIANGLE_STRIP, vbo._obstacleFrameIndexNumbers[ i ], GL_UNSIGNED_INT, 0 );
		}
	}

	::glDisableClientState( GL_COLOR_ARRAY );
	::glEnableClientState( GL_TEXTURE_COORD_ARRAY );
}

void DrawVboPolyShadows() {
/*
	glClear(GL_STENCIL_BUFFER_BIT);
	glEnable(GL_STENCIL_TEST);
    glStencilFunc (GL_EQUAL, 0, 1);
    glStencilOp (GL_KEEP, GL_KEEP, GL_INCR);
*/

	::glDisableClientState ( GL_TEXTURE_COORD_ARRAY );
	::glEnableClientState ( GL_COLOR_ARRAY );

	for ( int i = 0; i < global_quantityOfObstacles; i += 1 ) {
		if ( IsHere( PolyCent[ i ], PolyRad[ i ] +SHADOW_DIST_POLY2 ) ) {
			const int n = global_obstacleVerticesQuantities[ i ];
			::glBindBufferARB( GL_ARRAY_BUFFER_ARB, vbo._obstacleShadowVertexIdentifiers[ i ] );
			::glVertexPointer( 2, GL_FLOAT, sizeof( float ) * 6, 0 );
			::glColorPointer( 4, GL_FLOAT, sizeof( float ) * 6, ( GLvoid * )( 2 * sizeof( GLfloat ) ) );
			::glBindBufferARB( GL_ARRAY_BUFFER_ARB, 0 );

			::glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, vbo._obstacleShadowIndexIdentifiers[ i ] );
			::glIndexPointer( GL_UNSIGNED_INT, 0, 0 );
			::glDrawElements( GL_QUADS, vbo._obstacleShadowIndexNumbers[ i ], GL_UNSIGNED_INT, 0 );
		}
	}

	::glDisableClientState ( GL_COLOR_ARRAY );
	::glEnableClientState ( GL_TEXTURE_COORD_ARRAY );
	//glDisable(GL_STENCIL_TEST);
}

void GenVBOPolyShadow(tka* p,float** arr,int** ind) {
	int j,l=0,ptt=0;
	int n=LNUM(p);
	bool fl1,fl2;
	tka tmpt;
	tka tp,tk;//,old;
	float d=3;
	float tmpel[6]={0,0,0,0,0,SHADOW_KOEF};
	
	*arr=0;
	*ind=0;
	
	for(j=0;j<n;j++)
	{
		tp=p[j+1]-p[j];
		if ( tp.getX() > tp.getY() ) {
			tk=p[j]-p[(j-1+n)%n];
			fl1 = ( ( tk.getX() < tk.getY() ) && ( tp.getVectorProduction( tk ) > 0 ) );
			tk=p[(j+2)%n]-p[j+1];
			fl2 = ( ( tk.getX() < tk.getY() ) && ( tp.getVectorProduction( tk ) < 0 ) );
			tp.normalize();
			tp*=SHADOW_DIST_POLY3;

			tmpel[ 0 ] = ( p + j )->getX();
            tmpel[ 1 ] = ( p + j )->getY();
            AddElemVBO( tmpel, 6, arr, ind );

			tmpel[ 0 ] = ( p + j + 1 )->getX();
            tmpel[ 1 ] = ( p + j + 1 )->getY();
            AddElemVBO( tmpel, 6, arr, ind );

			tmpel[ 0 ] = ( p + j + 1 )->getX() + SHADOW_DIST_POLY - tp.getX() * fl2;
            tmpel[ 1 ] = ( p + j + 1 )->getY() + SHADOW_DIST_POLY - tp.getY() * fl2;
            AddElemVBO( tmpel, 6, arr, ind );

			tmpel[ 0 ] = ( p + j )->getX() + SHADOW_DIST_POLY + tp.getX() * fl1;
            tmpel[ 1 ] = ( p + j )->getY() + SHADOW_DIST_POLY + tp.getY() * fl1;
            AddElemVBO( tmpel, 6, arr, ind );
		}
	}
	
	for(j=0;j<n;j++) {
		tp=p[j+1]-p[j];

		if ( tp.getX() > tp.getY() ) {
			tk=p[j]-p[(j-1+n)%n];
			fl1 = ( ( tk.getX() < tk.getY() ) && ( tp.getVectorProduction( tk ) > 0 ) );
			tk=p[(j+2)%n]-p[j+1];
			fl2 = ( ( tk.getX() < tk.getY() ) && ( tp.getVectorProduction( tk ) < 0 ) );
			tp.normalize();
			tp*=SHADOW_DIST_POLY3;
			tmpel[5]=SHADOW_KOEF;

			tmpel[ 0 ] = ( p + j + 1 )->getX() + SHADOW_DIST_POLY - tp.getX() * fl2;
            tmpel[ 1 ] = ( p + j + 1 )->getY() + SHADOW_DIST_POLY - tp.getY() * fl2;
            AddElemVBO( tmpel, 6, arr, ind );

			tmpel[ 0 ] = ( p + j )->getX() + SHADOW_DIST_POLY + tp.getX() * fl1;
            tmpel[ 1 ] = ( p + j )->getY() + SHADOW_DIST_POLY + tp.getY() * fl1;
            AddElemVBO( tmpel, 6, arr, ind );

			tmpel[5]=0;

			tmpel[ 0 ] = ( p + j )->getX() + SHADOW_DIST_POLY2 + tp.getX() * fl1;
            tmpel[ 1 ] = ( p + j )->getY() + SHADOW_DIST_POLY2 + tp.getY() * fl1;
            AddElemVBO( tmpel, 6, arr, ind );

			tmpel[ 0 ] = ( p + j + 1 )->getX() + SHADOW_DIST_POLY2 - tp.getX() * fl2;
            tmpel[ 1 ] = ( p + j + 1 )->getY() + SHADOW_DIST_POLY2 - tp.getY() * fl2;
            AddElemVBO( tmpel, 6, arr, ind );

			if(fl1)
			{
				tmpel[ 0 ] = ( p + j )->getX() + SHADOW_DIST_POLY2 + tp.getX() * fl1;
                tmpel[ 1 ] = ( p + j )->getY() + SHADOW_DIST_POLY2 + tp.getY() * fl1;
                AddElemVBO( tmpel, 6, arr, ind );

				tmpel[ 0 ] = ( p + j )->getX() + ( SHADOW_DIST_POLY - tp.getX() * fl1 * 0.2f ) * 0.2f;
                tmpel[ 1 ] = ( p + j )->getY() + ( SHADOW_DIST_POLY - tp.getY() * fl1 * 0.2f ) * 0.2f;
                AddElemVBO( tmpel, 6, arr, ind );

				tmpel[5]=SHADOW_KOEF;

				tmpel[ 0 ] = ( p + j )->getX();
                tmpel[ 1 ] = ( p + j )->getY();
                AddElemVBO( tmpel, 6, arr, ind );
				
				tmpel[ 0 ] = ( p + j )->getX() + SHADOW_DIST_POLY + tp.getX() * fl1;
                tmpel[ 1 ] = ( p + j )->getY() + SHADOW_DIST_POLY + tp.getY() * fl1;
                AddElemVBO( tmpel, 6, arr, ind );
			}
			if(fl2)
			{
				tmpel[5]=0;

				tmpel[ 0 ] = ( p + j + 1 )->getX() + SHADOW_DIST_POLY2 - tp.getX() * fl2;
                tmpel[ 1 ] = ( p + j + 1 )->getY() + SHADOW_DIST_POLY2 - tp.getY() * fl2;
                AddElemVBO( tmpel, 6, arr, ind );

				tmpel[ 0 ] = ( p + j + 1 )->getX() + ( SHADOW_DIST_POLY + tp.getX() * fl2 * 0.2f ) * 0.2f;
                tmpel[ 1 ] = ( p + j + 1 )->getY() + ( SHADOW_DIST_POLY + tp.getY() * fl2 * 0.2f ) * 0.2f;
                AddElemVBO( tmpel, 6, arr, ind );

				tmpel[5]=SHADOW_KOEF;

				tmpel[ 0 ] = ( p + j + 1 )->getX();
                tmpel[ 1 ] = ( p + j + 1 )->getY();
                AddElemVBO( tmpel, 6, arr, ind );

				tmpel[ 0 ] = ( p + j + 1 )->getX() + SHADOW_DIST_POLY - tp.getX() * fl2;
                tmpel[ 1 ] = ( p + j + 1 )->getY() + SHADOW_DIST_POLY - tp.getY() * fl2;
                AddElemVBO( tmpel, 6, arr, ind );
			}

		}
	}

}

void GenVBOPolyFrame(tka* p,float** arr,int** ind) {
	int n=LNUM(p),j,l=0,ptt=0;
	bool fff;
	tka tmpt;
	
	float tmpel[6]={0,0,0,0,0,0};
	//glPushAttrib(GL_CURRENT_BIT);

	tka tp,tk;//,old;
	int kk;
	float d=3;
	*arr=0;
	
	*ind=0;
	

	for(kk=0;kk<2;kk++)
		for(j=0;j<n;j++)
		{
			//glColor3d(0,0,0);
			//glVertex2f((Poly[i]+j)->getX(),(Poly[i]+j)->getY());
			tmpel[0]=(p+j)->getX();
			tmpel[1]=(p+j)->getY();
			tmpel[5]=1;
			AddElemVBO(tmpel,6,arr,ind);
			

			tp=p[j+1]-p[j];
			tmpt=p[j]-p[(j-1+n)%n];
			fff = ( tp.getVectorProduction(tmpt)<0);
			tk=tp/tp.getLength()-tmpt/tmpt.getLength();
			tk.normalize();		

//			swap(tp.getX(),tp.getY());
            tp.setBoth( tp.getY(), tp.getX() );

            tp.setBoth( tp.getY(), tp.getX() );

            tp.setY( -tp.getY() ); tp.normalize();
			tmpt = tk * ( ( kk ? -0.1f : 1 ) * d / tk.getScalarProduction( tp ) );

			if(!kk&&fff)if(tmpt.getLengthSquare()>d*d)
			{
				tk*=(-d);
				tp=tk;

//				swap(tp.getX(),tp.getY());
                tp.setBoth( tp.getY(), tp.getX() );

				tp.setY( -tp.getY() );
				tmpt=tk+LinesCross(tp,p[j+1]-p[j],tmpt-tk);
			}
			tmpt+=p[j];
//			glColor4d(0,0,0,0);
//			glVertex2f(tmpt.x,tmpt.y);

			tmpel[0]=tmpt.getX();
			tmpel[1]=tmpt.getY();
			tmpel[5]=0;
			AddElemVBO(tmpel,6,arr,ind);
//			(*arr)[vr+5]=1;

//			glColor3d(0,0,0);
//			glVertex2f((Poly[i]+j+1)->getX(),(Poly[i]+j+1)->getY());
			tmpel[0]=(p+1+j)->getX();
			tmpel[1]=(p+1+j)->getY();
			tmpel[5]=1;
			AddElemVBO(tmpel,6,arr,ind);


			
			tp=p[(j+2)%n]-p[j+1];
			tmpt=p[j+1]-p[j];
			fff = ( tp.getVectorProduction(tmpt)<0);
			tk=tp/tp.getLength()-tmpt/tmpt.getLength();
			tk.normalize();		

//			swap(tp.getX(),tp.getY());
            tp.setBoth( tp.getY(), tp.getX() );
            tp.setY( -tp.getY() );
            tp.normalize();
			tmpt=tk*((kk?-0.1f:1)*d/tk.getScalarProduction(tp));
			//if(fff)if(tmpt.getLengthSquare()>d*d){tmpt.normalize();tmpt*=d;}
			if(!kk&&fff)if(tmpt.getLengthSquare()>d*d)
			{
				tk*=(-d);
				tp=tk;
//				swap(tp.getX(),tp.getY());
                tp.setBoth( tp.getY(), tp.getX() );
				tp.setY( -tp.getY() );
				tmpt=tk+LinesCross(tp,p[j+1]-p[j],tmpt-tk);
			}

			tmpt+=p[j+1];
			
			//glColor4d(0,0,0,0);
			//glVertex2f(tmpt.x,tmpt.y);
			tmpel[0]=tmpt.getX();
			tmpel[1]=tmpt.getY();
			tmpel[5]=0;
			AddElemVBO(tmpel,6,arr,ind);
		}	
}