#include "TimeFunctions.h"

#include <winternl.h>

#include "external_source_antiwarning.h"

static HINSTANCE hNtdll = NULL;
typedef BOOL (NTAPI *tRtlTimeToSecondsSince1970)(PLARGE_INTEGER Time, PULONG ElapsedSeconds);
tRtlTimeToSecondsSince1970 RtlTimeToSeconds;

void loadNtDll() {
    if( RtlTimeToSeconds == NULL ) {
        if( hNtdll != NULL ) {
             RtlTimeToSeconds = (tRtlTimeToSecondsSince1970 )GetProcAddress(hNtdll, "RtlTimeToSecondsSince1970");
	    }
        else {
            hNtdll = LoadLibraryA("ntdll.dll");
            if( hNtdll != NULL ) {
                RtlTimeToSeconds = (tRtlTimeToSecondsSince1970 )GetProcAddress(hNtdll, "RtlTimeToSecondsSince1970");
            }
        }
    }
}

ULONG ConvertFileTimeToSeconds( const FILETIME &ft ) {
	loadNtDll();

    _LARGE_INTEGER ftLI  = {};
    ULONG fileTimeInSeconds = 0;

    ftLI.HighPart = ft.dwHighDateTime;
    ftLI.LowPart = ft.dwLowDateTime;
    RtlTimeToSeconds( &ftLI, &fileTimeInSeconds );    
    return fileTimeInSeconds;
}

ULONG GetLocalTimeInSeconds() {
	loadNtDll();

    ULONG nowLocalTimeInSeconds = 0; 
    _LARGE_INTEGER nowLocalTimeLI = {};
    SYSTEMTIME localTimeST = {};
    FILETIME localTimeFT = {};

    ::GetLocalTime( &localTimeST );
    ::SystemTimeToFileTime( &localTimeST, &localTimeFT );
    nowLocalTimeLI.HighPart = localTimeFT.dwHighDateTime;
    nowLocalTimeLI.LowPart = localTimeFT.dwLowDateTime;
    RtlTimeToSeconds( &nowLocalTimeLI, &nowLocalTimeInSeconds );

    return nowLocalTimeInSeconds;
}
