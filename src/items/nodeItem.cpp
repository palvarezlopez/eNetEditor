#include "nodeItem.h"

// Configuration
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/nodeItemConfiguration.h"
#include "../configuration/items/trafficLightItemConfiguration.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// Database
#include "../database/eNetEditorDatabase.h"
#include "../database/nodeTable.h"

// Items
#include "edges/edgeItem.h"
#include "laneItem.h"
#include "trafficLightItem.h"
#include "connectionItem.h"
#include "prohibitionItem.h"
#include "turnRatios/turnRatioIntervalItem.h"
#include "turnRatios/turnRatioItem.h"


nodeItem::nodeItem(const QString &newId, qreal posx, qreal posy, eNetEditorDatabase *database) : eNetEditorItem(database->getNodeTable(), "red", "darkred")
{
    // Set node ID
    eNetEditorItem::setItemId(newId);

    // Set node Name
    setItemLabel(newId);

    // Set node position
    setPos(posx, posy);

    // By default, elevation of node is 0
    z = getProjectConfiguration()->getNodeItemConfiguration()->getNodeDefaultPosz();

    // By default, type of node is "priority"
    type = getProjectConfiguration()->getNodeItemConfiguration()->getNodeDefaultType();

    // By default, there are not a associated Traffic Light
    tLight = NULL;

    // Set currently diametre
    currentlyDiametre = 0;

    // Set pen size
    setItemPen(getProjectConfiguration()->getNodeItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getNodeItemConfiguration()->getItemPenSize());

    // Set font
    setItemFontText(getProjectConfiguration()->getNodeItemConfiguration()->getItemTextFont(), getProjectConfiguration()->getNodeItemConfiguration()->getItemTextSize());

    // Set pen text size
    setItemPenText(getProjectConfiguration()->getNodeItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getNodeItemConfiguration()->getItemTextPenSize());

    // if newId is not defined manually
    if(newId == "")
    {
        // Set the correspond index to maintain the integrity
        setItemId(QString::number(getDatabase()->getNodeTable()->getIndex()));

        // Update nextIndex
        getDatabase()->getNodeTable()->updateIndex();
    }

    // When a node is created, flag "Node" is activated, then is NOT selectable
    setItemSelectable(false);

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getNodeItemConfiguration()->getItemAltitude());

    /** Nota para futuras revisiones: Sería conveniente mirar primero que la ID nueva no exista
     * en caso de que se añada en la cabecera manualmente **/


    // Make Node
    make();
}

nodeItem::~nodeItem()
{
    // Clear incoming edges
    clearIncomingEdge();

    // Clear outcoming edges
    clearOutcomingEdge();

    // Clear Conections (Should be already empty)
    clearConnection();

    // Clear prohibitions (Should be already empty)
    clearProhibition();

    // clear turn Ratios
    clearTurnRatio();
}

void nodeItem::make()
{
    // Declare int to count the max number of lanes and set the diametre of node
    int maxNumberOfLanes = 2;

    // Iterate over list of incomings edges
    for(QList<edgeItem *>::iterator i = listOfIncomingsEdges.begin(); i != listOfIncomingsEdges.end(); i++)
    {
        // Keep the maximal number of lanes
        if((*i)->getNumberOfLanes() > maxNumberOfLanes)
        {
            maxNumberOfLanes = (*i)->getNumberOfLanes();
        }
    }

    // Iterate over list of outcomings edges
    for(QList<edgeItem *>::iterator i = listOfOutcomingsEdges.begin(); i != listOfOutcomingsEdges.end(); i++)
    {
        // Keep the maximal number of lanes
        if((*i)->getNumberOfLanes() > maxNumberOfLanes)
        {
            maxNumberOfLanes = (*i)->getNumberOfLanes();
        }
    }

    // Set the currently Diametre
    currentlyDiametre = (maxNumberOfLanes * 4);

    // Set bounding Rect
    setBoundingRect(QRectF(-0.5 * currentlyDiametre, -0.5 * currentlyDiametre, currentlyDiametre, currentlyDiametre));

    // Remake all incomings edges of the node
    for(QList<edgeItem *>::iterator i = listOfIncomingsEdges.begin(); i != listOfIncomingsEdges.end(); i++)
    {
        // Make incomings edge
        (*i)->make();
    }

    // Remake all outcomingsedges of the node
    for(QList<edgeItem *>::iterator i = listOfOutcomingsEdges.begin(); i != listOfOutcomingsEdges.end(); i++)
    {
        // Make outcoming edge
        (*i)->make();
    }
}

