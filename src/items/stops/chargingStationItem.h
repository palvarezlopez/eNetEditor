#ifndef CHARGINGSTATIONITEM_H
#define CHARGINGSTATIONITEM_H

#include "../eNetEditorItem.h"


/// ATENCION: FALTA value friendlyPos


class chargingStationItem : public eNetEditorItem
{

public:

    chargingStationItem(const QString &newID, laneItem *newLaneParent, eNetEditorDatabase *database);

    ~chargingStationItem();

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
    const long int &getChrgpower() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getEfficiency() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const unsigned int &getChargeInTransit() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const unsigned int &getChargeDelay() const;


    // Set Functions

    void setStartPos(qreal newStartPos);

    void setEndPos(qreal newEndPos);

    void setChrgpower(const long int &newChrgPower);

    void setEfficiency(qreal newEfficiency);

    void setChargeInTransit(const unsigned int &newChargeInTransit);

    void setChargeDelay(const unsigned int &newChargeDelay);


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 02 - Lane who is the charging station.
    laneItem *laneParent;

    // SUMO Parameter 03 - Start position in the lane of the Charging Station
    qreal startPos;

    // SUMO Parameter 04 - End position in the lane of the Charging Station
    qreal endPos;

    // SUMO Parameter 05 - Charging power of the Charging Station (In W)
    long int chrgPower;

    // SUMO Parameter 06 - Efficiency in the charge [0 - 1]
    qreal efficiency;

    // SUMO Parameter 07 - Charge in transit [True - False]
    unsigned int chargeInTransit;

    // SUMO Parameter 08 - Delay in the charge (In TimeUnits)
    unsigned int chargeDelay;

    // QT paramter 01 - Rect of the charging station
    QRectF chargingStationRect;
};

#endif // CHARGINGSTATION_H
