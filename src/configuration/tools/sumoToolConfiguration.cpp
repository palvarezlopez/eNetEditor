#include "sumoToolConfiguration.h"

sumoToolConfiguration::sumoToolConfiguration() : eNetEditorToolConfiguration(0, 0, 0 /** arreglar **/)
{
    setOutputfolder("sumo");

    // Load road network description from FILE
    sumoDefaultNetFile;

    // Load routes descriptions from FILE(s)
    sumoDefaultRouteFiles;

    // Load further descriptions from FILE(s)
    sumoDefaultAdditionalFiles;

    // Load edge/lane weights for online rerouting from FILE
    sumoDefaultWeightFiles;

    // Name of the xml attribute which gives the edge weight; default: traveltime
    sumoDefaultWeightAttribute;

    // Loads a network state from FILE
    sumoDefaultLoadState;

    sumoDefaultLoadStateOffset = 0;

    // Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    sumoDefaultOutputPrefix;

    // Save complete network states into FILE
    sumoDefaultNetstateDump;

    sumoDefaultNetstateDumpEmptyEdges = false;

    sumoDefaultNetstateDumpPrecision = 2;

    // Save the emission values of each vehicle
    sumoDefaultEmissionOutput;

    // Save the Floating Car Data
    sumoDefaultFcdOutput;

    sumoDefaultFcdOutputGeo = false;

    sumoDefaultFcdOutputSignals = false;

    // Save a lot of information for each timestep (very redundant)
    sumoDefaultFullOutput;

    // Save the vehicle queues at the junctions (experimental)
    sumoDefaultQueueOutput;

    // Save complete vehicle positions inclusive speed values in the VTK Format (usage: /path/out will produce /path/out_$TIMESTEP$Vtp files)
    sumoDefaultVtkOutput;

    // Save the vehicle trajectories in the Amitran format
    sumoDefaultAmitranOutput;

    // Save aggregated vehicle departure info into FILE
    sumoDefaultSummaryOutput;

    // Save single vehicle trip info into FILE
    sumoDefaultTripinfoOutput;

    sumoDefaultTripinfoOutputWriteUnfinished = false;

    // Save single vehicle route info into FILE
    sumoDefaultVehrouteOutput;

    sumoDefaultVehrouteOutputExitTimes = false;

    sumoDefaultVehrouteOutputLastRoute = false;

    sumoDefaultVehrouteOutputSorted = false;

    sumoDefaultVehrouteOutputDua = false;

    sumoDefaultVehrouteOutputIntendedDepart = false;

    sumoDefaultVehrouteOutputWriteUnfinished = false;

    // Save links states into FILE
    sumoDefaultLinkOutput;

    // Save bt visibilities into FILE
    sumoDefaultBtOutput;

    // Use INT[] as times at which a network state written
    sumoDefaultSaveStateTimes;

    // Prefix for network states; default: state
    sumoDefaultSaveStatePrefix;

    // Files for network states
    sumoDefaultSaveStateFiles;

    sumoDefaultBegin = 0;

    sumoDefaultEnd = -1;

    sumoDefaultStepLength = 1;

    sumoDefaultRouteSteps = 200;

    sumoDefaultNoInternalLinks = false;

    sumoDefaultIgnoreJunctionBlocker = -1;

    sumoDefaultIgnoreAccidents = false;

    sumoDefaultIgnoreRouteErrors = false;

    sumoDefaultMaxNumVehicles = -1;

    // Scale demand by the given factor (by discarding or duplicating vehicles)
    sumoDefaultScale;

    sumoDefaultTimeToTeleport = 300;

    sumoDefaultTimeToTeleportHighways = 0;

    sumoDefaultMaxDepartDelay = -1;

    sumoDefaultSloppyInsert = false;

    sumoDefaultEagerInsert = false;

    sumoDefaultRandomDepartOffset = 0;

    sumoDefaultLanechangeAllowSwap = false;

    sumoDefaultLanechangeDuration = 0;

    sumoDefaultLanechangeOvertakeRight = false;

    sumoDefaultPedestrianModel = "striping";

    sumoDefaultPedestrianStripingStripeWidth = 0.65;

    sumoDefaultPedestrianStripingDawdling = 0.2;

    sumoDefaultPedestrianStripingJamtime = 300;

    sumoDefaultRoutingAlgorithm = "dijkstra";

    // Edge weights for routing are dynamically disturbed by a random factor between [1,FLOAT]
    sumoDefaultWeightsRandomFactor;

    sumoDefaultDeviceReroutingProbability = 0;

    // Assign a 'rerouting' device to named vehicles
    sumoDefaultDeviceReroutingExplicit;

    sumoDefaultDeviceReroutingDeterministic = false;

    sumoDefaultDeviceReroutingPeriod = 0;

    sumoDefaultDeviceReroutingPrePeriod = 1;

    sumoDefaultDeviceReroutingAdaptationWeight = 0.5;

    sumoDefaultDeviceReroutingAdaptationInterval = 1;

    sumoDefaultDeviceReroutingWithTaz = false;

    sumoDefaultDeviceReroutingInitWithLoadedWeights = false;

    // Initialize lookup table for astar from the given distance matrix
    sumoDefaultDeviceReroutingShortestPathFile;

    sumoDefaultDeviceReroutingThreads = 0;

    // Save adapting weights to FILE
    sumoDefaultDeviceReroutingOutput;

    sumoDefaultVerbose = false;

    sumoDefaultPrintOptions = false;

    sumoDefaultHelp = false;

    sumoDefaultVersion = false;

    sumoDefaultXmlValidation = "auto";

    sumoDefaultXmlValidationNet = "never";

    sumoDefaultNoWarnings = false;

    sumoDefaultLog = "sumo.log";

    sumoDefaultMessageLog = "sumo.messageLog";

    sumoDefaultErrorLog = "sumo.errorLog";

    sumoDefaultNoDurationLog = false;

    sumoDefaultNoStepLog = false;

    sumoDefaultPhemlightPath = "./PHEMlight/";

    sumoDefaultDeviceEmissionsProbability = 0;

    sumoDefaultDeviceEmissionsExplicit = "";

    sumoDefaultDeviceEmissionsDeterministic = false;

    sumoDefaultDeviceBtreceiverProbability = 0;

    sumoDefaultDeviceBtreceiverExplicit = "";

    sumoDefaultDeviceBtreceiverDeterministic = false;

    sumoDefaultDeviceBtreceiverRange = 300;

    sumoDefaultDeviceBtreceiverAllRecognitions = false;

    sumoDefaultDeviceBtreceiverOfftime = 0.64;

    sumoDefaultDeviceBtsenderProbability = 0;

    sumoDefaultDeviceBtsenderExplicit = "";

    sumoDefaultDeviceBtsenderDeterministic = false;

    sumoDefaultDeviceExampleExplicit = "";

    sumoDefaultDeviceExampleParameter = 0;

    sumoDefaultRemotePort = 0;

    sumoDefaultRandom = false;

    sumoDefaultSeed = 23423;
}

