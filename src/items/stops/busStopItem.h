#ifndef BUSSTOPITEM_H
#define BUSSTOPITEM_H

#include "../eNetEditorItem.h"

/// ATENCION: FALTA value friendlyPos


class busStopItem : public eNetEditorItem
{
public:

    busStopItem(const QString &newID, laneItem *newLaneParent, eNetEditorDatabase *database);

    ~busStopItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);


    /**
        @brief Get

        @return QString with the
        @details Get
    */
    laneItem *getLane() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getStartPos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getEndPos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getLines() const;


    // Set Functions

    void setStartPos(qreal newStartPos);

    void setEndPos(qreal newEndPos);

    void setLines(const QString &newLines);


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 02 - Lane who the Bus Stop is.
    laneItem *laneParent;

    // SUMO Parameter 03 - Start position of the Bus Stop
    qreal startPos;

    // SUMO Parameter 04 - End position of the Bus Stop
    qreal endPos;

    // SUMO Parameter 05 - Bus lines of the Bus Stop
    QString lines;

    // QT Parameter 01 - Rect with the bus Stop
    QRectF busStopRect;
};

#endif // BUSSTOP_H
