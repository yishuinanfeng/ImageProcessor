#include "imageselector.h"

ImageSelector::ImageSelector(class QWidget *parent) {
    resize(400, 200);
    auto *layout = new QVBoxLayout(this);
    auto *btn = new QPushButton("选择图片", this);
//    imageLabel = new QLabel("图片将在这里显示", this);
//    imageLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(btn);
//    layout->addWidget(imageLabel);

    connect(btn, &QPushButton::clicked, this, &ImageSelector::openImageFile);
}


void ImageSelector::openImageFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "选择图片", "", "Images (*.png *.xpm *.jpg)");
    if (!filePath.isEmpty()) {
      //  QPixmap pixmap(filePath);
       // imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        if (!filePath.isEmpty()) {
           emit imagePathSelected(filePath); // 发射信号，传递图片路径
           this->close(); // 关闭当前窗口
        }
    }
}