sumoToolConfiguration::~sumoToolConfiguration()
{
    // Nothing to erase
}

const QString &sumoToolConfiguration::getSumoDefaultNetFile() const
{
    return sumoDefaultNetFile;
}

const QString &sumoToolConfiguration::getSumoDefaultRouteFiles() const
{
    return sumoDefaultRouteFiles;
}

const QString &sumoToolConfiguration::getSumoDefaultAdditionalFiles() const
{
    return sumoDefaultAdditionalFiles;
}

const QString &sumoToolConfiguration::getSumoDefaultWeightFiles() const
{
    return sumoDefaultWeightFiles;
}

const QString &sumoToolConfiguration::getSumoDefaultWeightAttribute() const
{
    return sumoDefaultWeightAttribute;
}

const QString &sumoToolConfiguration::getSumoDefaultLoadState() const
{
    return sumoDefaultLoadState;
}

int sumoToolConfiguration::getSumoDefaultLoadStateOffset() const
{
    return sumoDefaultLoadStateOffset;
}

const QString &sumoToolConfiguration::getSumoDefaultOutputPrefix() const
{
    return sumoDefaultOutputPrefix;
}

const QString &sumoToolConfiguration::getSumoDefaultNetstateDump() const
{
    return sumoDefaultNetstateDump;
}

bool sumoToolConfiguration::getSumoDefaultNetstateDumpEmptyEdges() const
{
    return sumoDefaultNetstateDumpEmptyEdges;
}

int sumoToolConfiguration::getSumoDefaultNetstateDumpPrecision() const
{
    return sumoDefaultNetstateDumpPrecision;
}

const QString &sumoToolConfiguration::getSumoDefaultEmissionOutput() const
{
    return sumoDefaultEmissionOutput;
}

const QString &sumoToolConfiguration::getSumoDefaultFcdOutput() const
{
    return sumoDefaultFcdOutput;
}

