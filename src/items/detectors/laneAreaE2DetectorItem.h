#ifndef LANEAREADETECTORE2ITEM_H
#define LANEAREADETECTORE2ITEM_H

#include "abstractDetectorItem.h"


class laneAreaE2DetectorItem : public abstractDetectorItem
{
public:

    laneAreaE2DetectorItem(laneItem *newLaneOfDetector, eNetEditorDatabase *database);

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);


    // GET FUNCTIONS

    bool getCont() const;

    bool getFriendlyPos() const;

    int getTimeThreshold() const;

    qreal getSpeedThreshold() const;

    qreal getJamThreshold() const;


    // SET FUNCTIONS

    void setCont(bool value);

    void setFriendlyPos(bool value);

    void setTimeThreshold(int value);

    void setSpeedThreshold(qreal value);

    void setJamThreshold(qreal value);


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 01 - Holds the information whether detectors longer than a lane shall be cut off or continued (set it to true for the second case); default: false (detector lies on one lane only).
    bool cont;

    // SUMO Parameter 02 - The time-based threshold that describes how much time has to pass until a vehicle is recognized as halting; in s, default: 1s.
    bool friendlyPos;

    // SUMO Parameter 03 - The speed-based threshold that describes how slow a vehicle has to be to be recognized as halting; in m/s, default: 5/3.6m/s.
    int timeThreshold;

    // SUMO Parameter 04 - The minimum distance to the next standing vehicle in order to make this vehicle count as a participant to the jam; in m, default: 10m.
    qreal speedThreshold;

    // SUMO Parameter 05 - If set, no error will be reported if the detector is placed behind the lane. Instead, the detector will be placed 0.1 meters from the lane's end or at position 0.1, if the position was negative and larger than the lane's length after multiplication with -1; default: false.
    qreal jamThreshold;
};

#endif // LANEAREADETECTORE2ITEM_H