QDomElement nodeItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("node");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement nodeItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("node");

    // Save Id of item
    itemDomElement.setAttribute("id", getItemId());

    // Set atribute x
    itemDomElement.setAttribute("x", QString::number(pos().x()));

    // Set atribute y
    itemDomElement.setAttribute("y", QString::number(pos().y() * (-1)));

    // Set atribute z
    itemDomElement.setAttribute("z", QString::number(z));

    // Set atribute type
    itemDomElement.setAttribute("type", getProjectConfiguration()->getNodeItemConfiguration()->getNodeTypeValue(type));

    // if Traffic light was defined
    if(tLight != NULL)
    {
        // Set atribute tl
        itemDomElement.setAttribute("tl", tLight->getItemId());

        // Set atribute tlType
        itemDomElement.setAttribute("tlType", getProjectConfiguration()->getTrafficLightItemConfiguration()->getTrafficLightTypeValue(tLight->getType()));
    }
    /**
        // Set atribute radius
        itemDomElement.setAttribute("radius", QString::number());

        // Set atribute shape
        itemDomElement.setAttribute("shape", QString::number());

        // Set atribute keepClear
        itemDomElement.setAttribute("keepClear", QString::number());

        // Set atribute controlledInner
        itemDomElement.setAttribute("controlledInner", QString::number());
    **/
    // Return itemDomElement
    return itemDomElement;
}

void nodeItem::addIncomingEdge(edgeItem *e)
{
    // Add Outcoming Edge
    listOfIncomingsEdges.push_back(e);
}

void nodeItem::addOutcomingEdge(edgeItem *e)
{
    // Add Outcoming Edge
    listOfOutcomingsEdges.push_back(e);
}

void nodeItem::removeIncomingEdge(edgeItem *e)
{
    // Remove edge of list
    listOfIncomingsEdges.removeAll(e);
}

void nodeItem::clearIncomingEdge()
{
    // Create a copy of the list of incoming edges
    QList<edgeItem *> copyOfListOfIncomingsEdges = listOfIncomingsEdges;

    // Iterate over copy of list of incoming edges
    for(QList<edgeItem *>::iterator i = copyOfListOfIncomingsEdges.begin(); i != copyOfListOfIncomingsEdges.end(); i++)
    {
        // Delete edge
        delete (*i);
    }
}

void nodeItem::removeOutcomingEdge(edgeItem *e)
{
    // Remove edge of list
    listOfOutcomingsEdges.removeAll(e);
}

void nodeItem::clearOutcomingEdge()
{
    // Create copy of list of Outcomings Edges
    QList<edgeItem *> copyOfListOfOutcomingsEdges = listOfOutcomingsEdges;

    // Iterate over copy of list of Outcomings edges
    for(QList<edgeItem *>::iterator i = copyOfListOfOutcomingsEdges.begin(); i != copyOfListOfOutcomingsEdges.end(); i++)
    {
        // Delete edge
        delete (*i);
    }
}

void nodeItem::addConnection(connectionItem *c)
{
    listOfConnections.push_back(c);
}

void nodeItem::removeConnection(connectionItem *c)
{
    listOfConnections.removeAll(c);
}

void nodeItem::clearConnection()
{
    // Create copy of list of connections
    QList<connectionItem *> copyOfListOfConnections = listOfConnections;

    // Iterate over copy of list of connection
    for(QList<connectionItem *>::iterator i = copyOfListOfConnections.begin(); i != copyOfListOfConnections.end(); i++)
    {
        // Delete connection
        delete (*i);
    }
}

void nodeItem::addProhibition(prohibitionItem *p)
{
    listOfProhibitions.push_back(p);
}

void nodeItem::removeProhibition(prohibitionItem *p)
{
    listOfProhibitions.removeAll(p);
}

void nodeItem::clearProhibition()
{
    // Create copy of list of prohibition
    QList<prohibitionItem *> copyOfListOfProhibitions = listOfProhibitions;

    // Iterate over copy of list of prohibition
    for(QList<prohibitionItem *>::iterator i = copyOfListOfProhibitions.begin(); i != copyOfListOfProhibitions.end(); i++)
    {
        // Delete prohibition
        delete (*i);
    }
}



void nodeItem::addTurnRatio(turnRatioItem *tr)
{
    listOfTurnRatios.push_back(tr);
}

void nodeItem::removeTurnRatio(turnRatioItem *tr)
{
    listOfTurnRatios.removeAll(tr);
}

