#include "jtrRouterToolConfiguration.h"

jtrRouterToolConfiguration::jtrRouterToolConfiguration() : eNetEditorToolConfiguration(0, 0, 0 /** arreglar **/)
{
    setOutputfolder("jtrRouter");

    jtrRouterDefaultNetFile = "net";

    jtrRouterDefaultAdditionalFiles = "additionals";

    jtrRouterDefaultAlternativeFiles = "alternatives";

    jtrRouterDefaultFlowFiles = "flows";

    jtrRouterDefaultTurnRatioFiles = "turnRatios";

    jtrRouterDefaultOutputPrefix = "";

    jtrRouterDefaultOutputFile = "jtrRouter.output";

    jtrRouterDefaultVtypeOutput = "jtrRouter.vehicleTypeOutput";

    jtrRouterDefaultExitTimes = false;

    jtrRouterDefaultIgnoreErrors = false;

    jtrRouterDefaultUnsortedInput = false;

    jtrRouterDefaultRouteSteps = 200;

    jtrRouterDefaultRandomizeFlows = false;

    jtrRouterDefaultMaxAlternatives = 5;

    jtrRouterDefaultRemoveLoops = false;

    jtrRouterDefaultRepair = false;

    jtrRouterDefaultWeightsInterpolate = false;

    jtrRouterDefaultWithTaz = false;

    jtrRouterDefaultRoutingThreads = 0;

    jtrRouterDefaultMaxEdgesFactor = 2;

    jtrRouterDefaultAcceptAllDestinations = false;

    jtrRouterDefaultIgnoreVclasses = false;

    jtrRouterDefaultAllowLoops = false;

    jtrRouterDefaultDefaultsOverride = false;

    jtrRouterDefaultBegin = 0;

    jtrRouterDefaultEnd = 655535; /** OJO **/

    jtrRouterDefaultVerbose = false;

    jtrRouterDefaultPrintOptions = false;

    jtrRouterDefaultHelp = false;

    jtrRouterDefaultVersion = false;

    jtrRouterDefaultXmlValidation = "auto";

    jtrRouterDefaultXmlValidationNet = "never";

    jtrRouterDefaultNoWarnings = false;

    jtrRouterDefaultLog = "jtrRouter.log";

    jtrRouterDefaultMessageLog = "jtrRouter.messageLog";

    jtrRouterDefaultErrorLog = "jtrRouter.errorLog";

    jtrRouterDefaultStatsPeriod = -1;

    jtrRouterDefaultNoStepLog = false;

    jtrRouterDefaultRandom = false;

    jtrRouterDefaultSeed = 23423;
}

