#ifndef ABSTRACTVEHICLEITEM_H
#define ABSTRACTVEHICLEITEM_H

#include "../eNetEditorItem.h"

class abstractVehicleItem : public eNetEditorItem
{
public:

    abstractVehicleItem(eNetEditorTable *newItemTable, const QString &newId, vehicleTypeItem *newType, routeItem *newRouteVehicle);

    virtual ~abstractVehicleItem();

    virtual void make() = 0;

    virtual QDomElement saveItem(QDomDocument *domDoc) = 0;

    virtual QDomElement exportItemToXML(QDomDocument *domDoc) = 0;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    vehicleTypeItem *getVehicleType() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    routeItem *getRoute() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getColor() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getDepartLane() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getDepartPos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getDepartSpeed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getArrivalLane() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getArrivalPos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getArrivalSpeed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getLine() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getPersonNumber() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getContainerNumber() const;


    // SET FUNCTIONS

    void setType(vehicleTypeItem *newType);

    void setRoute(routeItem *newRouteVehicle);

    void setColor(const QString &newColor);

    void setDepartLane(const QString &newDepartLane);

    void setDepartPos(const QString &newDepartPos);

    void setDepartSpeed(const QString &newDepartSpeed);

    void setArrivalLane(const QString &newArrivalLane);

    void setArrivalPos(const QString &newArrivalPos);

    void setArrivalSpeed(const QString &newArrivalSpeed);

    void setLine(const QString &newLine);

    void setPersonNumber(int newPersonNumber);

    void setContainerNumber(int newContainerNumber);


protected:

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) = 0;

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) = 0;

    virtual QPainterPath shape() const = 0;


private:

    // SUMO Parameter 02 - Vehicle: The id of the vehicle type to use for this vehicle
    vehicleTypeItem *type;

    // SUMO Parameter 03 - Vehicle: The id of the route the vehicle shall drive along
    routeItem *routeVehicle;

    // SUMO Parameter 04 - Vehicle: Vehicle: This vehicle's color
    QString color;

    // SUMO Parameter 05 - Vehicle: The lane on which the vehicle shall be inserted. [≥0, "random", "free", "allowed", "best", "first"]
    QString departLane;

    // SUMO Parameter 06 - Vehicle: The position at which the vehicle shall enter the net; ["random", "free", "random_free", "base", "pwagSimple", "pwagGeneric"]
    // "free" means the point closest to the start of the departlane where it is possible to insert the vehicle.
    // "random_free" tries forcefully to find a free random position and if that fails, places the vehicle at the next "free" position.
    // "base" sets the vehicle's depart position to the vehicle's length + eps (eps=.1m), this means the vehicle is completely at the begin of the depart lane.
    QString departPos;

    // SUMO Parameter 07 - Vehicle: The speed with which the vehicle shall enter the network. [≥0, "random", "max"]
    QString departSpeed;

    // SUMO Parameter 08 - Vehicle: The lane at which the vehicle shall leave the network [≥0,"current"]
    QString arrivalLane;

    // SUMO Parameter 09 - Vehicle: The position at which the vehicle shall leave the network [≥0(1), "random", "max"]
    QString arrivalPos;

    // SUMO Parameter 10 - Vehicle: The speed with which the vehicle shall leave the network [≥0,"current"]
    QString arrivalSpeed;

    // SUMO Parameter 11 - Vehicle: A string specifying the id of a public transport line which can be used when specifying person rides
    QString line;

    // SUMO Parameter 12 - Vehicle: The number of occupied seats when the vehicle is inserted
    int personNumber;

    // SUMO Parameter 13 - Vehicle: The number of occupied container places when the vehicle is inserted
    int containerNumber;

};

#endif // ENETEDITORVEHICLEITEM_H
