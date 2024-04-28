#include "dashboardshower.h"

#include <QMouseEvent>
#include <QPainter>

DashBoardShower::DashBoardShower(QWidget *parent) : QWidget(parent)
{
    //设置窗口大小
    setFixedSize(640,480);
    //去掉问号
    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~Qt::WindowContextHelpButtonHint);
    //背景设置成黑色
    QPalette bgpal=palette();
    bgpal.setColor(QPalette::Background,QColor(0,0,0));
    setPalette(bgpal);

}

void DashBoardShower::paintEvent(QPaintEvent *event)
{
    qDebug()<< "paintEvent";
    QPainter painter(this);
    int width=this->width();
    int height=this->height();
    radius=((width>height)?height:width)/2;
    //将画笔移动到中下方
    painter.translate(width>>1,height*0.6);
    //启用反锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);
    //取消画笔
    //    painter.setPen(Qt::NoPen);
    painter.setPen(QColor(98,246,255));
    QFont font;
    font.setFamily("SimHei");
    font.setPointSize(12);
    painter.setFont(font);
    //设置画刷颜色
    painter.setBrush(QColor(98,246,255));

    drawPoint(painter,radius);
    drawDigital(painter,radius);
    drawCircle(painter,radius);
    drawSmallScale(painter,radius);
    drawBigScale(painter,radius);
    drawText(painter,radius);
    drawPointer(painter,radius);
}

void DashBoardShower::drawPoint(QPainter &painter, int radius)
{
    qDebug()<< "paintEvent";
    //组装点的路径图
    QPainterPath pointPath;
    pointPath.moveTo(-2,-2);
    pointPath.lineTo(2,-2);
    pointPath.lineTo(2,2);
    pointPath.lineTo(0,4);
    pointPath.lineTo(-2,2);
    //绘制13个小点，先移动旋转坐标系，再绘制路径
    for(int i=0;i<13;++i){
        QPointF point(0,0);
        painter.save();
        //计算并移动绘图对象中心点
        point.setX(radius*qCos(((210-i*20)*M_PI)/180));
        point.setY(radius*qSin(((210-i*20)*M_PI)/180));
        //计算并移动绘图对象的中心点（-point.y是因为qt坐标y是往下为正）
        painter.translate(point.x(),-point.y());
        //计算并旋转绘图对象坐标
        painter.rotate(-120+i*20);
        //绘制路径
        painter.drawPath(pointPath);
        painter.restore();
    }
}

void DashBoardShower::drawDigital(QPainter &painter, int radius)
{
    qDebug()<< "drawDigital";
    //绘制13个小点
    for(int i=0;i<13;++i){
        QPointF point(0,0);
        painter.save();
        //计算并移动绘图对象中心点
        point.setX(radius*qCos(((210-i*20)*M_PI)/180));
        point.setY(radius*qSin(((210-i*20)*M_PI)/180));
        //计算并移动绘图对象的中心点（-point.y是因为qt坐标y是往下为正）
        painter.translate(point.x(),-point.y());
        //计算并选择绘图对象坐标
        painter.rotate(-120+i*20);
        //绘制路径
//        qDebug()<< "drawDigital";
        painter.drawText(-15, 10, 30, 20,Qt::AlignCenter,QString::number(i*20));
        painter.restore();
    }

}

void DashBoardShower::drawCircle(QPainter &painter, int radius)
{
    //保存绘图对象
    painter.save();
    //计算大小圆路径
    QPainterPath outRing;
    QPainterPath inRing;
    outRing.moveTo(0,0);
    inRing.moveTo(0,0);
    //即在-radius,-radius, 2*radius,2*radius形成的矩形rect内，起始角度为45，逆时针转270度形成的弧。
    outRing.arcTo(-radius+grdientRadiusDiff,-radius+grdientRadiusDiff
                  , 2*(radius-grdientRadiusDiff),2*(radius-grdientRadiusDiff),-31,242);
    inRing.addEllipse(-radius+grdientRadiusDiff*1.5,-radius+grdientRadiusDiff*1.5
                      ,2*(radius-grdientRadiusDiff*1.5),2*(radius-grdientRadiusDiff*1.5));
    outRing.closeSubpath();
    //设置渐变色圆心和渐变焦点都在（0,0）
    QRadialGradient radialGradient(0,0,radius-grdientRadiusDiff,0,0);
    radialGradient.setColorAt(0.95,QColor(98,246,255));
    radialGradient.setColorAt(1,QColor(0,0,0));
    //设置渐变画刷
    painter.setBrush(radialGradient);
    //大圆减去小圆得到圆环
    painter.drawPath(outRing.subtracted(inRing));
    //恢复绘图对象
    painter.restore();
}

