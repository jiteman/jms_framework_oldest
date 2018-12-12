#pragma once

#include "abstractFileDescriptor.h"


#include "temporary_windows_include.h"


#include <list>


#define MAX_BS_COUNT            40
#define MAX_BS_NAME_LENGTH      70
#define MAX_FILE_NAME_LENGTH    MAX_PATH
#define MAX_DECIPHER_QUEUE_SIZE 100

#define MAX_FOLDERS_COUNT       20
#define MAX_FOLDER_NAME         MAX_PATH

/*
 структуры с префиксом GUI_ доступны интерфейсу
 структуры с префиксом DLL_ доступны только из библиотеки

 При вызове функции updateGlobalStatistics происходит только копирование из структур с префиксом DLL_ в структуры с префиксом GUI_.

 Вся работа по обновлению статистики происходит со структурами с префиксом DLL_.

*/

////////////////////////////////////////////////////////////////
//  Structures available in GUI.
////////////////////////////////////////////////////////////////
struct GUI_BaseStationsData {
    unsigned long BSCount;
    char BSList[MAX_BS_COUNT][MAX_BS_NAME_LENGTH];
};

struct GUI_DecipherQueueData {
    GUI_BaseStationsData BS;
    char fileNames[MAX_BS_COUNT][MAX_FILE_NAME_LENGTH];
};

struct BaseStationStatistics {
    char BSName[MAX_BS_NAME_LENGTH];

    unsigned long appenderFoundFTC;
    unsigned long appenderFoundSDC;

    unsigned long decipherInputFiles;
    unsigned long decipherDecipheredFiles;
    unsigned long decipherNotDecipheredFiles;

    unsigned long databaseSMSSend;
    unsigned long databaseSDCSend;
    unsigned long databaseFTCSend;

    unsigned long deleterFTCFiles;
    unsigned long deleterSDCFiles;
};

struct GUI_NowDecipherFileData {
    char nowDecipherBSName[MAX_BS_NAME_LENGTH];
    char nowDecipherFile[MAX_FILE_NAME_LENGTH];
    int nowDecipherFileDonePercent;
};

struct GlobalStatisticsData {
    unsigned long baseStationCount;
    BaseStationStatistics bsStat[MAX_BS_COUNT];   

    GUI_DecipherQueueData decipherQueue;
    GUI_NowDecipherFileData nowDecipherFile;
};

// Надо бы куда то отсюда это дело, короче выкинуть в другое файло
struct AppenderFoldersList {
    unsigned long foldersCount;
    char folders[MAX_FOLDERS_COUNT][MAX_FOLDER_NAME];
};

////////////////////////////////////////////////////////////////
// Structures available only in DLL
////////////////////////////////////////////////////////////////

// Counters
struct DLL_appenderStatisticsCounters {
    ::std::string bsName;
    unsigned long ftc_found;
    unsigned long sdc_found;
};

struct DLL_decipherCounters {
    ::std::string bsName;
    unsigned long inputFiles;
    unsigned long decipheredFiles;
    unsigned long notDecipheredFiles;
};

struct DLL_dataBaseCounters {
    ::std::string bsName;
    unsigned long sms_send;
    unsigned long sdc_send;
    unsigned long voice_send;
};

struct DLL_deleteFilesCountes {
    ::std::string bsName;
    unsigned long ftc_delete;
    unsigned long sdc_delete;
};

// Statistics lists
// appender
struct FileAppenderStatisticsData {
    ::std::list< DLL_appenderStatisticsCounters > statistics;
};

// Decipher 
struct NowDecipherFileData {
    ::std::string nowDecipherBSName;
    ::std::string nowDecipherFile;
    int nowDecipherFileDonePercent;
};

struct DLL_decipherQueue {
    ::std::string bsName;
    ::std::string fileName;
};

struct DecipherQueueData {
    ::std::list< DLL_decipherQueue > decipherQueue;    
};

struct DecipherStatisticsCountersData {
    ::std::list< DLL_decipherCounters > counters;
};

// Global decipher statistics
struct DecipherStatisticsData {
    NowDecipherFileData nowDecipherFile;    
    DecipherQueueData decipherQueue;
    DecipherStatisticsCountersData counters;
};

// Database
struct DataBaseStatisticsData {
    ::std::list< DLL_dataBaseCounters > dataBaseCounters;
};

// Deleter statistics
struct DeleteFilesStatisticsData {
    ::std::list< DLL_deleteFilesCountes > deleteFilesCounters;
};

////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////
// call from mdm
GlobalStatisticsData *createGlobalStatistics();
void deleteGlobalStatistics( GlobalStatisticsData *globalStat );

FileAppenderStatisticsData *createFileAppenderStatistics();
void deleteFileAppenderStatistics( FileAppenderStatisticsData *statistics);

DecipherStatisticsData *createDecipherStatistics();
void deleteDecipherStatistics( DecipherStatisticsData *statistics);

DataBaseStatisticsData *createDataBaseStatistics();
void deleteDataBaseStatistics( DataBaseStatisticsData *statistics);

DeleteFilesStatisticsData *createDeleteFilesStatistics();
void deleteDeleteFilesStatistics( DeleteFilesStatisticsData *statistics);

void updateAppenderStatistics(FileAppenderStatisticsData *appenderStat, FileDescriptorData &file);

void updateDecipherNowDecipherFile(DecipherStatisticsData *decipherStat, const FileDescriptorData &file);

// real time
void updateDecipherNowDecipherFilePercent(DecipherStatisticsData *decipherStat, /*const FileDescriptorData &file, */unsigned int persent);

void updateDecipherQueue(DecipherStatisticsData *decipherStat, const FileDescriptorData &file);
void updateDecipherOKFiles(DecipherStatisticsData *decipherStat, const FileDescriptorData &file);
void updateDecipherBADFiles(DecipherStatisticsData *decipherStat, const FileDescriptorData &file, bool isDeletedFromDecipher = false );

// Вызвать для каждого файла в отдельности
void updateDataBaseStatisticts(DataBaseStatisticsData *dataBaseStat, FileDescriptorData &file);
void updateDeleteFiles(DeleteFilesStatisticsData *deleteFilesStat, const FileDescriptorData &file);

void updateGlobalStatistics(GlobalStatisticsData *globalStatistics,
                            FileAppenderStatisticsData *appenderStat,
                            DecipherStatisticsData *decipherStat,
                            DataBaseStatisticsData *dataBaseStat,
                            DeleteFilesStatisticsData *deleteStat);

void copyGlobalStatistics(const GlobalStatisticsData *statIn, GlobalStatisticsData *statOut);