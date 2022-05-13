#include "GUI.h"

#include "Units.h"
#include "Menu.h"
#include "Game.h"
#include "Bases.h"
#include "Network.h"
#include "Control.h"
#include "Group.h"
#include "Wid.h"


stek<MyMessage>global_onScreenMessages;
std::string mess;


MyFont ArialFont;

int tmp_info;


void DrawInformation()
{
	glColor4d(0.4,0.4,0.2,0.7);
	glDisable(GL_TEXTURE_2D);
	DrawQuad(float(WIDTH-200),5.0f,float(WIDTH-5),55.0f,1/64.0f);
	glEnable(GL_TEXTURE_2D);
	DrawFrame(WIDTH-200,5,195,50,0);

	glColor3d(0.9,0.9,0.5);
	DrawMyText(WIDTH-200,10,195,20,std::string(LSTRING("Units:","Кол-во юнитов: "))+IntToString(UnitsNum));
	
	if(Building)

//	DrawMyText(WIDTH-200,30,195,20,std::string("Производство: ")+IntToString((100*(GameTime%GROW_TIME))/GROW_TIME)+std::string("%"));
	DrawMyText(WIDTH-200,30,195,20,std::string(LSTRING("Production:","Производство: "))+IntToString(100-(100*Building)/GROW_TIME)+std::string("%"));
//else
	//DrawMyText(WIDTH-200,30,195,20,(std::string("min: ")+IntToString(Build_start)));
	
	
	DrawNumber(10,130,10,net_time);
//	DrawNumber(10,150,10,tmp_info);

	DrawNumber(10,100,15,fps);	
}

void DrawMes()
{
	el<MyMessage>*tmp=global_onScreenMessages.top;
	
	int y=MES_BOX_Y,nn=0;
	static int ttt=100;
	static std::string ps(LSTRING("Pause","Пауза"));
	if(status&16){glColor3d(0,0,0);DrawMyText(WIDTH/2-20,10,1,ps);}

	if(!tmp)return;
	
	nn=global_onScreenMessages.GetNum();
	tmp=global_onScreenMessages.top;
	glBindTexture ( GL_TEXTURE_2D, TEXTURE_WID.texID);
		
	if(MouseOnButton(MES_BOX_X,(float)(MES_BOX_Y-MES_TXT_STEP*nn),MES_BOX_W,(float)(MES_TXT_STEP*nn)))
		glColor3f(0.5f,0.5f,0.4f);
	else
		glColor4f(0.3f,0.3f,0.2f,0.7f);
	DrawQuad(MES_BOX_X,MES_BOX_Y,MES_BOX_X+MES_BOX_W,MES_BOX_Y-MES_TXT_STEP*nn,(1.0f/64));
	DrawFrame(MES_BOX_X,MES_BOX_Y-MES_TXT_STEP*nn,MES_BOX_W,MES_TXT_STEP*nn,0);
	while(tmp)
	{
		nn++;
		glColor3fv(tmp->v.col);
		y-=MES_TXT_STEP;
		DrawMyText(MES_BOX_X+10,y,0.8f,tmp->v.val);
		tmp=tmp->next;
	}
   ttt--;
   if(!ttt){ttt=1000;global_onScreenMessages.DeleteEl();}
	

}

