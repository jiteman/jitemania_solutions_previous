#pragma once


#include "al.h"
#include <fstream>
#include "vorbis/vorbisfile.h"


#define NUM_OF_DYNBUF	2		// num buffers in queue


class OLD_remSnd  
{
public:
	ALfloat mVel[3];
	ALfloat mPos[3];
	bool mLooped;
	
	// Functions
	bool Open( const std::string &Filename, bool Looped, bool Streamed );
	bool IsStreamed();
	void Play();
	void Close();
	void Update();
	void Move( float X, float Y, float Z );
	void Stop();

	// Construction/destruction
	OLD_remSnd();
	virtual ~OLD_remSnd();

	// OAL specific vars
	ALuint mSourceID;
private:
	// vorbisfile specific vars
	OggVorbis_File *mVF;
	vorbis_comment *mComment;
	vorbis_info *mInfo;
	// Common vars
	std::ifstream OggFile;
	bool mStreamed;

	// Functions
	bool ReadOggBlock( ALuint BufID, size_t Size );
	bool LoadOggFile( const std::string &Filename, bool Streamed );
	bool LoadWavFile( const std::string &Filename );
};

// Public standalone functions
extern std::string GetSndInfo();
extern bool InitializeOpenAL();
extern void DestroyOpenAL();
