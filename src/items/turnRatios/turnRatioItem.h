#ifndef TURNRATIOITEM_H
#define TURNRATIOITEM_H

#include "../eNetEditorItem.h"


class turnRatioItem : public eNetEditorItem
{
public:

    turnRatioItem(turnRatioIntervalItem *newTurnRatioIntervalParent, edgeItem *newEdgeFrom, edgeItem *newEdgeTo, eNetEditorDatabase *database);

    ~turnRatioItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    turnRatioIntervalItem *getTurnRatioIntervalParent() const;

    edgeItem *getEdgeFrom() const;

    edgeItem *getEdgeTo() const;

    qreal getProbability() const;

    // Set functions

    void setProbability(qreal newProbability);

    void setBlocked(bool value);

    // IS Function

    bool isProbabilityBlocked();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // turnRatioIntervalItem of turn probability
    turnRatioIntervalItem *turnRatioIntervalParent;

    // Edge from
    edgeItem *edgeFrom;

    // Edge to
    edgeItem *edgeTo;

    // Probability
    qreal probability;

    // Blocked
    bool blocked;
};

#endif // TURNPROBABILITYITEM_H
