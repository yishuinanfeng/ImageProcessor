#ifndef HALCONBINARYPROCESSOR_H
#define HALCONBINARYPROCESSOR_H

#include "HalconScriptProcesser.h"

class HalconBinaryProcessor : public HalconScriptProcesser
{
public:
    HalconBinaryProcessor(HalconCpp::HObject &img);
};

#endif // HALCONBINARYPROCESSOR_H
