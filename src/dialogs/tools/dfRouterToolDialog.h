#ifndef DFROUTERDIALOG_H
#define DFROUTERDIALOG_H

#include "eNetEditorToolDialog.h"


namespace Ui
{
class dfRouterToolDialog;
}

class dfRouterToolDialog : public eNetEditorToolDialog
{
    Q_OBJECT

public:

    explicit dfRouterToolDialog(eNetEditorMainWindow *neweNetEditorMainW);

    ~dfRouterToolDialog();


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

    void on_ButtonSearchDetectorFiles_released();

    void on_ButtonSearchMeasureFiles_released();

    void on_ButtonSearchSumoNetwork_released();

    void on_TextDetectorFiles_textChanged();

    void on_TextMeasureFiles_textChanged();

    void on_TextSumoNetwork_textChanged();

    void on_TextTimeBegin_textChanged();

    void on_TextTimeEnd_textChanged();

    void on_TextDisallowedEdges_textChanged();

    void on_TextMaxSearchDepth_textChanged();

    void on_TextMinRouteLenght_textChanged();

    void on_TextScale_textChanged();

    void on_TextTimeFactor_textChanged();

    void on_TextTimeOffset_textChanged();

    void on_TextTimeStep_textChanged();

    void on_ButtonSearchDetectorOutput_released();

    void on_ButtonSearchDetectorsPoiOutput_released();

    void on_ButtonSearchEmmitersOutput_released();

    void on_ButtonSearchEmmitersPoiOutput_released();

    void on_ButtonSearchEndRerouteOutput_released();

    void on_ButtonValidationOutput_released();

    void on_ButtonVariableSpdOutput_released();

    void on_TextDetectorOutput_textChanged();

    void on_TextDetectorsPoiOutput_textChanged();

    void on_TextEmmitersOutput_textChanged();

    void on_TextEmmitersPoiOutput_textChanged();

    void on_TextEndRerouteOutput_textChanged();

    void on_TextRoutesOutput_textChanged();

    void on_TextValidationOutput_textChanged();

    void on_TextVariableSpdSignOutput_textChanged();

    void on_TextArrivalLane_textChanged();

    void on_TextArrivalPos_textChanged();

    void on_TextArrivalSpeed_textChanged();

    void on_TextDepartLane_textChanged();

    void on_TextDepartPos_textChanged();

    void on_TextDepartSpeed_textChanged();

    void on_TextSeed_textChanged();

    void on_CheckBoxRandom_toggled(bool checked);

    void on_ButtonSearchErrorLog_released();

    void on_ButtonSearchLog_released();

    void on_ButtonSearchMessageLog_released();

    void on_ComboBoxXmlValidation_currentTextChanged(const QString &arg1);

    void on_ComboBoxXmlValidationNet_currentTextChanged(const QString &arg1);

    void on_TextErrorLog_textChanged();

    void on_TextLog_textChanged();

    void on_TextMessageLog_textChanged();

    void on_CheckBoxHelp_toggled(bool checked);

    void on_CheckBoxNoStepLog_toggled(bool checked);

    void on_CheckBoxNoWarnings_toggled(bool checked);

    void on_CheckBoxPrintAbsoluteLogs_toggled(bool checked);

    void on_CheckBoxPrintOptions_toggled(bool checked);

    void on_CheckBoxReportEmptyDetectors_toggled(bool checked);

    void on_CheckBoxVerbose_toggled(bool checked);

    void on_CheckBoxVersion_toggled(bool checked);

    void on_ButtonRoutesOutput_released();

    void on_CheckBoxRoutesForAll_toggled(bool checked);

    void on_CheckBoxVType_toggled(bool checked);

    void on_CheckBoxValidationOutputAddSource_toggled(bool checked);

    void on_CheckBoxCalibratorOutput_toggled(bool checked);

    void on_CheckBoxEmissionsOnly_toggled(bool checked);

    void on_CheckBoxGuessEmptyFlows_toggled(bool checked);

    void on_CheckBoxHighwayMode_toggled(bool checked);

    void on_CheckBoxIgnoreInvalidDetectors_toggled(bool checked);

    void on_CheckBoxIncludeUnusedRoutes_toggled(bool checked);

    void on_CheckBoxKeepLongerRoutes_toggled(bool checked);

    void on_CheckBoxKeepUnfinishedRoutes_toggled(bool checked);

    void on_CheckBoxKeepturnAorunds_toggled(bool checked);

