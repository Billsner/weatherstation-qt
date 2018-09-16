#ifndef LOGGINGDEF_HPP
#define LOGGINGDEF_HPP

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

const int invalidLogID = -1;

#endif // LOGGINGDEF_HPP
