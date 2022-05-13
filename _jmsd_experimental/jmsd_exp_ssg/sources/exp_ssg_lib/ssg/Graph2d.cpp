#include "Graph2d.h"

#include "GUI.h"
#include "Control.h"
#include "myfuns.h"
#include "Bases.h"
#include "Diplomation.h"
#include "Game.h"
#include "Wid.h"
#include "Group.h"
#include "vbo.h"
#include "MainGl.h"
#include "Zamer.h"
#include "Missiles.h"
#include "DrawPolygon.h"
#include "Animation.h"
#include "warfog.h"


int ababua=0,fps=0;

tka mPos;
char MouseOnBase=0;//мышь над базой

float PLColor[8][3];
float SelCol[4]={0.7f,1,0.9f,0.5f};
float RedLifeCol[4]={0.7f,0,0,0.4f};
float GroupSelCol[4]={0.9f,0.9f,0.4f,0.4f};
bool MouseOnButton( float x, float y, float w, float h)
{
	return (mPos.x>x && mPos.y>y && mPos.x<x+w && mPos.y<y+h);
}

void DrawButton( float x, float y, float w, float h,std::string text,int style)
{
	bool mon=(mPos.x>x && mPos.y>y && mPos.x<x+w && mPos.y<y+h);
	switch(style)
	{
	case 0:
		glColor3f(0.3f,0.3f,0.1f);
//		::glBindTexture( GL_TEXTURE_2D, TEXTURE_WID.texID );
		::sf::Texture::bind( &( TEXTURE_WID ) );
		DrawQuad(x,y,x+w,y+h,(1.0f/64));
		DrawFrame(x,y,w,h,0);
		glColor3f(1,1,1);
		DrawMyText_float_box( x, y + h / 4, w, h / 2, text, ArialFont );
		break;

	case 1:
		if ( mon ) {
			::glColor3f( 0.5f, 0.5f, 0.3f );
		} else {
			::glColor3f( 0.3f, 0.3f, 0.2f );
		}

//		::glBindTexture( GL_TEXTURE_2D, TEXTURE_POLY( 7 ).texID );
		::sf::Texture::bind( &( TEXTURE_POLY( 7 ) ) );

		DrawQuad(x,y,x+w,y+h,(1.0f/64));

		if ( mon )glColor3f(0.0f,0.0f,0.0f);else glColor3f(0.1f,0.1f,0);
		DrawFrame(x,y,w,h,0);

		if ( !text.empty() ) {
			if ( mon ) {
				::glColor3f( 1.0f, 1.0f, 1.0f );
			} else {
				::glColor3f( 0.5f, 0.6f, 0.7f );
			}

			DrawMyText_float_box( x, y + h / 8, w, ( 6 * h ) / 8, text, ArialFont );
		}

		break;
	}
}

void glMYLine( float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
}
void glMYRectangle ( float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,y1);
	glVertex2f(x1,y2);
	glVertex2f(x2,y2);
	glVertex2f(x2,y1);
	glEnd();
}

void DrawQuad ( int x, int y, int x1, int y1)
{
	DrawQuad ((float)x,(float)y,(float)x1,(float)y1);
}
void DrawQuad ( int x, int y, int x1, int y1,float txt_size)
{
	DrawQuad ((float)x,(float)y,(float)x1,(float)y1,txt_size);
}
void DrawQuad2 ( int x, int y, int x1, int y1,float tx1, float ty1,float tx2, float ty2)
{
	DrawQuad2 ((float)x,(float)y,(float)x1,(float)y1,tx1,ty1,tx2,ty2);
}

//void DrawQuad2( int x, int y, int x1, int y1,int txi1, int tyi1,int txi2, int tyi2, TextureImage &txt ) {
//	DrawQuad2( ( float )x, ( float )y, ( float )x1, ( float )y1, txi1, tyi1, txi2, tyi2, txt );
//}
void DrawQuad2( int x, int y, int x1, int y1,int txi1, int tyi1,int txi2, int tyi2, ::sf::Texture const &txt ) {
	DrawQuad2( ( float )x, ( float )y, ( float )x1, ( float )y1, txi1, tyi1, txi2, tyi2, txt );
}


