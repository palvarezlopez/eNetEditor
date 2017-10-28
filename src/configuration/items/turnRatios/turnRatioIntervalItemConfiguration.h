#ifndef TURNRATIOINTERVALITEMCONFIGURATION_H
#define TURNRATIOINTERVALITEMCONFIGURATION_H

#include "abstractTurnRatioItemConfiguration.h"


class turnRatioIntervalItemConfiguration : public abstractTurnRatioItemConfiguration
{
public:

    turnRatioIntervalItemConfiguration();

    const QColor &getPlotEdgeColor(int index);


private:

    QVector<QColor> vectorOfColor;

};

#endif // TURNRATIOINTERVALITEMCONFIGURATION_H
