/*
 *  sqc_sound.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_sound.h"
#include "sqc/sqc_file_data_stream.h"
#include "sqc/sqc_file_api.h"

NAMESPACE_SQC


sqc_sound_server::sqc_sound_server() : m_sound_enabled(true) {
    
}

void sqc_sound_server::set_sound_enabled(bool enabled) {
    m_sound_enabled = enabled;
}

void sqc_sound_server::play_music( const char* filename, bool loop ) {
    if (music().open(filename)) {
        music().play(loop);
    }
}

void sqc_sound_server::play_sample( const char* filename ) {
    sqc_sound_sample_ptr sample = load_sample(filename);
    if (sample) {
        sample->play();
    }
}




class stub_sqc_music_player : public sqc_music_player {
private:
	bool	m_playing;
public:
	stub_sqc_music_player() {
		m_playing = false;
	}
	/// set stream ( file )
	virtual bool open( const sqc_string& file ) {
		return false;
	}
	///  play current stream ( restart if already played )
	virtual void play( bool loop ) {
		m_playing = true;
	}
    /// stop
    virtual void stop() {
        
    }
	/// stream now is playing
	virtual bool is_playing() {
		return m_playing;
	}
	/// pause stream
	virtual void pause() {
		m_playing = false;
	}
	/// resume playing
	virtual void resume() {
		m_playing = true;
	}
};

class stub_sqc_sound_server : public sqc_sound_server {
private:
	stub_sqc_music_player	m_music;
public:
	virtual sqc_sound_sample_ptr load_sample( const sqc_string& file ) {
		return sqc_sound_sample_ptr();
	}
	virtual sqc_music_player& music() {
		return m_music;
	}
};


sqc_sound_server_ptr sqc_create_stub_sound_server() {
	return sqc_sound_server_ptr( new stub_sqc_sound_server() );
}


END_NAMESPACE_SQC