#include "flowMeasureItem.h"

//Configuration
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/flowMeasureItemConfiguration.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// Database
#include "../database/eNetEditorDatabase.h"
#include "../database/flowMeasureTable.h"

// Items
#include "detectors/inductionLoopsE1DetectorItem.h"
#include "laneItem.h"
#include "edges/edgeItem.h"


flowMeasureItem::flowMeasureItem(inductionLoopsE1DetectorItem *newInductionLoopsE1DetectorItemParent, eNetEditorDatabase *database) : eNetEditorItem(database->getFlowMeasureTable())
{
    // Set pointer to inductionLoopsE1DetectorItemParent
    inductionLoopsE1DetectorItemParent = newInductionLoopsE1DetectorItemParent;

    // Set time
    time = getProjectConfiguration()->getFlowMeasureItemConfiguration()->getFlowMeasureDefaultTime();

    // Set qPKW
    qPKW = getProjectConfiguration()->getFlowMeasureItemConfiguration()->getFlowMeasureDefaultQPKW();

    // Set vPKW
    vPKW = getProjectConfiguration()->getFlowMeasureItemConfiguration()->getFlowMeasureDefaultVPKW();

    // Set qLKW
    qLKW = getProjectConfiguration()->getFlowMeasureItemConfiguration()->getFlowMeasureDefaultQLKW();

    // Set vLKW
    vLKW = getProjectConfiguration()->getFlowMeasureItemConfiguration()->getFlowMeasureDefaultVLKW();

    // By default, a detector is removable
    removable = true;

    // Add flow measure to inductionLoopsE1DetectorItemParent
    inductionLoopsE1DetectorItemParent->addFlowMeasure(this);

    // Add fow measures to edge
    inductionLoopsE1DetectorItemParent->getLaneParent()->getEdgeParent()->addFlowMeasure(this);
}


flowMeasureItem::~flowMeasureItem()
{
    // Remove inductionLoopsE1DetectorItemParent
    inductionLoopsE1DetectorItemParent->removeFlowMeasure(this);

    // Add fow measures to edge
    inductionLoopsE1DetectorItemParent->getLaneParent()->getEdgeParent()->removeFlowMeasure(this);
}

void flowMeasureItem::make()
{
    // Nothing to make
}

QDomElement flowMeasureItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("flowMeasure");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement flowMeasureItem::exportItemToXML(QDomDocument *domDoc)
{
    // Ignore warnings
    Q_UNUSED(domDoc);

    // Return itemDomElement clear
    return QDomElement();
}

QString flowMeasureItem::toString()
{
    return getInductionLoopsE1DetectorItemParent()->getItemId() + ";" +
           QString::number(time) + ";" +
           QString::number(qPKW) + ";" +
           QString::number(vPKW) + ";" +
           QString::number(qLKW) + ";" +
           QString::number(vLKW);
}

inductionLoopsE1DetectorItem *flowMeasureItem::getInductionLoopsE1DetectorItemParent() const
{
    return inductionLoopsE1DetectorItemParent;
}

QString flowMeasureItem::getItemId()
{
    return inductionLoopsE1DetectorItemParent->getItemId() + "_" + QString::number(time);
}

int flowMeasureItem::getTime() const
{
    return time;
}

qreal flowMeasureItem::getQPKW() const
{
    return qPKW;
}

qreal flowMeasureItem::getVPKW() const
{
    return vPKW;
}

qreal flowMeasureItem::getQLKW() const
{
    return qLKW;
}

qreal flowMeasureItem::getVLKW() const
{
    return vLKW;
}

void flowMeasureItem::setTime(int newTime)
{
    time = newTime;
}

void flowMeasureItem::setQPKW(qreal newQPKV)
{
    qPKW = newQPKV;
}

void flowMeasureItem::setVPKW(qreal newVPKW)
{
    vPKW = newVPKW;
}

void flowMeasureItem::setQLKW(qreal newQLKW)
{
    qLKW = newQLKW;
}

void flowMeasureItem::setVLKW(qreal newVLKW)
{
    vLKW = newVLKW;
}

void flowMeasureItem::setRemovable(bool value)
{
    removable = value;
}

bool flowMeasureItem::isRemovable()
{
    return removable;
}

void flowMeasureItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //Nothing to draw
    Q_UNUSED(painter)
}

void flowMeasureItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath flowMeasureItem::shape() const
{
    // Declare QPainterPath
    QPainterPath path;

    // Return empty path
    return path;
}


