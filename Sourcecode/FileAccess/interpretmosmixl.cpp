#include "interpretmosmixl.hpp"
#include <QStringList>
#include <QDir>
#include <QProcess>
#include <QCoreApplication>

InterpretMOSMIXL::InterpretMOSMIXL() :
    mLogging("FileAcces.InterpretMOSMIXL")
{

}

InterpretMOSMIXL::~InterpretMOSMIXL()
{

}

void InterpretMOSMIXL::startIntepretion(void)
{
    mLogging <= "startIntepretion";
    unzipFile();
}

void InterpretMOSMIXL::unzipFile(void)
{
    QProcess unzip;
    QStringList argument;
    argument << "";
    unzip.setWorkingDirectory(QCoreApplication::applicationDirPath()+"/download");
    unzip.start("./unzipfiles.sh");
    if (unzip.waitForFinished())
    {
        (mLogging << "unzipFile: unzip finish: ") <= QCoreApplication::applicationDirPath().toStdString();
    }
}

void InterpretMOSMIXL::openFile(void)
{

}
