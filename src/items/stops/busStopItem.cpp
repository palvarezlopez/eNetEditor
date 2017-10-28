#include "busStopItem.h"

// Configuration
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/stops/busStopItemConfiguration.h"
#include "../../configuration/items/laneItemConfiguration.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"
#include "../../database/stops/busStopTable.h"

// Include items
#include "../laneItem.h"
#include "../edges/edgeItem.h"
#include "../nodeItem.h"


busStopItem::busStopItem(const QString &newID, laneItem *newLaneParent, eNetEditorDatabase *database) : eNetEditorItem(database->getBusStopTable(), "greenyellow", "green")
{
    // Set Bus Stop ID
    eNetEditorItem::setItemId(newID);

    // Set Lane Parent
    laneParent = newLaneParent;

    // Set StartPos
    startPos = getProjectConfiguration()->getBusStopItemConfiguration()->getBusStopDefaultStartPos();

    // Set endPos
    endPos = getProjectConfiguration()->getBusStopItemConfiguration()->getBusStopDefaultEndPos();

    // Set Lines
    lines = getProjectConfiguration()->getBusStopItemConfiguration()->getBusStopDefaultLines();

    // Add bus stop of the list of bus stops
    laneParent->addBusStop(this);

    // Set pen size
    setItemPen(getProjectConfiguration()->getBusStopItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getBusStopItemConfiguration()->getItemPenSize());

    // Set font
    setItemFontText(getProjectConfiguration()->getBusStopItemConfiguration()->getItemTextFont(), getProjectConfiguration()->getBusStopItemConfiguration()->getItemTextSize());

    // Set pen text size
    setItemPenText(getProjectConfiguration()->getBusStopItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getBusStopItemConfiguration()->getItemTextPenSize());

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getBusStopItemConfiguration()->getItemAltitude());

    /*
    // If id != ""
    if(newID != "")
    {
        // Set own ID in busStop
        bs->setItemId(newID);
    }
    */

    // Make Bus Stop
    make();
}

busStopItem::~busStopItem()
{
    // delete bus stop of the list of bus stops
    laneParent->removeBusStop(this);
}

void busStopItem::make()
{
    // Move matrix to center of Node origin
    setPos(laneParent->getEdgeParent()->getNodeOrigin()->pos());

    // Do a rotation using as reference the position of both nodes
    setRotation(360.0 - QLineF(laneParent->getEdgeParent()->getNodeOrigin()->pos(), laneParent->getEdgeParent()->getNodeDestiny()->pos()).angle());

    // Set rect of the bus stop
    busStopRect = QRectF(startPos + getProjectConfiguration()->getLaneItemConfiguration()->getLaneOffset() + (laneParent->getEdgeParent()->getNodeOrigin()->getCurrentlyDiametre() * 0.5), laneParent->getIndex() * getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth(), endPos, getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth());

    // Set the Bounding rect
    setBoundingRect(busStopRect);
}

QDomElement busStopItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("busStop");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement busStopItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("busStop");

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
    // Set atribute lines
    itemDomElement.setAttribute("lines", lines);

    // Return itemDomElement
    return itemDomElement;
}

laneItem *busStopItem::getLane() const
{
    return laneParent;
}

qreal busStopItem::getStartPos() const
{
    return startPos;
}

qreal busStopItem::getEndPos() const
{
    return endPos;
}

const QString &busStopItem::getLines() const
{
    return lines;
}



void busStopItem::setStartPos(qreal newStartPos)
{
    if (newStartPos < laneParent->getEdgeParent()->getLength())
    {
        startPos = newStartPos;
    }
    else
    {
        startPos = 0;
    }
}

void busStopItem::setEndPos(qreal newEndPos)
{
    if (newEndPos < laneParent->getEdgeParent()->getLength())
    {
        endPos = newEndPos;
    }
    else
    {
        newEndPos = laneParent->getEdgeParent()->getLength();
    }
}

void busStopItem::setLines(const QString &newLines)
{
    lines = newLines;
}

void busStopItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // if Draw item is enabled
    if(getParameterManager()->isShowAllBusStopItems())
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
        if(getParameterManager()->isBusStopShowLabelEnabled())
        {
            // Set the modified font to the painter
            painter->setFont(getItemFontText());

            // Add pen to painter
            painter->setPen(getItemPenText());

            // Draw text
            painter->drawText(boundingRect().center() - QPointF(5, 0), this->getItemId());
        }

        // If flag ShowIcon is enabled
        if(getParameterManager()->isBusStopShowIconEnabled())
        {
            // Change brush to green
            painter->setBrush(QColor("green"));

            // Draw circle
            painter->drawEllipse(QRectF(boundingRect().center().x() - 1, boundingRect().center().y() - 1, 2, 2));

            // Change brush to Yellow
            painter->setBrush(QColor("yellow"));

            // Draw circle a little bit more little
            painter->drawEllipse(QRectF(boundingRect().center().x() - 0.8, boundingRect().center().y() - 0.8, 1.6, 1.6));
        }
    }
}

void busStopItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath busStopItem::shape() const
{
    // Declare QPainterPath
    QPainterPath path;

    // If the item isn't blocked
    if(getParameterManager()->isBusStopBlocked() == false)
    {
        // Add path
        path.addRect(boundingRect());
    }

    // Return path
    return path;
}