bool sumoToolConfiguration::getSumoDefaultFcdOutputGeo() const
{
    return sumoDefaultFcdOutputGeo;
}

bool sumoToolConfiguration::getSumoDefaultFcdOutputSignals() const
{
    return sumoDefaultFcdOutputSignals;
}

const QString &sumoToolConfiguration::getSumoDefaultFullOutput() const
{
    return sumoDefaultFullOutput;
}

const QString &sumoToolConfiguration::getSumoDefaultQueueOutput() const
{
    return sumoDefaultQueueOutput;
}

const QString &sumoToolConfiguration::getSumoDefaultVtkOutput() const
{
    return sumoDefaultVtkOutput;
}

const QString &sumoToolConfiguration::getSumoDefaultAmitranOutput() const
{
    return sumoDefaultAmitranOutput;
}

const QString &sumoToolConfiguration::getSumoDefaultSummaryOutput() const
{
    return sumoDefaultSummaryOutput;
}

const QString &sumoToolConfiguration::getSumoDefaultTripinfoOutput() const
{
    return sumoDefaultTripinfoOutput;
}

bool sumoToolConfiguration::getSumoDefaultTripinfoOutputWriteUnfinished() const
{
    return sumoDefaultTripinfoOutputWriteUnfinished;
}

const QString &sumoToolConfiguration::getSumoDefaultVehrouteOutput() const
{
    return sumoDefaultVehrouteOutput;
}

bool sumoToolConfiguration::getSumoDefaultVehrouteOutputExitTimes() const
{
    return sumoDefaultVehrouteOutputExitTimes;
}

bool sumoToolConfiguration::getSumoDefaultVehrouteOutputLastRoute() const
{
    return sumoDefaultVehrouteOutputLastRoute;
}

bool sumoToolConfiguration::getSumoDefaultVehrouteOutputSorted() const
{
    return sumoDefaultVehrouteOutputSorted;
}

bool sumoToolConfiguration::getSumoDefaultVehrouteOutputDua() const
{
    return sumoDefaultVehrouteOutputDua;
}

bool sumoToolConfiguration::getSumoDefaultVehrouteOutputIntendedDepart() const
{
    return sumoDefaultVehrouteOutputIntendedDepart;
}

bool sumoToolConfiguration::getSumoDefaultVehrouteOutputWriteUnfinished() const
{
    return sumoDefaultVehrouteOutputWriteUnfinished;
}

const QString &sumoToolConfiguration::getSumoDefaultLinkOutput() const
{
    return sumoDefaultLinkOutput;
}

const QString &sumoToolConfiguration::getSumoDefaultBtOutput() const
{
    return sumoDefaultBtOutput;
}

int sumoToolConfiguration::getSumoDefaultSaveStateTimes() const
{
    return sumoDefaultSaveStateTimes;
}

const QString &sumoToolConfiguration::getSumoDefaultSaveStatePrefix() const
{
    return sumoDefaultSaveStatePrefix;
}

const QString &sumoToolConfiguration::getSumoDefaultSaveStateFiles() const
{
    return sumoDefaultSaveStateFiles;
}

int sumoToolConfiguration::getSumoDefaultBegin() const
{
    return sumoDefaultBegin;
}

int sumoToolConfiguration::getSumoDefaultEnd() const
{
    return sumoDefaultEnd;
}

int sumoToolConfiguration::getSumoDefaultStepLength() const
{
    return sumoDefaultStepLength;
}

int sumoToolConfiguration::getSumoDefaultRouteSteps() const
{
    return sumoDefaultRouteSteps;
}

bool sumoToolConfiguration::getSumoDefaultNoInternalLinks() const
{
    return sumoDefaultNoInternalLinks;
}

int sumoToolConfiguration::getSumoDefaultIgnoreJunctionBlocker() const
{
    return sumoDefaultIgnoreJunctionBlocker;
}

bool sumoToolConfiguration::getSumoDefaultIgnoreAccidents() const
{
    return sumoDefaultIgnoreAccidents;
}

bool sumoToolConfiguration::getSumoDefaultIgnoreRouteErrors() const
{
    return sumoDefaultIgnoreRouteErrors;
}

int sumoToolConfiguration::getSumoDefaultMaxNumVehicles() const
{
    return sumoDefaultMaxNumVehicles;
}

qreal sumoToolConfiguration::getSumoDefaultScale() const
{
    return sumoDefaultScale;
}

