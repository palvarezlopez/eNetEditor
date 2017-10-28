#ifndef ENETEDITORMAINWINDOW_H
#define ENETEDITORMAINWINDOW_H

#include "../../main/eNetEditor.h"


namespace Ui
{
class eNetEditorMainWindow;
}

class eNetEditorMainWindow : public QMainWindow, public eNetEditor
{
    Q_OBJECT

public:

    explicit eNetEditorMainWindow();

    ~eNetEditorMainWindow();

    eNetEditorMainConfiguration *geteNetEditorConfiguration() const;

    eNetEditorMessages *getMessages() const;

    QTextBrowser *getConsole() const;

    eNetEditorProjectDialog *geteNetEditorProjectDialog() const;

    eNetEditorProcessingDialog *getProcessingDialog() const;

    nodeTableDialog *getNodeTableDialog() const;

    edgeTableDialog *getEdgeTableDialog() const;

    laneTableDialog *getLaneTableDialog() const;

    connectionTableDialog *getConnectionTableDialog() const;

    prohibitionTableDialog *getProhibitionTableDialog() const;

    routeTableDialog *getRouteTableDialog() const;

    trafficLightTableDialog *getTrafficLightTableDialog() const;

    busStopTableDialog *getBusStopTableDialog() const;

    chargingStationTableDialog *getChargingStationTableDialog() const;

    vehicleTypeTableDialog *getVehicleTypeTableDialog() const;

    vehicleTableDialog *getVehicleTableDialog() const;

    flowTableDialog *getFlowTableDialog() const;

    edgeTypeTableDialog *getEdgeTypeTableDialog() const;

    distributionFunctionTableDialog *getDistributionFunctionTableDialog() const;

    flowMeasureTableDialog *getFlowMeasureTableDialog() const;

    inductionLoopsE1DetectorTableDialog *getinductionLoopsE1DetectorTableDialog() const;

    laneAreaE2DetectorTableDialog *getLaneAreaE2DetectorTableDialog() const;

    multiEntryExitE3DetectorTableDialog *getMultiEntryExitE3DetectorTableDialog() const;

    turnRatioTableDialog *getTurnRatioTableDialog() const;

    turnRatioIntervalTableDialog *getTurnRatioIntervalTableDialog() const;


public slots:

    bool createNewProject(const QString &newProjectName, const QString &newPathRoute, const QString &newImageRoute, int newBeginDuration, int newEndDuration, const openStreetMapPixelMeter &newScale);

    bool openProject(QString filepath);

    bool closeProject();

    void openDialog();


    // Set Functions

    void setActions(bool mode);

    void setUndo(bool mode);

    void setLabelMousePos(qreal x, qreal y);

    void closeEvent(QCloseEvent *event);


private slots:

    // File actions
    void on_ActionNewNetEditorProject_triggered();
    void on_ActionOpenNetEditorProject_triggered();
    void on_ActionSaveNetEditorProject_triggered();
    void on_ActionSaveNetEditorProjectAs_triggered();
    void on_ActionImport_triggered();

    // Add items actions
    void on_ActionAddorRemoveNodeOrEdgeOrLane_triggered();
    void on_ActionAddOrRemoveConnection_triggered();
    void on_ActionAddOrRemoveProhibition_triggered();
    void on_ActionAddOrRemoveTrafficLight_triggered();
    void on_ActionAddOrRemoveRoute_triggered();
    void on_ActionAddOrRemoveBusStop_triggered();
    void on_ActionAddOrRemoveChargingStation_triggered();
    void on_ActionAddOrRemoveDetector_triggered();

    // Edit items actions
    void on_ActionEditVehicleTypes_triggered();
    void on_ActionEditTrafficLights_triggered();
    void on_ActionEditEdgeTypes_triggered();
    void on_ActionShowStatistics_triggered();
    void on_ActionEditVehicles_triggered();
    void on_ActionEditFlows_triggered();

    // Hide/show actions
    void on_ActionShowTag_triggered();
    void on_ActionShowSignals_triggered();

    // Preferences actions
    void on_ActionScalaPreferences_triggered();
    void on_ActionProjectPreferences_triggered();

    // Other actions
    void on_ActionConsole_triggered();
    void on_ActionPreferences_triggered();
    void on_ActionAbout_triggered();
    void on_ActionCloseProject_triggered();
    void on_ActionExit_triggered();

    // Tools
    void on_ActionExecuteNetConvert_triggered();
    void on_ActionExecuteDfRouter_triggered();
    void on_ActionExecuteCadyts_triggered();
    void on_ActionExecuteDuaRouter_triggered();
    void on_ActionExecuteNetGenerator_triggered();
    void on_ActionExecuteJtrRouter_triggered();
    void on_ActionExecuteSumoSimulator_triggered();


private:

    // Main interfaz
    Ui::eNetEditorMainWindow *ui;

    // Loading dialog
    eNetEditorLoadingDialog *eNetEditorLoadingD;

    // These labels cann't not be configured in the UI Editor
    QLabel *labelMousePos;
    QLabel *labelSpinBoxNumberOflanes;
    QLabel *labelProjectName;

    // QSpinBox for the number of lanes
    QSpinBox *spinBoxNumberOfLanes;

    // QCheckBox for double Lane
    QCheckBox *checkboxDoubleLane;

    // NetEditor sub-Dialogs
    eNetEditorAboutDialog *aboutD;
    eNetEditorNewFileDialog *newFileD;
    eNetEditorImportNetDialog *importNetD;
    eNetEditorStatisticsDialog *statisticsD;
    eNetEditorProcessingDialog *processingD;

    // Configuration Dialog
    eNetEditorConfigurationDialog *configurationD;

    // Project Dialogsç
    eNetEditorProjectDialog *projectD;
    scalaDialog *scalaD;

    // Tables Dialog
    nodeTableDialog *nodeTableD;
    edgeTableDialog *edgeTableD;
    laneTableDialog *laneTableD;
    connectionTableDialog *connectionTableD;
    prohibitionTableDialog *prohibitionTableD;
    routeTableDialog *routeTableD;
    trafficLightTableDialog *trafficLightTableD;
    busStopTableDialog *busStopTableD;
    chargingStationTableDialog *chargingStationTableD;
    vehicleTypeTableDialog *vehicleTypeTableD;
    vehicleTableDialog *vehicleTableD;
    flowTableDialog *flowTableD;
    edgeTypeTableDialog *edgeTypeTableD;
    distributionFunctionTableDialog *distributionFunctionTableD;
    flowMeasureTableDialog *flowMeasureTableD;
    inductionLoopsE1DetectorTableDialog *inductionLoopsE1DetectorTableD;
    laneAreaE2DetectorTableDialog *laneAreaE2DetectorTableD;
    multiEntryExitE3DetectorTableDialog *multiEntryExitE3DetectorTableD;
    turnRatioTableDialog *turnRatioTableD;
    turnRatioIntervalTableDialog *turnRatioIntervalTableD;

    // Tools dialog
    cadytsToolDialog *cadytsD;
    dfRouterToolDialog *dfRoutertD;
    duaRouterToolDialog *duaRoutertD;
    jtrRouterToolDialog *jtrRoutertD;
    netConvertToolDialog *netConvertD;
    netGenerateToolDialog *netGeneratetD;
    sumoToolDialog *sumotD;

    // Configuration manager
    eNetEditorMainConfiguration *eNetEditorC;

    // Pointer to actual Project
    eNetEditorProject *actualProject;

    // Pointer to Qobjet to manage messages
    eNetEditorMessages *messages;
};


#endif // ENETEDITORMAINWINDOW_H
