#ifndef IMAGESELECTOR_H
#define IMAGESELECTOR_H

#include <QLabel>
#include <QWidget>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPixmap>

/*** 本地图片选择器 ***/
class ImageSelector : public QWidget
{
    Q_OBJECT
public:
    explicit ImageSelector(QWidget *parent = nullptr);

signals:
    void imagePathSelected(const QString &path); // 定义信号
private:
    QLabel *imageLabel;

    QObject * QWidget;
//signals:
    void openImageFile();
};

#endif // IMAGESELECTOR_H
