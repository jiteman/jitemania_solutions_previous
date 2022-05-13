#include "remSnd.h"

#include "Sound.h"

#include "vorbis/codec.h"

#include "AL/alc.h"

// #include "AL/alu.h"
#include "AL/alut.h"

#include <map>
#include <string>
#include <sstream>


#include "include_Windows.h"

//using namespace std;

// Defines
#define NUM_OF_DYNBUF	2		// num buffers in queue
#define DYNBUF_SIZE		10024	// Buffer size
#define ERRMSG(Msg) MessageBox(NULL, Msg, "Error", MB_OK | MB_ICONEXCLAMATION)

// Typedefs
typedef struct
{
	unsigned int	ID;
	std::string		Filename;
	unsigned int	Rate;
	unsigned int	Format;
} SndInfo;

typedef std::map<ALuint, SndInfo> TBuf;

// Vars
TBuf		Buffers;
ALCdevice	*pDevice;
ALCcontext	*pContext;

std::string ExtractFileExt(const std::string &Filename)
{
    if (Filename.size() == 0) return "";

    int i = Filename.size();
    std::string buf;
    while((Filename[i] != '.') && (i > 0))
    {
        buf = Filename[i--] + buf;
    }
    //_strupr((char *)buf.c_str());
    return buf;
}

//-----------------------------------------------------------
//    Standalone OpenAL function implementation
//-----------------------------------------------------------

ALboolean CheckALCError()
{
	ALenum ErrCode;
	std::string Err = "ALC error: ";
	if ((ErrCode = alcGetError(pDevice)) != ALC_NO_ERROR)
	{
		Err += (char *)alcGetString(pDevice, ErrCode);
		ERRMSG(Err.data());
		return AL_FALSE;
	}
	return AL_TRUE;
}

ALboolean CheckALError()
{
	ALenum ErrCode;
	std::string Err = "OpenAL error: ";
	if ((ErrCode = alGetError()) != AL_NO_ERROR)
	{
		Err += (char *)alGetString(ErrCode);
		//ERRMSG(Err.data());
		return AL_FALSE;
	}
	return AL_TRUE;
}

bool global_initializeSoundSubsystem()
{

	// Position of the Listener.
	ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };

	// Velocity of the Listener.
	ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };

	// Orientation of the Listener. (first 3 elements are "at", second 3 are "up")
	// Also note that these should be units of '1'.
	ALfloat ListenerOri[] = { 0.0, 0.0, -1.0,  0.0, 1.0, 0.0 };

	// Open default sound device
	pDevice = alcOpenDevice(NULL);
	// Check for errors
	if (!pDevice)
	{
		ERRMSG("Default sound device not present");
		return false;
	}
	// Creating rendering context
	pContext = alcCreateContext(pDevice, NULL);
	if (!CheckALCError()) return false;

	alcMakeContextCurrent(pContext);

	// Set listener properties
    alListenerfv(AL_POSITION,    ListenerPos);
    alListenerfv(AL_VELOCITY,    ListenerVel);
    alListenerfv(AL_ORIENTATION, ListenerOri);

    ::InitMusic();
    ::InitSound();

	return true;
}

void global_uninitializeSoundSubsystem() {
	::ReleaseSound();
	::ReleaseMusic();

	// Clear all buffers and sources
	for (TBuf::iterator i = Buffers.begin(); i != Buffers.end(); i++)
		alDeleteBuffers(1, &i->second.ID);
	// Shut down context
	alcMakeContextCurrent(NULL);
	// Destroy context
	alcDestroyContext(pContext);
	// Close sound device
	alcCloseDevice(pDevice);
}

std::string GetSndInfo()
{
	std::ostringstream SOut;
	SOut << "ALC info: \n";
	SOut << "DEFAULT_DEVICE_SPECIFIER: " << (char *)alcGetString(pDevice, ALC_DEFAULT_DEVICE_SPECIFIER) << '\n';
	SOut << "DEVICE_SPECIFIER: " << (char *)alcGetString(pDevice, ALC_DEVICE_SPECIFIER) << '\n';
	SOut << "EXTENSIONS: " << (char *)alcGetString(pDevice, ALC_EXTENSIONS) << '\n' << '\n';
	SOut << "AL info: \n";
	SOut << "VERSION: " << (char *)alGetString(AL_VERSION) << '\n';
	SOut << "RENDERER: " << (char *)alGetString(AL_RENDERER) << '\n';
	SOut << "VENDOR: " << (char *)alGetString(AL_VENDOR) << '\n';
	SOut << "EXTENSIONS: " << (char *)alGetString(AL_EXTENSIONS) << '\n' << std::ends;
	return SOut.str();
}

