#include "halconbinaryprocessor.h"

HalconBinaryProcessor::HalconBinaryProcessor(HalconCpp::HObject &img)
    :HalconScriptProcesser("get_binary_img",img)
{
    qDebug()<< "HalconBinaryProcessor";
}

