
#include "halconscripthandler.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QObject>
#include <imgProcess/halcongrayprocessor.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    selector = new ImageSelector();
    halconScriptHandler = new HalconScriptHandler(parent,ui);
    halconScriptHandler->init();
    QObject::connect(selector, &ImageSelector::imagePathSelected, halconScriptHandler, &HalconScriptHandler::ShowImgByHalcon);

}

MainWindow::~MainWindow()
{
    HDevEngineCpp::HDevEngine().StopDebugServer();
    delete halconScriptHandler;
    delete ui;
}

void MainWindow::on_showImg_clicked()
{

    selector->show();

    qDebug()<< "selector->show()";

}

//void MainWindow::mousePressEvent(QMouseEvent *event) {
//    event->ignore(); // 阻止窗口处理鼠标事件
//}



