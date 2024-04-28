#ifndef HALCONDYNTHRESPROCESSOR_H
#define HALCONDYNTHRESPROCESSOR_H

#include "halconsourceprocessor.h"
/* dyn_threshold是一个动态阈值分割算子，
 * 它会根据图像的局部特性（如像素周围的灰度值分布）
 * 来自动计算每个像素的阈值。这种方法特别适用于背景和前景亮度不均
 * 、存在阴影或光照条件不均匀的情况 */
class HalconDynThresProcessor : public HalconSourceProcessor
{
public:
    HalconDynThresProcessor(HalconCpp::HObject &img);

private:
    int offset = 5;
public:
    virtual void realExecute() override;
    virtual void reExecuteProcess() override;

private:
    void get_dyn_threshold_img (HalconCpp::HObject ho_originImg, HalconCpp::HObject  &ho_outputImg
                                  );
private slots:
        void onOffsetChange(int offset);
};

#endif // HALCONDYNTHRESPROCESSOR_H
