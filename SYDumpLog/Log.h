#pragma once

class Log
{
public:
	//creat
	static Log* Instance(void);
	~Log(void);
	//method
	void DumpLog(const wchar_t *pFilePath, wchar_t *pStr);
	void DumpLogLine(const wchar_t *pFilePath, wchar_t *pStr);
private:
	//method
	Log(void);
	void UnicodeToAnsi(const wchar_t *source, char **dest);
private:
	//var
	//creat
	static Log*	m_instance;	
};
