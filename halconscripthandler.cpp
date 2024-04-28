#include "halconscripthandler.h"

#include "imgProcess/halcongrayprocessor.h"

#include <imgProcess/halconbinaryprocessor.h>
#include <imgProcess/halconcannydetectprocessor.h>
#include <imgProcess/halcondynthresprocessor.h>
#include <imgProcess/halcongaussprocesser.h>
#include <imgProcess/halcongrequencegaussprocessor.h>
#include <imgProcess/halconhistogramprocessor.h>
#include <imgProcess/halconmeanprocessor.h>
#include <imgProcess/halconmedianprocessor.h>
#include <imgProcess/halconsobelprocessor.h>
#include <imgProcess/halconsourceprocessor.h>
#include <imgProcess/halconthresholdprocessor.h>


HalconScriptHandler::HalconScriptHandler(QObject *parent,Ui::MainWindow *ui)
    : QObject(parent),ui(ui)
{

}

HalconScriptHandler::~HalconScriptHandler()
{
    delete halconProcesser;
}

void HalconScriptHandler::startProcess()
{
    if(halconProcesser == nullptr){
        return;
    }
    connectProcessorCallback(halconProcesser);
    halconProcesser->executeProcess();

    //    delete(halconProcesser);
}

void HalconScriptHandler::init()
{


    try{
        QString scriptPath = QCoreApplication::applicationDirPath() + "/../../halconScript/";
        qDebug()<< "scriptPath:" << scriptPath.toStdString().c_str();
        HDevEngineCpp::HDevEngine().SetProcedurePath(scriptPath.toStdString().c_str());

    }catch(HalconCpp::HException &Exception)
    {
        qDebug() << "Exception.ProcNam:" << Exception.ProcName().Text(); //实际的HALCON算子的名字
        qDebug()<< "Exception.ErrorMessage:" << Exception.ErrorMessage().Text(); //错误信息
        qDebug()<< "Exception.ErrorCode:" << Exception.ErrorCode(); //错误码
    }


    connect(ui->actiongray,&QAction::triggered,this,[=]() mutable{
        qDebug()<< "actiongray";

        //        QString methodName = "get_gray_picture";
        //executeHalconProcess(methodName);
        if(!isImgLoaded){
            qDebug()<< "load image first!";
            return ;
        }


        halconProcesser = new HalconGrayProcessor(currentImg);
        startProcess();
    });

    connect(ui->actionBinarization,&QAction::triggered,this,[=]()mutable{
        qDebug()<< "actionBinarization";
        if(!isImgLoaded){
            qDebug()<< "load image first!";
            return ;
        }
        halconProcesser = new HalconBinaryProcessor(currentImg);
        startProcess();
    });

    connect(ui->actionCanny,&QAction::triggered,this,[=]()mutable{
        qDebug()<< "actionCanny";
        if(!isImgLoaded){
            qDebug()<< "load image first!";
            return ;
        }
        halconProcesser = new HalconCannyDetectprocessor(currentImg);
        startProcess();
    });

    connect(ui->actionmean,&QAction::triggered,this,[=](){
        qDebug()<< "actionmean";
        if(!isImgLoaded){
            qDebug()<< "load image first!";
            return ;
        }
        halconProcesser = new HalconMeanProcessor(currentImg);
        startProcess();

    });


    connect(ui->actionSobel,&QAction::triggered,this,[=](){
        qDebug()<< "actionSobel";

        if(!isImgLoaded){
            qDebug()<< "load image first!";
            return ;
        }

        halconProcesser = new HalconSobelProcessor(currentImg);
        qDebug()<< "connect halconSobelProcessor";

        connectProcessorCallback(halconProcesser);

        //        QObject::connect(halconProcesser, &HalconSobelProcessor::imageProcessDone,
        //                         this, &HalconScriptHandler::onImgProcessed);
        //        halconSobelProcessor->executeProcess();
        startProcess();

    });

    connect(ui->actionmedian,&QAction::triggered,this,[=](){
        qDebug()<< "actionmedian";
        if(!isImgLoaded){
            qDebug()<< "load image first!";
            return ;
        }
        halconProcesser = new HalconMedianProcessor(currentImg);
        qDebug()<< "connect HalconSourceProcessor";
        connectProcessorCallback(halconProcesser);
        startProcess();
    });

    connect(ui->actionHSVThred,&QAction::triggered,this,[=](){
        qDebug()<< "actionHSVThred";
    });


    connect(ui->actionRGBThred,&QAction::triggered,this,[=](){
        qDebug()<< "actionRGBThred";
        if(!isImgLoaded){
            qDebug()<< "load image first!";
            return ;
        }

        halconProcesser = new HalconThresholdProcessor(currentImg);
        qDebug()<< "connect HalconSourceProcessor";
        connectProcessorCallback(halconProcesser);
        startProcess();

    });


    connect(ui->actionequlization,&QAction::triggered,this,[=](){
        qDebug()<< "actionequlization";

        if(!isImgLoaded){
            qDebug()<< "load image first!";
            return ;
        }

        halconProcesser = new HalconHistogramProcessor(currentImg);
        qDebug()<< "connect HalconSourceProcessor";
        connectProcessorCallback(halconProcesser);
        startProcess();

    });


    connect(ui->actionadapter,&QAction::triggered,this,[=](){
        qDebug()<< "actionadapter";
    });

    connect(ui->actiondilate,&QAction::triggered,this,[=](){
        qDebug()<< "actiondilate";
    });

    connect(ui->actioncorrosion,&QAction::triggered,this,[=](){
        qDebug()<< "actioncorrosion";
    });

    connect(ui->actionblackHat,&QAction::triggered,this,[=](){
        qDebug()<< "actionblackHat";
    });

    connect(ui->actionlocal,&QAction::triggered,this,[=](){
        qDebug()<< "actionlocal";


        halconProcesser = new HalconDynThresProcessor(currentImg);
        qDebug()<< "connect HalconDynThresProcessor";
        connectProcessorCallback(halconProcesser);
        startProcess();
    });

    connect(ui->actiongau,&QAction::triggered,this,[=](){
        qDebug()<< "actiongau";
        if(!isImgLoaded){
            qDebug()<< "load image first!";
            return ;
        }


        halconProcesser = new HalconGaussProcesser(currentImg);
        connectProcessorCallback(halconProcesser);
        startProcess();
    });

    connect(ui->actionfrequenceGaussFilter,&QAction::triggered,this,[=](){
        qDebug()<< "actionfrequenceGaussFilter";

        halconProcesser = new HalconFrequenceGaussProcessor(currentImg);
        qDebug()<< "connect HalconSourceProcessor";
        connectProcessorCallback(halconProcesser);
        startProcess();
    });

    connect(ui->actiontopHat,&QAction::triggered,this,[=](){
        qDebug()<< "actiontopHat";
    });

    connect(ui->actionmean,&QAction::triggered,this,[=](){
        qDebug()<< "actiongray";
    });

    connect(ui->actionmedian,&QAction::triggered,this,[=](){
        qDebug()<< "actiongray";
    });

    connect(ui->actiondashBoard,&QAction::triggered,this,[=](){
        qDebug()<< "actiondashBoard";

        dashBoardShower = new DashBoardShower();
        dashBoardShower->show();
    });
}

