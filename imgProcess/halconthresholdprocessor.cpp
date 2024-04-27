#include "halconthresholdprocessor.h"

HalconThresholdProcessor::HalconThresholdProcessor(HalconCpp::HObject &img)
:HalconSourceProcessor(img,true){
    connect(m_sliderDialog->slider(), &QSlider::valueChanged, this, &HalconThresholdProcessor::onThresHoldChange);
    if(m_sliderDialog != nullptr){
        m_sliderDialog->setText("change Threshold");
        m_sliderDialog->setRange(0,255);
        m_sliderDialog->setInitValue(minThres);
    }
}

void HalconThresholdProcessor::realExecute()
{
    qDebug()<< "HalconThresholdProcessor realExecute minThres:" << minThres;
    HalconSourceProcessor::realExecute();
    HalconCpp::HObject ho_outputImg;
    get_thresHold_img(currentImg,ho_outputImg);
    qDebug()<< "get_thresHold_img done";
    emit imageProcessDone(ho_outputImg,false);
}

void HalconThresholdProcessor::reExecuteProcess()
{
    realExecute();
}

void HalconThresholdProcessor::get_thresHold_img(HalconCpp::HObject ho_originImg, HalconCpp::HObject &ho_outputImg)
{
    Threshold(ho_originImg, &ho_outputImg, minThres, maxThres);
}

void HalconThresholdProcessor::onThresHoldChange(int minThres)
{
    qDebug()<< "onThresHoldChange minThres:" << minThres;

    this->minThres = minThres;
    reExecuteProcess();
}
