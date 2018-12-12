/////////////////////////////////////////////////////////////////////////////
// EAProcess.cpp
//
// Copyright (c) 2003, Electronic Arts Inc. All rights reserved.
// Created by Paul Pedriana
//
// This module defines functions for process spawning and query.
/////////////////////////////////////////////////////////////////////////////


#include "EA/StdC/internal/Config.h"
#include <EAStdC/EAProcess.h>
#include <EAStdC/EAString.h>
#include EA_ASSERT_HEADER

#if defined(EA_PLATFORM_WINDOWS)
    #pragma warning(push, 0)
    #include <Windows.h>
    #include <process.h>
    #include <ShellAPI.h>
    #include <stdlib.h>
    #pragma warning(pop)

    #ifdef _MSC_VER
        #pragma comment(lib, "shell32.lib") // Required for shellapi calls.
    #endif

#elif defined(EA_PLATFORM_UNIX)
    #include <sys/types.h>
    #if EASTDC_SYS_WAIT_H_AVAILABLE
        #include <sys/wait.h>
    #endif
    #include <unistd.h>
    #include <errno.h>
    #include <stdio.h>

#elif defined(EA_PLATFORM_XENON)
    #pragma warning(push, 1)
    #include <xtl.h>
    #if EA_XBDM_ENABLED
        #include <xbdm.h>
        // #pragma comment(lib, "xbdm.lib") The application is expected to provide this if needed.
    #endif
    #pragma warning(pop)

#elif defined(EA_PLATFORM_PS3)
    #include <sys/paths.h>
    #include <sysutil/sysutil_gamecontent.h> 
    #include <sys/fs_external.h>

#endif

#if defined(EA_PLATFORM_OSX)
    // An alternative to _NSGetArgv which works on iOS in addition to OSX is NSProcessInfo.
    extern "C" char*** _NSGetArgv();
#endif


namespace EA
{

namespace StdC
{


#if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
    const int kMaxPathLength      = _MAX_PATH;
    const int kMaxDirectoryLength = _MAX_PATH;


    // According to Microsoft documentation:
    //   The GetModuleFileName function retrieves the full path and file name
    //   for the file containing the specified module.
    //   If the function succeeds, the return value is the length of the string 
    //   copied to the buffer, in TCHARs. If the buffer is too small to hold the 
    //   module name, the string is truncated to the user-supplied capacity, and 
    //   the function returns that capacity.

