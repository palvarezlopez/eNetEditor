#include "vehicleItem.h"

// Parameter Manager
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/vehicles/vehicleItemConfiguration.h"

// Configuration
#include "../../project/itemManagerProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"
#include "../../database/vehicles/vehicleTable.h"

// Items
#include "../vehicleTypeItem.h"
#include "../routeItem.h"


vehicleItem::vehicleItem(const QString &newId, vehicleTypeItem *newType, routeItem *newRouteVehicle, eNetEditorDatabase *database) : abstractVehicleItem(database->getVehicleTable(), newId, newType, newRouteVehicle)
{
    // Set Depart
    depart = getProjectConfiguration()->getVehicleItemConfiguration()->getVehicleDefaultDepart();

    /**
        // Check ID
        if(newId == "")
        {
            // CHange ID
            v->setItemId("vehicle" + QString::number(nextIndex) + "_" + newRouteVehicle->getItemId());

            // Update nextIndex
            nextIndex++;
        }
        **/


    // Add flow to route list
    getRoute()->addVehicle(this);
}

vehicleItem::~vehicleItem()
{
    // Erase flow of route
    getRoute()->removeVehicle(this);

    // Erase vehicle of vehicle type
    getVehicleType()->removeVehicle(this);
}

void vehicleItem::make()
{
    // Nothing to make
}

QDomElement vehicleItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("vehicle");

    // Return itemDomElement
    return itemDomElement;
}

qreal vehicleItem::getDepart() const
{
    return depart;
}

void vehicleItem::setDepart(qreal newDepart)
{
    depart = newDepart;
}

void vehicleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Nothing to draw
    Q_UNUSED(painter);
}

void vehicleItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath vehicleItem::shape() const
{
    // This item don't have shape
    return QPainterPath();
}
