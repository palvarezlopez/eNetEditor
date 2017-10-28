#include "laneAreaE2DetectorItem.h"

// Parameter Manager
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/laneItemConfiguration.h"
#include "../../configuration/items/detectors/laneAreaE2DetectorItemConfiguration.h"

// Project
#include "../../project/eNetEditorProject.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// DataBase
#include "../../database/eNetEditorDatabase.h"
#include "../../database/detectors/laneAreaE2DetectorTable.h"

// Items
#include "../../items/edges/edgeItem.h"
#include "../../items/laneItem.h"
#include "../../items/nodeItem.h"


laneAreaE2DetectorItem::laneAreaE2DetectorItem(laneItem *newLaneOfDetector, eNetEditorDatabase *database) : abstractDetectorItem(database->getLaneAreaE2Table(), newLaneOfDetector)
{
    // Set pen size
    setItemPen(getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getItemPenSize());

    // Set font
    setItemFontText(getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getItemTextFont(), getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getItemTextSize());

    // Set pen text size
    setItemPenText(getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getItemTextPenSize());

    // Set parameter cont
    cont = getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getLaneAreaE2DetectorItemDefaultCont();

    // Set parameter friendlyPos
    friendlyPos = getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getLaneAreaE2DetectorItemDefaultFriendlyPos();

    // Set parameter timeThreshold
    timeThreshold = getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getLaneAreaE2DetectorItemDefaultTimeThreshold();

    // Set parameter speedThresthold
    speedThreshold = getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getLaneAreaE2DetectorItemDefaultSpeedThreshold();

    // Set parameter jamThresthold
    jamThreshold = getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getLaneAreaE2DetectorItemDefaultJamThreshold();

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration()->getItemAltitude());

    // Make detectors
    make();
}

void laneAreaE2DetectorItem::make()
{
    // Move matrix to center of Node origin
    setPos(getLaneParent()->getEdgeParent()->getNodeOrigin()->pos());

    // Do a rotation using as reference the position of both nodes
    setRotation(360.0 - QLineF(getLaneParent()->getEdgeParent()->getNodeOrigin()->pos(), getLaneParent()->getEdgeParent()->getNodeDestiny()->pos()).angle());

    // Set the Bounding rect
    setBoundingRect(QRectF(getPosDetector() + getProjectConfiguration()->getLaneItemConfiguration()->getLaneOffset() + (getLaneParent()->getEdgeParent()->getNodeOrigin()->getCurrentlyDiametre() * 0.5), 2 * getLaneParent()->getIndex() * 0.333333, getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth() * 0.333333, getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth() * 0.333333));
}

QDomElement laneAreaE2DetectorItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("E2");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement laneAreaE2DetectorItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("laneAreaDetector");

    // Save Id of item
    itemDomElement.setAttribute("id", getItemId());

    // Set atribute lane
    itemDomElement.setAttribute("lane", getLaneParent()->getItemId());

    // Set atribute pos
    itemDomElement.setAttribute("pos", QString::number(getPosDetector()));

    // Set atribute filename
    itemDomElement.setAttribute("file", getFileName());

    // Set atribute friendlyPos
    if (friendlyPos)
    {
        itemDomElement.setAttribute("friendlyPos", "true");
    }
    else
    {
        itemDomElement.setAttribute("friendlyPos", "false");
    }

    // Set atribute cont
    if (cont)
    {
        itemDomElement.setAttribute("cont", "true");
    }
    else
    {
        itemDomElement.setAttribute("cont", "false");
    }

    // Set atribute timeThreshold
    itemDomElement.setAttribute("timeThreshold", QString::number(timeThreshold));

    // Set atribute speedThreshold
    itemDomElement.setAttribute("speedThreshold", QString::number(speedThreshold));

    // Set atribute jamThreshold
    itemDomElement.setAttribute("jamThreshold", QString::number(jamThreshold));

    // Return itemDomElement
    return itemDomElement;
}

void laneAreaE2DetectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // if Draw item is enabled
    if(getParameterManager()->isShowAllDetectorItems())
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
    }
}

void laneAreaE2DetectorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath laneAreaE2DetectorItem::shape() const
{
    // Declare QPainterPath
    QPainterPath path;

    // If the item isn't blocked
    if(getParameterManager()->isDetectorBlocked() == false)
    {
        // Add path
        path.addRect(boundingRect());
    }

    // Return new path
    return path;
}

void laneAreaE2DetectorItem::setJamThreshold(qreal value)
{
    jamThreshold = value;
}

void laneAreaE2DetectorItem::setSpeedThreshold(qreal value)
{
    speedThreshold = value;
}

void laneAreaE2DetectorItem::setTimeThreshold(int value)
{
    timeThreshold = value;
}

void laneAreaE2DetectorItem::setFriendlyPos(bool value)
{
    friendlyPos = value;
}

void laneAreaE2DetectorItem::setCont(bool value)
{
    cont = value;
}

qreal laneAreaE2DetectorItem::getJamThreshold() const
{
    return jamThreshold;
}

qreal laneAreaE2DetectorItem::getSpeedThreshold() const
{
    return speedThreshold;
}

int laneAreaE2DetectorItem::getTimeThreshold() const
{
    return timeThreshold;
}

bool laneAreaE2DetectorItem::getFriendlyPos() const
{
    return friendlyPos;
}

bool laneAreaE2DetectorItem::getCont() const
{
    return cont;
}

