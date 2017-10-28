#ifndef DUAROUTERTOOLCONFIGURATION_H
#define DUAROUTERTOOLCONFIGURATION_H

#include "eNetEditorToolConfiguration.h"


/*!
    \brief duaRouter configuration
    \author Pablo Álvarez López
    \date 2015
    \details Class to keep all parameters of duaRouter tool, including configuration and default
    values of input, output and configuration parameters
 */
class duaRouterToolConfiguration : public eNetEditorToolConfiguration
{
public:

    duaRouterToolConfiguration();

    ~duaRouterToolConfiguration();


    // GET FUNCTIONS

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultNetFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultAdditionalFiles() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultAlternativeFiles() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultFlowFiles() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultWeightFiles() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultLaneWeightFiles() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultWeightAttribute() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultPhemlightPath() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultTripFiles() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultRouteFiles() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultOutputPrefix() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultOutputFile() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultVtypeOutput() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultExitTimes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultIgnoreErrors() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultUnsortedInput() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDuaRouterDefaultRouteSteps() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultRandomizeFlows() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDuaRouterDefaultMaxAlternatives() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultRemoveLoops() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultRepair() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultWeightsInterpolate() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultWithTaz() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultRoutingAlgorithm() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDuaRouterDefaultWeightPeriod() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDuaRouterDefaultRoutingThreads() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultWeightsExpand() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getDuaRouterDefaultGawronBeta() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getDuaRouterDefaultGawronA() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultKeepAllRoutes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultSkipNewRoutes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultLogit() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultRouteChoiceMethod() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getDuaRouterDefaultLogitBeta() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getDuaRouterDefaultLogitGamma() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getDuaRouterDefaultLogitTheta() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultDepartlane() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultDepartpos() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultDepartspeed() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultArrivallane() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultArrivalpos() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultArrivalspeed() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultDefaultsOverride() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDuaRouterDefaultBegin() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDuaRouterDefaultEnd() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultVerbose() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultPrintOptions() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultHelp() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultVersion() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultXmlValidation() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultXmlValidationNet() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultNoWarnings() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultLog() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultMessageLog() const;

    /**
        @brief Get
        @return QString with the
        @details Get
    */
    const QString &getDuaRouterDefaultErrorLog() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDuaRouterDefaultStatsPeriod() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultNoStepLog() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getDuaRouterDefaultRandom() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getDuaRouterDefaultSeed() const;


