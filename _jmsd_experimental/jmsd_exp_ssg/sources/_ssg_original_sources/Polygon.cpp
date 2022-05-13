#include "Polygon.h"

#include "Game.h"
#include "Units.h"
#include "vbo.h"


tka*fld;
tka**Poly;
float* PolyRad;
int* global_obstacleVerticesQuantities;
tka**TPoly;
tka*PolyCent;

size_t global_quantityOfObstacles = 0;

tka****Qpoly;
int***Qip;


tka RandTka()
{
	return tka(RND01*(MapW*KLET_SIZE),RND01*(MapH*KLET_SIZE));
}
tka RandFreeTka()
{
	tka res;
	int ii,jj;

	do{
		res=RandTka();
		ii=((int)res.x)/KLET_SIZE;
		jj=((int)res.y)/KLET_SIZE;

	    if(here(ii,jj))
			if(!Qpoly[ii][jj])break;
	}while(1);
	return res;
}

void CreateField()
{
	int i;
	fld=new tka[FLD_NUM];
	for(i=0;i<FLD_NUM;i++)
		fld[i] = RandTka();
}
/*
tka RandFreeTka1()
{
	tka res,d((MYRND-0.5f)*(2*KLET_SIZE),0);
	d.y=(KLET_SIZE-d.x);
	if(MyRand()&1)d.y=-d.y;
	int ii,jj;

	res=RandTka();
	do{
		if(MyRand()%20)
			res.add(d.x,d.y);else
			res.set(MYRND*(FIELDSIZEX*KLET_SIZE),MYRND*(FIELDSIZEY*KLET_SIZE));
		ii=((int)res.x)/KLET_SIZE;
		jj=((int)res.y)/KLET_SIZE;

	    if(here(ii,jj))
			if(!Qpoly[ii][jj])break;
	}while(1);
	return res;
}*/
/*
BOOL LineCrossCircR(float cx,float cy,float x,float y,float radsq)
{
	float ll=(x*x+y*y),t=(x*cy-cx*y)/ll,x0=cx+y*t,y0=cy-x*t;

	if((cx-x0)*(cx-x0)+(cy-y0)*(cy-y0)>=radsq)return 0;
	if((x0>minim(0,x)&&x0<maxim(0,x))||(y0>minim(0,y)&&y0<maxim(0,y)))
		return 1;
	if(cx*cx+cy*cy<radsq) {return 1;}
	if((cx-x)*(cx-x)+(cy-y)*(cy-y)<radsq) {return 1;}
	

	return 0;

}*/
float DistSQRLineToCirc(tka a,tka l,tka v)
{
	float t=l.getScalarProduction(v-a)/(l.getLengthSquare());
	if(t<0)return (v-a).getLengthSquare();
	if(t>1)return (a+l-v).getLengthSquare();

	return (a+l*t-v).getLengthSquare();

}

float DistSQRLineToLine(tka a1,tka a2,tka b1,tka b2)
{
	float l,ml=32000;
	tka l1=a2-a1,l2=b2-b1;
	l=DistSQRLineToCirc(a1,l1,b1); if(ml>l)ml=l;
	l=DistSQRLineToCirc(a1,l1,b2); if(ml>l)ml=l;
	l=DistSQRLineToCirc(b1,l2,a1); if(ml>l)ml=l;
	l=DistSQRLineToCirc(b1,l2,a2); if(ml>l)ml=l;

	return ml;
	
}
float DistSQRPolyToPoly(tka*p1,tka*p2)
{
	int n[]={LNUM(p1),LNUM(p2)};
	int i,j;
	float l,ml=32000;
	
	for(i=0;i<n[0];i++)
		for(j=0;j<n[1];j++)
		{
			l=DistSQRLineToLine(*(p1+i),*(p1+i+1),*(p2+j),*(p2+j+1));
			if(ml>l)ml=l;
		}
	return ml;
}

