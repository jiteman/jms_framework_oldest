#include "abstractStatistics.h"
#include "../../exceptions/exception_StatisticsError.h"
#include "jmsf/factory_TextObject.h"

#include <hash_map>

#include <direct.h>

#include "external_source_antiwarning.h"

static int decipherQueueCounter = 0;

#ifdef _DEBUG
//     static std::ofstream _logGlobalStatisticFile;
//     static std::ofstream _logAppenderStatisticFile;
//     static std::ofstream _logDecipherStatisticFile;
//     static std::ofstream _logDatabaseStatisticFile;
//     static std::ofstream _logDeleteStatFile;

// 	static std::ofstream _logDecipherQueueIn("_logDecipherQueueIn.log");
// 	static std::ofstream _logDecipherOk("_logDecipherOk.log");
// 	static std::ofstream _logDecipherBad("_logDecipherBad.log");
#endif


GlobalStatisticsData *createGlobalStatistics() {
#ifdef _DEBUG
//     DWORD currentThreadID = ::GetCurrentThreadId();
//     std::ostringstream o;
//     o << currentThreadID;
//     if( !_logGlobalStatisticFile.is_open() ) {
//         _mkdir("globalStatisticsLogs");
//         _logGlobalStatisticFile.open( "globalStatisticsLogs\\" + o.str() + "globalStat.log" );
//     }
//     
//     if( !_logGlobalStatisticFile.is_open() )
//         throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "CreateGlobalStat: already create" ) );
#endif

    GlobalStatisticsData *statistics = new GlobalStatisticsData;
    memset( statistics, 0x00, sizeof(GlobalStatisticsData) );
    return statistics;
}

void deleteGlobalStatistics( GlobalStatisticsData *globalStat ) {
#ifdef _DEBUG
//     if( _logGlobalStatisticFile.is_open() ) {
//         _logGlobalStatisticFile.flush();
//         _logGlobalStatisticFile.close();
//     }
#endif
    delete globalStat;
}

FileAppenderStatisticsData *createFileAppenderStatistics() {
#ifdef _DEBUG
//     DWORD currentThreadID = ::GetCurrentThreadId();
//     std::ostringstream o;
//     o << currentThreadID;
//     if( !_logAppenderStatisticFile.is_open() ) {
//         _mkdir( "appenderLogs" );
//         _logAppenderStatisticFile.open( "appenderLogs\\" + o.str() + "appenderStat.log" );
//     }
//     
//     if( !_logAppenderStatisticFile.is_open() )
//         throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "CreateAppenderStat: already create" ) );
#endif
    FileAppenderStatisticsData *statistics = new FileAppenderStatisticsData;
    return statistics;
}

void deleteFileAppenderStatistics( FileAppenderStatisticsData *statistics ) {
#ifdef _DEBUG   
//    if( _logAppenderStatisticFile.is_open() ) {
//         _logAppenderStatisticFile.flush();
//         _logAppenderStatisticFile.close();   
//    }
#endif
    delete statistics;
}

DecipherStatisticsData *createDecipherStatistics() {
#ifdef _DEBUG
//     DWORD currentThreadID = ::GetCurrentThreadId();
//     std::ostringstream o;
//     o << currentThreadID;
//     if( !_logDecipherStatisticFile.is_open() ) {
//         _mkdir( "decipherLogs" );
//         _logDecipherStatisticFile.open( "decipherLogs\\" + o.str() + "decipherStat.log" );
//     }
//     
//     if( !_logDecipherStatisticFile.is_open() )
//         throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "CreateDecipherStat: already create" ) );    
#endif
    DecipherStatisticsData *statistics = new DecipherStatisticsData;
    return statistics;
}

void deleteDecipherStatistics( DecipherStatisticsData *statistics ) {
#ifdef _DEBUG
//     if( _logDecipherStatisticFile.is_open() ) {
//         _logDecipherStatisticFile.flush();
//         _logDecipherStatisticFile.close();
//     }
#endif
    delete statistics;
}

