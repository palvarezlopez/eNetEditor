#include "eNetEditorProjectConfiguration.h"

// items configurations
#include "../items/nodeItemConfiguration.h"
#include "../items/edges/edgeItemConfiguration.h"
#include "../items/laneItemConfiguration.h"
#include "../items/connectionItemConfiguration.h"
#include "../items/prohibitionItemConfiguration.h"
#include "../items/trafficLightItemConfiguration.h"
#include "../items/routeItemConfiguration.h"
#include "../items/stops/busStopItemConfiguration.h"
#include "../items/stops/chargingStationItemConfiguration.h"
#include "../items/vehicleTypeItemConfiguration.h"
#include "../items/vehicles/vehicleItemConfiguration.h"
#include "../items/vehicles/flowItemConfiguration.h"
#include "../items/edges/edgeTypeItemConfiguration.h"
#include "../items/flowMeasureItemConfiguration.h"
#include "../items/distributionFunctionItemConfiguration.h"
#include "../items/detectors/inductionLoopsE1DetectorItemConfiguration.h"
#include "../items/detectors/laneAreaE2DetectorItemConfiguration.h"
#include "../items/detectors/multiEntryExitE3DetectorItemConfiguration.h"
#include "../items/turnRatios/turnRatioIntervalItemConfiguration.h"
#include "../items/turnRatios/turnRatioItemConfiguration.h"


