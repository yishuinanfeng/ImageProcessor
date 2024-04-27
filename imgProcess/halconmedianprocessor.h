#ifndef HALCONMEDIANPROCESSOR_H
#define HALCONMEDIANPROCESSOR_H

#include "IImgProcess.h"
#include <QObject>
//#ifndef __APPLE__
//#  include "HalconCpp.h"
//#  include "HDevThread.h"
//#else
//#  ifndef HC_LARGE_IMAGES
//#    include <halconcpp/HalconCpp.h>
//#    include <halconcpp/HDevThread.h>
//#include <halconcpp/HObject.h>
//#include <halconcpp/HTuple.h>
//#  else
//#    include <HALCONCppxl/HalconCpp.h>
//#    include <HALCONCppxl/HDevThread.h>
//#  endif
//#endif

#include "halconcpp/HalconCpp.h"
#include "halconsourceprocessor.h"
#include <halconcpp/HTuple.h>
#include <halconcpp/HException.h>



/* HalconC++中值滤波 */
class HalconMedianProcessor : public HalconSourceProcessor
{
private:
    int medianRadius = 5;
public:
    HalconMedianProcessor(HalconCpp::HObject &img);

    void get_median_filter_img (HalconCpp::HObject ho_originImg, HalconCpp::HObject &ho_outputImg, HalconCpp::HTuple hv_radius);

    virtual void realExecute() override;
    virtual void reExecuteProcess() override;
    virtual void preExecute() override;
    virtual void afterExecute() override;

private slots:
        void onMedianFilterKernelSizeChange(int size);


};


#endif // HALCONMEDIANPROCESSOR_H
