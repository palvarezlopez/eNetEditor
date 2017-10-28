#include "netConvertToolConfiguration.h"

netConvertToolConfiguration::netConvertToolConfiguration() : eNetEditorToolConfiguration(17, 11, 127)
{
    setOutputfolder("netConvert");

    netConvertDefaultSumoNetFile = "net";

    netConvertDefaultNodeFiles = "nodes";

    netConvertDefaultEdgeFiles = "edges";

    netConvertDefaultConnectionFiles = "connections";

    netConvertDefaultTllogicFiles = "trafficLights";

    netConvertDefaultTypeFiles = "types";

    netConvertDefaultShapefilePrefix = "shapes";

    netConvertDefaultDlrNavteqPrefix = "txt";

    netConvertDefaultOsmFiles = "osm";

    netConvertDefaultOpendriveFiles = "openDrive";

    netConvertDefaultVisumFile = "visum";

    netConvertDefaultVissimFile = "vissim";

    netConvertDefaultRobocupDir = "robocup";

    netConvertDefaultMatsimFiles = "matSim";

    netConvertDefaultItsumoFiles = "itSumo";

    netConvertDefaultHeightmapShapefiles = "heightmapShape";

    netConvertDefaultHeightmapGeotiff = "HeightmapGeotiff";

    netConvertDefaultOutputPrefix = "";

    netConvertDefaultOutputFile = "netConvert.net.xml";

    netConvertDefaultPlainOutputPrefix = "";

    netConvertDefaultJunctionsJoinOutput = "netConvert.junctions";

    netConvertDefaultAmitranOutput = "netConvert.Amitran";

    netConvertDefaultMatsimOutput = "netConvert.matSim";

    netConvertDefaultOpendriveOutput = "netConvert.openDrive";

    netConvertDefaultDlrNavteqOutput = "netConvert.dlrNavteq";

    netConvertDefaultOutputStreetNames = false;

    netConvertDefaultOutputOriginalNames = false;

    netConvertDefaultStreetSignOutput = "netConvert.streetSign";

    netConvertDefaultSimpleProjection = false;

    netConvertDefaultProjScale = 0;

    netConvertDefaultProjUtm = false;

    netConvertDefaultProjDhdn = false;

    netConvertDefaultProj = "!";

    netConvertDefaultProjInverse = false;

    netConvertDefaultProjDhdnutm = false;

    netConvertDefaultProjPlainGeo = false;

    netConvertDefaultTlsDiscardLoaded = false;

    netConvertDefaultTlsDiscardSimple = false;

    netConvertDefaultTlsGuess = false;

    netConvertDefaultTlsTazNodes = false;

    netConvertDefaultTlsGuessJoining = false;

    netConvertDefaultTlsJoin = false;

    netConvertDefaultTlsGreenTime = 31;

    netConvertDefaultTlsYellowMinDecel = 3;

    netConvertDefaultTlsYellowPatchSmall = false;

    netConvertDefaultTlsYellowTime = 0; /** Warning: In the NETGENERATOR webseit this variable don't have a default value **/

    netConvertDefaultTlsHalfOffset;

    netConvertDefaultTlsQuarterOffset;

    netConvertDefaultTlsDefaultType = "static";

    netConvertDefaultRampsGuess = false;

    netConvertDefaultRampsMaxRampSpeed = -1;

    netConvertDefaultRampsMinHighwaySpeed = 21.9444;

    netConvertDefaultRampsRampLength = 100;

    netConvertDefaultRampsNoSplit = false;

    netConvertDefaultKeepEdgesPostload = false;

    netConvertDefaultRemoveEdgesIsolated = false;

    netConvertDefaultKeepNodesUnregulated = false;

    netConvertDefaultKeepNodesUnregulatedDistrictNodes = false;

    netConvertDefaultIgnoreErrors = false;

    netConvertDefaultIgnoreErrorsConnections = false;

    netConvertDefaultShowErrorsConnectionsFirstTry = false;

    netConvertDefaultIgnoreErrorsEdgeType = false;

    netConvertDefaultLanesFromCapacityNorm = 1800;

    netConvertDefaultSpeedInKmh = false;

    netConvertDefaultPlainExtendEdgeShape = false;

    netConvertDefaultMatsimKeepLength = false;

    netConvertDefaultMatsimLanesFromCapacity = false;

    netConvertDefaultShapefileUseDefaultsOnFailure = false;

    netConvertDefaultShapefileAllBidirectional = false;

    netConvertDefaultShapefileGuessProjection = false;

    netConvertDefaultVissimJoinDistance = 5;

    netConvertDefaultVissimDefaultSpeed = 50;

    netConvertDefaultVissimSpeedNorm = 1;

    netConvertDefaultVissimReportUnsetSpeeds = false;

    netConvertDefaultVisumUseTypePriority = false;

    netConvertDefaultVisumUseTypeLaneno = false;

    netConvertDefaultVisumUseTypeSpeed = false;

    netConvertDefaultVisumConnectorSpeeds = 100;

    netConvertDefaultVisumConnectorsLaneNumber = 3;

    netConvertDefaultVisumNoConnectors = false;

    netConvertDefaultVisumRecomputeLaneNumber = false;

    netConvertDefaultVisumVerboseWarnings = false;

    netConvertDefaultOsmSkipDuplicatesCheck = false;

    netConvertDefaultOsmRailwayOnewayDefault = true;

    netConvertDefaultOsmElevation = false;

    netConvertDefaultOpendriveImportAllLanes = false;

    netConvertDefaultOpendriveIgnoreWidths = false;

    netConvertDefaultNoInternalLinks = false;

    netConvertDefaultDismissVclasses = false;

    netConvertDefaultNoTurnarounds = false;

    netConvertDefaultNoTurnaroundsTls = false;

    netConvertDefaultNoLeftConnections = false;

    netConvertDefaultGeometrySplit = false;

    netConvertDefaultGeometryRemove = false;

    netConvertDefaultGeometryMaxSegmentLength = 0;

    netConvertDefaultGeometryMinDist = 0; /** I'm not sure, if this is the default value **/

    netConvertDefaultGeometryMaxAngle = 99;

    netConvertDefaultGeometryMinRadius = 9;

    netConvertDefaultGeometryMinRadiusFix = false;

    netConvertDefaultGeometryJunctionMismatchThreshold = 20;

    netConvertDefaultOffsetDisableNormalization = false;

    netConvertDefaultOffsetX = 0;

    netConvertDefaultOffsetY = 0;

    netConvertDefaultFlipYAxis = false;

    netConvertDefaultRoundaboutsGuess = false;

    netConvertDefaultLefthand = false;

    netConvertDefaultJunctionsJoin = false;

    netConvertDefaultJunctionsJoinDist = 10;

    netConvertDefaultSpeedOffset = 0;

    netConvertDefaultSpeedFactor = 1;

    netConvertDefaultJunctionsCornerDetail = 0;

    netConvertDefaultCheckLaneFoesRoundabout = true;

    netConvertDefaultCheckLaneFoesAll = false;

    netConvertDefaultSidewalksGuess = false;

    netConvertDefaultSidewalksGuessMaxSpeed = 13.89;

    netConvertDefaultSidewalksGuessMinSpeed = 5.8;

    netConvertDefaultSidewalksGuessFromPermissions = false;

    netConvertDefaultCrossingsGuess = false;

    netConvertDefaultTlsJoinDist = 20;

    netConvertDefaultTlsGuessSignals = false;

    netConvertDefaultTlsGuessSignalsDist = 25;

    netConvertDefaultDefaultLanenumber = 1;

    netConvertDefaultDefaultSpeed = 13.9;

    netConvertDefaultDefaultPriority = -1;

    netConvertDefaultDefaultSidewalkWidth = 2;

    netConvertDefaultVerbose = false;

    netConvertDefaultPrintOptions = false;

    netConvertDefaultHelp = false;

    netConvertDefaultVersion = false;

    netConvertDefaultxmlValidation = "auto";

    netConvertDefaultNoWarnings = false;

    netConvertDefaultLog = "netConvert.log";

    netConvertDefaultMessageLog = "netConvert.messageLog";

    netConvertDefaultErrorLog = "netConvert.errorLog";

    netConvertDefaultRandom = false;

    netConvertDefaultSeed = 23423;
}