eNetEditorProjectConfiguration::eNetEditorProjectConfiguration() : eNetEditorConfiguration()
{
    // Create itemConfiguration
    nodeItemC = new nodeItemConfiguration();
    edgeItemC = new edgeItemConfiguration();
    laneItemC = new laneItemConfiguration();
    connectionItemC = new connectionItemConfiguration();
    prohibitionItemC = new prohibitionItemConfiguration();
    trafficLightItemC = new trafficLightItemConfiguration();
    routeItemC = new routeItemConfiguration();
    busStopItemC = new busStopItemConfiguration();
    chargingStationItemC = new chargingStationItemConfiguration();
    vehicleTypeItemC = new vehicleTypeItemConfiguration();
    vehicleItemC = new vehicleItemConfiguration();
    flowItemC = new flowItemConfiguration();
    edgeTypeItemC = new edgeTypeItemConfiguration();
    flowMeasureItemC = new flowMeasureItemConfiguration();
    distributionFunctionItemC = new distributionFunctionItemConfiguration();
    inductionLoopsE1DetectorItemC = new inductionLoopsE1DetectorItemConfiguration();
    laneAreaE2DetectorItemC = new laneAreaE2DetectorItemConfiguration();
    multiEntryExitE3DetectorItemC = new multiEntryExitE3DetectorItemConfiguration();
    turnRatioIntervalItemC = new turnRatioIntervalItemConfiguration();
    turnRatioItemC = new turnRatioItemConfiguration();

    // Set default project file extension
    defaultProjectExtensionFile = ".eneprj";

    // Set default project file folder
    defaultProjectFolder = QCoreApplication::applicationDirPath() + "/projects";

    // Set default image altitude
    imageMapAltitude = 0;

    // Set default project name
    defaultProjectName = "project";

    // Set default duration
    defaultDuration = 100;

    // Set default name of TripInfo output
    defaultTripInfoOutputFile = "tripinfo.xml";

    // Set default name of Battery Output
    defaultBatteryOutputFile = "battery-output.xml";

    // Fill list of open Street Map Pixel meters
    vectorOfOpenStreetMapPixelMeter.push_back(156412.0);
    vectorOfOpenStreetMapPixelMeter.push_back(78206.0);
    vectorOfOpenStreetMapPixelMeter.push_back(39103.0);
    vectorOfOpenStreetMapPixelMeter.push_back(19551.0);
    vectorOfOpenStreetMapPixelMeter.push_back(9776.0);
    vectorOfOpenStreetMapPixelMeter.push_back(4888.0);
    vectorOfOpenStreetMapPixelMeter.push_back(2444.0);
    vectorOfOpenStreetMapPixelMeter.push_back(1222.0);
    vectorOfOpenStreetMapPixelMeter.push_back(610.984);
    vectorOfOpenStreetMapPixelMeter.push_back(305.492);
    vectorOfOpenStreetMapPixelMeter.push_back(152.746);
    vectorOfOpenStreetMapPixelMeter.push_back(76.373);
    vectorOfOpenStreetMapPixelMeter.push_back(38.187);
    vectorOfOpenStreetMapPixelMeter.push_back(19.093);
    vectorOfOpenStreetMapPixelMeter.push_back(9.547);
    vectorOfOpenStreetMapPixelMeter.push_back(4.773);
    vectorOfOpenStreetMapPixelMeter.push_back(2.387);
    vectorOfOpenStreetMapPixelMeter.push_back(1.193);
    vectorOfOpenStreetMapPixelMeter.push_back(0.596);
    vectorOfOpenStreetMapPixelMeter.push_back(0.298);

    // Fill list of Open Street Map Scales
    vectorOfOpenStreetMapScales.push_back("1:500000");
    vectorOfOpenStreetMapScales.push_back("1:250000");
    vectorOfOpenStreetMapScales.push_back("1:150000");
    vectorOfOpenStreetMapScales.push_back("1:70000");
    vectorOfOpenStreetMapScales.push_back("1:35000");
    vectorOfOpenStreetMapScales.push_back("1:15000");
    vectorOfOpenStreetMapScales.push_back("1:10000");
    vectorOfOpenStreetMapScales.push_back("1:4000");
    vectorOfOpenStreetMapScales.push_back("1:2000");
    vectorOfOpenStreetMapScales.push_back("1:1000");
    vectorOfOpenStreetMapScales.push_back("1:500");
    vectorOfOpenStreetMapScales.push_back("1:250");
    vectorOfOpenStreetMapScales.push_back("1:150");
    vectorOfOpenStreetMapScales.push_back("1:70");
    vectorOfOpenStreetMapScales.push_back("1:35");
    vectorOfOpenStreetMapScales.push_back("1:15");
    vectorOfOpenStreetMapScales.push_back("1:8");
    vectorOfOpenStreetMapScales.push_back("1:4");
    vectorOfOpenStreetMapScales.push_back("1:2");
    vectorOfOpenStreetMapScales.push_back("1:1");

    // Fill list of Open Street Degrees
    vectorOfOpenStreetMapDegrees.push_back(360.0);
    vectorOfOpenStreetMapDegrees.push_back(180.0);
    vectorOfOpenStreetMapDegrees.push_back(90.0);
    vectorOfOpenStreetMapDegrees.push_back(45.0);
    vectorOfOpenStreetMapDegrees.push_back(22.5);
    vectorOfOpenStreetMapDegrees.push_back(11.25);
    vectorOfOpenStreetMapDegrees.push_back(5.625);
    vectorOfOpenStreetMapDegrees.push_back(2.813);
    vectorOfOpenStreetMapDegrees.push_back(1.406);
    vectorOfOpenStreetMapDegrees.push_back(0.703);
    vectorOfOpenStreetMapDegrees.push_back(0.352);
    vectorOfOpenStreetMapDegrees.push_back(0.176);
    vectorOfOpenStreetMapDegrees.push_back(0.088);
    vectorOfOpenStreetMapDegrees.push_back(0.044);
    vectorOfOpenStreetMapDegrees.push_back(0.022);
    vectorOfOpenStreetMapDegrees.push_back(0.011);
    vectorOfOpenStreetMapDegrees.push_back(0.005);
    vectorOfOpenStreetMapDegrees.push_back(0.003);
    vectorOfOpenStreetMapDegrees.push_back(0.001);
    vectorOfOpenStreetMapDegrees.push_back(0.0005);

}

eNetEditorProjectConfiguration::~eNetEditorProjectConfiguration()
{
    // Delete ItemsConfig
    delete nodeItemC;
    delete edgeItemC;
    delete laneItemC;
    delete connectionItemC;
    delete prohibitionItemC;
    delete trafficLightItemC;
    delete routeItemC;
    delete busStopItemC;
    delete chargingStationItemC;
    delete vehicleTypeItemC;
    delete vehicleItemC;
    delete flowItemC;
    delete edgeTypeItemC;
    delete flowMeasureItemC;
    delete distributionFunctionItemC;
    delete inductionLoopsE1DetectorItemC;
    delete laneAreaE2DetectorItemC;
    delete multiEntryExitE3DetectorItemC;
    delete turnRatioItemC;
}

nodeItemConfiguration *eNetEditorProjectConfiguration::getNodeItemConfiguration() const
{
    return nodeItemC;
}

edgeItemConfiguration *eNetEditorProjectConfiguration::getEdgeItemConfiguration() const
{
    return edgeItemC;
}

laneItemConfiguration *eNetEditorProjectConfiguration::getLaneItemConfiguration() const
{
    return laneItemC;
}

