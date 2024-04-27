#ifndef HALCONCANNYDETECTPROCESSOR_H
#define HALCONCANNYDETECTPROCESSOR_H

#include "HalconScriptProcesser.h"

class HalconCannyDetectprocessor : public HalconScriptProcesser
{
public:
    HalconCannyDetectprocessor(HalconCpp::HObject &img);
};

#endif // HALCONCANNYDETECTPROCESSOR_H
