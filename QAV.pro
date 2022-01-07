QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    copenglwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    videoplayer.cpp \
    videoslider.cpp

HEADERS += \
    copenglwidget.h \
    mainwindow.h \
    videoplayer.h \
    videoslider.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32{
    FFMPEG_HOME = D:/3thlibrary/ffmpeg
}
INCLUDEPATH += $${FFMPEG_HOME}/include
LIBS += -L$${FFMPEG_HOME}/lib/win64/ -lavdevice \
    -lavformat \
    -lavutil

RESOURCES += \
    res.qrc