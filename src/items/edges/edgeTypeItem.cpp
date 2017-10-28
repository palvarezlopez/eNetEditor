#include "edgeTypeItem.h"

// Configuration
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/edges/edgeTypeItemConfiguration.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"
#include "../../database/edges/edgeTypeTable.h"

// Items



edgeTypeItem::edgeTypeItem(const QString &newId, eNetEditorDatabase *database) : abstractEdgeItem(database->getEdgeTypeTable())
{
    // Set ID
    eNetEditorItem::setItemId(newId);

    /** ACABAR **/

    // Create and set allowed vehicles
    allow = new QStringList();

    // Create and set Disallowed vehicles
    disallow = new QStringList();

    // Set Discard
    discard = false;

    // Set Num of lanes
    numLanes = -1;

    // Set Oneway
    oneway = false;

    // Set Priority
    priority = -1;

    // Set Speed
    speed = -1;

    // Set sidewalWidth
    sidewalkWidth = -1;

    /*
    // if ID is not null
    if(newId != "")
    {
        // Set automatic ID
        et->setItemId("edgeType" + QString::number(nextEdgeTypeIndex));

        // Update nextEdgeTypeIndex
        nextEdgeTypeIndex++;
    }*/
}

edgeTypeItem::~edgeTypeItem()
{
    // Delete qstringlists
    delete allow;
    delete disallow;
}

void edgeTypeItem::make()
{
    // Nothing to make
}

QDomElement edgeTypeItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("edgeType");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement edgeTypeItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("terminar");

    // Return itemDomElement
    return itemDomElement;
}



QStringList *edgeTypeItem::getAllow() const
{
    return allow;
}

QStringList *edgeTypeItem::getDisallow() const
{
    return disallow;
}

int edgeTypeItem::getNumLanes() const
{
    return numLanes;
}

int edgeTypeItem::getPriority() const
{
    return priority;
}

qreal edgeTypeItem::getSpeed() const
{
    return speed;
}

qreal edgeTypeItem::getSidewalkWidth() const
{
    return sidewalkWidth;
}



void edgeTypeItem::setAllow(const QStringList &newAllow)
{
    // ClearList
    allow->clear();

    // Add the new elements
    (*allow) << newAllow;
}

void edgeTypeItem::setDisallow(const QStringList &newDisallow)
{
    // ClearList
    disallow->clear();

    // Add the new elements
    (*disallow) << newDisallow;
}

void edgeTypeItem::SetDiscard(bool value)
{
    discard = value;
}

void edgeTypeItem::setNumLanes(int newNumLanes)
{
    numLanes = newNumLanes;
}

void edgeTypeItem::setOneway(bool value)
{
    oneway = value;
}

void edgeTypeItem::setPriority(int newPriority)
{
    priority = newPriority;
}

void edgeTypeItem::setSpeed(qreal newSpeed)
{
    speed = newSpeed;
}

void edgeTypeItem::setSidewalkWidth(qreal newSidewalkWidth)
{
    sidewalkWidth = newSidewalkWidth;
}

bool edgeTypeItem::isDiscard() const
{
    return discard;
}

bool edgeTypeItem::isOneway() const
{
    return oneway;
}

void edgeTypeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Nothing to draw
    Q_UNUSED(painter);
}

void edgeTypeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath edgeTypeItem::shape() const
{
    // This element don't have shape
    return QPainterPath();
}
