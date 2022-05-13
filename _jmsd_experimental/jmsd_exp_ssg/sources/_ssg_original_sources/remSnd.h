#pragma once


#include "osl/audiere/audiere.h"
#include "osl/libvorbis/vorbis/vorbisfile.h"

#include "jmsf/Pointer.hpp"

#include "jmsf/Boolean.h"


//#define NUM_OF_DYNBUF	2		// num buffers in queue


class remSnd {

public:
//	ALfloat mVel[3];
//	ALfloat mPos[3];
	bool mLooped;
	
	// Functions
	bool Open( const std::string &Filename, bool Looped, bool Streamed );
	bool IsStreamed();
	void Play();
	void Close();
	void Update();
	void Move( float X, float Y, float Z );
	void Stop();

	::jmsf::Boolean isEmpty() const throw();

	// Construction/destruction
	remSnd();
	virtual ~remSnd();

	// OAL specific vars
//	ALuint mSourceID;
private:
	jmsf::Pointer< audiere::OutputStreamPtr > _audiereOutputStream;

	bool mStreamed;

	// Functions
//	bool ReadOggBlock( ALuint BufID, size_t Size );
	bool LoadOggFile( const std::string &Filename, bool Streamed );
	bool LoadWavFile( const std::string &Filename );

};

// Public standalone functions
extern std::string GetSndInfo();
extern bool global_initializeSoundSubsystem();
extern void global_uninitializeSoundSubsystem();
