#include "laneItemConfiguration.h"

// Vehicle Type configuration
#include "vehicleTypeItemConfiguration.h"


laneItemConfiguration::laneItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set Item Altitude
    setItemAltitude(2);

    // Set item pen size
    setItemPenSize(0);

    // Set Text font
    setItemTextFont("arial");

    // Set Text Size
    setItemTextSize(1);

    // Set Color
    setItemPenColor("gray");

    // Set Text Pen size
    setItemTextPenSize(0);

    // Set Lanes Width
    laneWidth = 2;
    laneOffset = 1;
    laneRectHeight = 0.5;

    // Set default parameter allowed vehicles
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassBicycle );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassMoped );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassMotorcycle );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassPrivate );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassHov );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassEvehicle );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassPassenger );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassCoach );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassBus );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassDelivery );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassTruck );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassTrailer );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassTaxi );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassEmergency );
    laneDefaultListOfAllowedVehicles.push_back( vehicleClassArmy );
}

laneItemConfiguration::~laneItemConfiguration()
{
    // Nothing to erase
}

qreal laneItemConfiguration::getLaneWidth() const
{
    return laneWidth;
}

qreal laneItemConfiguration::getLaneOffset() const
{
    return laneOffset;
}

qreal laneItemConfiguration::getLaneRectHeight() const
{
    return laneRectHeight;
}

const QList<vehicleClass> &laneItemConfiguration::getLaneDefaultListOfAllowedVehicles() const
{
    return laneDefaultListOfAllowedVehicles;
}

const QList<vehicleClass> &laneItemConfiguration::getLaneDefaultListOfDisallowedVehicles() const
{
    return laneDefaultListOfDisallowedVehicles;
}

