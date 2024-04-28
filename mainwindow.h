#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



#include "halconcpp/HalconCpp.h"
#include <halconcpp/HTuple.h>
#include "imageselector.h"
#include "utils.h"

#include <halconcpp/HException.h>
#include <QDebug>
#include "hdevengine/HDevEngineCpp.h"
#include "halconscripthandler.h"

#include <imgProcess/HalconScriptProcesser.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    
//    void mousePressEvent(QMouseEvent *event) override;
private slots:

    void on_showImg_clicked();

private:
    Ui::MainWindow *ui;    
    ImageSelector *selector;
    HalconScriptHandler *halconScriptHandler;

    void executeHalconProcess(QString &methodName);
};
#endif // MAINWINDOW_H
