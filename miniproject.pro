QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET += IMDB-review
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    imdb_class/imdb_class.cpp \
    main.cpp \
    main-IMDB/imdb.cpp \
    source_class/source_class.cpp \
    user_class/user_class.cpp

HEADERS += \
    imdb_class/imdb_class.h \
    main-IMDB/imdb.h \
    source_class/source_class.h \
    user_class/user_class.h

FORMS += \
    main-IMDB/imdb.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
