#ifndef JTRROUTERTOOLCONFIGURATION_H
#define JTRROUTERTOOLCONFIGURATION_H

#include "eNetEditorToolConfiguration.h"


class jtrRouterToolConfiguration : public eNetEditorToolConfiguration
{
public:

    jtrRouterToolConfiguration();

    ~jtrRouterToolConfiguration();


    // GET FUNCTIONS

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultNetFile() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultAdditionalFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultAlternativeFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultFlowFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultTurnRatioFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultOutputPrefix() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultOutputFile() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultVtypeOutput() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultExitTimes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultIgnoreErrors() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultUnsortedInput() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getJtrRouterDefaultRouteSteps() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultRandomizeFlows() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getJtrRouterDefaultMaxAlternatives() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultRemoveLoops() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultRepair() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultWeightsInterpolate() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultWithTaz() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getJtrRouterDefaultRoutingThreads() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getJtrRouterDefaultMaxEdgesFactor() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultTurnDefaults() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultSinkEdges() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultAcceptAllDestinations() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultIgnoreVclasses() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultAllowLoops() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultDepartlane() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultDepartpos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultDepartspeed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultArrivallane() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultArrivalpos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultArrivalspeed() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultDefaultsOverride() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getJtrRouterDefaultBegin() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getJtrRouterDefaultEnd() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultVerbose() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultPrintOptions() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultHelp() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultVersion() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultXmlValidation() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultXmlValidationNet() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultNoWarnings() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultLog() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultMessageLog() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getJtrRouterDefaultErrorLog() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getJtrRouterDefaultStatsPeriod() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultNoStepLog() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getJtrRouterDefaultRandom() const;

    /**
        @brief Get
        @return int with the
        @details Get
    */
    int getJtrRouterDefaultSeed() const;