void nodeItem::clearTurnRatio()
{
    // Create copy of list of turn Ratios
    QList<turnRatioItem *> copyOfListOfTurnRatios = listOfTurnRatios;

    // Iterate over copy of list of turn Ratios
    for(QList<turnRatioItem *>::iterator i = copyOfListOfTurnRatios.begin(); i != copyOfListOfTurnRatios.end(); i++)
    {
        // Delete turn Ratios
        delete (*i);
    }
}

qreal nodeItem::getPosx() const
{
    return this->pos().x();
}

qreal nodeItem::getPosy() const
{
    return this->pos().y();
}

qreal nodeItem::getPosz() const
{
    return z;
}

nodeItemType nodeItem::getType() const
{
    return type;
}

int nodeItem::getCurrentlyDiametre() const
{
    return currentlyDiametre;
}

trafficLightItem *nodeItem::getTrafficLight() const
{
    return tLight;
}

int nodeItem::getNumberOfIncomingEdges() const
{
    return listOfIncomingsEdges.size();
}

int nodeItem::getNumberOfOutcomingEdges() const
{
    return listOfOutcomingsEdges.size();
}

int nodeItem::getNumberOfConnections() const
{
    return listOfConnections.size();
}

int nodeItem::getNumberOfProhibitions() const
{
    return listOfProhibitions.size();
}



int nodeItem::getNumberOfTurnRatios() const
{
    return listOfTurnRatios.size();
}

edgeItem *nodeItem::getFirstIncomingEdge() const
{
    if(listOfIncomingsEdges.size() > 0)
    {
        return listOfIncomingsEdges.first();
    }
    else
    {
        return NULL;
    }
}

edgeItem *nodeItem::getLastIncomingEdge() const
{
    if(listOfIncomingsEdges.size() > 0)
    {
        return listOfIncomingsEdges.last();
    }
    else
    {
        return NULL;
    }
}

edgeItem *nodeItem::getFirstOutcomingEdge() const
{
    if(listOfOutcomingsEdges.size() > 0)
    {
        return listOfOutcomingsEdges.first();
    }
    else
    {
        return NULL;
    }
}

edgeItem *nodeItem::getLastOutcomingEdge() const
{
    if(listOfOutcomingsEdges.size() > 0)
    {
        return listOfOutcomingsEdges.last();
    }
    else
    {
        return NULL;
    }
}

connectionItem *nodeItem::getFirstConnection() const
{
    if(listOfConnections.size() > 0)
    {
        return listOfConnections.first();
    }
    else
    {
        return NULL;
    }
}

connectionItem *nodeItem::getLastConnection() const
{
    if(listOfConnections.size() > 0)
    {
        return listOfConnections.last();
    }
    else
    {
        return NULL;
    }
}

prohibitionItem *nodeItem::getFirstProhibition() const
{
    if(listOfProhibitions.size() > 0)
    {
        return listOfProhibitions.first();
    }
    else
    {
        return NULL;
    }
}

prohibitionItem *nodeItem::getLastProhibition() const
{
    if(listOfProhibitions.size() > 0)
    {
        return listOfProhibitions.last();
    }
    else
    {
        return NULL;
    }
}

turnRatioItem *nodeItem::getFirstTurnRatio() const
{
    if(listOfTurnRatios.size() > 0)
    {
        return listOfTurnRatios.last();
    }
    else
    {
        return NULL;
    }
}

turnRatioItem *nodeItem::getLastTurnRatio() const
{
    if(listOfTurnRatios.size() > 0)
    {
        return listOfTurnRatios.last();
    }
    else
    {
        return NULL;
    }
}

edgeItem *nodeItem::getIncomingEdgeByIndex(int index) const
{
    if(index < listOfIncomingsEdges.size())
    {
        return listOfIncomingsEdges.at(index);
    }
    else
    {
        return NULL;
    }
}

edgeItem *nodeItem::getOutcomingEdgeByIndex(int index) const
{
    if(index < listOfOutcomingsEdges.size())
    {
        return listOfOutcomingsEdges.at(index);
    }
    else
    {
        return NULL;
    }
}

connectionItem *nodeItem::getConnectionByIndex(int index) const
{
    if(index < listOfConnections.size())
    {
        return listOfConnections.at(index);
    }
    else
    {
        return NULL;
    }
}

prohibitionItem *nodeItem::getProhibitionByIndex(int index) const
{
    if(index < listOfProhibitions.size())
    {
        return listOfProhibitions.at(index);
    }
    else
    {
        return NULL;
    }
}

