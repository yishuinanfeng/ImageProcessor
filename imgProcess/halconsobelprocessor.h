#ifndef HALCONSOBELPROCESSOR_H
#define HALCONSOBELPROCESSOR_H

#include "halconsourceprocessor.h"
#include "halconsourceprocessor.h"
#include "halconcpp/HalconCpp.h"
#include "halconsourceprocessor.h"
#include <halconcpp/HTuple.h>
#include <halconcpp/HException.h>
#include <halconcpp/HObject.h>
/* sobel边缘检测 */
class HalconSobelProcessor : public HalconSourceProcessor
{
public:
    HalconSobelProcessor(HalconCpp::HObject &img);

private:
    int sobelSize = 5;
public:
    virtual void realExecute() override;
    virtual void reExecuteProcess() override;

private:
    void get_sobel_detect_img (HalconCpp::HObject ho_originImg, HalconCpp::HObject  &ho_outputImg
                                  );
private slots:
        void onSobelKernelSizeChange(int size);
};

#endif // HALCONSOBELPROCESSOR_H
