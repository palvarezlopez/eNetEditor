#include "turnRatioIntervalItem.h"

// Configuration
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/turnRatios/turnRatioIntervalItemConfiguration.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"
#include "../../database/turnRatios/turnRatioIntervalTable.h"
#include "../../database/turnRatios/turnRatioTable.h"
#include "../../database/nodeTable.h"

// Project
#include "../../project/eNetEditorProject.h"

// Items
#include "turnRatioItem.h"
#include "../nodeItem.h"
#include "../edges/edgeItem.h"



turnRatioIntervalItem::turnRatioIntervalItem(eNetEditorDatabase *database) : abstractTurnRatioItem(database->getTurnRatioIntervalTable())
{
    // Set time begin Hour of interval
    intervalBeginH = 0;

    // Set time begin Minute of interval
    intervalBeginM = 0;

    // Set time begin Second of interval
    intervalBeginS = 0;

    // Set time end Hour of interval
    intervalEndH = 24;

    // Set time end Minute of interval
    intervalEndM = 0;

    // Set time end Second of interval
    intervalEndS = 0;

    // Set Item ID
    setItemId("trInterval" + QString::number(intervalBeginH) + ":" + QString::number(intervalBeginM) + ":" + QString::number(intervalBeginS) + "to" + QString::number(intervalEndH) + ":" + QString::number(intervalEndM) + ":" + QString::number(intervalEndS));

    // Declare auxiliar pointer to nodeItem
    nodeItem *nAux;

    // Iterate over Node Table
    for(QList<eNetEditorItem *>::iterator i = getDatabase()->getNodeTable()->iteratorTableBegin(); i != getDatabase()->getNodeTable()->iteratorTableEnd(); i++)
    {
        // Cast item to Node
        nAux = dynamic_cast<nodeItem *>(*i);

        // Iterate over list of incomings edges of node parent
        for (QList<edgeItem *>::iterator j = nAux->iteratorIncomingEdgesBegin(); j != nAux->iteratorIncomingEdgesBegin(); j++)
        {
            // Iterate over list of outcomings edges of node parent
            for (QList<edgeItem *>::iterator k = nAux->iteratorOutcomingEdgesBegin(); k != nAux->iteratorOutcomingEdgesBegin(); k++)
            {
                // Create new Turn Ratio
                new turnRatioItem(this, (*j), (*k), database);
            }
        }
    }

    // Add item to project
    getProject()->addTurnRatioInterval(this);

    // Make Item
    make();
}

turnRatioIntervalItem::~turnRatioIntervalItem()
{
    // Clear turn ratios associated to this turn ratio interval
    clearTurnRatio();

    // remove item of project
    getProject()->removeTurnRatioInterval(this);
}

void turnRatioIntervalItem::make()
{
    // Nothing to make
}

QDomElement turnRatioIntervalItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("prohibition");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement turnRatioIntervalItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("terminar");


    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("interval ");


    /*

        // Set Id of item
        itemDomElement.setAttribute("interval ", getItemId());

        // Set atribute x
        itemDomElement.setAttribute("x", QString::number(pos().x()));

        // Set atribute y
        itemDomElement.setAttribute("y", QString::number(pos().y() * (-1)));

        // Set atribute z
        itemDomElement.setAttribute("z", QString::number(z));

        // Set atribute type
        itemDomElement.setAttribute("type", getProjectConfiguration()->getNodeItemConfiguration()->getNodeTypeValue(type));


    */

    // Return itemDomElement
    return itemDomElement;
}

void turnRatioIntervalItem::addTurnRatio(turnRatioItem *tr)
{
    listOfTurnRatios.push_back(tr);

    // Update probabilities of turn ratios associated to this turnRatioIntervalItem
    updateProbabilities(tr->getEdgeFrom()->getNodeDestiny());
}

void turnRatioIntervalItem::removeTurnRatio(turnRatioItem *tr)
{
    listOfTurnRatios.removeAll(tr);

    // Update probabilities of turn ratios associated to this turnRatioIntervalItem
    updateProbabilities(tr->getEdgeFrom()->getNodeDestiny());
}

void turnRatioIntervalItem::clearTurnRatio()
{
    // Create a copy of the list of turn Ratios
    QList<turnRatioItem *> copyOfListOfTurnRatios = listOfTurnRatios;

    // Iterate over copy of list of turn Ratios
    for(QList<turnRatioItem *>::iterator i = copyOfListOfTurnRatios.begin(); i != copyOfListOfTurnRatios.end(); i++)
    {
        // Delete turn Ratio
        delete (*i);
    }
}

