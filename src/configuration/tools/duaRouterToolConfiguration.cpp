#include "duaRouterToolConfiguration.h"

duaRouterToolConfiguration::duaRouterToolConfiguration() : eNetEditorToolConfiguration(0, 0, 0 /** arreglar **/)
{
    setOutputfolder("duaRouter");

    duaRouterDefaultNetFile = "net";

    duaRouterDefaultAdditionalFiles = "additionals";

    duaRouterDefaultAlternativeFiles = "alternatives";

    duaRouterDefaultFlowFiles = "flows";

    duaRouterDefaultWeightFiles = "weights";

    duaRouterDefaultLaneWeightFiles = "laneWeights";

    duaRouterDefaultWeightAttribute = "traveltime";

    duaRouterDefaultPhemlightPath = "./PHEMlight/";

    duaRouterDefaultTripFiles = "trips";

    duaRouterDefaultRouteFiles = "routes";

    duaRouterDefaultOutputPrefix = "";

    duaRouterDefaultOutputFile = "duaRouter.routes";

    duaRouterDefaultVtypeOutput = "duaRouter.vehicleType";

    duaRouterDefaultExitTimes = false;

    duaRouterDefaultIgnoreErrors = false;

    duaRouterDefaultUnsortedInput = false;

    duaRouterDefaultRouteSteps = 200;

    duaRouterDefaultRandomizeFlows = false;

    duaRouterDefaultMaxAlternatives = 5;

    duaRouterDefaultRemoveLoops = false;

    duaRouterDefaultRepair = false;

    duaRouterDefaultWeightsInterpolate = false;

    duaRouterDefaultWithTaz = false;

    duaRouterDefaultRoutingAlgorithm = "dijkstra";

    duaRouterDefaultWeightPeriod = 3600;

    duaRouterDefaultRoutingThreads = 0;

    duaRouterDefaultWeightsExpand = false;

    duaRouterDefaultGawronBeta = 0.3;

    duaRouterDefaultGawronA = 0.05;

    duaRouterDefaultKeepAllRoutes = false;

    duaRouterDefaultSkipNewRoutes = false;

    duaRouterDefaultLogit = false;

    duaRouterDefaultRouteChoiceMethod = "gawron";

    duaRouterDefaultLogitBeta = -1;

    duaRouterDefaultLogitGamma = 1;

    duaRouterDefaultLogitTheta = -1;

    duaRouterDefaultDefaultsOverride = false;

    duaRouterDefaultBegin = 0;

    duaRouterDefaultEnd = 2147483;

    duaRouterDefaultVerbose = false;

    duaRouterDefaultPrintOptions = false;

    duaRouterDefaultHelp = false;

    duaRouterDefaultVersion = false;

    duaRouterDefaultXmlValidation = "auto";

    duaRouterDefaultXmlValidationNet = "never";

    duaRouterDefaultNoWarnings = false;

    duaRouterDefaultLog = "duaRouter.log";

    duaRouterDefaultMessageLog = "duaRouter.messageLog";

    duaRouterDefaultErrorLog = "duaRouter.errorLog";

    duaRouterDefaultStatsPeriod = -1;

    duaRouterDefaultNoStepLog = false;

    duaRouterDefaultRandom = false;

    duaRouterDefaultSeed = 23423;
}

