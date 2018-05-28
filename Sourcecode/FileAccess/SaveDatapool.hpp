#ifndef SAVEDATAPOOL_HPP
#define SAVEDATAPOOL_HPP

#include <QString>
#include <QFile>
#include <QDataStream>
#include <QLoggingCategory>

class SaveDatapool
{
public:
    SaveDatapool();
    ~SaveDatapool();

    static SaveDatapool *getInstance();

    void openFile();
    void closeFile();

    void setHeader();
    int readHeader();

    void saveLine(unsigned int id, char *data, int datasize);
    void loadLine(unsigned int id, char *data, int &datasize);


private:
    QString mfilename;
    QFile mfile;
    int mHeaderOffset;
    QLoggingCategory m_categrory;
};

#endif // SAVEDATAPOOL_HPP
