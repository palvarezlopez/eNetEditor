#include "abstractVehicleItem.h"

// Configuration
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/vehicles/abstractVehicleItemConfiguration.h"
#include "../../configuration/items/vehicles/vehicleItemConfiguration.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"


abstractVehicleItem::abstractVehicleItem(eNetEditorTable *newItemTable, const QString &newId, vehicleTypeItem *newType, routeItem *newRouteVehicle) : eNetEditorItem(newItemTable)
{
    // Set ID
    eNetEditorItem::setItemId(newId);

    // Set vehicle type
    type = newType;

    // Set route
    routeVehicle = newRouteVehicle;

    // Set Color
    color = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultColor();

    // Set Depart Lane
    departLane = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultDepartLane();

    // Set depart Pos
    departPos = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultDepartPos();

    // Set depart Speed
    departSpeed = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultDepartSpeed();

    // Set arrival Lane
    arrivalLane = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultArrivalLane();

    // Set arrival Pos
    arrivalPos = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultArrivalPos();

    // Set arrival Speed
    arrivalSpeed = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultArrivalSpeed();

    // Set Line
    line = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultLine();

    // Set person number
    personNumber = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultPersonNumber();

    // Set Container number
    containerNumber = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultContainerNumber();
}

abstractVehicleItem::~abstractVehicleItem()
{
    // Nothing to erase
}

vehicleTypeItem *abstractVehicleItem::getVehicleType() const
{
    return type;
}

routeItem *abstractVehicleItem::getRoute() const
{
    return routeVehicle;
}

const QString &abstractVehicleItem::getColor() const
{
    return color;
}

const QString &abstractVehicleItem::getDepartLane() const
{
    return departLane;
}

const QString &abstractVehicleItem::getDepartPos() const
{
    return departPos;
}

const QString &abstractVehicleItem::getDepartSpeed() const
{
    return departSpeed;
}

const QString &abstractVehicleItem::getArrivalLane() const
{
    return arrivalLane;
}

const QString &abstractVehicleItem::getArrivalPos() const
{
    return arrivalPos;
}

const QString &abstractVehicleItem::getArrivalSpeed() const
{
    return arrivalSpeed;
}

const QString &abstractVehicleItem::getLine() const
{
    return line;
}

int abstractVehicleItem::getPersonNumber() const
{
    return personNumber;
}

int abstractVehicleItem::getContainerNumber() const
{
    return containerNumber;
}


void abstractVehicleItem::setType(vehicleTypeItem *newType)
{
    type = newType;
}

void abstractVehicleItem::setRoute(routeItem *newRouteVehicle)
{
    routeVehicle = newRouteVehicle;
}

void abstractVehicleItem::setColor(const QString &newColor)
{
    color = newColor;
}

void abstractVehicleItem::setDepartLane(const QString &newDepartLane)
{
    departLane = newDepartLane;
}

void abstractVehicleItem::setDepartPos(const QString &newDepartPos)
{
    departPos = newDepartPos;
}

void abstractVehicleItem::setDepartSpeed(const QString &newDepartSpeed)
{
    departSpeed = newDepartSpeed;
}

void abstractVehicleItem::setArrivalLane(const QString &newArrivalLane)
{
    arrivalLane = newArrivalLane;
}

void abstractVehicleItem::setArrivalPos(const QString &newArrivalPos)
{
    arrivalPos = newArrivalPos;
}

void abstractVehicleItem::setArrivalSpeed(const QString &newArrivalSpeed)
{
    arrivalSpeed = newArrivalSpeed;
}

void abstractVehicleItem::setLine(const QString &newLine)
{
    line = newLine;
}

void abstractVehicleItem::setPersonNumber(int newPersonNumber)
{
    personNumber = newPersonNumber;
}

void abstractVehicleItem::setContainerNumber(int newContainerNumber)
{
    containerNumber = newContainerNumber;
}

