/*
 *  sqc_sound.h
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SQC_SOUND_H_INCLUDED
#define SQC_SOUND_H_INCLUDED

#include "sqc/sqc_defs.h"
#include "sqc/sqc_data_stream.h"

NAMESPACE_SQC

/// sound sample, short sound
class sqc_sound_sample : public sqc_noncopyable {
public:
	virtual ~sqc_sound_sample() {}
	
	/// play sample
	virtual void play(  ) = 0;
    /// stop sample
    virtual void stop( ) = 0;
};
typedef std::tr1::shared_ptr<sqc_sound_sample> sqc_sound_sample_ptr;


/// music player ( play music )
class sqc_music_player : public sqc_noncopyable {
public:
	virtual ~sqc_music_player() {}
	/// set stream ( file )
	virtual bool open( const sqc_string& file ) = 0;
	///  play current stream ( restart if already played )
	virtual void play( bool loop=true ) = 0;
    /// stop play
    virtual void stop() = 0;
	/// stream now is playing
	virtual bool is_playing() = 0;
	/// pause stream
	virtual void pause() = 0 ;
	/// resume playing
	virtual void resume() = 0;
};

/// sound server ( manage sounds )
class sqc_sound_server : public sqc_noncopyable {
public:
    sqc_sound_server();
	virtual ~sqc_sound_server() { }
	/// load sound sample
	virtual sqc_sound_sample_ptr load_sample( const sqc_string& file ) = 0;
	/// get music interface
	virtual sqc_music_player& music() = 0;
    //  enable sound
    void set_sound_enabled( bool sounds );
    bool sound_enabled() const { return m_sound_enabled;}
    /// helpers
    void play_music( const char* filename, bool loop = true );
    void play_sample( const char* filename );
protected:
private:
    bool    m_sound_enabled;
};
typedef std::tr1::shared_ptr<sqc_sound_server> sqc_sound_server_ptr;
extern sqc_sound_server_ptr sqc_create_stub_sound_server();

END_NAMESPACE_SQC


#endif /*SQC_SOUND_H_INCLUDED*/