void DrawMenu()
{
	int i,ct=0;//,nct;
	bool mon;
	float tmpf;
	char tmpc;
	float x1,y1,x2,y2;
	el<int>* tmp=GrpSel.beg;
	int x=WIDTH-ICON_RAMA-ICON_SIZE,y=HEIGHT-2*ICON_SIZE-2*ICON_RAMA, ct2=0;
	


	y1=float(HEIGHT-ICON_SIZE-ICON_RAMA);
	y2=float(HEIGHT-ICON_RAMA);
	

	
	/*
	{
		if(!selB.beg)return;
		x2=float(ICON_RAMA);
		
		glBindTexture ( GL_TEXTURE_2D, TEXTURE_STATES.texID );
		glColor3f(1,1,1);
		for(i=0;i<BASE_STATES_NUM;i++)
		{
			x1=x2;
			x2+=ICON_SIZE;
			
			//tmpc=(Bases+selB.beg->v)->status;
			//if((tmpc&(1<<i)))glColor3f(1,1,1);else glColor4f(0.5f,0.5f,0.5f,0.6f);

		    
			DrawQuad2(x1,y1,x2,y2,i*0.25f,0,0.25f*(i+1),1);
			
	   }
	  	glColor3f(0.1f,0.1f,0);
		glBindTexture ( GL_TEXTURE_2D, TEXTURE_FRAME(0).texID );
		//if(ct)DrawFrame(WIDTH-ICON_RAMA-ICON_SIZE*ct,int(y1),ICON_SIZE*ct,ICON_SIZE,-1);
		DrawFrame(ICON_RAMA,int(y1),i*ICON_SIZE,ICON_SIZE,-1);
		//if(ct2)DrawFrame(WIDTH-ICON_RAMA-ICON_SIZE*ct2,y,ICON_SIZE*ct2,ICON_SIZE,-1);

		
	}
    */
	for(i=0;i<UNIT_TYPES;i++)
		if(SelInfo[i])
	    {
		    glBindTexture ( GL_TEXTURE_2D, TEXTURE_POLY(7).texID );
			x1=float(WIDTH-ICON_SIZE*ct-ICON_RAMA);
			
			x2=float(WIDTH-ICON_SIZE*(ct+1)-ICON_RAMA);
			mon=(mPos.x>x2 && mPos.y>y1 && mPos.x<x1 && mPos.y<y2);
			if(mon)glColor3f(0.5f,0.5f,0.3f);else glColor3f(0.3f,0.3f,0.2f);
			
			DrawQuad(x1,y1,x2,y2);
			glColor3f(1,1,1);
			tmpf=i/(float)UNIT_TYPES;
			glBindTexture ( GL_TEXTURE_2D, TEXTURE_UNITS.texID );
			DrawQuad2(x1-15,y1+5,x2+5,y2-15,tmpf,0,tmpf+1.0f/UNIT_TYPES,0.25f);
			
			DrawNumber(int(x2)+3,int(y2)-15,12,SelInfo[i]);
			
			
			ct++;

		
	    }

	while(tmp)
	{
		ct2++;
		mon=(mPos.x>x && mPos.y>y && mPos.x<x+ICON_SIZE && mPos.y<y+ICON_SIZE);
		if(mon)glColor3f(0.5f,0.5f,0.3f);else glColor3f(0.3f,0.3f,0.2f);
	    glBindTexture ( GL_TEXTURE_2D, TEXTURE_POLY(7).texID );

		DrawQuad(x,y,x+ICON_SIZE,y+ICON_SIZE);

		tmpf=(Units+(global_groups+tmp->v)->un.beg->v)->type/(float)UNIT_TYPES;
		glBindTexture ( GL_TEXTURE_2D, TEXTURE_UNITS.texID );
		DrawQuad2(x+3,y+3,x+ICON_SIZE-3,y+ICON_SIZE-3,tmpf,0,tmpf+1.0f/UNIT_TYPES,0.25f);

		glColor3d(1,1,1);

		
		DrawNumber(x+3,y+3,12,(global_groups+tmp->v)->un.GetNum());

		


		tmp=tmp->next;
		x-=ICON_SIZE;
	}

	if(!Building)  DrawButton(ICON_RAMA,ICON_RAMA,130,ICON_SIZE/2,LSTRING("Build units","Производство"),1);
	if(ct)  DrawButton((float)(WIDTH-ICON_RAMA-ICON_SIZE*(ct+1)),(float)(y1+ICON_SIZE/4),ICON_SIZE/2,ICON_SIZE/2,"G",1);
	if(ct2)	DrawButton((float)(WIDTH-ICON_RAMA-ICON_SIZE*(ct2+1)),(float)(y+ICON_SIZE/4),ICON_SIZE/2,ICON_SIZE/2,"U",1);
	
	if(ct||ct2)
	{
		x2=float(ICON_RAMA);
		
		glBindTexture ( GL_TEXTURE_2D, TEXTURE_STATES.texID );
		for(i=0;i<3;i++)
		{
			x1=x2;
			x2+=ICON_SIZE;
			
			//mon=(mPos.x>x1 && mPos.y>y1 && mPos.x<x2 && mPos.y<y2);
			if(sel.beg)
				tmpc=(Units+sel.beg->v)->pl;
			else
				tmpc=(Units+(global_groups+GrpSel.beg->v)->un.beg->v)->pl;
			if((tmpc&(1<<(3+i))))glColor3f(1,1,1);else glColor4f(0.5f,0.5f,0.5f,0.6f);

		    
			DrawQuad2(x1,y1,x2,y2,i*0.25f,0,0.25f*(i+1),1);
			
	   }


		
		glColor3f(0.1f,0.1f,0);
		glBindTexture ( GL_TEXTURE_2D, TEXTURE_FRAME(0).texID );
		if(ct) DrawFrame(WIDTH-ICON_RAMA-ICON_SIZE*ct,int(y1),ICON_SIZE*ct,ICON_SIZE,-1);
		DrawFrame(ICON_RAMA,int(y1),3*ICON_SIZE,ICON_SIZE,-1);
		if(ct2)DrawFrame(WIDTH-ICON_RAMA-ICON_SIZE*ct2,y,ICON_SIZE*ct2,ICON_SIZE,-1);

	}

}

