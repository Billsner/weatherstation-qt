#ifndef LOGFILE_HPP
#define LOGFILE_HPP

#include <QFile>
#include <QDataStream>
#include <QLoggingCategory>
#include <QMutex>

class Logfile
{
public:
    Logfile();
    ~Logfile();

    void openFile();
    void closeFile();
    void writeLogMsg(const char *msg);



private:
    QFile mfile;
    QMutex m_mutex;
    bool mfileopen;
    QLoggingCategory m_categrory;
};

#endif // LOGFILE_HPP
