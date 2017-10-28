#include "edgeItem.h"

// Configuration
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/edges/edgeItemConfiguration.h"
#include "../../configuration/items/nodeItemConfiguration.h"
#include "../../configuration/items/laneItemConfiguration.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"
#include "../../database/edges/edgeTable.h"
#include "../../database/turnRatios/turnRatioIntervalTable.h"

// Items
#include "edgeTypeItem.h"
#include "../nodeItem.h"
#include "../laneItem.h"
#include "../routeItem.h"
#include "../distributionFunctionItem.h"
#include "../detectors/inductionLoopsE1DetectorItem.h"
#include "../detectors/laneAreaE2DetectorItem.h"
#include "../detectors/multiEntryExitE3DetectorItem.h"
#include "../flowMeasureItem.h"
#include "../turnRatios/turnRatioItem.h"
#include "../turnRatios/turnRatioIntervalItem.h"


edgeItem::edgeItem(nodeItem *newOrigin, nodeItem *newDestiny, eNetEditorDatabase *database) : abstractEdgeItem(database->getEdgeTable())
{
    // Set pointer to node origin
    nodeOrigin = newOrigin;

    // Set pointer to node destiny
    nodeDestiny = newDestiny;

    // Set ID
    eNetEditorItem::setItemId(nodeOrigin->getItemId() + "to" + nodeDestiny->getItemId());

    // By default type of edge is NULL
    type = NULL;

    // Set Speed of edge
    speed = getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeDefaultSpeed();

    // Set priority of edge
    priority = getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeDefaultPriority();

    // Set Spreadtype
    spreadType = getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeItemDefaultSpreadTyp();

    // Set Streetname
    name = getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeItemDefaultName();

    // Set end Offset
    endOffset = getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeItemDefaultEndOffset();

    // Set Sidewalk Width
    sidewalkWidth = getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeDefaultSidewalkWidth();

    // By default edge don't have a distribution function
    distributionFunction = NULL;

    // Set Label of edge
    setItemLabel("Edge " + this->getItemId() + " ➜");

    // Set pen size
    setItemPen(getProjectConfiguration()->getEdgeItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getEdgeItemConfiguration()->getItemPenSize());

    // Set font
    setItemFontText(getProjectConfiguration()->getEdgeItemConfiguration()->getItemTextFont(), getProjectConfiguration()->getEdgeItemConfiguration()->getItemTextSize());

    // Set pen text size
    setItemPenText(getProjectConfiguration()->getEdgeItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getEdgeItemConfiguration()->getItemTextPenSize());

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getEdgeItemConfiguration()->getItemAltitude());

    // Insert edge in the list of edges of each node
    nodeOrigin->addOutcomingEdge(this);
    nodeDestiny->addIncomingEdge(this);

    // An Edge has always as minimum one Lane, then create a lane
    new laneItem(this, database);

    // An Edge has always one distribution function, then a new distribution function has to be inserted
    new distributionFunctionItem(this, database);

    // Declare temporal turn Ratio Interval
    turnRatioIntervalItem *triAux = NULL;

    // Iterate over turn Ratios Intervals of datahbase
    for(QList<eNetEditorItem *>::iterator i = getDatabase()->getTurnRatioIntervalTable()->iteratorTableBegin(); i != getDatabase()->getTurnRatioIntervalTable()->iteratorTableEnd(); i++)
    {
        // Cast turnRatioIntervalItem
        triAux = dynamic_cast<turnRatioIntervalItem *>(*i);

        // If turnRatioIntervalItem was casted correctly
        if(triAux)
        {
            // Iterate over incoming Edgges of node Origin
            for(QList<edgeItem *>::iterator j = nodeOrigin->iteratorIncomingEdgesBegin(); j != nodeOrigin->iteratorIncomingEdgesEnd(); j++)
            {
                // Create new Turn Ratio
                new turnRatioItem(triAux, (*j), this, getDatabase());
            }

            // Iterate over outcoming Edgges of node Origin
            for(QList<edgeItem *>::iterator j = nodeOrigin->iteratorOutcomingEdgesBegin(); j != nodeOrigin->iteratorOutcomingEdgesEnd(); j++)
            {
                // Create new Turn Ratio
                new turnRatioItem(triAux, this, (*j), getDatabase());
            }
        }
    }

    // Make visual edge
    make();
}

