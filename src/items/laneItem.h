#ifndef LANEITEM_H
#define LANEITEM_H

#include "eNetEditorItem.h"

/// FALTA ATRIBUTO ENDOFFSET

class laneItem : public eNetEditorItem
{
public:

    explicit laneItem(edgeItem *newEdgeParent, eNetEditorDatabase *database);

    ~laneItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    void updateLaneLabel();

    void addIncomingConnection(connectionItem *c);

    void removeIncomingConnection(connectionItem *c);

    void clearIncomingConnection();

    void addOutcomingConnection(connectionItem *c);

    void removeOutcomingConnection(connectionItem *c);

    void clearOutcomingConnection();

    void addIncomingProhibition(prohibitionItem *p);

    void removeIncomingProhibition(prohibitionItem *p);

    void clearIncomingProhibition();

    void addOutcomingProhibition(prohibitionItem *p);

    void removeOutcomingProhibition(prohibitionItem *p);

    void clearOutcomingProhibition();

    void addBusStop(busStopItem *bs);

    void removeBusStop(busStopItem *bs);

    void clearBusStop();

    void addChargingStation(chargingStationItem *cs);

    void removeChargingStation(chargingStationItem *cs);

    void clearChargingStation();

    void addInductionLoopsE1Detector(inductionLoopsE1DetectorItem *E1);

    void removeInductionLoopsE1Detector(inductionLoopsE1DetectorItem *E1);

    void clearInductionLoopsE1Detector();

    void addLaneAreaE2Detector(laneAreaE2DetectorItem *E2);

    void removeLaneAreaE2Detector(laneAreaE2DetectorItem *E2);

    void clearLaneAreaE2Detector();

    void addMultiEntryExitE3Detector(multiEntryExitE3DetectorItem *E3);

    void removeMultiEntryExitE3Detector(multiEntryExitE3DetectorItem *E3);

    void clearMultiEntryExitE3Detector();


    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getIndex() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getEdgeParent() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getSpeed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getWidth() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QList<vehicleClass> *getListOfAllowedVehicles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QList<vehicleClass> *getListOfDisallowedVehicles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfIncomingsConnections() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfOutcomingsConnections() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfIncomingsProhibitions() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfOutcomingsProhibitions() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfBusStops() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfChargingStations() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfInductionLoopsDetectorsE1();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfLaneAreaDetectorsE2();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfMultiEntryExitDetectorssE3();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    connectionItem *getFirstIncomingsConnections() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    connectionItem *getLastIncomingsConnections() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    connectionItem *getFirstOutcomingsConnections() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    connectionItem *getLastOutcomingsConnections() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    prohibitionItem *getFirstIncomingsProhibitions() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    prohibitionItem *getLastIncomingsProhibitions() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    prohibitionItem *getFirstOutcomingsProhibitions() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    prohibitionItem *getLastOutcomingsProhibitions() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    busStopItem *getFirstBusStops() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    busStopItem *getLastBusStops() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    chargingStationItem *getFirstChargingStations() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    chargingStationItem *getLastChargingStations() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    inductionLoopsE1DetectorItem *getFirstInductionLoopsE1Detector() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    inductionLoopsE1DetectorItem *getLastInductionLoopsE1Detector() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    laneAreaE2DetectorItem *getFirstLaneAreaE2Detector() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    laneAreaE2DetectorItem *getLastLaneAreaE2Detector() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    multiEntryExitE3DetectorItem *getFirstMultiEntryExitE3Detector() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    multiEntryExitE3DetectorItem *getLastMultiEntryExitE3Detector() const;


    //QLineF getLine

    QLineF getConnectionLineFrontTop(connectionItem *c) const;

    QLineF getConnectionLineFrontBottom(connectionItem *c) const;

    QLineF getConnectionLineBackTop(connectionItem *c) const;

    QLineF getConnectionLineBackBottom(connectionItem *c) const;

    QLineF getInternalLineCentral() const;

    QLineF getInternalLineTop() const;

    QLineF getInternalLineBottom() const;

    QLineF getExternalLineFrontCentral() const;

    QLineF getExternalLineFrontTop() const;

    QLineF getExternalLineFrontBottom() const;

    QLineF getExternalLineBackCentral() const;

    QLineF getExternalLineBackTop() const;

