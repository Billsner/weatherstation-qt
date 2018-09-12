#ifndef LOGFILE_HPP
#define LOGFILE_HPP

#include <QFile>
#include <QDataStream>
#include <QMutex>

class Logfile
{
public:
    Logfile();
    ~Logfile();

    static Logfile *getInstance();

    void openFile();
    void closeFile();
    void writeLogMsg(const char *msg);



private:
    QFile mfile;
    QMutex m_mutex;
    bool mfileopen;
};

#endif // LOGFILE_HPP
