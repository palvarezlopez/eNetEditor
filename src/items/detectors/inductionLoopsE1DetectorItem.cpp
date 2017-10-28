#include "inductionLoopsE1DetectorItem.h"

// Parameter Manager
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/detectors/inductionLoopsE1DetectorItemConfiguration.h"
#include "../../configuration/items/laneItemConfiguration.h"

// Project
#include "../../project/eNetEditorProject.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// DataBase
#include "../../database/eNetEditorDatabase.h"
#include "../../database/detectors/inductionLoopsE1DetectorTable.h"

// Items
#include "../../items/flowMeasureItem.h"
#include "../../items/edges/edgeItem.h"
#include "../../items/laneItem.h"
#include "../../items/nodeItem.h"


inductionLoopsE1DetectorItem::inductionLoopsE1DetectorItem(laneItem *newLaneOfDetector, eNetEditorDatabase *database) : abstractDetectorItem(database->getInductionLoopsE1Table(), newLaneOfDetector)
{
    // Set default friendlyPos
    friendlyPos = getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getInductionLoopsE1DetectorItemDefaultFriendlyPos();

    // Set default splitByType
    splitByType = getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getInductionLoopsE1DetectorItemDefaultSplitByType();

    // Set Label of edge
    setItemLabel(getItemId());

    // Set pen size
    setItemPen(getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getItemPenSize());

    // Set font
    setItemFontText(getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getItemTextFont(), getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getItemTextSize());

    // Set pen text size
    setItemPenText(getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getItemTextPenSize());

    // Add inductionLoopsE1Detector to laneParent
    getLaneParent()->addInductionLoopsE1Detector(this);

    // Add inductionLoopsE1Detector to edgeParent
    getLaneParent()->getEdgeParent()->addInductionLoopsE1Detector(this);

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getItemAltitude());

    // makeDetector
    make();
}

inductionLoopsE1DetectorItem::~inductionLoopsE1DetectorItem()
{
    // clear flow measures
    clearFlowMeasures();

    // Remove inductionLoopsE1Detector to laneParent
    getLaneParent()->removeInductionLoopsE1Detector(this);

    // Remove inductionLoopsE1Detector to edgeParent
    getLaneParent()->getEdgeParent()->removeInductionLoopsE1Detector(this);
}

void inductionLoopsE1DetectorItem::make()
{
    // Move matrix to center of Node origin
    setPos(getLaneParent()->getEdgeParent()->getNodeOrigin()->pos());

    // Do a rotation using as reference the position of both nodes
    setRotation(360.0 - QLineF(getLaneParent()->getEdgeParent()->getNodeOrigin()->pos(), getLaneParent()->getEdgeParent()->getNodeDestiny()->pos()).angle());

    // Set the Bounding rect
    setBoundingRect(QRectF(getPosDetector() + getProjectConfiguration()->getLaneItemConfiguration()->getLaneOffset() + (getLaneParent()->getEdgeParent()->getNodeOrigin()->getCurrentlyDiametre() * 0.5), 2 * getLaneParent()->getIndex(), getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth() * 0.333333, getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth() * 0.333333));
}

QDomElement inductionLoopsE1DetectorItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("E1");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement inductionLoopsE1DetectorItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("inductionLoop");

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

    // Set atribute splitByType
    if (splitByType)
    {
        itemDomElement.setAttribute("splitByType", "true");
    }
    else
    {
        itemDomElement.setAttribute("splitByType", "false");
    }

    // Return itemDomElement
    return itemDomElement;
}

void inductionLoopsE1DetectorItem::addFlowMeasure(flowMeasureItem *fm)
{
    listOfFlowMeasures.push_back(fm);
}

void inductionLoopsE1DetectorItem::removeFlowMeasure(flowMeasureItem *fm)
{
    // Remove flowMeasure
    listOfFlowMeasures.removeAll(fm);
}

int inductionLoopsE1DetectorItem::getNumberOfFlowMeasures() const
{
    return listOfFlowMeasures.size();
}

void inductionLoopsE1DetectorItem::clearFlowMeasures() const
{
    // Create a copy of list of flow measures
    QList<flowMeasureItem *> copyOfListOfFlowMeasures;

    // Iterate over list
    for(QList<flowMeasureItem *>::iterator i = copyOfListOfFlowMeasures.begin(); i != copyOfListOfFlowMeasures.end(); i++)
    {
        // Delete flow measure
        delete (*i);
    }
}

flowMeasureItem *inductionLoopsE1DetectorItem::getFirstFlowMeasure()
{
    // If listOfFlowMeasures isn't empty
    if(listOfFlowMeasures.size() > 0)
    {
        return listOfFlowMeasures.first();
    }
    else
    {
        return NULL;
    }
}

flowMeasureItem *inductionLoopsE1DetectorItem::getLastFlowMeasure()
{
    if(listOfFlowMeasures.size() > 0)
    {
        return listOfFlowMeasures.last();
    }
    else
    {
        return NULL;
    }
}

void inductionLoopsE1DetectorItem::setSplitByType(bool newSplitByType)
{
    splitByType = newSplitByType;
}

void inductionLoopsE1DetectorItem::setFriendlyPos(bool newFriendlyPos)
{
    friendlyPos = newFriendlyPos;
}

bool inductionLoopsE1DetectorItem::isFriendlyPosEnabled()
{
    return friendlyPos;
}

bool inductionLoopsE1DetectorItem::isSplitByTypeEnabled()
{
    return splitByType;
}

void inductionLoopsE1DetectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

void inductionLoopsE1DetectorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath inductionLoopsE1DetectorItem::shape() const
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



QList<flowMeasureItem *>::iterator inductionLoopsE1DetectorItem::flowMeasuresBegin()
{
    return listOfFlowMeasures.begin();
}

QList<flowMeasureItem *>::iterator inductionLoopsE1DetectorItem::flowMeasuresEnd()
{
    return listOfFlowMeasures.end();
}

