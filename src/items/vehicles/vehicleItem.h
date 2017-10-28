#ifndef VEHICLEITEM_H
#define VEHICLEITEM_H

#include "abstractVehicleItem.h"


class vehicleItem : public abstractVehicleItem
{
public:

    vehicleItem(const QString &newId, vehicleTypeItem *newType, routeItem *newRouteVehicle, eNetEditorDatabase *database);

    ~vehicleItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc)
    {
        // Declare QDomElement
        QDomElement itemDomElement;

        // Create QDomElement with the corresponding type
        itemDomElement = domDoc->createElement("terminar");

        // Return itemDomElement
        return itemDomElement;
    }

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getDepart() const;


    void setDepart(qreal newDepart);


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 05 - The time step at which the vehicle shall enter the network
    qreal depart;
};

#endif // VEHICLE_H
