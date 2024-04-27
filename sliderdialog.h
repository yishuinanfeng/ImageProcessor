#ifndef SLIDERDIALOG_H
#define SLIDERDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QSlider>
/* 带有滑动条的对话框 */
class SliderDialog : public QDialog {
    Q_OBJECT

public:
    explicit SliderDialog(QWidget *parent = nullptr);
    QSlider* slider() const;
    void setText(QString text);
    void setRange(int min,int max);
    void setInitValue(int initValue);

private:
    QSlider *m_slider;
    QLabel *label;
};
#endif // SLIDERDIALOG_H