int sumoToolConfiguration::getSumoDefaultTimeToTeleport() const
{
    return sumoDefaultTimeToTeleport;
}

int sumoToolConfiguration::getSumoDefaultTimeToTeleportHighways() const
{
    return sumoDefaultTimeToTeleportHighways;
}

int sumoToolConfiguration::getSumoDefaultMaxDepartDelay() const
{
    return sumoDefaultMaxDepartDelay;
}

bool sumoToolConfiguration::getSumoDefaultSloppyInsert() const
{
    return sumoDefaultSloppyInsert;
}

bool sumoToolConfiguration::getSumoDefaultEagerInsert() const
{
    return sumoDefaultEagerInsert;
}

int sumoToolConfiguration::getSumoDefaultRandomDepartOffset() const
{
    return sumoDefaultRandomDepartOffset;
}

bool sumoToolConfiguration::getSumoDefaultLanechangeAllowSwap() const
{
    return sumoDefaultLanechangeAllowSwap;
}

int sumoToolConfiguration::getSumoDefaultLanechangeDuration() const
{
    return sumoDefaultLanechangeDuration;
}

bool sumoToolConfiguration::getSumoDefaultLanechangeOvertakeRight() const
{
    return sumoDefaultLanechangeOvertakeRight;
}

const QString &sumoToolConfiguration::getSumoDefaultPedestrianModel() const
{
    return sumoDefaultPedestrianModel;
}

qreal sumoToolConfiguration::getSumoDefaultPedestrianStripingStripeWidth() const
{
    return sumoDefaultPedestrianStripingStripeWidth;
}

qreal sumoToolConfiguration::getSumoDefaultPedestrianStripingDawdling() const
{
    return sumoDefaultPedestrianStripingDawdling;
}

int sumoToolConfiguration::getSumoDefaultPedestrianStripingJamtime() const
{
    return sumoDefaultPedestrianStripingJamtime;
}

const QString &sumoToolConfiguration::getSumoDefaultRoutingAlgorithm() const
{
    return sumoDefaultRoutingAlgorithm;
}

qreal sumoToolConfiguration::getSumoDefaultWeightsRandomFactor() const
{
    return sumoDefaultWeightsRandomFactor;
}

qreal sumoToolConfiguration::getSumoDefaultDeviceReroutingProbability() const
{
    return sumoDefaultDeviceReroutingProbability;
}

const QString &sumoToolConfiguration::getSumoDefaultDeviceReroutingExplicit() const
{
    return sumoDefaultDeviceReroutingExplicit;
}

bool sumoToolConfiguration::getSumoDefaultDeviceReroutingDeterministic() const
{
    return sumoDefaultDeviceReroutingDeterministic;
}

int sumoToolConfiguration::getSumoDefaultDeviceReroutingPeriod() const
{
    return sumoDefaultDeviceReroutingPeriod;
}

int sumoToolConfiguration::getSumoDefaultDeviceReroutingPrePeriod() const
{
    return sumoDefaultDeviceReroutingPrePeriod;
}

qreal sumoToolConfiguration::getSumoDefaultDeviceReroutingAdaptationWeight() const
{
    return sumoDefaultDeviceReroutingAdaptationWeight;
}

int sumoToolConfiguration::getSumoDefaultDeviceReroutingAdaptationInterval() const
{
    return sumoDefaultDeviceReroutingAdaptationInterval;
}

bool sumoToolConfiguration::getSumoDefaultDeviceReroutingWithTaz() const
{
    return sumoDefaultDeviceReroutingWithTaz;
}

bool sumoToolConfiguration::getSumoDefaultDeviceReroutingInitWithLoadedWeights() const
{
    return sumoDefaultDeviceReroutingInitWithLoadedWeights;
}

const QString &sumoToolConfiguration::getSumoDefaultDeviceReroutingShortestPathFile() const
{
    return sumoDefaultDeviceReroutingShortestPathFile;
}

int sumoToolConfiguration::getSumoDefaultDeviceReroutingThreads() const
{
    return sumoDefaultDeviceReroutingThreads;
}

const QString &sumoToolConfiguration::getSumoDefaultDeviceReroutingOutput() const
{
    return sumoDefaultDeviceReroutingOutput;
}

bool sumoToolConfiguration::getSumoDefaultVerbose() const
{
    return sumoDefaultVerbose;
}

bool sumoToolConfiguration::getSumoDefaultPrintOptions() const
{
    return sumoDefaultPrintOptions;
}

