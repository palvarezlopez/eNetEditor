#include "flowMeasureItemConfiguration.h"

flowMeasureItemConfiguration::flowMeasureItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("csv");

    // Set filename
    setItemFileName("flowMeasures");

    // Set flowMeasure default parameters
    flowMeasureDefaultTime = 0;
    flowMeasureDefaultQPKW = 0;
    flowMeasureDefaultVPKW = 0;
    flowMeasureDefaultQLKW = 0;
    flowMeasureDefaultVLKW = 0;
}

flowMeasureItemConfiguration::~flowMeasureItemConfiguration()
{
    // Nothing to erase
}

int flowMeasureItemConfiguration::getFlowMeasureDefaultTime() const
{
    return flowMeasureDefaultTime;
}
qreal flowMeasureItemConfiguration::getFlowMeasureDefaultQPKW() const
{
    return flowMeasureDefaultQPKW;
}

qreal flowMeasureItemConfiguration::getFlowMeasureDefaultVPKW() const
{
    return flowMeasureDefaultVPKW;
}

qreal flowMeasureItemConfiguration::getFlowMeasureDefaultQLKW() const
{
    return flowMeasureDefaultQLKW;
}

qreal flowMeasureItemConfiguration::getFlowMeasureDefaultVLKW() const
{
    return flowMeasureDefaultVLKW;
}
