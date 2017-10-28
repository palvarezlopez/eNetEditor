#include "multiEntryExitE3DetectorItem.h"

// Parameter Manager
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/laneItemConfiguration.h"
#include "../../configuration/items/detectors/multiEntryExitE3DetectorItemConfiguration.h"

// Project
#include "../../project/eNetEditorProject.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// DataBase
#include "../../database/eNetEditorDatabase.h"
#include "../../database/detectors/multiEntryExitE3DetectorTable.h"

// Items
#include "../../items/edges/edgeItem.h"
#include "../../items/laneItem.h"
#include "../../items/nodeItem.h"


multiEntryExitE3DetectorItem::multiEntryExitE3DetectorItem(laneItem *newLaneOfDetector, eNetEditorDatabase *database) : abstractDetectorItem(database->getMultiEntryExitE3Table(), newLaneOfDetector)
{
    // Set pen size
    setItemPen(getProjectConfiguration()->getMultiEntryExitE3DetectorItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getMultiEntryExitE3DetectorItemConfiguration()->getItemPenSize());

    // Set font
    setItemFontText(getProjectConfiguration()->getMultiEntryExitE3DetectorItemConfiguration()->getItemTextFont(), getProjectConfiguration()->getMultiEntryExitE3DetectorItemConfiguration()->getItemTextSize());

    // Set pen text size
    setItemPenText(getProjectConfiguration()->getMultiEntryExitE3DetectorItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getMultiEntryExitE3DetectorItemConfiguration()->getItemTextPenSize());

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getMultiEntryExitE3DetectorItemConfiguration()->getItemAltitude());
    /*
        // If id != ""
        if(newID != "")
        {
            // Set own ID
            setItemId(newID);
        }
    */

    // Make detector
    make();
}

void multiEntryExitE3DetectorItem::make()
{
    // Move matrix to center of Node origin
    setPos(getLaneParent()->getEdgeParent()->getNodeOrigin()->pos());

    // Do a rotation using as reference the position of both nodes
    setRotation(360.0 - QLineF(getLaneParent()->getEdgeParent()->getNodeOrigin()->pos(), getLaneParent()->getEdgeParent()->getNodeDestiny()->pos()).angle());

    // Set the Bounding rect
    setBoundingRect(QRectF(getPosDetector() + getProjectConfiguration()->getLaneItemConfiguration()->getLaneOffset() + (getLaneParent()->getEdgeParent()->getNodeOrigin()->getCurrentlyDiametre() * 0.5), 2 * getLaneParent()->getIndex() * 0.666666, getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth() * 0.333333, getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth() * 0.333333));
}

QDomElement multiEntryExitE3DetectorItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("E3");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement multiEntryExitE3DetectorItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("entryExitDetector");

    // Save Id of item
    itemDomElement.setAttribute("id", getItemId());

    // Set atribute lane
    itemDomElement.setAttribute("lane", getLaneParent()->getItemId());

    // Set atribute pos
    itemDomElement.setAttribute("pos", QString::number(getPosDetector()));

    // Set atribute filename
    itemDomElement.setAttribute("file", getFileName());

    // Return itemDomElement
    return itemDomElement;
}

void multiEntryExitE3DetectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

void multiEntryExitE3DetectorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath multiEntryExitE3DetectorItem::shape() const
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

