#include "vehicleTypeItemConfiguration.h"

vehicleTypeItemConfiguration::vehicleTypeItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set filename
    setItemFileName("vehicleTypes");

    // Set number of vehicle classes
    numberOfVehicleClasses = 25;

    // Fill vector of vehicle Class
    vectorOfVehicleTypeClasses.push_back("unknown");
    vectorOfVehicleTypeClasses.push_back("bicycle");
    vectorOfVehicleTypeClasses.push_back("moped");
    vectorOfVehicleTypeClasses.push_back("motorcycle");
    vectorOfVehicleTypeClasses.push_back("private");
    vectorOfVehicleTypeClasses.push_back("hov");
    vectorOfVehicleTypeClasses.push_back("evehicle");
    vectorOfVehicleTypeClasses.push_back("passenger");
    vectorOfVehicleTypeClasses.push_back("coach");
    vectorOfVehicleTypeClasses.push_back("bus");
    vectorOfVehicleTypeClasses.push_back("delivery");
    vectorOfVehicleTypeClasses.push_back("truck");
    vectorOfVehicleTypeClasses.push_back("trailer");
    vectorOfVehicleTypeClasses.push_back("taxi");
    vectorOfVehicleTypeClasses.push_back("emergency");
    vectorOfVehicleTypeClasses.push_back("army");
    vectorOfVehicleTypeClasses.push_back("NOTIMPLEMENTED");
    vectorOfVehicleTypeClasses.push_back("NOTIMPLEMENTED");
    vectorOfVehicleTypeClasses.push_back("NOTIMPLEMENTED");
    vectorOfVehicleTypeClasses.push_back("NOTIMPLEMENTED");
    vectorOfVehicleTypeClasses.push_back("NOTIMPLEMENTED");
    vectorOfVehicleTypeClasses.push_back("NOTIMPLEMENTED");
    vectorOfVehicleTypeClasses.push_back("NOTIMPLEMENTED");
    vectorOfVehicleTypeClasses.push_back("NOTIMPLEMENTED");
    vectorOfVehicleTypeClasses.push_back("NOTIMPLEMENTED");
    vectorOfVehicleTypeClasses.push_back("NOTIMPLEMENTED");

    // Fill vector of vehicle shapes
    vectorOfvehicleTypeShapes.push_back("unknown");
    vectorOfvehicleTypeShapes.push_back("pedestrian");
    vectorOfvehicleTypeShapes.push_back("bicycle");
    vectorOfvehicleTypeShapes.push_back("motorcycle");
    vectorOfvehicleTypeShapes.push_back("passenger");
    vectorOfvehicleTypeShapes.push_back("passenger/sedan");
    vectorOfvehicleTypeShapes.push_back("passenger/hatchback");
    vectorOfvehicleTypeShapes.push_back("passenger/wagon");
    vectorOfvehicleTypeShapes.push_back("passenger/van");
    vectorOfvehicleTypeShapes.push_back("delivery");
    vectorOfvehicleTypeShapes.push_back("transport");
    vectorOfvehicleTypeShapes.push_back("transport/semitrailer");
    vectorOfvehicleTypeShapes.push_back("transport/trailer");
    vectorOfvehicleTypeShapes.push_back("bus");
    vectorOfvehicleTypeShapes.push_back("bus/city");
    vectorOfvehicleTypeShapes.push_back("bus/flexible");
    vectorOfvehicleTypeShapes.push_back("bus/overland");
    vectorOfvehicleTypeShapes.push_back("rail");
    vectorOfvehicleTypeShapes.push_back("rail/light");
    vectorOfvehicleTypeShapes.push_back("rail/city");
    vectorOfvehicleTypeShapes.push_back("rail/slow");
    vectorOfvehicleTypeShapes.push_back("rail/fast");
    vectorOfvehicleTypeShapes.push_back("rail/cargo");
    vectorOfvehicleTypeShapes.push_back("evehicle");

    // Fill vector with the vehicle emissions
    vectorOfVehicleTypeEmissions.push_back("P_7_7");

    // Set vehicle type defaults values
    vehicleTypeDefaultVClass = vehicleClassUnknown;
    vehicleTypeDefaultAccel = 2.6;
    vehicleTypeDefaultDecel = 4.5;
    vehicleTypeDefaultSigma = 0.5;
    vehicleTypeDefaultTau = 1.0;
    vehicleTypeDefaultLength = 5.0;
    vehicleTypeDefaultMinGap = 2.5;
    vehicleTypeDefaultMaxSpeed = 70.0;
    vehicleTypeDefaultSpeedFactor = 1.0;
    vehicleTypeDefaultSpeedDev = 0.0;
    vehicleTypeDefaultColor = "0;0;1";
    vehicleTypeDefaultEmissionClass = "P_7_7";
    vehicleTypeDefaultguiShape = vehicleShapeUnknown;
    vehicleTypeDefaultWidth = 2.0;
    vehicleTypeDefaultFilename = "";
    vehicleTypeDefaultImpatience = 0.0;
    vehicleTypeDefaultEdgeChangeModel = "DK2008";
    vehicleTypeDefaultActBatKap = 500;
    vehicleTypeDefaultMaxBatKap = 1000;
    vehicleTypeDefaultPowerMax = 100;
    vehicleTypeDefaultMass = 1000;
    vehicleTypeDefaultFrontSurfaceArea = 2;
    vehicleTypeDefaultAirDragCoefficient = 0.4;
    vehicleTypeDefaultInternalMomentOfInertia = 10;
    vehicleTypeDefaultRadialDragCoefficient = 1;
    vehicleTypeDefaultRollDragCoefficient = 0.5;
    vehicleTypeDefaultConstantPowerIntake = 10;
    vehicleTypeDefaultPropulsionEfficiency = 0.5;
    vehicleTypeDefaultRecuperationEfficiency = 0;
}


