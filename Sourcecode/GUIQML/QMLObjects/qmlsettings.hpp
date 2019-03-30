#ifndef QMLSETTINGS_HPP
#define QMLSETTINGS_HPP

#include <QObject>
#include "Utils/logging.hpp"

class QMLSettings: public QObject
{
    Q_OBJECT
public:
    QMLSettings();
    ~QMLSettings();

    void init();

    void triggertimer(void);
    void setDataformat2GUI(void);

public slots:
    void receiveDateformate(QString format);
    void receiveDateformateIndex(int formatid);

private:
    Logging mLogging;
    QObject *mSettingsObject;

    void connect();

};

#endif // QMLSETTINGS_HPP
