#include "Diplomation.h"

#include "Units.h"
#include "Graph2d.h"
#include "MainGl.h"
#include "Ai.h"


Diplomation global_diplomation;

void Diplomation::UpdateUnits()
{
	int i;
	sld*sldp=Units;
	for(i=0;i<MAXSLD;i++,sldp++)
		if(sldp->enemy!=-1)
			if(!global_diplomation.AreEnemies(sldp->pl&7,(Units+(sldp->enemy&0xFFFF))->pl&7))
				sldp->enemy=-1;

}


void AddSortedIntSt(st<int>* to,st<int>* from)
{
	el<int> *fr=from->beg, *tt,*tt0,*tmp;

	while(fr)
	{
		tt=to->beg;
		if(tt)
		{
			if(tt->v<fr->v)
			{
				tmp=to->beg;
				to->beg=new el<int>;
				to->beg->v=fr->v;
				to->beg->next=tmp;

			}else
			{
				tt0=0;
				while(tt)
				{
					if(tt->v<fr->v)break;
					tt0=tt;
					tt=tt->next;
				}
				tmp=new el<int>;
				tmp->v=fr->v;
				tmp->next=tt;
				tt0->next=tmp;
			}
		}else
		{
			to->beg=new el<int>;
			to->beg->v=fr->v;
			to->beg->next=0;
		}


		fr=fr->next;
	}
}

void Diplomation::Draw(int x0,int y0,int h)
{
	int i,j,x1=x0+10*h;
	
	for(i=0;i<8;i++)
	{
		glColor3fv(PLColor[i]);
		DrawQuadSimple((float)(x0+(i+1)*h),(float)y0,(float)(x0+(i+2)*h),(float)(y0+h));
		DrawQuadSimple((float)x0,(float)(y0+(i+1)*h),(float)(x0+h),(float)(y0+(i+2)*h));
		DrawQuadSimple((float)x1,(float)(y0+(i+1)*h),(float)(x1+((WIDTH-x1)*score[i])/score[enemy]),(float)(y0+(i+2)*h));


		for(j=0;j<8;j++)
		{
			if(d[i]&(1<<j))glColor4d(1,0,0,0.5);else glColor4d(0,1,0,0.5);
			DrawQuadSimple((float)(x0+(i+1)*h),(float)(y0+(j+1)*h),(float)(x0+(i+2)*h),(float)(y0+(j+2)*h));
		}
	}


	sld*sldp=Units;
	char opl=-1;
	
	glBegin(GL_LINES);
	for(i=0;i<MAXSLD;i++,sldp++)
	if(sldp->life)
	{
		if(opl!=(sldp->pl&7))
		{
			opl=(sldp->pl&7);
			glColor3fv(PLColor[opl]);
		}
		glVertex2f((i*WIDTH)/(float)MAXSLD,(float)HEIGHT-100);
		glVertex2f((i*WIDTH)/(float)MAXSLD,(float)HEIGHT-50);
	}
	glEnd();	
}
