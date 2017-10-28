#include "netGenerateToolconfiguration.h"

netGenerateToolConfiguration::netGenerateToolConfiguration() : eNetEditorToolConfiguration(0, 0, 0 /** arreglar **/)
{
    // Set netGenerate default parameters

    setOutputfolder("netGenerate");

    netGenerateDefaultGrid = false;

    netGenerateDefaultGridNumber = 5;

    netGenerateDefaultGridLength = 100;

    netGenerateDefaultGridXNumber = 5;

    netGenerateDefaultGridYNumber = 5;

    netGenerateDefaultGridXLength = 100;

    netGenerateDefaultGridYLength = 100;

    netGenerateDefaultGridAttachLength = 0;

    netGenerateDefaultSpider = false;

    netGenerateDefaultSpiderArmNumber = 13;

    netGenerateDefaultSpiderCircleNumber = 20;

    netGenerateDefaultSpiderSpaceRadius = 100;

    netGenerateDefaultSpiderOmitCenter = false;

    netGenerateDefaultRand = false;

    netGenerateDefaultRandIterations = 2000;

    netGenerateDefaultRandBidiProbability = 1;

    netGenerateDefaultRandMaxDistance = 250;

    netGenerateDefaultRandMinDistance = 100;

    netGenerateDefaultRandMinAngle = 0.785398;

    netGenerateDefaultRandNumTries = 50;

    netGenerateDefaultRandConnectivity = 0.95;

    netGenerateDefaultRandNeighborDist1 = 0;

    netGenerateDefaultRandNeighborDist2 = 0;

    netGenerateDefaultRandNeighborDist3 = 10;

    netGenerateDefaultRandNeighborDist4 = 10;

    netGenerateDefaultRandNeighborDist5 = 2;

    netGenerateDefaultRandNeighborDist6 = 1;

    netGenerateDefaultOutputFile = "netGenerate.output";

    netGenerateDefaultPlainOutputPrefix = "";

    netGenerateDefaultJunctionsJoinOutput = "netGnerate.juntionJoin";

    netGenerateDefaultAmitranOutput = "netGenerate.Amitran";

    netGenerateDefaultMatsimOutput = "netGenerate.MatSim";

    netGenerateDefaultOpendriveOutput = "netGenerate.openDrive";

    netGenerateDefaultDlrNavteqOutput = "netGenerate.dlrNavteq";

    netGenerateDefaultOutputStreetNames = false;

    netGenerateDefaultOutputOriginalNames = false;

    netGenerateDefaultStreetSignOutput = "netGenerate.streetSign";

    netGenerateDefaultTlsGuess = false;

    netGenerateDefaultTlsGuessJoining = false;

    netGenerateDefaultTlsJoin = false;

    netGenerateDefaultTlsGreenTime = 31;

    netGenerateDefaultTlsYellowMinDecel = 3;

    netGenerateDefaultTlsYellowPatchSmall = false;

    netGenerateDefaultTlsYellowTime = 0;

    netGenerateDefaultTlsDefaultType = "static";

    netGenerateDefaultKeepEdgesMinSpeed = 0;

    netGenerateDefaultKeepNodesUnregulated = false;

    netGenerateDefaultKeepNodesUnregulatedDistrictNodes = false;

    netGenerateDefaultNoInternalLinks = false;

    netGenerateDefaultNoTurnarounds = false;

    netGenerateDefaultNoTurnaroundsTls = false;

    netGenerateDefaultNoLeftConnections = false;

    netGenerateDefaultOffsetDisableNormalization = false;

    netGenerateDefaultOffsetX = 0;

    netGenerateDefaultOffsetY = 0;

    netGenerateDefaultFlipYAxis = false;

    netGenerateDefaultRoundaboutsGuess = false;

    netGenerateDefaultLefthand = false;

    netGenerateDefaultJunctionsJoin = false;

    netGenerateDefaultJunctionsJoinDist = 10;

    netGenerateDefaultJunctionsCornerDetail = 0;

    netGenerateDefaultCheckLaneFoesRoundabout = true;

    netGenerateDefaultCheckLaneFoesAll = false;

    netGenerateDefaultSidewalksGuess = false;

    netGenerateDefaultSidewalksGuessMaxSpeed = 13.89;

    netGenerateDefaultSidewalksGuessMinSpeed = 5.8;

    netGenerateDefaultSidewalksGuessFromPermissions = false;

    netGenerateDefaultCrossingsGuess = false;

    netGenerateDefaultTlsJoinDist = 20;

    netGenerateDefaultDefaultLanenumber = 1;

    netGenerateDefaultDefaultSpeed = 13.9;

    netGenerateDefaultDefaultPriority = -1;

    netGenerateDefaultDefaultSidewalkWidth = 2;

    netGenerateDefaultDefaultJunctionType = "priority";

    netGenerateDefaultVerbose = false;

    netGenerateDefaultPrintOptions = false;

    netGenerateDefaultHelp = false;

    netGenerateDefaultVersion = false;

    netGenerateDefaultXmlValidation = "auto";

    netGenerateDefaultXmlValidationNet = "never";

    netGenerateDefaultNoWarnings = false;

    netGenerateDefaultLog = "netGenerate.log";

    netGenerateDefaultMessageLog = "netGenerate.messageLog";

    netGenerateDefaultErrorLog = "netGnerate.errorLog";

    netGenerateDefaultRandom = false;

    netGenerateDefaultSeed = 23423;
}