edgeItem::~edgeItem()
{
    // Clear Lanes
    clearLanes(false);

    // Clear Routes
    clearRoutes();

    // Clear detector E1 (Shoul be already empty)
    clearInductionLoopsE1Detector();

    // Clar Detector E2 (Shoul be already empty)
    clearLaneAreaE2Detector();

    // Clear Detector E3 (Shoul be already empty)
    clearMultiEntryExitE3Detector();

    // Clear Flow measures (Shoul be already empty)
    clearFlowMeasure();

    // Clear turn Ratios From
    clearTurnRatioFrom();

    // Clear turn Ratios To
    clearTurnRatioTo();

    // Remove references to edge in the nodes
    nodeOrigin->removeOutcomingEdge(this);
    nodeDestiny->removeIncomingEdge(this);
}

void edgeItem::make()
{
    // Move matrix to center of Node origin
    setPos(nodeOrigin->scenePos());

    // Do a rotation using as reference the position of both nodes
    setRotation(360.0 - QLineF(nodeOrigin->scenePos(), nodeDestiny->scenePos()).angle());

    // Set distanceBetweenCenters
    distanceBetweenCenters = sqrt( pow( (nodeDestiny->getPosx() - nodeOrigin->getPosx()), 2) +
                                   pow( (nodeDestiny->getPosy() - nodeOrigin->getPosy()), 2) );

    // Set the rect of the edge
    edgeRect = QRectF(nodeOrigin->getCurrentlyDiametre() * 0.5, listOfLanes.size() * getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth(), distanceBetweenCenters - (nodeOrigin->getCurrentlyDiametre() * 0.5) - (nodeDestiny->getCurrentlyDiametre() * 0.5), getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeWidth());

    // Set the Bounding rect
    setBoundingRect(edgeRect);

    // Set rect Icon
    iconRect.setTopRight(edgeRect.topRight() + QPointF(getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeIconOffset() * -1, getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeIconOffset()));
    iconRect.setBottomLeft(edgeRect.bottomRight() + QPointF((getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeWidth() * -1) + getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeIconOffset(), -1 * getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeIconOffset()));

    // Remake all lanes of the edge
    for(QList<laneItem *>::iterator i = listOfLanes.begin(); i != listOfLanes.end(); i++)
    {
        (*i)->make();
    }

    // Remake all routes of the edge
    for(QList<routeItem *>::iterator i = listOfRoutes.begin(); i != listOfRoutes.end(); i++)
    {
        (*i)->make();
    }
}

QDomElement edgeItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("edge");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement edgeItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("edge");

    // Set atribute id
    itemDomElement.setAttribute("id", getItemId());

    // Set atribute from
    itemDomElement.setAttribute("from", nodeOrigin->getItemId());

    // Set atribute to
    itemDomElement.setAttribute("to", nodeDestiny->getItemId());

    // If type was defined
    if(type != NULL)
    {
        // Set atribute type
        itemDomElement.setAttribute("type", type->getItemId());
    }
    else
    {
        // Set atribute numLanes
        itemDomElement.setAttribute("numLanes", QString::number(listOfLanes.size()));

        // Set atribute speed
        itemDomElement.setAttribute("speed", QString::number(speed));

        // Set atribute priority
        itemDomElement.setAttribute("priority", QString::number(priority));

        // Set atribute length
        itemDomElement.setAttribute("length", QString::number(getLength()));

        // Set atribute shape
        itemDomElement.setAttribute("shape", "");

        // Set atribute spreadType
        itemDomElement.setAttribute("spreadType", getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeSpreadTypeValue(spreadType));

        // If name != ""
        if(name != "")
        {
            // Set atribute name
            itemDomElement.setAttribute("name", name);
        }

        // Set atribute endOffset
        itemDomElement.setAttribute("endOffset", QString::number(endOffset));

        // Set atribute sidewalkWidth
        itemDomElement.setAttribute("sidewalkWidth", QString::number(sidewalkWidth));
    }

    // Iterate over list of lanes
    for(QList<laneItem *>::iterator i = listOfLanes.begin(); i != listOfLanes.end(); i++)
    {
        // Append lane Dom Element
        itemDomElement.appendChild((*i)->exportItemToXML(domDoc));
    }

    // Return itemDomElement
    return itemDomElement;
}