bool sumoToolConfiguration::getSumoDefaultHelp() const
{
    return sumoDefaultHelp;
}

bool sumoToolConfiguration::getSumoDefaultVersion() const
{
    return sumoDefaultVersion;
}

const QString &sumoToolConfiguration::getSumoDefaultXmlValidation() const
{
    return sumoDefaultXmlValidation;
}

const QString &sumoToolConfiguration::getSumoDefaultXmlValidationNet() const
{
    return sumoDefaultXmlValidationNet;
}

bool sumoToolConfiguration::getSumoDefaultNoWarnings() const
{
    return sumoDefaultNoWarnings;
}

const QString &sumoToolConfiguration::getSumoDefaultLog() const
{
    return sumoDefaultLog;
}

const QString &sumoToolConfiguration::getSumoDefaultMessageLog() const
{
    return sumoDefaultMessageLog;
}

const QString &sumoToolConfiguration::getSumoDefaultErrorLog() const
{
    return sumoDefaultErrorLog;
}

bool sumoToolConfiguration::getSumoDefaultNoDurationLog() const
{
    return sumoDefaultNoDurationLog;
}

bool sumoToolConfiguration::getSumoDefaultNoStepLog() const
{
    return sumoDefaultNoStepLog;
}

const QString &sumoToolConfiguration::getSumoDefaultPhemlightPath() const
{
    return sumoDefaultPhemlightPath;
}

qreal sumoToolConfiguration::getSumoDefaultDeviceEmissionsProbability() const
{
    return sumoDefaultDeviceEmissionsProbability;
}

const QString &sumoToolConfiguration::getSumoDefaultDeviceEmissionsExplicit() const
{
    return sumoDefaultDeviceEmissionsExplicit;
}

bool sumoToolConfiguration::getSumoDefaultDeviceEmissionsDeterministic() const
{
    return sumoDefaultDeviceEmissionsDeterministic;
}

qreal sumoToolConfiguration::getSumoDefaultDeviceBtreceiverProbability() const
{
    return sumoDefaultDeviceBtreceiverProbability;
}

const QString &sumoToolConfiguration::getSumoDefaultDeviceBtreceiverExplicit() const
{
    return sumoDefaultDeviceBtreceiverExplicit;
}

bool sumoToolConfiguration::getSumoDefaultDeviceBtreceiverDeterministic() const
{
    return sumoDefaultDeviceBtreceiverDeterministic;
}

qreal sumoToolConfiguration::getSumoDefaultDeviceBtreceiverRange() const
{
    return sumoDefaultDeviceBtreceiverRange;
}

bool sumoToolConfiguration::getSumoDefaultDeviceBtreceiverAllRecognitions() const
{
    return sumoDefaultDeviceBtreceiverAllRecognitions;
}

qreal sumoToolConfiguration::getSumoDefaultDeviceBtreceiverOfftime() const
{
    return sumoDefaultDeviceBtreceiverOfftime;
}

qreal sumoToolConfiguration::getSumoDefaultDeviceBtsenderProbability() const
{
    return sumoDefaultDeviceBtsenderProbability;
}

const QString &sumoToolConfiguration::getSumoDefaultDeviceBtsenderExplicit() const
{
    return sumoDefaultDeviceBtsenderExplicit;
}

bool sumoToolConfiguration::getSumoDefaultDeviceBtsenderDeterministic() const
{
    return sumoDefaultDeviceBtsenderDeterministic;
}

const QString &sumoToolConfiguration::getSumoDefaultDeviceExampleExplicit() const
{
    return sumoDefaultDeviceExampleExplicit;
}

qreal sumoToolConfiguration::getSumoDefaultDeviceExampleParameter() const
{
    return sumoDefaultDeviceExampleParameter;
}

int sumoToolConfiguration::getSumoDefaultRemotePort() const
{
    return sumoDefaultRemotePort;
}

bool sumoToolConfiguration::getSumoDefaultRandom() const
{
    return sumoDefaultRandom;
}

int sumoToolConfiguration::getSumoDefaultSeed() const
{
    return sumoDefaultSeed;
}

void sumoToolConfiguration::setSumoDefaultNetFile(const QString &value)
{
    sumoDefaultNetFile = value;
}

void sumoToolConfiguration::setSumoDefaultRouteFiles(const QString &value)
{
    sumoDefaultRouteFiles = value;
}

void sumoToolConfiguration::setSumoDefaultAdditionalFiles(const QString &value)
{
    sumoDefaultAdditionalFiles = value;
}

