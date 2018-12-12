#include "abstractCheckMatchVoiceSMS.h"

#include "external_source_antiwarning.h"

extern ULONG ConvertFileTimeToSeconds( const FILETIME &ft );

bool isServiceFileWithinTimeRangeOfVoiceFile( const FileDescriptorData &voiceFile, const FileDescriptorData &smsFile ) {
    //if( voiceFile.baseStation != smsFile.baseStation )

    // First file time is later than second file time.
    if( ::CompareFileTime( &smsFile.creationTimeIni, &voiceFile.creationTimeIni ) == 1 )
        return false;

    ULONG smsFileTimeInSeconds = ConvertFileTimeToSeconds( smsFile.creationTimeIni );
    ULONG voiceFileTimeInSeconds = ConvertFileTimeToSeconds( voiceFile.creationTimeIni );
    __int64 elaps = static_cast<__int64>(voiceFileTimeInSeconds - smsFileTimeInSeconds);

    if( (elaps <= 1000) && (elaps >= 0) )
        return true;
    else
        return false;
}