netConvertToolConfiguration::~netConvertToolConfiguration()
{
    // Nothing to erase
}

const QString &netConvertToolConfiguration::getNetConvertDefaultSumoNetFile() const
{
    return netConvertDefaultSumoNetFile;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultNodeFiles() const
{
    return netConvertDefaultNodeFiles;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultEdgeFiles() const
{
    return netConvertDefaultEdgeFiles;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultConnectionFiles() const
{
    return netConvertDefaultConnectionFiles;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultTllogicFiles() const
{
    return netConvertDefaultTllogicFiles;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultTypeFiles() const
{
    return netConvertDefaultTypeFiles;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultShapefilePrefix() const
{
    return netConvertDefaultShapefilePrefix;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultDlrNavteqPrefix() const
{
    return netConvertDefaultDlrNavteqPrefix;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultOsmFiles() const
{
    return netConvertDefaultOsmFiles;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultOpendriveFiles() const
{
    return netConvertDefaultOpendriveFiles;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultVisumFile() const
{
    return netConvertDefaultVisumFile;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultVissimFile() const
{
    return netConvertDefaultVissimFile;
}


const QString &netConvertToolConfiguration::getNetConvertDefaultRobocupDir() const
{
    return netConvertDefaultRobocupDir;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultMatsimFiles() const
{
    return netConvertDefaultMatsimFiles;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultItsumoFiles() const
{
    return netConvertDefaultItsumoFiles;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultHeightmapShapefiles() const
{
    return netConvertDefaultHeightmapShapefiles;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultHeightmapGeotiff() const
{
    return netConvertDefaultHeightmapGeotiff;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultOutputPrefix() const
{
    return netConvertDefaultOutputPrefix;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultOutputFile() const
{
    return netConvertDefaultOutputFile;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultPlainOutputPrefix() const
{
    return netConvertDefaultPlainOutputPrefix;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultJunctionsJoinOutput() const
{
    return netConvertDefaultJunctionsJoinOutput;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultAmitranOutput() const
{
    return netConvertDefaultAmitranOutput;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultMatsimOutput() const
{
    return netConvertDefaultMatsimOutput;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultOpendriveOutput() const
{
    return netConvertDefaultOpendriveOutput;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultDlrNavteqOutput() const
{
    return netConvertDefaultDlrNavteqOutput;
}

bool netConvertToolConfiguration::getNetConvertDefaultOutputStreetNames() const
{
    return netConvertDefaultOutputStreetNames;
}

bool netConvertToolConfiguration::getNetConvertDefaultOutputOriginalNames() const
{
    return netConvertDefaultOutputOriginalNames;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultStreetSignOutput() const
{
    return netConvertDefaultStreetSignOutput;
}

bool netConvertToolConfiguration::getNetConvertDefaultSimpleProjection() const
{
    return netConvertDefaultSimpleProjection;
}

int netConvertToolConfiguration::getNetConvertDefaultProjScale() const
{
    return netConvertDefaultProjScale;
}

bool netConvertToolConfiguration::getNetConvertDefaultProjUtm() const
{
    return netConvertDefaultProjUtm;
}

bool netConvertToolConfiguration::getNetConvertDefaultProjDhdn() const
{
    return netConvertDefaultProjDhdn;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultProj() const
{
    return netConvertDefaultProj;
}

bool netConvertToolConfiguration::getNetConvertDefaultProjInverse() const
{
    return netConvertDefaultProjInverse;
}

bool netConvertToolConfiguration::getNetConvertDefaultProjDhdnutm() const
{
    return netConvertDefaultProjDhdnutm;
}

bool netConvertToolConfiguration::getNetConvertDefaultProjPlainGeo() const
{
    return netConvertDefaultProjPlainGeo;
}

bool netConvertToolConfiguration::getNetConvertDefaultTlsDiscardLoaded() const
{
    return netConvertDefaultTlsDiscardLoaded;
}

bool netConvertToolConfiguration::getNetConvertDefaultTlsDiscardSimple() const
{
    return netConvertDefaultTlsDiscardSimple;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultTlsSet() const
{
    return netConvertDefaultTlsSet;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultTlsUnset() const
{
    return netConvertDefaultTlsUnset;
}

bool netConvertToolConfiguration::getNetConvertDefaultTlsGuess() const
{
    return netConvertDefaultTlsGuess;
}

bool netConvertToolConfiguration::getNetConvertDefaultTlsTazNodes() const
{
    return netConvertDefaultTlsTazNodes;
}

bool netConvertToolConfiguration::getNetConvertDefaultTlsGuessJoining() const
{
    return netConvertDefaultTlsGuessJoining;
}

bool netConvertToolConfiguration::getNetConvertDefaultTlsJoin() const
{
    return netConvertDefaultTlsJoin;
}

int netConvertToolConfiguration::getNetConvertDefaultTlsGreenTime() const
{
    return netConvertDefaultTlsGreenTime;
}

qreal netConvertToolConfiguration::getNetConvertDefaultTlsYellowMinDecel() const
{
    return netConvertDefaultTlsYellowMinDecel;
}

bool netConvertToolConfiguration::getNetConvertDefaultTlsYellowPatchSmall() const
{
    return netConvertDefaultTlsYellowPatchSmall;
}

int netConvertToolConfiguration::getNetConvertDefaultTlsYellowTime() const
{
    return netConvertDefaultTlsYellowTime;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultTlsHalfOffset() const
{
    return netConvertDefaultTlsHalfOffset;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultTlsQuarterOffset() const
{
    return netConvertDefaultTlsQuarterOffset;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultTlsDefaultType() const
{
    return netConvertDefaultTlsDefaultType;
}

bool netConvertToolConfiguration::getNetConvertDefaultRampsGuess() const
{
    return netConvertDefaultRampsGuess;
}

qreal netConvertToolConfiguration::getNetConvertDefaultRampsMaxRampSpeed() const
{
    return netConvertDefaultRampsMaxRampSpeed;
}

qreal netConvertToolConfiguration::getNetConvertDefaultRampsMinHighwaySpeed() const
{
    return netConvertDefaultRampsMinHighwaySpeed;
}

qreal netConvertToolConfiguration::getNetConvertDefaultRampsRampLength() const
{
    return netConvertDefaultRampsRampLength;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultRampsSet() const
{
    return netConvertDefaultRampsSet;
}

bool netConvertToolConfiguration::getNetConvertDefaultRampsNoSplit() const
{
    return netConvertDefaultRampsNoSplit;
}

qreal netConvertToolConfiguration::getNetConvertDefaultKeepEdgesMinSpeed() const
{
    return netConvertDefaultKeepEdgesMinSpeed;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultRemoveEdgesExplicit() const
{
    return netConvertDefaultRemoveEdgesExplicit;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultKeepEdgesExplicit() const
{
    return netConvertDefaultKeepEdgesExplicit;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultKeepEdgesInputFile() const
{
    return netConvertDefaultKeepEdgesInputFile;
}

bool netConvertToolConfiguration::getNetConvertDefaultKeepEdgesPostload() const
{
    return netConvertDefaultKeepEdgesPostload;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultKeepEdgesInBoundary() const
{
    return netConvertDefaultKeepEdgesInBoundary;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultKeepEdgesInGeoBoundary() const
{
    return netConvertDefaultKeepEdgesInGeoBoundary;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultKeepEdgesByVclass() const
{
    return netConvertDefaultKeepEdgesByVclass;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultRemoveEdgesByVclass() const
{
    return netConvertDefaultRemoveEdgesByVclass;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultKeepEdgesByType() const
{
    return netConvertDefaultKeepEdgesByType;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultRemoveEdgesByType() const
{
    return netConvertDefaultRemoveEdgesByType;
}

bool netConvertToolConfiguration::getNetConvertDefaultRemoveEdgesIsolated() const
{
    return netConvertDefaultRemoveEdgesIsolated;
}

bool netConvertToolConfiguration::getNetConvertDefaultKeepNodesUnregulated() const
{
    return netConvertDefaultKeepNodesUnregulated;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultKeepNodesUnregulatedExplicit() const
{
    return netConvertDefaultKeepNodesUnregulatedExplicit;
}

bool netConvertToolConfiguration::getNetConvertDefaultKeepNodesUnregulatedDistrictNodes() const
{
    return netConvertDefaultKeepNodesUnregulatedDistrictNodes;
}

bool netConvertToolConfiguration::getNetConvertDefaultIgnoreErrors() const
{
    return netConvertDefaultIgnoreErrors;
}

bool netConvertToolConfiguration::getNetConvertDefaultIgnoreErrorsConnections() const
{
    return netConvertDefaultIgnoreErrorsConnections;
}

bool netConvertToolConfiguration::getNetConvertDefaultShowErrorsConnectionsFirstTry() const
{
    return netConvertDefaultShowErrorsConnectionsFirstTry;
}

bool netConvertToolConfiguration::getNetConvertDefaultIgnoreErrorsEdgeType() const
{
    return netConvertDefaultIgnoreErrorsEdgeType;
}

qreal netConvertToolConfiguration::getNetConvertDefaultLanesFromCapacityNorm() const
{
    return netConvertDefaultLanesFromCapacityNorm;
}

bool netConvertToolConfiguration::getNetConvertDefaultSpeedInKmh() const
{
    return netConvertDefaultSpeedInKmh;
}

bool netConvertToolConfiguration::getNetConvertDefaultPlainExtendEdgeShape() const
{
    return netConvertDefaultPlainExtendEdgeShape;
}

bool netConvertToolConfiguration::getNetConvertDefaultMatsimKeepLength() const
{
    return netConvertDefaultMatsimKeepLength;
}

bool netConvertToolConfiguration::getNetConvertDefaultMatsimLanesFromCapacity() const
{
    return netConvertDefaultMatsimLanesFromCapacity;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultShapefileStreetId() const
{
    return netConvertDefaultShapefileStreetId;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultShapefileFromId() const
{
    return netConvertDefaultShapefileFromId;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultShapefileToId() const
{
    return netConvertDefaultShapefileToId;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultShapefileTypeId() const
{
    return netConvertDefaultShapefileTypeId;
}

bool netConvertToolConfiguration::getNetConvertDefaultShapefileUseDefaultsOnFailure() const
{
    return netConvertDefaultShapefileUseDefaultsOnFailure;
}

bool netConvertToolConfiguration::getNetConvertDefaultShapefileAllBidirectional() const
{
    return netConvertDefaultShapefileAllBidirectional;
}

bool netConvertToolConfiguration::getNetConvertDefaultShapefileGuessProjection() const
{
    return netConvertDefaultShapefileGuessProjection;
}

qreal netConvertToolConfiguration::getNetConvertDefaultVissimJoinDistance() const
{
    return netConvertDefaultVissimJoinDistance;
}

qreal netConvertToolConfiguration::getNetConvertDefaultVissimDefaultSpeed() const
{
    return netConvertDefaultVissimDefaultSpeed;
}

qreal netConvertToolConfiguration::getNetConvertDefaultVissimSpeedNorm() const
{
    return netConvertDefaultVissimSpeedNorm;
}

bool netConvertToolConfiguration::getNetConvertDefaultVissimReportUnsetSpeeds() const
{
    return netConvertDefaultVissimReportUnsetSpeeds;
}

bool netConvertToolConfiguration::getNetConvertDefaultVisumUseTypePriority() const
{
    return netConvertDefaultVisumUseTypePriority;
}

bool netConvertToolConfiguration::getNetConvertDefaultVisumUseTypeLaneno() const
{
    return netConvertDefaultVisumUseTypeLaneno;
}

bool netConvertToolConfiguration::getNetConvertDefaultVisumUseTypeSpeed() const
{
    return netConvertDefaultVisumUseTypeSpeed;
}

qreal netConvertToolConfiguration::getNetConvertDefaultVisumConnectorSpeeds() const
{
    return netConvertDefaultVisumConnectorSpeeds;
}

int netConvertToolConfiguration::getNetConvertDefaultVisumConnectorsLaneNumber() const
{
    return netConvertDefaultVisumConnectorsLaneNumber;
}

bool netConvertToolConfiguration::getNetConvertDefaultVisumNoConnectors() const
{
    return netConvertDefaultVisumNoConnectors;
}

bool netConvertToolConfiguration::getNetConvertDefaultVisumRecomputeLaneNumber() const
{
    return netConvertDefaultVisumRecomputeLaneNumber;
}

bool netConvertToolConfiguration::getNetConvertDefaultVisumVerboseWarnings() const
{
    return netConvertDefaultVisumVerboseWarnings;
}

bool netConvertToolConfiguration::getNetConvertDefaultOsmSkipDuplicatesCheck() const
{
    return netConvertDefaultOsmSkipDuplicatesCheck;
}

bool netConvertToolConfiguration::getNetConvertDefaultOsmRailwayOnewayDefault() const
{
    return netConvertDefaultOsmRailwayOnewayDefault;
}

bool netConvertToolConfiguration::getNetConvertDefaultOsmElevation() const
{
    return netConvertDefaultOsmElevation;
}

bool netConvertToolConfiguration::getNetConvertDefaultOpendriveImportAllLanes() const
{
    return netConvertDefaultOpendriveImportAllLanes;
}

bool netConvertToolConfiguration::getNetConvertDefaultOpendriveIgnoreWidths() const
{
    return netConvertDefaultOpendriveIgnoreWidths;
}

bool netConvertToolConfiguration::getNetConvertDefaultNoInternalLinks() const
{
    return netConvertDefaultNoInternalLinks;
}

bool netConvertToolConfiguration::getNetConvertDefaultDismissVclasses() const
{
    return netConvertDefaultDismissVclasses;
}

bool netConvertToolConfiguration::getNetConvertDefaultNoTurnarounds() const
{
    return netConvertDefaultNoTurnarounds;
}

bool netConvertToolConfiguration::getNetConvertDefaultNoTurnaroundsTls() const
{
    return netConvertDefaultNoTurnaroundsTls;
}

bool netConvertToolConfiguration::getNetConvertDefaultNoLeftConnections() const
{
    return netConvertDefaultNoLeftConnections;
}

bool netConvertToolConfiguration::getNetConvertDefaultGeometrySplit() const
{
    return netConvertDefaultGeometrySplit;
}

bool netConvertToolConfiguration::getNetConvertDefaultGeometryRemove() const
{
    return netConvertDefaultGeometryRemove;
}

qreal netConvertToolConfiguration::getNetConvertDefaultGeometryMaxSegmentLength() const
{
    return netConvertDefaultGeometryMaxSegmentLength;
}

qreal netConvertToolConfiguration::getNetConvertDefaultGeometryMinDist() const
{
    return netConvertDefaultGeometryMinDist;
}

qreal netConvertToolConfiguration::getNetConvertDefaultGeometryMaxAngle() const
{
    return netConvertDefaultGeometryMaxAngle;
}

qreal netConvertToolConfiguration::getNetConvertDefaultGeometryMinRadius() const
{
    return netConvertDefaultGeometryMinRadius;
}

bool netConvertToolConfiguration::getNetConvertDefaultGeometryMinRadiusFix() const
{
    return netConvertDefaultGeometryMinRadiusFix;
}

qreal netConvertToolConfiguration::getNetConvertDefaultGeometryJunctionMismatchThreshold() const
{
    return netConvertDefaultGeometryJunctionMismatchThreshold;
}

bool netConvertToolConfiguration::getNetConvertDefaultOffsetDisableNormalization() const
{
    return netConvertDefaultOffsetDisableNormalization;
}

qreal netConvertToolConfiguration::getNetConvertDefaultOffsetX() const
{
    return netConvertDefaultOffsetX;
}

qreal netConvertToolConfiguration::getNetConvertDefaultOffsetY() const
{
    return netConvertDefaultOffsetY;
}

bool netConvertToolConfiguration::getNetConvertDefaultFlipYAxis() const
{
    return netConvertDefaultFlipYAxis;
}

bool netConvertToolConfiguration::getNetConvertDefaultRoundaboutsGuess() const
{
    return netConvertDefaultRoundaboutsGuess;
}

bool netConvertToolConfiguration::getNetConvertDefaultLefthand() const
{
    return netConvertDefaultLefthand;
}

bool netConvertToolConfiguration::getNetConvertDefaultJunctionsJoin() const
{
    return netConvertDefaultJunctionsJoin;
}

qreal netConvertToolConfiguration::getNetConvertDefaultJunctionsJoinDist() const
{
    return netConvertDefaultJunctionsJoinDist;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultJunctionsJoinExclude() const
{
    return netConvertDefaultJunctionsJoinExclude;
}

qreal netConvertToolConfiguration::getNetConvertDefaultSpeedOffset() const
{
    return netConvertDefaultSpeedOffset;
}

qreal netConvertToolConfiguration::getNetConvertDefaultSpeedFactor() const
{
    return netConvertDefaultSpeedFactor;
}

int netConvertToolConfiguration::getNetConvertDefaultJunctionsCornerDetail() const
{
    return netConvertDefaultJunctionsCornerDetail;
}

bool netConvertToolConfiguration::getNetConvertDefaultCheckLaneFoesRoundabout() const
{
    return netConvertDefaultCheckLaneFoesRoundabout;
}

bool netConvertToolConfiguration::getNetConvertDefaultCheckLaneFoesAll() const
{
    return netConvertDefaultCheckLaneFoesAll;
}

bool netConvertToolConfiguration::getNetConvertDefaultSidewalksGuess() const
{
    return netConvertDefaultSidewalksGuess;
}

qreal netConvertToolConfiguration::getNetConvertDefaultSidewalksGuessMaxSpeed() const
{
    return netConvertDefaultSidewalksGuessMaxSpeed;
}

qreal netConvertToolConfiguration::getNetConvertDefaultSidewalksGuessMinSpeed() const
{
    return netConvertDefaultSidewalksGuessMinSpeed;
}

bool netConvertToolConfiguration::getNetConvertDefaultSidewalksGuessFromPermissions() const
{
    return netConvertDefaultSidewalksGuessFromPermissions;
}

bool netConvertToolConfiguration::getNetConvertDefaultCrossingsGuess() const
{
    return netConvertDefaultCrossingsGuess;
}

qreal netConvertToolConfiguration::getNetConvertDefaultTlsJoinDist() const
{
    return netConvertDefaultTlsJoinDist;
}

bool netConvertToolConfiguration::getNetConvertDefaultTlsGuessSignals() const
{
    return netConvertDefaultTlsGuessSignals;
}

qreal netConvertToolConfiguration::getNetConvertDefaultTlsGuessSignalsDist() const
{
    return netConvertDefaultTlsGuessSignalsDist;
}

int netConvertToolConfiguration::getNetConvertDefaultDefaultLanenumber() const
{
    return netConvertDefaultDefaultLanenumber;
}

qreal netConvertToolConfiguration::getNetConvertDefaultDefaultSpeed() const
{
    return netConvertDefaultDefaultSpeed;
}

int netConvertToolConfiguration::getNetConvertDefaultDefaultPriority() const
{
    return netConvertDefaultDefaultPriority;
}

qreal netConvertToolConfiguration::getNetConvertDefaultDefaultSidewalkWidth() const
{
    return netConvertDefaultDefaultSidewalkWidth;
}

bool netConvertToolConfiguration::getNetConvertDefaultVerbose() const
{
    return netConvertDefaultVerbose;
}

bool netConvertToolConfiguration::getNetConvertDefaultPrintOptions() const
{
    return netConvertDefaultPrintOptions;
}

bool netConvertToolConfiguration::getNetConvertDefaultHelp() const
{
    return netConvertDefaultHelp;
}

bool netConvertToolConfiguration::getNetConvertDefaultVersion() const
{
    return netConvertDefaultVersion;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultxmlValidation() const
{
    return netConvertDefaultxmlValidation;
}

bool netConvertToolConfiguration::getNetConvertDefaultNoWarnings() const
{
    return netConvertDefaultNoWarnings;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultLog() const
{
    return netConvertDefaultLog;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultMessageLog() const
{
    return netConvertDefaultMessageLog;
}

const QString &netConvertToolConfiguration::getNetConvertDefaultErrorLog() const
{
    return netConvertDefaultErrorLog;
}

bool netConvertToolConfiguration::getNetConvertDefaultRandom() const
{
    return netConvertDefaultRandom;
}

int netConvertToolConfiguration::getNetConvertDefaultSeed() const
{
    return netConvertDefaultSeed;
}
void netConvertToolConfiguration::setNetConvertDefaultSumoNetFile(const QString &value)
{
    netConvertDefaultSumoNetFile = value;
}

void netConvertToolConfiguration::setNetConvertDefaultNodeFiles(const QString &value)
{
    netConvertDefaultNodeFiles = value;
}

void netConvertToolConfiguration::setNetConvertDefaultEdgeFiles(const QString &value)
{
    netConvertDefaultEdgeFiles = value;
}

void netConvertToolConfiguration::setNetConvertDefaultConnectionFiles(const QString &value)
{
    netConvertDefaultConnectionFiles = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTllogicFiles(const QString &value)
{
    netConvertDefaultTllogicFiles = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTypeFiles(const QString &value)
{
    netConvertDefaultTypeFiles = value;
}

void netConvertToolConfiguration::setNetConvertDefaultShapefilePrefix(const QString &value)
{
    netConvertDefaultShapefilePrefix = value;
}

void netConvertToolConfiguration::setNetConvertDefaultDlrNavteqPrefix(const QString &value)
{
    netConvertDefaultDlrNavteqPrefix = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOsmFiles(const QString &value)
{
    netConvertDefaultOsmFiles = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOpendriveFiles(const QString &value)
{
    netConvertDefaultOpendriveFiles = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVisumFile(const QString &value)
{
    netConvertDefaultVisumFile = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVissimFile(const QString &value)
{
    netConvertDefaultVissimFile = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRobocupDir(const QString &value)
{
    netConvertDefaultRobocupDir = value;
}

void netConvertToolConfiguration::setNetConvertDefaultMatsimFiles(const QString &value)
{
    netConvertDefaultMatsimFiles = value;
}

void netConvertToolConfiguration::setNetConvertDefaultItsumoFiles(const QString &value)
{
    netConvertDefaultItsumoFiles = value;
}

void netConvertToolConfiguration::setNetConvertDefaultHeightmapShapefiles(const QString &value)
{
    netConvertDefaultHeightmapShapefiles = value;
}

void netConvertToolConfiguration::setNetConvertDefaultHeightmapGeotiff(const QString &value)
{
    netConvertDefaultHeightmapGeotiff = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOutputPrefix(const QString &value)
{
    netConvertDefaultOutputPrefix = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOutputFile(const QString &value)
{
    netConvertDefaultOutputFile = value;
}

void netConvertToolConfiguration::setNetConvertDefaultPlainOutputPrefix(const QString &value)
{
    netConvertDefaultPlainOutputPrefix = value;
}

void netConvertToolConfiguration::setNetConvertDefaultJunctionsJoinOutput(const QString &value)
{
    netConvertDefaultJunctionsJoinOutput = value;
}

void netConvertToolConfiguration::setNetConvertDefaultAmitranOutput(const QString &value)
{
    netConvertDefaultAmitranOutput = value;
}

void netConvertToolConfiguration::setNetConvertDefaultMatsimOutput(const QString &value)
{
    netConvertDefaultMatsimOutput = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOpendriveOutput(const QString &value)
{
    netConvertDefaultOpendriveOutput = value;
}

void netConvertToolConfiguration::setNetConvertDefaultDlrNavteqOutput(const QString &value)
{
    netConvertDefaultDlrNavteqOutput = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOutputStreetNames(bool value)
{
    netConvertDefaultOutputStreetNames = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOutputOriginalNames(bool value)
{
    netConvertDefaultOutputOriginalNames = value;
}

void netConvertToolConfiguration::setNetConvertDefaultStreetSignOutput(const QString &value)
{
    netConvertDefaultStreetSignOutput = value;
}

void netConvertToolConfiguration::setNetConvertDefaultSimpleProjection(bool value)
{
    netConvertDefaultSimpleProjection = value;
}

void netConvertToolConfiguration::setNetConvertDefaultProjScale(int value)
{
    netConvertDefaultProjScale = value;
}

void netConvertToolConfiguration::setNetConvertDefaultProjUtm(bool value)
{
    netConvertDefaultProjUtm = value;
}

void netConvertToolConfiguration::setNetConvertDefaultProjDhdn(bool value)
{
    netConvertDefaultProjDhdn = value;
}

void netConvertToolConfiguration::setNetConvertDefaultProj(const QString &value)
{
    netConvertDefaultProj = value;
}

void netConvertToolConfiguration::setNetConvertDefaultProjInverse(bool value)
{
    netConvertDefaultProjInverse = value;
}

void netConvertToolConfiguration::setNetConvertDefaultProjDhdnutm(bool value)
{
    netConvertDefaultProjDhdnutm = value;
}

void netConvertToolConfiguration::setNetConvertDefaultProjPlainGeo(bool value)
{
    netConvertDefaultProjPlainGeo = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsDiscardLoaded(bool value)
{
    netConvertDefaultTlsDiscardLoaded = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsDiscardSimple(bool value)
{
    netConvertDefaultTlsDiscardSimple = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsSet(const QString &value)
{
    netConvertDefaultTlsSet = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsUnset(const QString &value)
{
    netConvertDefaultTlsUnset = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsGuess(bool value)
{
    netConvertDefaultTlsGuess = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsTazNodes(bool value)
{
    netConvertDefaultTlsTazNodes = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsGuessJoining(bool value)
{
    netConvertDefaultTlsGuessJoining = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsJoin(bool value)
{
    netConvertDefaultTlsJoin = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsGreenTime(int value)
{
    netConvertDefaultTlsGreenTime = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsYellowMinDecel(qreal value)
{
    netConvertDefaultTlsYellowMinDecel = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsYellowPatchSmall(bool value)
{
    netConvertDefaultTlsYellowPatchSmall = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsYellowTime(int value)
{
    netConvertDefaultTlsYellowTime = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsHalfOffset(const QString &value)
{
    netConvertDefaultTlsHalfOffset = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsQuarterOffset(const QString &value)
{
    netConvertDefaultTlsQuarterOffset = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsDefaultType(const QString &value)
{
    netConvertDefaultTlsDefaultType = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRampsGuess(bool value)
{
    netConvertDefaultRampsGuess = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRampsMaxRampSpeed(qreal value)
{
    netConvertDefaultRampsMaxRampSpeed = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRampsMinHighwaySpeed(qreal value)
{
    netConvertDefaultRampsMinHighwaySpeed = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRampsRampLength(qreal value)
{
    netConvertDefaultRampsRampLength = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRampsSet(const QString &value)
{
    netConvertDefaultRampsSet = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRampsNoSplit(bool value)
{
    netConvertDefaultRampsNoSplit = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepEdgesMinSpeed(qreal value)
{
    netConvertDefaultKeepEdgesMinSpeed = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRemoveEdgesExplicit(const QString &value)
{
    netConvertDefaultRemoveEdgesExplicit = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepEdgesExplicit(const QString &value)
{
    netConvertDefaultKeepEdgesExplicit = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepEdgesInputFile(const QString &value)
{
    netConvertDefaultKeepEdgesInputFile = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepEdgesPostload(bool value)
{
    netConvertDefaultKeepEdgesPostload = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepEdgesInBoundary(const QString &value)
{
    netConvertDefaultKeepEdgesInBoundary = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepEdgesInGeoBoundary(const QString &value)
{
    netConvertDefaultKeepEdgesInGeoBoundary = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepEdgesByVclass(const QString &value)
{
    netConvertDefaultKeepEdgesByVclass = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRemoveEdgesByVclass(const QString &value)
{
    netConvertDefaultRemoveEdgesByVclass = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepEdgesByType(const QString &value)
{
    netConvertDefaultKeepEdgesByType = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRemoveEdgesByType(const QString &value)
{
    netConvertDefaultRemoveEdgesByType = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRemoveEdgesIsolated(bool value)
{
    netConvertDefaultRemoveEdgesIsolated = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepNodesUnregulated(bool value)
{
    netConvertDefaultKeepNodesUnregulated = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepNodesUnregulatedExplicit(const QString &value)
{
    netConvertDefaultKeepNodesUnregulatedExplicit = value;
}

void netConvertToolConfiguration::setNetConvertDefaultKeepNodesUnregulatedDistrictNodes(bool value)
{
    netConvertDefaultKeepNodesUnregulatedDistrictNodes = value;
}

void netConvertToolConfiguration::setNetConvertDefaultIgnoreErrors(bool value)
{
    netConvertDefaultIgnoreErrors = value;
}

void netConvertToolConfiguration::setNetConvertDefaultIgnoreErrorsConnections(bool value)
{
    netConvertDefaultIgnoreErrorsConnections = value;
}

void netConvertToolConfiguration::setNetConvertDefaultShowErrorsConnectionsFirstTry(bool value)
{
    netConvertDefaultShowErrorsConnectionsFirstTry = value;
}

void netConvertToolConfiguration::setNetConvertDefaultIgnoreErrorsEdgeType(bool value)
{
    netConvertDefaultIgnoreErrorsEdgeType = value;
}

void netConvertToolConfiguration::setNetConvertDefaultLanesFromCapacityNorm(qreal value)
{
    netConvertDefaultLanesFromCapacityNorm = value;
}

void netConvertToolConfiguration::setNetConvertDefaultSpeedInKmh(bool value)
{
    netConvertDefaultSpeedInKmh = value;
}

void netConvertToolConfiguration::setNetConvertDefaultPlainExtendEdgeShape(bool value)
{
    netConvertDefaultPlainExtendEdgeShape = value;
}

void netConvertToolConfiguration::setNetConvertDefaultMatsimKeepLength(bool value)
{
    netConvertDefaultMatsimKeepLength = value;
}

void netConvertToolConfiguration::setNetConvertDefaultMatsimLanesFromCapacity(bool value)
{
    netConvertDefaultMatsimLanesFromCapacity = value;
}

void netConvertToolConfiguration::setNetConvertDefaultShapefileStreetId(const QString &value)
{
    netConvertDefaultShapefileStreetId = value;
}

void netConvertToolConfiguration::setNetConvertDefaultShapefileFromId(const QString &value)
{
    netConvertDefaultShapefileFromId = value;
}

void netConvertToolConfiguration::setNetConvertDefaultShapefileToId(const QString &value)
{
    netConvertDefaultShapefileToId = value;
}

void netConvertToolConfiguration::setNetConvertDefaultShapefileTypeId(const QString &value)
{
    netConvertDefaultShapefileTypeId = value;
}

void netConvertToolConfiguration::setNetConvertDefaultShapefileUseDefaultsOnFailure(bool value)
{
    netConvertDefaultShapefileUseDefaultsOnFailure = value;
}

void netConvertToolConfiguration::setNetConvertDefaultShapefileAllBidirectional(bool value)
{
    netConvertDefaultShapefileAllBidirectional = value;
}

void netConvertToolConfiguration::setNetConvertDefaultShapefileGuessProjection(bool value)
{
    netConvertDefaultShapefileGuessProjection = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVissimJoinDistance(qreal value)
{
    netConvertDefaultVissimJoinDistance = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVissimDefaultSpeed(qreal value)
{
    netConvertDefaultVissimDefaultSpeed = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVissimSpeedNorm(qreal value)
{
    netConvertDefaultVissimSpeedNorm = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVissimReportUnsetSpeeds(bool value)
{
    netConvertDefaultVissimReportUnsetSpeeds = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVisumUseTypePriority(bool value)
{
    netConvertDefaultVisumUseTypePriority = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVisumUseTypeLaneno(bool value)
{
    netConvertDefaultVisumUseTypeLaneno = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVisumUseTypeSpeed(bool value)
{
    netConvertDefaultVisumUseTypeSpeed = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVisumConnectorSpeeds(qreal value)
{
    netConvertDefaultVisumConnectorSpeeds = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVisumConnectorsLaneNumber(int value)
{
    netConvertDefaultVisumConnectorsLaneNumber = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVisumNoConnectors(bool value)
{
    netConvertDefaultVisumNoConnectors = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVisumRecomputeLaneNumber(bool value)
{
    netConvertDefaultVisumRecomputeLaneNumber = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVisumVerboseWarnings(bool value)
{
    netConvertDefaultVisumVerboseWarnings = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOsmSkipDuplicatesCheck(bool value)
{
    netConvertDefaultOsmSkipDuplicatesCheck = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOsmRailwayOnewayDefault(bool value)
{
    netConvertDefaultOsmRailwayOnewayDefault = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOsmElevation(bool value)
{
    netConvertDefaultOsmElevation = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOpendriveImportAllLanes(bool value)
{
    netConvertDefaultOpendriveImportAllLanes = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOpendriveIgnoreWidths(bool value)
{
    netConvertDefaultOpendriveIgnoreWidths = value;
}

void netConvertToolConfiguration::setNetConvertDefaultNoInternalLinks(bool value)
{
    netConvertDefaultNoInternalLinks = value;
}

void netConvertToolConfiguration::setNetConvertDefaultDismissVclasses(bool value)
{
    netConvertDefaultDismissVclasses = value;
}

void netConvertToolConfiguration::setNetConvertDefaultNoTurnarounds(bool value)
{
    netConvertDefaultNoTurnarounds = value;
}

void netConvertToolConfiguration::setNetConvertDefaultNoTurnaroundsTls(bool value)
{
    netConvertDefaultNoTurnaroundsTls = value;
}

void netConvertToolConfiguration::setNetConvertDefaultNoLeftConnections(bool value)
{
    netConvertDefaultNoLeftConnections = value;
}

void netConvertToolConfiguration::setNetConvertDefaultGeometrySplit(bool value)
{
    netConvertDefaultGeometrySplit = value;
}

void netConvertToolConfiguration::setNetConvertDefaultGeometryRemove(bool value)
{
    netConvertDefaultGeometryRemove = value;
}

void netConvertToolConfiguration::setNetConvertDefaultGeometryMaxSegmentLength(qreal value)
{
    netConvertDefaultGeometryMaxSegmentLength = value;
}

void netConvertToolConfiguration::setNetConvertDefaultGeometryMinDist(qreal value)
{
    netConvertDefaultGeometryMinDist = value;
}

void netConvertToolConfiguration::setNetConvertDefaultGeometryMaxAngle(qreal value)
{
    netConvertDefaultGeometryMaxAngle = value;
}

void netConvertToolConfiguration::setNetConvertDefaultGeometryMinRadius(qreal value)
{
    netConvertDefaultGeometryMinRadius = value;
}

void netConvertToolConfiguration::setNetConvertDefaultGeometryMinRadiusFix(bool value)
{
    netConvertDefaultGeometryMinRadiusFix = value;
}

void netConvertToolConfiguration::setNetConvertDefaultGeometryJunctionMismatchThreshold(qreal value)
{
    netConvertDefaultGeometryJunctionMismatchThreshold = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOffsetDisableNormalization(bool value)
{
    netConvertDefaultOffsetDisableNormalization = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOffsetX(qreal value)
{
    netConvertDefaultOffsetX = value;
}

void netConvertToolConfiguration::setNetConvertDefaultOffsetY(qreal value)
{
    netConvertDefaultOffsetY = value;
}

void netConvertToolConfiguration::setNetConvertDefaultFlipYAxis(bool value)
{
    netConvertDefaultFlipYAxis = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRoundaboutsGuess(bool value)
{
    netConvertDefaultRoundaboutsGuess = value;
}

void netConvertToolConfiguration::setNetConvertDefaultLefthand(bool value)
{
    netConvertDefaultLefthand = value;
}

void netConvertToolConfiguration::setNetConvertDefaultJunctionsJoin(bool value)
{
    netConvertDefaultJunctionsJoin = value;
}

void netConvertToolConfiguration::setNetConvertDefaultJunctionsJoinDist(qreal value)
{
    netConvertDefaultJunctionsJoinDist = value;
}

void netConvertToolConfiguration::setNetConvertDefaultJunctionsJoinExclude(const QString &value)
{
    netConvertDefaultJunctionsJoinExclude = value;
}

void netConvertToolConfiguration::setNetConvertDefaultSpeedOffset(qreal value)
{
    netConvertDefaultSpeedOffset = value;
}

void netConvertToolConfiguration::setNetConvertDefaultSpeedFactor(qreal value)
{
    netConvertDefaultSpeedFactor = value;
}

void netConvertToolConfiguration::setNetConvertDefaultJunctionsCornerDetail(int value)
{
    netConvertDefaultJunctionsCornerDetail = value;
}

void netConvertToolConfiguration::setNetConvertDefaultCheckLaneFoesRoundabout(bool value)
{
    netConvertDefaultCheckLaneFoesRoundabout = value;
}

void netConvertToolConfiguration::setNetConvertDefaultCheckLaneFoesAll(bool value)
{
    netConvertDefaultCheckLaneFoesAll = value;
}

void netConvertToolConfiguration::setNetConvertDefaultSidewalksGuess(bool value)
{
    netConvertDefaultSidewalksGuess = value;
}

void netConvertToolConfiguration::setNetConvertDefaultSidewalksGuessMaxSpeed(qreal value)
{
    netConvertDefaultSidewalksGuessMaxSpeed = value;
}

void netConvertToolConfiguration::setNetConvertDefaultSidewalksGuessMinSpeed(qreal value)
{
    netConvertDefaultSidewalksGuessMinSpeed = value;
}

void netConvertToolConfiguration::setNetConvertDefaultSidewalksGuessFromPermissions(bool value)
{
    netConvertDefaultSidewalksGuessFromPermissions = value;
}

void netConvertToolConfiguration::setNetConvertDefaultCrossingsGuess(bool value)
{
    netConvertDefaultCrossingsGuess = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsJoinDist(qreal value)
{
    netConvertDefaultTlsJoinDist = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsGuessSignals(bool value)
{
    netConvertDefaultTlsGuessSignals = value;
}

void netConvertToolConfiguration::setNetConvertDefaultTlsGuessSignalsDist(qreal value)
{
    netConvertDefaultTlsGuessSignalsDist = value;
}

void netConvertToolConfiguration::setNetConvertDefaultDefaultLanenumber(int value)
{
    netConvertDefaultDefaultLanenumber = value;
}

void netConvertToolConfiguration::setNetConvertDefaultDefaultSpeed(qreal value)
{
    netConvertDefaultDefaultSpeed = value;
}

void netConvertToolConfiguration::setNetConvertDefaultDefaultPriority(int value)
{
    netConvertDefaultDefaultPriority = value;
}

void netConvertToolConfiguration::setNetConvertDefaultDefaultSidewalkWidth(qreal value)
{
    netConvertDefaultDefaultSidewalkWidth = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVerbose(bool value)
{
    netConvertDefaultVerbose = value;
}

void netConvertToolConfiguration::setNetConvertDefaultPrintOptions(bool value)
{
    netConvertDefaultPrintOptions = value;
}

void netConvertToolConfiguration::setNetConvertDefaultHelp(bool value)
{
    netConvertDefaultHelp = value;
}

void netConvertToolConfiguration::setNetConvertDefaultVersion(bool value)
{
    netConvertDefaultVersion = value;
}

void netConvertToolConfiguration::setNetConvertDefaultxmlValidation(const QString &value)
{
    netConvertDefaultxmlValidation = value;
}

void netConvertToolConfiguration::setNetConvertDefaultNoWarnings(bool value)
{
    netConvertDefaultNoWarnings = value;
}

void netConvertToolConfiguration::setNetConvertDefaultLog(const QString &value)
{
    netConvertDefaultLog = value;
}

void netConvertToolConfiguration::setNetConvertDefaultMessageLog(const QString &value)
{
    netConvertDefaultMessageLog = value;
}

void netConvertToolConfiguration::setNetConvertDefaultErrorLog(const QString &value)
{
    netConvertDefaultErrorLog = value;
}

void netConvertToolConfiguration::setNetConvertDefaultRandom(bool value)
{
    netConvertDefaultRandom = value;
}

void netConvertToolConfiguration::setNetConvertDefaultSeed(int value)
{
    netConvertDefaultSeed = value;
}