//-----------------------------------------------------------
//    ov_callback specific functions
//-----------------------------------------------------------

size_t ReadOgg(void *ptr, size_t size, size_t nmemb, void *datasource)
{
	std::istream *File = reinterpret_cast<std::istream*>(datasource);
	File->read((char *)ptr, size * nmemb);
	return File->gcount();
}

int SeekOgg(void *datasource, ogg_int64_t offset, int whence)
{
	std::istream *File = reinterpret_cast<std::istream*>(datasource);
	std::ios_base::seekdir Dir;
	File->clear();
	switch (whence)
	{
		case SEEK_SET: Dir = std::ios::beg;  break;
		case SEEK_CUR: Dir = std::ios::cur;  break;
		case SEEK_END: Dir = std::ios::end;  break;
		default: return -1;
	}
	File->seekg((std::streamoff)offset, Dir);
	return (File->fail() ? -1 : 0);
}

long TellOgg(void *datasource)
{
	std::istream *File = reinterpret_cast<std::istream*>(datasource);
	return File->tellg();
}

int CloseOgg(void * /*datasource*/)
{
	return 0;
}

//-----------------------------------------------------------
//    Sound class
//-----------------------------------------------------------

remSnd::remSnd() {
	for (int i = 0; i < 3; i++) {
		mPos[i] = mVel[i] = 0.0f;
	}

	mInfo		= NULL;
	mVF			= NULL;
	mComment	= NULL;
}

remSnd::~remSnd()
{}

bool remSnd::Open( const std::string &Filename, const bool Looped, const bool Streamed ) {
	// Check file existance
	std::ifstream a(Filename.c_str());
	if (!a.is_open()) return false;
	a.close();

	mLooped = Looped;

	// Create source
	alGenSources(1, &mSourceID);

	if (!CheckALError()) return false;

	alSourcef(mSourceID, AL_PITCH, 1.0f);
	alSourcef(mSourceID, AL_GAIN, 1.0f);
	alSourcefv(mSourceID, AL_POSITION, mPos);
	alSourcefv(mSourceID, AL_VELOCITY, mVel);
	alSourcei(mSourceID, AL_LOOPING, mLooped);

	// Extract ext
	std::string Ext = ExtractFileExt(Filename).data();
	if (Ext == "WAV") return LoadWavFile(Filename);
	if (Ext == "OGG")
	{
		mStreamed = Streamed;
		return LoadOggFile(Filename, Streamed);
	}
	return false;
}

bool remSnd::IsStreamed() {
	return mStreamed;
}

bool remSnd::LoadWavFile( const std::string &Filename ) {
	SndInfo		buffer;
	ALenum		format;
	ALvoid		*data;
	ALsizei		size;
	ALsizei		freq;
	ALboolean	loop;
	ALuint		BufID = 0;

	// Fill buffer struct
	buffer.Filename = Filename;
	// Check for existance of sound
	for (TBuf::iterator i = Buffers.begin(); i != Buffers.end(); i++)
	{
		if (i->second.Filename == Filename) BufID = i->first;
	}

	// If Such buffer not exist yet
	if (!BufID)
	{
		// Generate buffers
		alGenBuffers(1, &buffer.ID);
		if (!CheckALError()) return false;
		// Load wav data
		alutLoadWAVFile((ALbyte *)Filename.data(), &format, &data, &size, &freq, &loop);
		if (!CheckALError()) return false;

		buffer.Format			= format;
		buffer.Rate				= freq;
		// Fill buffer
		alBufferData(buffer.ID, format, data, size, freq);
		if (!CheckALError()) return false;
		// Unload wav
		alutUnloadWAV(format, data, size, freq);
		if (!CheckALError()) return false;

		Buffers[buffer.ID] = buffer;
	}
	else
		buffer = Buffers[BufID];

	alSourcei (mSourceID, AL_BUFFER,	buffer.ID);

	// Place buffer to Buffers map
	return true;
}

