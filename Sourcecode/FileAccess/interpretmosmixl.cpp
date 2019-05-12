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
    argument << "/download/MOSMIX_L_LATEST_10488.kmz.0";
    unzip.setWorkingDirectory(QCoreApplication::applicationDirPath()+"/download");
    unzip.start("unzip",argument);
    if (unzip.waitForFinished())
    {
        (mLogging << "unzipFile: unzip finish: ") <= QCoreApplication::applicationDirPath().toStdString();
    }
}

void InterpretMOSMIXL::openFile(void)
{

}
