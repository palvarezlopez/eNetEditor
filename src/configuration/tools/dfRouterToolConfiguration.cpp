#include "dfRouterToolConfiguration.h"

dfRouterToolConfiguration::dfRouterToolConfiguration() : eNetEditorToolConfiguration(3, 12, 45)
{
    setOutputfolder("dfRouter");

    dfRouterDefaultOutputPrefixFile = "";

    dfRouterDefaultOutputRoutesFile = "dfRouter.routes.xml";

    dfRouterDefaultOutputRoutesForAll = false;

    dfRouterDefaultOutputDetectorFile = "dfRouter.detectors.xml";

    dfRouterDefaultOutputDetectorsPoiFile = "dfRouter.poi.xml";

    dfRouterDefaultOutputEmittersFile = "dfRouter.emitters.xml";

    dfRouterDefaultOutputVtype = false;

    dfRouterDefaultOutputEmittersPoiFile = "dfRouter.emitters.poi.xml";

    dfRouterDefaultOutputVariableSpeedSignFile = "dfRouter.speedSign.xml";

    dfRouterDefaultOutputEndRerouteFile = "dfRoute.rerouters.xml";

    dfRouterDefaultOutputValidationFile = "dfRouter.validation.xml";

    dfRouterDefaultOutputValidationAddSources = false;

    dfRouterDefaultGuessEmptyFlows = false;

    dfRouterDefaultHighwayMode = false;

    dfRouterDefaultIgnoreInvalidDetectors = false;

    dfRouterDefaultRevalidateDetectors = false;

    dfRouterDefaultRevalidateRoutes = false;

    dfRouterDefaultKeepUnfinishedRoutes = false;

    dfRouterDefaultKeepLongerRoutes = false;

    dfRouterDefaultMaxSearchDepth = 30;

    dfRouterDefaultEmissionsOnly = false;

    dfRouterDefaultKeepTurnarounds = false;

    dfRouterDefaultMinRouteLength = -1;

    dfRouterDefaultTimeFactor = 60;

    dfRouterDefaultTimeOffset = 0;

    dfRouterDefaultTimeStep = 60;

    dfRouterDefaultCalibratorOutput = false;

    dfRouterDefaultIncludeUnusedRoutes = false;

    dfRouterDefaultRevalidateFlows = false;

    dfRouterDefaultRemoveEmptyDetectors = false;

    dfRouterDefaultStrictSources = false;

    dfRouterDefaultRespectConcurrentInflows = false;

    dfRouterDefaultScale = 1;

    dfRouterDefaultBegin = 0;

    dfRouterDefaultEnd = 86400;

    dfRouterDefaultVerbose = false;

    dfRouterDefaultPrintOptions = false;

    dfRouterDefaultHelp = false;

    dfRouterDefaultVersion = false;

    dfRouterDefaultXmlValidation = "auto";

    dfRouterDefaultXmlValidationNet = "never";

    dfRouterDefaultNoWarnings = false;

    dfRouterDefaultLog = "dfRouter.log.txt";

    dfRouterDefaultMessageLog = "dfRouter.messageLog.txt";

    dfRouterDefaultErrorLog = "dfRouter.errorLog.txt";

    dfRouterDefaultReportEmptyDetectors = false;

    dfRouterDefaultPrintAbsoluteFlows = false;

    dfRouterDefaultNoStepLog = false;

    dfRouterDefaultRandom = false;

    dfRouterDefaultSeed = 23423;
}

