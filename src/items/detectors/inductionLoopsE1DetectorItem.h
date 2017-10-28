#ifndef INDUCTIONLOOPSDETECTORE1ITEM_H
#define INDUCTIONLOOPSDETECTORE1ITEM_H

#include "abstractDetectorItem.h"


class inductionLoopsE1DetectorItem : public abstractDetectorItem
{
public:

    inductionLoopsE1DetectorItem(laneItem *newLaneOfDetector, eNetEditorDatabase *database);

    ~inductionLoopsE1DetectorItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    void addFlowMeasure(flowMeasureItem *fm);

    void removeFlowMeasure(flowMeasureItem *fm);

    void clearFlowMeasures() const;

    // GET FUNCTIONS

    int getNumberOfFlowMeasures() const;

    flowMeasureItem *getFirstFlowMeasure();

    flowMeasureItem *getLastFlowMeasure();


    // SET FUNCTIONS

    void setSplitByType(bool newSplitByType);

    void setFriendlyPos(bool newFriendlyPos);


    // IS FUNCTIONS

    bool isFriendlyPosEnabled();

    bool isSplitByTypeEnabled();


    // ITERATORS

    QList<flowMeasureItem *>::iterator flowMeasuresBegin();

    QList<flowMeasureItem *>::iterator flowMeasuresEnd();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 06 - If set, no error will be reported if the detector is placed behind the lane. Instead, the detector will be placed 0.1 meters from the lane's end or at position 0.1, if the position was negative and larger than the lane's length after multiplication with -1; default: false.
    bool friendlyPos;

    // SUMO Parameter 07 - If set, the collected values will be additionally reported on per-vehicle type base, see below; default: false.
    bool splitByType;

    // QT Parameter 01 - List with the flowMeasures
    QList<flowMeasureItem *> listOfFlowMeasures;
};

#endif // INDUCTIONLOOPSDETECTORE1ITEM_H
