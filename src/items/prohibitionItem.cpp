#include "prohibitionItem.h"

// Configuration
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/prohibitionItemConfiguration.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// Database
#include "../database/eNetEditorDatabase.h"
#include "../database/prohibitionTable.h"

// Items
#include "nodeItem.h"
#include "edges/edgeItem.h"
#include "laneItem.h"


prohibitionItem::prohibitionItem(edgeItem *newEdgeProhibitionOrigin, edgeItem *newEdgeProhibitionDestiny, eNetEditorDatabase *database) : eNetEditorItem(database->getProhibitionTable(), "black", "black")
{
    // Set lane prohibition origin
    edgeProhibitionOrigin = newEdgeProhibitionOrigin;

    // Set lane prohibition destiny
    edgeProhibitionDestiny = newEdgeProhibitionDestiny;

    // Set Node of prohibition
    nodeParent = edgeProhibitionOrigin->getNodeDestiny();

    // Add Prohibition to node
    nodeParent->addProhibition(this);

    // Add prohibition to all lanes from edge Origin
    for (QList<laneItem *>::iterator i = edgeProhibitionOrigin->iteratorLanesBegin(); i != edgeProhibitionOrigin->iteratorLanesEnd(); i++)
    {
        (*i)->addOutcomingProhibition(this);
    }

    // Add prohibition to all lanes from edge Destiny
    for (QList<laneItem *>::iterator i = edgeProhibitionDestiny->iteratorLanesBegin(); i != edgeProhibitionDestiny->iteratorLanesEnd(); i++)
    {
        (*i)->addIncomingProhibition(this);
    }

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getProhibitionItemConfiguration()->getItemAltitude());

    // Make prohibition
    make();
}

prohibitionItem::~prohibitionItem()
{
    // Remove prohibition of node
    nodeParent->removeProhibition(this);

    // Remove prohibition of all lanes from edge Origin
    for (QList<laneItem *>::iterator i = edgeProhibitionOrigin->iteratorLanesBegin(); i != edgeProhibitionOrigin->iteratorLanesEnd(); i++)
    {
        (*i)->removeOutcomingProhibition(this);
    }

    // Remove prohibition ofo all lanes from edge Destiny
    for (QList<laneItem *>::iterator i = edgeProhibitionDestiny->iteratorLanesBegin(); i != edgeProhibitionDestiny->iteratorLanesEnd(); i++)
    {
        (*i)->removeIncomingProhibition(this);
    }
}

void prohibitionItem::make()
{

}

QDomElement prohibitionItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("prohibition");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement prohibitionItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("terminar");

    // Return itemDomElement
    return itemDomElement;
}



edgeItem *prohibitionItem::getEdgeProhibitionOrigin() const
{
    return edgeProhibitionOrigin;
}

edgeItem *prohibitionItem::getEdgeProhibitionDestiny() const
{
    return edgeProhibitionDestiny;
}

void prohibitionItem::setItemId(const QString &newId)
{
    if(newId == "")
    {
        eNetEditorItem::setItemId("pro_" + edgeProhibitionOrigin->getItemId() + "->" + edgeProhibitionDestiny->getItemId());
    }
    else
    {
        eNetEditorItem::setItemId(newId);
    }
}

void prohibitionItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // if Draw item is enabled
    if(getParameterManager()->isShowAllProhibitionItems())
    {
        painter;
    }
}

void prohibitionItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath prohibitionItem::shape() const
{
    // Declare QPainterPath
    QPainterPath path;

    // If the item isn't blocked
    if(getParameterManager()->isEdgeBlocked() == false)
    {
        // Add path
        ;   // Finish
    }

    // Return new path
    return path;
}
