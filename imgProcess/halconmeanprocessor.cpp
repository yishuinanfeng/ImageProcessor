#include "halconmeanprocessor.h"

HalconMeanProcessor::HalconMeanProcessor(HalconCpp::HObject &img)
    :HalconScriptProcesser("get_mean_filter_img",img,true)
{
    qDebug()<< "HalconGrayProcessor";
    connect(m_sliderDialog->slider(), &QSlider::valueChanged, this
            , &HalconMeanProcessor::onMeanFilterKernelSizeChange);
    if(m_sliderDialog != nullptr){
        m_sliderDialog->setText("change gauss filter kernel");
        m_sliderDialog->setRange(3,101);
    }
}

void HalconMeanProcessor::preExecute() {
    HalconScriptProcesser::preExecute();
    if(proCall != nullptr){
       qDebug()<< "SetInputCtrlParamTuple";
       proCall->SetInputCtrlParamTuple("size",meanSize);
    }
}

void HalconMeanProcessor::afterExecute(){
    HalconScriptProcesser::afterExecute();
}

void HalconMeanProcessor::onMeanFilterKernelSizeChange(int size)
{
    qDebug()<< "onGaussFilterKernelSizeChange size:" << size;
    if(size%2 == 0){
        qDebug()<< "size%2 return" << size;
        return;
    }

    meanSize = size;
    reExecuteProcess();
}