void turnRatioIntervalItem::updateProbabilities(nodeItem *nodeParent)
{
    // Declare lists of turn ratios to keep turn ratios blocked and non blocked
    QList<turnRatioItem *> listOfTurnRatiosBlocked;
    QList<turnRatioItem *> listOfTurnRatiosNonBlocked;

    // Declare probability
    qreal probability;

    // Iterate over Incomings edges of nodes
    for(QList<edgeItem *>::iterator j = nodeParent->iteratorIncomingEdgesBegin(); j != nodeParent->iteratorIncomingEdgesBegin(); j++)
    {
        // Clear lists of turn Ratios
        listOfTurnRatiosBlocked.clear();
        listOfTurnRatiosNonBlocked.clear();

        // Iterate over list of turn ratio From of edge
        for(QList<turnRatioItem *>::iterator k = (*j)->iteratorTurnRatioFromBegin(); k != (*j)->iteratorTurnRatioFromBegin(); k++)
        {
            // If Probability of turnRatioItem is blocked
            if((*k)->isProbabilityBlocked() == true)
            {
                // Add blocked turn ratio in the list of turn ratios Blocked
                listOfTurnRatiosBlocked.push_back(*k);
            }
            else
            {
                // Add non-blocked turn ratio in the list of turn ratios non Blocked
                listOfTurnRatiosNonBlocked.push_back(*k);
            }
        }

        // If list of turn Ratios non Blocked isn't empty
        if(listOfTurnRatiosNonBlocked.size() > 0)
        {
            // new probability for all turn ratios
            probability = qreal(1) / qreal(listOfTurnRatiosNonBlocked.size());

            // Iterate over list of non-blocked turn ratios
            for(QList<turnRatioItem *>::iterator j = listOfTurnRatiosNonBlocked.begin(); j != listOfTurnRatiosNonBlocked.end(); j++)
            {
                // Set new probability
                (*j)->setProbability(probability);
            }
        }
    }
}

QList<turnRatioItem *> turnRatioIntervalItem::getListOfTurnRatioByEdgeFrom(edgeItem *e)
{
    // Declare listOfTurnRatioByEdgeFrom
    QList<turnRatioItem *> listOfTurnRatioByEdgeFrom;

    // Iterate over list of turn Ratios
    for(QList<turnRatioItem *>::iterator i = listOfTurnRatios.begin(); i != listOfTurnRatios.end(); i++)
    {
        // If edgeFrom of item is == to e
        if((*i)->getEdgeFrom() == e)
        {
            // Return pointer to turnRatioItem
            listOfTurnRatioByEdgeFrom.push_back(*i);
        }
    }

    // Return list Of Turn Ratio By Edge From
    return listOfTurnRatioByEdgeFrom;
}

void turnRatioIntervalItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Nothing to draw
    Q_UNUSED(painter);
}

void turnRatioIntervalItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath turnRatioIntervalItem::shape() const
{
    // This item don't have shape
    return QPainterPath();
}

int turnRatioIntervalItem::getIntervalEndSecond() const
{
    return intervalEndS;
}

int turnRatioIntervalItem::getIntervalEndMinute() const
{
    return intervalEndM;
}

int turnRatioIntervalItem::getIntervalEndHour() const
{
    return intervalEndH;
}

int turnRatioIntervalItem::getIntervalBeginSecond() const
{
    return intervalBeginS;
}

int turnRatioIntervalItem::getIntervalBeginMinute() const
{
    return intervalBeginM;
}

int turnRatioIntervalItem::getIntervalBeginHour() const
{
    return intervalBeginH;
}

void turnRatioIntervalItem::setIntervalBegin(int value)
{
    // Set time begin Hour of interval
    intervalBeginH = (value / 3600);

    // Set time begin Minute of interval
    intervalBeginM = (value - (intervalBeginH * 3600)) / 60;

    // Set time begin Second of interval
    intervalBeginS = value - (intervalBeginH * 3600) - (intervalBeginM * 60);

    // Set Item ID
    setItemId("trInterval" + QString::number(intervalBeginH) + ":" + QString::number(intervalBeginM) + ":" + QString::number(intervalBeginS) + "to" + QString::number(intervalEndH) + ":" + QString::number(intervalEndM) + ":" + QString::number(intervalEndS));
}

void turnRatioIntervalItem::setIntervalEnd(int value)
{
    // Set time End Hour of interval
    intervalEndH = (value / 3600);

    // Set time End Minute of interval
    intervalEndM = (value - (intervalEndH * 3600)) / 60;

    // Set time End Second of interval
    intervalEndS = value - (intervalEndH * 3600) - (intervalEndM * 60);

    // Set Item ID
    setItemId("trInterval" + QString::number(intervalBeginH) + ":" + QString::number(intervalBeginM) + ":" + QString::number(intervalBeginS) + "to" + QString::number(intervalEndH) + ":" + QString::number(intervalEndM) + ":" + QString::number(intervalEndS));
}

int turnRatioIntervalItem::getIntervalBegin() const
{
    return (intervalBeginH * 3600) +  (intervalBeginM * 60) + intervalBeginS;
}

int turnRatioIntervalItem::getNumberOfTurnRatios()
{
    return listOfTurnRatios.size();
}

turnRatioItem *turnRatioIntervalItem::getFirstTurnRatio()
{
    // If there are turnRatios in the list
    if(listOfTurnRatios.size() > 0)
    {
        return listOfTurnRatios.first();
    }
    else
    {
        return NULL;
    }
}

turnRatioItem *turnRatioIntervalItem::getLastTurnRatio()
{
    // If there are turnRatios in the list
    if(listOfTurnRatios.size() > 0)
    {
        return listOfTurnRatios.last();
    }
    else
    {
        return NULL;
    }
}

QList<turnRatioItem *>::iterator turnRatioIntervalItem::iteratorTurnRatiosBegin()
{
    return listOfTurnRatios.begin();
}

QList<turnRatioItem *>::iterator turnRatioIntervalItem::iteratorTurnRatiosEnd()
{
    return listOfTurnRatios.end();
}

int turnRatioIntervalItem::getIntervalEnd() const
{
    return (intervalEndH * 3600) +  (intervalEndM * 60) + intervalEndS;
}
