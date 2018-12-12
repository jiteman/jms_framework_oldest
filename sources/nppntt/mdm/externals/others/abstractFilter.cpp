#include "abstractFilter.h"
#include "TimeFunctions.h"

#include <sstream>
#include <direct.h>

#include "external_source_antiwarning.h"

FilterData *createFilter() {
    FilterData *filter = new FilterData;
    memset( filter, 0x00, sizeof( FilterData ) );
    return filter;
}

void deleteFilter( FilterData *filter ) {
    delete filter;
}

void changeFilter( const FilterData *filterIn, FilterData *filterOut ) {
    //filterOut = filterIn;
    memcpy( filterOut, filterIn, sizeof( FilterData ) );
}       

WORD convertStringToInt(const std::string str) {
    WORD result = 0;
    std::istringstream s_year(str);
    s_year >> result;
    return result;
}

FILETIME stringToFILETIME( const std::string dateTime ) {
    FILETIME ft = {};
    if ( dateTime != "" ) {
        // parse string : 16.06.2010 21:01:23
        std::string workString = dateTime;
        INT tokenPosition = workString.find(".");

        std::string str_day ( workString.begin(), workString.begin() + tokenPosition );
        workString.erase( workString.begin(), workString.begin() + tokenPosition + 1 );

        tokenPosition = workString.find(".");
        std::string str_month ( workString.begin(), workString.begin() + tokenPosition );
        workString.erase( workString.begin(), workString.begin() + tokenPosition + 1 );

        tokenPosition = workString.find(" ");
        std::string str_year ( workString.begin(), workString.begin() + tokenPosition );
        workString.erase( workString.begin(), workString.begin() + tokenPosition + 1 );

        tokenPosition = workString.find(":");
        std::string str_hour ( workString.begin(), workString.begin() + tokenPosition );
        workString.erase( workString.begin(), workString.begin() + tokenPosition + 1 );

        tokenPosition = workString.find(":");
        std::string str_minute ( workString.begin(), workString.begin() + tokenPosition );
        workString.erase( workString.begin(), workString.begin() + tokenPosition + 1 );

        std::string str_second ( workString.begin(), workString.end() );
        workString.erase( workString.begin(), workString.end() );

        WORD year = convertStringToInt(str_year); 
        WORD month = convertStringToInt(str_month);
        WORD day = convertStringToInt(str_day);
        WORD hour = convertStringToInt(str_hour);
        WORD minute = convertStringToInt(str_minute);
        WORD second = convertStringToInt(str_second);
        WORD millisecond = 0;

        //DateTime(year, month, day, hour, minute, second, millisecond, ft);
        SYSTEMTIME st = { year, month, 0, day, hour, minute, second, millisecond };
        ::SystemTimeToFileTime(&st, &ft);
    }
 
    return ft;
}

bool isDecipheredFile( const FileDescriptorData *file, const FilterData *filter ) {
    if( filter->isSetup ) {
        // check network
        if( filter->networkCounter > 0 ) {
            BOOL networkCheck = FALSE;
            for(unsigned int i = 0; i < filter->networkCounter; i++) {
                std::string network = filter->newtworkList[i];
                if (file->network == network) networkCheck = TRUE;
            }
            if( !networkCheck ) 
				return false;
        }
        // check BS
        if( filter->baseStationCounter > 0 ) {
            BOOL BSCheck = FALSE;
            for (unsigned int i = 0; i < filter->baseStationCounter; i++) {
                std::string bs = filter->BSList[i];
                if (file->baseStation == bs) BSCheck = TRUE;
            }
            if (!BSCheck) 
				return false;
        }
        // check period
        if( filter->periodActive ) {
            std::string strPeriodMin = filter->periodMin, strPeriodMax = filter->periodMax;
            FILETIME periodMin = stringToFILETIME(strPeriodMin);
            FILETIME periodMax = stringToFILETIME(strPeriodMax);

            // if file->time < period min return false
            // if file->time > period max return false
            // First file time is earlier than second file time.
            if( ::CompareFileTime( &file->creationTime, &periodMin ) == -1 )
                return false;
            // First file time is later than second file time
            if( ::CompareFileTime( &file->creationTime, &periodMax ) == 1 )
                return false;
        }
    }
    return true;
}

