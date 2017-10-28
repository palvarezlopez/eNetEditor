#include "abstractVehicleItemConfiguration.h"

eNetEditorVehicleConfiguration::eNetEditorVehicleConfiguration() : eNetEditorItemConfiguration()
{
    // Set vehicle defaults values
    vehicleDefaultColor = "white";
    vehicleDefaultDepartLane = "first";
    vehicleDefaultDepartPos = "0";
    vehicleDefaultDepartSpeed = "0";
    vehicleDefaultArrivalLane = "0";
    vehicleDefaultArrivalPos = "0";
    vehicleDefaultArrivalSpeed = "0";
    vehicleDefaultLine = "";
    vehicleDefaultPersonNumber = 0;
    vehicleDefaultContainerNumber = 0;
}

eNetEditorVehicleConfiguration::~eNetEditorVehicleConfiguration()
{
    // Nothing to erase
}

const QString &eNetEditorVehicleConfiguration::getVehicleDefaultColor() const
{
    return vehicleDefaultColor;
}

const QString &eNetEditorVehicleConfiguration::getVehicleDefaultDepartLane() const
{
    return vehicleDefaultDepartLane;
}

const QString &eNetEditorVehicleConfiguration::getVehicleDefaultDepartPos() const
{
    return vehicleDefaultDepartPos;
}

const QString &eNetEditorVehicleConfiguration::getVehicleDefaultDepartSpeed() const
{
    return vehicleDefaultDepartSpeed;
}

const QString &eNetEditorVehicleConfiguration::getVehicleDefaultArrivalLane() const
{
    return vehicleDefaultArrivalLane;
}

const QString &eNetEditorVehicleConfiguration::getVehicleDefaultArrivalPos() const
{
    return vehicleDefaultArrivalPos;
}

const QString &eNetEditorVehicleConfiguration::getVehicleDefaultArrivalSpeed() const
{
    return vehicleDefaultArrivalSpeed;
}

const QString &eNetEditorVehicleConfiguration::getVehicleDefaultLine() const
{
    return vehicleDefaultLine;
}

int eNetEditorVehicleConfiguration::getVehicleDefaultPersonNumber() const
{
    return vehicleDefaultPersonNumber;
}

int eNetEditorVehicleConfiguration::getVehicleDefaultContainerNumber() const
{
    return vehicleDefaultContainerNumber;
}
