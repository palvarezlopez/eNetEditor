#include "flowItem.h"

// Configuration
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/vehicles/flowItemConfiguration.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"
#include "../../database/vehicles/flowTable.h"

// Items
#include "../vehicleTypeItem.h"
#include "../routeItem.h"


flowItem::flowItem(const QString &newId, vehicleTypeItem *newType, routeItem *newRouteVehicle, eNetEditorDatabase *database) : abstractVehicleItem(database->getFlowTable(), newId, newType, newRouteVehicle)
{
    // Set begin
    begin = getProjectConfiguration()->getFlowItemConfiguration()->getFlowBegin();

    // Set end
    end = getProjectConfiguration()->getFlowItemConfiguration()->getFlowEnd();

    // Set vehicles per hour
    vehsPerHour = getProjectConfiguration()->getFlowItemConfiguration()->getFlowVehsPerHour();

    // Set Period
    period = getProjectConfiguration()->getFlowItemConfiguration()->getFlowPeriod();

    // Set Probability
    probability = getProjectConfiguration()->getFlowItemConfiguration()->getFlowProbability();

    // Set number
    number = getProjectConfiguration()->getFlowItemConfiguration()->getFlowNumber();

    // By default vehsPerHourOption is enabled
    vehsPerHourOption = true;

    // By default periodOption is disabled
    periodOption = false;

    // By default probabilityOption is enabled
    probabilityOption = false;

    // By default numberOption is disabled
    numberOption = false;

    // Add flow to route list
    getRoute()->addFlow(this);

    /// CAMBIAR ESTO
    setItemId("flow" + QString::number(getRoute()->getListOfFlows()->indexOf(this)) + "_" + getRoute()->getItemId());
}

flowItem::~flowItem()
{
    // Erase flow of route
    getRoute()->removeFlow(this);

    // Erase flow of vehicle type
    getVehicleType()->removeFlow(this);
}

void flowItem::make()
{
    // Nothing to make
}

QDomElement flowItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("flow");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement flowItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("terminar");

    // Return itemDomElement
    return itemDomElement;
}

qreal flowItem::getBegin() const
{
    return begin;
}

qreal flowItem::getEnd() const
{
    return end;
}

qreal flowItem::getVehsPerHour() const
{
    return vehsPerHour;
}

qreal flowItem::getPeriod() const
{
    return period;
}

qreal flowItem::getProbability() const
{
    return probability;
}

int flowItem::getNumber() const
{
    return number;
}

void flowItem::setBegin(const qreal newBegin)
{
    begin = newBegin;
}

void flowItem::setEnd(const qreal newEnd)
{
    end = newEnd;
}

void flowItem::setVehsPerHour(const qreal newVehsPerHour)
{
    vehsPerHour = newVehsPerHour;
}

void flowItem::setPeriod(const qreal newPeriod)
{
    period = newPeriod;
}

void flowItem::setProbability(const qreal newProbability)
{
    if(newProbability < 0)
    {
        probability = 0;
    }
    else if (newProbability > 1)
    {
        probability = 1;
    }
    else
    {
        probability = newProbability;
    }
}

void flowItem::setNumber(const int newNumber)
{
    number = newNumber;
}

void flowItem::setVehsPerHourOption(bool value)
{
    if(value == true)
    {
        // Enable option and disable the others
        vehsPerHourOption = true;
        periodOption = false;
        probabilityOption = false;
        numberOption = false;
    }
    else
    {
        vehsPerHourOption = false;

        // Always one of the tree options has to be enabled (By default, probability)
        if((vehsPerHourOption == false) && (periodOption == false) && (probabilityOption == false) && (numberOption == false))
        {
            probabilityOption = true;
        }
    }
}

void flowItem::setPeriodOption(bool value)
{
    if(value == true)
    {
        // Enable option and disable the others
        vehsPerHourOption = false;
        periodOption = true;
        probabilityOption = false;
        numberOption = false;
    }
    else
    {
        periodOption = false;

        // Always one of the tree options has to be enabled (By default, probability)
        if((vehsPerHourOption == false) && (periodOption == false) && (probabilityOption == false) && (numberOption == false))
        {
            probabilityOption = true;
        }
    }
}

void flowItem::setProbabilityOption(bool value)
{
    if(value == true)
    {
        // Enable option and disable the others
        vehsPerHourOption = false;
        periodOption = false;
        probabilityOption = true;
        numberOption = false;
    }
    else
    {
        probabilityOption = false;

        // Always one of the tree options has to be enabled (By default, probability)
        if((vehsPerHourOption == false) && (periodOption == false) && (probabilityOption == false) && (numberOption == false))
        {
            probabilityOption = true;
        }
    }
}

void flowItem::setProbabilityNumber(bool value)
{
    if(value == true)
    {
        // Enable option and disable the others
        vehsPerHourOption = false;
        periodOption = false;
        probabilityOption = false;
        numberOption = true;
    }
    else
    {
        numberOption = false;

        // Always one of the tree options has to be enabled (By default, probability)
        if((vehsPerHourOption == false) && (periodOption == false) && (probabilityOption == false) && (numberOption == false))
        {
            probabilityOption = true;
        }
    }
}

bool flowItem::isVehsPerHourOptionEnabled()
{
    return vehsPerHourOption;
}

bool flowItem::isPeriodOptionEnabled()
{
    return periodOption;
}

bool flowItem::isProbabilityOptionEnabled()
{
    return probabilityOption;
}

bool flowItem::isNumberOptionEnabled()
{
    return numberOption;
}

void flowItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Nothing to draw
    Q_UNUSED(painter);
}

void flowItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath flowItem::shape() const
{
    // This element don't have shape
    return QPainterPath();
}