bool GoodPoly(int p)
{
	int i;
	for(i=0;i<p;i++)
		if(!PolyCrossPoly(Poly[p],Poly[i]))
			if(DistSQRPolyToPoly(Poly[p],Poly[i])<16||TkaInsidePoly(Poly[p][0],Poly[i])||TkaInsidePoly(Poly[i][0],Poly[p]))return 0;
	return 1;
}

bool LineCrossLine(tka*a1,tka*a2,tka*b1,tka*b2)
{
	return ((((b1->x-a1->x)*(a2->y-a1->y)-(b1->y-a1->y)*(a2->x-a1->x))*((b2->x-a1->x)*(a2->y-a1->y)-(b2->y-a1->y)*(a2->x-a1->x))<0)&&
		    (((a1->x-b1->x)*(b2->y-b1->y)-(a1->y-b1->y)*(b2->x-b1->x))*((a2->x-b1->x)*(b2->y-b1->y)-(a2->y-b1->y)*(b2->x-b1->x))<0));
	
}

bool LineCrossSomething(tka a,tka b,int*ppoly, tka* pnt)
{
	tka d(0,0),**t;
//1	st<tka*> oldl;
	int n=((int)maxF(abs(b.x-a.x),abs(b.y-a.y)))/(KLET_SIZE),ii,jj,i,j,nn,ii0=-1,jj0=-1;
	if(n)
	{
		d.setBoth((b.x-a.x)/n,(b.y-a.y)/n);
	}else
		return 0;

	for(i=0;i<=n;i++)
	{
		ii=((int)a.x)/KLET_SIZE;
		jj=((int)a.y)/KLET_SIZE;
		if(ii!=ii0 || jj!=jj0)
		{
			ii0=ii;
			jj0=jj;
			if(here(ii,jj))
			{
				t=Qpoly[ii][jj];
				if(t)
				{
					nn=_msize(t)/sizeof(tka*);
					for(j=0;j<nn;j++)
//1						if(!oldl.Exists(t[j]))
					{
//1						oldl.AddEl(t[j]);
						if(LineCrossLine(&a,&b,t[j],t[j]+1))
						{
							if(ppoly)*ppoly=Qip[ii][jj][j];
							if(pnt)*pnt=a;
							return 1;
						}
					}
				}
			}
		}

		a.x+=d.x;
		a.y+=d.y;
	}
	return 0;
}

int LineCrossPoly( tka *a, tka *b, tka *p, const bool onetime ) {
	const int n = LNUM( p );
	int s = 0;
	
	for ( int i = 0; i < n; i++ ) {
		if ( LineCrossLine( a, b, p + i, p + i + 1 ) ) {
			if ( onetime ) {
				return 1;
			}

			s++;
		}
	}

	return s;
}

bool LineLine2(tka&a1,tka&a2,tka&b1,tka&b2,tka*v0)
{
	float t;
	if((((b1.x-a1.x)*(a2.y-a1.y)-(b1.y-a1.y)*(a2.x-a1.x))*((b2.x-a1.x)*(a2.y-a1.y)-(b2.y-a1.y)*(a2.x-a1.x))<0)&&
		    (((a1.x-b1.x)*(b2.y-b1.y)-(a1.y-b1.y)*(b2.x-b1.x))*((a2.x-b1.x)*(b2.y-b1.y)-(a2.y-b1.y)*(b2.x-b1.x))<0))
	{
		t=((b1.x-a1.x)*(a2.y-a1.y)-(b1.y-a1.y)*(a2.x-a1.x))/((b2.y-b1.y)*(a2.x-a1.x)-(b2.x-b1.x)*(a2.y-a1.y));
		
		if(v0)v0->setBoth(b1.x+(b2.x-b1.x)*t,b1.y+(b2.y-b1.y)*t);
		
		
		return 1;

	}
	return 0;
}

