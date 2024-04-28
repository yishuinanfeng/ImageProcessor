#include "halcondynthresprocessor.h"

HalconDynThresProcessor::HalconDynThresProcessor(HalconCpp::HObject &img)
    :HalconSourceProcessor(img,true)
{
    connect(m_sliderDialog->slider(), &QSlider::valueChanged, this, &HalconDynThresProcessor::onOffsetChange);
    if(m_sliderDialog != nullptr){
        m_sliderDialog->setText("change dynThres offset");
        m_sliderDialog->setRange(1,99);
        m_sliderDialog->setInitValue(offset);
    }
}

void HalconDynThresProcessor::realExecute()
{
    qDebug()<< "HalconDynThresProcessor realExecute offset:" << offset;
    HalconSourceProcessor::realExecute();
    HalconCpp::HObject ho_outputImg;
    get_dyn_threshold_img(currentImg,ho_outputImg);
    qDebug()<< "get_dyn_threshold_img done";
    emit imageProcessDone(ho_outputImg,false);
}

void HalconDynThresProcessor::reExecuteProcess()
{
     realExecute();
}

void HalconDynThresProcessor::get_dyn_threshold_img(HalconCpp::HObject ho_originImg, HalconCpp::HObject &ho_outputImg)
{
    // Local iconic variables
     HalconCpp::HObject  ho_ImageMean;
     //均值滤波
     HalconCpp::MeanImage(ho_originImg, &ho_ImageMean, 15, 15);
     DynThreshold(ho_originImg, ho_ImageMean, &ho_outputImg, offset, "light");
}

void HalconDynThresProcessor::onOffsetChange(int offset)
{
    qDebug()<< "onOffsetChange offset:" << offset;
    this->offset = offset;
    reExecuteProcess();
}
