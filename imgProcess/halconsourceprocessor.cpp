#include "halconsourceprocessor.h"
/* halcon c++源码图像处理类 */
HalconSourceProcessor::HalconSourceProcessor(HalconCpp::HObject &img
                                             ,boolean needShowSlideBar)
    :currentImg(img),needShowSlideBar(needShowSlideBar)
{

}

void HalconSourceProcessor::executeProcess()
{
    preExecute();
    realExecute();
    afterExecute();
}

void HalconSourceProcessor::reExecuteProcess()
{

}

void HalconSourceProcessor::realExecute()
{

}

void HalconSourceProcessor::preExecute()
{

}

void HalconSourceProcessor::afterExecute()
{
    qDebug()<< "afterExecute";
    if(needShowSlideBar && m_sliderDialog != nullptr && !m_sliderDialog->isVisible()){
       m_sliderDialog->show();
       qDebug()<< "show m_sliderDialog";
    }


}
