#ifndef HALCONTHRESHOLDPROCESSOR_H
#define HALCONTHRESHOLDPROCESSOR_H

#include "halconsourceprocessor.h"

class HalconThresholdProcessor : public HalconSourceProcessor
{
public:
    HalconThresholdProcessor(HalconCpp::HObject &img);
private:
    int minThres = 128,maxThres = 255;
public:
    virtual void realExecute() override;
    virtual void reExecuteProcess() override;

private:
    void get_thresHold_img (HalconCpp::HObject ho_originImg, HalconCpp::HObject  &ho_outputImg
                                  );
private slots:
        void onThresHoldChange(int minThres);
};

#endif // HALCONTHRESHOLDPROCESSOR_H