netGenerateToolConfiguration::~netGenerateToolConfiguration()
{
    // Nothing to erase
}

bool netGenerateToolConfiguration::getNetGenerateDefaultGrid() const
{
    return netGenerateDefaultGrid;
}

int netGenerateToolConfiguration::getNetGenerateDefaultGridNumber() const
{
    return netGenerateDefaultGridNumber;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultGridLength() const
{
    return netGenerateDefaultGridLength;
}

int netGenerateToolConfiguration::getNetGenerateDefaultGridXNumber() const
{
    return netGenerateDefaultGridXNumber;
}

int netGenerateToolConfiguration::getNetGenerateDefaultGridYNumber() const
{
    return netGenerateDefaultGridYNumber;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultGridXLength() const
{
    return netGenerateDefaultGridXLength;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultGridYLength() const
{
    return netGenerateDefaultGridYLength;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultGridAttachLength() const
{
    return netGenerateDefaultGridAttachLength;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultSpider() const
{
    return netGenerateDefaultSpider;
}

int netGenerateToolConfiguration::getNetGenerateDefaultSpiderArmNumber() const
{
    return netGenerateDefaultSpiderArmNumber;
}

int netGenerateToolConfiguration::getNetGenerateDefaultSpiderCircleNumber() const
{
    return netGenerateDefaultSpiderCircleNumber;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultSpiderSpaceRadius() const
{
    return netGenerateDefaultSpiderSpaceRadius;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultSpiderOmitCenter() const
{
    return netGenerateDefaultSpiderOmitCenter;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultRand() const
{
    return netGenerateDefaultRand;
}

int netGenerateToolConfiguration::getNetGenerateDefaultRandIterations() const
{
    return netGenerateDefaultRandIterations;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultRandBidiProbability() const
{
    return netGenerateDefaultRandBidiProbability;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultRandMaxDistance() const
{
    return netGenerateDefaultRandMaxDistance;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultRandMinDistance() const
{
    return netGenerateDefaultRandMinDistance;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultRandMinAngle() const
{
    return netGenerateDefaultRandMinAngle;
}

int netGenerateToolConfiguration::getNetGenerateDefaultRandNumTries() const
{
    return netGenerateDefaultRandNumTries;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultRandConnectivity() const
{
    return netGenerateDefaultRandConnectivity;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultRandNeighborDist1() const
{
    return netGenerateDefaultRandNeighborDist1;
}
qreal netGenerateToolConfiguration::getNetGenerateDefaultRandNeighborDist2() const
{
    return netGenerateDefaultRandNeighborDist2;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultRandNeighborDist3() const
{
    return netGenerateDefaultRandNeighborDist3;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultRandNeighborDist4() const
{
    return netGenerateDefaultRandNeighborDist4;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultRandNeighborDist5() const
{
    return netGenerateDefaultRandNeighborDist5;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultRandNeighborDist6() const
{
    return netGenerateDefaultRandNeighborDist6;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultOutputPrefix() const
{
    return netGenerateDefaultOutputPrefix;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultOutputFile() const
{
    return netGenerateDefaultOutputFile;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultPlainOutputPrefix() const
{
    return netGenerateDefaultPlainOutputPrefix;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultJunctionsJoinOutput() const
{
    return netGenerateDefaultJunctionsJoinOutput;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultAmitranOutput() const
{
    return netGenerateDefaultAmitranOutput;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultMatsimOutput() const
{
    return netGenerateDefaultMatsimOutput;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultOpendriveOutput() const
{
    return netGenerateDefaultOpendriveOutput;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultDlrNavteqOutput() const
{
    return netGenerateDefaultDlrNavteqOutput;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultOutputStreetNames() const
{
    return netGenerateDefaultOutputStreetNames;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultOutputOriginalNames() const
{
    return netGenerateDefaultOutputOriginalNames;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultStreetSignOutput() const
{
    return netGenerateDefaultStreetSignOutput;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultTlsSet() const
{
    return netGenerateDefaultTlsSet;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultTlsUnset() const
{
    return netGenerateDefaultTlsUnset;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultTlsGuess() const
{
    return netGenerateDefaultTlsGuess;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultTlsGuessJoining() const
{
    return netGenerateDefaultTlsGuessJoining;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultTlsJoin() const
{
    return netGenerateDefaultTlsJoin;
}

int netGenerateToolConfiguration::getNetGenerateDefaultTlsGreenTime() const
{
    return netGenerateDefaultTlsGreenTime;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultTlsYellowMinDecel() const
{
    return netGenerateDefaultTlsYellowMinDecel;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultTlsYellowPatchSmall() const
{
    return netGenerateDefaultTlsYellowPatchSmall;
}

int netGenerateToolConfiguration::getNetGenerateDefaultTlsYellowTime() const
{
    return netGenerateDefaultTlsYellowTime;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultTlsHalfOffset() const
{
    return netGenerateDefaultTlsHalfOffset;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultTlsQuarterOffset() const
{
    return netGenerateDefaultTlsQuarterOffset;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultTlsDefaultType() const
{
    return netGenerateDefaultTlsDefaultType;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultKeepEdgesMinSpeed() const
{
    return netGenerateDefaultKeepEdgesMinSpeed;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultRemoveEdgesExplicit() const
{
    return netGenerateDefaultRemoveEdgesExplicit;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultKeepEdgesExplicit() const
{
    return netGenerateDefaultKeepEdgesExplicit;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultKeepEdgesInputFile() const
{
    return netGenerateDefaultKeepEdgesInputFile;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultKeepEdgesInBoundary() const
{
    return netGenerateDefaultKeepEdgesInBoundary;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultKeepEdgesInGeoBoundary() const
{
    return netGenerateDefaultKeepEdgesInGeoBoundary;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultKeepNodesUnregulated() const
{
    return netGenerateDefaultKeepNodesUnregulated;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultKeepNodesUnregulatedExplicit() const
{
    return netGenerateDefaultKeepNodesUnregulatedExplicit;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultKeepNodesUnregulatedDistrictNodes() const
{
    return netGenerateDefaultKeepNodesUnregulatedDistrictNodes;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultNoInternalLinks() const
{
    return netGenerateDefaultNoInternalLinks;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultNoTurnarounds() const
{
    return netGenerateDefaultNoTurnarounds;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultNoTurnaroundsTls() const
{
    return netGenerateDefaultNoTurnaroundsTls;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultNoLeftConnections() const
{
    return netGenerateDefaultNoLeftConnections;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultOffsetDisableNormalization() const
{
    return netGenerateDefaultOffsetDisableNormalization;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultOffsetX() const
{
    return netGenerateDefaultOffsetX;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultOffsetY() const
{
    return netGenerateDefaultOffsetY;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultFlipYAxis() const
{
    return netGenerateDefaultFlipYAxis;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultRoundaboutsGuess() const
{
    return netGenerateDefaultRoundaboutsGuess;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultLefthand() const
{
    return netGenerateDefaultLefthand;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultJunctionsJoin() const
{
    return netGenerateDefaultJunctionsJoin;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultJunctionsJoinDist() const
{
    return netGenerateDefaultJunctionsJoinDist;
}

int netGenerateToolConfiguration::getNetGenerateDefaultJunctionsCornerDetail() const
{
    return netGenerateDefaultJunctionsCornerDetail;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultCheckLaneFoesRoundabout() const
{
    return netGenerateDefaultCheckLaneFoesRoundabout;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultCheckLaneFoesAll() const
{
    return netGenerateDefaultCheckLaneFoesAll;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultSidewalksGuess() const
{
    return netGenerateDefaultSidewalksGuess;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultSidewalksGuessMaxSpeed() const
{
    return netGenerateDefaultSidewalksGuessMaxSpeed;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultSidewalksGuessMinSpeed() const
{
    return netGenerateDefaultSidewalksGuessMinSpeed;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultSidewalksGuessFromPermissions() const
{
    return netGenerateDefaultSidewalksGuessFromPermissions;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultCrossingsGuess() const
{
    return netGenerateDefaultCrossingsGuess;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultTlsJoinDist() const
{
    return netGenerateDefaultTlsJoinDist;
}

int netGenerateToolConfiguration::getNetGenerateDefaultDefaultLanenumber() const
{
    return netGenerateDefaultDefaultLanenumber;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultDefaultSpeed() const
{
    return netGenerateDefaultDefaultSpeed;
}

int netGenerateToolConfiguration::getNetGenerateDefaultDefaultPriority() const
{
    return netGenerateDefaultDefaultPriority;
}

qreal netGenerateToolConfiguration::getNetGenerateDefaultDefaultSidewalkWidth() const
{
    return netGenerateDefaultDefaultSidewalkWidth;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultDefaultJunctionType() const
{
    return netGenerateDefaultDefaultJunctionType;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultVerbose() const
{
    return netGenerateDefaultVerbose;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultPrintOptions() const
{
    return netGenerateDefaultPrintOptions;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultHelp() const
{
    return netGenerateDefaultHelp;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultVersion() const
{
    return netGenerateDefaultVersion;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultXmlValidation() const
{
    return netGenerateDefaultXmlValidation;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultXmlValidationNet() const
{
    return netGenerateDefaultXmlValidationNet;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultNoWarnings() const
{
    return netGenerateDefaultNoWarnings;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultLog() const
{
    return netGenerateDefaultLog;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultMessageLog() const
{
    return netGenerateDefaultMessageLog;
}

const QString &netGenerateToolConfiguration::getNetGenerateDefaultErrorLog() const
{
    return netGenerateDefaultErrorLog;
}

bool netGenerateToolConfiguration::getNetGenerateDefaultRandom() const
{
    return netGenerateDefaultRandom;
}

int netGenerateToolConfiguration::getNetGenerateDefaultSeed() const
{
    return netGenerateDefaultSeed;
}

void netGenerateToolConfiguration::setNetGenerateDefaultGrid(bool value)
{
    netGenerateDefaultGrid = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultGridNumber(int value)
{
    netGenerateDefaultGridNumber = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultGridLength(qreal value)
{
    netGenerateDefaultGridLength = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultGridXNumber(int value)
{
    netGenerateDefaultGridXNumber = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultGridYNumber(int value)
{
    netGenerateDefaultGridYNumber = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultGridXLength(qreal value)
{
    netGenerateDefaultGridXLength = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultGridYLength(qreal value)
{
    netGenerateDefaultGridYLength = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultGridAttachLength(qreal value)
{
    netGenerateDefaultGridAttachLength = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultSpider(bool value)
{
    netGenerateDefaultSpider = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultSpiderArmNumber(int value)
{
    netGenerateDefaultSpiderArmNumber = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultSpiderCircleNumber(int value)
{
    netGenerateDefaultSpiderCircleNumber = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultSpiderSpaceRadius(qreal value)
{
    netGenerateDefaultSpiderSpaceRadius = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultSpiderOmitCenter(bool value)
{
    netGenerateDefaultSpiderOmitCenter = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRand(bool value)
{
    netGenerateDefaultRand = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandIterations(int value)
{
    netGenerateDefaultRandIterations = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandBidiProbability(qreal value)
{
    netGenerateDefaultRandBidiProbability = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandMaxDistance(qreal value)
{
    netGenerateDefaultRandMaxDistance = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandMinDistance(qreal value)
{
    netGenerateDefaultRandMinDistance = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandMinAngle(qreal value)
{
    netGenerateDefaultRandMinAngle = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandNumTries(int value)
{
    netGenerateDefaultRandNumTries = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandConnectivity(qreal value)
{
    netGenerateDefaultRandConnectivity = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandNeighborDist1(qreal value)
{
    netGenerateDefaultRandNeighborDist1 = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandNeighborDist2(qreal value)
{
    netGenerateDefaultRandNeighborDist2 = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandNeighborDist3(qreal value)
{
    netGenerateDefaultRandNeighborDist3 = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandNeighborDist4(qreal value)
{
    netGenerateDefaultRandNeighborDist4 = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandNeighborDist5(qreal value)
{
    netGenerateDefaultRandNeighborDist5 = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandNeighborDist6(qreal value)
{
    netGenerateDefaultRandNeighborDist6 = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultOutputPrefix(const QString &value)
{
    netGenerateDefaultOutputPrefix = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultOutputFile(const QString &value)
{
    netGenerateDefaultOutputFile = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultPlainOutputPrefix(const QString &value)
{
    netGenerateDefaultPlainOutputPrefix = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultJunctionsJoinOutput(const QString &value)
{
    netGenerateDefaultJunctionsJoinOutput = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultAmitranOutput(const QString &value)
{
    netGenerateDefaultAmitranOutput = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultMatsimOutput(const QString &value)
{
    netGenerateDefaultMatsimOutput = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultOpendriveOutput(const QString &value)
{
    netGenerateDefaultOpendriveOutput = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultDlrNavteqOutput(const QString &value)
{
    netGenerateDefaultDlrNavteqOutput = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultOutputStreetNames(bool value)
{
    netGenerateDefaultOutputStreetNames = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultOutputOriginalNames(bool value)
{
    netGenerateDefaultOutputOriginalNames = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultStreetSignOutput(const QString &value)
{
    netGenerateDefaultStreetSignOutput = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsSet(const QString &value)
{
    netGenerateDefaultTlsSet = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsUnset(const QString &value)
{
    netGenerateDefaultTlsUnset = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsGuess(bool value)
{
    netGenerateDefaultTlsGuess = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsGuessJoining(bool value)
{
    netGenerateDefaultTlsGuessJoining = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsJoin(bool value)
{
    netGenerateDefaultTlsJoin = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsGreenTime(int value)
{
    netGenerateDefaultTlsGreenTime = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsYellowMinDecel(qreal value)
{
    netGenerateDefaultTlsYellowMinDecel = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsYellowPatchSmall(bool value)
{
    netGenerateDefaultTlsYellowPatchSmall = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsYellowTime(int value)
{
    netGenerateDefaultTlsYellowTime = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsHalfOffset(const QString &value)
{
    netGenerateDefaultTlsHalfOffset = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsQuarterOffset(const QString &value)
{
    netGenerateDefaultTlsQuarterOffset = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsDefaultType(const QString &value)
{
    netGenerateDefaultTlsDefaultType = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultKeepEdgesMinSpeed(qreal value)
{
    netGenerateDefaultKeepEdgesMinSpeed = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRemoveEdgesExplicit(const QString &value)
{
    netGenerateDefaultRemoveEdgesExplicit = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultKeepEdgesExplicit(const QString &value)
{
    netGenerateDefaultKeepEdgesExplicit = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultKeepEdgesInputFile(const QString &value)
{
    netGenerateDefaultKeepEdgesInputFile = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultKeepEdgesInBoundary(const QString &value)
{
    netGenerateDefaultKeepEdgesInBoundary = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultKeepEdgesInGeoBoundary(const QString &value)
{
    netGenerateDefaultKeepEdgesInGeoBoundary = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultKeepNodesUnregulated(bool value)
{
    netGenerateDefaultKeepNodesUnregulated = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultKeepNodesUnregulatedExplicit(const QString &value)
{
    netGenerateDefaultKeepNodesUnregulatedExplicit = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultKeepNodesUnregulatedDistrictNodes(bool value)
{
    netGenerateDefaultKeepNodesUnregulatedDistrictNodes = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultNoInternalLinks(bool value)
{
    netGenerateDefaultNoInternalLinks = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultNoTurnarounds(bool value)
{
    netGenerateDefaultNoTurnarounds = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultNoTurnaroundsTls(bool value)
{
    netGenerateDefaultNoTurnaroundsTls = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultNoLeftConnections(bool value)
{
    netGenerateDefaultNoLeftConnections = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultOffsetDisableNormalization(bool value)
{
    netGenerateDefaultOffsetDisableNormalization = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultOffsetX(qreal value)
{
    netGenerateDefaultOffsetX = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultOffsetY(qreal value)
{
    netGenerateDefaultOffsetY = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultFlipYAxis(bool value)
{
    netGenerateDefaultFlipYAxis = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRoundaboutsGuess(bool value)
{
    netGenerateDefaultRoundaboutsGuess = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultLefthand(bool value)
{
    netGenerateDefaultLefthand = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultJunctionsJoin(bool value)
{
    netGenerateDefaultJunctionsJoin = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultJunctionsJoinDist(qreal value)
{
    netGenerateDefaultJunctionsJoinDist = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultJunctionsCornerDetail(int value)
{
    netGenerateDefaultJunctionsCornerDetail = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultCheckLaneFoesRoundabout(bool value)
{
    netGenerateDefaultCheckLaneFoesRoundabout = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultCheckLaneFoesAll(bool value)
{
    netGenerateDefaultCheckLaneFoesAll = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultSidewalksGuess(bool value)
{
    netGenerateDefaultSidewalksGuess = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultSidewalksGuessMaxSpeed(qreal value)
{
    netGenerateDefaultSidewalksGuessMaxSpeed = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultSidewalksGuessMinSpeed(qreal value)
{
    netGenerateDefaultSidewalksGuessMinSpeed = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultSidewalksGuessFromPermissions(bool value)
{
    netGenerateDefaultSidewalksGuessFromPermissions = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultCrossingsGuess(bool value)
{
    netGenerateDefaultCrossingsGuess = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultTlsJoinDist(qreal value)
{
    netGenerateDefaultTlsJoinDist = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultDefaultLanenumber(int value)
{
    netGenerateDefaultDefaultLanenumber = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultDefaultSpeed(qreal value)
{
    netGenerateDefaultDefaultSpeed = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultDefaultPriority(int value)
{
    netGenerateDefaultDefaultPriority = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultDefaultSidewalkWidth(qreal value)
{
    netGenerateDefaultDefaultSidewalkWidth = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultDefaultJunctionType(const QString &value)
{
    netGenerateDefaultDefaultJunctionType = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultVerbose(bool value)
{
    netGenerateDefaultVerbose = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultPrintOptions(bool value)
{
    netGenerateDefaultPrintOptions = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultHelp(bool value)
{
    netGenerateDefaultHelp = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultVersion(bool value)
{
    netGenerateDefaultVersion = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultXmlValidation(const QString &value)
{
    netGenerateDefaultXmlValidation = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultXmlValidationNet(const QString &value)
{
    netGenerateDefaultXmlValidationNet = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultNoWarnings(bool value)
{
    netGenerateDefaultNoWarnings = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultLog(const QString &value)
{
    netGenerateDefaultLog = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultMessageLog(const QString &value)
{
    netGenerateDefaultMessageLog = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultErrorLog(const QString &value)
{
    netGenerateDefaultErrorLog = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultRandom(bool value)
{
    netGenerateDefaultRandom = value;
}

void netGenerateToolConfiguration::setNetGenerateDefaultSeed(int value)
{
    netGenerateDefaultSeed = value;
}