void edgeItem::updateEdgeLabel()
{
    // Set name to show over the edge
    setItemLabel("Edge " + this->getItemId() + " ➜");

    // Update names of the lanes
    for(QList<laneItem *>::iterator i = listOfLanes.begin(); i != listOfLanes.end(); i++)
    {
        (*i)->updateLaneLabel();
    }
}

void edgeItem::addLane(laneItem *l)
{
    // Insert Lane in the lane list
    listOfLanes.push_back(l);

    // Remake node origin
    nodeOrigin->make();

    // Remake node destiny
    nodeDestiny->make();

    // Remake IDs
    for(QList<laneItem *>::iterator i = listOfLanes.begin(); i != listOfLanes.end(); i++)
    {
        (*i)->updateLaneLabel();
    }
}

void edgeItem::removeLane(laneItem *l)
{
    // Remove lane of list
    listOfLanes.removeAll(l);

    // Remake node origin
    nodeOrigin->make();

    // Remake node destiny
    nodeDestiny->make();

    // Remake IDs
    for(QList<laneItem *>::iterator i = listOfLanes.begin(); i != listOfLanes.end(); i++)
    {
        (*i)->updateLaneLabel();
    }
}

void edgeItem::clearLanes(bool dontRemoveFirstLane)
{
    // Create copy of the list whit the lanes of edge.
    QList<laneItem *> copyOfListOfLanes = listOfLanes;

    // If dontRemoveFirstLane is enabled and number of lanes is more than 0
    if((dontRemoveFirstLane == true) && (listOfLanes.size() > 0))
    {
        // Remove first lane of the list of lanes
        copyOfListOfLanes.removeAll(listOfLanes.first());
    }

    // Iterate over copy of list of lanes
    for(QList<laneItem *>::iterator i = copyOfListOfLanes.begin(); i != copyOfListOfLanes.end(); i++)
    {
        // Delete lane
        delete (*i);
    }
}

void edgeItem::addRoute(routeItem *r)
{
    // Insert route in the route list
    listOfRoutes.push_back(r);
}

void edgeItem::removeRoute(routeItem *r)
{
    // Erase route of list
    listOfRoutes.removeAll(r);
}

void edgeItem::clearRoutes()
{
    // Create copy of the list with the routes that contains this edge
    QList<routeItem *> copyOfListOfRoutes = listOfRoutes;

    // Iterate over list of routes
    for(QList<routeItem *>::iterator i = copyOfListOfRoutes.begin(); i != copyOfListOfRoutes.end(); i++)
    {
        // Delete route
        delete (*i);
    }
}

void edgeItem::addInductionLoopsE1Detector(inductionLoopsE1DetectorItem *E1)
{
    listOfE1.push_back(E1);
}

void edgeItem::removeInductionLoopsE1Detector(inductionLoopsE1DetectorItem *E1)
{
    listOfE1.removeAll(E1);
}

void edgeItem::clearInductionLoopsE1Detector()
{
    // Create copy of the list whit the E1 detector associated with this edge.
    QList<inductionLoopsE1DetectorItem *> copyOfListOfE1 = listOfE1;

    // Iterate over copy of list of E1
    for(QList<inductionLoopsE1DetectorItem *>::iterator i = copyOfListOfE1.begin(); i != copyOfListOfE1.end(); i++)
    {
        // Delete E1
        delete (*i);
    }
}

