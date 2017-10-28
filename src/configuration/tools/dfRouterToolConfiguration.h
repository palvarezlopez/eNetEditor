#ifndef DFROUTERTOOLCONFIGURATION_H
#define DFROUTERTOOLCONFIGURATION_H

#include "eNetEditorToolConfiguration.h"


/*!
    \brief dfRouter configuration
    \author Pablo Álvarez López
    \date 2015
    \details Class to keep all parameters of dfRouter tool, including configuration and default
    values of input, output and configuration parameters
 */
class dfRouterToolConfiguration : public eNetEditorToolConfiguration
{
public:

    dfRouterToolConfiguration();

    ~dfRouterToolConfiguration();

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultInputNetFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultInputDetectorFiles() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultInputMeasureFiles() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultOutputPrefixFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultOutputRoutesFile() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultOutputRoutesForAll() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultOutputDetectorFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultOutputDetectorsPoiFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultOutputEmittersFile() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultOutputVtype() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultOutputEmittersPoiFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultOutputVariableSpeedSignFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultOutputEndRerouteFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultOutputValidationFile() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultOutputValidationAddSources() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultGuessEmptyFlows() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultHighwayMode() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultIgnoreInvalidDetectors() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultRevalidateDetectors() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultRevalidateRoutes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultKeepUnfinishedRoutes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultKeepLongerRoutes() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDfRouterDefaultMaxSearchDepth() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultEmissionsOnly() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultDisallowedEdges() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultKeepTurnarounds() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getDfRouterDefaultMinRouteLength() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDfRouterDefaultTimeFactor() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDfRouterDefaultTimeOffset() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDfRouterDefaultTimeStep() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultCalibratorOutput() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultIncludeUnusedRoutes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultRevalidateFlows() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultRemoveEmptyDetectors() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultStrictSources() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultRespectConcurrentInflows() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getDfRouterDefaultScale() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultDepartlane() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultDepartpos() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultDepartspeed() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultArrivalpos() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultArrivallane() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultArrivalspeed() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDfRouterDefaultBegin() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDfRouterDefaultEnd() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultVerbose() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultPrintOptions() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultHelp() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultVersion() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultXmlValidation() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultXmlValidationNet() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultNoWarnings() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultLog() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultMessageLog() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDfRouterDefaultErrorLog() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultReportEmptyDetectors() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultPrintAbsoluteFlows() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultNoStepLog() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDfRouterDefaultRandom() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDfRouterDefaultSeed() const;


    // SET FUNCTIONS

