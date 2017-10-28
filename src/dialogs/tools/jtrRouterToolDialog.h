#ifndef JTRROUTERDIALOG_H
#define JTRROUTERDIALOG_H

#include "eNetEditorToolDialog.h"


namespace Ui
{
class jtrRouterToolDialog;
}

class jtrRouterToolDialog : public eNetEditorToolDialog
{
    Q_OBJECT

public:

    explicit jtrRouterToolDialog(eNetEditorMainWindow *neweNetEditorMainW);

    ~jtrRouterToolDialog();


public slots:

    void openDialog(eNetEditorProject *newProject);

    void resetParameters();

    void updateParameters();


private slots:

    void setInputParameters();

    void setOutputParameters();

    void setProcessingParameters();

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_ButtonReset_released();

    void on_TextSumoNetwork_textChanged();

    void on_TextAdditionalFiles_textChanged();

    void on_TextAlternativeFiles_textChanged();

    void on_TextFlowFiles_textChanged();

    void on_TextTurnRatioFiles_textChanged();

    void on_ButtonSearchSumoNetwork_released();

    void on_ButtonSearchAdditional_released();

    void on_ButtonSearchAlternativeFiles_released();

    void on_ButtonSearchFlowFiles_released();

    void on_ButtonSearchTurnRatioFiles_released();

    void on_TextDepartLane_textChanged();

    void on_TextDepartPos_textChanged();

    void on_TextDepartSpeed_textChanged();

    void on_TextArrivalLane_textChanged();

    void on_TextArrivalPos_textChanged();

    void on_TextArrivalSpeed_textChanged();

    void on_TextTimeBegin_textChanged();

    void on_TextTimeEnd_textChanged();

    void on_TextSeed_textChanged();

    void on_CheckBoxRandom_toggled(bool checked);

    void on_TextOutput_textChanged();

    void on_TextVTypeOutput_textChanged();

    void on_ButtonOutput_released();

    void on_ButtonSearchVTypeOutput_released();

    void on_CheckBoxExitTimes_toggled(bool checked);

    void on_TextLog_textChanged();

    void on_TextMessageLog_textChanged();

    void on_TextErrorLog_textChanged();

    void on_ButtonSearchLog_released();

    void on_ButtonSearchMessageLog_released();

    void on_ButtonSearchErrorLog_released();

    void on_CheckBoxVerbose_toggled(bool checked);

    void on_CheckBoxVersion_toggled(bool checked);

    void on_CheckBoxPrintOptions_toggled(bool checked);

    void on_CheckBoxNoStepLog_toggled(bool checked);

    void on_CheckBoxHelp_toggled(bool checked);

    void on_CheckBoxNoWarnings_toggled(bool checked);

    void on_TextStatsPeriod_textChanged();

    void on_ComboBoxXmlValidation_editTextChanged(const QString &arg1);

    void on_ComboBoxXmlValidationNet_currentTextChanged(const QString &arg1);


    void on_TextRouteSteps_textChanged();

    void on_TextMaxAlternatives_textChanged();

    void on_TextRoutingThreads_textChanged();

    void on_TextMaxEdgeFactor_textChanged();

    void on_TextTurnDefaults_textChanged();

    void on_TextSinkEdges_textChanged();

    void on_CheckBoxIgnoreErrors_toggled(bool checked);

    void on_CheckBoxUnsortedInput_toggled(bool checked);

    void on_CheckBoxRandomizeFlows_toggled(bool checked);

    void on_CheckBoxRemoveLoops_toggled(bool checked);

    void on_CheckBoxRepair_toggled(bool checked);

    void on_CheckBoxWeightsInterpolate_toggled(bool checked);

    void on_CheckBoxWidthTaz_toggled(bool checked);

    void on_CheckBoxAcceptAllDestinations_toggled(bool checked);

    void on_CheckBoxIgnoreVClasses_toggled(bool checked);

    void on_CheckBoxAllowLoops_toggled(bool checked);