    void on_CheckBoxRemoveEmptyDetectors_toggled(bool checked);

    void on_CheckBoxRespectConcurrenceInflows_toggled(bool checked);

    void on_CheckBoxRevalidateDetectors_toggled(bool checked);

    void on_CheckBoxRevalidateFlows_toggled(bool checked);

    void on_CheckBoxRevalidateRoutes_toggled(bool checked);

    void on_CheckBoxStrictSources_toggled(bool checked);


private:

    // UI
    Ui::dfRouterToolDialog *ui;

    // dfRouter Tool
    dfRouterTool *dfRouterT;


    // INPUT PARAMETERS

    // Loads the SUMO-network FILE
    QString inputNetFile;

    // Loads detector descriptions from FILE
    QString inputInductionLoopsE1DetectorFiles;

    // Loads detector flows from FILE(s)
    QString inputMeasureFiles;

    // OUTPUT PARAMETERS

    // Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    QString outputPrefixFile;

    // Saves computed routes to FILE
    QString outputRoutesFile;

    // Forces DFROUTER to compute routes for in-between detectors; default: false
    bool outputRoutesForAll;

    // Saves typed detectors to FILE
    QString outputDetectorFile;

    // Saves detector positions as pois to FILE
    QString outputDetectorsPoiFile;

    // Saves emitter definitions for source detectors to FILE
    QString outputEmittersFile;

    // Add vehicle types to the emitters file (PKW, LKW); default: false
    bool outputVtype;

    // Saves emitter positions as pois to FILE
    QString outputEmittersPoiFile;

    // Saves variable seed sign definitions for sink detectors to FILE
    QString outputVariableSpeedSignFile;

    // Saves rerouter definitions for sink detectors to FILE
    QString outputEndRerouteFile;

    // Saves validation
    QString outputValidationFile;

    // Add sources to output default: false
    bool outputValidationAddSources;

    // PROCESSING PARAMETERS

    // 	Derive missing flow values from upstream or downstream (not working!); default: false
    bool guessEmptyFlows;

    // Switches to highway-mode; default: false
    bool highwayMode;

    // Only warn about unparseable detectors; default: false
    bool ignoreInvalidDetectors;

    // Recomputes detector types even if given; default: false
    bool revalidateDetectors;

    // Recomputes routes even if given; default: false
    bool revalidateRoutes;

    // Keeps routes even if they have exhausted max-search-depth; default: false
    bool keepUnfinishedRoutes;

    // Keeps routes even if a shorter one exists; default: false
    bool keepLongerRoutes;

    // Number of edges to follow a route without passing a detector; default: 30
    int maxSearchDepth;

    // Writes only emission times; default: false
    bool emissionsOnly;

    // Do not route on these edges
    QString disallowedEdges;

    // Allow turnarounds as route continuations; default: false
    bool keepTurnarounds;

    // Minimum distance in meters between start and end node of every route; default: -1
    qreal minRouteLength;

    // Multiply flow times with TIME to get seconds; default: 60
    int timeFactor;

    // Subtracts TIME seconds from (scaled) flow times; default: 0
    int timeOffset;

    // Expected distance between two successive data sets; default: 60
    int timeStep;

    // Write calibrators to FILE; default: false
    bool calibratorOutput;

    // Include unused routes; default: false
    bool includeUnusedRoutes;

    // Revalidate flows; default: false
    bool revalidateFlows;

    // Removes empty detectors from the list; default: false
    bool removeEmptyDetectors;

    // Strict sources; default: false
    bool strictSources;

    // Try to determine further inflows to an inbetween detector when computing split probabilities; default: false
    bool respectConcurrentInflows;

    // Scale factor for flows; default: 1
    qreal scale;

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

    // Defines the begin time; Previous defs will be discarded; default: 0
    int begin;

    // Defines the end time; Later defs will be discarded; Defaults to one day; default: 86400
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

    // Writes all non-error messages to FILE (implies verbose)
    QString messageLog;

    // Writes all warnings and errors to FILE
    QString errorLog;

    // Lists detectors with no flow (enable -v); default: false
    bool reportEmptyDetectors;

    // Prints aggregated detector flows; default: false
    bool printAbsoluteFlows;

    // Disable console output of route parsing step; default: false
    bool noStepLog;

    // Initialises the random number generator with the current system time; default: false
    bool random;

    // Initialises the random number generator with the given value; default: 23423
    int seed;
};

#endif // DFROUTERDIALOG_H