void DrawQuad ( float x, float y, float x1, float y1)
{

  glBegin ( GL_TRIANGLE_STRIP );
    glTexCoord2i ( 0, 0 );    glVertex2f ( x,  y );
    glTexCoord2i ( 1, 0 );    glVertex2f ( x1, y );
    glTexCoord2i ( 0, 1 );    glVertex2f ( x,  y1 );
    glTexCoord2i ( 1, 1 );    glVertex2f ( x1, y1 );
  glEnd();

}

void DrawQuadSimple( const float x, const float y, const float x1, const float y1 ) {
  ::glBegin( GL_TRIANGLE_STRIP );
  ::glVertex2f( x,  y );
  ::glVertex2f( x1, y );
  ::glVertex2f( x,  y1 );
  ::glVertex2f( x1, y1 );
  ::glEnd();
}

void DrawQuad ( float x, float y, float x1, float y1,float txt_size)
{
  glBegin ( GL_TRIANGLE_STRIP );
    glTexCoord2f ( x*txt_size, y*txt_size );    glVertex2f ( x,  y );
    glTexCoord2f ( x1*txt_size, y*txt_size );    glVertex2f ( x1, y );
    glTexCoord2f ( x*txt_size, y1*txt_size );    glVertex2f ( x,  y1 );
    glTexCoord2f ( x1*txt_size, y1*txt_size );    glVertex2f ( x1, y1 );
  glEnd();
}


void DrawQuad2 ( float x, float y, float x1, float y1, float tx1, float ty1, float tx2, float ty2 )
{
	::glBegin( GL_TRIANGLE_STRIP );
    ::glTexCoord2f( tx1, ty1 ); glVertex2f( x, y );
    ::glTexCoord2f( tx2, ty1 ); glVertex2f( x1, y );
    ::glTexCoord2f( tx1, ty2 ); glVertex2f( x,  y1 );
    ::glTexCoord2f( tx2, ty2 ); glVertex2f( x1, y1 );
	::glEnd();
}

//void DrawQuad2( float x, float y, float x1, float y1,int txi1, int tyi1,int txi2, int tyi2, TextureImage &txt ) {
//	float const tx1 = txi1 / ( float )txt.width;
//	float const tx2 = txi2 / ( float )txt.width;
//	float const ty1 = tyi1 / ( float )txt.height;
//	float const ty2 = tyi2 / ( float )txt.height;
//    ::glBegin ( GL_TRIANGLE_STRIP );
//    ::glTexCoord2f ( tx1, ty1 );    glVertex2f ( x,     y );
//    ::glTexCoord2f ( tx2, ty1 );    glVertex2f ( x1, y );
//    ::glTexCoord2f ( tx1, ty2 );    glVertex2f ( x,     y1 );
//    ::glTexCoord2f ( tx2, ty2 );    glVertex2f ( x1, y1 );
//    ::glEnd();
//}

void DrawQuad2( float x, float y, float x1, float y1,int txi1, int tyi1,int txi2, int tyi2, ::sf::Texture const &txt ) {
//	float const tx1 = txi1 / ( float )txt.width;
//	float const tx2 = txi2 / ( float )txt.width;
//	float const ty1 = tyi1 / ( float )txt.height;
//	float const ty2 = tyi2 / ( float )txt.height;

	float const tx1 = txi1 / ( float )txt.getSize().x;
	float const tx2 = txi2 / ( float )txt.getSize().x;
	float const ty1 = tyi1 / ( float )txt.getSize().y;
	float const ty2 = tyi2 / ( float )txt.getSize().y;

    ::glBegin ( GL_TRIANGLE_STRIP );
    ::glTexCoord2f ( tx1, ty1 );    glVertex2f ( x,     y );
    ::glTexCoord2f ( tx2, ty1 );    glVertex2f ( x1, y );
    ::glTexCoord2f ( tx1, ty2 );    glVertex2f ( x,     y1 );
    ::glTexCoord2f ( tx2, ty2 );    glVertex2f ( x1, y1 );
    ::glEnd();
}

void GoToTkaOnMap(tka ps) {
	curpos=ps;
}


void DrawArrow(float x1,float y1,float x2,float y2)
{
	float tx=(y2-y1),ty=(x1-x2),bx=(x2*3+x1)/4,by=(y2*3+y1)/4;
/*
	if(LineCrossSomething(tka(x1+curx,y1+cury)/SCALE,tka(x2+curx,y2+cury)/SCALE))glColor3d(1,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glEnd();
*/	glBegin(GL_LINE_LOOP);
   glVertex2f(x1-tx/15,y1-ty/15);
   glVertex2f(x1+tx/15,y1+ty/15);
   glVertex2f(bx+tx/15,by+ty/15);
   glVertex2f(bx+tx/5,by+ty/5);
   glVertex2f(x2,y2);
   glVertex2f(bx-tx/5,by-ty/5);
   glVertex2f(bx-tx/15,by-ty/15);


   glEnd();
}

