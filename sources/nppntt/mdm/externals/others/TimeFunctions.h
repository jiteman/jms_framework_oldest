#pragma once

#include "external_header_antiwarning.h"

#include "temporary_windows_include.h"


ULONG ConvertFileTimeToSeconds( const FILETIME &ft );
ULONG GetLocalTimeInSeconds();
