#ifndef HALCONSCRIPTHANDLER_H
#define HALCONSCRIPTHANDLER_H

#include <QObject>
#include "ui_mainwindow.h"
#include "halconcpp/HalconCpp.h"
#include <halconcpp/HTuple.h>
#include "imageselector.h"
#include "utils.h"
#include "dashboardshower.h"
#include <halconcpp/HException.h>
#include <QDebug>
#include "hdevengine/HDevEngineCpp.h"

#include <imgProcess/HalconScriptProcesser.h>

/* Halcon脚本图像处理的处理类 */
class HalconScriptHandler : public QObject
{
    Q_OBJECT
public:
    explicit HalconScriptHandler(QObject *parent = nullptr,Ui::MainWindow *ui = nullptr);

    ~HalconScriptHandler();

    void init();

    void ShowImgByHalcon(const QString &ImgPath);

    void connectProcessorCallback(IImgProcess *halconScriptProcesser);

    void startProcess();

private:
    Ui::MainWindow *ui;
    HalconCpp::HTuple hHandle;


    Utils utils;
    HalconCpp::HObject currentImg;

    boolean isImgLoaded = false;

    IImgProcess *halconProcesser = nullptr;

    DashBoardShower *dashBoardShower;

 private  slots:
     void onImgProcessed(const HalconCpp::HObject &processImg,boolean needOpenWindow);

signals:

};

#endif // HALCONSCRIPTHANDLER_H