dfRouterToolConfiguration::~dfRouterToolConfiguration()
{
    // Nothing to erase
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultInputNetFile() const
{
    return dfRouterDefaultInputNetFile;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultInputDetectorFiles() const
{
    return dfRouterDefaultInputDetectorFiles;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultInputMeasureFiles() const
{
    return dfRouterDefaultInputMeasureFiles;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultOutputPrefixFile() const
{
    return dfRouterDefaultOutputPrefixFile;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultOutputRoutesFile() const
{
    return dfRouterDefaultOutputRoutesFile;
}

bool dfRouterToolConfiguration::getDfRouterDefaultOutputRoutesForAll() const
{
    return dfRouterDefaultOutputRoutesForAll;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultOutputDetectorFile() const
{
    return dfRouterDefaultOutputDetectorFile;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultOutputDetectorsPoiFile() const
{
    return dfRouterDefaultOutputDetectorsPoiFile;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultOutputEmittersFile() const
{
    return dfRouterDefaultOutputEmittersFile;
}

bool dfRouterToolConfiguration::getDfRouterDefaultOutputVtype() const
{
    return dfRouterDefaultOutputVtype;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultOutputEmittersPoiFile() const
{
    return dfRouterDefaultOutputEmittersPoiFile;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultOutputVariableSpeedSignFile() const
{
    return dfRouterDefaultOutputVariableSpeedSignFile;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultOutputEndRerouteFile() const
{
    return dfRouterDefaultOutputEndRerouteFile;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultOutputValidationFile() const
{
    return dfRouterDefaultOutputValidationFile;
}

bool dfRouterToolConfiguration::getDfRouterDefaultOutputValidationAddSources() const
{
    return dfRouterDefaultOutputValidationAddSources;
}

bool dfRouterToolConfiguration::getDfRouterDefaultGuessEmptyFlows() const
{
    return dfRouterDefaultGuessEmptyFlows;
}

bool dfRouterToolConfiguration::getDfRouterDefaultHighwayMode() const
{
    return dfRouterDefaultHighwayMode;
}

bool dfRouterToolConfiguration::getDfRouterDefaultIgnoreInvalidDetectors() const
{
    return dfRouterDefaultIgnoreInvalidDetectors;
}

bool dfRouterToolConfiguration::getDfRouterDefaultRevalidateDetectors() const
{
    return dfRouterDefaultRevalidateDetectors;
}

bool dfRouterToolConfiguration::getDfRouterDefaultRevalidateRoutes() const
{
    return dfRouterDefaultRevalidateRoutes;
}

bool dfRouterToolConfiguration::getDfRouterDefaultKeepUnfinishedRoutes() const
{
    return dfRouterDefaultKeepUnfinishedRoutes;
}

bool dfRouterToolConfiguration::getDfRouterDefaultKeepLongerRoutes() const
{
    return dfRouterDefaultKeepLongerRoutes;
}

int dfRouterToolConfiguration::getDfRouterDefaultMaxSearchDepth() const
{
    return dfRouterDefaultMaxSearchDepth;
}

bool dfRouterToolConfiguration::getDfRouterDefaultEmissionsOnly() const
{
    return dfRouterDefaultEmissionsOnly;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultDisallowedEdges() const
{
    return dfRouterDefaultDisallowedEdges;
}

bool dfRouterToolConfiguration::getDfRouterDefaultKeepTurnarounds() const
{
    return dfRouterDefaultKeepTurnarounds;
}

qreal dfRouterToolConfiguration::getDfRouterDefaultMinRouteLength() const
{
    return dfRouterDefaultMinRouteLength;
}

int dfRouterToolConfiguration::getDfRouterDefaultTimeFactor() const
{
    return dfRouterDefaultTimeFactor;
}

int dfRouterToolConfiguration::getDfRouterDefaultTimeOffset() const
{
    return dfRouterDefaultTimeOffset;
}

int dfRouterToolConfiguration::getDfRouterDefaultTimeStep() const
{
    return dfRouterDefaultTimeStep;
}

bool dfRouterToolConfiguration::getDfRouterDefaultCalibratorOutput() const
{
    return dfRouterDefaultCalibratorOutput;
}

bool dfRouterToolConfiguration::getDfRouterDefaultIncludeUnusedRoutes() const
{
    return dfRouterDefaultIncludeUnusedRoutes;
}

bool dfRouterToolConfiguration::getDfRouterDefaultRevalidateFlows() const
{
    return dfRouterDefaultRevalidateFlows;
}

bool dfRouterToolConfiguration::getDfRouterDefaultRemoveEmptyDetectors() const
{
    return dfRouterDefaultRemoveEmptyDetectors;
}

bool dfRouterToolConfiguration::getDfRouterDefaultStrictSources() const
{
    return dfRouterDefaultStrictSources;
}

bool dfRouterToolConfiguration::getDfRouterDefaultRespectConcurrentInflows() const
{
    return dfRouterDefaultRespectConcurrentInflows;
}

qreal dfRouterToolConfiguration::getDfRouterDefaultScale() const
{
    return dfRouterDefaultScale;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultDepartlane() const
{
    return dfRouterDefaultDepartlane;
}


const QString &dfRouterToolConfiguration::getDfRouterDefaultDepartpos() const
{
    return dfRouterDefaultDepartpos;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultDepartspeed() const
{
    return dfRouterDefaultDepartspeed;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultArrivalpos() const
{
    return dfRouterDefaultArrivalpos;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultArrivallane() const
{
    return dfRouterDefaultArrivallane;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultArrivalspeed() const
{
    return dfRouterDefaultArrivalspeed;
}

int dfRouterToolConfiguration::getDfRouterDefaultBegin() const
{
    return dfRouterDefaultBegin;
}

int dfRouterToolConfiguration::getDfRouterDefaultEnd() const
{
    return dfRouterDefaultEnd;
}

bool dfRouterToolConfiguration::getDfRouterDefaultVerbose() const
{
    return dfRouterDefaultVerbose;
}

bool dfRouterToolConfiguration::getDfRouterDefaultPrintOptions() const
{
    return dfRouterDefaultPrintOptions;
}

bool dfRouterToolConfiguration::getDfRouterDefaultHelp() const
{
    return dfRouterDefaultHelp;
}

bool dfRouterToolConfiguration::getDfRouterDefaultVersion() const
{
    return dfRouterDefaultVersion;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultXmlValidation() const
{
    return dfRouterDefaultXmlValidation;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultXmlValidationNet() const
{
    return dfRouterDefaultXmlValidationNet;
}

bool dfRouterToolConfiguration::getDfRouterDefaultNoWarnings() const
{
    return dfRouterDefaultNoWarnings;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultLog() const
{
    return dfRouterDefaultLog;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultMessageLog() const
{
    return dfRouterDefaultMessageLog;
}

const QString &dfRouterToolConfiguration::getDfRouterDefaultErrorLog() const
{
    return dfRouterDefaultErrorLog;
}

bool dfRouterToolConfiguration::getDfRouterDefaultReportEmptyDetectors() const
{
    return dfRouterDefaultReportEmptyDetectors;
}

bool dfRouterToolConfiguration::getDfRouterDefaultPrintAbsoluteFlows() const
{
    return dfRouterDefaultPrintAbsoluteFlows;
}

bool dfRouterToolConfiguration::getDfRouterDefaultNoStepLog() const
{
    return dfRouterDefaultNoStepLog;
}

bool dfRouterToolConfiguration::getDfRouterDefaultRandom() const
{
    return dfRouterDefaultRandom;
}

int dfRouterToolConfiguration::getDfRouterDefaultSeed() const
{
    return dfRouterDefaultSeed;
}

void dfRouterToolConfiguration::setDfRouterDefaultInputNetFile(const QString &value)
{
    dfRouterDefaultInputNetFile = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultInputDetectorFiles(const QString &value)
{
    dfRouterDefaultInputDetectorFiles = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultInputMeasureFiles(const QString &value)
{
    dfRouterDefaultInputMeasureFiles = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputPrefixFile(const QString &value)
{
    dfRouterDefaultOutputPrefixFile = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputRoutesFile(const QString &value)
{
    dfRouterDefaultOutputRoutesFile = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputRoutesForAll(bool value)
{
    dfRouterDefaultOutputRoutesForAll = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputDetectorFile(const QString &value)
{
    dfRouterDefaultOutputDetectorFile = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputDetectorsPoiFile(const QString &value)
{
    dfRouterDefaultOutputDetectorsPoiFile = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputEmittersFile(const QString &value)
{
    dfRouterDefaultOutputEmittersFile = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputVtype(bool value)
{
    dfRouterDefaultOutputVtype = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputEmittersPoiFile(const QString &value)
{
    dfRouterDefaultOutputEmittersPoiFile = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputVariableSpeedSignFile(const QString &value)
{
    dfRouterDefaultOutputVariableSpeedSignFile = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputEndRerouteFile(const QString &value)
{
    dfRouterDefaultOutputEndRerouteFile = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputValidationFile(const QString &value)
{
    dfRouterDefaultOutputValidationFile = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultOutputValidationAddSources(bool value)
{
    dfRouterDefaultOutputValidationAddSources = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultGuessEmptyFlows(bool value)
{
    dfRouterDefaultGuessEmptyFlows = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultHighwayMode(bool value)
{
    dfRouterDefaultHighwayMode = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultIgnoreInvalidDetectors(bool value)
{
    dfRouterDefaultIgnoreInvalidDetectors = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultRevalidateDetectors(bool value)
{
    dfRouterDefaultRevalidateDetectors = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultRevalidateRoutes(bool value)
{
    dfRouterDefaultRevalidateRoutes = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultKeepUnfinishedRoutes(bool value)
{
    dfRouterDefaultKeepUnfinishedRoutes = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultKeepLongerRoutes(bool value)
{
    dfRouterDefaultKeepLongerRoutes = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultMaxSearchDepth(int value)
{
    dfRouterDefaultMaxSearchDepth = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultEmissionsOnly(bool value)
{
    dfRouterDefaultEmissionsOnly = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultDisallowedEdges(const QString &value)
{
    dfRouterDefaultDisallowedEdges = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultKeepTurnarounds(bool value)
{
    dfRouterDefaultKeepTurnarounds = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultMinRouteLength(qreal value)
{
    dfRouterDefaultMinRouteLength = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultTimeFactor(int value)
{
    dfRouterDefaultTimeFactor = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultTimeOffset(int value)
{
    dfRouterDefaultTimeOffset = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultTimeStep(int value)
{
    dfRouterDefaultTimeStep = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultCalibratorOutput(bool value)
{
    dfRouterDefaultCalibratorOutput = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultIncludeUnusedRoutes(bool value)
{
    dfRouterDefaultIncludeUnusedRoutes = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultRevalidateFlows(bool value)
{
    dfRouterDefaultRevalidateFlows = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultRemoveEmptyDetectors(bool value)
{
    dfRouterDefaultRemoveEmptyDetectors = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultStrictSources(bool value)
{
    dfRouterDefaultStrictSources = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultRespectConcurrentInflows(bool value)
{
    dfRouterDefaultRespectConcurrentInflows = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultScale(qreal value)
{
    dfRouterDefaultScale = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultDepartlane(const QString &value)
{
    dfRouterDefaultDepartlane = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultDepartpos(const QString &value)
{
    dfRouterDefaultDepartpos = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultDepartspeed(const QString &value)
{
    dfRouterDefaultDepartspeed = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultArrivallane(const QString &value)
{
    dfRouterDefaultArrivallane = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultArrivalpos(const QString &value)
{
    dfRouterDefaultArrivalpos = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultArrivalspeed(const QString &value)
{
    dfRouterDefaultArrivalspeed = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultBegin(int value)
{
    dfRouterDefaultBegin = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultEnd(int value)
{
    dfRouterDefaultEnd = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultVerbose(bool value)
{
    dfRouterDefaultVerbose = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultPrintOptions(bool value)
{
    dfRouterDefaultPrintOptions = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultHelp(bool value)
{
    dfRouterDefaultHelp = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultVersion(bool value)
{
    dfRouterDefaultVersion = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultXmlValidation(const QString &value)
{
    dfRouterDefaultXmlValidation = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultXmlValidationNet(const QString &value)
{
    dfRouterDefaultXmlValidationNet = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultNoWarnings(bool value)
{
    dfRouterDefaultNoWarnings = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultLog(const QString &value)
{
    dfRouterDefaultLog = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultMessageLog(const QString &value)
{
    dfRouterDefaultMessageLog = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultErrorLog(const QString &value)
{
    dfRouterDefaultErrorLog = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultReportEmptyDetectors(bool value)
{
    dfRouterDefaultReportEmptyDetectors = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultPrintAbsoluteFlows(bool value)
{
    dfRouterDefaultPrintAbsoluteFlows = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultNoStepLog(bool value)
{
    dfRouterDefaultNoStepLog = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultRandom(bool value)
{
    dfRouterDefaultRandom = value;
}

void dfRouterToolConfiguration::setDfRouterDefaultSeed(int value)
{
    dfRouterDefaultSeed = value;
}
