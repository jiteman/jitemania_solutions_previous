#include "remSnd.h"

#include "Sound.h"

#include "osl/libvorbis/vorbis/codec.h"

#include "jmsf/stdal/stdal_stl.h"

#include "temporary_windows_include.h"


// Defines
// #define NUM_OF_DYNBUF	2		// num buffers in queue
// #define DYNBUF_SIZE		10024	// Buffer size
#define ERRMSG(Msg) MessageBox(NULL, Msg, L"Error", MB_OK | MB_ICONEXCLAMATION)

// Typedefs
struct SndInfo {

	unsigned int	ID;
	std::string		Filename;
	unsigned int	Rate;
	unsigned int	Format;

};

jmsf::Pointer< audiere::AudioDevicePtr > device;


bool global_initializeSoundSubsystem() {
	device = jmsf::Pointer< audiere::AudioDevicePtr >::createUnique( new audiere::AudioDevicePtr( audiere::OpenDevice() ) );
	
	// Check for errors
	if ( device.isEmpty() ) {
		ERRMSG( L"Default sound device not present" );
		return false;
	}

	for ( size_t index = 0; index < SOUNDS_NUMBER; index += 1 ) {
		global_Snd3D[ index ] = new remSnd;
	}

// 	for ( int i = 0; i < SOUNDS_NUMBER * 2; i++ ) {
// 		PlayWavFile( std::string( "empty" ) );
// 	}

//	InitMusic();
	return true;
}

void global_uninitializeSoundSubsystem() {
	for ( size_t index = 0; index < SOUNDS_NUMBER; index += 1 ) {
		delete global_Snd3D[ index ];
		global_Snd3D[ index ] = nullptr;
	}

	for ( size_t index =0; index < MUSICS_NUMBER; index += 1 ) {
		delete global_Music[ index ];
		global_Music[ index ] = nullptr;
	}

	device = ::jmsf::Pointer< audiere::AudioDevicePtr >::createEmpty();
}

remSnd::remSnd()
{}

remSnd::~remSnd()
{}

bool remSnd::Open( const std::string &Filename, const bool Looped, const bool Streamed ) {
	// Check file existance
	{
		std::ifstream audioFile( Filename );

		if ( !audioFile.is_open() ) {
			return false;
		}

		audioFile.close();
	}

	mStreamed = Streamed;
	mLooped = Looped;

	_audiereOutputStream = jmsf::Pointer< audiere::OutputStreamPtr >::createUnique( new audiere::OutputStreamPtr( audiere::OpenSound( *device, Filename.c_str(), Streamed ) ) );

	return *_audiereOutputStream;
}

bool remSnd::IsStreamed() {
	return mStreamed;
}

void remSnd::Play() {
	if ( isEmpty().not() ) {
		( *_audiereOutputStream )->play();
	}
}

void remSnd::Close() {
	_audiereOutputStream = ::jmsf::Pointer< audiere::OutputStreamPtr >::createEmpty();
}

void remSnd::Update()
{}

void remSnd::Stop() {
	if ( isEmpty().not() ) {
		( *_audiereOutputStream )->stop();
	}
}

::jmsf::Boolean remSnd::isEmpty() const throw() {
	return _audiereOutputStream.isEmpty();
}

void remSnd::Move( const float X, const float Y, const float Z ) {
// 	ALfloat Pos[3] = { X, Y, Z };
// 	alSourcefv(mSourceID, AL_POSITION, Pos);
}
