#include "halconcannydetectprocessor.h"

HalconCannyDetectprocessor::HalconCannyDetectprocessor(HalconCpp::HObject &img)
    :HalconScriptProcesser("get_canny_edge_detect",img)
{

}