int LineCrossPoly2(tka* a,tka* b,tka*p,tka*v0)
{
	
	
	int n=LNUM(p),i,k=-1;
	float l,ml;
	tka tmpt;
	
	for(i=0;i<n;i++)
		if((b->x-a->x)*((p+i+1)->y-(p+i)->y)-(b->y-a->y)*((p+i+1)->x-(p+i)->x)>0)
		if(LineLine2(*a,*b,p[i],p[i+1],&tmpt))
	    {
			l=(a->x-tmpt.x)*(a->x-tmpt.x)+(a->y-tmpt.y)*(a->y-tmpt.y);
			if(k==-1||ml>l)
			{
				ml=l;
				k=i;
				*v0=tmpt;
			}
		
	    }
	return k;

}

bool PolyCrossPoly(tka*p1,tka*p2)
{
	int i,j;
	int n[]={LNUM(p1),LNUM(p2)};
	
	for(i=0;i<n[0];i++)
		for(j=0;j<n[1];j++)
			if(LineCrossLine(p1+i,p1+i+1,p2+j,p2+j+1)){return 1;}
	return 0;

}
tka*PolyUnion(tka*p1,tka*p2)
{
	int cp=0,cv=0,oldp,oldv,tmpi,i=0;
	tka tmpt,tmpt2;
	tka*up=0;
	int n[]={LNUM(p1),LNUM(p2)};
	tka*p[]={p1,p2};
	
	//if(!PolyCrossPoly(p1,p2))return 0;
	for(oldp=0;oldp<2;oldp++)
	    for(oldv=0;oldv<n[oldp];oldv++)
		{
			if((p[cp]+cv)->x<(p[oldp]+oldv)->x){cp=oldp;cv=oldv;}
			
		}
	
	
	
	oldp=cp;
	oldv=cv;
/*	PutInt(cp);
	PutChar1(' ');
	PutInt(cv);
	PutChar1(';');*/
	tmpt=p[cp][cv];
	
	do
	{
		AddElem(tmpt,&up);
		
		cv=(cv+1)%n[cp];
		
		
		
		tmpi=LineCrossPoly2(&tmpt,p[cp]+cv,p[!cp],&tmpt2);
		
		if(tmpi!=-1)
		{
			
			tmpt=tmpt2;
			cp=!cp;
			cv=tmpi;
		}else tmpt=p[cp][cv];
		i++;
		
	}
	while(!(cv==oldv&&cp==oldp&&(tmpi==-1))&&i<200);
	if(i==500){delete[]up;return 0;}

	AddElem(*up,&up);
	return up;

				
}

void LinePr(float cx,float cy,float *vx,float *vy)
{
	float h=(*vx*cx+*vy*cy)/(cx*cx+cy*cy);
	*vx=cx*h;
	*vy=cy*h;

}

void LinePr2(float cx,float cy,float *vx,float *vy)
{
	float h=(*vx*cx+*vy*cy)/(cx*cx+cy*cy);
	//*vx*=-0.1f;
	//*vx*=-0.1f;
	*vx+=cx*h-cy*0.1f;
	*vy+=cy*h+cx*0.1f;

}

