#include "itemManagerProject.h"

#include "../items/nodeItem.h"
#include "../items/edges/edgeItem.h"
#include "../items/laneItem.h"
#include "../items/connectionItem.h"
#include "../items/prohibitionItem.h"
#include "../items/routeItem.h"
#include "../items/stops/busStopItem.h"
#include "../items/stops/chargingStationItem.h"
#include "../items/vehicles/flowItem.h"
#include "../items/detectors/abstractDetectorItem.h"


itemManagerProject::itemManagerProject()
{
    // Movable value
    nodeMovables = false;

    // Block value
    nodeBlocked = true;
    edgeBlocked = true;
    laneBlocked = true;
    connectionBlocked = true;
    prohibitionBlocked = true;
    routeBlocked = true;
    busStopBlocked = true;
    chargingStationBlocked = true;
    detectorBlocked = true;

    // Show icon value
    nodeShowIcon = false;
    busStopShowIcon = false;
    chargingStationShowIcon = false;

    // Show label value
    nodeShowLabel = false;
    edgeShowLabel = false;
    laneShowLabel = false;
    connectionShowLabel = false;
    prohibitionShowLabel = false;
    routeShowLabel = false;
    busStopShowLabel = false;
    chargingStationShowLabel = false;
    detectorShowLabel = false;

    // Show Item
    nodeShowItem = true;
    edgeShowItem = true;
    laneShowItem = true;
    connectionShowItem = true;
    prohibitionShowItem = true;
    routeShowItem = true;
    busStopShowItem = true;
    chargingStationShowItem = true;

    // Create lists
    listOfNodesMarked = new QList<nodeItem *>;
    listOfEdgesMarked = new QList<edgeItem *>;
    listOfLanesMarked = new QList<laneItem *>;
    listOfConnectionsMarked = new QList<connectionItem *>;
    listOfProhibitionsMarked = new QList<prohibitionItem *>;
    listOfRoutesMarked = new QList<routeItem *>;
    listOfBusStopsMarked = new QList<busStopItem *>;
    listOfChargingStationsMarked = new QList<chargingStationItem *>;
    listOfDetectorsMarked = new QList<abstractDetectorItem *>;
}

itemManagerProject::~itemManagerProject()
{
    // Delete lists
    delete listOfNodesMarked;
    delete listOfEdgesMarked;
    delete listOfLanesMarked;
    delete listOfConnectionsMarked;
    delete listOfProhibitionsMarked;
    delete listOfRoutesMarked;
    delete listOfBusStopsMarked;
    delete listOfChargingStationsMarked;
    delete listOfDetectorsMarked;
}

void itemManagerProject::dismarkAllItems()
{
    dismarkAllNodes();
    dismarkAllEdges();
    dismarkAllLanes();
    dismarkAllConnections();
    dismarkAllProhibitions();
    dismarkAllRoutes();
    dismarkAllBusStops();
    dismarkAllChargingStations();
}

int itemManagerProject::getNumberOfItemsMarked()
{
    return listOfNodesMarked->size() +
           listOfEdgesMarked->size() +
           listOfLanesMarked->size() +
           listOfConnectionsMarked->size() +
           listOfProhibitionsMarked->size() +
           listOfRoutesMarked->size() +
           listOfBusStopsMarked->size() +
           listOfChargingStationsMarked->size() +
           listOfDetectorsMarked->size();
}

void itemManagerProject::setBlockAllItems(bool value)
{
    setBlockAllNodes(value);
    setBlockAllEdges(value);
    setBlockAllLanes(value);
    setBlockAllConnections(value);
    setBlockAllProhibitions(value);
    setBlockAllRoutes(value);
    setBlockAllBusStops(value);
    setBlockAllChargingStations(value);
    setBlockAllDetectors(value);
}

void itemManagerProject::setShowAllItems(bool value)
{
    setShowAllNodes(value);
    setShowAllEdges(value);
    setShowAllLanes(value);
    setShowAllConnections(value);
    setShowAllProhibitions(value);
    setShowAllRoutes(value);
    setShowAllBusStops(value);
    setShowAllChargingStations(value);
    setShowAllDetectors(value);
}

void itemManagerProject::setShowLabelAllItems(bool value)
{
    setShowLabelAllNodes(value);
    setShowLabelAllEdges(value);
    setShowLabelAllLanes(value);
    setShowLabelAllConnections(value);
    setShowLabelAllProhibitions(value);
    setShowLabelAllRoutes(value);
    setShowLabelAllBusStops(value);
    setShowLabelAllChargingStations(value);
    setShowLabelAllDetectors(value);
}