void edgeItem::addLaneAreaE2Detector(laneAreaE2DetectorItem *E2)
{
    listOfE2.push_back(E2);
}

void edgeItem::removeLaneAreaE2Detector(laneAreaE2DetectorItem *E2)
{
    listOfE2.removeAll(E2);
}

void edgeItem::clearLaneAreaE2Detector()
{
    // Create copy of the list whit the E2 detector associated with this edge.
    QList<laneAreaE2DetectorItem *> copyOfListOfE2 = listOfE2;

    // Iterate over copy of list of E2
    for(QList<laneAreaE2DetectorItem *>::iterator i = copyOfListOfE2.begin(); i != copyOfListOfE2.end(); i++)
    {
        // Delete E2
        delete (*i);
    }
}

void edgeItem::addMultiEntryExitE3Detector(multiEntryExitE3DetectorItem *E3)
{
    listOfE3.push_back(E3);
}

void edgeItem::removeMultiEntryExitE3Detector(multiEntryExitE3DetectorItem *E3)
{
    listOfE3.removeAll(E3);
}

void edgeItem::clearMultiEntryExitE3Detector()
{
    // Create copy of the list whit the E3 detector associated with this edge.
    QList<multiEntryExitE3DetectorItem *> copyOfListOfE3 = listOfE3;

    // Iterate over copy of list of E3
    for(QList<multiEntryExitE3DetectorItem *>::iterator i = copyOfListOfE3.begin(); i != copyOfListOfE3.end(); i++)
    {
        // Delete E3
        delete (*i);
    }
}

void edgeItem::addFlowMeasure(flowMeasureItem *fm)
{
    listOfFlowMeasures.push_back(fm);
}

void edgeItem::removeFlowMeasure(flowMeasureItem *fm)
{
    listOfFlowMeasures.removeAll(fm);
}

void edgeItem::clearFlowMeasure()
{
    // Create copy of the list whit the Flow measures associated with this edge.
    QList<flowMeasureItem *> copyOfListOfFlowMeasures = listOfFlowMeasures;

    // Iterate over copy of list of Flow measures
    for(QList<flowMeasureItem *>::iterator i = copyOfListOfFlowMeasures.begin(); i != copyOfListOfFlowMeasures.end(); i++)
    {
        // Delete flow measure
        delete (*i);
    }
}

void edgeItem::addTurnRatioFrom(turnRatioItem *tr)
{
    listOfTurnRatiosFrom.push_back(tr);
}

void edgeItem::removeTurnRatioFrom(turnRatioItem *tr)
{
    listOfTurnRatiosFrom.removeAll(tr);
}

void edgeItem::clearTurnRatioFrom()
{
    // Create copy of the list whit the turn Ratios associated with this edge.
    QList<turnRatioItem *> copyOfListOfturnRatiosFrom = listOfTurnRatiosFrom;

    // Iterate over copy of list of turn Ratios
    for(QList<turnRatioItem *>::iterator i = copyOfListOfturnRatiosFrom.begin(); i != copyOfListOfturnRatiosFrom.end(); i++)
    {
        // Delete turn Ratio
        delete (*i);
    }
}

void edgeItem::addTurnRatioTo(turnRatioItem *tr)
{
    listOfTurnRatiosTo.push_back(tr);
}

void edgeItem::removeTurnRatioTo(turnRatioItem *tr)
{
    listOfTurnRatiosTo.removeAll(tr);
}

void edgeItem::clearTurnRatioTo()
{
    // Create copy of the list whit the turn Ratios associated with this edge.
    QList<turnRatioItem *> copyOfListOfturnRatiosTo = listOfTurnRatiosTo;

    // Iterate over copy of list of turn Ratios
    for(QList<turnRatioItem *>::iterator i = copyOfListOfturnRatiosTo.begin(); i != copyOfListOfturnRatiosTo.end(); i++)
    {
        // Delete turn Ratio
        delete (*i);
    }
}