void DrawCursor() {
	tka ttt = ::MOUSETKA();
	::glColor3f( 1, 1, 1 );
	MouseOnBase = -1;

    for ( size_t i = 0; i < BasesNum; i++ ) {
		if ( global_diplomation.AreEnemies( ( Bases + i)->pl, MyConf.MY_PLAYER ) || ( Bases + i )->pl == -1 ) {
			if ( KVAZIL( ( Bases + i )->pos, ttt ) < MAX_DEFENDER_DIST ) {
				MouseOnBase = i;
				break;
			}
		}
	}

	if ( MouseOnBase == -1 || cur_wdj != -1 ) {
//	   ::glBindTexture( GL_TEXTURE_2D, TEXTURE_CURSOR.texID );
	   ::sf::Texture::bind( &( TEXTURE_CURSOR ) );
	} else {
//	    ::glBindTexture( GL_TEXTURE_2D, TEXTURE_ATTACK_CURSOR.texID );
	    ::sf::Texture::bind( &( TEXTURE_ATTACK_CURSOR ) );
	}

	::DrawQuad( mPos.x, mPos.y, mPos.x + 30, mPos.y + 60 );
}

void DrawUnitSelection(int *id)
{
	sld* sldp=Units+*id;
	el<tka>*ttt;
	float x,y;

//	if(sldp->life)
	{

		x=sldp->pos.x;
		y=sldp->pos.y;

		if(sldp->enemy!=-1)	glColor4fv(RedLifeCol);
		else
		{
			if(sldp->group_id==-1)
				glColor4fv(SelCol);
			else
				glColor4fv(GroupSelCol);
		}
        glMYRectangle(x-1,y-1,x+1,y+1);

		if(MyConf.show_tracks)
		{
			glBegin(GL_LINE_STRIP);
			ttt=sldp->way.top;
			glVertex2fv(&sldp->pos.x);
			if(sldp->enemy!=-1)
			{
				glVertex2fv(&(Units+sldp->enemy)->pos.x);
			}else
			while(ttt)
			{
				glVertex2fv(&ttt->v.x);
				ttt=ttt->next;
			}
			glEnd();
		}
		if(sldp->way.top)
		{
			x=sldp->way.beg->v.x;
			y=sldp->way.beg->v.y;
			glMYRectangle(x-1,y-1,x+1,y+1);
		}

	}
}
void DrawOrder(Order **ord)
{
	char ttt=(*ord)->type;
	el<int>*tmp=(*ord)->sl.beg;
	if(ttt==0 || ttt==2)
		DrawArrow((*ord)->pos.x,(*ord)->pos.y,(*ord)->nav.x,(*ord)->nav.y);
	switch(ttt)
	{
	case 0:
		glBegin(GL_LINES);
		while(tmp)
		{
			glVertex2fv(&(Units+tmp->v)->pos.x);
			glVertex2fv(&(*ord)->pos.x);
			tmp=tmp->next;
		}
		glEnd();
		break;
	case 1:
		glBegin(GL_LINES);
		while(tmp)
		{
			glVertex2fv(&(Bases+tmp->v)->pos.x);
			glVertex2fv(&(*ord)->pos.x);
			tmp=tmp->next;
		}
		glEnd();
		break;
	case 2:
		glBegin(GL_LINES);
		while(tmp)
		{
			glVertex2fv(&(global_groups+tmp->v)->pos.x);
			glVertex2fv(&(*ord)->pos.x);
			tmp=tmp->next;
		}
		glEnd();
		break;
	}
}

