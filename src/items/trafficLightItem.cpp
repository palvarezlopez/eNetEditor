#include "trafficLightItem.h"

// Configuration
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/trafficLightItemConfiguration.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// Database
#include "../database/eNetEditorDatabase.h"
#include "../database/trafficLightTable.h"

// Items
#include "nodeItem.h"
#include "edges/edgeItem.h"
#include "laneItem.h"
#include "connectionItem.h"


trafficLightItem::trafficLightItem(nodeItem *newNodeParent, eNetEditorDatabase *database) : eNetEditorItem(database->getTrafficLightTable(), "black", "black")
{
    // Set ProgramID
    ProgramID = newNodeParent->getItemId() + "program";

    // Set node parent
    nodeParent = newNodeParent;

    // Set Type
    type = getProjectConfiguration()->getTrafficLightItemConfiguration()->getTrafficLightDefaultType();

    // Set Offset
    offset = getProjectConfiguration()->getTrafficLightItemConfiguration()->getTrafficLightDefaultOffset();

    // Set maxGap
    maxGap = getProjectConfiguration()->getTrafficLightItemConfiguration()->getTrafficLightDefaultMaxGap();

    // Set passing Time
    passingTime = getProjectConfiguration()->getTrafficLightItemConfiguration()->getTrafficLightDefaultPassingTime();

    // Set detector Gap
    detectorGap = getProjectConfiguration()->getTrafficLightItemConfiguration()->getTrafficLightDefaultDetectorGap();

    // Set pointer to this traffic light in the node
    nodeParent->setTrafficLight(this);

    // Set the first the duration vector
    vectorOfDuration.push_back(getProjectConfiguration()->getTrafficLightItemConfiguration()->getTrafficLightDefaultDuration());

    // Vinculate this traffic light with the connections of this node
    for(QList<connectionItem *>::iterator i = nodeParent->iteratorConnectionsBegin(); i != nodeParent->iteratorConnectionsEnd(); i++)
    {
        (*i)->setTrafficLight(this);
    }
}

trafficLightItem::~trafficLightItem()
{
    // DesVinculate this traffic light with the connections of this node
    for(QList<connectionItem *>::iterator i = nodeParent->iteratorConnectionsBegin(); i != nodeParent->iteratorConnectionsEnd(); i++)
    {
        (*i)->setTrafficLight(NULL);
    }

    // Set pointer to NULL in the node Origin
    nodeParent->setTrafficLight(NULL);
}

void trafficLightItem::make()
{
    // Nothing to make
}

QDomElement trafficLightItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("trafficLight");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement trafficLightItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("terminar");

    // Return itemDomElement
    return itemDomElement;
}

const QString &trafficLightItem::getItemId() const
{
    return nodeParent->getItemId();
}

const trafficLightType &trafficLightItem::getType() const
{
    return type;
}

const QString &trafficLightItem::getProgramID() const
{
    return ProgramID;
}

int trafficLightItem::getOffset() const
{
    return offset;
}

int trafficLightItem::getMaxGap() const
{
    return maxGap;
}

int trafficLightItem::getPassingTime() const
{
    return passingTime;
}

int trafficLightItem::getDetectorGap() const
{
    return detectorGap;
}

nodeItem *trafficLightItem::getNodeParent() const
{
    return nodeParent;
}

QVector<int> &trafficLightItem::getVectorOfDuration()
{
    return vectorOfDuration;
}

void trafficLightItem::setItemId(const QString &newID)
{
    if(newID == "")
    {
        eNetEditorItem::setItemId(nodeParent->getItemId());
    }
    else
    {
        eNetEditorItem::setItemId(newID);
    }
}

void trafficLightItem::setType(const trafficLightType &newType)
{
    type = newType;
}

void trafficLightItem::setProgramID(const QString &newProgramID)
{
    ProgramID = newProgramID;
}

void trafficLightItem::setOffset(int newOffset)
{
    offset = newOffset;
}

void trafficLightItem::setMaxGap(int newMaxGap)
{
    maxGap = newMaxGap;
}

void trafficLightItem::setPassingTime(int newPassingTime)
{
    passingTime = newPassingTime;
}

void trafficLightItem::setDetectorGap(int newDetectorGap)
{
    detectorGap = newDetectorGap;
}

void trafficLightItem::setDuration(int pos, int value)
{
    if(pos < vectorOfDuration.size())
    {
        vectorOfDuration[pos] = value;
    }
}

void trafficLightItem::setVectorOfDurations(const QVector<int> &newVectorOfDurations)
{
    vectorOfDuration = newVectorOfDurations;
}


void trafficLightItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Nothing to draw
    Q_UNUSED(painter)
}

void trafficLightItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath trafficLightItem::shape() const
{
    // This item don't have shape
    return QPainterPath();
}
