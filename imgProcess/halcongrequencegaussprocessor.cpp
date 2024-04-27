
#include "halcongrequencegaussprocessor.h"

HalconFrequenceGaussProcessor::HalconFrequenceGaussProcessor(HalconCpp::HObject &img)
    :HalconSourceProcessor(img,true)
{
    connect(m_sliderDialog->slider(), &QSlider::valueChanged, this, &HalconFrequenceGaussProcessor::onFreGaussFilterKernelSizeChange);
    if(m_sliderDialog != nullptr){
        m_sliderDialog->setText("change Frequence Gauss filter kernel");
        m_sliderDialog->setRange(3,19);
    }
}


void HalconFrequenceGaussProcessor::realExecute()
{
    qDebug()<< "HalconFrequenceGaussProcessor realExecute Sigma:" << Sigma;
    HalconSourceProcessor::realExecute();
    HalconCpp::HObject ho_outputImg;
    get_frequence_gauss_img(currentImg,ho_outputImg);
    qDebug()<< "get_frequence_gauss_img done";
    emit imageProcessDone(ho_outputImg,false);
}

void HalconFrequenceGaussProcessor::reExecuteProcess()
{
    realExecute();
}

void HalconFrequenceGaussProcessor::get_frequence_gauss_img (HalconCpp::HObject ho_originImg, HalconCpp::HObject &ho_outputImg)
{

  // Local iconic variables
  HalconCpp::HObject  ho_ImageFFT, ho_ImageGauss, ho_ImageConvol;

  // Local control variables
  HalconCpp::HTuple  hv_Width, hv_Height;

  GetImageSize(ho_originImg, &hv_Width, &hv_Height);
  RftGeneric(ho_originImg, &ho_ImageFFT, "to_freq", "none", "complex", hv_Width);
  GenGaussFilter(&ho_ImageGauss, Sigma, Sigma, 0, "n", "rft", hv_Width, hv_Height);
  ConvolFft(ho_ImageFFT, ho_ImageGauss, &ho_ImageConvol);
  RftGeneric(ho_ImageConvol, &ho_outputImg, "from_freq", "none", "byte", hv_Width);

  return;
}

void HalconFrequenceGaussProcessor::onFreGaussFilterKernelSizeChange(int size)
{
    qDebug()<< "HalconFrequenceGaussProcessor size:" << size;
    if(size%2 == 0){
        qDebug()<< "size%2 return" << size;
        return;
    }

    Sigma = size;
    reExecuteProcess();
}


