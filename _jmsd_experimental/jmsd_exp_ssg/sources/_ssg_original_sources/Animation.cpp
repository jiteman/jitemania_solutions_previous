#include "Animation.h"


#include "Textures.h"
#include "Graph2d.h"
#include "Units.h"
#include "Control.h"

#include "open_gl.h"


Anim* anim[ANIMATION_NUM];
int AnimNum=0;


void AddAnimation(Anim* an)
{
	if(AnimNum==ANIMATION_NUM) return;
	anim[AnimNum] = an;
	AnimNum++;

}
void DeleteAnimation(int id)
{
	if(AnimNum)
	if(anim[id])
	{
		AnimNum--;
		delete anim[id];
		anim[id]=anim[AnimNum];
		anim[AnimNum]=0;
	}

}

void DrawAnimations() {
	::glBindTexture( GL_TEXTURE_2D, TEXTURE_ANIM.texID );
	
	for ( int i = 0; i < AnimNum; i += 1 ) 	{
		Anim *cur_anim = anim[ i ];

		if ( IsHere( cur_anim->pos, MAX_ANIM_SIZE ) ) {
			::glPushMatrix();
			::glTranslatef( cur_anim->pos.getX(), cur_anim->pos.getY(), 0.0f );

			if ( cur_anim->ang ) {
				::glRotated( cur_anim->ang, 0, 0, 1 );
			}

			cur_anim->Draw();
			::glPopMatrix();		
		}
	}
}

void ActAnimations()
{
	int i=0;
	while(i<AnimNum)
	{
		anim[i]->des--;
		if(!anim[i]->des) DeleteAnimation(i); else i++;
	}
}
FlashAnim::FlashAnim(tka& npos,int a)
{
	des=30;
	pos=npos;
	ang=a;

}
void FlashAnim::Draw()
{
	float des1=(100-3*des)*0.03f+0.3f;
	float tmpf=des/(30.0f);
	if(des1>1)
	{
		glColor4f(tmpf,tmpf,tmpf,tmpf);
		DrawQuad2(0.0f,-des1,des1*5.0f,des1,0,0,32,16,TEXTURE_ANIM);
	}
}
PMonAnim::PMonAnim(sld& ss)
{
	des=79;
	pos=ss.pos;
	for(int i=0;i<3;i++)
		color[i]=PLColor[ss.pl&7][i];

	ang=(char)MyRand();

}
void PMonAnim::Draw()
{
	int id=7-des/10,tmpi = 2;
	
	if(SCALE>1)
	{
		color[3]=(des%10)/10.0f;
		glColor4fv(color);
		DrawQuad2(-tmpi,-tmpi,tmpi,tmpi,id*32,16,(id+1)*32,16+32,TEXTURE_ANIM);
		if(id<7)
		{
			color[3]=1.0f-color[3];
			glColor4fv(color);
			DrawQuad2(-tmpi,-tmpi,tmpi,tmpi,(id+1)*32,16,(id+2)*32,16+32,TEXTURE_ANIM);
		}
	}
}