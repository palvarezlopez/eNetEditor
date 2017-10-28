#ifndef ENETEDITORDATABASE_H
#define ENETEDITORDATABASE_H

#include "../main/eNetEditor.h"


class eNetEditorDatabase : public eNetEditor
{
public:

    eNetEditorDatabase(eNetEditorScene *newScene);

    eNetEditorDatabase(const QString &filePath, eNetEditorScene *newScene);

    ~eNetEditorDatabase();

    bool save();

    bool load();

    // GET FUNCTIONS

    eNetEditorScene *geteNetEditorScene() const;

    eNetEditorProject *getProject() const;

    eNetEditorProjectConfiguration *getProjectConfiguration() const;

    eNetEditorMessages *getMessages() const;

    // Set functions

    /// Eliminar esta funcion
    void setScaleInTable(qreal newMapPixelMeter);

    void setSaved(bool value);

    // IS FUNCTIONS

    bool isSaved();



    /** Functions relative to all items **/

    bool exportDatabaseToXML();

    int getNumberOfItems();

    nodeItem *findNodeById(const QString &IdToSearch);

    edgeItem *findEdgeById(const QString &IdToSearch);

    QStringList getIdsOfLanes(edgeItem *e);

    laneItem *findLaneById(const QString &IdToSearch);

    connectionItem *findConnectionById(const QString &IdToSearch);

    connectionItem *findConnectionByComponents(laneItem *laneOrigin, laneItem *laneDestiny);

    prohibitionItem *findProhibitionById(const QString &IdToSearch);

    prohibitionItem *findProhibitionByComponents(edgeItem *edgeOrigin, edgeItem *edgeDestiny);

    routeItem *findRouteById(const QString &IdToSearch);

    busStopItem *findBusStopById(const QString &IdToSearch);

    chargingStationItem *findChargingStationById(const QString &IdToSearch);

    vehicleTypeItem *findVehicleTypeById(const QString &IdToSearch);

    vehicleTypeItem *getVehicleTypeOfTable(int index);

    flowItem *findFlowById(const QString &IdToSearch);

    vehicleItem *findVehicleById(const QString &IdToSearch);

    edgeTypeItem *findEdgeTypeById(const QString &IdToSearch);

    inductionLoopsE1DetectorItem *findInductionLoopsE1DetectorById(const QString &IdToSearch);

    laneAreaE2DetectorItem *findLaneAreaE2DetectorById(const QString &IdToSearch);

    multiEntryExitE3DetectorItem *findMultiEntryExitE3DetectorById(const QString &IdToSearch);

    flowMeasureItem *findFlowMeasureById(const QString &IdToSearch);

    distributionFunctionItem *findDistributionFunctionById(const QString &IdToSearch);

    turnRatioItem *findTurnRatioById(const QString &IdToSearch);

    // Tables

    nodeTable *getNodeTable() const;

    edgeTable *getEdgeTable() const;

    laneTable *getLaneTable() const;

    connectionTable *getConnectionTable() const;

    prohibitionTable *getProhibitionTable() const;

    routeTable *getRouteTable() const;

    trafficLightTable *getTrafficLightTable() const;

    busStopTable *getBusStopTable() const;

    chargingStationTable *getChargingStationTable() const;

    vehicleTypeTable *getVehicleTypeTable() const;

    flowTable *getFlowTable() const;

    edgeTypeTable *getEdgeTypeTable() const;

    vehicleTable *getVehicleTable() const;

    inductionLoopsE1DetectorTable *getInductionLoopsE1Table() const;

    laneAreaE2DetectorTable *getLaneAreaE2Table() const;

    multiEntryExitE3DetectorTable *getMultiEntryExitE3Table() const;

    flowMeasureTable *getFlowMeasureTable() const;

    distributionFunctionTable *getDistributionFunctionTable() const;

    turnRatioIntervalTable *getTurnRatioIntervalTable() const;

    turnRatioTable *getTurnRatioTable() const;


private:

    // Pointer to scene parent
    eNetEditorScene *scene;

    // Undo Redo
    undoRedoProject *undoRedo;

    // Flag saved
    bool saved;

    // Tables with the items
    nodeTable *nTable;
    edgeTable *eTable;
    laneTable *lTable;
    connectionTable *cTable;
    prohibitionTable *pTable;
    routeTable *rTable;
    trafficLightTable *tlTable;
    busStopTable *bsTable;
    chargingStationTable *csTable;
    vehicleTypeTable *vtTable;
    flowTable *fTable;
    edgeTypeTable *etTable;
    vehicleTable *vTable;
    inductionLoopsE1DetectorTable *E1Table;
    laneAreaE2DetectorTable *E2Table;
    multiEntryExitE3DetectorTable *E3Table;
    flowMeasureTable *fmTable;
    distributionFunctionTable *dfTable;
    turnRatioIntervalTable *triTable;
    turnRatioTable *trTable;

    // Loading functions
    void loadNodes(QDomElement rootTable);

    void loadEdges(QDomElement rootTable);

    void loadLanes(QDomElement rootTable);

    void loadConnections(QDomElement rootTable);

    void loadProhibitions(QDomElement rootTable);

    void loadRoutes(QDomElement rootTable);

    void loadTrafficLights(QDomElement rootTable);

    void loadBusStops(QDomElement rootTable);

    void loadChargingStations(QDomElement rootTable);

    void loadVehicleTypes(QDomElement rootTable);

    void loadFlows(QDomElement rootTable);

    void loadEdgeTypes(QDomElement rootTable);

    void loadVehicles(QDomElement rootTable);

    void loadDetectors(QDomElement rootTable);

    void loadFlowMeasures(QDomElement rootTable);
};



#endif // NETEDITORDATABASE_H
