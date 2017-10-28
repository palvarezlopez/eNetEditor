#ifndef FLOWMESASURE_H
#define FLOWMESASURE_H

#include "eNetEditorItem.h"


class flowMeasureItem : public eNetEditorItem
{
public:

    explicit flowMeasureItem(inductionLoopsE1DetectorItem *newInductionLoopsE1DetectorItemParent, eNetEditorDatabase *database);

    ~flowMeasureItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    QString toString();


    // GET FUNCTIONS

    inductionLoopsE1DetectorItem *getInductionLoopsE1DetectorItemParent() const;

    QString getItemId();

    int getTime() const;

    qreal getQPKW() const;

    qreal getVPKW() const;

    qreal getQLKW() const;

    qreal getVLKW() const;


    // SET FUNCTIONS

    void setTime(int newTime);

    void setQPKW(qreal newQPKV);

    void setVPKW(qreal newVPKW);

    void setQLKW(qreal newQLKW);

    void setVLKW(qreal newVLKW);

    void setRemovable(bool value);


    // IS FUNCTIONS

    bool isRemovable();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    inductionLoopsE1DetectorItem *inductionLoopsE1DetectorItemParent;

    int time;
    qreal qPKW;
    qreal vPKW;
    qreal qLKW;
    qreal vLKW;

    bool removable;
};

#endif // FLOWMESASURE_H
