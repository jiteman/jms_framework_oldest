#pragma once

#include "abstractFileDescriptor.h"
#include "abstractKey.h"

#include "abstractEmulationDefines.h"

struct _decipherTimeLimit {
    int timeLimitInSeconds;
};

#ifdef _EMULATION_DECIPHER 
#include <hash_map>

struct _Keys {
    unsigned int R1;
    unsigned int R2;
    unsigned int R3;

    int sessionResult;
};
#endif

bool loadDecipherDll();
void unloadDecipherDll();

bool decipherInitialize();
bool decipherRelease();

bool decipherThisFile( FileDescriptorData *voiceFile, KeyData *key );
void decipherSetTimeLimit( const _decipherTimeLimit &timeLimit );
int decipherGetCurrentVoiceFileProgress();
