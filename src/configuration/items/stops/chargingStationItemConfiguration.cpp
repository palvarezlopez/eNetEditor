#include "chargingStationItemConfiguration.h"

chargingStationItemConfiguration::chargingStationItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set Item Altitude
    setItemAltitude(4);

    // Set item pen size
    setItemPenSize(0);

    // Set filename
    setItemFileName("chargingStations");

    // Set Text font
    setItemTextFont("arial");

    // Set Text Size
    setItemTextSize(1);

    // Set Color
    setItemTextPenColor("black");

    // Set Text Pen size
    setItemTextPenSize(0);

    // Set Charging Stations defaults values
    chargingStationDefaultStartPos = 0;
    chargingStationDefaultEndPos = 10;
    chargingStationDefaultChrgPower = 220000;
    chargingStationDefaultEfficiency = 0.95;
    chargingStationDefaultChargeInTransit = 0;
    chargingStationDefaultChargeDelay = 0;
}

chargingStationItemConfiguration::~chargingStationItemConfiguration()
{
    // Nothing to erase
}


qreal chargingStationItemConfiguration::getChargingStationDefaultStartPos() const
{
    return chargingStationDefaultStartPos;
}

qreal chargingStationItemConfiguration::getChargingStationDefaultEndPos() const
{
    return chargingStationDefaultEndPos;
}

qreal chargingStationItemConfiguration::getChargingStationDefaultChrgPower() const
{
    return chargingStationDefaultChrgPower;
}

qreal chargingStationItemConfiguration::getChargingStationDefaultEfficiency() const
{
    return chargingStationDefaultEfficiency;
}

qreal chargingStationItemConfiguration::getChargingStationDefaultChargeInTransit() const
{
    return chargingStationDefaultChargeInTransit;
}

qreal chargingStationItemConfiguration::getChargingStationDefaultChargeDelay() const
{
    return chargingStationDefaultChargeDelay;
}