    EASTDC_API size_t GetCurrentProcessPath(char16_t* pPath)
    {
        const DWORD dwResult = GetModuleFileNameW(NULL, pPath, kMaxPathLength);

        if((dwResult != 0) && (dwResult < kMaxPathLength)) // If there wasn't an error and there was enough capacity...
            return (size_t)dwResult;

        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessPath(char8_t* pPath)
    {
        // We cannot use GetModuleFileNameA here, because the text encoding of 
        // GetModuleFileNameA is arbitrary and in any case is usually not UTF8. 
        char16_t path16[kMaxPathLength];
        GetCurrentProcessPath(path16);

        const int intendedStrlen = Strlcpy(pPath, path16, kMaxPathLength);

        if((intendedStrlen >= 0) && (intendedStrlen < kMaxPathLength))
            return (size_t)intendedStrlen;

        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char16_t* pDirectory)
    {
        const DWORD dwResult = GetModuleFileNameW(NULL, pDirectory, kMaxDirectoryLength);

        if((dwResult != 0) && (dwResult < kMaxDirectoryLength)) // If there wasn't an error and there was enough capacity...
        {
            DWORD dw;

            for(dw = dwResult; dw > 0; --dw)
            {
                if((pDirectory[dw - 1] != '/') && (pDirectory[dw - 1] != '\\'))
                    pDirectory[dw - 1] = 0;
                else
                    break;
            }

            return dw;
        }

        pDirectory[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char8_t* pDirectory)
    {
        char16_t path16[kMaxDirectoryLength];
        GetCurrentProcessDirectory(path16);

        const int intendedStrlen = Strlcpy(pDirectory, path16, kMaxDirectoryLength);

        if((intendedStrlen >= 0) && (intendedStrlen < kMaxDirectoryLength))
            return (size_t)intendedStrlen;

        pDirectory[0] = 0;
        return 0;
    }

#elif defined(EA_PLATFORM_XENON)

    const int kMaxPathLength      = 260;
    const int kMaxDirectoryLength = 260;

    // XBox 360 (a.k.a. Xenon) doesn't support the wide (W) functions that Windows does.
    // The encoding of file and directory names is limited to a subset of 8 bit ASCII.

    EASTDC_API size_t GetCurrentProcessPath(char16_t* pPath)
    {
        // We get the 8 bit path and upconvert it to char16_t.
        char8_t path8[kMaxPathLength];
        GetCurrentProcessPath(path8);

        const int intendedStrlen = Strlcpy(pPath, path8, kMaxPathLength);

        if((intendedStrlen >= 0) && (intendedStrlen < kMaxPathLength)) // If successful (UTF8 to UTF16 conversions can theoretically fail, if the encoded chars are bad...
            return (size_t)intendedStrlen;

        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessPath(char8_t* pPath)
    {
        #if EA_XBDM_ENABLED
            const char pNameTemp[1] = { 0 };
            DM_XBE xbeInfo;
            memset(&xbeInfo, 0, sizeof(xbeInfo));
            HRESULT hResult = DmGetXbeInfo(pNameTemp, &xbeInfo);

            if((hResult == XBDM_NOERR) && xbeInfo.LaunchPath[0])
            {
                const char* const pLastSeparator = Strrchr(xbeInfo.LaunchPath, '\\');

                if(pLastSeparator)
                {
                    Strcpy(pPath, "GAME:\\");
                    Strcat(pPath, pLastSeparator + 1);  // To do: Switch this to Strlcat and check its return value.
                    return Strlen(pPath);
                }
            }
        #endif

        //#if defined(EA_DEBUG) // To do: Test this.
        //    const char* const pCommandLine = GetCommandLineA();
        //
        //    if(pCommandLine)
        //    {
        //        const char* pBegin = pCommandLine;
        //        if(*pBegin == '\"')
        //            pBegin += 1;
        //
        //        const char* pEnd = Stristr(pCommandLine, ".xex");
        //        if(pEnd)
        //        {
        //             pEnd += 4;
        //
        //             size_t i;
        //             for(int i = 0; i < (kMaxPathLength - 1) && (pBegin != pEnd); i++, pBegin++)
        //                 pPath[i] = *pBegin;
        //             pPath[i] = 0;
        //             return i;
        //        }
        //    }
        //#endif

        // We need a different strategy. It turns out that XGetLaunchData / XGetLaunchInfo
        // don't seem to work, as they don't have a defined data format we can rely on.

        const char*     pPattern = "GAME:\\*";
        WIN32_FIND_DATA wfd;
        HANDLE          hFind = FindFirstFile(pPattern, &wfd);

        if(hFind == INVALID_HANDLE_VALUE)
            pPath[0] = 0;
        else
        {
            Strlcpy(pPath, "GAME:\\", kMaxPathLength);
            Strlcat(pPath, wfd.cFileName, kMaxPathLength);

            FindClose(hFind);
        }

        return Strlen(pPath);
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char16_t* pDirectory)
    {
        pDirectory[0] = 'G';
        pDirectory[1] = 'A';
        pDirectory[2] = 'M';
        pDirectory[3] = 'E';
        pDirectory[4] = ':';
        pDirectory[5] = '\\';
        pDirectory[6] = 0;

        return 6;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char8_t* pDirectory)
    {
        pDirectory[0] = 'G';
        pDirectory[1] = 'A';
        pDirectory[2] = 'M';
        pDirectory[3] = 'E';
        pDirectory[4] = ':';
        pDirectory[5] = '\\';
        pDirectory[6] = 0;

        return 6;
    }

#elif defined(EA_PLATFORM_PS3)

    const int kMaxPathLength      = 1024;
    const int kMaxDirectoryLength = 1024;

    EASTDC_API size_t GetCurrentProcessPath(char16_t* pPath)
    {
        char8_t path8[kMaxPathLength];
        GetCurrentProcessPath(path8);

        const int intendedStrlen = Strlcpy(pPath, path8, kMaxPathLength);

        if((intendedStrlen >= 0) && (intendedStrlen < kMaxPathLength)) // If successful (UTF8 to UTF16 conversions can theoretically fail, if the encoded chars are bad...
            return (size_t)intendedStrlen;

        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessPath(char8_t* pPath)
    {
        pPath[0] = 0;
        return 0;

        #if 0 // To do: Implement per-platform code here instead of the EAIO code below.

            char16_t pPath16[kMaxPathLength];

            if(GetCurrentProcessDirectory(pPath16))
            {
                IO::DirectoryIterator dir;
                IO::DirectoryIterator::EntryList entryList(IO::DirectoryIterator::EntryList::allocator_type(EASTL_NAME_VAL(UTFFOUNDATION_ALLOC_PREFIX "EAProcess/EntryList")));
                const char16_t* pWildcard[3] = { EA_CHAR16("*.self"), EA_CHAR16("*.elf"), EA_CHAR16("*.exe") };

                for(size_t i = 0; i < sizeof(pWildcard)/sizeof(pWildcard[0]); i++)
                {
                    if(dir.Read(pPath16, entryList, pWildcard[i], IO::kDirectoryEntryFile, 1))
                    {
                        const IO::DirectoryIterator::Entry& entry = entryList.front();
                        Strcat(pPath16, entry.msName.c_str());

                        return Strlcpy(pPath, pPath16, kMaxPathLength);
                    }
                }
            }
        #endif
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char16_t* pDirectory)
    {
        #if EASTDC_PS3_GAMEDATA_ENABLED
            size_t nStrlen;

            // cellGameBootCheck can get the directory of games loaded from the HDD.
            // Apparently it works only from HDD-booted games.

            unsigned int        type = 0;           // CELL_GAME_GAMETYPE_DISC or CELL_GAME_GAMETYPE_HDD
            unsigned int        attr = 0;           // CELL_GAME_ATTRIBUTE_PATCH | CELL_GAME_ATTRIBUTE_APP_HOME | CELL_GAME_ATTRIBUTE_DEBUG | etc.
            CellGameContentSize gameContentSize;
            char                dirName[CELL_FS_MAX_FS_PATH_LENGTH] = { 0 };

            int result = cellGameBootCheck(&type, &attr, &gameContentSize, dirName);

            if((result ==  CELL_GAME_RET_OK) && dirName[0])
            {
                nStrlen = Strlcpy(pDirectory, dirName, CELL_FS_MAX_FS_PATH_LENGTH);
                if((nStrlen == 0) || (pDirectory[nStrlen - 1] != '/'))
                    pDirectory[nStrlen++] = '/';
            }
            else
            {
                Strcpy(pDirectory, EA_CHAR16("/app_home/"));
                nStrlen = Strlen(pDirectory);
            }

            return nStrlen;
        #else
            Strcpy(pDirectory, EA_CHAR16("/app_home/"));
            return Strlen(pDirectory);
        #endif
    }


    EASTDC_API size_t GetCurrentProcessDirectory(char8_t* pDirectory)
    {
        #if EASTDC_PS3_GAMEDATA_ENABLED
            size_t nStrlen;

            // cellGameBootCheck can get the directory of games loaded from the HDD.
            // Apparently it works only from HDD-booted games.

            unsigned int        type = 0;   // CELL_GAME_GAMETYPE_DISC or CELL_GAME_GAMETYPE_HDD
            unsigned int        attr = 0;   // CELL_GAME_ATTRIBUTE_PATCH | CELL_GAME_ATTRIBUTE_APP_HOME | CELL_GAME_ATTRIBUTE_DEBUG | etc.
            CellGameContentSize gameContentSize;

            int result = cellGameBootCheck(&type, &attr, &gameContentSize, pDirectory);

            if((result ==  CELL_GAME_RET_OK) && pDirectory[0])
            {
                nStrlen = Strlen(pDirectory);
                if((nStrlen == 0) || (pDirectory[nStrlen - 1] != '/'))
                    pDirectory[nStrlen++] = '/';
            }
            else
            {
                Strcpy(pDirectory, "/app_home/");
                nStrlen = Strlen(pDirectory);
            }

            return nStrlen;
        #else
            Strcpy(pDirectory, "/app_home/");
            return Strlen(pDirectory);
        #endif
    }


#elif defined(EA_PLATFORM_REVOLUTION) || defined(EA_PLATFORM_CTR)

    const int kMaxPathLength      = 512;
    const int kMaxDirectoryLength = 512;

    EASTDC_API size_t GetCurrentProcessPath(char16_t* pPath)
    {
        char8_t path8[kMaxPathLength];
        GetCurrentProcessPath(path8);

        const int intendedStrlen = Strlcpy(pPath, path8, kMaxPathLength);

        if((intendedStrlen >= 0) && (intendedStrlen < kMaxPathLength)) // If successful (UTF8 to UTF16 conversions can theoretically fail, if the encoded chars are bad...
            return (size_t)intendedStrlen;

        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessPath(char8_t* pPath)
    {
        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char16_t* pDirectory)
    {
        pDirectory[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char8_t* pDirectory)
    {
        pDirectory[0] = 0;
        return 0;
    }

#elif defined(EA_PLATFORM_OSX)

    const int kMaxPathLength      = 1024;
    const int kMaxDirectoryLength = 1024;

    EASTDC_API size_t GetCurrentProcessPath(char16_t* pPath)
    {
        char8_t path8[kMaxPathLength];
        GetCurrentProcessPath(path8);

        const int intendedStrlen = Strlcpy(pPath, path8, kMaxPathLength);

        if((intendedStrlen >= 0) && (intendedStrlen < kMaxPathLength)) // If successful (UTF8 to UTF16 conversions can theoretically fail, if the encoded chars are bad...
            return (size_t)intendedStrlen;

        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessPath(char8_t* pPath)
    {
        // We could be a little more portable by using something like this:
        //     int getProcessArgs[3] = { CTL_KERN, KERN_PROCARGS, 50 };
        //     sysctl(getProcessArgs, 3, NULL, &length, NULL, 0);
        //     char* processArgs = malloc(length * sizeof(char));
        //     sysctl(getProcessArgs, 3, processArgs, &length, NULL, 0);
        //     . . .
        
        char** argv = *_NSGetArgv();

        const size_t intendedStrlen = Strlcpy(pPath, argv[0], kMaxPathLength);

        if(intendedStrlen < (size_t)kMaxPathLength) // If succeeded (if pPath had enough capacity) ... 
            return Strlen(pPath);

        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char16_t* pDirectory)
    {
        char8_t path8[kMaxDirectoryLength];    // We don't have access to EAIO here.
        GetCurrentProcessDirectory(path8);

        const int intendedStrlen = Strlcpy(pDirectory, path8, kMaxDirectoryLength);

        if((intendedStrlen >= 0) && (intendedStrlen < kMaxDirectoryLength)) // If successful (UTF8 to UTF16 conversions can theoretically fail, if the encoded chars are bad...
            return (size_t)intendedStrlen;

        pDirectory[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char8_t* pDirectory)
    {
        // argv[0]       pDirectory
        // --------------------------------------------------
        // ""      ->    ""          (Should never happen)
        // "/"     ->    "/"         (Should never happen)
        // "a"     ->    "a"         (Should never happen)
        // "/a/b"  ->    /a/"

        char** argv = *_NSGetArgv();

        EA_COMPILETIME_ASSERT(kMaxDirectoryLength >= kMaxPathLength); // We assert this because argv[0] could concievably be as long as kMaxPathLength.
        const size_t intendedStrlen = Strlcpy(pDirectory, argv[0], kMaxDirectoryLength);

        if(intendedStrlen < 512) // If succeeded... 
        {
            for(char8_t* p = pDirectory + intendedStrlen; p > pDirectory; --p)
            {
                if(p[-1] == '/')
                {
                    p[0] = 0; // e.g. /aaa/bbb/ccc => /aaa/bbb/
                    return (size_t)(p - pDirectory);
                }
            }

            // Alternative slower implementation:
            //char* p = strrchr(pDirectory, '/');
            //if(p) // This should usually (always?) be valid.
            //    *p = 0;   // e.g. /aaa/bbb/ccc => /aaa/bbb/

            return Strlen(pDirectory);
        }

        pDirectory[0] = 0;
        return 0;
    }

#elif defined(EA_PLATFORM_LINUX)

    const int kMaxPathLength      = 1024;
    const int kMaxDirectoryLength = 1024;

    EASTDC_API size_t GetCurrentProcessPath(char8_t* pPath)
    {
        char pCmdLineBuffer[kMaxPathLength];

        FILE* fp = fopen("/proc/self/cmdline", "r");
        EA_ASSERT(fp != NULL);
        size_t count = fread(pCmdLineBuffer, 1, kMaxPathLength, fp);  // cmdline is a long string of 0-terminated strings (argv values) one after the other.
        pCmdLineBuffer[kMaxPathLength - 1] = 0;
        fclose(fp);

        if(count) // We can use feof(fp) to tell if there was an error or simply no result.
        {
            const size_t length = Strlcpy(pPath, pCmdLineBuffer, kMaxPathLength);
            EA_ASSERT(length < (size_t)kMaxPathLength);

            if(length < (size_t)kMaxPathLength)
                return length;
        }

        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessPath(char16_t* pPath)
    {
        char8_t path8[kMaxPathLength];
        GetCurrentProcessPath(path8);

        const int intendedStrlen = Strlcpy(pPath, path8, kMaxPathLength);

        if((intendedStrlen >= 0) && (intendedStrlen < kMaxPathLength)) // If successful (UTF8 to UTF16 conversions can theoretically fail, if the encoded chars are bad...
            return (size_t)intendedStrlen;

        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char8_t* pDirectory)
    {
        char pCmdLineBuffer[kMaxPathLength];

        FILE *fp = fopen("/proc/self/cmdline", "r");
        EA_ASSERT(fp != NULL);
        size_t count = fread(pCmdLineBuffer, 1, kMaxPathLength, fp);   // cmdline is a long string of 0-terminated strings (argv values) one after the other.
        pCmdLineBuffer[kMaxPathLength - 1] = 0;
        fclose(fp);

        if(count) // We can use feof(fp) to tell if there was an error or simply no result.
        {
            size_t length = Strlcpy(pDirectory, pCmdLineBuffer, kMaxPathLength);
            EA_ASSERT(length < (size_t)kMaxPathLength);

            if(length < (size_t)kMaxPathLength) // If there was enough capacity...
            {
                while(length && (pDirectory[length - 1] != '/'))
                    pDirectory[--length] = 0;
                return length;
            }
        }

        pDirectory[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char16_t* pDirectory)
    {
        char8_t path8[kMaxDirectoryLength];    // We don't have access to EAIO here.
        GetCurrentProcessDirectory(path8);

        const int intendedStrlen = Strlcpy(pDirectory, path8, kMaxDirectoryLength);

        if((intendedStrlen >= 0) && (intendedStrlen < kMaxDirectoryLength)) // If successful (UTF8 to UTF16 conversions can theoretically fail, if the encoded chars are bad...
            return (size_t)intendedStrlen;

        pDirectory[0] = 0;
        return 0;
    }

    #if 0
    /*
        // http://blog.linuxgamepublishing.com/2009/10/12/argv-and-argc-and-just-how-to-get-them/
        // http://stackoverflow.com/questions/1585989/how-to-parse-proc-pid-cmdline
        // https://www.google.com/search?q=%2Fproc%2Fself%2Fcmdline

        char** get_argv()
        {
            static char   emptyNonConstString[1][1] = { { 0 } };
            static char** savedArgv = NULL;
        
            if(!savedArgv)
            {
                FILE* pFile = fopen("/proc/self/cmdline", "r");
        
                if(pFile) // This should be true for at least all recent Linux versions.
                {
                    const  size_t kBufferSize = 1024; // This should be dynamically allocated if we are to be able to ready any buffer.
                    char   buffer[kBufferSize];
                    size_t count = fread(buffer, 1, kBufferSize, pFile);
        
                    if(ferror(pFile) == 0) // If succeeded...
                    {
                        buffer[kBufferSize - 1] = 0;
         
                        // To do.
                        // buffer has an arbitrary number of 0-terminated strings layed one after another.
                        // Allocate an array of char pointers or use a static array of arrays. We can simply copy buffer to a permanent buffer and index its strings.
                        // Need to free an allocated array on shutdown.
                        // Check to make sure that the strlen wasn't too long.
                    }
                    fclose(pFile);   
                }
            }
        
            savedArgv = emptyNonConstString;
            return savedArgv;
        }
    */
    #endif

#else
    const int kMaxPathLength      = 512;
    const int kMaxDirectoryLength = 512;

    EASTDC_API size_t GetCurrentProcessPath(char16_t* pPath)
    {
        char8_t path8[kMaxPathLength];
        GetCurrentProcessPath(path8);

        const int intendedStrlen = Strlcpy(pPath, path8, kMaxPathLength);

        if(intendedStrlen >= 0) // If successful (UTF8 to UTF16 conversions can theoretically fail, if the encoded chars are bad...
            return (size_t)intendedStrlen;

        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessPath(char8_t* pPath)
    {
        pPath[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char16_t* pDirectory)
    {
        pDirectory[0] = 0;
        return 0;
    }

    EASTDC_API size_t GetCurrentProcessDirectory(char8_t* pDirectory)
    {
        pDirectory[0] = 0;
        return 0;
    }

#endif


// The 32 bit versions of GetCurrentProcessPath and GetCurrentProcessDirectory are the same generic
// versions for all platforms, as they just route to using the platform-specific versions.
EASTDC_API size_t GetCurrentProcessPath(char32_t* pPath)
{
    char8_t path8[kMaxPathLength];
    GetCurrentProcessPath(path8);

    const int intendedStrlen = Strlcpy(pPath, path8, kMaxPathLength);

    if((intendedStrlen >= 0) && (intendedStrlen < kMaxPathLength)) // If successful...
        return (size_t)intendedStrlen;

    pPath[0] = 0;
    return 0;
}

EASTDC_API size_t GetCurrentProcessDirectory(char32_t* pDirectory)
{
    char8_t path8[kMaxDirectoryLength];    // We don't have access to EAIO here.
    GetCurrentProcessDirectory(path8);

    const int intendedStrlen = Strlcpy(pDirectory, path8, kMaxDirectoryLength);

    if((intendedStrlen >= 0) && (intendedStrlen < kMaxDirectoryLength)) // If successful...
        return (size_t)intendedStrlen;

    pDirectory[0] = 0;
    return 0;
}






EASTDC_API size_t GetEnvironmentVar(const char16_t* pName, char16_t* pValue, size_t valueCapacity)
{
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        DWORD dwLength = GetEnvironmentVariableW(pName, pValue, (DWORD)valueCapacity);

        if(dwLength == 0)
        {
            if(GetLastError() == ERROR_ENVVAR_NOT_FOUND)
                return (size_t)-1;
        }
        else if(dwLength > valueCapacity)
            dwLength -= 1; // On insufficient capacity, Windows returns the required capacity.

        return (size_t)dwLength;

    #else
        char8_t name8[260];    
        char8_t value8[260];    

        Strlcpy(name8, pName, 260);
        const size_t len = GetEnvironmentVar(name8, value8, 260);

        if(len < 260)
            return (size_t)Strlcpy(pValue, value8, valueCapacity, len);

        return len; // Note that the len here is for UTF8 chars, but the user is asking for 16 bit chars. So the returned len may be higher than the actual required len.
    #endif
}


EASTDC_API size_t GetEnvironmentVar(const char8_t* pName, char8_t* pValue, size_t valueCapacity)
{
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        DWORD dwLength = GetEnvironmentVariableA(pName, pValue, (DWORD)valueCapacity);

        if(dwLength == 0)
        {
            if(GetLastError() == ERROR_ENVVAR_NOT_FOUND)
                return (size_t)-1;
        }
        else if(dwLength > valueCapacity)
            dwLength -= 1; // On insufficient capacity, Windows returns the required capacity.

        return (size_t)dwLength;

    #elif defined(EA_PLATFORM_UNIX)
        const char8_t* const var = getenv(pName);
        if (var)
            return Strlcpy(pValue, var, valueCapacity);
        return (size_t)-1;
    #else
        // To consider: Implement this manually for the given platform.
        // Environment variables are application globals and so we probably need to use our OSGlobal to implement this.
        EA_UNUSED(pName);
        EA_UNUSED(pValue);
        EA_UNUSED(valueCapacity);
        return (size_t)-1;
    #endif
}


EASTDC_API bool SetEnvironmentVar(const char16_t* pName, const char16_t* pValue)
{
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        const BOOL bResult = SetEnvironmentVariableW(pName, pValue); // Windows has the same behavior as us: NULL pValue removes the variable.
        return (bResult != 0);
    #else
        char8_t name8[260];
        Strlcpy(name8, pName, 260);

        char8_t value8[260];
        Strlcpy(value8, pValue, 260);

        return SetEnvironmentVar(name8, value8);
    #endif
}


EASTDC_API bool SetEnvironmentVar(const char8_t* pName, const char8_t* pValue)
{
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        const BOOL bResult = SetEnvironmentVariableA(pName, pValue); // Windows has the same behavior as us: NULL pValue removes the variable.
        return (bResult != 0);
    #elif defined(EA_PLATFORM_UNIX)
        // The opinion of the Linux people is that you just shouldn't ever call setenv during application runtime.
        // A better solution for us is to use shared mapped memory (shm_open(), mmap()): http://www.ibm.com/developerworks/aix/library/au-spunix_sharedmemory/index.html
        if(pValue)
            return setenv(pName, pValue, 1) == 0;
        else
            return unsetenv(pName) == 0;
    #else
        // To consider: Implement this manually for the given platform.
        // Environment variables are application globals and so we probably need to use our OSGlobal to implement this.
        // The easiest way for us to implement this is with an stl/eastl map. But we don't currently have access to those
        // from this package. So we are currently stuck using something simpler, like a key=value;key=value;key=value... string.
        EA_UNUSED(pName);
        EA_UNUSED(pValue);
        return false;
    #endif
}




EASTDC_API int Spawn(const char16_t* pPath, const char16_t* const* pArgumentArray, bool wait)
{
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        if (wait)
            return int(_wspawnv(_P_WAIT, pPath, pArgumentArray));
        else
            return int(_wspawnv(_P_DETACH, pPath, pArgumentArray));
    #else
        EA_UNUSED(pPath);
        EA_UNUSED(pArgumentArray);
        EA_UNUSED(wait);

        // TODO: convert and call char8_t version
        EA_FAIL_MESSAGE("Spawn: Not implemented for this platform.");
        return -1;
    #endif
}


EASTDC_API int Spawn(const char8_t* pPath, const char8_t* const* pArgumentArray, bool wait)
{
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        if(wait)
            return int(_spawnv(_P_WAIT, pPath, pArgumentArray));
        else
            return int(_spawnv(_P_DETACH, pPath, pArgumentArray));

    #elif defined(EA_PLATFORM_UNIX) && EASTDC_SYS_WAIT_H_AVAILABLE
        pid_t id = fork();

        if(id == 0) // child
        {
            //int result = 
            execv(pPath, (char* const*)pArgumentArray);
            exit(errno);
        }

        if(wait)
        {
            int status;
            waitpid(id, &status, 0); // waitpid() is safer than wait(), and seems currently be available on all OSs that matter to us.

            if(WIFEXITED(status))
                return WEXITSTATUS(status); // exit value of child

            // the child was killed due to a signal. we could find out
            // which signal if we wanted, but we're not really doing unix signals.
            return -1;
        }
        return 0;

    #else
        EA_UNUSED(pPath);
        EA_UNUSED(pArgumentArray);
        EA_UNUSED(wait);

        EA_FAIL_MESSAGE("Spawn: Not implemented for this platform.");
        return -1;
    #endif
}


EASTDC_API int ExecuteShellCommand(const char16_t* pCommand)
{
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        // Todo: verify that newlines work here and support them if not.
        return _wsystem(pCommand); // We could do this via the shell api as well.
    #else
        char8_t command8[260];   
        Strlcpy(command8, pCommand, 260);

        return ExecuteShellCommand(command8);
    #endif
}


int ExecuteShellCommand(const char8_t* pCommand)
{
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        // Todo: verify that newlines work here and support them if not.
        return system(pCommand); // We could do this via the shell api as well.
    #elif defined(EA_PLATFORM_UNIX)
        return system(pCommand);
    #else
        EA_UNUSED(pCommand);
        return false;
    #endif
}



#if defined(DISABLED_____EA_PLATFORM_UNIX) // Need to implement this in a way that doesn't use EASTL or an allocator.
    EASTDC_API bool SearchEnvPathWithMode(const char8_t* pathListVar, const char8_t* fileName, int mode, eastl::string8* fullPath)
    {
        if (*fileName == '/' || *fileName == '\\')
        {
            fullPath->assign(fileName);
            return access(fileName, F_OK) == 0;
        }

        const char* pathList = getenv(pathListVar);

        if (pathList)
        {
            const char* pathStart = pathList;
            const char* pathEnd   = pathStart;

            while (true)
            {
                while ((*pathEnd != ':') && (*pathEnd != 0))
                    ++pathEnd;

                if (pathEnd > pathStart)
                {
                    fullPath->assign(pathStart, pathEnd - pathStart);

                    if ((*pathEnd != '/') && (*pathEnd != '\\'))
                        *fullPath += '/';

                    *fullPath += fileName;

                    if (access(fullPath->c_str(), F_OK) == 0)
                        return true;
                }

                if (*pathEnd == 0)  // end explicitly so we don't access outside pathList.
                    break;

                pathEnd++;
                pathStart = pathEnd;
            }          
        }

        return false;
    }

#endif // EA_PLATFORM_UNIX



EASTDC_API bool SearchEnvironmentPath(const char16_t* pFileName, char16_t* pPath, const char16_t* pEnvironmentVar)
{
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        if(!pEnvironmentVar)
            pEnvironmentVar = EA_CHAR16("PATH");
        _wsearchenv(pFileName, pEnvironmentVar, pPath);
        return (*pPath != 0);

    #else 
        char8_t path8    [260]; 
        char8_t fileName8[260]; 

        Strlcpy(path8,     pPath,     260);
        Strlcpy(fileName8, pFileName, 260);

        bool success;

        if (pEnvironmentVar)
        {
            char8_t environmentVariable8[260]; 
            Strlcpy(environmentVariable8, pEnvironmentVar, 260);

            success = EA::StdC::SearchEnvironmentPath(fileName8, path8, environmentVariable8);
        }
        else
            success = EA::StdC::SearchEnvironmentPath(fileName8, path8);

        Strlcpy(pPath, path8, 260);
        return success;
    #endif
}


EASTDC_API bool SearchEnvironmentPath(const char8_t* pFileName, char8_t* pPath, const char8_t* pEnvironmentVar)
{
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        if(!pEnvironmentVar)
            pEnvironmentVar = "PATH";
        _searchenv(pFileName, pEnvironmentVar, pPath);
        return (*pPath != 0);

    #elif defined(DISABLED_____EA_PLATFORM_UNIX) // Need to implement this in a way that doesn't use EASTL or an allocator.
        eastl::string8 path8(EASTLAllocatorType(UTFFOUNDATION_ALLOC_PREFIX "EAProcess"));
        bool success;

        if (pEnvironmentVar)
            success = SearchEnvPathWithMode(pEnvironmentVar, pFileName, F_OK, &path8); // Just require existence.
        else
            success = SearchEnvPathWithMode("PATH", pFileName, X_OK, &path8); // Require executability.
            
        if (success)
        {
            Strcpy(pPath, path8.c_str());
            return true;
        }
        return false;

    #else
        EA_UNUSED(pFileName); 
        EA_UNUSED(pPath); 
        EA_UNUSED(pEnvironmentVar);
        return false;
    #endif
}


#if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
    namespace // anonymous namespace for this file.
    {
        typedef HINSTANCE (APIENTRY* ShellExecuteWFunctionType)(HWND hwnd, LPCWSTR lpOperation, LPCWSTR lpFile, LPCWSTR lpParameters, LPCWSTR lpDirectory, INT nShowCmd);
        static ShellExecuteWFunctionType ShellExecuteWFunction = NULL;
        static HINSTANCE hShellExecuteWFunctionLibrary = NULL;

        struct ShellExecuteWFunctionEntryPointFinder
        {
            ShellExecuteWFunctionEntryPointFinder()
            {
                hShellExecuteWFunctionLibrary = LoadLibraryW(EA_CHAR16("shell32.dll"));
                if(hShellExecuteWFunctionLibrary)
                    ShellExecuteWFunction = (ShellExecuteWFunctionType)(void*)::GetProcAddress(hShellExecuteWFunctionLibrary, "ShellExecuteW");
            }
            ~ShellExecuteWFunctionEntryPointFinder()
            {
                if(hShellExecuteWFunctionLibrary)
                    ::FreeLibrary(hShellExecuteWFunctionLibrary);
            }
        };
    }

    EASTDC_API bool OpenFile(const char16_t* pPath)
    {
        HINSTANCE hInstance = 0;

        ShellExecuteWFunctionEntryPointFinder sShellExecuteWFunctionEntryPointFinder;

        if(ShellExecuteWFunction)
        {
            if(Strstr(pPath, EA_CHAR16("http://")) == pPath) // If the path begins with "http://" and is thus a URL...
            {
                char16_t pathMod[260 + 4];
                Strcpy(pathMod, EA_CHAR16("url:"));
                Strlcat(pathMod, pPath,260 + 4); // ShellExecute wants the path to look like this: "url:http://www.bozo.com"
                hInstance = ShellExecuteWFunction(NULL, EA_CHAR16("open"), pathMod, NULL, NULL, SW_SHOWNORMAL);
            }
            else
                hInstance = ShellExecuteWFunction(NULL, EA_CHAR16("open"), pPath, NULL, NULL, SW_SHOWNORMAL);
        }

        return ((uintptr_t)hInstance > 32);
    }

    EASTDC_API bool OpenFile(const char8_t* pPath)
    {
        char16_t path16[260]; 
        Strlcpy(path16, pPath, 260);

        return OpenFile(path16);
    }

#else

    EASTDC_API bool OpenFile(const char16_t* pPath)
    {
        char8_t path8[260];
        Strlcpy(path8, pPath, 260);

        return OpenFile(path8);
    }

    EASTDC_API bool OpenFile(const char8_t* pPath)
    {
        #if defined (EA_PLATFORM_OSX)
            const char8_t* args[] =
            {
                "open",
                pPath,
                0
            };
            return Spawn("/usr/bin/open", args) != -1;
        #else
            EA_UNUSED(pPath);
            return false;
        #endif
    }

#endif // EA_PLATFORM_WINDOWS



} // namespace StdC

} // namespace EA







