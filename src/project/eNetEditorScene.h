#ifndef SCENEPROJECT_H
#define SCENEPROJECT_H

// Defines
#include "../main/eNetEditor.h"


class eNetEditorScene : public QGraphicsScene, public eNetEditor
{
    Q_OBJECT

public:

    // Función terminada y documentada
    explicit eNetEditorScene(eNetEditorProject *newProject);

    // Función terminada y documentada
    explicit eNetEditorScene(const QString &filePath, eNetEditorProject *newProject);

    // Función terminada y documentada
    ~eNetEditorScene();

    // Función terminada y documentada
    void setImageMap();


public slots:

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorProject *getProject() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getMousePosx() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getMousePosy() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */    flagOperation getFlag() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorDatabase *getDatabase() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    itemManagerProject *getParameterManager() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorMessages *getMessages() const;


    // SET FUNCTIONS

    // Función terminada y documentada
    void setFlag(flagOperation newFlag);

    void setNumberOfAutomaticLanes(int newNumberOfAutomaticLanes);

    void setDoubleEdge(bool newDoubleEdge);

    void setScrolling(bool value);

    // IS FUNCTIONS

    bool isScrolling();

    /** Add items functions **/

    // Función terminada y documentada
    nodeItem *insertNodeInScene(qreal posx, qreal posy);

    // Función terminada y documentada
    edgeItem *insertEdgeInScene(nodeItem *nodeOrigin, nodeItem *nodeDestiny);

    // Función terminada y documentada
    connectionItem *insertConnectionInScene(laneItem *laneOrigin, laneItem *laneDestiny);

    // Función terminada y documentada
    prohibitionItem *insertProhibitionInScene(edgeItem *edgeOrigin, edgeItem *edgeDestiny);

    // Función terminada y documentada
    trafficLightItem *insertTrafficLightInScene(nodeItem *n);

    // Función Terminada y documentada
    routeItem *insertOrUpdateRouteInScene(edgeItem *edgeOrigin, edgeItem *edgeDestiny);

    // Función terminada y documentada
    busStopItem *insertBusStopInScene(laneItem *laneParent);

    // Función terminada y documentada
    chargingStationItem *insertChargingStationInScene(laneItem *laneParent);

    // Función terminada y documentada
    void resetAndCreateAutomaticConnections(nodeItem *n);

    /** Remove Items functions **/

    // Función terminada y documentada
    bool removeNode(nodeItem *n);

    // Función terminada y documentada
    bool removeLane(laneItem *l);

    // Función terminada y documentada
    bool removeConnection(connectionItem *c);

    // Función terminada y documentada
    bool removeProhibition(prohibitionItem *p);

    // Función terminada y documentada
    bool removeTrafficLight(nodeItem *n);

    // Función terminada y documentada
    bool removeRoute(routeItem *r);

    /** Operations functions **/

    void processOperationAddNodeOrEdgeOrLane(QGraphicsItem *item);

    void processOperationAddConnection(QGraphicsItem *item);

    void processOperationAddProhibition(QGraphicsItem *item);

    void processOperationAddRoute(QGraphicsItem *item);

    void processOperationAddTrafficLight(QGraphicsItem *item);

    void processOperationAddBusStop(QGraphicsItem *item);

    void processOperationAddChargingStation(QGraphicsItem *item);

    void processOperationRemoveNodeOrEdgeOrLane(QGraphicsItem *item);

    void processOperationRemoveConnection(QGraphicsItem *item);

    void processOperationRemoveProhibition(QGraphicsItem *item);

    void processOperationRemoveRoute(QGraphicsItem *item);

    void processOperationRemoveTrafficLight(QGraphicsItem *item);

    void processOperationRemoveBusStop(QGraphicsItem *item);

    void processOperationRemoveChargingStation(QGraphicsItem *item);


protected:

    //void drawBackground(QPainter *painter, const QRectF &rect);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);


signals:

    // Update mouse pos in the main Dialog
    void updateMousePos(qreal x, qreal y);


private:

    // Pointer to project parent
    eNetEditorProject *project;

    // Parameter manager
    itemManagerProject *parameterManager;

    // Database with the elements
    eNetEditorDatabase *database;

    // Image with the map
    QGraphicsPixmapItem *imageMapItem;

    // Position of mouse in the scene
    qreal posx;
    qreal posy;

    // Number of automatic lanes
    int numberOfAutomaticLanes;

    // Automatic double Edge
    bool doubleEdge;

    // Pointer to node (used in the insertion of new nodes)
    nodeItem *temporalNode;
    nodeItem *lastInsertedNode;

    // Pointer to grabbed item
    QGraphicsItem *grabbedItem;

    // Bool to check if shift key is pressed
    bool shiftKeyPressed;

    // Bool to check if user is scrolling window
    bool scrolling;

    // Bool to indicate if selfconnections are allowed
    bool allowSelfconnection;

    // Flag
    flagOperation flag;
};


#endif