bool LineCrossCirc(float cx,float cy,float x,float y,float *vx,float *vy)
{
	if(y*(*vx)-x*(*vy)<=0)return 0;
	float ll=(x*x+y*y),t=(x*cx+cy*y)/ll,x0=x*t,y0=y*t,h;
	if((cx-x0)*(cx-x0)+(cy-y0)*(cy-y0)>=MANSIZESQ)return 0;
	//if((x0>minim(0,x)&&x0<maxim(0,x))||(y0>minim(0,y)&&y0<maxim(0,y)))
	if(t>=0.0f && t<=1.0f)
	{
	    
	    h=(*vx*x+*vy*y)/ll;
		*vx*=-0.1f;
		*vy*=-0.1f;
		*vx+=x*h;//*0.1f;
		*vy+=y*h;//*0.1f;

		return 1;
	}

	if(cx*cx+cy*cy<MANSIZESQ) {LinePr2(cy,-cx,vx,vy);return 1;}
	if((cx-x)*(cx-x)+(cy-y)*(cy-y)<MANSIZESQ) {LinePr2(cy-y,x-cx,vx,vy);return 1;}
	

	return 0;

}
void RoundPoly(tka**p)
{
	int i,n=LNUM(*p),j;
	tka*np=0;
	for(i=0;i<n;i++)
		for(j=1;j<3;j++)
		    AddElem(*(*p+i+1)*float(j)/3.0f+*(*p+i)*float(3-j)/3.0f,&np);
	AddElem(*np,&np);
	delete[]*p;
	*p=np;

}
void RandPoly(tka*p)
{
	tka c;
	bool f=1;
	float ang=RND01*(PI*2),sa,ca;
	int i,sz=MyRand()%POLY_Q_SIZE+POLY_Q_SIZE/2 , pqs=10;
	float tmpi=float(FLD_SIZE*(MyConf.map_size+1));
	tmpi*=tmpi;

/*	do{
	c=RandTka();
	}while(c.x<pqs||c.y<pqs||c.x>MapW*KLET_SIZE-pqs||c.y>MapH*KLET_SIZE-pqs);
*/	
	sa=sin(ang);
	ca=cos(ang);
	while(f)
	{
		c=RandTka();
		
		for(i=0;i<FLD_NUM;i++)
			if((fld+i)->getLengthSquare(c)<tmpi)
			{
				tmpi*=0.7f;
				break;
			}
		if(i!=FLD_NUM)continue;

		p->setBoth(-RND01*sz-sz,-RND01*sz-sz);
		(p+1)->setBoth(-RND01*sz-sz,RND01*sz+sz);
		(p+2)->setBoth(RND01*sz+sz,RND01*sz+sz);
		(p+3)->setBoth(RND01*sz+sz,-RND01*sz-sz);
		if(MyRand()%10 == 0){p->x-=sz*10;(p+2)->x+=sz*10;}

		for(sz=0;sz<4;sz++)
		{
			(p+sz)->rotate(sa,ca);
			p[sz]+=c;
		}
		f=0;
		for(sz=0;sz<4;sz++)
			if((p+sz)->x<pqs||(p+sz)->y<pqs||(p+sz)->x>MapW*KLET_SIZE-pqs||(p+sz)->y>MapH*KLET_SIZE-pqs)f=1;

	}




}
void LineMark(tka*a,tka*b,int ip)
{
	tka d=(*b-*a),t0=*a;
	int l=((int)d.getLength()),i,ii,jj,aa,bb;
	if(l)d=d/(float)l;
	
	for(i=0;i<l;i++)
	{
		ii=((int)t0.x)/KLET_SIZE;
		jj=((int)t0.y)/KLET_SIZE;
		for(aa=ii-1;aa<=ii+1;aa++)
  		   for(bb=jj-1;bb<=jj+1;bb++)
			   if(here(aa,bb))
			   {
				   if(!ExistsElem(a,Qpoly[aa][bb]))
				   {
				      AddElem(a,Qpoly[aa]+bb);
					  AddElem(ip,Qip[aa]+bb);
					  
				   }
			   }

		t0=t0+d;
	

	}
	
}
void PolyMark(tka*p,int ip)
{
	
	int j,n=LNUM(p);
	int i1,j1,i2,j2,ii,jj;
	tka tmpt,tmpt2;
	
	for(j=0;j<n;j++)
	{
		if(!j||(i1>(int)(p+j)->x))i1=(int)(p+j)->x;
		if(!j||(j1>(int)(p+j)->y))j1=(int)(p+j)->y;
		if(!j||(i2<(int)(p+j)->x))i2=(int)(p+j)->x;
		if(!j||(j2<(int)(p+j)->y))j2=(int)(p+j)->y;
	
		LineMark(p+j,p+j+1,ip);
	}
	i1/=KLET_SIZE;
	j1/=KLET_SIZE;
	i2/=KLET_SIZE;
	j2/=KLET_SIZE;
	if(i1<0)i1=0;
	if(j1<0)j1=0;
	if(i2>=MapW)i2=MapW-1;
	if(j2>=MapH)j2=MapH-1;
	tmpt2.setBoth((i2+2)*KLET_SIZE+0.01f,(j2+2)*KLET_SIZE+0.001f);
	for(ii=i1;ii<=i2;ii++)
		for(jj=j1;jj<=j2;jj++)
			if(!Qpoly[ii][jj])
		{
			tmpt.setBoth(ii*KLET_SIZE+KLET_SIZE*0.5f,jj*KLET_SIZE+KLET_SIZE*0.5f);
			if(LineCrossPoly(&tmpt,&tmpt2,p)&1)
			{
				
				
			    AddElem(p,Qpoly[ii]+jj);
				AddElem(ip,Qip[ii]+jj);
			}
		}
	


}
tka** UnitePolies(tka**pols)
{
	tka**res=0;
	tka*tmpp;
	int i,j,n0=_msize(pols)/sizeof(tka*),n1=0;
	
	for(i=0;i<n0;i++)
	{
		tmpp=0;
		if(n1)
		for(j=0;j<n1;j++)
			if(PolyCrossPoly(res[j],pols[i]) || TkaInsidePoly(*res[j],pols[i]) || TkaInsidePoly(*pols[i],res[j]))
			{
				

				
				tmpp=PolyUnion(res[j],pols[i]);
				
				if(tmpp)
				{
				   delete[]res[j];
				   delete[]pols[i];
				   res[j]=tmpp;

				   break;
				}//else PutChar1('f');
			}
		if(!tmpp)
		{
			AddElem(pols[i],&res);
			n1++;
		}

	}
	return res;


}
int MakeUnion(tka***pols)
{
    int n0,n1;
	tka**tmp;
	n1=_msize(*pols)/sizeof(tka*);
	do
	{
		n0=n1;
		
		tmp=UnitePolies(*pols);
		
		delete[]*pols;
		*pols=tmp;
		n1=_msize(*pols)/sizeof(tka*);
		
	}while(n0!=n1);
	return n1;
}