    /**
        @brief Set
        @param
        @details set
    */
    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultInputNetFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultInputDetectorFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultInputMeasureFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputPrefixFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputRoutesFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputRoutesForAll(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputDetectorFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputDetectorsPoiFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputEmittersFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputVtype(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputEmittersPoiFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputVariableSpeedSignFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputEndRerouteFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputValidationFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultOutputValidationAddSources(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultGuessEmptyFlows(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultHighwayMode(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultIgnoreInvalidDetectors(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultRevalidateDetectors(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultRevalidateRoutes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultKeepUnfinishedRoutes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultKeepLongerRoutes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultMaxSearchDepth(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultEmissionsOnly(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultDisallowedEdges(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultKeepTurnarounds(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultMinRouteLength(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultTimeFactor(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultTimeOffset(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultTimeStep(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultCalibratorOutput(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultIncludeUnusedRoutes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultRevalidateFlows(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultRemoveEmptyDetectors(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultStrictSources(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultRespectConcurrentInflows(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultScale(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultDepartlane(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultDepartpos(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultDepartspeed(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultArrivallane(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultArrivalpos(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultArrivalspeed(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultBegin(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultEnd(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultVerbose(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultPrintOptions(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultHelp(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultVersion(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultXmlValidation(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultXmlValidationNet(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultNoWarnings(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultMessageLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultErrorLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultReportEmptyDetectors(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultPrintAbsoluteFlows(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultNoStepLog(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultRandom(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDfRouterDefaultSeed(int value);


private:

    // Loads the SUMO-network FILE
    QString dfRouterDefaultInputNetFile;

    // Loads detector descriptions from FILE
    QString dfRouterDefaultInputDetectorFiles;

    // Loads detector flows from FILE(s)
    QString dfRouterDefaultInputMeasureFiles;

    // Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    QString dfRouterDefaultOutputPrefixFile;

    // Saves computed routes to FILE
    QString dfRouterDefaultOutputRoutesFile;

    // Forces DFROUTER to compute routes for in-between detectors; default: false
    bool dfRouterDefaultOutputRoutesForAll;

    // Saves typed detectors to FILE
    QString dfRouterDefaultOutputDetectorFile;

    // Saves detector positions as pois to FILE
    QString dfRouterDefaultOutputDetectorsPoiFile;

    // Saves emitter definitions for source detectors to FILE
    QString dfRouterDefaultOutputEmittersFile;

    // Add vehicle types to the emitters file (PKW, LKW); default: false
    bool dfRouterDefaultOutputVtype;

    // Saves emitter positions as pois to FILE
    QString dfRouterDefaultOutputEmittersPoiFile;

    // Saves variable seed sign definitions for sink detectors to FILE
    QString dfRouterDefaultOutputVariableSpeedSignFile;

    // Saves rerouter definitions for sink detectors to FILE
    QString dfRouterDefaultOutputEndRerouteFile;

    // Saves validation
    QString dfRouterDefaultOutputValidationFile;

    // Add sources to output default: false
    bool dfRouterDefaultOutputValidationAddSources;

    // 	Derive missing flow values from upstream or downstream (not working!); default: false
    bool dfRouterDefaultGuessEmptyFlows;

    // Switches to highway-mode; default: false
    bool dfRouterDefaultHighwayMode;

    // Only warn about unparseable detectors; default: false
    bool dfRouterDefaultIgnoreInvalidDetectors;

    // Recomputes detector types even if given; default: false
    bool dfRouterDefaultRevalidateDetectors;

    // Recomputes routes even if given; default: false
    bool dfRouterDefaultRevalidateRoutes;

    // Keeps routes even if they have exhausted max-search-depth; default: false
    bool dfRouterDefaultKeepUnfinishedRoutes;

    // Keeps routes even if a shorter one exists; default: false
    bool dfRouterDefaultKeepLongerRoutes;

    // Number of edges to follow a route without passing a detector; default: 30
    int dfRouterDefaultMaxSearchDepth;

    // Writes only emission times; default: false
    bool dfRouterDefaultEmissionsOnly;

    // Do not route on these edges
    QString dfRouterDefaultDisallowedEdges;

    // Allow turnarounds as route continuations; default: false
    bool dfRouterDefaultKeepTurnarounds;

    // Minimum distance in meters between start and end node of every route; default: -1
    qreal dfRouterDefaultMinRouteLength;

    // Multiply flow times with TIME to get seconds; default: 60
    int dfRouterDefaultTimeFactor;

    // Subtracts TIME seconds from (scaled) flow times; default: 0
    int dfRouterDefaultTimeOffset;

    // Expected distance between two successive data sets; default: 60
    int dfRouterDefaultTimeStep;

    // Write calibrators to FILE; default: false
    bool dfRouterDefaultCalibratorOutput;

    // Include unused routes; default: false
    bool dfRouterDefaultIncludeUnusedRoutes;

    // Revalidate flows; default: false
    bool dfRouterDefaultRevalidateFlows;

    // Removes empty detectors from the list; default: false
    bool dfRouterDefaultRemoveEmptyDetectors;

    // Strict sources; default: false
    bool dfRouterDefaultStrictSources;

    // Try to determine further inflows to an inbetween detector when computing split probabilities; default: false
    bool dfRouterDefaultRespectConcurrentInflows;

    // Scale factor for flows; default: 1
    qreal dfRouterDefaultScale;

    // Assigns a default depart lane
    QString dfRouterDefaultDepartlane;

    // Assigns a default depart position
    QString dfRouterDefaultDepartpos;

    // Assigns a default depart speed
    QString dfRouterDefaultDepartspeed;

    // Assigns a default arrival lane
    QString dfRouterDefaultArrivallane;

    // Assigns a default arrival position
    QString dfRouterDefaultArrivalpos;

    // Assigns a default arrival speed
    QString dfRouterDefaultArrivalspeed;

    // Defines the begin time; Previous defs will be discarded; default: 0
    int dfRouterDefaultBegin;

    // Defines the end time; Later defs will be discarded; Defaults to one day; default: 86400
    int dfRouterDefaultEnd;

    // Switches to verbose output; default: false
    bool dfRouterDefaultVerbose;

    // Prints option values before processing; default: false
    bool dfRouterDefaultPrintOptions;

    // Prints this screen; default: false
    bool dfRouterDefaultHelp;

    // Prints the current version; default: false
    bool dfRouterDefaultVersion;

    // Set schema validation scheme of XML inputs ("never", "auto" or "always"); default: auto
    QString dfRouterDefaultXmlValidation;

    // Set schema validation scheme of SUMO network inputs ("never", "auto" or "always"); default: never
    QString dfRouterDefaultXmlValidationNet;

    // Disables output of warnings; default: false
    bool dfRouterDefaultNoWarnings;

    // Writes all messages to FILE (implies verbose)
    QString dfRouterDefaultLog;

    // Writes all non-error messages to FILE (implies verbose)
    QString dfRouterDefaultMessageLog;

    // Writes all warnings and errors to FILE
    QString dfRouterDefaultErrorLog;

    // Lists detectors with no flow (enable -v); default: false
    bool dfRouterDefaultReportEmptyDetectors;

    // Prints aggregated detector flows; default: false
    bool dfRouterDefaultPrintAbsoluteFlows;

    // Disable console output of route parsing step; default: false
    bool dfRouterDefaultNoStepLog;

    // Initialises the random number generator with the current system time; default: false
    bool dfRouterDefaultRandom;

    // Initialises the random number generator with the given value; default: 23423
    int dfRouterDefaultSeed;
};

#endif // DFROUTERCONFIGURATION_H