nodeItem *edgeItem::getNodeOrigin() const
{
    return nodeOrigin;
}

nodeItem *edgeItem::getNodeDestiny() const
{
    return nodeDestiny;
}

edgeTypeItem *edgeItem::getType() const
{
    return type;
}

int edgeItem::getNumberOfLanes() const
{
    return listOfLanes.size();
}

qreal edgeItem::getSpeed() const
{
    return speed;
}

int edgeItem::getPriority() const
{
    return priority;
}

qreal edgeItem::getLength() const
{
    return getCentralLine().length();
}

edgeSpreadType edgeItem::getSpreadType() const
{
    return spreadType;
}

const QString &edgeItem::getStreetName() const
{
    return name;
}

laneItem *edgeItem::getLane(int index)
{
    if(index < listOfLanes.size())
    {
        return listOfLanes.at(index);
    }
    else
    {
        return NULL;
    }
}

routeItem *edgeItem::getRoute(int index)
{
    if(index < listOfRoutes.size())
    {
        return listOfRoutes.at(index);
    }
    else
    {
        return NULL;
    }
}

QLineF edgeItem::getExternalLine() const
{
    return QLineF(edgeRect.bottomLeft(), edgeRect.bottomRight());
}

QLineF edgeItem::getCentralLine() const
{
    return QLineF(edgeRect.bottomLeft() - QPointF(0, getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeWidth() * 0.5), edgeRect.bottomRight() - QPointF(0, getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeWidth() * 0.5));
}

QLineF edgeItem::getInternalLine() const
{
    return QLineF(edgeRect.topLeft(), edgeRect.topRight());
}

qreal edgeItem::getDistanceBetweenCenters() const
{
    return distanceBetweenCenters;
}

distributionFunctionItem *edgeItem::getDistributionFunction() const
{
    return distributionFunction;
}

int edgeItem::getNumberOfRoutes() const
{
    return listOfRoutes.size();
}

int edgeItem::getNumberOfInductionLoopsE1Detectors() const
{
    return listOfE1.size();
}

int edgeItem::getNumberOfFlowMeasures() const
{
    return listOfFlowMeasures.size();
}

laneItem *edgeItem::getLaneByIndex(int index) const
{
    if(index < listOfLanes.size())
    {
        return listOfLanes.at(index);
    }
    else
    {
        return NULL;
    }
}

laneItem *edgeItem::getFirstLane() const
{
    if(!listOfLanes.empty())
    {
        return listOfLanes.first();
    }
    else
    {
        return NULL;
    }
}

laneItem *edgeItem::getLastLane() const
{
    if(!listOfLanes.empty())
    {
        return listOfLanes.last();
    }
    else
    {
        return NULL;
    }
}

routeItem *edgeItem::getFirstRoute() const
{
    if(listOfRoutes.size() > 0)
    {
        return listOfRoutes.first();
    }
    else
    {
        return NULL;
    }
}

routeItem *edgeItem::getLastRoute() const
{
    if(listOfRoutes.size() > 0)
    {
        return listOfRoutes.last();
    }
    else
    {
        return NULL;
    }
}

inductionLoopsE1DetectorItem *edgeItem::getFirstInductionLoopsE1Detector() const
{
    if(listOfE1.size() > 0)
    {
        return listOfE1.first();
    }
    else
    {
        return NULL;
    }
}

inductionLoopsE1DetectorItem *edgeItem::getLastInductionLoopsE1Detector() const
{
    if(listOfE1.size() > 0)
    {
        return listOfE1.last();
    }
    else
    {
        return NULL;
    }
}

flowMeasureItem *edgeItem::getFirstFlowMeasure() const
{
    if(listOfFlowMeasures.size() > 0)
    {
        return listOfFlowMeasures.first();
    }
    else
    {
        return NULL;
    }
}

flowMeasureItem *edgeItem::getLastFlowMeasure() const
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