bool InsideTriangle(tka v,tka a,tka b,tka c)
{
	char bbb;
	bbb=((v-a).getVectorProduction(b-a)>0);
	bbb|=2*((v-b).getVectorProduction(c-b)>0);
	bbb|=4*((v-c).getVectorProduction(a-c)>0);
	return (bbb==0)||(bbb==7);



}

bool TkaInsidePoly(tka a,tka*p)
{
	int i,n=LNUM(p),k=0;
	tka ttt;
	for(i=1;i<n;i++)
		if((p+i)->x>(p+k)->x)k=i;
	ttt=*(p+k)+tka(1,0);
	return (LineCrossPoly(&a,&ttt,p)&1);
	
}
tka*BuildTPoly(tka*p)
{
	tka*tp=0;
	tka tmpt,tmpt2;
	int i,n=LNUM(p);
	for(i=0;i<n;i++)
	{
		tmpt=p[(i+1)%n]-p[i];
		tmpt.setBoth(-tmpt.y,tmpt.x);
		tmpt2=p[(i+1)%n]-p[(i+2)%n];
		tmpt2.setBoth(tmpt2.y,-tmpt2.x);
		tmpt.normalize();
		tmpt2.normalize();
		tmpt+=tmpt2;
		tmpt.normalize();
		tmpt=p[(i+1)%n]+tmpt*4.0f;
		//if(!TkaInsidePoly(tmpt,p))
		AddElem(tmpt,&tp);

	}
	return tp;

}
void CurrectTP(int id)
{
	tka*p=Poly[id],*tp=TPoly[id];
	tka*ntp=0;
	int tn=TLNUM(tp),i;
	for(i=0;i<tn;i++)
		if(!TkaInsidePoly(tp[i],p))AddElem(tp[i],&ntp);
	delete[]tp;
	TPoly[id]=ntp;
}
void PreparePoly(int i)
{
	int n=LNUM(Poly[i]),j;
	float ll;
	PolyMark(Poly[i],i);
    (PolyCent+i)->setBoth(0,0);
   
    for(j=0;j<n;j++)
		   PolyCent[i]+=Poly[i][j];
    PolyCent[i]/=(float)n;
	TPoly[i]=BuildTPoly(Poly[i]);
	global_obstacleVerticesQuantities[i]=n;
	PolyRad[i]=0;
	for(j=0;j<global_obstacleVerticesQuantities[i];j++)
	{
	   ll=(PolyCent+i)->getLengthSquare(Poly[i][j]);
	   if(ll>PolyRad[i])PolyRad[i]=ll;
	}	   
	PolyRad[i]=sqrt(PolyRad[i]);
}
void PreparePolys()
{
	int i;
	PolyCent=new tka[global_quantityOfObstacles];
	TPoly=new tka*[global_quantityOfObstacles];
	global_obstacleVerticesQuantities=new int[global_quantityOfObstacles];
	PolyRad=new float[global_quantityOfObstacles];
	for(i=0;i<global_quantityOfObstacles;i++)
	{
		
		//for(j=0;j<3;j++)		
//		RoundPoly(Poly+i);
//		RoundPoly(Poly+i);

//		CurrectTP(i);


//		OptPoly(Poly+i);
//		if(!GoodPoly(i)){PutInt(i);PutChar1(' ');}
	   
		PreparePoly(i);

	}
	vbo.InitPolyVBO();
}

