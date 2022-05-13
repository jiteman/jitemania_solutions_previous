#include "warfog.h"

#include "vbo.h"
#include "MainGl.h"
#include "Control.h"
#include "Game.h"
#include "open_gl.h"

//#include "temporary_windows_include.h"


fog_krug fog[MAX_FOG_NUM];
size_t fog_num=0;


void ClearFog()
{
	fog_num=0;
}
void DrawKrug(tka c,float rad)
{

	glPushMatrix();
	glTranslated(c.x,c.y,0);
	glScaled(rad,rad,0);
	glDrawElements( GL_TRIANGLE_FAN , FOG_CIRC_NUM+1, GL_UNSIGNED_INT, 0 );
	glPopMatrix();
}

void DrawWarfog2() {
	glColor3f( 1, 1, 1 );
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );

	vbo.StartKrug();

	fog_krug *cur_fog = fog;

	for ( size_t i = 0; i < fog_num; i++, cur_fog++ ) {
		DrawKrug( cur_fog->pos, 10 );
	}

	glEnableClientState ( GL_TEXTURE_COORD_ARRAY );
}

void DrawWarfog()
{
	//glBlendFunc( GL_ONE, GL_ONE );
	//glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
	//glAlphaFunc(GL_LESS ,1);

	float const tmpf2 = 0.6f * WIDTH / SCALE;

	glColor4f(0,0,0,1);
	glDisableClientState ( GL_TEXTURE_COORD_ARRAY );

	vbo.StartKrug();

	{
		float const tmpf = sqrF( FOG_VIS_RAD + tmpf2 );
		fog_krug *cur_fog = fog;

		for ( size_t i = 0; i < fog_num; i++, cur_fog++ ) {
			if ( cur_fog->pos.getLengthSquare( curpos ) < tmpf ) {
				DrawKrug( cur_fog->pos, cur_fog->rad );
			}
		}
	}

	glEnableClientState ( GL_COLOR_ARRAY );
	glBindBufferARB( GL_ARRAY_BUFFER_ARB, vbo.fog_colId );
	glColorPointer(4,GL_FLOAT,sizeof(float)*4, 0);
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, 0 );
	glBindBufferARB( GL_ARRAY_BUFFER_ARB, vbo.get_vertex_id( 4 ) );
	glVertexPointer( 2, GL_FLOAT, sizeof(tka), 0 );
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, 0 );
	glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, vbo.get_index_id( 4 ) );
	glIndexPointer( GL_UNSIGNED_INT, 0, 0 );

	{
		float const tmpf = sqrF( ( FOG_VIS_RAD * FOG_SMOOTH_KOEF ) + tmpf2 );
		fog_krug *cur_fog = fog;

		for ( size_t i = 0; i < fog_num; i++, cur_fog++ ) {
			if ( cur_fog->pos.getLengthSquare( curpos ) < tmpf ) {
				glPushMatrix();
				glTranslated( cur_fog->pos.x, cur_fog->pos.y, 0 );
				glScaled( cur_fog->rad, cur_fog->rad, 0 );
				glDrawElements( GL_TRIANGLE_STRIP , 2 * FOG_CIRC_NUM, GL_UNSIGNED_INT, 0 );
				glPopMatrix();
			}
		}
	}

	glDisableClientState ( GL_COLOR_ARRAY );
	glEnableClientState ( GL_TEXTURE_COORD_ARRAY );


	//glBlendEquation(GL_FUNC_ADD);

	//glAlphaFunc(GL_ALWAYS,1);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void MakeSeen(tka& t)
{
	size_t i = 0;
	fog_krug *ff = fog;

	for ( ; i < fog_num; i++, ff++ ) {
		if ( ff->pos.getLengthSquare( t ) < FOG_DIST * FOG_DIST) {
			break;
		}
	}

	if ( i == MAX_FOG_NUM ) {
		return;
	}

	if ( i == fog_num ) {
		ff->pos = t;
		ff->rad = 1;
		fog_num++;
	}

	ff->grow = true;
}

void GrowWarfog() {
	fog_krug* ff = fog;

	for ( size_t i = 0; i < fog_num; i++, ff++ ) {
		float const tmpf = FOG_GROW_SPEED / ( 1 + 0.005f * ( ff->rad * ff->rad ) );

		if ( ff->grow ) {
			ff->rad += tmpf;
		} else {
			ff->rad -= ( tmpf + 1 ) * 0.04f;
		}

		if ( ff->rad > FOG_VIS_RAD ) {
			ff->rad = FOG_VIS_RAD;
		} else if ( ff->rad < 0 ) {
			fog_num--;
			*ff = *( fog + fog_num );
		}
	}
}

void UpdateWarfog() {
	{
		fog_krug *ff = fog;

		for ( size_t i = 0; i < fog_num; i++, ff++ ) {
			ff->grow=false;
		}
	}

	{
		sld* sldp = Units;

		for ( size_t i = 0; i < MAXSLD; i++, sldp++ ) {
			if ( sldp->life ) {
				if ( ( sldp->pl & 7 ) == MyConf.MY_PLAYER ) {
					MakeSeen( sldp->pos );
				}
			}
		}
	}

	{
		base *bb = Bases;

		for ( size_t i = 0; i < BasesNum; i++, bb++ ) {
			if ( bb->pl == MyConf.MY_PLAYER ) {
				MakeSeen( bb->pos );
			}
		}
	}
}
