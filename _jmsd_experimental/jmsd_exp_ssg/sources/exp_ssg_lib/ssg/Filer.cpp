#include "Filer.h"

#include "Units.h"
#include "Group.h"
#include "GUI.h"
#include "Polygon.h"
#include "Game.h"
#include "Control.h"
#include "Bases.h"
#include "Diplomation.h"
#include "Missiles.h"
#include "warfog.h"
#include "Ai.h"
#include "MainGl.h"
#include "DrawPolygon.h"


// #include "include_Windows.h"


bool LoadGame( ::std::string const &fn ) {
	CFile gfile;

	if ( !gfile.Open( fn.c_str(), OPEN_EXISTING ) ) {
		global_onScreenMessages.AddElToBeg( MyMessage( fn + ::std::string( LSTRING( " didn't found", " не найден" ) ) ) );
		return 0;
	}


	DelPolys();
	DeleteAllGroups();

	gfile.Read( &MyConf.MY_PLAYER, sizeof( char ) );
	gfile.Read( &PlHere, sizeof( char ) );
	gfile.Read( &comp, sizeof( char ) );

	gfile.Read( &curpos, sizeof( tka ) );

	gfile.Read( &SCALE,sizeof(float));


	gfile.Read( &MapW, sizeof( int ) );
	gfile.Read( &MapH, sizeof( int ) );
	gfile.Read( &global_quantityOfObstacles, sizeof( int ) );

	Poly = new tka * [ global_quantityOfObstacles ];

	for ( size_t i = 0; i < global_quantityOfObstacles; i++ ) {
		size_t n = 0;
 	    gfile.Read( &n, sizeof( n ) );
		Poly[ i ] = new tka[ n + 1 ];

		gfile.Read( Poly[ i ], sizeof( tka ) * n );
		Poly[ i ][ n ] = Poly[ i ][ 0 ];
	}

	PreparePolys();

	gfile.Read(&BasesNum,sizeof(int));
	gfile.Read(Bases,BasesNum*sizeof(base));

	for ( size_t i = 0; i < MAXSLD; i++ ) {
		( Units + i )->way.renull();
		( Units + i )->life = 0;
	}

	for ( size_t j = 0; j < UNIT_TYPES; j++ ) {
		SelInfo[ j ] = 0;

	    for ( size_t i = 0; i < PLAYERS_NUM; i++ ) {
			UnInfo[ i ][ j ] = 0;
		}
	}

	UnSelect();

	gfile.Read( &UnitsNum, sizeof( UnitsNum ) );

	sld *sldp = Units;

	for ( size_t i = 0; i < UnitsNum; i++, sldp++ ) {
        gfile.Read(&(sldp->pos),sizeof(tka));
		gfile.Read(&(sldp->pl),sizeof(char));
		gfile.Read(&(sldp->type),sizeof(char));
		gfile.Read(&(sldp->life),sizeof(char));
		gfile.Read(&(sldp->a),sizeof(sldp->a));
		gfile.Read(&(sldp->group_id),sizeof(sldp->group_id));
		if(sldp->group_id!=-1)(global_groups+sldp->group_id)->un.AddEl(i);
		sldp->way.AddEl(tka(0,0));
		gfile.Read(&(sldp->way.beg->v),sizeof(tka));
		sldp->enemy=-1;

		sldp->nav.setBoth(cos(sldp->a*(float)(PI_180*0.5)),sin(sldp->a*(float)(PI_180*0.5)));
		//sldp->a=0;
		//sldp->nav.set(1,0);

		sldp->vel.setBoth(0,0);

		UnInfo[sldp->pl&7][sldp->type]++;

	}

	Group *gg = global_groups;

	for ( size_t i = 0; i < MAX_GROUPS_NUM; i++, gg++ ) {
		if(gg->un.beg)
		{
			gfile.Read(&gg->pos,sizeof(tka));
			gfile.Read(&gg->nav,sizeof(tka));
		}
	}

	gfile.Read(&global_diplomation,sizeof(global_diplomation));
	gfile.Read(&Warfog_is,sizeof(Warfog_is));

//	gfile.Read(&Build_start,sizeof(Build_start));
//	gfile.Read(&Building_is,sizeof(Building_is));

	gfile.Read(&Building,sizeof(Building));
	MisNum=0;
	ClearFog();
	gfile.Close();


	UpDateEnemy();


	return 1;
}

