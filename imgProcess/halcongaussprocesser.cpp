#include "halcongaussprocesser.h"

HalconGaussProcesser::HalconGaussProcesser(HalconCpp::HObject &img)
    :HalconScriptProcesser("get_gauss_filter_img",img,true)
{
    connect(m_sliderDialog->slider(), &QSlider::valueChanged, this, &HalconGaussProcesser::onGaussFilterKernelSizeChange);
    if(m_sliderDialog != nullptr){
        m_sliderDialog->setText("change gauss filter kernel");
        m_sliderDialog->setRange(3,11);
    }
}

void HalconGaussProcesser::preExecute() {
    HalconScriptProcesser::preExecute();
    if(proCall != nullptr){
       qDebug()<< "SetInputCtrlParamTuple";
       proCall->SetInputCtrlParamTuple("size",gaussSize);
    }
}

void HalconGaussProcesser::afterExecute(){
    HalconScriptProcesser::afterExecute();
}

void HalconGaussProcesser::onGaussFilterKernelSizeChange(int size)
{
    qDebug()<< "onGaussFilterKernelSizeChange size:" << size;
    if(size%2 == 0){
        qDebug()<< "size%2 return" << size;
        return;
    }

    gaussSize = size;
    reExecuteProcess();
}