void DrawMyText(float x1,float y1,float scale,std::string& s, MyFont& fnt)
{
/*	int pp=0,ct=0,n=s.size();
	tka ps;
	unsigned char ch;
	glBindTexture ( GL_TEXTURE_2D, texture[5]);
	while(pp!=n)
	{
		ch=s[pp]-32;
		ps.set((float)(ch%16)*(1.0f/16.0f),1-(float)(ch/16)*(1.0f/14.0f));
		DrawQuad2(x1+(pp*h),y1+h,x1+((pp+1)*h),y1, ps.x,ps.y-(1.0f/14.0f),ps.x+(1.0f/16.0f),ps.y);
		pp++;
	}
*/
	
	int i,n=s.size();
	float ps=(float)x1;
	//int ch;
	//int ww,www=0;
	FontChar tmpc;
	glBindTexture ( GL_TEXTURE_2D, TEXTURE_ARIAL_FONT.texID);
	for(i=0;i<n;i++)
	{
		tmpc=fnt.ch[((unsigned char)s[i])-32];
		//ww=(int)(tmpc.w*(h/((float)tmpc.h)));
		ps+=(float)tmpc.of1;
		DrawQuad2(ps,y1,(ps+tmpc.w*scale),y1+tmpc.h*scale, tmpc.x/512.0f,tmpc.y/256.0f,(tmpc.x+tmpc.w)/512.0f,(tmpc.y+tmpc.h)/256.0f);
		ps+=(tmpc.w+tmpc.of2)*scale;
	}
	
}
void DrawMyText(int x1,int y1,int w,int h,std::string& s, MyFont& fnt)
{
	DrawMyText((float)x1,(float)y1,(float)w,(float)h,s,fnt);
}
void DrawMyText(float x1,float y1,float w,float h,std::string& s, MyFont& fnt)
{
	int i,n=s.size(),ww=0,hh=0;
	tka ps;
	FontChar tmpc;
	float sc;
	if(!n)return;
	for(i=0;i<n;i++)
	{
		tmpc=fnt.ch[((unsigned char)s[i])-32];
		ww+=tmpc.w+tmpc.of1+tmpc.of2;
		hh=(int)std::max( h, static_cast< float >( tmpc.h ) );
	}
	sc=h/(float)hh;
	DrawMyText(x1+((w-ww*sc)*0.5f),y1+((h-hh*sc)*0.5f),sc,s,fnt);
}
void DrawMyText(int x1,int y1,float scale,std::string& s, MyFont& fnt)
{
	DrawMyText((float)x1,(float)y1,scale,s,ArialFont);
}
void DrawNumber(int x1,int y1,int h,int numb)
{
	DrawNumber((float)x1,(float)y1,(float)h,numb);
}

