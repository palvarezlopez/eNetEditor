#ifndef DUAROUTERDIALOG_H
#define DUAROUTERDIALOG_H

#include "eNetEditorToolDialog.h"


namespace Ui
{
class duaRouterToolDialog;
}

class duaRouterToolDialog : public eNetEditorToolDialog
{
    Q_OBJECT

public:

    explicit duaRouterToolDialog(eNetEditorMainWindow *neweNetEditorMainW);

    ~duaRouterToolDialog();


public slots:

    void openDialog(eNetEditorProject *newProject);

    void resetParameters()
    {

    }

    void updateParameters()
    {

    }


private slots:

    void setInputParameters()
    {

    }

    void setOutputParameters()
    {

    }

    void setProcessingParameters()
    {

    }

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_ButtonReset_released();

    void on_ButtonSearchAdditionalFiles_released();

    void on_ButtonSearchAlternativeFiles_released();

    void on_ButtonSearchFlowFiles_released();

    void on_ButtonSearchLaneWeightFiles_released();

    void on_ButtonSearchPhemlightPath_released();

    void on_ButtonSearchRouteFiles_released();

    void on_ButtonSearchSumoNetwork_released();

    void on_ButtonSearchTripFiles_released();

    void on_ButtonSearchWeightAttribute_released();

    void on_ButtonSearchWeightFiles_released();

    void on_TextAdditionalFiles_textChanged();

    void on_TextAlternativeFiles_textChanged();

    void on_TextFlowFiles_textChanged();

    void on_TextLaneWeightFiles_textChanged();

    void on_TextPhemlightPath_textChanged();

    void on_TextRouteFiles_textChanged();

    void on_TextSumoNetwork_textChanged();

    void on_TextTripFiles_textChanged();

    void on_TextWeightAttribute_textChanged();

    void on_TextWeightFiles_textChanged();

    void on_ButtonSearchOutputFIle_released();

    void on_ButtonSearchVTypeOutput_released();

    void on_TextOutputFile_textChanged();

    void on_TextVTypeOutput_textChanged();

    void on_TextArrivalLane_textChanged();

    void on_TextArrivalPos_textChanged();

    void on_TextArrivalSpeed_textChanged();

    void on_TextDepartLane_textChanged();

    void on_TextDepartPos_textChanged();

    void on_TextDepartSpeed_textChanged();

    void on_TextTimeBegin_textChanged();

    void on_TextTimeEnd_textChanged();

    void on_TextLogitBeta_textChanged();

    void on_TextLogitGanma_textChanged();

    void on_TextLogitTheta_textChanged();

    void on_TextMaxAlternatives_textChanged();

    void on_TextRouteChoiceMethod_textChanged();

    void on_TextRouteSteps_textChanged();

    void on_TextRoutingAlgorithm_textChanged();

    void on_TextRoutingThreads_textChanged();

    void on_TextWeightPeriod_textChanged();

    void on_TextSeed_textChanged();


private:

    // UI
    Ui::duaRouterToolDialog *ui;

    // duaRouter Tool
    duaRouterTool *duaRouterT;


    // INPUT PARAMETERS

    // 	Use FILE as SUMO-network to route on
    QString inputNetFile;

    // Read additional network data (districts, bus stops) from FILE
    QString inputAdditionalFile;

    // Read alternatives from FILE
    QString inputAlternativeFile;

    // Read flow-definitions from FILE(s)
    QString inputFlowFile;

    // Read network weights from FILE(s)
    QString inputWeightFiles;

    // Read lane-based network weights from FILE(s)
    QString inputLaneWeightFiles;

    // Name of the xml attribute which gives the edge weight; default: traveltime
    QString inputWeightAttribute;

    // Determines where to load PHEMlight definitions from.; default: ./PHEMlight/
    QString inputPhemlightPath;

    // Read trip-definitions from FILE(s)
    QString inputTripFiles;

    // Read sumo-routes from FILE(s)
    QString inputRouteFiles;


    // OUTPUT PARAMETERS

    // Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    QString outputPrefixFile;

    // Write generated routes to FILE
    QString outputFile;

    // Write used vehicle types into separate FILE
    QString outputVtypeFile;

    // Write exit times (weights) for each edge; default: false
    bool outputExitTimes;


    // PROCESSING PARAMETERS

    // Continue if a route could not be build; default: false
    bool processingIgnoreErrors;

    // Assume input is unsorted; default: false
    bool processingUnsortedInput;

    // Load routes for the next number of seconds ahead; default: 200
    int processingRouteSteps;

    // Generate random departure times for flow input; default: false
    bool processingRandomizeFlows;

    // Prune the number of alternatives to INT; default: 5
    int processingMaxAlternatives;

    // Remove loops within the route; Remove turnarounds at start and end of the route; default: false
    bool processingRemoveLoops;

    // Tries to correct a false route; default: false
    bool processingRepair;

    // Interpolate edge weights at interval boundaries; default: false
    bool processingWeightsInterpolate;

    // Use origin and destination zones (districts) for in- and output; default: false
    bool processingWithTaz;

    // Select among routing algorithms ['dijkstra', 'astar', 'bulkstar', 'CH', 'CHWrapper']; default: dijkstra
    QString processingRoutingAlgorithm;

    // Aggregation period for the given weight files; triggers rebuilding of Contraction Hierarchy; default: 3600
    int processingWeightPeriod;

    // The number of parallel execution threads used for routing; default: 0
    int processingRoutingThreads;

    // Expand weights behind the simulation's end; default: false
    bool processingWeightsExpand;

    // Use FLOAT as Gawron's beta; default: 0.3
    qreal processingGawronBeta;

    // Use FLOAT as Gawron's a; default: 0.05
    qreal processingGawronA;

    // Save routes with near zero probability; default: false
    bool processingKeepAllRoutes;

    // Only reuse routes from input, do not calculate new ones; default: false
    bool processingSkipNewRoutes;

    // Use c-logit model (deprecated in favor of processingroute-choice-method logit); default: false
    bool processingLogit;

    // Choose a route choice method: gawron, logit, or lohse; default: gawron
    QString processingRouteChoiceMethod;

    // Use FLOAT as logit's beta; default: -1
    qreal processingLogitBeta;

    // Use FLOAT as logit's gamma; default: 1
    qreal processingLogitGamma;

    // Use FLOAT as logit's theta (negative values mean auto-estimation); default: -1
    qreal processingLogitTheta;
};

#endif // DUAROUTERDIALOG_H