    // GET FUNCTIONS

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultNetFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultAdditionalFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultAlternativeFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultFlowFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultWeightFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultLaneWeightFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultWeightAttribute(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultPhemlightPath(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultTripFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultRouteFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultOutputPrefix(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultOutputFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultVtypeOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultExitTimes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultIgnoreErrors(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultUnsortedInput(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultRouteSteps(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultRandomizeFlows(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultMaxAlternatives(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultRemoveLoops(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultRepair(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultWeightsInterpolate(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultWithTaz(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultRoutingAlgorithm(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultWeightPeriod(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultRoutingThreads(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultWeightsExpand(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultGawronBeta(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultGawronA(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultKeepAllRoutes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultSkipNewRoutes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultLogit(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultRouteChoiceMethod(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultLogitBeta(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultLogitGamma(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultLogitTheta(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultDepartlane(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultDepartpos(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultDepartspeed(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultArrivallane(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultArrivalpos(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultArrivalspeed(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultDefaultsOverride(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultBegin(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultEnd(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultVerbose(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultPrintOptions(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultHelp(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultVersion(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultXmlValidation(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultXmlValidationNet(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultNoWarnings(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultMessageLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultErrorLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultStatsPeriod(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultNoStepLog(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultRandom(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setDuaRouterDefaultSeed(int value);


private:

    // Use FILE as SUMONetwork to route on
    QString duaRouterDefaultNetFile;

    // Read additional network data (districts, bus stops) from FILE
    QString duaRouterDefaultAdditionalFiles;

    // Read alternatives from FILE
    QString duaRouterDefaultAlternativeFiles;

    // Read flowDefinitions from FILE(s)
    QString duaRouterDefaultFlowFiles;

    // Read network weights from FILE(s)
    QString duaRouterDefaultWeightFiles;

    // Read laneBased network weights from FILE(s)
    QString duaRouterDefaultLaneWeightFiles;

    // Name of the xml attribute which gives the edge weight; default: traveltime
    QString duaRouterDefaultWeightAttribute;

    // Determines where to load PHEMlight definitions from.; default: ./PHEMlight/
    QString duaRouterDefaultPhemlightPath;

    // Read tripDefinitions from FILE(s)
    QString duaRouterDefaultTripFiles;

    // Read sumoRoutes from FILE(s)
    QString duaRouterDefaultRouteFiles;

    // Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    QString duaRouterDefaultOutputPrefix;

    // Write generated routes to FILE
    QString duaRouterDefaultOutputFile;

    // Write used vehicle types into separate FILE
    QString duaRouterDefaultVtypeOutput;

    // Write exit times (weights) for each edge; default: false
    bool duaRouterDefaultExitTimes;

    // Continue if a route could not be build; default: false
    bool duaRouterDefaultIgnoreErrors;

    // Assume input is unsorted; default: false
    bool duaRouterDefaultUnsortedInput;

    // Load routes for the next number of seconds ahead; default: 200
    int duaRouterDefaultRouteSteps;

    // generate random departure times for flow input; default: false
    bool duaRouterDefaultRandomizeFlows;

    // Prune the number of alternatives to; default: 5
    int duaRouterDefaultMaxAlternatives;

    // Remove loops within the route; Remove turnarounds at start and end of the route; default: false
    bool duaRouterDefaultRemoveLoops;

    // Tries to correct a false route; default: false
    bool duaRouterDefaultRepair;

    // Interpolate edge weights at interval boundaries; default: false
    bool duaRouterDefaultWeightsInterpolate;

    // Use origin and destination zones (districts) for in- and output; default: false
    bool duaRouterDefaultWithTaz;

    // Select among routing algorithms ['dijkstra', 'astar', 'bulkstar', 'CH', 'CHWrapper']; default: dijkstra
    QString duaRouterDefaultRoutingAlgorithm;

    // Aggregation period for the given weight files; triggers rebuilding of Contraction Hierarchy; default: 3600
    int duaRouterDefaultWeightPeriod;

    // The number of parallel execution threads used for routing; default: 0
    int duaRouterDefaultRoutingThreads;

    // Expand weights behind the simulation's end; default: false
    bool duaRouterDefaultWeightsExpand;

    // Use FLOAT as Gawron's beta; default: 0.3
    qreal duaRouterDefaultGawronBeta;

    // Use FLOAT as Gawron's a; default: 0.05
    qreal duaRouterDefaultGawronA;

    // Save routes with near zero probability; default: false
    bool duaRouterDefaultKeepAllRoutes;

    // Only reuse routes from input, do not calculate new ones; default: false
    bool duaRouterDefaultSkipNewRoutes;

    // Use cLogit model (deprecated in favor of duaRouterDefaultRouteChoiceMethod logit); default: false
    bool duaRouterDefaultLogit;

    // Choose a route choice method: gawron, logit, or lohse; default: gawron
    QString duaRouterDefaultRouteChoiceMethod;

    // Use FLOAT as logit's beta; default: -1
    qreal duaRouterDefaultLogitBeta;

    // Use FLOAT as logit's gamma; default: 1
    qreal duaRouterDefaultLogitGamma;

    // Use FLOAT as logit's theta (negative values mean autoEstimation); default: -1
    qreal duaRouterDefaultLogitTheta;

    // Assigns a default depart lane
    QString duaRouterDefaultDepartlane;

    // Assigns a default depart position
    QString duaRouterDefaultDepartpos;

    // Assigns a default depart speed
    QString duaRouterDefaultDepartspeed;

    // Assigns a default arrival lane
    QString duaRouterDefaultArrivallane;

    // Assigns a default arrival position
    QString duaRouterDefaultArrivalpos;

    // Assigns a default arrival speed
    QString duaRouterDefaultArrivalspeed;

    // Defaults will override given values; default: false
    bool duaRouterDefaultDefaultsOverride;

    // Defines the begin time; Previous trips will be discarded; default: 0
    int duaRouterDefaultBegin;

    // Defines the end time; Later trips will be discarded; Defaults to the maximum time that SUMO can represent; default: 2147483
    int duaRouterDefaultEnd;

    // Switches to verbose output; default: false
    bool duaRouterDefaultVerbose;

    // Prints option values before processing; default: false
    bool duaRouterDefaultPrintOptions;

    // Prints this screen; default: false
    bool duaRouterDefaultHelp;

    // Prints the current version; default: false
    bool duaRouterDefaultVersion;

    // Set schema validation scheme of XML inputs ("never", "auto" or "always"); default: auto
    QString duaRouterDefaultXmlValidation;

    // Set schema validation scheme of SUMO network inputs ("never", "auto" or "always"); default: never
    QString duaRouterDefaultXmlValidationNet;

    // Disables output of warnings; default: false
    bool duaRouterDefaultNoWarnings;

    // Writes all messages to FILE (implies verbose)
    QString duaRouterDefaultLog;

    // Writes all nonError messages to FILE (implies verbose)
    QString duaRouterDefaultMessageLog;

    // Writes all warnings and errors to FILE
    QString duaRouterDefaultErrorLog;

    // Defines how often statistics shall be printed; default: -1
    int duaRouterDefaultStatsPeriod;

    // Disable console output of route parsing step; default: false
    bool duaRouterDefaultNoStepLog;

    // Initialises the random number generator with the current system time; default: false
    bool duaRouterDefaultRandom;

    // Initialises the random number generator with the given value; default: 23423
    int duaRouterDefaultSeed;
};

#endif // DUAROUTERCONFIGURATION_H