void DrawNumber(float x1,float y1,float h,int numb)
{
    
	char ct=5,pp=0,tmp[5];
	glBindTexture ( GL_TEXTURE_2D, TEXTURE_DIGITS.texID);
	do
	{
		ct--;
		tmp[ct]=numb%10;
		numb/=10;
	}
	while(numb);
	while(ct!=5)
	{
    	

		DrawQuad2(x1+(pp*h),y1+h,x1+((pp+1)*h),y1,float(tmp[ct])/10,1,float(tmp[ct]+1)/10,0);
		pp++;ct++;
	}
}

void DrawWid()
{
	int i,n;
	wid*www;
	if(cur_wdj==-1)return;
	
	www=wdj[cur_wdj];
	n=wid_num[cur_wdj];
	for(i=0;i<n;i++)
	{
		www->Draw();
		www++;		
	}

}
std::string GetListString(const char* s, int id)
{
//	std::string res;
	int i=0,old=0;
	while(s[i])
	{
		if(s[i]==';')
		{
			if(id)
			{
				id--;
				old=i+1;
			}
			else
			{
				return std::string(s+old,i-old);
			}
		}
		i++;
	}
	return "";
	
	
}
void DrawFrame(int x,int y,int w,int h,int txt)
{
	DrawFrame(float(x),float(y),float(w),float(h),txt);
}

