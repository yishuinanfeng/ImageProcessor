#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include "halconcpp/HalconCpp.h"
#include <halconcpp/HTuple.h>



class Utils
{
public:
    Utils();

    void convertQStringToHTuple(const QString& qString, HalconCpp::HTuple& hTuple);
};

#endif // UTILS_H
