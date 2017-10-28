#include "chargingStationItem.h"

// Configuration
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/stops/chargingStationItemConfiguration.h"
#include "../../configuration/items/laneItemConfiguration.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"
#include "../../database/stops/chargingStationTable.h"

// Items
#include "../laneItem.h"
#include "../edges/edgeItem.h"
#include "../nodeItem.h"


chargingStationItem::chargingStationItem(const QString &newID, laneItem *newLaneParent, eNetEditorDatabase *database) : eNetEditorItem(database->getChargingStationTable(), "turquoise", "darkturquoise")
{
    // Set Cahrging station ID
    eNetEditorItem::setItemId(newID);

    // Set lane Parent
    laneParent = newLaneParent;

    // Set start position
    startPos = getProjectConfiguration()->getChargingStationItemConfiguration()->getChargingStationDefaultStartPos();

    // Set end position
    endPos = getProjectConfiguration()->getChargingStationItemConfiguration()->getChargingStationDefaultEndPos();

    // Set charging power
    chrgPower = getProjectConfiguration()->getChargingStationItemConfiguration()->getChargingStationDefaultChrgPower();

    // Set efficiency
    efficiency = getProjectConfiguration()->getChargingStationItemConfiguration()->getChargingStationDefaultEfficiency();

    // Set charge in transit
    chargeInTransit = getProjectConfiguration()->getChargingStationItemConfiguration()->getChargingStationDefaultChargeInTransit();

    // Set charge delay
    chargeDelay = getProjectConfiguration()->getChargingStationItemConfiguration()->getChargingStationDefaultChargeDelay();

    // Add Charging Station to the list of Charging stations
    laneParent->addChargingStation(this);

    // Set pen size
    setItemPen(getProjectConfiguration()->getChargingStationItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getChargingStationItemConfiguration()->getItemPenSize());

    // Set font
    setItemFontText(getProjectConfiguration()->getChargingStationItemConfiguration()->getItemTextFont(), getProjectConfiguration()->getChargingStationItemConfiguration()->getItemTextSize());

    // Set pen text size
    setItemPenText(getProjectConfiguration()->getChargingStationItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getChargingStationItemConfiguration()->getItemTextPenSize());

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getChargingStationItemConfiguration()->getItemAltitude());
    /*
        // If id != ""
        if(newID != "")
        {
            // Set own ID in charging station
            cs->setItemId(newID);
        }
    */

    // Make Charging Station
    make();
}

chargingStationItem::~chargingStationItem()
{
    // delete charging station of the list of charging station
    laneParent->removeChargingStation(this);
}

void chargingStationItem::make()
{
    // Move matrix to center of Node origin
    setPos(laneParent->getEdgeParent()->getNodeOrigin()->pos());

    // Do a rotation using as reference the position of both nodes
    setRotation(360.0 - QLineF(laneParent->getEdgeParent()->getNodeOrigin()->pos(), laneParent->getEdgeParent()->getNodeDestiny()->pos()).angle());

    // Set rect of the charging station
    chargingStationRect = QRectF(startPos + getProjectConfiguration()->getLaneItemConfiguration()->getLaneOffset() + (laneParent->getEdgeParent()->getNodeOrigin()->getCurrentlyDiametre() * 0.5), laneParent->getIndex() * getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth(), endPos, getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth());

    // Set the Bounding rect
    setBoundingRect(chargingStationRect);
}

QDomElement chargingStationItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("chargingStation");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement chargingStationItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("chargingStation");

    // Set atribute id
    itemDomElement.setAttribute("id", getItemId());

    // Set atribute lane
    itemDomElement.setAttribute("lane", laneParent->getItemId());

    // Set atribute start pos
    itemDomElement.setAttribute("startPos", QString::number(startPos));

    // Set atribute end pos
    itemDomElement.setAttribute("endPos", QString::number(endPos));

    /**
    // Set atribute friendlyPos
    if(friendlyp)
    {
        itemDomElement.setAttribute("friendlyPos", "true");
    }
    else
    {
        itemDomElement.setAttribute("friendlyPos", "false");
    }
    */

    // Set atribute chrgPower
    itemDomElement.setAttribute("chrgPower", QString::number(chrgPower));

    // Set atribute efficiency
    itemDomElement.setAttribute("efficiency", QString::number(efficiency));

    // Set atribute
    itemDomElement.setAttribute("chargeDelay", QString::number(chargeDelay));

    // Set atribute chargeInTransit
    itemDomElement.setAttribute("chargeInTransit", QString::number(chargeInTransit));

    // Return itemDomElement
    return itemDomElement;
}



