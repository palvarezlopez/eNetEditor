#ifndef ENETEDITORPROJECTCONFIGURATION_H
#define ENETEDITORPROJECTCONFIGURATION_H

#include "../eNetEditorConfiguration.h"



// Enum Open Street Map Pixel/Meters
enum openStreetMapPixelMeter
{
    openStreetMapPixelMeter00,
    openStreetMapPixelMeter01,
    openStreetMapPixelMeter02,
    openStreetMapPixelMeter03,
    openStreetMapPixelMeter04,
    openStreetMapPixelMeter05,
    openStreetMapPixelMeter06,
    openStreetMapPixelMeter07,
    openStreetMapPixelMeter08,
    openStreetMapPixelMeter09,
    openStreetMapPixelMeter10,
    openStreetMapPixelMeter11,
    openStreetMapPixelMeter12,
    openStreetMapPixelMeter13,
    openStreetMapPixelMeter14,
    openStreetMapPixelMeter15,
    openStreetMapPixelMeter16,
    openStreetMapPixelMeter17,
    openStreetMapPixelMeter18,
    openStreetMapPixelMeter19
};

// Enum Open Street Map Scale
enum openStreetMapScale
{
    openStreetMapScale00,
    openStreetMapScale01,
    openStreetMapScale02,
    openStreetMapScale03,
    openStreetMapScale04,
    openStreetMapScale05,
    openStreetMapScale06,
    openStreetMapScale07,
    openStreetMapScale08,
    openStreetMapScale09,
    openStreetMapScale10,
    openStreetMapScale11,
    openStreetMapScale12,
    openStreetMapScale13,
    openStreetMapScale14,
    openStreetMapScale15,
    openStreetMapScale16,
    openStreetMapScale17,
    openStreetMapScale18,
    openStreetMapScale19
};

// Enum Open Street Map Degrees
enum openStreetMapDegree
{
    openStreetMapDegree00,
    openStreetMapDegree01,
    openStreetMapDegree02,
    openStreetMapDegree03,
    openStreetMapDegree04,
    openStreetMapDegree05,
    openStreetMapDegree06,
    openStreetMapDegree07,
    openStreetMapDegree08,
    openStreetMapDegree09,
    openStreetMapDegree10,
    openStreetMapDegree11,
    openStreetMapDegree12,
    openStreetMapDegree13,
    openStreetMapDegree14,
    openStreetMapDegree15,
    openStreetMapDegree16,
    openStreetMapDegree17,
    openStreetMapDegree18,
    openStreetMapDegree19
};

class eNetEditorProjectConfiguration : public eNetEditorConfiguration
{
public:

    eNetEditorProjectConfiguration();

    ~eNetEditorProjectConfiguration();


    // GET FUNCTIONS

    nodeItemConfiguration *getNodeItemConfiguration() const;

    edgeItemConfiguration *getEdgeItemConfiguration() const;

    laneItemConfiguration *getLaneItemConfiguration() const;

    connectionItemConfiguration *getConnectionItemConfiguration() const;

    prohibitionItemConfiguration *getProhibitionItemConfiguration() const;

    trafficLightItemConfiguration *getTrafficLightItemConfiguration() const;

    routeItemConfiguration *getRouteItemConfiguration() const;

    busStopItemConfiguration *getBusStopItemConfiguration() const;

    chargingStationItemConfiguration *getChargingStationItemConfiguration() const;

    vehicleTypeItemConfiguration *getVehicleTypeItemConfiguration() const;

    vehicleItemConfiguration *getVehicleItemConfiguration() const;

    flowItemConfiguration *getFlowItemConfiguration() const;

    edgeTypeItemConfiguration *getEdgeTypeItemConfiguration() const;

    flowMeasureItemConfiguration *getFlowMeasureItemConfiguration() const;

    distributionFunctionItemConfiguration *getDistributionFunctionItemConfiguration() const;

    inductionLoopsE1DetectorItemConfiguration *getInductionLoopsE1DetectorItemConfiguration() const;

    laneAreaE2DetectorItemConfiguration *getLaneAreaE2DetectorItemConfiguration() const;

    multiEntryExitE3DetectorItemConfiguration *getMultiEntryExitE3DetectorItemConfiguration() const;

    turnRatioIntervalItemConfiguration *getTurnRatioIntervalItemConfiguration() const;

    turnRatioItemConfiguration *getTurnRatioItemConfiguration() const;

    const QString &getDefaultProjectExtensionFile() const;

    const QString &getDefaultProjectName() const;

    const QString &getDefaultProjectFolder() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getImageMapAltitude() const;

    int getDefaultDuration() const;

    const QString &getDefaultTripInfoOutputFile() const;

    const QString &getDefaultBatteryOutputFile() const;


    // SET FUNCTIONS

    void setDefaultProjectName(const QString &newDefaultProjectName);

    void setDefaultDuration(int newDefaultDuration);

    qreal getOpenStreetMapPixelMeterValue(const openStreetMapPixelMeter &index) const;

    const QString &getOpenStreetMapScaleValue(const openStreetMapScale &index) const;

    qreal getOpenStreetMapDegreeValue(const openStreetMapDegree &index) const;


private:

    // Declare items configuration
    nodeItemConfiguration *nodeItemC;
    edgeItemConfiguration *edgeItemC;
    laneItemConfiguration *laneItemC;
    connectionItemConfiguration *connectionItemC;
    prohibitionItemConfiguration *prohibitionItemC;
    trafficLightItemConfiguration *trafficLightItemC;
    routeItemConfiguration *routeItemC;
    busStopItemConfiguration *busStopItemC;
    chargingStationItemConfiguration *chargingStationItemC;
    vehicleTypeItemConfiguration *vehicleTypeItemC;
    vehicleItemConfiguration *vehicleItemC;
    flowItemConfiguration *flowItemC;
    edgeTypeItemConfiguration *edgeTypeItemC;
    flowMeasureItemConfiguration *flowMeasureItemC;
    distributionFunctionItemConfiguration *distributionFunctionItemC;
    inductionLoopsE1DetectorItemConfiguration *inductionLoopsE1DetectorItemC;
    laneAreaE2DetectorItemConfiguration *laneAreaE2DetectorItemC;
    multiEntryExitE3DetectorItemConfiguration *multiEntryExitE3DetectorItemC;
    turnRatioIntervalItemConfiguration *turnRatioIntervalItemC;
    turnRatioItemConfiguration *turnRatioItemC;

    // Default project extension File
    QString defaultProjectExtensionFile;

    // Default project name
    QString defaultProjectName;

    // Default project folder
    QString defaultProjectFolder;

    // Items altitude
    qreal imageMapAltitude;

    // Default duration of simulation
    int defaultDuration;



    // Default name of TripInfo output
    QString defaultTripInfoOutputFile;

    // Default name of Battery Output
    QString defaultBatteryOutputFile;

    // List of Open Street Map Pixel Meters
    QVector<qreal> vectorOfOpenStreetMapPixelMeter;

    // List of Open Street Map Scales
    QVector<QString> vectorOfOpenStreetMapScales;

    // List of Open Street Map Degrees
    QVector<qreal> vectorOfOpenStreetMapDegrees;

};

#endif // ENETEDITORPROJECTCONFIGURATION_H
