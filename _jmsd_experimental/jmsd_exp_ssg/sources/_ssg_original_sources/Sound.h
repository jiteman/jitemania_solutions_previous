#pragma once


#include "myfuns.h"
#include "st.h"

#include "jmsf/stdal/stdal_stl.h"

class remSnd;

#define SOUNDS_NUMBER 30
#define SOUND_HERE 100
#define MUSICS_NUMBER 1


extern remSnd *global_Snd3D[ SOUNDS_NUMBER ];
extern remSnd *global_Music[ MUSICS_NUMBER ];
extern st< std::string > CurPlay;

void PlayWavFile( const std::string &fname, tka pos = tka( -999, -999 ) );
void PlayMusic();
void InitMusic();

void SetEffectsVolume(float v);
void SetMusucVolume(float v);

int operator==( const std::string &s1, const std::string &s2 );
std::string operator+ (std::string& s1,std::string& s2);
