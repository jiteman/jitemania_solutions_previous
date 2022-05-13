#include "Missiles.h"

#include "Units.h"
#include "Diplomation.h"
#include "Game.h"
#include "Sound.h"
#include "Polygon.h"

#include "st.h"

#include <algorithm>


miss ms[MAX_MISSILES];//снаряды
int MisNum=0;


void AddMiss(float nx,float ny,float nvx,float nvy,int ndes,char npl)
{
	if(MisNum==MAX_MISSILES)return;
	ms[MisNum].pos.x=nx;
	ms[MisNum].pos.y=ny;
	ms[MisNum].vel.x=nvx;
	ms[MisNum].vel.y=nvy;
	ms[MisNum].des=ndes;
	ms[MisNum].pl=npl;
	MisNum++;
}
void AddMiss(tka npos,tka nv,int ndes,char npl)
{
	if(MisNum==MAX_MISSILES)return;
	ms[MisNum].pos=npos;
	ms[MisNum].vel=nv;
	ms[MisNum].des=ndes;
	ms[MisNum].pl=npl;
	MisNum++;
}
void DelMiss(int i)
{
	MisNum--;
	*(ms+i)=*(ms+MisNum);
}


void FlyMiss()
{
	int i=0,ii,jj;
	el<int>*ss;
	char tmppl;

	sld *sldp;
	tka **tmpt;

	miss*tmp=ms;

	tka ttt;
	while(i<MisNum)
	{

		tmp->pos.x+=tmp->vel.x;
		tmp->pos.y+=tmp->vel.y;
		tmp->des--;
		if(!tmp->des){DelMiss(i);continue;}

		ii=int(tmp->pos.x)/KLET_SIZE;
	    jj=int(tmp->pos.y)/KLET_SIZE;

		tmppl=global_diplomation.d[tmp->pl];

        if(here(ii,jj))
		{
			if((QUNex[ii][jj])&tmppl)
		{

			ss=QUNid[ii][jj].beg;

			while ( ss != nullptr ) {
				sldp=Units+ss->v;
				if(MyPow2(sldp->pl&7)&tmppl && sldp->life)
				{
					if(tmp->pos.getLengthSquare(sldp->pos)<=MANSIZE_PLUS_MISSSIZE_AND_SQ)
	    			{
						if((sldp->type!=1) || ((i+GameTime)&7)==0)
						{

						   sldp->life -= ::std::max(1,MISSATTACK-MissDefend[sldp->type]);

		    			   if(sldp->life<=0)DeleteUnit(ss->v);
						   sldp->vel.x+=(tmp->vel.x)*MISSPUSHKOEF;
						   sldp->vel.y+=(tmp->vel.y)*MISSPUSHKOEF;
						   PlayWavFile(std::string("pmon"),tmp->pos);
						   tmp->des=1;
						}else
						{
							tmp->vel.x=-tmp->vel.x+RND11;
							tmp->vel.y=-tmp->vel.y+RND11;
							PlayWavFile(std::string("defend"),tmp->pos);
							tmp->pl=sldp->pl&7;
						}
			    	}
				}
				ss=ss->next;
			}

		}

		tmpt = Qpoly[ ii ][ jj ];

		if ( tmpt ) {
			ii = _msize( tmpt ) / sizeof( tka * );

			for ( jj = 0; jj < ii; jj++,tmpt++ ) {
				if ( LineCrossLine( tmp->pos, ( tmp->pos + tmp->vel ), **tmpt, *( *tmpt + 1 ) ) ) {
					ttt = **tmpt - *( *tmpt + 1 );
					tmp->vel = ttt * ( 2 * ( ( tmp->vel.x * ttt.x + tmp->vel.y * ttt.y ) / ( ttt.x * ttt. x + ttt.y * ttt.y ) ) ) - tmp->vel;
					tmp->des = MISSDES * ( GameTime & 3 ) + 1;

					PlayWavFile( std::string( "wall" ), tmp->pos );
							//tmp.des=1;
					break;
				}
			}
		}
	}


		i++;
		tmp++;


	}


}
