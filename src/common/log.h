#pragma once
#ifndef __LOG_H__
#define __LOG_H__


#include <iostream>
#ifdef _WIN32
#include <log4cpp/config-win32.h>
#ifdef _DEBUG
#pragma comment(lib,"./../3rd/log4cpp/lib/log4cpp_d.lib")
#else
#pragma comment(lib,"./../3rd/log4cpp/lib/log4cpp.lib")
#endif
#endif // _WIN32
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <stdio.h>
#include <string.h>
#include <errno.h>
using namespace log4cpp;
class Logger
{
public:
	Logger();
	~Logger();
	void Init();
	Category& GetLogger();
public:
	char logName[64];
	char filePath[128];
	bool m_LogToConsole;
	bool m_LogToFile;
private:
	Category* logger;

};
extern Logger gLogger;
#define log_warn(__format__,...) \
	gLogger.GetLogger().warn(__format__,__VA_ARGS__)
#define log_info(__format__,...) \
	gLogger.GetLogger().info(__format__,__VA_ARGS__)
#define log_debug(__format__,...) \
	gLogger.GetLogger().debug(__format__,__VA_ARGS__)
#define log_error(__format__,...) \
	gLogger.GetLogger().error(__format__,__VA_ARGS__)
#define log_lasterror() \
	log_error("%s",strerror(errno))


#endif