void sumoToolConfiguration::setSumoDefaultWeightFiles(const QString &value)
{
    sumoDefaultWeightFiles = value;
}

void sumoToolConfiguration::setSumoDefaultWeightAttribute(const QString &value)
{
    sumoDefaultWeightAttribute = value;
}

void sumoToolConfiguration::setSumoDefaultLoadState(const QString &value)
{
    sumoDefaultLoadState = value;
}

void sumoToolConfiguration::setSumoDefaultLoadStateOffset(int value)
{
    sumoDefaultLoadStateOffset = value;
}

void sumoToolConfiguration::setSumoDefaultOutputPrefix(const QString &value)
{
    sumoDefaultOutputPrefix = value;
}

void sumoToolConfiguration::setSumoDefaultNetstateDump(const QString &value)
{
    sumoDefaultNetstateDump = value;
}

void sumoToolConfiguration::setSumoDefaultNetstateDumpEmptyEdges(bool value)
{
    sumoDefaultNetstateDumpEmptyEdges = value;
}

void sumoToolConfiguration::setSumoDefaultNetstateDumpPrecision(int value)
{
    sumoDefaultNetstateDumpPrecision = value;
}

void sumoToolConfiguration::setSumoDefaultEmissionOutput(const QString &value)
{
    sumoDefaultEmissionOutput = value;
}

void sumoToolConfiguration::setSumoDefaultFcdOutput(const QString &value)
{
    sumoDefaultFcdOutput = value;
}

void sumoToolConfiguration::setSumoDefaultFcdOutputGeo(bool value)
{
    sumoDefaultFcdOutputGeo = value;
}

void sumoToolConfiguration::setSumoDefaultFcdOutputSignals(bool value)
{
    sumoDefaultFcdOutputSignals = value;
}

void sumoToolConfiguration::setSumoDefaultFullOutput(const QString &value)
{
    sumoDefaultFullOutput = value;
}

void sumoToolConfiguration::setSumoDefaultQueueOutput(const QString &value)
{
    sumoDefaultQueueOutput = value;
}

void sumoToolConfiguration::setSumoDefaultVtkOutput(const QString &value)
{
    sumoDefaultVtkOutput = value;
}

void sumoToolConfiguration::setSumoDefaultAmitranOutput(const QString &value)
{
    sumoDefaultAmitranOutput = value;
}

void sumoToolConfiguration::setSumoDefaultSummaryOutput(const QString &value)
{
    sumoDefaultSummaryOutput = value;
}

void sumoToolConfiguration::setSumoDefaultTripinfoOutput(const QString &value)
{
    sumoDefaultTripinfoOutput = value;
}

void sumoToolConfiguration::setSumoDefaultTripinfoOutputWriteUnfinished(bool value)
{
    sumoDefaultTripinfoOutputWriteUnfinished = value;
}

void sumoToolConfiguration::setSumoDefaultVehrouteOutput(const QString &value)
{
    sumoDefaultVehrouteOutput = value;
}

void sumoToolConfiguration::setSumoDefaultVehrouteOutputExitTimes(bool value)
{
    sumoDefaultVehrouteOutputExitTimes = value;
}

void sumoToolConfiguration::setSumoDefaultVehrouteOutputLastRoute(bool value)
{
    sumoDefaultVehrouteOutputLastRoute = value;
}

void sumoToolConfiguration::setSumoDefaultVehrouteOutputSorted(bool value)
{
    sumoDefaultVehrouteOutputSorted = value;
}

void sumoToolConfiguration::setSumoDefaultVehrouteOutputDua(bool value)
{
    sumoDefaultVehrouteOutputDua = value;
}

void sumoToolConfiguration::setSumoDefaultVehrouteOutputIntendedDepart(bool value)
{
    sumoDefaultVehrouteOutputIntendedDepart = value;
}

void sumoToolConfiguration::setSumoDefaultVehrouteOutputWriteUnfinished(bool value)
{
    sumoDefaultVehrouteOutputWriteUnfinished = value;
}

void sumoToolConfiguration::setSumoDefaultLinkOutput(const QString &value)
{
    sumoDefaultLinkOutput = value;
}

void sumoToolConfiguration::setSumoDefaultBtOutput(const QString &value)
{
    sumoDefaultBtOutput = value;
}

void sumoToolConfiguration::setSumoDefaultSaveStateTimes(int value)
{
    sumoDefaultSaveStateTimes = value;
}

