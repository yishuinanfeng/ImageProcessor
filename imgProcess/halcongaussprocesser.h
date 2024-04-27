#ifndef HALCONGAUSSPROCESSER_H
#define HALCONGAUSSPROCESSER_H

#include "HalconScriptProcesser.h"

class HalconGaussProcesser : public HalconScriptProcesser
{
public:
    HalconGaussProcesser(HalconCpp::HObject &img);
    /*执行图像处理前的处理*/
    virtual void preExecute() override;
    /*执行图像处理后的处理*/
    virtual void afterExecute() override;

private slots:
        void onGaussFilterKernelSizeChange(int size);

private:
    int gaussSize = 3;
};

#endif // HALCONGAUSSPROCESSER_H
