#ifndef LOGGINGDEF_HPP
#define LOGGINGDEF_HPP

#include <QString>

enum LogLevel
{
    LLOFF,
    LLcritical,
    LLwarning,
    LLdebug,
    LLinfo,
    LLALL
};

enum LogMode
{
    LMoutput,
    LMfile,
    LMall
};

struct slogger
{
    QString loggername;
    LogLevel loglevel;
    LogMode logmode;
    bool logon;
    bool logconstr;
};

const int invalidLogID = -1;

#endif // LOGGINGDEF_HPP
