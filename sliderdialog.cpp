#include "sliderdialog.h"

// SliderDialog.cpp
#include "sliderdialog.h"

#include <QLabel>
#include <QVBoxLayout>

SliderDialog::SliderDialog(QWidget *parent) : QDialog(parent), m_slider(new QSlider(Qt::Horizontal, this)) {
    setWindowTitle("change value");
    QVBoxLayout *layout = new QVBoxLayout(this); // 创建一个垂直布局
    label = new QLabel(this);
    layout->addWidget(label);
    layout->addWidget(m_slider); // 将滑动条添加到布局中

    setLayout(layout); // 将布局设置给当前的弹窗
}

QSlider* SliderDialog::slider() const {
    return m_slider;
}

void SliderDialog::setText(QString text)
{
    label->setText(text);
}
// 设置滑动条的范围
void SliderDialog::setRange(int min, int max)
{
    m_slider->setRange(min, max);

}

void SliderDialog::setInitValue(int initValue)
{
    m_slider->setValue(initValue);
}