void sumoToolConfiguration::setSumoDefaultSaveStatePrefix(const QString &value)
{
    sumoDefaultSaveStatePrefix = value;
}

void sumoToolConfiguration::setSumoDefaultSaveStateFiles(const QString &value)
{
    sumoDefaultSaveStateFiles = value;
}

void sumoToolConfiguration::setSumoDefaultBegin(int value)
{
    sumoDefaultBegin = value;
}

void sumoToolConfiguration::setSumoDefaultEnd(int value)
{
    sumoDefaultEnd = value;
}

void sumoToolConfiguration::setSumoDefaultStepLength(int value)
{
    sumoDefaultStepLength = value;
}

void sumoToolConfiguration::setSumoDefaultRouteSteps(int value)
{
    sumoDefaultRouteSteps = value;
}

void sumoToolConfiguration::setSumoDefaultNoInternalLinks(bool value)
{
    sumoDefaultNoInternalLinks = value;
}

void sumoToolConfiguration::setSumoDefaultIgnoreJunctionBlocker(int value)
{
    sumoDefaultIgnoreJunctionBlocker = value;
}

void sumoToolConfiguration::setSumoDefaultIgnoreAccidents(bool value)
{
    sumoDefaultIgnoreAccidents = value;
}

void sumoToolConfiguration::setSumoDefaultIgnoreRouteErrors(bool value)
{
    sumoDefaultIgnoreRouteErrors = value;
}

void sumoToolConfiguration::setSumoDefaultMaxNumVehicles(int value)
{
    sumoDefaultMaxNumVehicles = value;
}

void sumoToolConfiguration::setSumoDefaultScale(qreal value)
{
    sumoDefaultScale = value;
}

void sumoToolConfiguration::setSumoDefaultTimeToTeleport(int value)
{
    sumoDefaultTimeToTeleport = value;
}

void sumoToolConfiguration::setSumoDefaultTimeToTeleportHighways(int value)
{
    sumoDefaultTimeToTeleportHighways = value;
}

void sumoToolConfiguration::setSumoDefaultMaxDepartDelay(int value)
{
    sumoDefaultMaxDepartDelay = value;
}

void sumoToolConfiguration::setSumoDefaultSloppyInsert(bool value)
{
    sumoDefaultSloppyInsert = value;
}

void sumoToolConfiguration::setSumoDefaultEagerInsert(bool value)
{
    sumoDefaultEagerInsert = value;
}

void sumoToolConfiguration::setSumoDefaultRandomDepartOffset(int value)
{
    sumoDefaultRandomDepartOffset = value;
}

void sumoToolConfiguration::setSumoDefaultLanechangeAllowSwap(bool value)
{
    sumoDefaultLanechangeAllowSwap = value;
}

void sumoToolConfiguration::setSumoDefaultLanechangeDuration(int value)
{
    sumoDefaultLanechangeDuration = value;
}

void sumoToolConfiguration::setSumoDefaultLanechangeOvertakeRight(bool value)
{
    sumoDefaultLanechangeOvertakeRight = value;
}

void sumoToolConfiguration::setSumoDefaultPedestrianModel(const QString &value)
{
    sumoDefaultPedestrianModel = value;
}

void sumoToolConfiguration::setSumoDefaultPedestrianStripingStripeWidth(qreal value)
{
    sumoDefaultPedestrianStripingStripeWidth = value;
}

void sumoToolConfiguration::setSumoDefaultPedestrianStripingDawdling(qreal value)
{
    sumoDefaultPedestrianStripingDawdling = value;
}

void sumoToolConfiguration::setSumoDefaultPedestrianStripingJamtime(int value)
{
    sumoDefaultPedestrianStripingJamtime = value;
}

void sumoToolConfiguration::setSumoDefaultRoutingAlgorithm(const QString &value)
{
    sumoDefaultRoutingAlgorithm = value;
}

