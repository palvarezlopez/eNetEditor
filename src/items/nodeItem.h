#ifndef NODEITEM_H
#define NODEITEM_H

#include "eNetEditorItem.h"

/// FALTAN ATRIBUTOS radius shape keepClear controlledInner

class nodeItem : public eNetEditorItem
{
public:

    // Función terminada y documentada
    nodeItem(const QString &newId, qreal posx, qreal posy, eNetEditorDatabase *database);

    // Función terminada y documentada
    ~nodeItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    void addIncomingEdge(edgeItem *e);

    void removeIncomingEdge(edgeItem *e);

    void clearIncomingEdge();

    void addOutcomingEdge(edgeItem *e);

    void removeOutcomingEdge(edgeItem *e);

    void clearOutcomingEdge();

    void addConnection(connectionItem *c);

    void removeConnection(connectionItem *c);

    void clearConnection();

    void addProhibition(prohibitionItem *p);

    void removeProhibition(prohibitionItem *p);

    void clearProhibition();

    void addTurnRatio(turnRatioItem *tr);

    void removeTurnRatio(turnRatioItem *tr);

    void clearTurnRatio();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getPosx() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getPosy() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getPosz() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    nodeItemType getType() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getCurrentlyDiametre() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    trafficLightItem *getTrafficLight() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfIncomingEdges() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfOutcomingEdges() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfConnections() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfProhibitions() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfTurnRatios() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getFirstIncomingEdge() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getLastIncomingEdge() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getFirstOutcomingEdge() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getLastOutcomingEdge() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    connectionItem *getFirstConnection() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    connectionItem *getLastConnection() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    prohibitionItem *getFirstProhibition() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    prohibitionItem *getLastProhibition() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    turnRatioItem *getFirstTurnRatio() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    turnRatioItem *getLastTurnRatio() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getIncomingEdgeByIndex(int index) const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getOutcomingEdgeByIndex(int index) const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    connectionItem *getConnectionByIndex(int index) const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    prohibitionItem *getProhibitionByIndex(int index) const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QList<turnRatioItem *> getListOfTurnRatiosByEdgeFrom(edgeItem *e);


    // SET FUNCTION

    void setItemId(const QString &newID);

    void setPosx(const qreal newPosx);

    void setPosy(const qreal newPosy);

    void setPosz(const qreal newPosz);

    void setType(nodeItemType newType);

    void setTrafficLight(trafficLightItem *newTLight);

    // IS Function

    bool isTrafficLight();


    // ITERATORS

    QList<edgeItem *>::iterator iteratorIncomingEdgesBegin();

    QList<edgeItem *>::iterator iteratorIncomingEdgesEnd();

    QList<edgeItem *>::iterator iteratorOutcomingEdgesBegin();

    QList<edgeItem *>::iterator iteratorOutcomingEdgesEnd();

    QList<connectionItem *>::iterator iteratorConnectionsBegin();

    QList<connectionItem *>::iterator iteratorConnectionsEnd();

    QList<prohibitionItem *>::iterator iteratorProhibitionsBegin();

    QList<prohibitionItem *>::iterator iteratorProhibitionsEnd();

    QList<turnRatioItem *>::iterator iteratorTurnRatiosBegin();

    QList<turnRatioItem *>::iterator iteratorTurnRatiosEnd();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 02 - x
    // Derivable from this->pos().x()

    // SUMO Parameter 03 - y
    // Derivable from this->pos().y()

    // SUMO Parameter 04 - z
    qreal z;

    // SUMO Parameter 05 - type
    nodeItemType type;

    // SUMO Parameter 06 - tlType
    // Traffic Lights container manage this parameter

    // SUMO Parameter 07 - tl
    // Traffic Lights container manage this parameter

    // SUMO Parameter 08 - shape
    // Optional, Ignored in this version, will be implemented in the future

    // QT Parameter 03 - List of IncomingsEdges
    QList<edgeItem *> listOfIncomingsEdges;

    // QT Parameter 04 - List of OutcomingsEdges
    QList<edgeItem *> listOfOutcomingsEdges;

    // QT Parameter 05 - List of connections
    QList<connectionItem *> listOfConnections;

    // QT Parameter 06 - List of prohibitions
    QList<prohibitionItem *> listOfProhibitions;

    // QT Parameter 08 - List of Turn ratios
    QList<turnRatioItem *> listOfTurnRatios;

    // QT Parameter 09 - Poligon of the node
    QPolygonF nodePolygon;

    // QT Parameter 10 - Pointer to associated Traffic Light (if exist)
    trafficLightItem *tLight;

    // QT Parameter 11 - Currently diameter of node
    int currentlyDiametre;


    /** temporal **/
public:

    QList<QPointF> poligonPoints;
    QList<QLineF> listOfLines;
    /** **/
};

#endif // NODE_H
