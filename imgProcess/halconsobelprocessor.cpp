#include "halconsobelprocessor.h"

HalconSobelProcessor::HalconSobelProcessor(HalconCpp::HObject &img)
    :HalconSourceProcessor(img,true)
{
    connect(m_sliderDialog->slider(), &QSlider::valueChanged, this, &HalconSobelProcessor::onSobelKernelSizeChange);
    if(m_sliderDialog != nullptr){
        m_sliderDialog->setText("change Frequence Gauss filter kernel");
        m_sliderDialog->setRange(3,19);
    }
}

void HalconSobelProcessor::realExecute()
{
    qDebug()<< "HalconSobelProcessor realExecute sobelSize:" << sobelSize;
    HalconSourceProcessor::realExecute();
    HalconCpp::HObject ho_outputImg;
    get_sobel_detect_img(currentImg,ho_outputImg);
    qDebug()<< "get_frequence_gauss_img done";
    emit imageProcessDone(ho_outputImg,false);
}

void HalconSobelProcessor::reExecuteProcess()
{
    realExecute();
}

void HalconSobelProcessor::get_sobel_detect_img (HalconCpp::HObject ho_originImg, HalconCpp::HObject &ho_outputImg)
{

  SobelAmp(ho_originImg, &ho_outputImg, "sum_abs", sobelSize);
  return;
}

void HalconSobelProcessor::onSobelKernelSizeChange(int size)
{
    qDebug()<< "HalconFrequenceGaussProcessor size:" << size;
    if(size%2 == 0){
        qDebug()<< "size%2 return" << size;
        return;
    }

    sobelSize = size;
    reExecuteProcess();
}