void sumoToolConfiguration::setSumoDefaultWeightsRandomFactor(qreal value)
{
    sumoDefaultWeightsRandomFactor = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingProbability(qreal value)
{
    sumoDefaultDeviceReroutingProbability = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingExplicit(const QString &value)
{
    sumoDefaultDeviceReroutingExplicit = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingDeterministic(bool value)
{
    sumoDefaultDeviceReroutingDeterministic = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingPeriod(int value)
{
    sumoDefaultDeviceReroutingPeriod = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingPrePeriod(int value)
{
    sumoDefaultDeviceReroutingPrePeriod = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingAdaptationWeight(qreal value)
{
    sumoDefaultDeviceReroutingAdaptationWeight = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingAdaptationInterval(int value)
{
    sumoDefaultDeviceReroutingAdaptationInterval = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingWithTaz(bool value)
{
    sumoDefaultDeviceReroutingWithTaz = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingInitWithLoadedWeights(bool value)
{
    sumoDefaultDeviceReroutingInitWithLoadedWeights = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingShortestPathFile(const QString &value)
{
    sumoDefaultDeviceReroutingShortestPathFile = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingThreads(int value)
{
    sumoDefaultDeviceReroutingThreads = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceReroutingOutput(const QString &value)
{
    sumoDefaultDeviceReroutingOutput = value;
}

void sumoToolConfiguration::setSumoDefaultVerbose(bool value)
{
    sumoDefaultVerbose = value;
}

void sumoToolConfiguration::setSumoDefaultPrintOptions(bool value)
{
    sumoDefaultPrintOptions = value;
}

void sumoToolConfiguration::setSumoDefaultHelp(bool value)
{
    sumoDefaultHelp = value;
}

void sumoToolConfiguration::setSumoDefaultVersion(bool value)
{
    sumoDefaultVersion = value;
}

void sumoToolConfiguration::setSumoDefaultXmlValidation(const QString &value)
{
    sumoDefaultXmlValidation = value;
}

void sumoToolConfiguration::setSumoDefaultXmlValidationNet(const QString &value)
{
    sumoDefaultXmlValidationNet = value;
}

void sumoToolConfiguration::setSumoDefaultNoWarnings(bool value)
{
    sumoDefaultNoWarnings = value;
}

void sumoToolConfiguration::setSumoDefaultLog(const QString &value)
{
    sumoDefaultLog = value;
}

void sumoToolConfiguration::setSumoDefaultMessageLog(const QString &value)
{
    sumoDefaultMessageLog = value;
}

void sumoToolConfiguration::setSumoDefaultErrorLog(const QString &value)
{
    sumoDefaultErrorLog = value;
}

void sumoToolConfiguration::setSumoDefaultNoDurationLog(bool value)
{
    sumoDefaultNoDurationLog = value;
}

void sumoToolConfiguration::setSumoDefaultNoStepLog(bool value)
{
    sumoDefaultNoStepLog = value;
}

void sumoToolConfiguration::setSumoDefaultPhemlightPath(const QString &value)
{
    sumoDefaultPhemlightPath = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceEmissionsProbability(qreal value)
{
    sumoDefaultDeviceEmissionsProbability = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceEmissionsExplicit(const QString &value)
{
    sumoDefaultDeviceEmissionsExplicit = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceEmissionsDeterministic(bool value)
{
    sumoDefaultDeviceEmissionsDeterministic = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceBtreceiverProbability(qreal value)
{
    sumoDefaultDeviceBtreceiverProbability = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceBtreceiverExplicit(const QString &value)
{
    sumoDefaultDeviceBtreceiverExplicit = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceBtreceiverDeterministic(bool value)
{
    sumoDefaultDeviceBtreceiverDeterministic = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceBtreceiverRange(qreal value)
{
    sumoDefaultDeviceBtreceiverRange = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceBtreceiverAllRecognitions(bool value)
{
    sumoDefaultDeviceBtreceiverAllRecognitions = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceBtreceiverOfftime(qreal value)
{
    sumoDefaultDeviceBtreceiverOfftime = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceBtsenderProbability(qreal value)
{
    sumoDefaultDeviceBtsenderProbability = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceBtsenderExplicit(const QString &value)
{
    sumoDefaultDeviceBtsenderExplicit = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceBtsenderDeterministic(bool value)
{
    sumoDefaultDeviceBtsenderDeterministic = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceExampleExplicit(const QString &value)
{
    sumoDefaultDeviceExampleExplicit = value;
}

void sumoToolConfiguration::setSumoDefaultDeviceExampleParameter(qreal value)
{
    sumoDefaultDeviceExampleParameter = value;
}

void sumoToolConfiguration::setSumoDefaultRemotePort(int value)
{
    sumoDefaultRemotePort = value;
}

void sumoToolConfiguration::setSumoDefaultRandom(bool value)
{
    sumoDefaultRandom = value;
}

void sumoToolConfiguration::setSumoDefaultSeed(int value)
{
    sumoDefaultSeed = value;
}
