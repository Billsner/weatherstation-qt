QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    OnlineServices/downloadmanager.cpp \
    Datapool/datapoolcontroll.cpp \
    Datapool/datapoolelement.cpp \
    Datapool/datapoolinterface.cpp \
    Datapool/datapooltrigger.cpp \
    FileAccess/logfile.cpp \
    FileAccess/logini.cpp \
    FileAccess/savedatapool.cpp \
    GUIQML/QMLObjects/qmlsettings.cpp \
    GUIQML/QMLObjects/qmlstatusline.cpp \
    GUIQML/QMLObjects/qmlweather.cpp \
    GUIQML/getqmlobject.cpp \
    Threads/datapoolthread.cpp \
    Threads/weatherthread.cpp \
    Utils/logging.cpp \
    Utils/loggingserver.cpp \
    weather/weatherpicinfo.cpp \
    weather/weatherpicwarning.cpp

RESOURCES += GUIQML/Resources/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    weather/weatherdef.hpp \
    OnlineServices/downloadmanager.hpp \
    Datapool/datapoolcontroll.hpp \
    Datapool/datapooldefinition.hpp \
    Datapool/datapoolelement.hpp \
    Datapool/datapoolindex.hpp \
    Datapool/datapoolinterface.hpp \
    Datapool/datapooltrigger.hpp \
    FileAccess/logfile.hpp \
    FileAccess/logini.hpp \
    FileAccess/savedatapool.hpp \
    GUIQML/QMLObjects/qmlsettings.hpp \
    GUIQML/QMLObjects/qmlstatusline.hpp \
    GUIQML/QMLObjects/qmlweather.hpp \
    GUIQML/getqmlobject.hpp \
    Threads/datapoolthread.hpp \
    Threads/weatherthread.hpp \
    Utils/logging.hpp \
    Utils/loggingdef.hpp \
    Utils/loggingserver.hpp \
    weather/weatherpicinfo.hpp \
    weather/weatherpicwarning.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