    void on_CheckBoxDefaultOverride_toggled(bool checked);


private:

    // UI
    Ui::jtrRouterToolDialog *ui;

    // jtrRouter Tool
    jtrRouterTool *jtrRouterT;

    // INPUT

    // Use FILE as SUMONetwork to route on
    QString netFile;

    // Read additional network data (districts, bus stops) from FILE
    QString additionalFiles;

    // Read alternatives from FILE
    QString alternativeFiles;

    // Read flowDefinitions from FILE(s)
    QString flowFiles;

    // Read turning ratios from FILE(s)
    QString turnRatioFiles;


    // OUTPUT PARAMETERS

    // Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    QString outputPrefix;

    // Write generated routes to FILE
    QString outputFile;

    // Write used vehicle types into separate FILE
    QString vtypeOutput;

    // Write exit times (weights) for each edge; default: false
    bool exitTimes;


    // PROCESSING PARAMETERS

    // Continue if a route could not be build; default: false
    bool ignoreErrors;

    // Assume input is unsorted; default: false
    bool unsortedInput;

    // Load routes for the next number of seconds ahead; default: 200
    int routeSteps;

    // generate random departure times for flow input; default: false
    bool randomizeFlows;

    // Prune the number of alternatives to; default: 5
    int maxAlternatives;

    // Remove loops within the route; Remove turnarounds at start and end of the route; default: false
    bool removeLoops;

    // Tries to correct a false route; default: false
    bool repair;

    // Interpolate edge weights at interval boundaries; default: false
    bool weightsInterpolate;

    // Use origin and destination zones (districts) for in- and output; default: false
    bool withTaz;

    // The number of parallel execution threads used for routing; default: 0
    int routingThreads;

    // Routes are cut off when the route edges to net edges ratio is larger than FLOAT; default: 2
    qreal maxEdgesFactor;

    // Use STR as default turn definition; default: 30,50,20
    QString turnDefaults;

    // Use STR as list of sink edges
    QString sinkEdges;

    // Whether all edges are allowed as sink edges; default: false
    bool acceptAllDestinations;

    // Ignore road restrictions based on vehicle class; default: false
    bool ignoreVclasses;

    // Allow to reUse a road; default: false
    bool allowLoops;

    // Assigns a default depart lane
    QString departlane;

    // Assigns a default depart position
    QString departpos;

    // Assigns a default depart speed
    QString departspeed;

    // Assigns a default arrival lane
    QString arrivallane;

    // Assigns a default arrival position
    QString arrivalpos;

    // Assigns a default arrival speed
    QString arrivalspeed;

    // Defaults will override given values; default: false
    bool defaultsOverride;

    // Defines the begin time; Previous trips will be discarded; default: 0
    int begin;

    // Defines the end time; Later trips will be discarded; Defaults to the maximum time that SUMO can represent; default: 2147483
    int end;

    // Switches to verbose output; default: false
    bool verbose;

    // Prints option values before processing; default: false
    bool printOptions;

    // Prints this screen; default: false
    bool help;

    // Prints the current version; default: false
    bool version;

    // Set schema validation scheme of XML inputs ("never", "auto" or "always"); default: auto
    QString xmlValidation;

    // Set schema validation scheme of SUMO network inputs ("never", "auto" or "always"); default: never
    QString xmlValidationNet;

    // Disables output of warnings; default: false
    bool noWarnings;

    // Writes all messages to FILE (implies verbose)
    QString log;

    // Writes all nonError messages to FILE (implies verbose)
    QString messageLog;

    // Writes all warnings and errors to FILE
    QString errorLog;

    // Defines how often statistics shall be printed; default: -1
    int statsPeriod;

    // Disable console output of route parsing step; default: false
    bool noStepLog;

    // Initialises the random number generator with the current system time; default: false
    bool random;

    // Initialises the random number generator with the given value; default: 23423
    int seed;
};

#endif // JTRROUTERDIALOG_H
