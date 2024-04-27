#include "halcongrayprocessor.h"

HalconGrayProcessor::HalconGrayProcessor(HalconCpp::HObject &img)
    :HalconScriptProcesser("get_gray_picture",img)
{
    qDebug()<< "HalconGrayProcessor";
}