void DrawUnitLifebar(int *id)
{
	sld* sldp=Units+*id;
	float v[2];

//	if(sldp->life)
	{

		glColor4fv(SelCol);
		v[0]=sldp->pos.x-1;
		v[1]=sldp->pos.y+1;
		glVertex2fv(v);
		v[0]+=(sldp->life*0.02f);

		glVertex2fv(v);
		glColor4fv(RedLifeCol);
		glVertex2fv(v);

		v[0]=sldp->pos.x+1;
		glVertex2fv(v);



	}
}
void DrawSelection()
{
	el<int> *tmp=selB.beg;

//	float x0;
//	sld*sldp;
	base*bbb;
	float x,y;
	float OrderCol[4]={1,1,0.5f,0.4f};

	while(tmp)
	{
		bbb=Bases+tmp->v;
		if(IsHere(bbb->pos,BASE_SIZE))
		{
			x=bbb->pos.x;
			y=bbb->pos.y;
			glColor4fv(SelCol);
			glMYRectangle(x-BASE_SIZE,y-BASE_SIZE,x+BASE_SIZE,y+BASE_SIZE);
			if(bbb->send.x)glMYLine(x,y,bbb->send.x,bbb->send.y);
/*
			x-=BASE_SIZE;
			y+=BASE_SIZE+4;
			x0=x+(GetBaseElapsed(bbb->level)*(2*BASE_SIZE));
			glColor4fv(BaseLifeCol);
			glMYLine(x,y,x0,y);
			x+=2*BASE_SIZE;
			glColor4fv(RedLifeCol);
			*/
		}

		tmp=tmp->next;
	}
	tmp=sel.beg;
	if(MyConf.lifebar_on && SCALE>5)
	{
		glLineWidth(3);
		glBegin(GL_LINES);
		DoForEach(sel.beg,DrawUnitLifebar);
		tmp=GrpSel.beg;
		while(tmp)
		{
			DoForEach((global_groups+tmp->v)->un.beg,DrawUnitLifebar);
			tmp=tmp->next;
		}
		glEnd();
		glLineWidth(1);

	}
	DoForEach(sel.beg,DrawUnitSelection);
	tmp=GrpSel.beg;
	while(tmp)
	{
		DoForEach((global_groups+tmp->v)->un.beg,DrawUnitSelection);
		tmp=tmp->next;
	}
	if(MyConf.show_tracks)
	{
		glColor4fv(OrderCol);
		DoForEach(global_OrdMan.ord_out[global_OrdMan.cur_ord].top,DrawOrder);
	}

}
void DrawBases()
{
//	int i;
	float x,y;
	char plpl,o_pl=-2;
	unsigned int o_type = ~0U;

	base *bp=Bases;
//	glBindTexture( GL_TEXTURE_2D, TEXTURE_BASES.texID );
	::sf::Texture::bind( &( TEXTURE_BASES ) );

	vbo.StartBase();
    for ( size_t i = 0; i < BasesNum; i++,bp++ )
	if(IsHere(bp->pos,BASE_SIZE))
	{
		x=bp->pos.x;
		y=bp->pos.y;
		glPushMatrix();
		glTranslated(x,y,0);
		plpl=bp->pl;
		if(o_pl!=plpl)
		{
			if(plpl!=-1)
				glColor3fv(PLColor[plpl]);
			else
				glColor3fv(BackColor);
			o_pl=plpl;

		}


		if ( o_type != bp->level )
		{
			o_type=bp->level;
			vbo.SwitchToBase(bp->level);
		}
		glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0 );
		glPopMatrix();
	}

}

void DrawBasesRects() {
//	char plpl,o_pl=-2;
//	float blCol[3]={0.8f,0.8f,0.8f};

	float const blCol[ 3 ] = { 0.8f, 0.8f, 0.8f };

	char o_pl = -1;

	for ( size_t i = 0; i < BasesNum; i++ ) {
		if ( IsHere( ( Bases + i )->pos, BASE_SIZE ) ) {
			float const x = ( Bases + i )->pos.x;
			float const y = ( Bases + i )->pos.y;
			char const plpl = ( Bases + i )->pl;

			if ( o_pl != plpl ) {
				::glColor3fv( plpl != -1 ? PLColor[ plpl ] : blCol );
				o_pl = plpl;
			}

			::glBegin( GL_LINE_LOOP );
			::glVertex2f( x - MAX_DEFENDER_DIST, y );
			::glVertex2f( x, y - MAX_DEFENDER_DIST );
			::glVertex2f( x + MAX_DEFENDER_DIST, y );
			::glVertex2f( x, y + MAX_DEFENDER_DIST );
			::glEnd();
		}
	}
}