DataBaseStatisticsData *createDataBaseStatistics() {
#ifdef _DEBUG
//     DWORD currentThreadID = ::GetCurrentThreadId();
//     std::ostringstream o;
//     o << currentThreadID;
//     if( !_logDatabaseStatisticFile.is_open() ) {
//         _mkdir("dataBaseLogs");
//         _logDatabaseStatisticFile.open( "dataBaseLogs\\" + o.str() + "databaseStat.log" );
//     }
//     if( !_logDatabaseStatisticFile.is_open() )
//         throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "CreateDataBaseStat: already create" ) );    
#endif
    DataBaseStatisticsData *statistics = new DataBaseStatisticsData;
    return statistics;
}

void deleteDataBaseStatistics( DataBaseStatisticsData *statistics ) {
#ifdef _DEBUG  
//     if( _logDatabaseStatisticFile.is_open() ) {
//         _logDatabaseStatisticFile.flush();
//         _logDatabaseStatisticFile.close();
//     }
#endif
    delete statistics;
}

DeleteFilesStatisticsData *createDeleteFilesStatistics() {
#ifdef _DEBUG
//     DWORD currentThreadID = ::GetCurrentThreadId();
//     std::ostringstream o;
//     o << currentThreadID;
//     if( !_logDeleteStatFile.is_open() ) {
//         _mkdir("deleteFilesLogs");
//         _logDeleteStatFile.open( "deleteFilesLogs\\" + o.str() + "deleteFileStat.log" );
//     }
//     if( !_logDeleteStatFile.is_open() )
//         throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "CreateDeleteFilesStat: already create" ) );    
#endif
    DeleteFilesStatisticsData *statistics = new DeleteFilesStatisticsData;
    return statistics;
}

