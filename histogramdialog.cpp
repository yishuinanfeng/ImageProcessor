#include "histogramdialog.h"

#include <QVBoxLayout>



HistogramDialog::HistogramDialog(QWidget *parent) : QDialog(parent)
{
    this->resize(400,400);
    QHBoxLayout  *layout = new QHBoxLayout(this); // 创建一个垂直布局

    originallabel = new QLabel(this);
    equalizationlabel = new QLabel(this);
//    QSizePolicy sizePolicy;
//    sizePolicy.setHorizontalPolicy(QSizePolicy::Preferred);
//    sizePolicy.setVerticalPolicy(QSizePolicy::Preferred);
    originallabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    equalizationlabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
//    label->setSizePolicy(sizePolicy);
    originallabel->resize(200,400);
    equalizationlabel->resize(200,400);
    layout->addWidget(originallabel);
    layout->addWidget(equalizationlabel);
    setLayout(layout);
}

void HistogramDialog::getHistogramImage(HalconCpp::HObject  &ho_GrayImage,
                                       HalconCpp::HObject &ho_outputImg)
{
    HalconCpp::HObject ho_Domain, ho_Region,ho_ImageEqualized;
    // Local control variables
    HalconCpp::HTuple  hv_Histo, hv_BinSize;
    GetDomain(ho_GrayImage, &ho_Domain);
    /* ho_Domain: 输入的域对象，表示图像的定义域。
       ho_GrayImage: 输入的灰度图像。
       0: 灰度直方图的起始灰度值。
       255: 灰度直方图的结束灰度值。
       256: 灰度直方图的灰度级数。
       hv_Histo: 输出的灰度直方图。
       hv_BinSize: 输出的灰度直方图的灰度级大小。  */
    GrayHistoRange(ho_Domain, ho_GrayImage, 0, 255, 256, &hv_Histo, &hv_BinSize);
    //将灰度直方图转换为区域对象
    /* ho_Region: 输出的区域对象，用于表示直方图的区域。
       hv_Histo: 输入的灰度直方图。
       255: 区域的高度。
       255: 区域的宽度。
       1: 区域的灰度级。 */
    GenRegionHisto(&ho_Region, hv_Histo, 255, 255, 1);
    /* ho_Region: 输入的区域对象。
       ho_outputImg: 输出的二值化图像。
       255: 用于生成二值化图像的灰度阈值。
       0: 输出图像的最小灰度值。
       512: 输出图像的宽度。
       512: 输出图像的高度。 */
    RegionToBin(ho_Region, &ho_outputImg, 255, 0, 512, 512);
}

void HistogramDialog::showImage(HalconCpp::HObject &image,QLabel * label,
                                HalconCpp::HTuple &hHandle)
{

    Hlong winID = label->winId();
    HalconCpp::CloseWindow(hHandle);
    HalconCpp::OpenWindow(0,0,label->width(),label->height()
                              ,winID,"visible","white",&hHandle);
    HalconCpp::DispObj(image,hHandle);
}

void HistogramDialog::showHistogramImage(HalconCpp::HObject &ho_originImg,
                                         HalconCpp::HObject &outputEuqlizationImage)
{
    qDebug()<< "HistogramDialog showHistogramImage";
    // Local iconic variables
     HalconCpp::HObject  ho_GrayImage, ho_Domain, ho_Region,ho_outputImg,ho_ImageEqualized;



     Rgb1ToGray(ho_originImg, &ho_GrayImage);
     getHistogramImage(ho_GrayImage,ho_outputImg);

     qDebug()<< "RegionToBin";


    qDebug()<< "showImag:";
    showImage(ho_outputImg,originallabel,hOriginalHandle);

    HalconCpp::HObject histogramImage;
    //直方图均衡化
    HalconCpp::EquHistoImage(ho_GrayImage, &outputEuqlizationImage);
    //获得直方图图像
    getHistogramImage(outputEuqlizationImage,histogramImage);
    showImage(histogramImage,equalizationlabel,hEqualizationHandle);

    this->show();
}