void SaveGame( ::std::string const &fn ) {
	CFile gfile(fn.c_str(),CREATE_ALWAYS);

	gfile.Write(&MyConf.MY_PLAYER,sizeof(char));
	gfile.Write(&PlHere,sizeof(char));
	gfile.Write(&comp,sizeof(char));


	gfile.Write(&curpos,sizeof(tka));
	gfile.Write(&SCALE,sizeof(float));

	gfile.Write(&MapW,sizeof(int));
	gfile.Write(&MapH,sizeof(int));
	gfile.Write(&global_quantityOfObstacles,sizeof(int));

	for ( size_t i = 0; i < global_quantityOfObstacles; i++ ) {
		size_t n = LNUM( Poly[ i ] );
 	    gfile.Write( &n, sizeof( n ) );
		//for(j=0;j<n;j++)
		gfile.Write( Poly[ i ], n * sizeof( tka ) );
	}

	gfile.Write(&BasesNum,sizeof(int));
	//for(i=0;i<BasesNum;i++)
	gfile.Write(Bases,BasesNum*sizeof(base));

	gfile.Write( &UnitsNum, sizeof( UnitsNum ) );

	sld *sldp = Units;

	for ( size_t i = 0; i < MAXSLD; i++, sldp++ )
		if(sldp->life)
		{

			gfile.Write(&sldp->pos,sizeof(tka));
			gfile.Write(&sldp->pl,sizeof(char));
			gfile.Write(&sldp->type,sizeof(char));
			gfile.Write(&sldp->life,sizeof(char));
			gfile.Write(&sldp->a,sizeof(sldp->a));
			gfile.Write(&sldp->group_id,sizeof(sldp->group_id));
			if(sldp->way.beg)gfile.Write(&sldp->way.beg->v,sizeof(tka));else gfile.Write(&sldp->pos,sizeof(tka));
		}

//	i=GetGroupsNum();
//	gfile.Write(&i,sizeof(int));

	Group *gg = global_groups;

	for ( size_t i = 0; i < MAX_GROUPS_NUM; i++, gg++ ) {
		if ( gg->un.beg ) {
			gfile.Write( &gg->pos, sizeof( tka ) );
			gfile.Write( &gg->nav, sizeof( tka ) );
		}
	}

	gfile.Write(&global_diplomation,sizeof(global_diplomation));
	gfile.Write(&Warfog_is,sizeof(Warfog_is));
//	gfile.Write(&Build_start,sizeof(Build_start));
//	gfile.Write(&Building_is,sizeof(Building_is));
	gfile.Write(&Building,sizeof(Building));

    gfile.Close();
	global_onScreenMessages.AddElToBeg(MyMessage(LSTRING("Game saved","»гра —охранена")));
}


void SaveSetings()
{
	CFile file("config.gm",CREATE_ALWAYS);
	file.Write(&MyConf,sizeof(MyConf));
	file.Close();

}
/*
void StoW(std::wstring &dest, const std::string &src)
{
    dest.resize(src.size());
    for (std::string::size_type i = 0; i < src.size(); i++)
        dest[i] = static_cast<unsigned char>(src[i]);
}
std::wstring StoW(const std::string &src)
{
	std::wstring dest;
	StoW(dest,src);
	return dest;
}

void WtoS(std::string &dest, const std::wstring &src)
{
    dest.resize(src.size());
    for (std::wstring::size_type i = 0; i < src.size(); i++)
        dest[i] = static_cast<char>(src[i]);
}
std::string WtoS(const std::wstring &src)
{
	std::string dest;
	WtoS(dest,src);
	return dest;
}*/

//void GetFiles( std::string& res_parameter, std::string type ) {
//	std::wstring res = std::toWideString( res_parameter );

//	int n=0,i1=0,i2=0;
//	bool fl = false;
//	std::wstring tmps;
//	WIN32_FIND_DATA lpFindFileData;

//	HANDLE hFindFile = ::FindFirstFile( L".\\*", &lpFindFileData );

//	if ( res.size() && res[ 0 ] > 0 ) {
//		fl = true;
//	}

//	res.clear();

//	//WCHAR fn[300];

//	res.push_back('#');

//    while(FindNextFile( hFindFile, &lpFindFileData))
//	{
//		i2=(int)wcslen(lpFindFileData.cFileName)-1;
//		i1=(int)type.size()-1;
//		if(type.size())
//		do
//		{
//			if(type[i1]!=lpFindFileData.cFileName[i2]) break;
//			i1--;
//			i2--;
//		}while(i1>=0 && i2>=0);
//		if(i1>=0 && i2>=0)continue;

