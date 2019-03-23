#ifndef LOGGINGDEF_HPP
#define LOGGINGDEF_HPP

#include <QString>
#include <stdint.h>

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
    LMnoLog,
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

const uint32_t invalidLogID = 0xffffffff;

#endif // LOGGINGDEF_HPP
