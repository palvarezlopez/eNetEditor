#ifndef MULTIENTRYEXITDETECTORSE3_H
#define MULTIENTRYEXITDETECTORSE3_H

#include "abstractDetectorItem.h"


class multiEntryExitE3DetectorItem : public abstractDetectorItem
{
public:

    multiEntryExitE3DetectorItem(laneItem *newLaneOfDetector, eNetEditorDatabase *database);

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;

};

#endif // MULTIENTRYEXITDETECTORSE3_H