void DrawUnitDots()
{
	int i;
	char plpl,o_pl=-1;
	sld*sldp=Units;
	//float x,y;
	BB(19);

	glBegin(GL_POINTS);

	for(i=0;i<MAXSLD;i++,sldp++)// рисуем солдатегов
	{
		if(sldp->life)
		if(IsHere(sldp->pos,1))
		{

			plpl=sldp->pl&7;
			if(o_pl!=plpl)
			{
				o_pl=plpl;
				glColor3fv(PLColor[plpl]);
			}

			glVertex2fv(&sldp->pos.x);

		}
	}
	glEnd();
	BB1(19);
}
void DrawSlds()
{
//	el<int> *sss1,*sss2;


	int i,j=DEAD_SLD_NUM;
	char type,plpl,lf,o_type=-1,o_lf=-1,o_pl=-1;
	sld*sldp=Units;
	sld_dead*sldd=DeadUnits+Current_dead-1;
	miss *mmm=ms;
	float tmpf2, x,y, ShadowCol[]={0,0,0,SHADOW_KOEF},col[4];
	vbo.StartUnit();


	BB(18);

//	glBindTexture ( GL_TEXTURE_2D, TEXTURE_UNITS.texID );
	::sf::Texture::bind( &( TEXTURE_UNITS ) );

	i=Current_dead-1;
	tmpf2=0.6f*Func01(0.3f*(SCALE-2));
	if(tmpf2)
	do  //рисуем трупеги
	{

		if(i==-1){ i=DEAD_SLD_NUM-1; sldd=DeadUnits+DEAD_SLD_NUM-1; }


	    if(IsHere(sldd->pos,1))
	    {

			type=sldd->type>>3;
			if(o_type!=type)
			{
				vbo.SwitchToUnit(type,0);
				o_type=type;
			}
			plpl=sldd->type&7;
			if(o_pl!=plpl)
			{
				o_pl=plpl;
				col[0]=PLColor[plpl][0];
				col[1]=PLColor[plpl][1];
				col[2]=PLColor[plpl][2];
				col[3]=tmpf2*(j/(float)DEAD_SLD_NUM);
				glColor4fv(col);
			}

			glPushMatrix();
			glTranslatef(sldd->pos.x,sldd->pos.y,0.0f);
			glRotated(sldd->ang*2,0,0,1);
			glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0 );


			glPopMatrix();

        }

		j--;

		i--;
		sldd--;
	}while(i!=Current_dead-1);

	o_pl=-1;
	BB1(18);
	BB(19);



	for(i=0;i<MAXSLD;i++,sldp++)// рисуем солдатегов
	{
		if(sldp->life)
		if(IsHere(sldp->pos,1))
		{

			type=sldp->type;
			lf=(sldp->life-1)/25;
			plpl=sldp->pl&7;
			if(o_type!=type || o_lf!=lf)
			{
				vbo.SwitchToUnit(type,lf);
				o_type=type;
				o_lf=lf;
			}

			if(SCALE>4 && MyConf.shadows_on)
			{
				glPushMatrix();
				glTranslatef(sldp->pos.x+SHADOW_DIST,sldp->pos.y+SHADOW_DIST,0.0f);
				glColor4fv(ShadowCol);
				glRotated(sldp->a*0.5,0,0,1);
				glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0 );
				glPopMatrix();
				glColor3fv(PLColor[plpl]);
			}else
			if(o_pl!=plpl)
			{
				o_pl=plpl;
				glColor3fv(PLColor[plpl]);
			}
			glPushMatrix();
			glTranslatef(sldp->pos.x,sldp->pos.y,0.0f);

			glRotated(sldp->a*0.5,0,0,1);


			glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0 );
			glPopMatrix();

		}
	}
	BB1(19);
	BB(20);

//	glBindTexture ( GL_TEXTURE_2D, TEXTURE_MISSILE.texID );
	::sf::Texture::bind( &( TEXTURE_MISSILE ) );

	vbo.StartMissile();
    for(i=0;i<MisNum;i++,mmm++)
	{
		if(IsHere(mmm->pos,MISSSIZE_TODRAW))
		{
	        x=mmm->pos.x;
			y=mmm->pos.y;
			glPushMatrix();
			glTranslatef(x,y,0.0f);

			plpl=mmm->pl;

			if(MyConf.shadows_on)
			{
				glColor4fv(ShadowCol);
				glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0 );
				glTranslatef(-SHADOW_DIST,-SHADOW_DIST,0.0f);
			}
			glColor3fv(PLColor[plpl]);
			glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0 );
			glPopMatrix();
		}
	}
	BB1(20);


}