connectionItemConfiguration *eNetEditorProjectConfiguration::getConnectionItemConfiguration() const
{
    return connectionItemC;
}

prohibitionItemConfiguration *eNetEditorProjectConfiguration::getProhibitionItemConfiguration() const
{
    return prohibitionItemC;
}

trafficLightItemConfiguration *eNetEditorProjectConfiguration::getTrafficLightItemConfiguration() const
{
    return trafficLightItemC;
}

routeItemConfiguration *eNetEditorProjectConfiguration::getRouteItemConfiguration() const
{
    return routeItemC;
}

busStopItemConfiguration *eNetEditorProjectConfiguration::getBusStopItemConfiguration() const
{
    return busStopItemC;
}

chargingStationItemConfiguration *eNetEditorProjectConfiguration::getChargingStationItemConfiguration() const
{
    return chargingStationItemC;
}

vehicleTypeItemConfiguration *eNetEditorProjectConfiguration::getVehicleTypeItemConfiguration() const
{
    return vehicleTypeItemC;
}

vehicleItemConfiguration *eNetEditorProjectConfiguration::getVehicleItemConfiguration() const
{
    return vehicleItemC;
}

flowItemConfiguration *eNetEditorProjectConfiguration::getFlowItemConfiguration() const
{
    return flowItemC;
}

edgeTypeItemConfiguration *eNetEditorProjectConfiguration::getEdgeTypeItemConfiguration() const
{
    return edgeTypeItemC;
}

flowMeasureItemConfiguration *eNetEditorProjectConfiguration::getFlowMeasureItemConfiguration() const
{
    return flowMeasureItemC;
}

distributionFunctionItemConfiguration *eNetEditorProjectConfiguration::getDistributionFunctionItemConfiguration() const
{
    return distributionFunctionItemC;
}

inductionLoopsE1DetectorItemConfiguration *eNetEditorProjectConfiguration::getInductionLoopsE1DetectorItemConfiguration() const
{
    return inductionLoopsE1DetectorItemC;
}

laneAreaE2DetectorItemConfiguration *eNetEditorProjectConfiguration::getLaneAreaE2DetectorItemConfiguration() const
{
    return laneAreaE2DetectorItemC;
}

multiEntryExitE3DetectorItemConfiguration *eNetEditorProjectConfiguration::getMultiEntryExitE3DetectorItemConfiguration() const
{
    return multiEntryExitE3DetectorItemC;
}

turnRatioIntervalItemConfiguration *eNetEditorProjectConfiguration::getTurnRatioIntervalItemConfiguration() const
{
    return turnRatioIntervalItemC;
}

turnRatioItemConfiguration *eNetEditorProjectConfiguration::getTurnRatioItemConfiguration() const
{
    return turnRatioItemC;
}

const QString &eNetEditorProjectConfiguration::getDefaultProjectExtensionFile() const
{
    return defaultProjectExtensionFile;
}

const QString &eNetEditorProjectConfiguration::getDefaultProjectName() const
{
    return defaultProjectName;
}

const QString &eNetEditorProjectConfiguration::getDefaultProjectFolder() const
{
    return defaultProjectFolder;
}

qreal eNetEditorProjectConfiguration::getImageMapAltitude() const
{
    return imageMapAltitude;
}

int eNetEditorProjectConfiguration::getDefaultDuration() const
{
    return defaultDuration;
}

const QString &eNetEditorProjectConfiguration::getDefaultTripInfoOutputFile() const
{
    return defaultTripInfoOutputFile;
}

const QString &eNetEditorProjectConfiguration::getDefaultBatteryOutputFile() const
{
    return defaultBatteryOutputFile;
}

void eNetEditorProjectConfiguration::setDefaultProjectName(const QString &newDefaultProjectName)
{
    defaultProjectName = newDefaultProjectName;
}

void eNetEditorProjectConfiguration::setDefaultDuration(int newDefaultDuration)
{
    defaultDuration = newDefaultDuration;
}

qreal eNetEditorProjectConfiguration::getOpenStreetMapPixelMeterValue(const openStreetMapPixelMeter &index) const
{
    return vectorOfOpenStreetMapPixelMeter.at(index);
}

const QString &eNetEditorProjectConfiguration::getOpenStreetMapScaleValue(const openStreetMapScale &index) const
{
    return vectorOfOpenStreetMapScales.at(index);
}

qreal eNetEditorProjectConfiguration::getOpenStreetMapDegreeValue(const openStreetMapDegree &index) const
{
    return vectorOfOpenStreetMapDegrees.at(index);
}
