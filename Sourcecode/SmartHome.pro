QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    thread1.cpp \
    thread2.cpp \
    objectthread1.cpp \
    Datapool/DatapoolThread.cpp \
    Datapool/QMLObjects/QMLDateTime.cpp \
    GUIQML/GetQMLObject.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    thread1.hpp \
    thread2.hpp \
    objectthread1.hpp \
    Datapool/DatapoolThread.hpp \
    Datapool/QMLObjects/QMLDateTime.hpp \
    GUIQML/GetQMLObject.hpp
