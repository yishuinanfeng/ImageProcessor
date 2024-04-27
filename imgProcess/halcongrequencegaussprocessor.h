#ifndef HALCONGREQUENCEGAUSSPROCESSOR_H
#define HALCONGREQUENCEGAUSSPROCESSOR_H

#include "halconsourceprocessor.h"
#include "halconcpp/HalconCpp.h"
#include "halconsourceprocessor.h"
#include <halconcpp/HTuple.h>
#include <halconcpp/HException.h>
#include <halconcpp/HObject.h>

class HalconFrequenceGaussProcessor : public HalconSourceProcessor
{
public:
    HalconFrequenceGaussProcessor(HalconCpp::HObject &img);

private:
    int Sigma = 5;
public:

    void get_frequence_gauss_filter_img (HalconCpp::HObject ho_originImg, HalconCpp::HObject &ho_outputImg, HalconCpp::HTuple hv_radius);

    virtual void realExecute() override;
    virtual void reExecuteProcess() override;

private:
    void get_frequence_gauss_img (HalconCpp::HObject ho_originImg, HalconCpp::HObject  &ho_outputImg
                                  );
private slots:
        void onFreGaussFilterKernelSizeChange(int size);

};

#endif // HALCONGREQUENCEGAUSSPROCESSOR_H
