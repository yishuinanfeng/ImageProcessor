#ifndef HALCONSOURCEPROCESSOR_H
#define HALCONSOURCEPROCESSOR_H

#include "IImgProcess.h"

#include <QObject>
#include <QString>
#include "halconcpp/HalconCpp.h"
#include <halconcpp/HTuple.h>
#include <halconcpp/HException.h>
#include <QDebug>
#include "hdevengine/HDevEngineCpp.h"
#include <halconcpp/HObject.h>

class HalconSourceProcessor : public IImgProcess
{

public:
    explicit HalconSourceProcessor(HalconCpp::HObject &img
                                   ,boolean needShowSlideBar);

    virtual void executeProcess() override; //
    virtual void reExecuteProcess() override;
    virtual void realExecute();
    virtual void preExecute();
    virtual void afterExecute();

//signals:
//    void imageProcessDone(const HalconCpp::HObject &processImg,boolean needOp); // 定义信号


protected:

    //要处理的图像
    HalconCpp::HObject currentImg;



private:
    boolean needShowSlideBar = false;

signals:

};

#endif // HALCONSOURCEPROCESSOR_H