bool remSnd::LoadOggFile( const std::string &Filename, const bool Streamed ) {
	int				i, DynBuffs = 1, BlockSize;
	// OAL specific
	SndInfo			buffer;
	ALuint			BufID = 0;
	// OggVorbis specific structures
	ov_callbacks	cb;

	// Fill cb struct
	cb.close_func	= CloseOgg;
	cb.read_func	= ReadOgg;
	cb.seek_func	= SeekOgg;
	cb.tell_func	= TellOgg;

	// Create OggVorbis_File struct
	mVF = new OggVorbis_File;

	// Open Ogg file
	OggFile.open(Filename.c_str(), std::ios_base::in | std::ios_base::binary);

	// Generate local buffers
	if ( ov_open_callbacks( &OggFile, mVF, NULL, -1, cb ) < 0 ) {
		// This is not ogg bitstream. Return
		return false;
	}

	// Check for existance of sound
	if ( !Streamed ) 	{
		for ( TBuf::iterator buffer_iterator = Buffers.begin(); buffer_iterator != Buffers.end(); buffer_iterator++ ) {
			if ( buffer_iterator->second.Filename == Filename ) {
				BufID = buffer_iterator->first;
			}
		}

		BlockSize = ov_pcm_total( mVF, -1 ) * 4;
	} else {
		BlockSize	= DYNBUF_SIZE;
		DynBuffs	= NUM_OF_DYNBUF;
		alSourcei( mSourceID, AL_LOOPING, AL_FALSE );
	}

	// Return vorbis_comment and vorbis_info structures
	mComment = ov_comment( mVF, -1 );
	mInfo = ov_info( mVF, -1 );

	// Fill buffer infos
	buffer.Rate = mInfo->rate;
	buffer.Filename	= Filename;
	buffer.Format = mInfo->channels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;

	// Fill buffers with data each block by DYNBUF_SIZE bytes
	if ( Streamed || !BufID ) {
		for ( i = 0; i < DynBuffs; i++ ) {
			// Create buffers
			alGenBuffers( 1, &buffer.ID );

			if ( !CheckALError() ) {
				return false;
			}

			Buffers[ buffer.ID ] = buffer;
			// Read amount (DYNBUF_SIZE) data into each buffer
			ReadOggBlock( buffer.ID, BlockSize );

			if ( !CheckALError() ) {
				return false;
			}

			if ( Streamed ) {// Place buffer to queue
				alSourceQueueBuffers( mSourceID, 1, &buffer.ID );
				if ( !CheckALError() ) {
					return false;
				}
			} else {
				alSourcei( mSourceID, AL_BUFFER, buffer.ID );
			}
		}
	} else {
		alSourcei( mSourceID, AL_BUFFER, Buffers[ BufID ].ID );
	}

	return true;
}

bool remSnd::ReadOggBlock( ALuint BufID, size_t const Size ) {
	if ( Size < 1 ) {
		return false;
	}

	char *PCM = new char[ Size ];
	size_t TotalRet = 0;
	long ret = 0;

	// Read loop
	while ( TotalRet < Size ) {
		int	current_section = 0;
		ret = ov_read( mVF, PCM + TotalRet, Size - TotalRet, 0, 2, 1, &current_section );

		// if end of file or read limit exceeded
		if ( ret == 0 ) {
			break;
		} else if ( ret < 0 ) {		// Error in bitstream
			//
		} else {
			TotalRet += ret;
		}
	}

	if ( TotalRet > 0 ) {
		alBufferData( BufID, Buffers[ BufID ].Format, ( void * )PCM, TotalRet, Buffers[ BufID ].Rate );
		CheckALError();
	}

	delete[] PCM;

	return ret > 0;
}

void remSnd::Play() {
	alSourcePlay( mSourceID );
}

void remSnd::Close() {
	alSourceStop( mSourceID );

	if ( alIsSource( mSourceID ) ) {
		alDeleteSources( 1, &mSourceID );
	}

	if ( !mVF ) {
		ov_clear( mVF );
		delete mVF;
	}
}

void remSnd::Update() {
	if ( !mStreamed ) {
		return;
	}

	int Processed = 0;
	ALuint BufID;

	alGetSourcei( mSourceID, AL_BUFFERS_PROCESSED, &Processed );

	// We still have processed buffers
	while ( Processed-- ) {
		alSourceUnqueueBuffers( mSourceID, 1, &BufID );

		if ( !CheckALError() ) {
			return;
		}

		if ( ReadOggBlock( BufID, DYNBUF_SIZE ) != 0 ) {
			alSourceQueueBuffers( mSourceID, 1, &BufID );

			if ( !CheckALError() ) {
				return;
			}
		} else {
			ov_pcm_seek( mVF, 0 );
			alSourceQueueBuffers( mSourceID, 1, &BufID );

			if ( !CheckALError() ) {
				return;
			}

			if ( !mLooped ) {
				Stop();
			}
		}
	}
}

void remSnd::Stop() {
	alSourceStop( mSourceID );
}

void remSnd::Move( const float X, const float Y, const float Z ) {
	ALfloat Pos[ 3 ] = { X, Y, Z };
	alSourcefv( mSourceID, AL_POSITION, Pos );
}