QList<turnRatioItem *> nodeItem::getListOfTurnRatiosByEdgeFrom(edgeItem *e)
{
    // Declare list of turn Ratios
    QList<turnRatioItem *> listOfTurnRatiosByEdgeFrom;

    // Iterate over list of turn ratios of interval
    for(QList<turnRatioItem *>::iterator i = listOfTurnRatios.begin(); i != listOfTurnRatios.end(); i++)
    {
        // If edgeFrom is == to e
        if((*i)->getEdgeFrom() == e)
        {
            // Add turnRatioItem to list
            listOfTurnRatiosByEdgeFrom.push_back(*i);
        }
    }

    // Return list of turn Ratios
    return listOfTurnRatiosByEdgeFrom;
}

void nodeItem::setItemId(const QString &newID)
{
    // Set Node ID
    eNetEditorItem::setItemId(newID);

    // Update the names of all edges
    for(QList<edgeItem *>::iterator i = listOfIncomingsEdges.begin(); i != listOfIncomingsEdges.end(); i++)
    {
        (*i)->setItemId();
    }

    // Update Id's of all edges
    for(QList<edgeItem *>::iterator i = listOfOutcomingsEdges.begin(); i != listOfOutcomingsEdges.end(); i++)
    {
        (*i)->setItemId();
    }
}

void nodeItem::setPosx(const qreal newPosx)
{
    this->setPos(newPosx, this->getPosy());
}

void nodeItem::setPosy(const qreal newPosy)
{
    this->setPos(this->getPosx(), newPosy);
}

void nodeItem::setPosz(const qreal newPosz)
{
    z = newPosz;
}

void nodeItem::setType(nodeItemType newType)
{
    // Change type
    type = newType;
}

void nodeItem::setTrafficLight(trafficLightItem *newTLight)
{
    tLight = newTLight;
}

bool nodeItem::isTrafficLight()
{
    if(tLight == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

QList<edgeItem *>::iterator nodeItem::iteratorIncomingEdgesBegin()
{
    return listOfIncomingsEdges.begin();
}

QList<edgeItem *>::iterator nodeItem::iteratorIncomingEdgesEnd()
{
    return listOfIncomingsEdges.end();
}

QList<edgeItem *>::iterator nodeItem::iteratorOutcomingEdgesBegin()
{
    return listOfOutcomingsEdges.begin();
}

QList<edgeItem *>::iterator nodeItem::iteratorOutcomingEdgesEnd()
{
    return listOfOutcomingsEdges.end();
}

QList<connectionItem *>::iterator nodeItem::iteratorConnectionsBegin()
{
    return listOfConnections.begin();
}

QList<connectionItem *>::iterator nodeItem::iteratorConnectionsEnd()
{
    return listOfConnections.end();
}

QList<prohibitionItem *>::iterator nodeItem::iteratorProhibitionsBegin()
{
    return listOfProhibitions.begin();
}

QList<prohibitionItem *>::iterator nodeItem::iteratorProhibitionsEnd()
{
    return listOfProhibitions.end();
}

QList<turnRatioItem *>::iterator nodeItem::iteratorTurnRatiosBegin()
{
    return listOfTurnRatios.begin();
}

QList<turnRatioItem *>::iterator nodeItem::iteratorTurnRatiosEnd()
{
    return listOfTurnRatios.end();
}

void nodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // if Draw item is enabled
    if(getParameterManager()->isShowAllNodeItems())
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
        else if (isItemMouseIn() && !(getParameterManager()->isNodesBlocked()))
        {
            // Set first color if mouse is over item but isn't blocked
            painter->setBrush(getItemFirstColor());
        }
        else
        {
            // Set second color in the rest of cases
            painter->setBrush(getItemSecondColor());
        }

        // Set node Pen
        painter->setPen(getItemPen());

        // draw a ellipse
        painter->drawEllipse(boundingRect());
    }

    //If showLabels is enabled
    if(getParameterManager()->isNodesShowLabelEnabled())
    {
        // Set the modified font to the painter
        painter->setFont(getItemFontText());

        // Add pen to painter
        painter->setPen(getItemPenText());

        // Draw text with the Node ID
        painter->drawText(boundingRect(), Qt::AlignCenter, getItemId());
    }
}

void nodeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // If item is movable and isn't blocked
    if(getParameterManager()->isNodesMovables() && !(getParameterManager()->isNodesBlocked()))
    {
        // Execute parents function of mouseMoveEvent
        eNetEditorItem::mouseMoveEvent(event);

        // Make Node and their adyacents
        make();
    }
    else
    {
        // If not movable, ignore event
        event->ignore();
    }
}


QPainterPath nodeItem::shape() const
{
    // Declare new QPainterPath
    QPainterPath path;

    // This element has allways shape.
    path.addEllipse(boundingRect());

    // Return new path
    return path;
}

