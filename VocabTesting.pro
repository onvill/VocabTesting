
QT       += testlib sql widgets multimedia

TARGET = maintest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += maintest.cpp \
    DbqeurierTest.cpp \
    \
    ../VocabWidener/dbqeurier.cpp


HEADERS += \
    DbqeurierTest.h \
    \
    ../VocabWidener/dbqeurier.h

DEFINES += SRCDIR=\\\"$$PWD/\\\"
