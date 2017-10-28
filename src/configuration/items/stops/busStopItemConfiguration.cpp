#include "busStopItemConfiguration.h"

busStopItemConfiguration::busStopItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set Item Altitude
    setItemAltitude(4);

    // Set item pen size
    setItemPenSize(0);

    // Set filename
    setItemFileName("busStops");

    // Set Text font
    setItemTextFont("arial");

    // Set Text Size
    setItemTextSize(1);

    // Set Color
    setItemTextPenColor("white");

    // Set Text Pen size
    setItemTextPenSize(0);

    // Set Bus Stops defaults values
    busStopDefaultStartPos = 0;
    busStopDefaultEndPos = 10;
    busStopDefaultLines = "";
}

busStopItemConfiguration::~busStopItemConfiguration()
{
    // Nothing to erase
}

qreal busStopItemConfiguration::getBusStopDefaultStartPos() const
{
    return busStopDefaultStartPos;
}

qreal busStopItemConfiguration::getBusStopDefaultEndPos() const
{
    return busStopDefaultEndPos;
}

const QString &busStopItemConfiguration::getBusStopDefaultLines() const
{
    return busStopDefaultLines;
}

