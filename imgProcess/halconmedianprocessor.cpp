#include "halconmedianprocessor.h"

HalconMedianProcessor::HalconMedianProcessor(HalconCpp::HObject &img)
    :HalconSourceProcessor(img,true)
{
    connect(m_sliderDialog->slider(), &QSlider::valueChanged, this, &HalconMedianProcessor::onMedianFilterKernelSizeChange);
    if(m_sliderDialog != nullptr){
        m_sliderDialog->setText("change gauss filter kernel");
        m_sliderDialog->setRange(3,11);
    }
}

void HalconMedianProcessor::realExecute()
{
    qDebug()<< "HalconMedianProcessor executeProcess:";
    HalconSourceProcessor::realExecute();
    HalconCpp::HObject ho_outputImg;
    HalconCpp::HTuple turple = HalconCpp::HTuple(medianRadius);
    get_median_filter_img(currentImg,ho_outputImg,turple);
    qDebug()<< "get_median_filter_img done";
    emit imageProcessDone(ho_outputImg,false);
}

void HalconMedianProcessor::reExecuteProcess()
{
    realExecute();
}

void HalconMedianProcessor::preExecute()
{
    HalconSourceProcessor::preExecute();
}

void HalconMedianProcessor::afterExecute()
{
    HalconSourceProcessor::afterExecute();
}

void HalconMedianProcessor::onMedianFilterKernelSizeChange(int size)
{
    qDebug()<< "onMedianFilterKernelSizeChange size:" << size;
    if(size%2 == 0){
        qDebug()<< "size%2 return" << size;
        return;
    }

    medianRadius = size;
    reExecuteProcess();
}

// Procedures
void HalconMedianProcessor::get_median_filter_img (HalconCpp::HObject ho_originImg, HalconCpp::HObject &ho_outputImg
                                                   , HalconCpp::HTuple hv_radius)
{
  qDebug()<< "get_median_filter_img";
  MedianImage(ho_originImg, &ho_outputImg, "circle", hv_radius, "mirrored");

  return;
}
