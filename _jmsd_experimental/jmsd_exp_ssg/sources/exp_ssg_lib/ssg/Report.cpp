#include "Report.h"

#include "Filer.h"


CFile global_file;

void CloseRpt()	{
	global_file.Close();
}

void OpenRpt() {
	global_file.Open( "MyReport.txt", CREATE_ALWAYS );
}

void PutChar1(char ch)
{
	global_file.Write(&ch,1);
}
void PutEnter()
{
	static char ENTER[]={13,10};
	global_file.Write(ENTER,2);
}
void PutString(std::string s)
{
	global_file.Write((LPVOID)s.c_str(),s.size());

}

void PutInt(int i)
{
	//PutChar1('{');
	char a[5],n=0;
	if(i<0){PutChar1('-');i=-i;}

	do
	{
		a[n]='0'+i%10;
		i/=10;
		n++;
	}while(i);
	do
	{
		n--;
		PutChar1(a[n]);
	}while(n);


	//PutChar1('}');
}
void PutDW(DWORD i)
{
	//PutChar1('{');
	char a[20],n=0;
	do
	{
		a[n]='0'+(char)(i%10);
		i/=10;
		n++;
	}while(i);
	do
	{
		n--;
		PutChar1(a[n]);
	}while(n);


	//PutChar1('}');
}
void PutFloat(float val)
{
	char tmpc[30];
	sprintf_s(tmpc,"%g",val);
	PutString(std::string(tmpc));
}

void ClearReport()
{global_file.Close();global_file.Open("MyReport.txt",CREATE_ALWAYS);}
