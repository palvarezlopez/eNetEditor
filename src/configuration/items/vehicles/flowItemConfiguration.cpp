#include "flowItemConfiguration.h"

flowItemConfiguration::flowItemConfiguration() : eNetEditorVehicleConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set filename
    setItemFileName("flows");

    // Set default parameters
    begin = 0;
    end = 100;
    vehsPerHour = 100;
    period = 10;
    probability = 0.5;
    number = 100;
}

flowItemConfiguration::~flowItemConfiguration()
{
    // Nothing to erase
}

qreal flowItemConfiguration::getFlowBegin() const
{
    return begin;
}

qreal flowItemConfiguration::getFlowEnd() const
{
    return end;
}

qreal flowItemConfiguration::getFlowVehsPerHour() const
{
    return vehsPerHour;
}

qreal flowItemConfiguration::getFlowPeriod() const
{
    return period;
}

qreal flowItemConfiguration::getFlowProbability() const
{
    return probability;
}

int flowItemConfiguration::getFlowNumber() const
{
    return number;
}

