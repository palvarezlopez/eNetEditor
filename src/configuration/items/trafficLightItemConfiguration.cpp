#include "trafficLightItemConfiguration.h"

trafficLightItemConfiguration::trafficLightItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set filename
    setItemFileName("trafficLights");

    // Fill vector with the Traffic Lights Types
    vectorOfTrafficLightsType.push_back("static");
    vectorOfTrafficLightsType.push_back("actuated");

    // SetTraffic lights Colors
    trafficLightPhaseGreenPriority = "background-color: rgb(0, 255, 0)";
    trafficLightPhaseGreen = "background-color: rgb(0, 170, 0);";
    trafficLightPhaseYellow = "background-color: rgb(255, 170, 0);";
    trafficLightPhaseRed = "background-color: rgb(255, 85, 0);";
    trafficLightPhaseBlack = "background-color: rgb(0, 0, 0);";

    // Traffic lights Colors QColor
    trafficLightColorGreenPriority.setRgb(0, 255, 0);
    trafficLightColorGreen.setRgb(0, 170, 0);
    trafficLightColorYellow.setRgb(255, 170, 0);
    trafficLightColorRed.setRgb(255, 85, 0);

    // Traffic lights defaults values
    trafficLightDefaultType = trafficLightTypeStatic;
    trafficLightDefaultOffset = 0;
    trafficLightDefaultMaxGap = 3.1;
    trafficLightDefaultPassingTime = 1.9;
    trafficLightDefaultDetectorGap = 3.0;
    trafficLightDefaultDuration = 5;
}

trafficLightItemConfiguration::~trafficLightItemConfiguration()
{
    // Nothing to erase
}

const QString &trafficLightItemConfiguration::getTrafficLightTypeValue(trafficLightType tlType) const
{
    return vectorOfTrafficLightsType.at(tlType);
}

int trafficLightItemConfiguration::getTrafficLightDefaultDuration() const
{
    return trafficLightDefaultDuration;
}
const QString &trafficLightItemConfiguration::getTrafficLightPhaseGreenPriority() const
{
    return trafficLightPhaseGreenPriority;
}

const QString &trafficLightItemConfiguration::getTrafficLightPhaseGreen() const
{
    return trafficLightPhaseGreen;
}

const QString &trafficLightItemConfiguration::getTrafficLightPhaseYellow() const
{
    return trafficLightPhaseYellow;
}

const QString &trafficLightItemConfiguration::getTrafficLightPhaseRed() const
{
    return trafficLightPhaseRed;
}

const QString &trafficLightItemConfiguration::getTrafficLightPhaseBlack() const
{
    return trafficLightPhaseBlack;
}

const QColor &trafficLightItemConfiguration::getTrafficLightColorGreenPriority() const
{
    return trafficLightColorGreenPriority;
}

const QColor &trafficLightItemConfiguration::getTrafficLightColorGreen() const
{
    return trafficLightColorGreen;
}

const QColor &trafficLightItemConfiguration::getTrafficLightColorYellow() const
{
    return trafficLightColorYellow;
}

const QColor &trafficLightItemConfiguration::getTrafficLightColorRed() const
{
    return trafficLightColorRed;
}

const trafficLightType &trafficLightItemConfiguration::getTrafficLightDefaultType() const
{
    return trafficLightDefaultType;
}

qreal trafficLightItemConfiguration::getTrafficLightDefaultOffset() const
{
    return trafficLightDefaultOffset;
}

qreal trafficLightItemConfiguration::getTrafficLightDefaultMaxGap() const
{
    return trafficLightDefaultMaxGap;
}

qreal trafficLightItemConfiguration::getTrafficLightDefaultPassingTime() const
{
    return trafficLightDefaultPassingTime;
}

qreal trafficLightItemConfiguration::getTrafficLightDefaultDetectorGap() const
{
    return trafficLightDefaultDetectorGap;
}