//		tmps = lpFindFileData.cFileName;
//		tmps.resize(tmps.size()-type.size());


//		res+=tmps;
//		res.push_back(';');
//		n++;
//	}
//	res[0]=fl?n:-n;

//	res_parameter = std::toString( res );
//}

void GetFiles( std::string *out_result, ::std::string const &type ) {
//	std::wstring out_result = std::toWideString( out_result );
	if ( out_result == nullptr ) return;

	int n=0,i1=0,i2=0;
	bool fl = false;
	::std::string tmps;
	WIN32_FIND_DATA lpFindFileData;

	HANDLE hFindFile = ::FindFirstFile( ".\\*", &lpFindFileData );

	if ( out_result->size() && ( *out_result )[ 0 ] > 0 ) {
		fl = true;
	}

	out_result->clear();

	//WCHAR fn[300];

	out_result->push_back( '#' );

    while ( ::FindNextFile( hFindFile, &lpFindFileData ) ) {
		i2 = ( int )::std::strlen( lpFindFileData.cFileName ) - 1;
		i1=(int)type.size()-1;
		if(type.size())
		do
		{
			if(type[i1]!=lpFindFileData.cFileName[i2]) break;
			i1--;
			i2--;
		}while(i1>=0 && i2>=0);
		if(i1>=0 && i2>=0)continue;

		tmps = lpFindFileData.cFileName;
		tmps.resize(tmps.size()-type.size());


		( *out_result ) += tmps;
		out_result->push_back(';');
		n++;
	}

	( *out_result )[ 0 ] = fl ? n : -n ;
}

void LoadSetings()
{
	CFile file;
	bool fl=1;
	if(file.Open("config.gm",OPEN_EXISTING))
	{
		if(file.GetLength()==(DWORD)sizeof(MyConf))
		{
			file.Read(&MyConf,sizeof(MyConf));
			fl=0;
		}
		file.Close();

	}
	if(fl)
	{
		MyConf.map_size=2;
		MyConf.MY_PLAYER=0;
		MyConf.PlNum=8;
		MyConf.poly_num=2;
		MyConf.screen=0;
		MyConf.bases_num=1;
		MyConf.sound_val=90;
		MyConf.music_val=80;
		MyConf.show_tracks=true;
		MyConf.shadows_on=true;
		MyConf.lifebar_on=true;

		MyConf.BackColor[0]=0.5f;
		MyConf.BackColor[1]=0.6f;
		MyConf.BackColor[2]=0.7f;
		MyConf.PolyColor[0]=0.3f;
		MyConf.PolyColor[1]=0.5f;
		MyConf.PolyColor[2]=0.3f;

		MyConf.steps_per_frame=1;
		MyConf.ScrollSpeed = 50;

		SaveSetings();

	}
	SetResolution(MyConf.screen);
	for(int i=0;i<3;i++)
	{
		BackColor[i]=MyConf.BackColor[i];
		PolyColor[i]=MyConf.PolyColor[i];
	}


}


DWORD CFile::Read( LPVOID buf, DWORD num ) {
	if ( hfile == INVALID_HANDLE_VALUE ) return 0;

	DWORD res;
	ReadFile( hfile, buf, num, &res, 0 );
	return res;
}
DWORD CFile::Write(LPVOID buf, DWORD num)
{
	DWORD res;
	if(hfile!=INVALID_HANDLE_VALUE)
	{
		WriteFile(hfile,buf,num,&res,0);
		return res;
	}
	return 0;
}
bool CFile::Open(std::string fn,DWORD type)
{
	hfile = CreateFileA(fn.c_str(),GENERIC_READ|GENERIC_WRITE,0,0,type,FILE_ATTRIBUTE_NORMAL,0);
	return (hfile==INVALID_HANDLE_VALUE)?false:true;

}
void CFile::Close()
{
	if(hfile!=INVALID_HANDLE_VALUE)	CloseHandle(hfile);
}
DWORD CFile::GetLength()
{
	LARGE_INTEGER tmp;
	GetFileSizeEx(hfile, &tmp);
	return tmp.LowPart;
}
CFile::CFile(std::string fn,DWORD type)
{
	hfile=INVALID_HANDLE_VALUE;
	Open(fn, type);
}
