#include "Sound.h"

#include "remSnd.h"
#include "Menu.h"
#include "Control.h"
#include "Graph2d.h"


char param=0;//&1-nosound

remSnd *global_Snd3D[ SOUNDS_NUMBER ];
remSnd *global_Music[ MUSICS_NUMBER ];
st<std::string> CurPlay;

int operator==( const std::string &s1, const std::string &s2 ) {
	return !strcmp( s1.c_str(), s2.c_str() );
} 

std::string operator +( const std::string &s1, const std::string &s2 ) {
	std::string res = s1;
	res += s2;
	return res;
}

void InitMusic() {	
	for ( int i = 0; i < MUSICS_NUMBER; i++ ) {
		remSnd *newMusic = new remSnd;

		remSnd **currentMusicSlot = &global_Music[ i ];

		if ( newMusic->Open( std::string( "Music//m" ) + IntToString( i ) + std::string( ".OGG" ), 0, 0 ) ) {
			newMusic->Move( 0, 0, 0 );
			*currentMusicSlot = newMusic;
			newMusic = nullptr;
		} else {
			*currentMusicSlot = nullptr;
		}
	}
}

void PlayMusic()
{
	static int cur_m=0;
	// JMSFC: transfering to Audiere
// 	ALint state=0;
// 	alGetSourcei(Music[cur_m].mSourceID, AL_SOURCE_STATE, &state);
// 	if(state==AL_PLAYING)return;
// 	cur_m++;
// 	if(cur_m==MUSICS_NUMBER)cur_m=0;

	remSnd *currentMusicFile = global_Music[ cur_m ];

	if ( currentMusicFile != nullptr ) {
		currentMusicFile->Stop();
		currentMusicFile->Play();
	}
}

void PlayWavFile( const std::string &fname, tka pos ) //=tka(-999,-999))
{
    
	static int cursnd=0;

	float sx=0,sy=0,sz=0;
	//if(!MyConf.sound_val)return;
	if(pos.x!=-999||pos.y!=-999)
		if(CurPlay.Exists(fname))return;
	std::string fn("Sound//");
	fn+=fname;
	fn+=".WAV";
	
	CurPlay.AddEltoBeg(fname);


	if(pos.x!=-999||pos.y!=-999)
	{
		if(SCALE<2 || !IsHere(pos,SOUND_HERE))return;
	
		sx=((pos.x-curpos.x)*SCALE)*0.01f;
		sy=((curpos.y-pos.y)*SCALE)*0.01f;
		sz=2.0f+30.0f/SCALE;
	}
	
	
	remSnd *currentSound = global_Snd3D[ cursnd ];
	::jmsf::Should::neverBeNull( currentSound );

	if ( currentSound != nullptr ) {

		currentSound->Stop();
		currentSound->Close();
	
		if ( currentSound->Open( fn, false, true ) ) {
			currentSound->Move( sx, sy, sz );
			currentSound->Play();
			cursnd += 1;

			if ( cursnd == SOUNDS_NUMBER ) {
				cursnd = 0;
			}
		}//else MessageBeep(0xFFFFFFFF);
	}
}

void SetEffectsVolume(float v)
{
	for(int i=0;i<SOUNDS_NUMBER;i++) {
		// JMFSC: transfering to Audiere
//		alSourcef(Snd3D[i].mSourceID, AL_GAIN, v);
	}
}

void SetMusucVolume(float v)
{
	for(int i=0;i<SOUNDS_NUMBER;i++) {
		// JMSFC: transfering to Audiere
//		alSourcef(Music[i].mSourceID, AL_GAIN, v);
	}
}
