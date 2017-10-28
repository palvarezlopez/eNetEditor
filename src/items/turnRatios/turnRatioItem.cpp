#include "turnRatioItem.h"

// Database
#include "../../database/eNetEditorDatabase.h"
#include "../../database/turnRatios/turnRatioTable.h"

// Configuration
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/turnRatios/turnRatioItemConfiguration.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// Items
#include "turnRatioIntervalItem.h"
#include "../edges/edgeItem.h"
#include "../nodeItem.h"


turnRatioItem::turnRatioItem(turnRatioIntervalItem *newTurnRatioIntervalParent, edgeItem *newEdgeFrom, edgeItem *newEdgeTo, eNetEditorDatabase *database) : eNetEditorItem(database->getTurnRatioTable())
{
    // Set pointer turnRatioIntervalParent
    turnRatioIntervalParent = newTurnRatioIntervalParent;

    // Set pointer edgeFrom
    edgeFrom = newEdgeFrom;

    // Set pointer to edgeTo
    edgeTo = newEdgeTo;

    // By default, probability is 0
    probability = 0;

    // By default, isn't blocked
    blocked = false;

    // Add this turnRatioItem to edgeFrom
    edgeFrom->addTurnRatioFrom(this);

    // Add this turnRatioItem to edgeTo
    edgeTo->addTurnRatioTo(this);

    // Add this turnRatioItem to turnRatioIntervalParent
    turnRatioIntervalParent->addTurnRatio(this);
}

turnRatioItem::~turnRatioItem()
{
    // Remove this turnRatioItem to edge
    edgeFrom->removeTurnRatioFrom(this);

    // Remove this turnRatioItem to edgeTo
    edgeTo->removeTurnRatioTo(this);

    // Remove this turnRatioItem of turnRatioIntervalParent
    turnRatioIntervalParent->removeTurnRatio(this);
}

void turnRatioItem::make()
{
    // Nothing to make
}

QDomElement turnRatioItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;
    QDomElement itemDomElementToEdge;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("turnRatio");

    // Save Id of item
    itemDomElement.setAttribute("fromEdge", edgeFrom->getItemId());

    /** ARREGLAR
        // Iterate over list of edges
        for(int i = 0; i < listOftoEdgesTo.size(); i++)
        {
            // Create sub element "toEdge"
            itemDomElementToEdge = domDoc->createElement("toEdge");

            // Set id
            itemDomElementToEdge.setAttribute("id", listOftoEdgesTo.at(i)->getItemId());

            // Set probability
            itemDomElementToEdge.setAttribute("probability", QString::number(listOftoProbabilities.at(i)));

            // AppendChild
            itemDomElement.appendChild(itemDomElementToEdge);
        }
    */
    // Return itemDomElement
    return itemDomElement;
}

QDomElement turnRatioItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("terminar");

    // Return itemDomElement
    return itemDomElement;
}


turnRatioIntervalItem *turnRatioItem::getTurnRatioIntervalParent() const
{
    return turnRatioIntervalParent;
}

edgeItem *turnRatioItem::getEdgeFrom() const
{
    return edgeFrom;
}

edgeItem *turnRatioItem::getEdgeTo() const
{
    return edgeTo;
}

qreal turnRatioItem::getProbability() const
{
    return probability;
}

void turnRatioItem::setProbability(qreal newProbability)
{
    probability = newProbability;
}

void turnRatioItem::setBlocked(bool value)
{
    blocked = value;
}

bool turnRatioItem::isProbabilityBlocked()
{
    return blocked;
}

void turnRatioItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Nothing to draw
    Q_UNUSED(painter);
}

void turnRatioItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath turnRatioItem::shape() const
{
    // This item don't have shape
    return QPainterPath();
}

