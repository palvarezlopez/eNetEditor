#ifndef ROUTEITEM_H
#define ROUTEITEM_H

#include "eNetEditorItem.h"


class routeItem : public eNetEditorItem
{
public:

    routeItem(const QString &newId, edgeItem *newEdgeOrigin, edgeItem *newEdgeDestiny, eNetEditorDatabase *database);

    ~routeItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    bool addEdge(edgeItem *e);

    bool removeEdge(edgeItem *e);

    void clearEdge()
    {

    }

    void addVehicle(vehicleItem *v);

    void removeVehicle(vehicleItem *v);

    void clearVehicle()
    {

    }

    void addFlow(flowItem *f);

    void removeFlow(flowItem *f);

    void clearFlow()
    {

    }

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
    QList<edgeItem *> *getListOfEdges()const ;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QList<vehicleItem *> *getListOfVehicles()const ;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QList<flowItem *> *getListOfFlows()const ;



    // SET FUNCTIONS

    void setColor(const QString &newColor);


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 02 - List of edges that composite  route
    QList<edgeItem *> *listOfEdges;

    // SUMO Parameter 02 - List of vehicles that using this route
    QList<vehicleItem *> *listOfVehicles;

    // SUMO Parameter 02 - List of flows that using this route
    QList<flowItem *> *listOfFlows;

    // SUMO Parameter 03 - Color of route
    QString color;

    // QT Parameter 01 - Path with the shape of route
    QGraphicsPathItem routePath;
};

#endif // ROUTE_H