    // SET FUNCTIONS

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultNetFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultAdditionalFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultAlternativeFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultFlowFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultTurnRatioFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultOutputPrefix(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultOutputFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultVtypeOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultExitTimes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultIgnoreErrors(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultUnsortedInput(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultRouteSteps(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultRandomizeFlows(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultMaxAlternatives(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultRemoveLoops(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultRepair(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultWeightsInterpolate(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultWithTaz(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultRoutingThreads(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultMaxEdgesFactor(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultTurnDefaults(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultSinkEdges(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultAcceptAllDestinations(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultIgnoreVclasses(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultAllowLoops(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultDepartlane(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultDepartpos(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultDepartspeed(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultArrivallane(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultArrivalpos(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultArrivalspeed(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultDefaultsOverride(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultBegin(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultEnd(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultVerbose(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultPrintOptions(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultHelp(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultVersion(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultXmlValidation(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultXmlValidationNet(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultNoWarnings(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultMessageLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultErrorLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultStatsPeriod(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultNoStepLog(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultRandom(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setJtrRouterDefaultSeed(int value);


private:

    // Use FILE as SUMONetwork to route on
    QString jtrRouterDefaultNetFile;

    // Read additional network data (districts, bus stops) from FILE
    QString jtrRouterDefaultAdditionalFiles;

    // Read alternatives from FILE
    QString jtrRouterDefaultAlternativeFiles;

    // Read flowDefinitions from FILE(s)
    QString jtrRouterDefaultFlowFiles;

    // Read turning ratios from FILE(s)
    QString jtrRouterDefaultTurnRatioFiles;

    // Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    QString jtrRouterDefaultOutputPrefix;

    // Write generated routes to FILE
    QString jtrRouterDefaultOutputFile;

    // Write used vehicle types into separate FILE
    QString jtrRouterDefaultVtypeOutput;

    // Write exit times (weights) for each edge; default: false
    bool jtrRouterDefaultExitTimes;

    // Continue if a route could not be build; default: false
    bool jtrRouterDefaultIgnoreErrors;

    // Assume input is unsorted; default: false
    bool jtrRouterDefaultUnsortedInput;

    // Load routes for the next number of seconds ahead; default: 200
    int jtrRouterDefaultRouteSteps;

    // generate random departure times for flow input; default: false
    bool jtrRouterDefaultRandomizeFlows;

    // Prune the number of alternatives to; default: 5
    int jtrRouterDefaultMaxAlternatives;

    // Remove loops within the route; Remove turnarounds at start and end of the route; default: false
    bool jtrRouterDefaultRemoveLoops;

    // Tries to correct a false route; default: false
    bool jtrRouterDefaultRepair;

    // Interpolate edge weights at interval boundaries; default: false
    bool jtrRouterDefaultWeightsInterpolate;

    // Use origin and destination zones (districts) for in- and output; default: false
    bool jtrRouterDefaultWithTaz;

    // The number of parallel execution threads used for routing; default: 0
    int jtrRouterDefaultRoutingThreads;

    // Routes are cut off when the route edges to net edges ratio is larger than FLOAT; default: 2
    qreal jtrRouterDefaultMaxEdgesFactor;

    // Use STR as default turn definition; default: 30,50,20
    QString jtrRouterDefaultTurnDefaults;

    // Use STR as list of sink edges
    QString jtrRouterDefaultSinkEdges;

    // Whether all edges are allowed as sink edges; default: false
    bool jtrRouterDefaultAcceptAllDestinations;

    // Ignore road restrictions based on vehicle class; default: false
    bool jtrRouterDefaultIgnoreVclasses;

    // Allow to reUse a road; default: false
    bool jtrRouterDefaultAllowLoops;

    // Assigns a default depart lane
    QString jtrRouterDefaultDepartlane;

    // Assigns a default depart position
    QString jtrRouterDefaultDepartpos;

    // Assigns a default depart speed
    QString jtrRouterDefaultDepartspeed;

    // Assigns a default arrival lane
    QString jtrRouterDefaultArrivallane;

    // Assigns a default arrival position
    QString jtrRouterDefaultArrivalpos;

    // Assigns a default arrival speed
    QString jtrRouterDefaultArrivalspeed;

    // Defaults will override given values; default: false
    bool jtrRouterDefaultDefaultsOverride;

    // Defines the begin time; Previous trips will be discarded; default: 0
    int jtrRouterDefaultBegin;

    // Defines the end time; Later trips will be discarded; Defaults to the maximum time that SUMO can represent; default: 2147483
    int jtrRouterDefaultEnd;

    // Switches to verbose output; default: false
    bool jtrRouterDefaultVerbose;

    // Prints option values before processing; default: false
    bool jtrRouterDefaultPrintOptions;

    // Prints this screen; default: false
    bool jtrRouterDefaultHelp;

    // Prints the current version; default: false
    bool jtrRouterDefaultVersion;

    // Set schema validation scheme of XML inputs ("never", "auto" or "always"); default: auto
    QString jtrRouterDefaultXmlValidation;

    // Set schema validation scheme of SUMO network inputs ("never", "auto" or "always"); default: never
    QString jtrRouterDefaultXmlValidationNet;

    // Disables output of warnings; default: false
    bool jtrRouterDefaultNoWarnings;

    // Writes all messages to FILE (implies verbose)
    QString jtrRouterDefaultLog;

    // Writes all nonError messages to FILE (implies verbose)
    QString jtrRouterDefaultMessageLog;

    // Writes all warnings and errors to FILE
    QString jtrRouterDefaultErrorLog;

    // Defines how often statistics shall be printed; default: -1
    int jtrRouterDefaultStatsPeriod;

    // Disable console output of route parsing step; default: false
    bool jtrRouterDefaultNoStepLog;

    // Initialises the random number generator with the current system time; default: false
    bool jtrRouterDefaultRandom;

    // Initialises the random number generator with the given value; default: 23423
    int jtrRouterDefaultSeed;
};

#endif // JTRROUTERCONFIGURATION_H