laneItem *chargingStationItem::getLane() const
{
    return laneParent;
}

qreal chargingStationItem::getStartPos() const
{
    return startPos;
}

qreal chargingStationItem::getEndPos() const
{
    return endPos;
}

const long &chargingStationItem::getChrgpower() const
{
    return chrgPower;
}

qreal chargingStationItem::getEfficiency() const
{
    return efficiency;
}

const unsigned int &chargingStationItem::getChargeInTransit() const
{
    return chargeInTransit;
}

const unsigned int &chargingStationItem::getChargeDelay() const
{
    return chargeDelay;
}

void chargingStationItem::setStartPos(qreal newStartPos)
{
    /** Arreglar esto en ambas **/

    if (newStartPos < laneParent->getEdgeParent()->getLength())
    {
        startPos = newStartPos;
    }
    else
    {
        startPos = 0;
    }
}

void chargingStationItem::setEndPos(qreal newEndPos)
{
    if (newEndPos < laneParent->getEdgeParent()->getLength())
    {
        endPos = newEndPos;
    }
    else
    {
        endPos = laneParent->getEdgeParent()->getLength();
    }
}

void chargingStationItem::setChrgpower(const long &newChrgPower)
{
    chrgPower = newChrgPower;
}

void chargingStationItem::setEfficiency(qreal newEfficiency)
{
    efficiency = newEfficiency;
}

void chargingStationItem::setChargeInTransit(const unsigned int &newChargeInTransit)
{
    chargeInTransit = newChargeInTransit;
}

void chargingStationItem::setChargeDelay(const unsigned int &newChargeDelay)
{
    chargeDelay = newChargeDelay;
}

void chargingStationItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // if Draw item is enabled
    if(getParameterManager()->isShowAllChargingStationItems())
    {
        // Set brush
        if(isItemSelectable() && isItemMouseIn())
        {
            // Set Selected color if item is selected
            painter->setBrush(getItemColorSelected());
        }
        else if (isItemMarked())
        {
            // Set Marked color if item is selected
            painter->setBrush(getItemColorMarked());
        }
        else if (isItemMouseIn())
        {
            // Set first color if mouse is over item but isn't blocked
            painter->setBrush(getItemFirstColor());
        }
        else
        {
            // Set second color in the rest of cases
            painter->setBrush(getItemSecondColor());
        }

        // Add pen to painter
        painter->setPen(getItemPen());

        // Draw the rect
        painter->drawRect(boundingRect());

        // If flag ShowLabels is enabled
        if(getParameterManager()->isChargingStationShowLabelEnabled())
        {
            // Set the modified font to the painter
            painter->setFont(getItemFontText());

            // Add pen to painter
            painter->setPen(getItemPenText());

            // Draw text
            painter->drawText(boundingRect().center() - QPointF(5, 0), this->getItemId());
        }

        // If flag ShowIcon is enabled
        if(getParameterManager()->isChargingStationShowIconEnabled())
        {
            // Change brush to green
            painter->setBrush(QColor("turquoise"));

            // Draw circle
            painter->drawEllipse(QRectF(boundingRect().center().x() - 1, boundingRect().center().y() - 1, 2, 2));

            // Change brush to Yellow
            painter->setBrush(QColor("yellow"));

            // Draw circle a little bit more little
            painter->drawEllipse(QRectF(boundingRect().center().x() - 0.8, boundingRect().center().y() - 0.8, 1.6, 1.6));
        }
    }
}

void chargingStationItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath chargingStationItem::shape() const
{
    // Declare QPainterPath
    QPainterPath path;

    // If the item isn't blocked
    if(getParameterManager()->isChargingStationBlocked() == false)
    {
        // Add path
        path.addRect(boundingRect());
    }

    // Return path
    return path;
}
