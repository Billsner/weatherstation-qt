QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    Threads/DatapoolThread.cpp \
    GUIQML/QMLObjects/QMLDateTime.cpp \
    GUIQML/GetQMLObject.cpp \
    Datapool/DatapoolControll.cpp \
    Datapool/DatapoolElement.cpp \
    Datapool/DatapoolInterface.cpp \
    FileAccess/SaveDatapool.cpp \
    Utils/Logging.cpp

RESOURCES += GUIQML/Resources/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Threads/DatapoolThread.hpp \
    GUIQML/QMLObjects/QMLDateTime.hpp \
    GUIQML/GetQMLObject.hpp \
    Datapool/DatapoolControll.hpp \
    Datapool/DatapoolElement.hpp \
    Datapool/DatapoolDefinition.hpp \
    Datapool/DatapoolIndex.hpp \
    Datapool/DatapoolInterface.hpp \
    FileAccess/SaveDatapool.hpp \
    Utils/Logging.hpp
