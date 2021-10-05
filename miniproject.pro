QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET += IMDB-review
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    class-source/file_class.cpp \
    class-source/move_class.cpp \
    main.cpp \
    main-page/imdb.cpp \
    class-source/user_class.cpp \
    process-page/process.cpp

HEADERS += \
    class-source/file_class.h \
    class-source/move_class.h \
    main-page/imdb.h \
    class-source/user_class.h \
    process-page/process.h

FORMS += \
    main-page/imdb.ui \
    process-page/process.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