void DrawBackground()
{
BB(8);

	float tmpf=Func01(0.3f*(SCALE-2));
//	glDisable(GL_TEXTURE_2D);
	glColor3fv(BackColor);
	DrawQuadSimple(0,0,float(MapW*KLET_SIZE),float(MapH*KLET_SIZE));
	if(Warfog_is)
		glColor4f(BackColor[0]*tmpf,BackColor[1]*tmpf,BackColor[2]*tmpf,tmpf);
	else
		glColor4f(BackColor[0],BackColor[1],BackColor[2],tmpf);
	glEnable(GL_TEXTURE_2D);
//	glBindTexture ( GL_TEXTURE_2D, TEXTURE_BG2.texID );
	::sf::Texture::bind( &( TEXTURE_BG2 ) );

	DrawQuad(0,0,MapW*KLET_SIZE,MapH*KLET_SIZE,0.05f);
BB1(8);
}
void SetVSync(bool sync)
{
	typedef bool (APIENTRY *PFNWGLSWAPINTERVALFARPROC)(int);

	PFNWGLSWAPINTERVALFARPROC wglSwapIntervalEXT = 0;

	wglSwapIntervalEXT = (PFNWGLSWAPINTERVALFARPROC)wglGetProcAddress("wglSwapIntervalEXT");

	if( wglSwapIntervalEXT )
		wglSwapIntervalEXT(sync);
}

void DrawMapObjects()
{


BB(10);
	DrawBases();
BB1(10);
BB(11);
	//if(SCALE<1)glDisable(GL_TEXTURE_2D);
if(SCALE>1)
	DrawSlds();
	//if(SCALE<1)glEnable(GL_TEXTURE_2D);
BB1(11);
BB(12);
	::DrawAnimations();
BB1(12);

BB(13);


//	if(MyConf.shadows_on)
//		glCallList(PolyShadowList);

//	glCallList(PolyList);
//glEnable(GL_TEXTURE_2D);


	if(MyConf.shadows_on)
	{
		glDisable(GL_TEXTURE_2D);
		DrawVboPolyShadows();
		glEnable(GL_TEXTURE_2D);
	}

	DrawVboPolys();
	glDisable(GL_TEXTURE_2D);

	if(SCALE<=1)
		DrawUnitDots();

	DrawVboPolyFrames();
	//glEnable(GL_TEXTURE_2D);

BB1(13);

}

void DrawMyLines() {
	BB( 14 );

	if ( SelIs ) {
		::glColor4fv( SelCol );
		::glMYRectangle( omL.x, omL.y, MOUSEX(), MOUSEY() );
	}

	if ( SelIsR ) {
		if ( !SelIs ) {
			::glColor4fv( SelCol );
		}

		::DrawArrow( omR.x, omR.y, MOUSEX(), MOUSEY() );
	}

	::DrawSelection();

	if ( SCALE < 2 ) {
		::DrawBasesRects();
	}

	BB1( 14 );
}

void MyDisplay()
{
	::glClear( GL_COLOR_BUFFER_BIT );
	BB( 9 );
	glPushMatrix();
	glTranslated(WIDTH/2,HEIGHT/2,0);
	glScaled(SCALE,SCALE,SCALE);
	glTranslated(-curpos.x,-curpos.y,0);

	glDisable(GL_TEXTURE_2D);

	if(Warfog_is)
	{
BB(21);

		glBlendFunc(GL_ONE, GL_ONE);
		::DrawWarfog();

		//glEnable(GL_TEXTURE_2D);
BB1(21);
	}else DrawBackground();


	glBlendFunc(GL_DST_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if(Warfog_is)DrawBackground();
	DrawMapObjects();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
BB(36);
	DrawMyLines();
	glPopMatrix();

BB1(36);
BB1(9);

BB(15);

	if(status&128){global_diplomation.Draw(100,100,50);}

	glEnable(GL_TEXTURE_2D);
    if(cur_wdj==-1)
	{
		DrawMenu();
		if(status&8)DrawInformation();
	}
	DrawMes();
	DrawWid();
	DrawCursor();
BB1(15);

glFlush();
}


bool IsHere( const tka &t, const float p_size ) {
	tka point = t;
	point -= curpos;
	point *= SCALE;
	const float size = p_size * SCALE;
	return t.x + size >= -WIDTH / 2 && t.y + size >= -HEIGHT / 2 && t.x - size <= WIDTH / 2 && t.y - size <= HEIGHT / 2;
}