void edgeItem::setItemId(const QString &newId)
{
    if(newId == "")
    {
        eNetEditorItem::setItemId(nodeOrigin->getItemId() + "to" + nodeDestiny->getItemId());
    }
    else
    {
        eNetEditorItem::setItemId(newId);
    }

    for(QList<laneItem *>::iterator i = listOfLanes.begin(); i != listOfLanes.end(); i++)
    {
        (*i)->setItemId();
    }
}

void edgeItem::setType(edgeTypeItem *newType)
{
    type = newType;
}

void edgeItem::setSpeed(qreal newSpeed)
{
    speed = newSpeed;
}

void edgeItem::setPriority(const int newPriority)
{
    priority = newPriority;
}

void edgeItem::setSpreadType(edgeSpreadType newSpreadType)
{
    spreadType = newSpreadType;
}

void edgeItem::setStreetName(const QString &newStreetName)
{
    name = newStreetName;
}

void edgeItem::setDistributionFunction(distributionFunctionItem *newFunction)
{
    distributionFunction = newFunction;
}

QList<laneItem *>::iterator edgeItem::iteratorLanesBegin()
{
    return listOfLanes.begin();
}

QList<laneItem *>::iterator edgeItem::iteratorLanesEnd()
{
    return listOfLanes.end();
}

QList<routeItem *>::iterator edgeItem::iteratorRoutesBegin()
{
    return listOfRoutes.begin();
}

QList<routeItem *>::iterator edgeItem::iteratorRoutesEnd()
{
    return listOfRoutes.end();
}

QList<inductionLoopsE1DetectorItem *>::iterator edgeItem::iteratorInductionLoopsE1Begin()
{
    return listOfE1.begin();
}

QList<inductionLoopsE1DetectorItem *>::iterator edgeItem::iteratorInductionLoopsE1End()
{
    return listOfE1.end();
}

QList<flowMeasureItem *>::iterator edgeItem::iteratorFlowMeasureBegin()
{
    return listOfFlowMeasures.begin();
}

QList<flowMeasureItem *>::iterator edgeItem::iteratorFlowMeasureEnd()
{
    return listOfFlowMeasures.end();
}

QList<turnRatioItem *>::iterator edgeItem::iteratorTurnRatioFromBegin()
{
    return listOfTurnRatiosFrom.begin();
}

QList<turnRatioItem *>::iterator edgeItem::iteratorTurnRatioFromEnd()
{
    return listOfTurnRatiosFrom.end();
}

QList<turnRatioItem *>::iterator edgeItem::iteratorTurnRatioToBegin()
{
    return listOfTurnRatiosTo.begin();
}

QList<turnRatioItem *>::iterator edgeItem::iteratorTurnRatioToEnd()
{
    return listOfTurnRatiosTo.end();
}

void edgeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // if Draw item is enabled
    if(getParameterManager()->isShowAllEdgeItems())
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
        painter->drawRect(edgeRect);

        // If flag ShowLabels is enabled
        if(getParameterManager()->isEdgeShowLabelEnabled())
        {
            // Set the modified font to the painter
            painter->setFont(getItemFontText());

            // Add pen to painter
            painter->setPen(getItemPenText());

            // Draw text with the label
            painter->drawStaticText(edgeRect.topLeft() + QPointF( (edgeRect.size().width() / 2.0) - 5.5, -0.75 ), getItemLabel());
        }

        // If showIcon is enabled
        if(getParameterManager()->isNodesShowIconEnabled())
        {
            // Get pointer to the pixmax correspond to type of edge destiny
            QPixmap *signalIcon = getProjectConfiguration()->getNodeItemConfiguration()->NodeSignalIcon(nodeDestiny->getType());

            // Draw icon
            painter->drawPixmap(iconRect, *signalIcon, signalIcon->rect());
        }
    }
}

void edgeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath edgeItem::shape() const
{
    // Declare QPainterPath
    QPainterPath path;

    // If the item isn't blocked
    if(getParameterManager()->isEdgeBlocked() == false)
    {
        // Add path
        path.addRect(edgeRect);
    }

    // Return new path
    return path;
}