void itemManagerProject::setShowIconAllItems(bool value)
{
    setShowIconAllNodes(value);
    setShowIconAllBusStops(value);
    setShowIconAllChargingStations(value);
}

void itemManagerProject::markNode(nodeItem *n)
{
    // If item isn't already marked
    if(n->isItemMarked() == false)
    {
        // Mark item
        n->setItemMarked(true);

        // insert in the corresponding list
        listOfNodesMarked->push_back(n);
    }
}

void itemManagerProject::markEdge(edgeItem *e)
{
    // If item isn't already marked
    if(e->isItemMarked() == false)
    {
        // Mark item
        e->setItemMarked(true);

        // insert in the corresponding list
        listOfEdgesMarked->push_back(e);
    }
}

void itemManagerProject::markLane(laneItem *l)
{
    // If item isn't already marked
    if(l->isItemMarked() == false)
    {
        // Mark item
        l->setItemMarked(true);

        // insert in the corresponding list
        listOfLanesMarked->push_back(l);
    }
}

void itemManagerProject::markConnection(connectionItem *c)
{
    // If item isn't already marked
    if(c->isItemMarked() == false)
    {
        // Mark item
        c->setItemMarked(true);

        // insert in the corresponding list
        listOfConnectionsMarked->push_back(c);
    }
}

void itemManagerProject::markProhibition(prohibitionItem *p)
{
    // If item isn't already marked
    if(p->isItemMarked() == false)
    {
        // Mark item
        p->setItemMarked(true);

        // insert in the corresponding list
        listOfProhibitionsMarked->push_back(p);
    }
}

void itemManagerProject::markRoute(routeItem *r)
{
    // If item isn't already marked
    if(r->isItemMarked() == false)
    {
        // Mark item
        r->setItemMarked(true);

        // insert in the corresponding list
        listOfRoutesMarked->push_back(r);
    }
}

void itemManagerProject::markBusStop(busStopItem *bs)
{
    // If item isn't already marked
    if(bs->isItemMarked() == false)
    {
        // Mark item
        bs->setItemMarked(true);

        // insert in the corresponding list
        listOfBusStopsMarked->push_back(bs);
    }
}

void itemManagerProject::markChargingStation(chargingStationItem *cs)
{
    // If item isn't already marked
    if(cs->isItemMarked() == false)
    {
        // Mark item
        cs->setItemMarked(true);

        // insert in the corresponding list
        listOfChargingStationsMarked->push_back(cs);
    }
}

void itemManagerProject::dismarkNode(nodeItem *n)
{
    n->setItemMarked(false);

    listOfNodesMarked->removeAll(n);
}

void itemManagerProject::dismarkEdge(edgeItem *e)
{
    e->setItemMarked(false);

    listOfEdgesMarked->removeAll(e);
}

void itemManagerProject::dismarkLane(laneItem *l)
{
    l->setItemMarked(false);

    listOfLanesMarked->removeAll(l);
}

void itemManagerProject::dismarkConnection(connectionItem *c)
{
    c->setItemMarked(false);

    listOfConnectionsMarked->removeAll(c);
}

void itemManagerProject::dismarkProhibition(prohibitionItem *p)
{
    p->setItemMarked(false);

    listOfProhibitionsMarked->removeAll(p);
}

void itemManagerProject::dismarkRoute(routeItem *r)
{
    r->setItemMarked(false);

    listOfRoutesMarked->removeAll(r);
}

void itemManagerProject::dismarkBusStop(busStopItem *bs)
{
    bs->setItemMarked(false);

    listOfBusStopsMarked->removeAll(bs);
}

void itemManagerProject::dismarkChargingStation(chargingStationItem *cs)
{
    cs->setItemMarked(false);

    listOfChargingStationsMarked->removeAll(cs);
}

void itemManagerProject::dismarkAllNodes()
{
    // Dismark all nodes
    for (QList<nodeItem *>::iterator i = listOfNodesMarked->begin(); i != listOfNodesMarked->end(); i++)
    {
        (*i)->setItemMarked(false);
    }

    // Clear List
    listOfNodesMarked->clear();
}

void itemManagerProject::dismarkAllEdges()
{
    // Dismark all edges
    for (QList<edgeItem *>::iterator i = listOfEdgesMarked->begin(); i != listOfEdgesMarked->end(); i++)
    {
        (*i)->setItemMarked(false);
    }

    // Clear List
    listOfEdgesMarked->clear();
}

void itemManagerProject::dismarkAllLanes()
{
    // Dismark all lanes
    for (QList<laneItem *>::iterator i = listOfLanesMarked->begin(); i != listOfLanesMarked->end(); i++)
    {
        (*i)->setItemMarked(false);
    }

    // Clear List
    listOfLanesMarked->clear();
}