void HalconScriptHandler::ShowImgByHalcon(const QString &ImgPath)
{
    qDebug()<< "ImgPath:" << ImgPath;

    try{

        HalconCpp::HObject hImg;
        HalconCpp::HTuple filePathTuiple;
        //        utils.convertQStringToHTuple(*fileImg,filePathTuiple);
        utils.convertQStringToHTuple(ImgPath,filePathTuiple);

        ///这里有坑！！要先ReadImage再OpenWindow图片尺寸才能正常
        HalconCpp::ReadImage(&hImg,filePathTuiple);
        //        HalconCpp::ReadImage(&hImg,"../image/haha.jpg");

        Hlong winID = ui->displayWidget->winId();
        HalconCpp::OpenWindow(0,0,ui->displayWidget->width(),ui->displayWidget->height()
                              ,winID,"visible","black",&hHandle);
        HalconCpp::DispObj(hImg,hHandle);

        currentImg = hImg;

        isImgLoaded = true;

        //        HalconCpp::HObject hImgResized;
        //        HalconCpp::ZoomImageSize(hImg, &hImgResized, ui->displayWidget->width()
        //                                 ,ui->displayWidget->height(),"constant");
        //        currentImg = hImgResized;

        //        HalconCpp::DispObj(hImg,hHandle);

        //        HalconCpp::DispObj(hImgResized,hHandle);

        //        HalconCpp::HTuple width,height;
        //        HalconCpp::GetImageSize(hImg, &width, &height);
        //        // 获取宽度和高度的整数值
        //        int widthValue = width[0].I();
        //        int heightValue = height[0].I();
        //        qDebug()<< "hImg width:" << widthValue;
        //        qDebug()<< "hImg height:" << heightValue;

        //        HalconCpp::GetImageSize(currentImg, &width, &height);
        //        // 获取宽度和高度的整数值
        //        int widthValueResized = width[0].I();
        //        int heightValueResized = height[0].I();

        //         qDebug()<< "currentImg width:" << widthValueResized;
        //         qDebug()<< "currentImg height:" << heightValueResized;

        //         qDebug()<< "displayWidget width:" << ui->displayWidget->width();
        //         qDebug()<< "displayWidget height:" << ui->displayWidget->height();

        //        qDebug()<< "after ReadImage";

        //        QString methodName = "get_bicycle";



        // 调整图像尺寸
        //        proCall->SetInputIconicParamObject("originImg",hImgResized);



        //        HalconCpp::DispObj(hImg,hHandle);

        //        HalconCpp::GetImageSize(currentImg, &width, &height);
        //        // 获取宽度和高度的整数值
        //        int widthOutputImg = width[0].I();
        //        int heightOutputImg = height[0].I();
        //        qDebug()<< "widthOutputImg width:" << widthOutputImg;
        //        qDebug()<< "heightOutputImg height:" << heightOutputImg;

        //        HalconCpp::DispObj(hImg,hHandle);

    }catch(HalconCpp::HException &Exception)
    {
        qDebug() << "Exception.ProcNam:" << Exception.ProcName().Text(); //实际的HALCON算子的名字
        qDebug()<< "Exception.ErrorMessage:" << Exception.ErrorMessage().Text(); //错误信息
        qDebug()<< "Exception.ErrorCode:" << Exception.ErrorCode(); //错误码
    }
}

void HalconScriptHandler::connectProcessorCallback(IImgProcess *halconProcesser)
{
    if(halconProcesser != nullptr){
        qDebug()<< "connect halconScriptProcesser";
        QObject::connect(halconProcesser, &IImgProcess::imageProcessDone,
                         this, &HalconScriptHandler::onImgProcessed);
    }
}

void HalconScriptHandler::onImgProcessed(const HalconCpp::HObject &processImg,boolean needOpenWindow){
    qDebug()<< "onImgProcessed needOpenWindow:" << needOpenWindow;
    Hlong winID = ui->displayWidget->winId();
    HalconCpp::CloseWindow(hHandle);
    //   if(needOpenWindow){
    HalconCpp::OpenWindow(0,0,ui->displayWidget->width(),ui->displayWidget->height()
                          ,winID,"visible","black",&hHandle);
    //   }

    HalconCpp::DispObj(processImg,hHandle);
}

