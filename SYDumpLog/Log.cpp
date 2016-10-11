#include "StdAfx.h"
#include "Log.h"
#include <fstream>

Log* Log::m_instance = NULL;

Log* Log::Instance()
{
	if (m_instance == NULL){
		m_instance = new Log(); 
	}
	return m_instance;
}

Log::Log(void)
{
}

Log::~Log(void)
{
}

////////////////////////////////////////////////////////////////
//	char *pAniFilename = NULL;
//	StringManager::Instance()->WCharTochar(appPath.c_str(), &pAniFilename);
//  delete pAniFilename;
void Log::UnicodeToAnsi(const wchar_t *source, char **dest)
{
	*dest = (char *)new char[2 * wcslen(source) + 1] ;
	memset(*dest, 0, 2 * wcslen(source) + 1);

	int nLen = (int)wcslen(source) + 1;
	WideCharToMultiByte(CP_ACP, 0, source, nLen, *dest, 2*nLen, NULL, NULL);
	//OutputDebugStringA((*dest));
}


void Log::DumpLog(const wchar_t *pFilePath, wchar_t *pStr)
{
	FILE *fLog = NULL;
	
	_wfopen_s(&fLog, pFilePath, L"a+");

	if ( fLog != NULL)
	{
		char *pAniFilename = NULL;
		UnicodeToAnsi(pStr, &pAniFilename);

		char szbuf[256];
		memset(szbuf, 0, sizeof(szbuf));
		sprintf(szbuf, "%s", pAniFilename);
		fwrite( szbuf, sizeof(char), strlen(szbuf), fLog );
		delete pAniFilename;
		fclose( fLog );
	}
}


void Log::DumpLogLine(const wchar_t *pFilePath, wchar_t *pStr)
{
	FILE *fLog = NULL;

	_wfopen_s(&fLog, pFilePath, L"a+");

	if ( fLog != NULL)
	{
		char *pAniFilename = NULL;
		UnicodeToAnsi(pStr, &pAniFilename);

		char szbuf[256];
		memset(szbuf, 0, sizeof(szbuf));
		sprintf(szbuf, "%s", pAniFilename);
		fwrite( szbuf, sizeof(char), strlen(szbuf), fLog );
		fwrite("\r\n", sizeof(char), 2, fLog );
		delete pAniFilename;
		fclose( fLog );
	}
}