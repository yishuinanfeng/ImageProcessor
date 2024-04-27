#ifndef HALCONHISTOGRAMPROCESSOR_H
#define HALCONHISTOGRAMPROCESSOR_H

#include "halconsourceprocessor.h"

#include <histogramdialog.h>

class HalconHistogramProcessor : public HalconSourceProcessor
{
public:
    HalconHistogramProcessor(HalconCpp::HObject &img);

public:
    virtual void realExecute() override;
    void histogramEqualization();
private:
    HistogramDialog *histogramDialog = nullptr;
};

#endif // HALCONHISTOGRAMPROCESSOR_H
