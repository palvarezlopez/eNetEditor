#ifndef ITEMMANAGERPROJECT_H
#define ITEMMANAGERPROJECT_H

#include "../main/eNetEditor.h"


class itemManagerProject
{
public:

    itemManagerProject();

    ~itemManagerProject();

    void dismarkAllItems();

    int getNumberOfItemsMarked();

    void setBlockAllItems(bool value);

    void setShowAllItems(bool value);

    void setShowLabelAllItems(bool value);

    void setShowIconAllItems(bool value);


// Set functions individual

    // Marking

    void markNode(nodeItem *n);

    void markEdge(edgeItem *e);

    void markLane(laneItem *l);

    void markConnection(connectionItem *c);

    void markProhibition(prohibitionItem *p);

    void markRoute(routeItem *r);

    void markBusStop(busStopItem *bs);

    void markChargingStation(chargingStationItem *cs);


    // Dismarking

    // Single items

    void dismarkNode(nodeItem *n);

    void dismarkEdge(edgeItem *e);

    void dismarkLane(laneItem *l);

    void dismarkConnection(connectionItem *c);

    void dismarkProhibition(prohibitionItem *p);

    void dismarkRoute(routeItem *r);

    void dismarkBusStop(busStopItem *bs);

    void dismarkChargingStation(chargingStationItem *cs);


    // All type of items

    void dismarkAllNodes();

    void dismarkAllEdges();

    void dismarkAllLanes();

    void dismarkAllConnections();

    void dismarkAllProhibitions();

    void dismarkAllRoutes();

    void dismarkAllBusStops();

    void dismarkAllChargingStations();


    // Get marked

    QList<nodeItem *> *getListOfNodesMarked() const;

    QList<edgeItem *> *getListOfEdgesMarked() const;

    QList<laneItem *> *getListOfLanesMarked() const;

    QList<connectionItem *> *getListOfConnectionsMarked() const;

    QList<prohibitionItem *> *getListOfProhibitionsMarked() const;

    QList<routeItem *> *getListOfRoutesMarked() const;

    QList<busStopItem *> *getListOfBusStopsMarked() const;

    QList<chargingStationItem *> *getListOfChargingStationsMarked() const;


// Set functions

    // Movement

    void setNodesMovables(bool value);


    // Block

    void setBlockAllNodes(bool value);

    void setBlockAllEdges(bool value);

    void setBlockAllLanes(bool value);

    void setBlockAllConnections(bool value);

    void setBlockAllProhibitions(bool value);

    void setBlockAllRoutes(bool value);

    void setBlockAllBusStops(bool value);

    void setBlockAllChargingStations(bool value);

    void setBlockAllDetectors(bool value);


    // Show Label

    void setShowLabelAllNodes(bool value);

    void setShowLabelAllEdges(bool value);

    void setShowLabelAllLanes(bool value);

    void setShowLabelAllConnections(bool value);

    void setShowLabelAllProhibitions(bool value);

    void setShowLabelAllRoutes(bool value);

    void setShowLabelAllBusStops(bool value);

    void setShowLabelAllChargingStations(bool value);

    void setShowLabelAllDetectors(bool value);


    // Show Icon

    void setShowIconAllNodes(bool value);

    void setShowIconAllBusStops(bool value);

    void setShowIconAllChargingStations(bool value);


    // Show Item

    void setShowAllNodes(bool value);

    void setShowAllEdges(bool value);

    void setShowAllLanes(bool value);

    void setShowAllConnections(bool value);

    void setShowAllProhibitions(bool value);

    void setShowAllRoutes(bool value);

    void setShowAllBusStops(bool value);

    void setShowAllChargingStations(bool value);

    void setShowAllDetectors(bool value);

// IS Fuctions

    // Movement

    bool isNodesMovables();


    // Blocked

    bool isNodesBlocked();

    bool isEdgeBlocked();

    bool isLaneBlocked();

    bool isConnectionBlocked();

    bool isProhibitionBlocked();

    bool isRouteBlocked();

    bool isBusStopBlocked();

    bool isChargingStationBlocked();

    bool isDetectorBlocked();


    // ShowLabel

    bool isNodesShowLabelEnabled();

    bool isEdgeShowLabelEnabled();

    bool isLaneShowLabelEnabled();

    bool isConnectionShowLabelEnabled();

    bool isProhibitionShowLabelEnabled();

    bool isRouteShowLabelEnabled();

    bool isBusStopShowLabelEnabled();

    bool isChargingStationShowLabelEnabled();

    bool isDetectorShowLabelEnabled();


    // ShowIcon

    bool isNodesShowIconEnabled();

    bool isBusStopShowIconEnabled();

    bool isChargingStationShowIconEnabled();


    // Show Item

    bool isShowAllNodeItems();

    bool isShowAllEdgeItems();

    bool isShowAllLaneItems();

    bool isShowAllConnectionItems();

    bool isShowAllProhibitionItems();

    bool isShowAllRouteItems();

    bool isShowAllBusStopItems();

    bool isShowAllChargingStationItems();

    bool isShowAllDetectorItems();


private:

    // Lists of pointers to marked items
    QList<nodeItem *> *listOfNodesMarked;
    QList<edgeItem *> *listOfEdgesMarked;
    QList<laneItem *> *listOfLanesMarked;
    QList<connectionItem *> *listOfConnectionsMarked;
    QList<prohibitionItem *> *listOfProhibitionsMarked;
    QList<routeItem *> *listOfRoutesMarked;
    QList<busStopItem *> *listOfBusStopsMarked;
    QList<chargingStationItem *> *listOfChargingStationsMarked;
    QList<abstractDetectorItem *> *listOfDetectorsMarked;

    // Movable value
    bool nodeMovables;

    // Block value
    bool nodeBlocked;
    bool edgeBlocked;
    bool laneBlocked;
    bool connectionBlocked;
    bool prohibitionBlocked;
    bool routeBlocked;
    bool busStopBlocked;
    bool chargingStationBlocked;
    bool detectorBlocked;

    // Show icon value
    bool nodeShowIcon;
    bool busStopShowIcon;
    bool chargingStationShowIcon;

    // Show label value
    bool nodeShowLabel;
    bool edgeShowLabel;
    bool laneShowLabel;
    bool connectionShowLabel;
    bool prohibitionShowLabel;
    bool routeShowLabel;
    bool busStopShowLabel;
    bool chargingStationShowLabel;
    bool detectorShowLabel;

    // Show Item
    bool nodeShowItem;
    bool edgeShowItem;
    bool laneShowItem;
    bool connectionShowItem;
    bool prohibitionShowItem;
    bool routeShowItem;
    bool busStopShowItem;
    bool chargingStationShowItem;
    bool detectorShowItem;
};

#endif // ITEMMANAGERPROJECT_H
