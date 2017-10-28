#ifndef TURNRATIOINTERVALITEM_H
#define TURNRATIOINTERVALITEM_H


#include "abstractTurnRatioItem.h"


class turnRatioIntervalItem : public abstractTurnRatioItem
{
public:

    turnRatioIntervalItem(eNetEditorDatabase *database);

    ~turnRatioIntervalItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    void addTurnRatio(turnRatioItem *tr);

    void removeTurnRatio(turnRatioItem *tr);

    void clearTurnRatio();

    void updateProbabilities(nodeItem *nodeParent);

    QList<turnRatioItem *> getListOfTurnRatioByEdgeFrom(edgeItem *e);

    int getIntervalBegin() const;

    int getIntervalEnd() const;

    int getIntervalBeginHour() const;

    int getIntervalBeginMinute() const;

    int getIntervalBeginSecond() const;

    int getIntervalEndHour() const;

    int getIntervalEndMinute() const;

    int getIntervalEndSecond() const;

    int getNumberOfTurnRatios();

    turnRatioItem *getFirstTurnRatio();

    turnRatioItem *getLastTurnRatio();

    void setIntervalBegin(int value);

    void setIntervalEnd(int value);

    // Iteradores

    QList<turnRatioItem *>::iterator iteratorTurnRatiosBegin();

    QList<turnRatioItem *>::iterator iteratorTurnRatiosEnd();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // Time begin Hour of interval
    int intervalBeginH;

    // Time begin Minute of interval
    int intervalBeginM;

    // Time begin Second of interval
    int intervalBeginS;

    // Time end Hour of interval
    int intervalEndH;

    // Time end Minute of interval
    int intervalEndM;

    // Time end Second of interval
    int intervalEndS;

    // list Of turn Ratios of this Turn Ratio interval
    QList<turnRatioItem *> listOfTurnRatios;
};

#endif // TURNRATIOINTERVALITEM_H
