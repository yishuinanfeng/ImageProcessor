#include "HalconScriptProcesser.h"
/* halcon脚本图像处理类 */
HalconScriptProcesser::HalconScriptProcesser(QString m,HalconCpp::HObject &img)
:currentImg(img),methodName(m)
{
    m_sliderDialog = new SliderDialog();
}

HalconScriptProcesser::HalconScriptProcesser(QString m,HalconCpp::HObject &img
                                             ,boolean needShowSlideBar)
:currentImg(img),methodName(m),needShowSlideBar(needShowSlideBar)
{

}

void HalconScriptProcesser::preExecute(){
    qDebug()<< "preExecute";


}

void HalconScriptProcesser::afterExecute(){
    qDebug()<< "afterExecute";
    if(needShowSlideBar && m_sliderDialog != nullptr && !m_sliderDialog->isVisible()){
       m_sliderDialog->show();
    }

    qDebug()<< "show m_sliderDialog";
}

void HalconScriptProcesser::executeProcess() {
    try{
        qDebug()<< "methodName:" << methodName.toStdString().c_str();

        HDevEngineCpp::HDevProcedure pro(methodName.toStdString().c_str());

        qDebug()<< "after pro";

        proCall = new HDevEngineCpp::HDevProcedureCall(pro);

        qDebug()<< "proCall(pro)";
        //开启halcon脚本调试
       // HDevEngineCpp::HDevEngine().StartDebugServer();

        proCall->SetInputIconicParamObject("originImg",currentImg);

//        qDebug()<< "DispObj currentImg:" <<  currentImg;
        //其他特有参数留给子类具体设置
        preExecute();


        qDebug()<< "executeProcess";

        proCall->Execute();

        qDebug()<< "after Execute";

        afterExecute();

        HalconCpp::HObject outputImg = proCall->GetOutputIconicParamObject("outputImg");

        qDebug()<< "get outputImg" << outputImg.Key();

        qDebug()<< "emit imageProcessDone";
        emit imageProcessDone(outputImg,true);


    }catch(HalconCpp::HException &Exception)
    {
        qDebug() << "Exception.ProcNam:" << Exception.ProcName().Text(); //实际的HALCON算子的名字
        qDebug()<< "Exception.ErrorMessage:" << Exception.ErrorMessage().Text(); //错误信息
        qDebug()<< "Exception.ErrorCode:" << Exception.ErrorCode(); //错误码
    }

}

void HalconScriptProcesser::reExecuteProcess()
{
    qDebug()<< "reExecuteProcess";
    if(proCall == nullptr){
        qDebug()<< "make proCall first";
        return;
    }

    try{
        preExecute();


        qDebug()<< "executeProcess";

        proCall->Execute();

        qDebug()<< "after Execute";

        afterExecute();

        HalconCpp::HObject outputImg = proCall->GetOutputIconicParamObject("outputImg");

        qDebug()<< "get outputImg" << outputImg.Key();

        qDebug()<< "emit imageProcessDone";
        emit imageProcessDone(outputImg,false);

    }catch(HalconCpp::HException &Exception)
    {
        qDebug() << "Exception.ProcNam:" << Exception.ProcName().Text(); //实际的HALCON算子的名字
        qDebug()<< "Exception.ErrorMessage:" << Exception.ErrorMessage().Text(); //错误信息
        qDebug()<< "Exception.ErrorCode:" << Exception.ErrorCode(); //错误码
    }

}
