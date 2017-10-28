#ifndef CONNECTIONITEM_H
#define CONNECTIONITEM_H

#include "eNetEditorItem.h"


/// ATENCION: FALTAN PARAMETROS uncontrolled y keepClear

class connectionItem : public eNetEditorItem
{
public:

    connectionItem(laneItem *newLaneOrigin, laneItem *newLaneDestiny, eNetEditorDatabase *database);

    ~connectionItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    void updateIndexLabel();

    bool updateState(int indexRegardingNode, char c);


    /**
        @brief Get

        @return QString with the
        @details Get
    */
    nodeItem *getNodeParent() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getEdgeOrigin() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getEdgeDestiny() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    laneItem *getLaneOrigin() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    laneItem *getLaneDestiny() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    trafficLightItem *getTlight() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getIndexRegardingNode() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getIndexRegardingLaneOrigin() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getIndexRegardingLaneDestiny() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getLinkIndex() const;

    QVector<char> &getVectorOfStates(); /** pasar a puntero **/

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getOriginIndex() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getDestinyIndex() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getOriginPos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getDestinyPos() const;


    // SET FUNCTIONS

    void setItemId(const QString &newId = "");

    void setTrafficLight(trafficLightItem *newTlight);

    void setPass(bool value);

    void setLinkIndex(int newLinkIndex);

    void setVectorOfStates(const QVector<char> &newVectorOfStates);


    // IS FUNCTIONS

    bool isPassEnabled();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 01 - Pointer to edge origin
    // Derivable from SUMO Parameter 03

    // SUMO Parameter 02 - Pointer to edge destiny
    // Derivable from SUMO Parameter 04

    // SUMO Parameter 03 - Pointer to lane origin
    laneItem *laneOrigin;

    // SUMO Parameter 04 - Pointer to lane destiny
    laneItem *laneDestiny;

    // SUMO Parameter 05 - if set, vehicles which pass this (lane-2-lane) connection) will not wait
    bool pass;

    // SUMO Parameter 06 - pointer to traffic Light (if exist)
    trafficLightItem *tlight;

    // SUMO Parameter 07 - Vector with the connection states (if exist)
    QVector<char> vectorOfStates;

    // QT Parameter 01 - Node parent of the connection (Node-EdgeOrigin-nodeParent-EdgeDestiny-Node)
    nodeItem *nodeParent;

    // QT Parameter 02 - Index of connection (Regarding of the node)
    int indexRegardingNode;

    // QT Parameter 03 - Index of connection (Regarding of the Lane Origin)
    int indexRegardingLaneOrigin;

    // QT Parameter 04 - Index of connection (Regarding of the Lane Origin)
    int indexRegardingLaneDestiny;

    // QT Parameter 05 - Path with the shape of connection
    QGraphicsPathItem connectionPath;

    // QT Parameter 06 - LinkIndexAutomatic of the connection (will be set after the ejecution of netConvert)
    int linkIndex;
};

#endif // CONNECTION_H