duaRouterToolConfiguration::~duaRouterToolConfiguration()
{
    // Nothing to erase
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultNetFile() const
{
    return duaRouterDefaultNetFile;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultAdditionalFiles() const
{
    return duaRouterDefaultAdditionalFiles;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultAlternativeFiles() const
{
    return duaRouterDefaultAlternativeFiles;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultFlowFiles() const
{
    return duaRouterDefaultFlowFiles;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultWeightFiles() const
{
    return duaRouterDefaultWeightFiles;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultLaneWeightFiles() const
{
    return duaRouterDefaultLaneWeightFiles;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultWeightAttribute() const
{
    return duaRouterDefaultWeightAttribute;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultPhemlightPath() const
{
    return duaRouterDefaultPhemlightPath;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultTripFiles() const
{
    return duaRouterDefaultTripFiles;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultRouteFiles() const
{
    return duaRouterDefaultRouteFiles;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultOutputPrefix() const
{
    return duaRouterDefaultOutputPrefix;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultOutputFile() const
{
    return duaRouterDefaultOutputFile;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultVtypeOutput() const
{
    return duaRouterDefaultVtypeOutput;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultExitTimes() const
{
    return duaRouterDefaultExitTimes;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultIgnoreErrors() const
{
    return duaRouterDefaultIgnoreErrors;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultUnsortedInput() const
{
    return duaRouterDefaultUnsortedInput;
}

int duaRouterToolConfiguration::getDuaRouterDefaultRouteSteps() const
{
    return duaRouterDefaultRouteSteps;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultRandomizeFlows() const
{
    return duaRouterDefaultRandomizeFlows;
}

int duaRouterToolConfiguration::getDuaRouterDefaultMaxAlternatives() const
{
    return duaRouterDefaultMaxAlternatives;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultRemoveLoops() const
{
    return duaRouterDefaultRemoveLoops;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultRepair() const
{
    return duaRouterDefaultRepair;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultWeightsInterpolate() const
{
    return duaRouterDefaultWeightsInterpolate;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultWithTaz() const
{
    return duaRouterDefaultWithTaz;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultRoutingAlgorithm() const
{
    return duaRouterDefaultRoutingAlgorithm;
}

int duaRouterToolConfiguration::getDuaRouterDefaultWeightPeriod() const
{
    return duaRouterDefaultWeightPeriod;
}

int duaRouterToolConfiguration::getDuaRouterDefaultRoutingThreads() const
{
    return duaRouterDefaultRoutingThreads;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultWeightsExpand() const
{
    return duaRouterDefaultWeightsExpand;
}

qreal duaRouterToolConfiguration::getDuaRouterDefaultGawronBeta() const
{
    return duaRouterDefaultGawronBeta;
}

qreal duaRouterToolConfiguration::getDuaRouterDefaultGawronA() const
{
    return duaRouterDefaultGawronA;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultKeepAllRoutes() const
{
    return duaRouterDefaultKeepAllRoutes;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultSkipNewRoutes() const
{
    return duaRouterDefaultSkipNewRoutes;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultLogit() const
{
    return duaRouterDefaultLogit;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultRouteChoiceMethod() const
{
    return duaRouterDefaultRouteChoiceMethod;
}

qreal duaRouterToolConfiguration::getDuaRouterDefaultLogitBeta() const
{
    return duaRouterDefaultLogitBeta;
}

qreal duaRouterToolConfiguration::getDuaRouterDefaultLogitGamma() const
{
    return duaRouterDefaultLogitGamma;
}

qreal duaRouterToolConfiguration::getDuaRouterDefaultLogitTheta() const
{
    return duaRouterDefaultLogitTheta;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultDepartlane() const
{
    return duaRouterDefaultDepartlane;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultDepartpos() const
{
    return duaRouterDefaultDepartpos;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultDepartspeed() const
{
    return duaRouterDefaultDepartspeed;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultArrivallane() const
{
    return duaRouterDefaultArrivallane;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultArrivalpos() const
{
    return duaRouterDefaultArrivalpos;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultArrivalspeed() const
{
    return duaRouterDefaultArrivalspeed;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultDefaultsOverride() const
{
    return duaRouterDefaultDefaultsOverride;
}

int duaRouterToolConfiguration::getDuaRouterDefaultBegin() const
{
    return duaRouterDefaultBegin;
}

int duaRouterToolConfiguration::getDuaRouterDefaultEnd() const
{
    return duaRouterDefaultEnd;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultVerbose() const
{
    return duaRouterDefaultVerbose;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultPrintOptions() const
{
    return duaRouterDefaultPrintOptions;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultHelp() const
{
    return duaRouterDefaultHelp;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultVersion() const
{
    return duaRouterDefaultVersion;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultXmlValidation() const
{
    return duaRouterDefaultXmlValidation;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultXmlValidationNet() const
{
    return duaRouterDefaultXmlValidationNet;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultNoWarnings() const
{
    return duaRouterDefaultNoWarnings;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultLog() const
{
    return duaRouterDefaultLog;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultMessageLog() const
{
    return duaRouterDefaultMessageLog;
}

const QString &duaRouterToolConfiguration::getDuaRouterDefaultErrorLog() const
{
    return duaRouterDefaultErrorLog;
}

int duaRouterToolConfiguration::getDuaRouterDefaultStatsPeriod() const
{
    return duaRouterDefaultStatsPeriod;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultNoStepLog() const
{
    return duaRouterDefaultNoStepLog;
}

bool duaRouterToolConfiguration::getDuaRouterDefaultRandom() const
{
    return duaRouterDefaultRandom;
}

int duaRouterToolConfiguration::getDuaRouterDefaultSeed() const
{
    return duaRouterDefaultSeed;
}

void duaRouterToolConfiguration::setDuaRouterDefaultNetFile(const QString &value)
{
    duaRouterDefaultNetFile = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultAdditionalFiles(const QString &value)
{
    duaRouterDefaultAdditionalFiles = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultAlternativeFiles(const QString &value)
{
    duaRouterDefaultAlternativeFiles = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultFlowFiles(const QString &value)
{
    duaRouterDefaultFlowFiles = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultWeightFiles(const QString &value)
{
    duaRouterDefaultWeightFiles = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultLaneWeightFiles(const QString &value)
{
    duaRouterDefaultLaneWeightFiles = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultWeightAttribute(const QString &value)
{
    duaRouterDefaultWeightAttribute = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultPhemlightPath(const QString &value)
{
    duaRouterDefaultPhemlightPath = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultTripFiles(const QString &value)
{
    duaRouterDefaultTripFiles = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultRouteFiles(const QString &value)
{
    duaRouterDefaultRouteFiles = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultOutputPrefix(const QString &value)
{
    duaRouterDefaultOutputPrefix = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultOutputFile(const QString &value)
{
    duaRouterDefaultOutputFile = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultVtypeOutput(const QString &value)
{
    duaRouterDefaultVtypeOutput = value;
}



void duaRouterToolConfiguration::setDuaRouterDefaultExitTimes(bool value)
{
    duaRouterDefaultExitTimes = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultIgnoreErrors(bool value)
{
    duaRouterDefaultIgnoreErrors = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultUnsortedInput(bool value)
{
    duaRouterDefaultUnsortedInput = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultRouteSteps(int value)
{
    duaRouterDefaultRouteSteps = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultRandomizeFlows(bool value)
{
    duaRouterDefaultRandomizeFlows = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultMaxAlternatives(int value)
{
    duaRouterDefaultMaxAlternatives = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultRemoveLoops(bool value)
{
    duaRouterDefaultRemoveLoops = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultRepair(bool value)
{
    duaRouterDefaultRepair = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultWeightsInterpolate(bool value)
{
    duaRouterDefaultWeightsInterpolate = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultWithTaz(bool value)
{
    duaRouterDefaultWithTaz = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultRoutingAlgorithm(const QString &value)
{
    duaRouterDefaultRoutingAlgorithm = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultWeightPeriod(int value)
{
    duaRouterDefaultWeightPeriod = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultRoutingThreads(int value)
{
    duaRouterDefaultRoutingThreads = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultWeightsExpand(bool value)
{
    duaRouterDefaultWeightsExpand = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultGawronBeta(qreal value)
{
    duaRouterDefaultGawronBeta = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultGawronA(qreal value)
{
    duaRouterDefaultGawronA = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultKeepAllRoutes(bool value)
{
    duaRouterDefaultKeepAllRoutes = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultSkipNewRoutes(bool value)
{
    duaRouterDefaultSkipNewRoutes = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultLogit(bool value)
{
    duaRouterDefaultLogit = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultRouteChoiceMethod(const QString &value)
{
    duaRouterDefaultRouteChoiceMethod = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultLogitBeta(qreal value)
{
    duaRouterDefaultLogitBeta = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultLogitGamma(qreal value)
{
    duaRouterDefaultLogitGamma = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultLogitTheta(qreal value)
{
    duaRouterDefaultLogitTheta = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultDepartlane(const QString &value)
{
    duaRouterDefaultDepartlane = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultDepartpos(const QString &value)
{
    duaRouterDefaultDepartpos = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultDepartspeed(const QString &value)
{
    duaRouterDefaultDepartspeed = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultArrivallane(const QString &value)
{
    duaRouterDefaultArrivallane = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultArrivalpos(const QString &value)
{
    duaRouterDefaultArrivalpos = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultArrivalspeed(const QString &value)
{
    duaRouterDefaultArrivalspeed = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultDefaultsOverride(bool value)
{
    duaRouterDefaultDefaultsOverride = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultBegin(int value)
{
    duaRouterDefaultBegin = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultEnd(int value)
{
    duaRouterDefaultEnd = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultVerbose(bool value)
{
    duaRouterDefaultVerbose = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultPrintOptions(bool value)
{
    duaRouterDefaultPrintOptions = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultHelp(bool value)
{
    duaRouterDefaultHelp = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultVersion(bool value)
{
    duaRouterDefaultVersion = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultXmlValidation(const QString &value)
{
    duaRouterDefaultXmlValidation = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultXmlValidationNet(const QString &value)
{
    duaRouterDefaultXmlValidationNet = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultNoWarnings(bool value)
{
    duaRouterDefaultNoWarnings = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultLog(const QString &value)
{
    duaRouterDefaultLog = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultMessageLog(const QString &value)
{
    duaRouterDefaultMessageLog = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultErrorLog(const QString &value)
{
    duaRouterDefaultErrorLog = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultStatsPeriod(int value)
{
    duaRouterDefaultStatsPeriod = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultNoStepLog(bool value)
{
    duaRouterDefaultNoStepLog = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultRandom(bool value)
{
    duaRouterDefaultRandom = value;
}

void duaRouterToolConfiguration::setDuaRouterDefaultSeed(int value)
{
    duaRouterDefaultSeed = value;
}
