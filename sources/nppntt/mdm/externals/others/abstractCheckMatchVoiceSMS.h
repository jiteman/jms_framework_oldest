#pragma once

#include "abstractFileDescriptor.h"
#include "temporary_windows_include.h"


bool isServiceFileWithinTimeRangeOfVoiceFile( const FileDescriptorData &voiceFile, const FileDescriptorData &smsFile );
