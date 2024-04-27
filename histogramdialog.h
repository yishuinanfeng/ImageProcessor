#ifndef HISTOGRAMDIALOG_H
#define HISTOGRAMDIALOG_H

#include <QDialog>
#include <QLabel>
#include <ui_mainwindow.h>

#include <QObject>
#include <QString>
#include "halconcpp/HalconCpp.h"
#include <halconcpp/HTuple.h>
#include <halconcpp/HException.h>
#include <QDebug>
#include "hdevengine/HDevEngineCpp.h"
#include <halconcpp/HObject.h>


class HistogramDialog : public QDialog
{
    Q_OBJECT
public:
    HistogramDialog(QWidget *parent = nullptr);
    /* 展示直方图 */
    void showHistogramImage(HalconCpp::HObject &Image,HalconCpp::HObject &equlizationImg);
    void getHistogramImage(HalconCpp::HObject  &ho_GrayImage,HalconCpp::HObject &ho_outputImg);

    void showImage(HalconCpp::HObject &image,QLabel * label,HalconCpp::HTuple &hHandle);

private:
    QLabel *originallabel;
    QLabel *equalizationlabel;
    HalconCpp::HTuple hOriginalHandle;
    HalconCpp::HTuple hEqualizationHandle;
};

#endif // HISTOGRAMDIALOG_H
