QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dashboardshower.cpp \
    halconscripthandler.cpp \
    histogramdialog.cpp \
    imageselector.cpp \
    imgProcess/HalconScriptProcesser.cpp \
    imgProcess/IImgProcess.cpp \
    imgProcess/halconbinaryprocessor.cpp \
    imgProcess/halconcannydetectprocessor.cpp \
    imgProcess/halcondynthresprocessor.cpp \
    imgProcess/halcongaussprocesser.cpp \
    imgProcess/halcongrayprocessor.cpp \
    imgProcess/halcongrequencegaussprocessor.cpp \
    imgProcess/halconhistogramprocessor.cpp \
    imgProcess/halconmeanprocessor.cpp \
    imgProcess/halconmedianprocessor.cpp \
    imgProcess/halconsobelprocessor.cpp \
    imgProcess/halconsourceprocessor.cpp \
    imgProcess/halconthresholdprocessor.cpp \
    main.cpp \
    mainwindow.cpp \
    sliderdialog.cpp \
    utils.cpp

HEADERS += \
    IImgProcess.h \
    dashboardshower.h \
    halconscripthandler.h \
    histogramdialog.h \
    imageselector.h \
    imgProcess/HalconScriptProcesser.h \
    imgProcess/IImgProcess.h \
    imgProcess/halconbinaryprocessor.h \
    imgProcess/halconcannydetectprocessor.h \
    imgProcess/halcondynthresprocessor.h \
    imgProcess/halcongaussprocesser.h \
    imgProcess/halcongrayprocessor.h \
    imgProcess/halcongrequencegaussprocessor.h \
    imgProcess/halconhistogramprocessor.h \
    imgProcess/halconmeanprocessor.h \
    imgProcess/halconmedianprocessor.h \
    imgProcess/halconsobelprocessor.h \
    imgProcess/halconsourceprocessor.h \
    imgProcess/halconthresholdprocessor.h \
    mainwindow.h \
    sliderdialog.h \
    utils.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#LIBS += -L'C:/Users/yanyinan/AppData/Local/Programs/MVTec/HALCON-22.05-Progress/lib/x64-win64/'
#LIBS += -lhalcon \
#     += -lhalconcpp \
#     += -lhdevenginecpp
LIBS += -LC:/Users/yanyinan/AppData/Local/Programs/MVTec/HALCON-22.05-Progress/lib/x64-win64/ -lhalcon
LIBS += -LC:/Users/yanyinan/AppData/Local/Programs/MVTec/HALCON-22.05-Progress/lib/x64-win64/ -lhalconcpp
LIBS += -LC:/Users/yanyinan/AppData/Local/Programs/MVTec/HALCON-22.05-Progress/lib/x64-win64/ -lhdevenginecpp
LIBS += -LD:/program/opencv4.5.5/opencv/build/x64/vc14/lib/opencv_world455.lib

INCLUDEPATH += C:/Users/yanyinan/AppData/Local/Programs/MVTec/HALCON-22.05-Progress/include \
               D:/program/opencv4.5.5/opencv/build/include \
               D:/program/opencv4.5.5/opencv/build/include/opencv2 \
DEPENDPATH += C:/Users/yanyinan/AppData/Local/Programs/MVTec/HALCON-22.05-Progress/include

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

#DISTFILES += \
#    imgProcess/新建文本文档.txt
