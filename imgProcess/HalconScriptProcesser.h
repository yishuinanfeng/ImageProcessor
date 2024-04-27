#ifndef HALCONSCRIPTPROCESSER_H
#define HALCONSCRIPTPROCESSER_H

#include "IImgProcess.h"


class HalconScriptProcesser: public IImgProcess
{

public:
    HalconScriptProcesser(QString m,HalconCpp::HObject &img);

    HalconScriptProcesser(QString m,HalconCpp::HObject &img,boolean needShowSlideBar);

    virtual void executeProcess() override; //执行图像处理前的预处理（设置参数等）
    virtual void reExecuteProcess() override;
    virtual void preExecute();
    /*执行图像处理后的处理*/
    virtual void afterExecute();

//signals:
//    void imageProcessDone(const HalconCpp::HObject &processImg,boolean needOp); // 定义信号


protected:
    //要处理的图像
    HalconCpp::HObject currentImg;
    HDevEngineCpp::HDevProcedureCall *proCall = nullptr;
    QString methodName = "";

private:
    boolean needShowSlideBar = false;
};

#endif // HALCONSCRIPTPROCESSER_H
