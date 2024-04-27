#ifndef HALCONGRAYPROCESSOR_H
#define HALCONGRAYPROCESSOR_H

#include "HalconScriptProcesser.h"

/* 灰度图效果 */
class HalconGrayProcessor : public HalconScriptProcesser
{
public:
    HalconGrayProcessor(HalconCpp::HObject &img);
};

#endif // HALCONGRAYPROCESSOR_H