void DashBoardShower::drawSmallScale(QPainter &painter, int radius)
{
    //组装点的路径图
    QPainterPath pointPath;
    pointPath.moveTo(-2,-2);
    pointPath.lineTo(-1,-4);
    pointPath.lineTo(1,-4);
    pointPath.lineTo(2,-2);
    pointPath.lineTo(1,8);
    pointPath.lineTo(-1,8);
    //绘制121个小点
    for(int i=0;i<121;++i){
        QPointF point(0,0);
        painter.save();
        //计算并移动绘图对象中心点
        point.setX((radius - 80) *qCos(((210-i*2)*M_PI)/180));
        point.setY((radius - 80)*qSin(((210-i*2)*M_PI)/180));
        //计算并移动绘图对象的中心点
        painter.translate(point.x(),-point.y());
        //计算并选择绘图对象坐标
        painter.rotate(-120+i*2);
        //绘制路径
        painter.drawPath(pointPath);
        painter.restore();
    }

}

void DashBoardShower::drawBigScale(QPainter &painter, int radius)
{
    //组装点的路径图。pointPath1和pointPath2一大一小
    QPainterPath pointPath1;
    pointPath1.moveTo(-2,-2);
    pointPath1.lineTo(-1,-4);
    pointPath1.lineTo(1,-4);
    pointPath1.lineTo(2,-2);
    pointPath1.lineTo(1,8);
    pointPath1.lineTo(-1,8);
    QPainterPath pointPath2;
    pointPath2.moveTo(-2,-2);
    pointPath2.lineTo(-1,-4);
    pointPath2.lineTo(1,-4);
    pointPath2.lineTo(2,-2);
    pointPath2.lineTo(1,15);
    pointPath2.lineTo(-1,15);
    //绘制25个刻度
    for(int i=0;i<25;++i){
        QPointF point(0,0);
        painter.save();
        //计算并移动绘图对象中心点
        point.setX((radius - 100)*qCos(((210-i*10)*M_PI)/180));
        point.setY((radius - 100)*qSin(((210-i*10)*M_PI)/180));
        //计算并移动绘图对象的中心点
        painter.translate(point.x(),-point.y());
        //计算并旋转绘图对象坐标
        painter.rotate(-120+i*10);
        //绘制路径
        if(i%2){
            painter.drawPath(pointPath1);
        }
        else{
            painter.drawPath(pointPath2);
        }
        painter.restore();
    }

}

void DashBoardShower::drawText(QPainter &painter, int radius)
{
    painter.save();
    //设置画笔
    painter.setPen(QColor(98,246,255));
    //设置字体
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(16);
    painter.setFont(font);
    painter.drawText(-50, -(radius - 130), 100, 30,Qt::AlignCenter,QString("km/h"));
    painter.restore();

}

void DashBoardShower::drawPointer(QPainter &painter, int radius)
{
    //组装点的路径图
    QPainterPath pointPath;
    pointPath.moveTo(10,0);
    pointPath.lineTo(1,-(radius - 120));
    pointPath.lineTo(-1,-(radius - 120));
    pointPath.lineTo(-10,0);
    //取矩形（左上角（-10,0），右上角点（20,20））从180度位置截取180度的圆弧
    pointPath.arcTo(-10,0,20,20,180,180);
    QPainterPath inRing;
    inRing.addEllipse(-5,-5,10,10);
    painter.save();
    //计算并选择绘图对象坐标
    qDebug()<< "drawPointer angle" << angle;
    painter.rotate(angle);
    //设置画刷
    painter.setBrush(QColor(255,0,0,200));
    //绘制路径
    painter.drawPath(pointPath.subtracted(inRing));
    painter.restore();

}

void DashBoardShower::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {

        // 记录鼠标按下时的位置和控件的位置
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        qDebug()<< "mousePressEvent dragPosition" << dragPosition;
        int wCenter=this->width()/2;
        int hCenter=this->height()/2;
        if(dragPosition.x() > wCenter-radius && dragPosition.x() < wCenter+radius
                && dragPosition.y() > hCenter-radius && dragPosition.y() < hCenter+radius){
            isDragging = true;
            event->accept();
            qDebug()<< "mousePressEvent event->accept";
        }else{
            event->ignore();
            qDebug()<< "mousePressEvent event->ignore";
        }
    }
}

void DashBoardShower::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton && isDragging) {
        // 移动控件到新位置
         qDebug()<< "mouseMoveEvent event" << event;
//        move(event->globalPos() - dragPosition);
          int dx = (event->globalPos().x() - frameGeometry().topLeft().x()
                  - dragPosition.x())/6;
          qDebug()<< "mouseMoveEvent dx" << dx;
          qDebug()<< "angle + dx " << angle + dx;
          if(angle + dx >= -120 && angle + dx <= 120){
             angle = angle + dx;
          }
          QWidget::update();
          qDebug()<< "QWidget::update";
    }
}

void DashBoardShower::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // 停止拖动
        isDragging = false;
        qDebug()<< "mouseReleaseEvent event" << event;
        event->accept();
    }
}