jtrRouterToolConfiguration::~jtrRouterToolConfiguration()
{
    // Nothing to erase
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultNetFile() const
{
    return jtrRouterDefaultNetFile;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultAdditionalFiles() const
{
    return jtrRouterDefaultAdditionalFiles;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultAlternativeFiles() const
{
    return jtrRouterDefaultAlternativeFiles;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultFlowFiles() const
{
    return jtrRouterDefaultFlowFiles;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultTurnRatioFiles() const
{
    return jtrRouterDefaultTurnRatioFiles;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultOutputPrefix() const
{
    return jtrRouterDefaultOutputPrefix;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultOutputFile() const
{
    return jtrRouterDefaultOutputFile;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultVtypeOutput() const
{
    return jtrRouterDefaultVtypeOutput;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultExitTimes() const
{
    return jtrRouterDefaultExitTimes;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultIgnoreErrors() const
{
    return jtrRouterDefaultIgnoreErrors;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultUnsortedInput() const
{
    return jtrRouterDefaultUnsortedInput;
}

int jtrRouterToolConfiguration::getJtrRouterDefaultRouteSteps() const
{
    return jtrRouterDefaultRouteSteps;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultRandomizeFlows() const
{
    return jtrRouterDefaultRandomizeFlows;
}

int jtrRouterToolConfiguration::getJtrRouterDefaultMaxAlternatives() const
{
    return jtrRouterDefaultMaxAlternatives;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultRemoveLoops() const
{
    return jtrRouterDefaultRemoveLoops;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultRepair() const
{
    return jtrRouterDefaultRepair;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultWeightsInterpolate() const
{
    return jtrRouterDefaultWeightsInterpolate;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultWithTaz() const
{
    return jtrRouterDefaultWithTaz;
}

int jtrRouterToolConfiguration::getJtrRouterDefaultRoutingThreads() const
{
    return jtrRouterDefaultRoutingThreads;
}

qreal jtrRouterToolConfiguration::getJtrRouterDefaultMaxEdgesFactor() const
{
    return jtrRouterDefaultMaxEdgesFactor;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultTurnDefaults() const
{
    return jtrRouterDefaultTurnDefaults;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultSinkEdges() const
{
    return jtrRouterDefaultSinkEdges;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultAcceptAllDestinations() const
{
    return jtrRouterDefaultAcceptAllDestinations;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultIgnoreVclasses() const
{
    return jtrRouterDefaultIgnoreVclasses;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultAllowLoops() const
{
    return jtrRouterDefaultAllowLoops;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultDepartlane() const
{
    return jtrRouterDefaultDepartlane;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultDepartpos() const
{
    return jtrRouterDefaultDepartpos;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultDepartspeed() const
{
    return jtrRouterDefaultDepartspeed;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultArrivallane() const
{
    return jtrRouterDefaultArrivallane;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultArrivalpos() const
{
    return jtrRouterDefaultArrivalpos;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultArrivalspeed() const
{
    return jtrRouterDefaultArrivalspeed;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultDefaultsOverride() const
{
    return jtrRouterDefaultDefaultsOverride;
}

int jtrRouterToolConfiguration::getJtrRouterDefaultBegin() const
{
    return jtrRouterDefaultBegin;
}

int jtrRouterToolConfiguration::getJtrRouterDefaultEnd() const
{
    return jtrRouterDefaultEnd;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultVerbose() const
{
    return jtrRouterDefaultVerbose;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultPrintOptions() const
{
    return jtrRouterDefaultPrintOptions;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultHelp() const
{
    return jtrRouterDefaultHelp;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultVersion() const
{
    return jtrRouterDefaultVersion;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultXmlValidation() const
{
    return jtrRouterDefaultXmlValidation;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultXmlValidationNet() const
{
    return jtrRouterDefaultXmlValidationNet;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultNoWarnings() const
{
    return jtrRouterDefaultNoWarnings;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultLog() const
{
    return jtrRouterDefaultLog;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultMessageLog() const
{
    return jtrRouterDefaultMessageLog;
}

const QString &jtrRouterToolConfiguration::getJtrRouterDefaultErrorLog() const
{
    return jtrRouterDefaultErrorLog;
}

int jtrRouterToolConfiguration::getJtrRouterDefaultStatsPeriod() const
{
    return jtrRouterDefaultStatsPeriod;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultNoStepLog() const
{
    return jtrRouterDefaultNoStepLog;
}

bool jtrRouterToolConfiguration::getJtrRouterDefaultRandom() const
{
    return jtrRouterDefaultRandom;
}

int jtrRouterToolConfiguration::getJtrRouterDefaultSeed() const
{
    return jtrRouterDefaultSeed;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultNetFile(const QString &value)
{
    jtrRouterDefaultNetFile = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultAdditionalFiles(const QString &value)
{
    jtrRouterDefaultAdditionalFiles = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultAlternativeFiles(const QString &value)
{
    jtrRouterDefaultAlternativeFiles = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultFlowFiles(const QString &value)
{
    jtrRouterDefaultFlowFiles = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultTurnRatioFiles(const QString &value)
{
    jtrRouterDefaultTurnRatioFiles = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultOutputPrefix(const QString &value)
{
    jtrRouterDefaultOutputPrefix = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultOutputFile(const QString &value)
{
    jtrRouterDefaultOutputFile = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultVtypeOutput(const QString &value)
{
    jtrRouterDefaultVtypeOutput = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultExitTimes(bool value)
{
    jtrRouterDefaultExitTimes = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultIgnoreErrors(bool value)
{
    jtrRouterDefaultIgnoreErrors = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultUnsortedInput(bool value)
{
    jtrRouterDefaultUnsortedInput = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultRouteSteps(int value)
{
    jtrRouterDefaultRouteSteps = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultRandomizeFlows(bool value)
{
    jtrRouterDefaultRandomizeFlows = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultMaxAlternatives(int value)
{
    jtrRouterDefaultMaxAlternatives = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultRemoveLoops(bool value)
{
    jtrRouterDefaultRemoveLoops = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultRepair(bool value)
{
    jtrRouterDefaultRepair = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultWeightsInterpolate(bool value)
{
    jtrRouterDefaultWeightsInterpolate = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultWithTaz(bool value)
{
    jtrRouterDefaultWithTaz = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultRoutingThreads(int value)
{
    jtrRouterDefaultRoutingThreads = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultMaxEdgesFactor(qreal value)
{
    jtrRouterDefaultMaxEdgesFactor = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultTurnDefaults(const QString &value)
{
    jtrRouterDefaultTurnDefaults = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultSinkEdges(const QString &value)
{
    jtrRouterDefaultSinkEdges = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultAcceptAllDestinations(bool value)
{
    jtrRouterDefaultAcceptAllDestinations = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultIgnoreVclasses(bool value)
{
    jtrRouterDefaultIgnoreVclasses = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultAllowLoops(bool value)
{
    jtrRouterDefaultAllowLoops = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultDepartlane(const QString &value)
{
    jtrRouterDefaultDepartlane = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultDepartpos(const QString &value)
{
    jtrRouterDefaultDepartpos = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultDepartspeed(const QString &value)
{
    jtrRouterDefaultDepartspeed = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultArrivallane(const QString &value)
{
    jtrRouterDefaultArrivallane = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultArrivalpos(const QString &value)
{
    jtrRouterDefaultArrivalpos = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultArrivalspeed(const QString &value)
{
    jtrRouterDefaultArrivalspeed = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultDefaultsOverride(bool value)
{
    jtrRouterDefaultDefaultsOverride = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultBegin(int value)
{
    jtrRouterDefaultBegin = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultEnd(int value)
{
    jtrRouterDefaultEnd = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultVerbose(bool value)
{
    jtrRouterDefaultVerbose = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultPrintOptions(bool value)
{
    jtrRouterDefaultPrintOptions = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultHelp(bool value)
{
    jtrRouterDefaultHelp = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultVersion(bool value)
{
    jtrRouterDefaultVersion = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultXmlValidation(const QString &value)
{
    jtrRouterDefaultXmlValidation = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultXmlValidationNet(const QString &value)
{
    jtrRouterDefaultXmlValidationNet = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultNoWarnings(bool value)
{
    jtrRouterDefaultNoWarnings = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultLog(const QString &value)
{
    jtrRouterDefaultLog = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultMessageLog(const QString &value)
{
    jtrRouterDefaultMessageLog = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultErrorLog(const QString &value)
{
    jtrRouterDefaultErrorLog = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultStatsPeriod(int value)
{
    jtrRouterDefaultStatsPeriod = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultNoStepLog(bool value)
{
    jtrRouterDefaultNoStepLog = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultRandom(bool value)
{
    jtrRouterDefaultRandom = value;
}

void jtrRouterToolConfiguration::setJtrRouterDefaultSeed(int value)
{
    jtrRouterDefaultSeed = value;
}
