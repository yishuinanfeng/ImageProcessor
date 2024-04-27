#include "utils.h"



Utils::Utils()
{

}

void Utils::convertQStringToHTuple(const QString& qString, HalconCpp::HTuple& hTuple) {
    // 第一步：将QString转换为std::string
    std::string stdString = qString.toStdString();

    // 第二步：将std::string转换为const char*，然后构造HTuple
    hTuple = HalconCpp::HTuple(stdString.c_str());
}
