#ifndef IIMGPROCESS_H
#define IIMGPROCESS_H

#include <sliderdialog.h>

#include <QMap>
#include <QString>
#include "halconcpp/HalconCpp.h"
#include <halconcpp/HTuple.h>
#include <halconcpp/HException.h>
#include <QDebug>
#include "hdevengine/HDevEngineCpp.h"




// IImgProcess.h
/* 图像处理逻辑类顶层抽象类，子类再实现具体执行图像处理库逻辑*/
class IImgProcess :public QObject{
    Q_OBJECT
public:
       IImgProcess();
       virtual ~IImgProcess() = 0; // 纯虚析构函数
       virtual void executeProcess() = 0;//处理图像，该函数内部不能修改任何成员变量（除非这些成员变量被声明为mutable）
       virtual void reExecuteProcess() = 0;//用于刷新图像，比如使用滑动条调图像数值
protected:
     SliderDialog *m_sliderDialog;

public: signals:
    void imageProcessDone(const HalconCpp::HObject &processImg,boolean needOp); // 定义信号

};




#endif // IIMGPROCESS_H