void deleteDeleteFilesStatistics( DeleteFilesStatisticsData *statistics ) {
#ifdef _DEBUG
//     if( _logDeleteStatFile.is_open() ) {
//         _logDeleteStatFile.flush();
//         _logDeleteStatFile.close();
//     }
#endif
    delete statistics;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void updateGlobalStatistics(GlobalStatisticsData *globalStatistics, 
                            FileAppenderStatisticsData *appenderStat,
                            DecipherStatisticsData *decipherStat,
                            DataBaseStatisticsData *dataBaseStat,
                            DeleteFilesStatisticsData *deleteStat) {

    // Заполняем список БС из аппендера, т.к он видит все множество входящих файлов
    memset( globalStatistics, 0x00, sizeof(GlobalStatisticsData) );
    {
        ::std::list< DLL_appenderStatisticsCounters >::const_iterator appenderStatIterator;

        for( appenderStatIterator = appenderStat->statistics.begin(); appenderStatIterator != appenderStat->statistics.end(); ++appenderStatIterator ) 
        {
            if( (appenderStatIterator->bsName.length() < MAX_BS_NAME_LENGTH) && (appenderStatIterator->bsName != "") ) {
				strncpy(globalStatistics->bsStat[globalStatistics->baseStationCount].BSName,
                        appenderStatIterator->bsName.c_str(), 
                        appenderStatIterator->bsName.length());

                globalStatistics->bsStat[globalStatistics->baseStationCount].BSName[appenderStatIterator->bsName.length()] = '\0';
			}
            else {
				throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: BaseStation name incorrect" ) );    
            }

            globalStatistics->bsStat[globalStatistics->baseStationCount].appenderFoundFTC = appenderStatIterator->ftc_found;
            globalStatistics->bsStat[globalStatistics->baseStationCount].appenderFoundSDC = appenderStatIterator->sdc_found;

            if( globalStatistics->baseStationCount < MAX_BS_COUNT - 1)
                globalStatistics->baseStationCount ++;
            else
                break;
        }
    } 
    // Заполняем счетчики дешифратора
    {
        ::std::list< DLL_decipherCounters >::const_iterator decipherCountersIterator;    
        
        for( unsigned int i = 0; i < globalStatistics->baseStationCount; i++ ) 
        {
            std::string tmpBSName( globalStatistics->bsStat[i].BSName );
            
            for( decipherCountersIterator = decipherStat->counters.counters.begin(); 
                decipherCountersIterator != decipherStat->counters.counters.end(); 
                ++decipherCountersIterator ) 
            {     
                if( tmpBSName == decipherCountersIterator->bsName ) {
                    globalStatistics->bsStat[i].decipherInputFiles = decipherCountersIterator->inputFiles;
                    globalStatistics->bsStat[i].decipherDecipheredFiles = decipherCountersIterator->decipheredFiles;
                    globalStatistics->bsStat[i].decipherNotDecipheredFiles = decipherCountersIterator->notDecipheredFiles;
                    break;
                }
            }
        }
    }   
    // Заполним очередь дешифратора
    {
        ::std::list< DLL_decipherQueue >::const_iterator decipherQueueIterator;
        for( decipherQueueIterator = decipherStat->decipherQueue.decipherQueue.begin(); 
             decipherQueueIterator != decipherStat->decipherQueue.decipherQueue.end(); 
             ++decipherQueueIterator ) 
        {
            unsigned int currentBSCount = globalStatistics->decipherQueue.BS.BSCount;

            if( (decipherQueueIterator->bsName.length() < MAX_BS_NAME_LENGTH) && (decipherQueueIterator->bsName != "") ) {
				strncpy(globalStatistics->decipherQueue.BS.BSList[currentBSCount], 
                        decipherQueueIterator->bsName.c_str(),
                        decipherQueueIterator->bsName.length());
                globalStatistics->decipherQueue.BS.BSList[currentBSCount][decipherQueueIterator->bsName.length()] = '\0';
			}
            else {
				throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: BaseStation name incorrect" ) );
            }

            if( (decipherQueueIterator->fileName.length() < MAX_FILE_NAME_LENGTH) && (decipherQueueIterator->fileName != "") ) {
				strncpy(globalStatistics->decipherQueue.fileNames[currentBSCount], 
                        decipherQueueIterator->fileName.c_str(),
                        decipherQueueIterator->fileName.length());
                globalStatistics->decipherQueue.fileNames[currentBSCount][decipherQueueIterator->fileName.length()] = '\0';
			}
            else {    
				throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: file name incorrect" ) );
            }

            if( currentBSCount < MAX_BS_COUNT - 1)
                globalStatistics->decipherQueue.BS.BSCount ++;
            else                                                                              
                break;
        }
    }
    // Заполним текущий дешифруемый файл
    {
        if( (decipherStat->nowDecipherFile.nowDecipherBSName.length() < MAX_BS_NAME_LENGTH) /*&& (decipherStat->nowDecipherFile.nowDecipherBSName != "")*/ ) {
			strncpy(globalStatistics->nowDecipherFile.nowDecipherBSName, 
                    decipherStat->nowDecipherFile.nowDecipherBSName.c_str(),
                    decipherStat->nowDecipherFile.nowDecipherBSName.length());
            globalStatistics->nowDecipherFile.nowDecipherBSName[decipherStat->nowDecipherFile.nowDecipherBSName.length()] = '\0';
		}
        else {
			throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: BaseStation name incorrect" ) );
        }
        if( (decipherStat->nowDecipherFile.nowDecipherFile.length() < MAX_FILE_NAME_LENGTH) /*&& (decipherStat->nowDecipherFile.nowDecipherFile != "")*/ ) {
			strncpy(globalStatistics->nowDecipherFile.nowDecipherFile, 
                    decipherStat->nowDecipherFile.nowDecipherFile.c_str(),
                    decipherStat->nowDecipherFile.nowDecipherFile.length());
            globalStatistics->nowDecipherFile.nowDecipherFile[decipherStat->nowDecipherFile.nowDecipherFile.length()] = '\0';
		}
        else {
			throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: file name incorrect" ) );
        }
        globalStatistics->nowDecipherFile.nowDecipherFileDonePercent = decipherStat->nowDecipherFile.nowDecipherFileDonePercent;
    }
    // Заполним счетчики отправки в БД
    {
        ::std::list< DLL_dataBaseCounters >::const_iterator dataBaseCountersIterator;    

        for( unsigned int i = 0; i < globalStatistics->baseStationCount; i++ ) 
        {
            std::string tmpBSName( globalStatistics->bsStat[i].BSName );

            for( dataBaseCountersIterator = dataBaseStat->dataBaseCounters.begin(); 
                dataBaseCountersIterator != dataBaseStat->dataBaseCounters.end(); 
                ++dataBaseCountersIterator ) 
            {     
                if( tmpBSName == dataBaseCountersIterator->bsName ) {
                    globalStatistics->bsStat[i].databaseFTCSend = dataBaseCountersIterator->voice_send;
                    globalStatistics->bsStat[i].databaseSMSSend = dataBaseCountersIterator->sms_send;
					globalStatistics->bsStat[i].databaseSDCSend = dataBaseCountersIterator->sdc_send;
                    break;
                }
            }
        }
    }
    // Заполним счетчики удаления
    {
        ::std::list< DLL_deleteFilesCountes >::const_iterator deleteFilesIterator;    

        for( unsigned int i = 0; i < globalStatistics->baseStationCount; i++ ) 
        {
            std::string tmpBSName( globalStatistics->bsStat[i].BSName );

            for( deleteFilesIterator = deleteStat->deleteFilesCounters.begin(); 
                deleteFilesIterator != deleteStat->deleteFilesCounters.end(); 
                ++deleteFilesIterator ) 
            {     
                if( tmpBSName == deleteFilesIterator->bsName ) {
                    globalStatistics->bsStat[i].deleterFTCFiles = deleteFilesIterator->ftc_delete;
                    globalStatistics->bsStat[i].deleterSDCFiles = deleteFilesIterator->sdc_delete;
                    break;
                }
            }
        }
    }
}

void appendNewBStoAppenderStatistics( FileAppenderStatisticsData *appenderStat, const FileDescriptorData &file ) {
    DLL_appenderStatisticsCounters newBSCounter = {};

    newBSCounter.bsName = file.baseStation;
    if( file.type == _FTC ) newBSCounter.ftc_found = 1;
    else if( file.type == _SDC ) newBSCounter.sdc_found = 1;

    appenderStat->statistics.push_back(newBSCounter);
}

static std::hash_map< std::string, unsigned int > global_fileSourceMap;

// check BS in list. if found then update counter, else append new
void updateAppenderStatistics( FileAppenderStatisticsData *appenderStat, FileDescriptorData &file ) { // REFACTOR - to const reference
    
	if( file.baseStation == "" )
		throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: BaseStation incorrect" ) );

	if( file.network == "" )
		throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: Network incorrect" ) );

	if( file.fileName == "" )
		throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: file name incorrect" ) );

    if( appenderStat->statistics.empty() ) {
        appendNewBStoAppenderStatistics(appenderStat, file);
    } else {
        ::std::list< DLL_appenderStatisticsCounters >::iterator appenderStatIterator;

        for( appenderStatIterator = appenderStat->statistics.begin(); appenderStatIterator != appenderStat->statistics.end(); ++appenderStatIterator ) {
            if( appenderStatIterator->bsName == file.baseStation ) {
                if( file.type == _FTC ) appenderStatIterator->ftc_found ++;
                else if( file.type == _SDC ) appenderStatIterator->sdc_found ++;
                break;
            }
        }
        if( appenderStatIterator == appenderStat->statistics.end() ) {
            appendNewBStoAppenderStatistics(appenderStat, file);
        }
    }

	{
		const std::string fileSource = file.network + " " + file.baseStation;

		const std::hash_map< std::string, unsigned int >::const_iterator foundedFileSource =
			global_fileSourceMap.find( fileSource );

		if ( foundedFileSource == global_fileSourceMap.end() ) {
			file.networkAndBaseStationId = global_fileSourceMap.size(); // index for new network and base station pair is equal to previous quantity of elements [ 0 ; N - 1 ]
			global_fileSourceMap.insert( global_fileSourceMap.end(), std::make_pair( fileSource, file.networkAndBaseStationId ) );
		} else {
			file.networkAndBaseStationId = foundedFileSource->second;
		}
	}
}

void updateDecipherInputFiles(DecipherStatisticsData *decipherStat, const FileDescriptorData &file);

void updateDecipherNowDecipherFile( DecipherStatisticsData *decipherStat, const FileDescriptorData &file ) {
	updateDecipherInputFiles( decipherStat, file );
    
	if( file.baseStation == "" )
		throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: BaseStation incorrect" ) );

	if( file.network == "" )		
		throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: Network incorrect" ) );

	if( file.fileName == "" )
		throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateGlobalStatistics: file name incorrect" ) );


    decipherStat->nowDecipherFile.nowDecipherBSName = file.baseStation;
    decipherStat->nowDecipherFile.nowDecipherFile = file.fileName + ".FTC"; 
}

void updateDecipherNowDecipherFilePercent( DecipherStatisticsData *decipherStat, unsigned int persent ) {
    decipherStat->nowDecipherFile.nowDecipherFileDonePercent = persent;    
}

void updateDecipherInputFiles( DecipherStatisticsData *decipherStat, const FileDescriptorData &file ) {
    ::std::list< DLL_decipherCounters >::iterator decipherCountersIterator;

    for( decipherCountersIterator = decipherStat->counters.counters.begin(); 
         decipherCountersIterator != decipherStat->counters.counters.end();
         ++decipherCountersIterator ) 
    {
        if( decipherCountersIterator->bsName == file.baseStation ) {
            decipherCountersIterator->inputFiles ++;
            break;
        }
    }
    if( decipherCountersIterator == decipherStat->counters.counters.end() ) {
        DLL_decipherCounters newBS = {};
        newBS.bsName = file.baseStation;
        newBS.inputFiles = 1;
        decipherStat->counters.counters.push_back(newBS);
    }
}

void updateDecipherQueue( DecipherStatisticsData *decipherStat, const FileDescriptorData &file ) {
    DLL_decipherQueue newFile = {};
	    
    newFile.bsName = file.baseStation;
    newFile.fileName = file.fileName + ".FTC";

    decipherStat->decipherQueue.decipherQueue.push_back(newFile);

#ifdef _DEBUG
//	_logDecipherQueueIn << newFile.fileName << std::endl;
#endif

	decipherQueueCounter ++;
}

void updateDecipherOKFiles( DecipherStatisticsData *decipherStat, const FileDescriptorData &file ) {

    {
        std::list< DLL_decipherCounters >::iterator decipherCountersIterator;

        for( decipherCountersIterator = decipherStat->counters.counters.begin(); 
             decipherCountersIterator != decipherStat->counters.counters.end();
             ++decipherCountersIterator ) 
        {
            if( decipherCountersIterator->bsName == file.baseStation ) {
                decipherCountersIterator->decipheredFiles ++;
                break;
            }
        }
        if( decipherCountersIterator == decipherStat->counters.counters.end() ) {
            throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateDecipherStatistics: OK file not found in counters" ) );
        }
    }

    {
        std::list< DLL_decipherQueue >::iterator decipherQueueIterator;
        std::string fileName = file.fileName + ".FTC";

#ifdef _DEBUG
//		_logDecipherOk << fileName << std::endl;
#endif
	
        for( decipherQueueIterator = decipherStat->decipherQueue.decipherQueue.begin(); 
             decipherQueueIterator != decipherStat->decipherQueue.decipherQueue.end();
             ++decipherQueueIterator ) 
        {
            if( decipherQueueIterator->fileName == fileName ) 
                break;
        }
        if( decipherQueueIterator == decipherStat->decipherQueue.decipherQueue.end() ) {
#ifdef _DEBUG
// 			_logDecipherOk.flush();
// 			_logDecipherOk.close();
// 
// 			if( _logDecipherQueueIn.is_open() ) {
// 				_logDecipherQueueIn.flush();
// 				_logDecipherQueueIn.close();
// 			}
#endif
            throw nppntt::mdm::exceptions::exception_StatisticsError ( ::jmsf::CONSTANT_TEXT_STRING( "UpdateDecipherStatistics: OK file not found in decipher queue" ) );
		}
        else {
            decipherStat->decipherQueue.decipherQueue.erase( decipherQueueIterator );
			if( decipherStat->decipherQueue.decipherQueue.empty() ) {
				decipherStat->nowDecipherFile.nowDecipherBSName = "";
				decipherStat->nowDecipherFile.nowDecipherFile = "";
				decipherStat->nowDecipherFile.nowDecipherFileDonePercent = 0;
			}
		}
    }
}

void updateDecipherBADFiles( DecipherStatisticsData *decipherStat, const FileDescriptorData &file, const bool isDeletedFromDecipher ) {
	//return;
	
	// Необходима инфа о том что это нормально дешифрованный файл, его здесь проверять не надо
	
	if( !isDeletedFromDecipher ) {
		// Значит это БЭД файл после попытки дешифрования
		{
			std::list< DLL_decipherCounters >::iterator decipherCountersIterator;

			for( decipherCountersIterator = decipherStat->counters.counters.begin(); 
				decipherCountersIterator != decipherStat->counters.counters.end();
				++decipherCountersIterator ) 
			{
				if( decipherCountersIterator->bsName == file.baseStation ) {
					decipherCountersIterator->notDecipheredFiles++;
					break;
				}
			}
			if( decipherCountersIterator == decipherStat->counters.counters.end() ) {
				throw nppntt::mdm::exceptions::exception_StatisticsError( ::jmsf::CONSTANT_TEXT_STRING( "UpdateDecipherStatistics: BAD file not found in counters" ) );
			}
		}
		{
			std::list< DLL_decipherQueue >::iterator decipherQueueIterator;
			std::string fileName = file.fileName + ".FTC";

			for( decipherQueueIterator = decipherStat->decipherQueue.decipherQueue.begin(); 
				decipherQueueIterator != decipherStat->decipherQueue.decipherQueue.end();
				++ decipherQueueIterator ) 
			{
				if( decipherQueueIterator->fileName == fileName ) 
					break;
			}
			
			if( decipherQueueIterator == decipherStat->decipherQueue.decipherQueue.end() ) {
				throw nppntt::mdm::exceptions::exception_StatisticsError ( ::jmsf::CONSTANT_TEXT_STRING( "UpdateDecipherStatistics: BAD file not found in decipher queue" ) );
			}
			else {
				decipherStat->decipherQueue.decipherQueue.erase( decipherQueueIterator );
				if( decipherStat->decipherQueue.decipherQueue.empty() ) {
					decipherStat->nowDecipherFile.nowDecipherBSName = "";
					decipherStat->nowDecipherFile.nowDecipherFile = "";
					decipherStat->nowDecipherFile.nowDecipherFileDonePercent = 0;
				}
			}
		}
	}
	else {
		// Файл взят из очереди дешифратора, не прошел фильтр
		// Попытаемся найти его в очереди и удалить
		{
			std::list< DLL_decipherQueue >::iterator decipherQueueIterator;
			std::string fileName = file.fileName + ".FTC";

			for( decipherQueueIterator = decipherStat->decipherQueue.decipherQueue.begin(); 
				decipherQueueIterator != decipherStat->decipherQueue.decipherQueue.end();
				++ decipherQueueIterator ) 
			{
				if( decipherQueueIterator->fileName == fileName ) 
					break;
			}
			
			if( decipherQueueIterator == decipherStat->decipherQueue.decipherQueue.end() ) {
				::Sleep( 0 );
				//throw nppntt::mdm::exceptions::exception_StatisticsError ( ::jmsf::CONSTANT_TEXT_STRING( "UpdateDecipherStatistics: BAD file not found in decipher queue" ) );
			}
			else {
				decipherStat->decipherQueue.decipherQueue.erase( decipherQueueIterator );
				if( decipherStat->decipherQueue.decipherQueue.empty() ) {
					decipherStat->nowDecipherFile.nowDecipherBSName = "";
					decipherStat->nowDecipherFile.nowDecipherFile = "";
					decipherStat->nowDecipherFile.nowDecipherFileDonePercent = 0;
				}
			}
		}
	}
}

// Вызвать для каждого файла в отдельности
void updateDataBaseStatisticts( DataBaseStatisticsData *dataBaseStat, FileDescriptorData &file ) {
    std::list< DLL_dataBaseCounters >::iterator dataBaseCounterIterator;
    
    for( dataBaseCounterIterator = dataBaseStat->dataBaseCounters.begin();
         dataBaseCounterIterator != dataBaseStat->dataBaseCounters.end();
         ++ dataBaseCounterIterator ) 
    {
        if( dataBaseCounterIterator->bsName == file.baseStation ) {
            if( file.type == _FTC ) 
                dataBaseCounterIterator->voice_send++;
            else if( file.type == _SDC ) {
				if( !file.isStatisticsAlreadyPassed ) {
					file.isStatisticsAlreadyPassed = TRUE;
					if( file.isSMS ) 
						dataBaseCounterIterator->sms_send++;
					else
						dataBaseCounterIterator->sdc_send++;
				}
//                 if( file.isSMS )
//                     dataBaseCounterIterator->sms_send++;
//                 else
//                     dataBaseCounterIterator->sdc_send++;
            }
            break;
        }
    }

    if( dataBaseCounterIterator == dataBaseStat->dataBaseCounters.end() ) {
        DLL_dataBaseCounters newBS = {};

        newBS.bsName = file.baseStation;
        if( file.type == _FTC )
            newBS.voice_send = 1;
        else if( file.type == _SDC ) {     
			if( !file.isStatisticsAlreadyPassed ) {
				file.isStatisticsAlreadyPassed = TRUE;
				if( file.isSMS ) 
					newBS.sms_send = 1;
				else
					newBS.sdc_send = 1;
			}
//             if( file.isSMS )
//                 newBS.sms_send = 1;
//             else
//                 newBS.sdc_send = 1;
        }
        dataBaseStat->dataBaseCounters.push_back( newBS );
    }
}

void updateDeleteFiles( DeleteFilesStatisticsData *deleteFilesStat, const FileDescriptorData &file ) {
    
    std::list< DLL_deleteFilesCountes >::iterator deleteFilesIterator;

    for( deleteFilesIterator = deleteFilesStat->deleteFilesCounters.begin();
         deleteFilesIterator != deleteFilesStat->deleteFilesCounters.end();
         ++ deleteFilesIterator ) 
    {

        if( deleteFilesIterator->bsName == file.baseStation ) {
            if( file.type == _FTC ) 
                deleteFilesIterator->ftc_delete ++;
            else if( file.type == _SDC )
                deleteFilesIterator->sdc_delete ++;
            break;
        }
    }
    if( deleteFilesIterator == deleteFilesStat->deleteFilesCounters.end() ) {
        DLL_deleteFilesCountes newBS = {};
        
        newBS.bsName = file.baseStation;
        if( file.type == _FTC ) 
            newBS.ftc_delete = 1;
        else if( file.type == _SDC )
            newBS.sdc_delete = 1;

        deleteFilesStat->deleteFilesCounters.push_back( newBS );
    }
}

void copyGlobalStatistics(const GlobalStatisticsData *statIn, GlobalStatisticsData *statOut) {
    memcpy(statOut, statIn, sizeof(GlobalStatisticsData));
}