bool isDeletedFile( const FileDescriptorData *file, const FilterData *filter ) {

	const ULONG secondsInHour = 60 * 60;

	if( filter->isSetup ) {
        ULONG nowLocalTimeInHours = GetLocalTimeInSeconds() / secondsInHour;
        ULONG addFileTimeInHours = ConvertFileTimeToSeconds( file->addFileTime ) / secondsInHour;
        ULONG filterInHours = filter->maxLiveTimeInHours;

        //if( (addFileTimeInSeconds + filterInSeconds) > nowLocalTimeInSeconds ) 
		if( (nowLocalTimeInHours - addFileTimeInHours) >= filterInHours )
            return true;
        else
            return false;
    }
    else
        return false;        
}

bool deleteFile( FileDescriptorData *file, AppliedData *data ) {
    deleteAppliedData( data );

	if( file!= NULL ) {
		std::string extension = "";
		if (file->type == _FTC) extension = ".FTC";
		else if (file->type == _SDC) extension = ".SDC";

		std::string fileName = file->longPath + file->fileName + extension;

		// TODO: Добавить флаг в приложении для неудаления файлов
		// delete SDC or FTC
#ifndef _NOT_DELETE_FILES
		::DeleteFileA(fileName.c_str());
#endif

		// delete his INI file
		extension = ".INI";
		fileName = file->longPath + file->fileName + extension;

#ifndef _NOT_DELETE_FILES
		::DeleteFileA(fileName.c_str());
#endif

		// if folder empty then delete
		if ( !_rmdir(file->longPath.c_str()) ) {
			// empty
			std::string folder = file->longPath;
			INT tokenPosition = 0;
			if( (tokenPosition = folder.find("\\")) != folder.npos ) {
				std::string drive (folder.begin(), folder.begin() + tokenPosition);
				folder.erase( folder.begin(), folder.begin() + tokenPosition + 1 );

				if( (tokenPosition = folder.find("\\")) != folder.npos ) {
                    std::string shareDir (folder.begin(), folder.begin() + tokenPosition);
 					folder.erase( folder.begin(), folder.begin() + tokenPosition + 1 );

                    if( (tokenPosition = folder.find("\\")) != folder.npos ) {
                        std::string dateDir (folder.begin(), folder.begin() + tokenPosition);
                        folder.erase( folder.begin(), folder.begin() + tokenPosition + 1 );

                        if( (tokenPosition = folder.find("\\")) != folder.npos ) {
                            std::string timeDir (folder.begin(), folder.begin() + tokenPosition);
                            folder.erase( folder.begin(), folder.begin() + tokenPosition + 1 );

                            std::string removeDir = drive + "\\" + shareDir + "\\" + dateDir + "\\" + timeDir + "\\";
                            _rmdir( removeDir.c_str() );

                            removeDir = drive + "\\" + shareDir + "\\" + dateDir + "\\";
                            _rmdir( removeDir.c_str() );
                        }
                        else {
                            std::string removeDir = drive + "\\" + shareDir + "\\" + dateDir + "\\";    
                            _rmdir( removeDir.c_str() );
                        }
                    } // dateDir
				} // shareDir
			} // drive
		}
	}
	else 
		return false;
    
    return true;
}

bool fillFileDescriptor( FileDescriptorData *file ) {
    file->appenderWorkFolder = "";
    file->baseStation = "";
    file->donePercent = 0;
    file->fileName = "";
    file->isSMS = FALSE;
    file->longPath = "";
    file->network = "";
    file->R1 = file->R2 = file->R3 = 0;
    file->temporaryNumber = "";
    file->type = _INVALID;

    file->addFileTime.dwHighDateTime = 0;     file->addFileTime.dwLowDateTime = 0;
    file->creationTime.dwHighDateTime = 0;    file->creationTime.dwLowDateTime = 0;
    file->creationTimeIni.dwHighDateTime = 0; file->creationTimeIni.dwLowDateTime = 0;
	file->networkAndBaseStationId = ~( unsigned int( 0 ) );

    return true;
}
