QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    Datapool/DatapoolThread.cpp \
    Datapool/QMLObjects/QMLDateTime.cpp \
    GUIQML/GetQMLObject.cpp \
    Datapool/DatapoolControll.cpp \
    Datapool/DatapoolElement.cpp

RESOURCES += GUIQML/Resources/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Datapool/DatapoolThread.hpp \
    Datapool/QMLObjects/QMLDateTime.hpp \
    GUIQML/GetQMLObject.hpp \
    Datapool/DatapoolControll.hpp \
    Datapool/DatapoolElement.hpp \
    Datapool/DatapoolDefinition.hpp