vehicleTypeItemConfiguration::~vehicleTypeItemConfiguration()
{
    // Nothing to erase
}

const QString &vehicleTypeItemConfiguration::getVehicleTypeClassValue(vehicleClass vClass) const
{
    return vectorOfVehicleTypeClasses.at(vClass);
}

const QString &vehicleTypeItemConfiguration::getVehicleTypeShapeValue(vehicleShape vShape) const
{
    return vectorOfVehicleTypeClasses.at(vShape);
}

const QString &vehicleTypeItemConfiguration::getVehicleTypeEmissionValue(vehicleEmission eValue) const
{
    return vectorOfVehicleTypeEmissions.at(eValue);
}

int vehicleTypeItemConfiguration::getVehicleTypeNumberOfVehicleClasses()
{
    return numberOfVehicleClasses;
}

vehicleClass vehicleTypeItemConfiguration::getVehicleTypeDefaultVClass() const
{
    return vehicleTypeDefaultVClass;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultAccel() const
{
    return vehicleTypeDefaultAccel;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultDecel() const
{
    return vehicleTypeDefaultDecel;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultSigma() const
{
    return vehicleTypeDefaultSigma;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultTau() const
{
    return vehicleTypeDefaultTau;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultLength() const
{
    return vehicleTypeDefaultLength;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultMinGap() const
{
    return vehicleTypeDefaultMinGap;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultMaxSpeed() const
{
    return vehicleTypeDefaultMaxSpeed;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultSpeedFactor() const
{
    return vehicleTypeDefaultSpeedFactor;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultSpeedDev() const
{
    return vehicleTypeDefaultSpeedDev;
}

const QString &vehicleTypeItemConfiguration::getVehicleTypeDefaultColor() const
{
    return vehicleTypeDefaultColor;
}

const QString &vehicleTypeItemConfiguration::getVehicleTypeDefaultEmissionClass() const
{
    return vehicleTypeDefaultEmissionClass;
}

vehicleShape vehicleTypeItemConfiguration::getVehicleTypeDefaultGuiShape() const
{
    return vehicleTypeDefaultguiShape;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultWidth() const
{
    return vehicleTypeDefaultWidth;
}

const QString &vehicleTypeItemConfiguration::getVehicleTypeDefaultFilename() const
{
    return vehicleTypeDefaultFilename;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultImpatience() const
{
    return vehicleTypeDefaultImpatience;
}

const QString &vehicleTypeItemConfiguration::getVehicleTypeDefaultLaneChangeModel() const
{
    return vehicleTypeDefaultEdgeChangeModel;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultActBatKap() const
{
    return vehicleTypeDefaultActBatKap;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultMaxBatKap() const
{
    return vehicleTypeDefaultMaxBatKap;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultPowerMax() const
{
    return vehicleTypeDefaultPowerMax;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultMass() const
{
    return vehicleTypeDefaultMass;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultFrontSurfaceArea() const
{
    return vehicleTypeDefaultFrontSurfaceArea;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultAirDragCoefficient() const
{
    return vehicleTypeDefaultAirDragCoefficient;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultInternalMomentOfInertia() const
{
    return vehicleTypeDefaultInternalMomentOfInertia;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultRadialDragCoefficient() const
{
    return vehicleTypeDefaultRadialDragCoefficient;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultRollDragCoefficient() const
{
    return vehicleTypeDefaultRollDragCoefficient;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultConstantPowerIntake() const
{
    return vehicleTypeDefaultConstantPowerIntake;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultPropulsionEfficiency() const
{
    return vehicleTypeDefaultPropulsionEfficiency;
}

qreal vehicleTypeItemConfiguration::getVehicleTypeDefaultRecuperationEfficiency() const
{
    return vehicleTypeDefaultRecuperationEfficiency;
}
