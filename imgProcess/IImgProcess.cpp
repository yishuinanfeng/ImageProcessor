#include "IImgProcess.h"

IImgProcess::~IImgProcess() {
  // 实现可以为空，但是必须有实现
}


IImgProcess::IImgProcess() {
  m_sliderDialog = new SliderDialog();
}

