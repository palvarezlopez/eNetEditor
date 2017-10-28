#include "laneAreaE2DetectorItemConfiguration.h"

laneAreaE2DetectorItemConfiguration::laneAreaE2DetectorItemConfiguration() : eNetEditorDetectorConfiguration()
{
    // Set Item Altitude
    setItemAltitude(4);

    // Set item pen size
    setItemPenSize(0);

    // Set filename
    setItemFileName("laneAreaDetectorsE2");

    // Set extension
    setItemFileExtension("xml");

    // Set Text font
    setItemTextFont("arial");

    // Set Text Size
    setItemTextSize(1);

    // Set Color
    setItemTextPenColor("white");

    // Set Text Pen size
    setItemTextPenSize(0);

    // LaneAreaE2DetectorItem default parameters
    laneAreaE2DetectorItemDefaultFriendlyPos = false;
    laneAreaE2DetectorItemDefaultCont = false;
    laneAreaE2DetectorItemDefaultTimeThreshold = 1;
    laneAreaE2DetectorItemDefaultSpeedThreshold = 5 / 3.6;
    laneAreaE2DetectorItemDefaultJamThreshold = 10;
}

laneAreaE2DetectorItemConfiguration::~laneAreaE2DetectorItemConfiguration()
{
    // Nothing to erase
}

bool laneAreaE2DetectorItemConfiguration::getLaneAreaE2DetectorItemDefaultFriendlyPos()
{
    return laneAreaE2DetectorItemDefaultFriendlyPos;
}

bool laneAreaE2DetectorItemConfiguration::getLaneAreaE2DetectorItemDefaultCont()
{
    return laneAreaE2DetectorItemDefaultCont;
}

int laneAreaE2DetectorItemConfiguration::getLaneAreaE2DetectorItemDefaultTimeThreshold()
{
    return laneAreaE2DetectorItemDefaultTimeThreshold;
}

qreal laneAreaE2DetectorItemConfiguration::getLaneAreaE2DetectorItemDefaultSpeedThreshold()
{
    return laneAreaE2DetectorItemDefaultSpeedThreshold;
}

qreal laneAreaE2DetectorItemConfiguration::getLaneAreaE2DetectorItemDefaultJamThreshold()
{
    return laneAreaE2DetectorItemDefaultJamThreshold;
}