void itemManagerProject::dismarkAllConnections()
{
    // Dismark all Connections
    for (QList<connectionItem *>::iterator i = listOfConnectionsMarked->begin(); i != listOfConnectionsMarked->end(); i++)
    {
        (*i)->setItemMarked(false);
    }

    // Clear List
    listOfConnectionsMarked->clear();
}

void itemManagerProject::dismarkAllProhibitions()
{
    // Dismark all Prohibitions
    for (QList<prohibitionItem *>::iterator i = listOfProhibitionsMarked->begin(); i != listOfProhibitionsMarked->end(); i++)
    {
        (*i)->setItemMarked(false);
    }

    // Clear List
    listOfProhibitionsMarked->clear();
}

void itemManagerProject::dismarkAllRoutes()
{
    // Dismark all Routes
    for (QList<routeItem *>::iterator i = listOfRoutesMarked->begin(); i != listOfRoutesMarked->end(); i++)
    {
        (*i)->setItemMarked(false);
    }

    // Clear List
    listOfRoutesMarked->clear();
}

void itemManagerProject::dismarkAllBusStops()
{
    // Dismark all BusStops
    for (QList<busStopItem *>::iterator i = listOfBusStopsMarked->begin(); i != listOfBusStopsMarked->end(); i++)
    {
        (*i)->setItemMarked(false);
    }

    // Clear List
    listOfBusStopsMarked->clear();
}

void itemManagerProject::dismarkAllChargingStations()
{
    // Dismark all Charging Stations
    for (QList<chargingStationItem *>::iterator i = listOfChargingStationsMarked->begin(); i != listOfChargingStationsMarked->end(); i++)
    {
        (*i)->setItemMarked(false);
    }

    // Clear List
    listOfChargingStationsMarked->clear();
}

QList<nodeItem *> *itemManagerProject::getListOfNodesMarked() const
{
    return listOfNodesMarked;
}

QList<edgeItem *> *itemManagerProject::getListOfEdgesMarked() const
{
    return listOfEdgesMarked;
}

QList<laneItem *> *itemManagerProject::getListOfLanesMarked() const
{
    return listOfLanesMarked;
}

QList<connectionItem *> *itemManagerProject::getListOfConnectionsMarked() const
{
    return listOfConnectionsMarked;
}

QList<prohibitionItem *> *itemManagerProject::getListOfProhibitionsMarked() const
{
    return listOfProhibitionsMarked;
}

QList<routeItem *> *itemManagerProject::getListOfRoutesMarked() const
{
    return listOfRoutesMarked;
}

QList<busStopItem *> *itemManagerProject::getListOfBusStopsMarked() const
{
    return listOfBusStopsMarked;
}

QList<chargingStationItem *> *itemManagerProject::getListOfChargingStationsMarked() const
{
    return listOfChargingStationsMarked;
}

void itemManagerProject::setNodesMovables(bool value)
{
    nodeMovables = value;
}

void itemManagerProject::setBlockAllNodes(bool value)
{
    nodeBlocked = value;
}

void itemManagerProject::setBlockAllEdges(bool value)
{
    edgeBlocked = value;
}

void itemManagerProject::setBlockAllLanes(bool value)
{
    laneBlocked = value;
}

void itemManagerProject::setBlockAllConnections(bool value)
{
    connectionBlocked = value;
}

void itemManagerProject::setBlockAllProhibitions(bool value)
{
    prohibitionBlocked = value;
}

void itemManagerProject::setBlockAllRoutes(bool value)
{
    routeBlocked = value;
}

void itemManagerProject::setBlockAllBusStops(bool value)
{
    busStopBlocked = value;
}

void itemManagerProject::setBlockAllChargingStations(bool value)
{
    chargingStationBlocked = value;
}

void itemManagerProject::setBlockAllDetectors(bool value)
{
    detectorBlocked = value;
}

void itemManagerProject::setShowLabelAllNodes(bool value)
{
    nodeShowLabel = value;
}

void itemManagerProject::setShowLabelAllEdges(bool value)
{
    edgeShowLabel = value;
}

void itemManagerProject::setShowLabelAllLanes(bool value)
{
    laneShowLabel = value;
}

void itemManagerProject::setShowLabelAllConnections(bool value)
{
    connectionShowLabel = value;
}

void itemManagerProject::setShowLabelAllProhibitions(bool value)
{
    prohibitionShowLabel = value;
}

void itemManagerProject::setShowLabelAllRoutes(bool value)
{
    routeShowLabel = value;
}