    QLineF getExternalLineBackBottom() const;


    // SET FUNCTIONS

    void setItemId(const QString &newId = "");

    void setSpeed(qreal newSpeed);

    void setWidth(qreal newWidth);

    void setListOfAllowedVehicles(const QList<vehicleClass> &newAllowedVehicles);

    void setListOfDisalllowedVehicles(const QList<vehicleClass> &newDisallowedVehicles);


    // ITERATORS FUNCTIONS

    QList<connectionItem *>::iterator iteratorIncomingsConnectionsBegin();

    QList<connectionItem *>::iterator iteratorIncomingsConnectionsEnd();

    QList<connectionItem *>::iterator iteratorOutcomingsConnectionsBegin();

    QList<connectionItem *>::iterator iteratorOutcomingsConnectionsEnd();

    QList<prohibitionItem *>::iterator iteratorIncomingsProhibitionsBegin();

    QList<prohibitionItem *>::iterator iteratorIncomingsProhibitionsEnd();

    QList<prohibitionItem *>::iterator iteratorOutcomingsProhibitionsBegin();

    QList<prohibitionItem *>::iterator iteratorOutcomingsProhibitionsEnd();

    QList<busStopItem *>::iterator iteratorBusStopsBegin();

    QList<busStopItem *>::iterator iteratorBusStopsEnd();

    QList<chargingStationItem *>::iterator iteratorChargingStationsBegin();

    QList<chargingStationItem *>::iterator iteratorChargingStationsEnd();

    QList<inductionLoopsE1DetectorItem *>::iterator iteratorInductionLoopsE1DetectorBegin();

    QList<inductionLoopsE1DetectorItem *>::iterator iteratorInductionLoopsE1DetectorEnd();

    QList<laneAreaE2DetectorItem *>::iterator iteratorLaneAreaE2DetectorBegin();

    QList<laneAreaE2DetectorItem *>::iterator iteratorLaneAreaE2DetectorEnd();

    QList<multiEntryExitE3DetectorItem *>::iterator iteratorMultiEntryExitE3DetectorBegin();

    QList<multiEntryExitE3DetectorItem *>::iterator iteratorMultiEntryExitE3DetectorEnd();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 01 - index (Set automatic by edge class).
    int index;

    // SUMO Parameter 02 - Speed (By default 50).
    qreal speed;

    // SUMO Parameter 03 - Width (By default 3).
    qreal width;

    // SUMO Parameter 04 - AllowedVehicles (By default empty).
    QList<vehicleClass> *allowedVehicles;

    // SUMO Parameter 05 - DisalllowedVehicles (By default empty).
    QList<vehicleClass> *disallowedVehicles;

    // QT Parameter 01 - Edge (Pointer to edge parent)
    edgeItem *edgeParent;

    // QT Parameter 02 - List of connections
    QList<connectionItem *> listOfIncomingsConnections;

    // QT Parameter 03 - List of connections
    QList<connectionItem *> listOfOutcomingsConnections;

    // QT Parameter 04 - List of prohibitions
    QList<prohibitionItem *> listOfIncomingsProhibitions;

    // QT Parameter 05 - List of prohibitions
    QList<prohibitionItem *> listOfOutcomingsProhibitions;

    // QT Parameter 06 - List of busStations
    QList<busStopItem *> listOfBusStops;

    // QT Parameter 07 - List of ChargingStations
    QList<chargingStationItem *> listOfChargingStations;

    // QT Parameter 08 - List of InductionLoopsE1Detector
    QList<inductionLoopsE1DetectorItem *> listOfInductionLoopsE1Detector;

    // QT Parameter 09 - List of laneAreaE2Detector
    QList<laneAreaE2DetectorItem *> listOfLaneAreaE2Detector;

    // QT Parameter 10 - List of multiEntryExitE3Detector
    QList<multiEntryExitE3DetectorItem *> listOfMultiEntryExitE3Detector;

    // QT Parameter 08 - Rect of the lane
    QRectF laneRect;

    // QT Parameter 15 - Rect at end of Lane (indicates the directiond and if is a semaphore)
    QRectF endRect;


    QLineF frontLineA;
    QLineF frontLineB;

    QLineF backLineA;
    QLineF backLineB;

};



#endif // LANE_H