void DrawFrame(float x,float y,float w,float h,int txt)
{
	if(txt!=-1)glBindTexture ( GL_TEXTURE_2D, TEXTURE_FRAME(txt).texID);
	DrawQuad(x-8,y-8,x+8,y+8);
	DrawQuad(x+w+8,y-8,x+w-8,y+8);
	DrawQuad(x-8,y+h+8,x+8,y+h-8);
	DrawQuad(x+w+8,y+h+8,x+w-8,y+h-8);

	DrawQuad2(x+8,y-8,x+w-8,y+8,15/16.0f,0.0f,15/16.0f,1.0f);
	DrawQuad2(x+8,y+h+8,x+w-8,y+h-8,15/16.0f,0.0f,15/16.0f,1.0f);
	DrawQuad2(x-8,y+8,x+8,y+h-8,0.0f,15/16.0f,1.0f,15/16.0f);
	DrawQuad2(x+w+8,y+8,x+w-8,y+h-8,0.0f,15/16.0f,1.0f,15/16.0f);

}
//0 - форма  1 - кнопка  2 - статич. текст
void wid::Draw()
{
	bool m_on=(mPos.x>x && mPos.y>y && mPos.x<x+w && mPos.y<y+h), enabled=GetEnable();
	//if(!enabled)m_on=0;
	int n=0,y1=y,i,h1=h;
	
	float ButCol[]={0.6f,0.6f,0.5f};
	float ButColMON[]={1.0f,1.0f,0.8f};
	float ButColDIS[]={0.8f,0.8f,0.8f};
	float Shadow[]={0.0f,0.0f,0.0f,0.5f};
	float White[]={1,1,1};
	float FrameCol[]={0.2f,0.3f,0.4f};
	float TxtCol[]={0.6f,0.6f,0.4f};
	float ListCol[]={0.4f,0.4f,0.1f};
	float ListColMON[]={0.7f,0.7f,0.2f};
	float TextBoxCol[]={0.4f,0.4f,0.3f};
	float TextBoxColACT[]={0.2f,0.2f,0.1f};

	switch(type)
	{
	case 0:
	case 3:

		glBindTexture ( GL_TEXTURE_2D, TEXTURE_WID.texID);
		if(enabled)
		{
			if(!m_on)glColor3fv(ButCol);else glColor3fv(ButColMON);
		}else glColor3fv(ButColDIS);

		DrawQuad(x,y,x+w,y+h,(1.0f/64));
		DrawFrame(x,y,w,h,1);
		
		
		if(m_on)
		{
			glColor4fv(Shadow);
			DrawMyText(x,y+2,w,h-4,text);
			glColor3fv(White);
			DrawMyText(x-3,y,w+1,h-3,text);
		}else
		{
			glColor3fv(White);
			DrawMyText(x,y+2,w,h-4,text);
		}
		
	break;
	case 1:
		glBindTexture ( GL_TEXTURE_2D, TEXTURE_WID.texID);
		if(enabled)
			glColor3fv(FrameCol);
		else
			glColor3fv(ButColMON);
		DrawQuad(x,y,x+w,y+h,(1.0f/64));
		DrawFrame(x,y,w,h,0);
		glColor3fv(TxtCol);
		DrawMyText(x,y+2,w,30,text);
		break;
	case 2:
		glColor3fv(TxtCol);
		DrawMyText(x,y,w,h,text);
		break;
	
/*	case 3:
		glBindTexture ( GL_TEXTURE_2D, texture[8]);
		DrawQuad(x,y,x+w,y+h,(1.0f/64));
		if(text[0]=='1')DrawMyText(x,y+2,w,h-4,std::string("V"));

		break;*/
	case 4:
		if(!m_on)glColor3fv(ListCol);else glColor3fv(ButColMON);
		glBindTexture ( GL_TEXTURE_2D, TEXTURE_WID.texID);
		DrawQuad(x+h,y,x+h+(((w-2*h)*text[0])/100),y+h,(1.0f/64));

		if(m_on && mPos.x<x+h) glColor3fv(ButColMON);else glColor3fv(ListCol);
		DrawQuad(x,y,x+h,y+h,(1.0f/64));

		

		if(m_on && mPos.x>x+w-h) glColor3fv(ButColMON);else glColor3fv(ListCol);
		DrawQuad(x+w-h,y,x+w,y+h,(1.0f/64));

		//glColor3fv(ButCol);
		glColor3fv(TextBoxColACT);
		DrawQuad(x+w-h,y,x+h+(((w-2*h)*text[0])/100),y+h,(1.0f/64));
		DrawFrame(x+h,y,w-2*h,h,2);
		DrawFrame(x,y,h,h,1);
		DrawFrame(x+w-h,y,h,h);
		glColor3fv(White);
		DrawMyText(x,y,h,h,std::string("<"));
		DrawMyText(x+w-h,y,h,h,std::string(">"));
		DrawMyText(x,y+2,w,h-4,IntToString(text[0])+std::string("%"));

		break;
	case 5:
		glBindTexture ( GL_TEXTURE_2D, TEXTURE_WID.texID);
		if(!m_on)glColor3fv(ListCol);else glColor3fv(ListColMON);
		
		DrawQuad(x,y,x+w,y+h,(1.0f/64));
		DrawFrame(x,y,w,h,1);
		glColor3fv(White);
		if(text[0]>0)
		{
			
			n=GetListSize(text.c_str()+1); 
			h1=h/(n+1);
			y1=y;
			DrawFrame(x,y1,w,h1,1);
			for(i=0;i<n;i++)
			{
				y1+=h1;
				if(mPos.x>x && mPos.y>y1 && mPos.x<x+w && mPos.y<y1+h1)
				{
					
					glBindTexture ( GL_TEXTURE_2D, TEXTURE_WID.texID);
					DrawQuad(x+2,y1,x+w-4,y1+h1,(1.0f/64));
					DrawFrame(x,y1,w,h1,2);
					
				}
				DrawMyText(x,y1+2,w,h1-4,GetListString(text.c_str()+1,i));
			}
		}
		
		DrawMyText(x,y+2,w,h1-4,GetListString(text.c_str()+1,abs(text[0])-1));

		

		break;
	case 6:
		glBindTexture ( GL_TEXTURE_2D, TEXTURE_WID.texID);
		
		if(cur_wdj_id!=id)glColor3fv(TextBoxCol);else glColor3fv(TextBoxColACT);
		DrawQuad(x,y,x+w,y+h,(1.0f/64));
		DrawFrame(x,y,w,h,1);
		
		if(!m_on)glColor3fv(TxtCol);else glColor3fv(White);
		DrawMyText(x,y,w,h,text);
		break;

	}
}