void itemManagerProject::setShowLabelAllBusStops(bool value)
{
    busStopShowLabel = value;
}

void itemManagerProject::setShowLabelAllChargingStations(bool value)
{
    chargingStationShowLabel = value;
}

void itemManagerProject::setShowLabelAllDetectors(bool value)
{
    detectorShowLabel = value;
}

void itemManagerProject::setShowIconAllNodes(bool value)
{
    nodeShowIcon = value;
}

void itemManagerProject::setShowIconAllBusStops(bool value)
{
    busStopShowIcon = value;
}

void itemManagerProject::setShowIconAllChargingStations(bool value)
{
    chargingStationShowIcon = value;
}

void itemManagerProject::setShowAllNodes(bool value)
{
    nodeShowItem = value;
}

void itemManagerProject::setShowAllEdges(bool value)
{
    edgeShowItem = value;
}

void itemManagerProject::setShowAllLanes(bool value)
{
    laneShowItem = value;
}

void itemManagerProject::setShowAllConnections(bool value)
{
    connectionShowItem = value;
}

void itemManagerProject::setShowAllProhibitions(bool value)
{
    prohibitionShowItem = value;
}

void itemManagerProject::setShowAllRoutes(bool value)
{
    routeShowItem = value;
}

void itemManagerProject::setShowAllBusStops(bool value)
{
    busStopShowItem = value;
}

void itemManagerProject::setShowAllChargingStations(bool value)
{
    chargingStationShowItem = value;
}

void itemManagerProject::setShowAllDetectors(bool value)
{
    detectorShowItem = value;
}

bool itemManagerProject::isNodesMovables()
{
    return nodeMovables;
}

bool itemManagerProject::isNodesBlocked()
{
    return nodeBlocked;
}

bool itemManagerProject::isEdgeBlocked()
{
    return edgeBlocked;
}

bool itemManagerProject::isLaneBlocked()
{
    return laneBlocked;
}

bool itemManagerProject::isConnectionBlocked()
{
    return connectionBlocked;
}

bool itemManagerProject::isProhibitionBlocked()
{
    return prohibitionBlocked;
}

bool itemManagerProject::isRouteBlocked()
{
    return routeBlocked;
}

bool itemManagerProject::isBusStopBlocked()
{
    return busStopBlocked;
}

bool itemManagerProject::isChargingStationBlocked()
{
    return chargingStationBlocked;
}

bool itemManagerProject::isDetectorBlocked()
{
    return detectorBlocked;
}

bool itemManagerProject::isNodesShowLabelEnabled()
{
    return nodeShowLabel;
}

bool itemManagerProject::isEdgeShowLabelEnabled()
{
    return edgeShowLabel;
}

bool itemManagerProject::isLaneShowLabelEnabled()
{
    return laneShowLabel;
}

bool itemManagerProject::isConnectionShowLabelEnabled()
{
    return connectionShowLabel;
}

bool itemManagerProject::isProhibitionShowLabelEnabled()
{
    return prohibitionShowLabel;
}

bool itemManagerProject::isRouteShowLabelEnabled()
{
    return routeShowLabel;
}

bool itemManagerProject::isBusStopShowLabelEnabled()
{
    return busStopShowLabel;
}

bool itemManagerProject::isChargingStationShowLabelEnabled()
{
    return chargingStationShowLabel;
}

bool itemManagerProject::isDetectorShowLabelEnabled()
{
    return detectorShowLabel;
}

bool itemManagerProject::isNodesShowIconEnabled()
{
    return nodeShowIcon;
}


bool itemManagerProject::isBusStopShowIconEnabled()
{
    return busStopShowIcon;
}

bool itemManagerProject::isChargingStationShowIconEnabled()
{
    return chargingStationShowIcon;
}

bool itemManagerProject::isShowAllNodeItems()
{
    return nodeShowItem;
}

bool itemManagerProject::isShowAllEdgeItems()
{
    return edgeShowItem;
}

bool itemManagerProject::isShowAllLaneItems()
{
    return laneShowItem;
}

bool itemManagerProject::isShowAllConnectionItems()
{
    return connectionShowItem;
}

bool itemManagerProject::isShowAllProhibitionItems()
{
    return prohibitionShowItem;
}

bool itemManagerProject::isShowAllRouteItems()
{
    return routeShowItem;
}

bool itemManagerProject::isShowAllBusStopItems()
{
    return busStopShowItem;
}

bool itemManagerProject::isShowAllChargingStationItems()
{
    return chargingStationShowItem;
}

bool itemManagerProject::isShowAllDetectorItems()
{
    return detectorShowItem;
}
