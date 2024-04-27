#ifndef HALCONMEANPROCESSOR_H
#define HALCONMEANPROCESSOR_H

#include "HalconScriptProcesser.h"
/* 均值滤波 */
class HalconMeanProcessor : public HalconScriptProcesser
{
public:
    HalconMeanProcessor(HalconCpp::HObject &img);

    /*执行图像处理前的处理*/
    virtual void preExecute() override;
    /*执行图像处理后的处理*/
    virtual void afterExecute() override;

private slots:
        void onMeanFilterKernelSizeChange(int size);
private:
    int meanSize = 3;
};

#endif // HALCONMEANPROCESSOR_H
