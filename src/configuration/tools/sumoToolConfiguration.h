#ifndef SUMOTOOLCONFIGURATION_H
#define SUMOTOOLCONFIGURATION_H

#include "eNetEditorToolConfiguration.h"


class sumoToolConfiguration : public eNetEditorToolConfiguration
{
public:

    sumoToolConfiguration();

    ~sumoToolConfiguration();

    // GET FUNCTIONS

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultNetFile() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultRouteFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultAdditionalFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultWeightFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultWeightAttribute() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultLoadState() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultLoadStateOffset() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultOutputPrefix() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultNetstateDump() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultNetstateDumpEmptyEdges() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultNetstateDumpPrecision() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultEmissionOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultFcdOutput() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultFcdOutputGeo() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultFcdOutputSignals() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultFullOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultQueueOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultVtkOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultAmitranOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultSummaryOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultTripinfoOutput() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultTripinfoOutputWriteUnfinished() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultVehrouteOutput() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultVehrouteOutputExitTimes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultVehrouteOutputLastRoute() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultVehrouteOutputSorted() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultVehrouteOutputDua() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultVehrouteOutputIntendedDepart() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultVehrouteOutputWriteUnfinished() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultLinkOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultBtOutput() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultSaveStateTimes() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultSaveStatePrefix() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultSaveStateFiles() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultBegin() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultEnd() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultStepLength() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultRouteSteps() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultNoInternalLinks() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultIgnoreJunctionBlocker() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultIgnoreAccidents() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultIgnoreRouteErrors() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultMaxNumVehicles() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultScale() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultTimeToTeleport() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultTimeToTeleportHighways() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultMaxDepartDelay() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultSloppyInsert() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultEagerInsert() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultRandomDepartOffset() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultLanechangeAllowSwap() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultLanechangeDuration() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultLanechangeOvertakeRight() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultPedestrianModel() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultPedestrianStripingStripeWidth() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultPedestrianStripingDawdling() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultPedestrianStripingJamtime() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultRoutingAlgorithm() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultWeightsRandomFactor() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultDeviceReroutingProbability() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultDeviceReroutingExplicit() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultDeviceReroutingDeterministic() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultDeviceReroutingPeriod() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultDeviceReroutingPrePeriod() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultDeviceReroutingAdaptationWeight() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultDeviceReroutingAdaptationInterval() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultDeviceReroutingWithTaz() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultDeviceReroutingInitWithLoadedWeights() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultDeviceReroutingShortestPathFile() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultDeviceReroutingThreads() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultDeviceReroutingOutput() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultVerbose() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultPrintOptions() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultHelp() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultVersion() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultXmlValidation() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultXmlValidationNet() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultNoWarnings() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultLog() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultMessageLog() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultErrorLog() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultNoDurationLog() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultNoStepLog() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultPhemlightPath() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultDeviceEmissionsProbability() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultDeviceEmissionsExplicit() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultDeviceEmissionsDeterministic() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultDeviceBtreceiverProbability() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultDeviceBtreceiverExplicit() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultDeviceBtreceiverDeterministic() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultDeviceBtreceiverRange() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultDeviceBtreceiverAllRecognitions() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultDeviceBtreceiverOfftime() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultDeviceBtsenderProbability() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultDeviceBtsenderExplicit() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultDeviceBtsenderDeterministic() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getSumoDefaultDeviceExampleExplicit() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getSumoDefaultDeviceExampleParameter() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultRemotePort() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getSumoDefaultRandom() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getSumoDefaultSeed() const;


