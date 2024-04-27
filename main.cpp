#include "mainwindow.h"

#include <QApplication>
#include "opencv2/opencv.hpp"
#include <opencv2/core/mat.hpp>
using namespace cv;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    Mat image=imread("E:/projects/qtProject/halconFristDemo/image/haha.jpg");
//    imshow("haha",image);
    return a.exec();
}
