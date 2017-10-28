#ifndef FLOWITEM_H
#define FLOWITEM_H

#include "abstractVehicleItem.h"


class flowItem : public abstractVehicleItem
{
public:

    flowItem(const QString &newId, vehicleTypeItem *newType, routeItem *newRouteVehicle, eNetEditorDatabase *database);

    ~flowItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getBegin() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getEnd() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehsPerHour() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getPeriod() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getProbability() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumber() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */




    void setBegin(const qreal newBegin = 0);

    void setEnd(const qreal newEnd = 100);

    void setVehsPerHour(const qreal newVehsPerHour = 50);

    void setPeriod(const qreal newPeriod = 100);

    void setProbability(const qreal newProbability = 0.5);

    void setNumber(const int newNumber = 100);

    void setVehsPerHourOption(bool value);

    void setPeriodOption(bool value);

    void setProbabilityOption(bool value);

    void setProbabilityNumber(bool value);


    // IS FUNCTIONS

    bool isVehsPerHourOptionEnabled();

    bool isPeriodOptionEnabled();

    bool isProbabilityOptionEnabled();

    bool isNumberOptionEnabled();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:



    // SUMO Parameter 14 - Flows: First vehicle departure time in seconds
    qreal begin;

    // SUMO Parameter 15 - Flows: End of departure interval in seconds
    qreal end;

    // SUMO Parameter 16 - Flows: Number of vehicles per hour, equally spaced (not together with period or probability)
    qreal vehsPerHour;

    // SUMO Parameter 17 - Flows: Insert equally spaced vehicles at that period in seconds (not together with vehsPerHour or probability)
    qreal period;

    // SUMO Parameter 18 - Flows: Probability [0,1] for emitting a vehicle each second (not together with vehsPerHour or period)
    qreal probability;

    // SUMO Parameter 19 - Flows: Total number of vehicles, equally spaced
    int number;

    // QT Parameter 01 - Boolean with the option vehsPerHour
    bool vehsPerHourOption;

    // QT Parameter 02 - Boolean with the option period
    bool periodOption;

    // QT Parameter 03 - Boolean with the option probability
    bool probabilityOption;

    // QT Parameter 04 - Boolean with the option number
    bool numberOption;
};



#endif // FLOW_H