void CreateRandPolys()
{
	int i,n;
	
	
	global_quantityOfObstacles=(POLY_NUM*(1+MyConf.poly_num)*(1+MyConf.map_size)*(1+MyConf.map_size))/64 + 10*(3-MyConf.map_size);
	Poly=new tka*[global_quantityOfObstacles];
	
	CreateField();
    for(i=0;i<global_quantityOfObstacles;i++)
	{
		
		n=4;
		Poly[i]=new tka[n+1];
		do{RandPoly(Poly[i]);Poly[i][n]=Poly[i][0];}while(!GoodPoly(i));
		
		
	}
	global_quantityOfObstacles=MakeUnion(&Poly);

	PreparePolys();

	
	delete[] fld;
	
}
void InitPoly()
{
	int i,j;

    
	Qpoly=new tka***[FIELDSIZEX];
	Qip=new int**[FIELDSIZEX];
	for(i=0;i<FIELDSIZEX;i++)
	{
		Qpoly[i]=new tka**[FIELDSIZEY];
		Qip[i]=new int*[FIELDSIZEY];
		for(j=0;j<FIELDSIZEY;j++)
		{
			Qip[i][j]=0;
			Qpoly[i][j]=0;
		}
	}
	

	
}
void UnInitPoly()
{
	int i;
	DelPolys();

	for(i=0;i<FIELDSIZEX;i++)
	{
		
		delete[]Qip[i];
		delete[]Qpoly[i];
	}
	delete[]Qip;
	delete[]Qpoly;
}

void DelPolys()
{
	int i,j;
	vbo.UnInitPolyVBO();
	for(i=0;i<global_quantityOfObstacles;i++){delete[]Poly[i];delete[]TPoly[i];}
	
	for(i=0;i<FIELDSIZEX;i++)
	{
		for(j=0;j<FIELDSIZEY;j++)
		{
			if(Qpoly[i][j]){delete[]Qpoly[i][j];Qpoly[i][j]=0;}
			if(Qip[i][j]){delete[]Qip[i][j];Qip[i][j]=0;}
		}
	}
	if(global_quantityOfObstacles)
	{
		global_quantityOfObstacles=0;
		delete[]Poly;
		delete[]global_obstacleVerticesQuantities;
		delete[]PolyRad;
		delete[]TPoly;
		delete[]PolyCent;
	}
}

