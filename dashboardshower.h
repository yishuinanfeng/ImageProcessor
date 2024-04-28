#ifndef DASHBOARDSHOWER_H
#define DASHBOARDSHOWER_H

#include <QWidget>
#include <QtMath>
#include <QDebug>
#include <QPainter>
/*
 * 仪表盘
 * （其实和图像处理没什么关系，只是一个额外的有趣功能）
*/
class DashBoardShower : public QWidget
{
    Q_OBJECT
public:
    explicit DashBoardShower(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

    void drawPoint(QPainter &painter,int radius);

    void drawDigital(QPainter &painter,int radius);

    void drawCircle(QPainter& painter,int radius);

    void drawSmallScale(QPainter& painter,int radius);

    void drawBigScale(QPainter& painter,int radius);

    void drawText(QPainter& painter,int radius);

    void drawPointer(QPainter& painter,int radius);

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

signals:

private:
    int grdientRadiusDiff = 40;

    bool isDragging;

    QPoint dragPosition;

    int radius = 0;

    int angle = -120;

};

#endif // DASHBOARDSHOWER_H
