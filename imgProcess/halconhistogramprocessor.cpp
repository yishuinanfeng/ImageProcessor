#include "halconhistogramprocessor.h"

HalconHistogramProcessor::HalconHistogramProcessor(HalconCpp::HObject &img)
    :HalconSourceProcessor(img,false)
{
    histogramDialog = new HistogramDialog();
}

void HalconHistogramProcessor::realExecute()
{
    if(histogramDialog != nullptr){
       HalconCpp::HObject euqlizationImage;
       histogramDialog->showHistogramImage(currentImg,euqlizationImage);
       qDebug()<< "emit imageProcessDone";
       emit imageProcessDone(euqlizationImage,false);
    }
}

void HalconHistogramProcessor::histogramEqualization()
{

}
