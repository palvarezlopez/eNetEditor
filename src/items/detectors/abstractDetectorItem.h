#ifndef DETECTORITEM_H
#define DETECTORITEM_H

#include "../eNetEditorItem.h"


class abstractDetectorItem : public eNetEditorItem
{
public:

    explicit abstractDetectorItem(eNetEditorTable *newItemTable, laneItem *newLaneOfDetector);

    virtual ~abstractDetectorItem();

    virtual void make() = 0;

    virtual QDomElement saveItem(QDomDocument *domDoc) = 0;

    virtual QDomElement exportItemToXML(QDomDocument *domDoc) = 0;


    // Get Functions

    laneItem *getLaneParent() const;

    qreal getPosDetector() const;

    qreal getFrequency() const;

    const QString &getFileName() const;


    // SET Functions

    void setPosInLane(qreal newPos);

    void setFrequency(qreal newFrecuency);

    void setFileName(const QString &newFileName);


protected:

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) = 0;

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) = 0;

    virtual QPainterPath shape() const = 0;


private:

    // SUMO Parameter 01 - The id of the lane the detector shall be laid on. The lane must be a part of the network used.
    laneItem *laneParent;

    // SUMO Parameter 02 - The position on the lane the detector shall be laid on in meters. The position must be a value between -1*lane's length and the lane's length. In the case of a negative value, the position will be computed backward from the lane's end (the position the vehicles drive towards).
    qreal pos;

    // SUMO Parameter 03 - The aggregation period the values the detector collects shall be summed up.
    qreal frequency;

    // SUMO Parameter 04 - The path to the output file. See Writing Files for further information.
    QString fileName;
};

#endif // ITEMDETECTOR_H