    // SET FUNCTIONS

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultNetFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultRouteFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultAdditionalFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultWeightFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultWeightAttribute(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultLoadState(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultLoadStateOffset(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultOutputPrefix(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultNetstateDump(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultNetstateDumpEmptyEdges(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultNetstateDumpPrecision(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultEmissionOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultFcdOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultFcdOutputGeo(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultFcdOutputSignals(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultFullOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultQueueOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultVtkOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultAmitranOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultSummaryOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultTripinfoOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultTripinfoOutputWriteUnfinished(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultVehrouteOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultVehrouteOutputExitTimes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultVehrouteOutputLastRoute(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultVehrouteOutputSorted(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultVehrouteOutputDua(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultVehrouteOutputIntendedDepart(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultVehrouteOutputWriteUnfinished(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultLinkOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultBtOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultSaveStateTimes(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultSaveStatePrefix(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultSaveStateFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultBegin(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultEnd(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultStepLength(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultRouteSteps(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultNoInternalLinks(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultIgnoreJunctionBlocker(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultIgnoreAccidents(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultIgnoreRouteErrors(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultMaxNumVehicles(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultScale(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultTimeToTeleport(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultTimeToTeleportHighways(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultMaxDepartDelay(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultSloppyInsert(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultEagerInsert(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultRandomDepartOffset(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultLanechangeAllowSwap(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultLanechangeDuration(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultLanechangeOvertakeRight(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultPedestrianModel(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultPedestrianStripingStripeWidth(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultPedestrianStripingDawdling(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultPedestrianStripingJamtime(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultRoutingAlgorithm(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultWeightsRandomFactor(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingProbability(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingDeterministic(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingPeriod(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingPrePeriod(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingAdaptationWeight(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingAdaptationInterval(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingWithTaz(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingInitWithLoadedWeights(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingShortestPathFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingThreads(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceReroutingOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultVerbose(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultPrintOptions(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultHelp(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultVersion(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultXmlValidation(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultXmlValidationNet(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultNoWarnings(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultMessageLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultErrorLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultNoDurationLog(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultNoStepLog(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultPhemlightPath(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceEmissionsProbability(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceEmissionsExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceEmissionsDeterministic(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceBtreceiverProbability(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceBtreceiverExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceBtreceiverDeterministic(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceBtreceiverRange(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceBtreceiverAllRecognitions(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceBtreceiverOfftime(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceBtsenderProbability(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceBtsenderExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceBtsenderDeterministic(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceExampleExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultDeviceExampleParameter(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultRemotePort(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultRandom(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setSumoDefaultSeed(int value);


private:

    // Load road network description from FILE
    QString sumoDefaultNetFile;

    // Load routes descriptions from FILE(s)
    QString sumoDefaultRouteFiles;

    // Load further descriptions from FILE(s)
    QString sumoDefaultAdditionalFiles;

    // Load edge/lane weights for online rerouting from FILE
    QString sumoDefaultWeightFiles;

    // Name of the xml attribute which gives the edge weight; default: traveltime
    QString sumoDefaultWeightAttribute;

    // Loads a network state from FILE
    QString sumoDefaultLoadState;

    // Sets the time offset for vehicle segment exit times; default: 0
    int sumoDefaultLoadStateOffset;

    // Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    QString sumoDefaultOutputPrefix;

    // Save complete network states into FILE
    QString sumoDefaultNetstateDump;

    // Write also empty edges completely when dumping; default: false
    bool sumoDefaultNetstateDumpEmptyEdges;

    // Write positions and speeds with the given precision (default 2); default: 2
    int sumoDefaultNetstateDumpPrecision;

    // Save the emission values of each vehicle
    QString sumoDefaultEmissionOutput;

    // Save the Floating Car Data
    QString sumoDefaultFcdOutput;

    // Save the Floating Car Data using geoCoordinates (lon/lat); default: false
    bool sumoDefaultFcdOutputGeo;

    // Add the vehicle signal state to the FCD output (brake lights etc.); default: false
    bool sumoDefaultFcdOutputSignals;

    // Save a lot of information for each timestep (very redundant)
    QString sumoDefaultFullOutput;

    // Save the vehicle queues at the junctions (experimental)
    QString sumoDefaultQueueOutput;

    // Save complete vehicle positions inclusive speed values in the VTK Format (usage: /path/out will produce /path/out_$TIMESTEP$Vtp files)
    QString sumoDefaultVtkOutput;

    // Save the vehicle trajectories in the Amitran format
    QString sumoDefaultAmitranOutput;

    // Save aggregated vehicle departure info into FILE
    QString sumoDefaultSummaryOutput;

    // Save single vehicle trip info into FILE
    QString sumoDefaultTripinfoOutput;

    // Write tripinfo output for vehicles which have not arrived at simulation end; default: false
    bool sumoDefaultTripinfoOutputWriteUnfinished;

    // Save single vehicle route info into FILE
    QString sumoDefaultVehrouteOutput;

    // Write the exit times for all edges; default: false
    bool sumoDefaultVehrouteOutputExitTimes;

    // Write the last route only; default: false
    bool sumoDefaultVehrouteOutputLastRoute;

    // Sorts the output by departure time; default: false
    bool sumoDefaultVehrouteOutputSorted;

    // Write the output in the duarouter alternatives style; default: false
    bool sumoDefaultVehrouteOutputDua;

    // Write the output with the intended instead of the real departure time; default: false
    bool sumoDefaultVehrouteOutputIntendedDepart;

    // Write vehroute output for vehicles which have not arrived at simulation end; default: false
    bool sumoDefaultVehrouteOutputWriteUnfinished;

    // Save links states into FILE
    QString sumoDefaultLinkOutput;

    // Save bt visibilities into FILE
    QString sumoDefaultBtOutput;

    // Use INT[] as times at which a network state written
    int sumoDefaultSaveStateTimes;

    // Prefix for network states; default: state
    QString sumoDefaultSaveStatePrefix;

    // Files for network states
    QString sumoDefaultSaveStateFiles;

    // Defines the begin time; The simulation starts at this time; default: 0
    int sumoDefaultBegin;

    // Defines the end time; The simulation ends at this time; default: -1
    int sumoDefaultEnd;

    // Defines the step duration; default: 1
    int sumoDefaultStepLength;

    // Load routes for the next number of seconds ahead; default: 200
    int sumoDefaultRouteSteps;

    // Disable (junction) internal links; default: false
    bool sumoDefaultNoInternalLinks;

    // Ignore vehicles which block the junction after they have been standing for SECONDS (-1 means never ignore); default: -1
    int sumoDefaultIgnoreJunctionBlocker;

    // Do not check whether accidents occur; default: false
    bool sumoDefaultIgnoreAccidents;

    // Do not check whether routes are connected; default: false
    bool sumoDefaultIgnoreRouteErrors;

    // Quit simulation if this number of vehicles is exceeded; default: -1
    int sumoDefaultMaxNumVehicles;

    // Scale demand by the given factor (by discarding or duplicating vehicles)
    qreal sumoDefaultScale;

    // Specify how long a vehicle may wait until being teleported, defaults to 300, nonPositive values disable teleporting; default: 300
    int sumoDefaultTimeToTeleport;

    // The waiting time after which vehicles on a fast road (speed > 69m/s) are teleported if they are on a nonContinuing lane; default: 0
    int sumoDefaultTimeToTeleportHighways;

    // How long vehicles wait for departure before being skipped, defaults to -1 which means vehicles are never skipped; default: -1
    int sumoDefaultMaxDepartDelay;

    // Whether insertion on an edge shall not be repeated in same step once failed; default: false
    bool sumoDefaultSloppyInsert;

    // Whether each vehicle is checked separately for insertion on an edge; default: false
    bool sumoDefaultEagerInsert;

    // Each vehicle receives a random offset to its depart value drawn uniformly from [0, TIME]; default: 0
    int sumoDefaultRandomDepartOffset;

    // Whether blocking vehicles trying to change lanes may be swapped; default: false
    bool sumoDefaultLanechangeAllowSwap;

    // Duration of a lane change maneuver (default 0); default: 0
    int sumoDefaultLanechangeDuration;

    // Whether overtaking on the right on motorways is permitted; default: false
    bool sumoDefaultLanechangeOvertakeRight;

    // Select among pedestrian models ['nonInteracting', 'striping']; default: striping
    QString sumoDefaultPedestrianModel;

    // Width of parallel stripes for segmenting a sidewalk (meters) for use with model 'striping'; default: 0.65
    qreal sumoDefaultPedestrianStripingStripeWidth;

    // factor for random slowDowns [0,1] for use with model 'striping'; default: 0.2
    qreal sumoDefaultPedestrianStripingDawdling;

    // Time in seconds after which pedestrians start squeezing through a jam when using model 'striping' (nonPositive values disable squeezing); default: 300
    int sumoDefaultPedestrianStripingJamtime;

    // Select among routing algorithms ['dijkstra', 'astar', 'CH', 'CHWrapper']; default: dijkstra
    QString sumoDefaultRoutingAlgorithm;

    // Edge weights for routing are dynamically disturbed by a random factor between [1,FLOAT]
    qreal sumoDefaultWeightsRandomFactor;

    // The probability for a vehicle to have a 'rerouting' device; default: 0
    qreal sumoDefaultDeviceReroutingProbability;

    // Assign a 'rerouting' device to named vehicles
    QString sumoDefaultDeviceReroutingExplicit;

    // The 'rerouting' devices are set deterministic using a fraction of 1000; default: false
    bool sumoDefaultDeviceReroutingDeterministic;

    // The period with which the vehicle shall be rerouted; default: 0
    int sumoDefaultDeviceReroutingPeriod;

    // The rerouting period before depart; default: 1
    int sumoDefaultDeviceReroutingPrePeriod;

    // The weight of prior edge weights; default: 0.5
    qreal sumoDefaultDeviceReroutingAdaptationWeight;

    // The interval for updating the edge weights; default: 1
    int sumoDefaultDeviceReroutingAdaptationInterval;

    // Use zones (districts) as routing end points; default: false
    bool sumoDefaultDeviceReroutingWithTaz;

    // Use given weight files for initializing edge weights; default: false
    bool sumoDefaultDeviceReroutingInitWithLoadedWeights;

    // Initialize lookup table for astar from the given distance matrix
    QString sumoDefaultDeviceReroutingShortestPathFile;

    // The number of parallel execution threads used for rerouting; default: 0
    int sumoDefaultDeviceReroutingThreads;

    // Save adapting weights to FILE
    QString sumoDefaultDeviceReroutingOutput;

    // Switches to verbose output; default: false
    bool sumoDefaultVerbose;

    // Prints option values before processing; default: false
    bool sumoDefaultPrintOptions;

    // Prints this screen; default: false
    bool sumoDefaultHelp;

    // Prints the current version; default: false
    bool sumoDefaultVersion;

    // Set schema validation scheme of XML inputs ("never", "auto" or "always"); default: auto
    QString sumoDefaultXmlValidation;

    // Set schema validation scheme of SUMO network inputs ("never", "auto" or "always"); default: never
    QString sumoDefaultXmlValidationNet;

    // Disables output of warnings; default: false
    bool sumoDefaultNoWarnings;

    // Writes all messages to FILE (implies verbose)
    QString sumoDefaultLog;

    // Writes all nonError messages to FILE (implies verbose)
    QString sumoDefaultMessageLog;

    // Writes all warnings and errors to FILE
    QString sumoDefaultErrorLog;

    // Disable performance reports for individual simulation steps; default: false
    bool sumoDefaultNoDurationLog;

    // Disable console output of current simulation step; default: false
    bool sumoDefaultNoStepLog;

    // Determines where to load PHEMlight definitions from.; default: ./PHEMlight/
    QString sumoDefaultPhemlightPath;

    // The probability for a vehicle to have a 'emissions' device; default: 0
    qreal sumoDefaultDeviceEmissionsProbability;

    // Assign a 'emissions' device to named vehicles
    QString sumoDefaultDeviceEmissionsExplicit;

    // The 'emissions' devices are set deterministic using a fraction of 1000; default: false
    bool sumoDefaultDeviceEmissionsDeterministic;

    // The probability for a vehicle to have a 'btreceiver' device; default: 0
    qreal sumoDefaultDeviceBtreceiverProbability;

    // Assign a 'btreceiver' device to named vehicles
    QString sumoDefaultDeviceBtreceiverExplicit;

    // The 'btreceiver' devices are set deterministic using a fraction of 1000; default: false
    bool sumoDefaultDeviceBtreceiverDeterministic;

    // The range of the bt receiver; default: 300
    qreal sumoDefaultDeviceBtreceiverRange;

    // Whether all recognition point shall be written; default: false
    bool sumoDefaultDeviceBtreceiverAllRecognitions;

    // The offtime used for calculating detection probability (in seconds); default: 0.64
    qreal sumoDefaultDeviceBtreceiverOfftime;

    // The probability for a vehicle to have a 'btsender' device; default: 0
    qreal sumoDefaultDeviceBtsenderProbability;

    // Assign a 'btsender' device to named vehicles
    QString sumoDefaultDeviceBtsenderExplicit;

    // The 'btsender' devices are set deterministic using a fraction of 1000; default: false
    bool sumoDefaultDeviceBtsenderDeterministic;

    // Assign a device to named vehicles
    QString sumoDefaultDeviceExampleExplicit;

    // An exemplary parameter which can be used by all instances of the example device; default: 0
    qreal sumoDefaultDeviceExampleParameter;

    // Enables TraCI Server if set; default: 0
    int sumoDefaultRemotePort;

    // Initialises the random number generator with the current system time; default: false
    bool sumoDefaultRandom;

    // Initialises the random number generator with the given value; default: 23423
    int sumoDefaultSeed;
};

#endif // SUMOCONFIGURATION_H
