#include "eNetEditorMainWindow.h"
#include "ui_eNetEditorMainWindow.h"

// Main Dialogs
#include "eNetEditorAboutDialog.h"
#include "eNetEditorNewFileDialog.h"
#include "eNetEditorImportNetDialog.h"
#include "eNetEditorConfigurationDialog.h"
#include "eNetEditorStatisticsDialog.h"
#include "eNetEditorProcessingDialog.h"
#include "eNetEditorLoadingDialog.h"

// Configuration managers
#include "../../configuration/main/eNetEditorMainConfiguration.h"
#include "../../configuration/items/eNetEditorItemConfiguration.h"
#include "../../configuration/tools/eNetEditorToolConfiguration.h"
#include "../../configuration/project/eNetEditorProjectConfiguration.h"

// Project files
#include "../../project/eNetEditorProject.h"
#include "../../project/eNetEditorScene.h"
#include "../../project/itemManagerProject.h"

// Project Dialogs
#include "../project/eNetEditorProjectDialog.h"
#include "../project/scalaProjectDialog.h"

// Database Dialogs
#include "../database/edges/edgeTableDialog.h"
#include "../database/nodeTableDialog.h"
#include "../database/edges/edgeTableDialog.h"
#include "../database/laneTableDialog.h"
#include "../database/connectionTableDialog.h"
#include "../database/prohibitionTableDialog.h"
#include "../database/routeTableDialog.h"
#include "../database/trafficLightTableDialog.h"
#include "../database/stops/busStopTableDialog.h"
#include "../database/stops/chargingStationTableDialog.h"
#include "../database/vehicleTypeTableDialog.h"
#include "../database/vehicles/vehicleTableDialog.h"
#include "../database/vehicles/flowTableDialog.h"
#include "../database/edges/edgeTypeTableDialog.h"
#include "../database/distributionFunctionTableDialog.h"
#include "../database/flowMeasureTableDialog.h"
#include "../database/detectors/inductionLoopsE1DetectorTableDialog.h"
#include "../database/detectors/laneAreaE2DetectorTableDialog.h"
#include "../database/detectors/multiEntryExitE3DetectorTableDialog.h"
#include "../database/turnRatios/turnRatioTableDialog.h"
#include "../database/turnRatios/turnRatioIntervalTableDialog.h"

// Messages
#include "../../main/eNetEditorMessages.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// Database
#include "../../database/edges/edgeTable.h"
#include "../../database/nodeTable.h"
#include "../../database/edges/edgeTable.h"
#include "../../database/laneTable.h"
#include "../../database/connectionTable.h"
#include "../../database/prohibitionTable.h"
#include "../../database/routeTable.h"
#include "../../database/trafficLightTable.h"
#include "../../database/stops/busStopTable.h"
#include "../../database/stops/chargingStationTable.h"
#include "../../database/vehicleTypeTable.h"
#include "../../database/vehicles/vehicleTable.h"
#include "../../database/vehicles/flowTable.h"
#include "../../database/edges/edgeTypeTable.h"
#include "../../database/distributionFunctionTable.h"
#include "../../database/flowMeasureTable.h"
#include "../../database/detectors/inductionLoopsE1DetectorTable.h"
#include "../../database/detectors/laneAreaE2DetectorTable.h"
#include "../../database/detectors/multiEntryExitE3DetectorTable.h"
#include "../../database/turnRatios/turnRatioTable.h"
#include "../../database/turnRatios/turnRatioIntervalTable.h"

// Items Dialog
#include "../items/stops/busStopItemDialog.h"
#include "../items/stops/chargingStationItemDialog.h"
#include "../items/connectionItemDialog.h"
#include "../items/edges/edgeItemDialog.h"
#include "../items/vehicles/flowItemDialog.h"
#include "../items/laneItemDialog.h"
#include "../items/nodeItemDialog.h"
#include "../items/prohibitionItemDialog.h"
#include "../items/routeItemDialog.h"
#include "../items/trafficLightItemDialog.h"
#include "../items/vehicleTypeItemDialog.h"
#include "../items/vehicles/vehicleItemDialog.h"
#include "../items/detectors/inductionLoopsE1DetectorItemDialog.h"
#include "../items/detectors/laneAreaE2DetectorItemDialog.h"
#include "../items/detectors/multiEntryExitE3DetectorItemDialog.h"

// Externals App Dialogs
#include "../tools/cadytsToolDialog.h"
#include "../tools/dfRouterToolDialog.h"
#include "../tools/duaRouterToolDialog.h"
#include "../tools/jtrRouterToolDialog.h"
#include "../tools/netConvertToolDialog.h"
#include "../tools/netGenerateToolDialog.h"
#include "../tools/sumoToolDialog.h"


eNetEditorMainWindow::eNetEditorMainWindow() : QMainWindow(NULL), ui(new Ui::eNetEditorMainWindow), eNetEditor()
{
    /** should be erased **/
    eNetEditorLoadingD = new eNetEditorLoadingDialog(this);

    //eNetEditorLoadingD->show();

    // Create interfaz
    ui->setupUi(this);

    // Create configuration manager
    eNetEditorC = new eNetEditorMainConfiguration();

    // Create processing dialog
    processingD = new eNetEditorProcessingDialog(this);

    // Create QObjet messages
    messages = new eNetEditorMessages(this);

    // Create netEditor sub-Dialogs
    aboutD = new eNetEditorAboutDialog(this);
    newFileD = new eNetEditorNewFileDialog(this);
    importNetD = new eNetEditorImportNetDialog(this);
    statisticsD = new eNetEditorStatisticsDialog(this);

    // Configuration Dialog
    configurationD = new eNetEditorConfigurationDialog(this);

    // Project dialogs
    projectD = new eNetEditorProjectDialog(this);
    scalaD = new scalaDialog(this);

    // Tables Dialog
    nodeTableD = new nodeTableDialog(this);
    edgeTableD = new edgeTableDialog(this);
    laneTableD = new laneTableDialog(this);
    connectionTableD = new connectionTableDialog(this);
    prohibitionTableD = new prohibitionTableDialog(this);
    routeTableD = new routeTableDialog(this);
    trafficLightTableD = new trafficLightTableDialog(this);
    busStopTableD = new busStopTableDialog(this);
    chargingStationTableD = new chargingStationTableDialog(this);
    vehicleTypeTableD = new vehicleTypeTableDialog(this);
    vehicleTableD = new vehicleTableDialog(this);
    flowTableD = new flowTableDialog(this);
    edgeTypeTableD = new edgeTypeTableDialog(this);
    distributionFunctionTableD = new distributionFunctionTableDialog(this);
    flowMeasureTableD = new flowMeasureTableDialog(this);
    inductionLoopsE1DetectorTableD = new inductionLoopsE1DetectorTableDialog(this);
    laneAreaE2DetectorTableD = new laneAreaE2DetectorTableDialog(this);
    multiEntryExitE3DetectorTableD = new multiEntryExitE3DetectorTableDialog(this);
    turnRatioTableD = new turnRatioTableDialog(this);
    turnRatioIntervalTableD = new turnRatioIntervalTableDialog(this);

    // Create dialog for tools
    cadytsD = new cadytsToolDialog(this);
    dfRoutertD = new dfRouterToolDialog(this);
    duaRoutertD = new duaRouterToolDialog(this);
    jtrRoutertD = new jtrRouterToolDialog(this);
    netConvertD = new netConvertToolDialog(this);
    netGeneratetD = new netGenerateToolDialog(this);
    sumotD = new sumoToolDialog(this);

    // Connect openFlowItemDialog with Flow Table
    connect(routeTableD->getRouteItemDialog(), SIGNAL(openFlowItemDialog(eNetEditorItem *)), flowTableD->getFlowItemDialog(), SLOT(openItemDialog(eNetEditorItem *)));

    // Connect openVehicleItemDialog with Flow Table
    connect(routeTableD->getRouteItemDialog(), SIGNAL(openVehicleItemDialog(eNetEditorItem *)), vehicleTableD->getVehicleItemDialog(), SLOT(openItemDialog(eNetEditorItem *)));

    // Connect flowItemDialog with afterFlowItemDialogClosed
    connect(flowTableD->getFlowItemDialog(), SIGNAL(dialogClosed(eNetEditorItemDialogCloseType)), routeTableD->getRouteItemDialog(), SLOT(afterFlowItemDialogClosed(eNetEditorItemDialogCloseType)));

    // Connect flowItemDialog with afterVehicleItemDialog
    connect(vehicleTableD->getVehicleItemDialog(), SIGNAL(dialogClosed(eNetEditorItemDialogCloseType)), routeTableD->getRouteItemDialog(), SLOT(afterVehicleItemDialog(eNetEditorItemDialogCloseType)));

    // By default, there is no project.
    actualProject = NULL;

    // Disable action Actions
    setActions(false);

    // Disable undo button
    setUndo(false);

    // By default, the console is hidden
    ui->Console->hide();

    // Create label with the mousePos
    labelMousePos = new QLabel(this);

    // By default, the text of mousePos is (-,-)
    labelMousePos->setText(" (-,-) ");

    // Set dimension of mouse pos label
    labelMousePos->setMinimumHeight(30);
    labelMousePos->setMaximumHeight(30);
    labelMousePos->setMinimumWidth(100);
    labelMousePos->setMinimumWidth(100);

    // Set alignment of mouse pos label
    labelMousePos->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    // Create label with the actual number of Nodes
    labelSpinBoxNumberOflanes = new QLabel(this);

    // By default, the text of numberOfNodes is " Nodes: -  "
    labelSpinBoxNumberOflanes->setText(" Number of Lanes ");

    // Create label with the actual name of the project
    labelProjectName = new QLabel(this);

    // By default, the text of projectName is " Project not loaded "
    labelProjectName->setText(" Project not loaded ");

    // Crate SpinBox number of lanes
    spinBoxNumberOfLanes = new QSpinBox;

    // Set size of SpinBox
    spinBoxNumberOfLanes->setMinimumHeight(23);
    spinBoxNumberOfLanes->setMaximumHeight(23);
    spinBoxNumberOfLanes->setMaximumWidth(60);
    spinBoxNumberOfLanes->setMinimumWidth(60);

    // Set value of SpinBox
    spinBoxNumberOfLanes->setValue(1);
    spinBoxNumberOfLanes->setMinimum(1);

    // Create checkbox DoubleLane
    checkboxDoubleLane = new QCheckBox;

    // Check chekboxDoubleLane
    checkboxDoubleLane->setChecked(true);

    // Set text of checkbox
    checkboxDoubleLane->setText(" Double edge ");

    // Set dimensions of checkbox
    checkboxDoubleLane->setMinimumHeight(30);
    checkboxDoubleLane->setMaximumHeight(30);

    // Add label numberOfNodes to toolBarBottom
    ui->toolBarBottom->addWidget(labelProjectName);

    // Add separator
    ui->toolBarBottom->addSeparator();

    // Add spin Box
    ui->toolBarBottom->addWidget(spinBoxNumberOfLanes);

    // Add label numberOfNodes to toolBarBottom
    ui->toolBarBottom->addWidget(labelSpinBoxNumberOflanes);

    // Add separator
    ui->toolBarBottom->addSeparator();

    // Add checkBox double lane
    ui->toolBarBottom->addWidget(checkboxDoubleLane);

    // Add separator
    ui->toolBarBottom->addSeparator();

    // Add label mousePos to toolBarBottom
    ui->toolBarBottom->addWidget(labelMousePos);

    // Disable SpinBox y checkbox
    spinBoxNumberOfLanes->setEnabled(false);
    checkboxDoubleLane->setEnabled(false);

    // Add information about the Net Editor version
    messages->writeInConsole("eNetEditor version " + eNetEditorC->geteNetEditorVersion() + " revision " + eNetEditorC->geteNetEditorRevision(), consoleMessageTypeNormal);
}

eNetEditorMainWindow::~eNetEditorMainWindow()
{
    // Delete project.
    if (actualProject != NULL)
    {
        delete actualProject;
    }

    // Delete interfaz.
    delete ui;

    // delete eNetEditorLoadingD
    delete eNetEditorLoadingD;

    // Delete NetEditor sub-Dialogs
    delete aboutD;
    delete newFileD;
    delete importNetD;
    delete statisticsD;
    delete processingD;

    // Delete configuration Dialog
    delete eNetEditorC;

    // Delete project Dialog
    delete projectD;
    delete scalaD;

    // Delete Tables dialog
    delete nodeTableD;
    delete edgeTableD;
    delete laneTableD;
    delete connectionTableD;
    delete prohibitionTableD;
    delete routeTableD;
    delete trafficLightTableD;
    delete busStopTableD;
    delete chargingStationTableD;
    delete vehicleTypeTableD;
    delete vehicleTableD;
    delete flowTableD;
    delete edgeTypeTableD;
    delete distributionFunctionTableD;
    delete flowMeasureTableD;
    delete inductionLoopsE1DetectorTableD;
    delete laneAreaE2DetectorTableD;
    delete multiEntryExitE3DetectorTableD;
    delete turnRatioTableD;
    delete turnRatioIntervalTableD;

    // Delete dialogs for tools
    delete cadytsD;
    delete dfRoutertD;
    delete duaRoutertD;
    delete jtrRoutertD;
    delete netConvertD;
    delete netGeneratetD;
    delete sumotD;

    // Delete Labels
    delete labelMousePos;
    delete labelSpinBoxNumberOflanes;
    delete labelProjectName;

    // Delete SpinBox
    delete spinBoxNumberOfLanes;

    // Delete checkBox
    delete checkboxDoubleLane;

    // delete QObjet messages
    delete messages;
}

eNetEditorMainConfiguration *eNetEditorMainWindow::geteNetEditorConfiguration() const
{
    return eNetEditorC;
}

void eNetEditorMainWindow::setActions(bool mode)
{
    // File actions
    ui->ActionSaveNetEditorProject->setEnabled(mode);
    ui->ActionSaveNetEditorProjectAs->setEnabled(mode);
    ui->ActionCloseProject->setEnabled(mode);
    ui->ActionUndo->setEnabled(mode);

    // Add Actions
    ui->ActionAddorRemoveNodeOrEdgeOrLane->setEnabled(mode);
    ui->ActionAddOrRemoveConnection->setEnabled(mode);
    ui->ActionAddOrRemoveProhibition->setEnabled(mode);
    ui->ActionAddOrRemoveTrafficLight->setEnabled(mode);
    ui->ActionAddOrRemoveRoute->setEnabled(mode);
    ui->ActionAddOrRemoveBusStop->setEnabled(mode);
    ui->ActionAddOrRemoveChargingStation->setEnabled(mode);
    ui->ActionAddOrRemoveDetector->setEnabled(mode);

    // Edit actions
    ui->ActionEditVehicleTypes->setEnabled(mode);
    ui->ActionEditTrafficLights->setEnabled(mode);
    ui->ActionEditEdgeTypes->setEnabled(mode);
    ui->ActionEditVehicles->setEnabled(mode);
    ui->ActionEditFlows->setEnabled(mode);

    // Show actions
    ui->ActionShowTag->setEnabled(mode);
    ui->ActionShowSignals->setEnabled(mode);

    // Preferences actions
    ui->ActionScalaPreferences->setEnabled(mode);
    ui->ActionProjectPreferences->setEnabled(mode);

    // Statictics actions
    ui->ActionShowStatistics->setEnabled(mode);

    // Tools actions
    ui->ActionExecuteCadyts->setEnabled(mode);
    ui->ActionExecuteDfRouter->setEnabled(mode);
    ui->ActionExecuteDuaRouter->setEnabled(mode);
    ui->ActionExecuteJtrRouter->setEnabled(mode);
    ui->ActionExecuteNetConvert->setEnabled(mode);
    ui->ActionExecuteNetGenerator->setEnabled(mode);
    ui->ActionExecuteSumoSimulator->setEnabled(mode);

    // unchecks Actions
    if(mode == false)
    {
        ui->ActionAddorRemoveNodeOrEdgeOrLane->setChecked(false);
        ui->ActionAddOrRemoveConnection->setChecked(false);
        ui->ActionAddOrRemoveProhibition->setChecked(false);
        ui->ActionAddOrRemoveTrafficLight->setChecked(false);
        ui->ActionAddOrRemoveBusStop->setChecked(false);
        ui->ActionAddOrRemoveChargingStation->setChecked(false);
    }
}

void eNetEditorMainWindow::setUndo(bool mode)
{
    ui->ActionUndo->setEnabled(mode);
}

void eNetEditorMainWindow::openDialog()
{
    // Open netEditor Dialog
    show();
}

bool eNetEditorMainWindow::createNewProject(const QString &newProjectName, const QString &newPathRoute, const QString &newImageRoute, int newBeginDuration, int newEndDuration, const openStreetMapPixelMeter &newScale)
{
    // if previously there is a project created
    if (actualProject)
    {
        // If the project cannot be closed
        if(!closeProject())
        {
            // project not created, then return false.
            return false;
        }
    }

    // Create a new project
    actualProject = new eNetEditorProject(newProjectName, newPathRoute, newImageRoute, newScale, newBeginDuration, newEndDuration, this);

    // remove temporal Layout
    ui->GraphicsViewLayout->removeWidget(ui->TemporalGraphicsView);

    // Add view project to the interfaz
    ui->GraphicsViewLayout->addWidget(actualProject);

    // Enable Actions
    setActions(true);

    // Configure Labels signals
    connect(actualProject->geteNetEditorScene(), SIGNAL(updateMousePos(qreal , qreal)), this, SLOT(setLabelMousePos(qreal , qreal)));

    // Configure Spinbox
    connect(spinBoxNumberOfLanes, SIGNAL(valueChanged(int)), actualProject->geteNetEditorScene(), SLOT(setNumberOfAutomaticLanes(int)));

    // Configure checkbox
    connect(checkboxDoubleLane, SIGNAL(toggled(bool)), actualProject->geteNetEditorScene(), SLOT(setDoubleEdge(bool)));

    // Update labels
    setLabelMousePos(0, 0);
    labelProjectName->setText(" " + actualProject->getProjectName() + " ");

    // project created, then write in console
    messages->writeInConsole("Project \"" + actualProject->getProjectName() + "\" created.", consoleMessageTypeNormal);

    // Project created, then return true
    return true;
}

bool eNetEditorMainWindow::openProject(QString filepath)
{
    // if previously there is a project created
    if (actualProject)
    {
        // If the project cannot be closed
        if(!closeProject())
        {
            // project not opened, then return false.
            return false;
        }
    }

    // Open a existen project
    actualProject = new eNetEditorProject(filepath, this);

    // remove temporal Layout
    ui->GraphicsViewLayout->removeWidget(ui->TemporalGraphicsView);

    // Add view project to the interfaz
    ui->GraphicsViewLayout->addWidget(actualProject);

    // Enable Actions
    setActions(true);

    // Configure Labels signals
    connect(actualProject->geteNetEditorScene(), SIGNAL(updateMousePos(qreal , qreal)), this, SLOT(setLabelMousePos(qreal , qreal)));

    // Update labels
    setLabelMousePos(0, 0);
    labelProjectName->setText(" " + actualProject->getProjectName() + " ");

    // project created, then write in console
    messages->writeInConsole("Project \"" + actualProject->getProjectName() + "\" loaded.", consoleMessageTypeNormal);

    // Project created, then return true
    return true;
}

bool eNetEditorMainWindow::closeProject()
{
    // If the user allow to close project
    if (actualProject->closeProject())
    {
        // Disconet mouse pos
        disconnect(actualProject->geteNetEditorScene(), SIGNAL(updateMousePos(qreal , qreal)), this, SLOT(setLabelMousePos(qreal , qreal)));

        // Disconnect Spinbox
        disconnect(spinBoxNumberOfLanes, SIGNAL(valueChanged(int)), actualProject->geteNetEditorScene(), SLOT(setNumberOfAutomaticLanes(int)));

        // Disconnect checkbox
        disconnect(checkboxDoubleLane, SIGNAL(toggled(bool)), actualProject->geteNetEditorScene(), SLOT(setDoubleEdge(bool)));

        // Set default value of the text of mousePos is (-,-)
        labelMousePos->setText(" (-,-) ");

        // Set default value of text of projectName is " Project not loaded "
        labelProjectName->setText(" Project not loaded ");

        // remove project of the main interface
        ui->GraphicsViewLayout->removeWidget(actualProject);

        // Delete project
        delete actualProject;

        // Set project pointer to null
        actualProject = NULL;

        // Add again the TemporalGraphicsView
        ui->GraphicsViewLayout->addWidget(ui->TemporalGraphicsView);

        // Disable action butons
        setActions(false);

        // Update interface
        update();

        // Project closed, then return true
        return true;
    }
    else
    {
        // Write information in console
        messages->writeInConsole("Closing of project \"" + actualProject->getProjectName() + "\" cancelled by user.", consoleMessageTypeWarning);

        // Project not closed, then return false
        return false;
    }
}

void eNetEditorMainWindow::closeEvent(QCloseEvent *event)
{
    // if the project is not saved
    if ( (actualProject != NULL) && !(actualProject->isSaved()) )
    {
        // Create message box
        QMessageBox messageBox;

        // Config type of message box
        messageBox.setIcon(QMessageBox::Question);

        // Set Text
        messageBox.setText("The project " + actualProject->getProjectName() + " is not saved.");

        // Set Question
        messageBox.setInformativeText("Do you want to save before exit?");

        // Set posible answers
        messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        // Set default option
        messageBox.setDefaultButton(QMessageBox::Yes);

        // Get selected option
        int optionSelected = messageBox.exec();

        // If user push Action "yes"
        if(optionSelected == QMessageBox::Yes)
        {
            // Save before close eNetEditor
            actualProject->save();

            // Accept event and then close eNetEditor
            event->accept();
        }
        // Else if user push Action "no"
        else if (optionSelected == QMessageBox::No)
        {
            // Accept event and then close eNetEditor
            event->accept();
        }
        // Else if user push Action Cancel or close
        else
        {
            // Ignore event and keep eNetEditor opened
            event->ignore();
        }
    }
    // Else if the project is closed/not created and its saved:
    else
    {
        // Accept event and then close eNetEditor
        event->accept();
    }
}

void eNetEditorMainWindow::setLabelMousePos(qreal x, qreal y)
{
    // Update pos of mouse in the status bar
    labelMousePos->setText(" (" + QString::number(x) + "," + QString::number(y) + ") ");
}

void eNetEditorMainWindow::on_ActionNewNetEditorProject_triggered()
{
    // Show the dialog newFile previously created
    newFileD->openDialog(this);
}

void eNetEditorMainWindow::on_ActionOpenNetEditorProject_triggered()
{
    // Open dialog to search net Editor project
    QString filepath = QFileDialog::getOpenFileName(
                           this,
                           "Open Net Editor Project File",
                           eNetEditorC->getProjectConfiguration()->getDefaultProjectFolder(),
                           "Net editor project (*" + eNetEditorC->getProjectConfiguration()->getDefaultProjectExtensionFile() + ")"
                       );

    // If the route is valid (cancel button was not pressed)
    if (filepath != "")
    {
        // Load project
        openProject(filepath);
    }
}

void eNetEditorMainWindow::on_ActionSaveNetEditorProject_triggered()
{
    actualProject->save();
}



void eNetEditorMainWindow::on_ActionAddorRemoveNodeOrEdgeOrLane_triggered()
{
    // If currently there is a project
    if(actualProject)
    {
        // Check and enable or disable the appropriate flag
        if (actualProject->getFlag() == flagOperationAddOrRemoveNodeOrEdgeOrLane)
        {
            actualProject->setFlag(flagOperationNoOperation);
            ui->ActionAddorRemoveNodeOrEdgeOrLane->setChecked(false);

            // Disable SpinBox y checkbox
            spinBoxNumberOfLanes->setEnabled(false);
            checkboxDoubleLane->setEnabled(false);
        }
        else
        {
            actualProject->setFlag(flagOperationAddOrRemoveNodeOrEdgeOrLane);
            ui->ActionAddorRemoveNodeOrEdgeOrLane->setChecked(true);

            // Disable SpinBox y checkbox
            spinBoxNumberOfLanes->setEnabled(true);
            checkboxDoubleLane->setEnabled(true);
        }
    }

    // Disable all other button actions
    ui->ActionAddOrRemoveConnection->setChecked(false);
    ui->ActionAddOrRemoveProhibition->setChecked(false);
    ui->ActionAddOrRemoveTrafficLight->setChecked(false);
    ui->ActionAddOrRemoveRoute->setChecked(false);
    ui->ActionAddOrRemoveBusStop->setChecked(false);
    ui->ActionAddOrRemoveChargingStation->setChecked(false);
    ui->ActionAddOrRemoveDetector->setChecked(false);
}

void eNetEditorMainWindow::on_ActionAddOrRemoveConnection_triggered()
{
    // Check and enable or disable the appropriate flag
    if (actualProject->getFlag() == flagOperationAddOrRemoveConnection)
    {
        actualProject->setFlag(flagOperationNoOperation);
        ui->ActionAddOrRemoveConnection->setChecked(false);
    }
    else
    {
        actualProject->setFlag(flagOperationAddOrRemoveConnection);
        ui->ActionAddOrRemoveConnection->setChecked(true);
    }

    // Disable all other button actions
    ui->ActionAddorRemoveNodeOrEdgeOrLane->setChecked(false);
    ui->ActionAddOrRemoveProhibition->setChecked(false);
    ui->ActionAddOrRemoveTrafficLight->setChecked(false);
    ui->ActionAddOrRemoveRoute->setChecked(false);
    ui->ActionAddOrRemoveBusStop->setChecked(false);
    ui->ActionAddOrRemoveChargingStation->setChecked(false);
    ui->ActionAddOrRemoveDetector->setChecked(false);

    // Disable SpinBox y checkbox
    spinBoxNumberOfLanes->setEnabled(false);
    checkboxDoubleLane->setEnabled(false);
}

void eNetEditorMainWindow::on_ActionAddOrRemoveProhibition_triggered()
{
    // Check and enable or disable the appropriate flag
    if (actualProject->getFlag() == flagOperationAddOrRemoveProhibition)
    {
        actualProject->setFlag(flagOperationNoOperation);
        ui->ActionAddOrRemoveProhibition->setChecked(false);
    }
    else
    {
        actualProject->setFlag(flagOperationAddOrRemoveProhibition);
        ui->ActionAddOrRemoveProhibition->setChecked(true);
    }

    // Disable all other button actions
    ui->ActionAddorRemoveNodeOrEdgeOrLane->setChecked(false);
    ui->ActionAddOrRemoveConnection->setChecked(false);
    ui->ActionAddOrRemoveTrafficLight->setChecked(false);
    ui->ActionAddOrRemoveRoute->setChecked(false);
    ui->ActionAddOrRemoveBusStop->setChecked(false);
    ui->ActionAddOrRemoveChargingStation->setChecked(false);
    ui->ActionAddOrRemoveDetector->setChecked(false);

    // Disable SpinBox y checkbox
    spinBoxNumberOfLanes->setEnabled(false);
    checkboxDoubleLane->setEnabled(false);
}


void eNetEditorMainWindow::on_ActionAddOrRemoveTrafficLight_triggered()
{
    // Check and enable or disable the appropriate flag
    if (actualProject->getFlag() == flagOperationAddOrRemoveTrafficLight)
    {
        actualProject->setFlag(flagOperationNoOperation);
        ui->ActionAddOrRemoveTrafficLight->setChecked(false);
    }
    else
    {
        actualProject->setFlag(flagOperationAddOrRemoveTrafficLight);
        ui->ActionAddOrRemoveTrafficLight->setChecked(true);
    }

    // Disable all other button actions
    ui->ActionAddorRemoveNodeOrEdgeOrLane->setChecked(false);
    ui->ActionAddOrRemoveConnection->setChecked(false);
    ui->ActionAddOrRemoveProhibition->setChecked(false);
    ui->ActionAddOrRemoveRoute->setChecked(false);
    ui->ActionAddOrRemoveBusStop->setChecked(false);
    ui->ActionAddOrRemoveChargingStation->setChecked(false);
    ui->ActionAddOrRemoveDetector->setChecked(false);

    // Disable SpinBox y checkbox
    spinBoxNumberOfLanes->setEnabled(false);
    checkboxDoubleLane->setEnabled(false);
}

void eNetEditorMainWindow::on_ActionAddOrRemoveRoute_triggered()
{
    // Check and enable or disable the appropriate flag
    if (actualProject->getFlag() == flagOperationAddOrRemoveRoute)
    {
        actualProject->setFlag(flagOperationNoOperation);
        ui->ActionAddOrRemoveRoute->setChecked(false);
    }
    else
    {
        actualProject->setFlag(flagOperationAddOrRemoveRoute);
        ui->ActionAddOrRemoveRoute->setChecked(true);
    }

    // Disable all other button actions
    ui->ActionAddorRemoveNodeOrEdgeOrLane->setChecked(false);
    ui->ActionAddOrRemoveConnection->setChecked(false);
    ui->ActionAddOrRemoveProhibition->setChecked(false);
    ui->ActionAddOrRemoveTrafficLight->setChecked(false);
    ui->ActionAddOrRemoveBusStop->setChecked(false);
    ui->ActionAddOrRemoveChargingStation->setChecked(false);
    ui->ActionAddOrRemoveDetector->setChecked(false);

    // Disable SpinBox y checkbox
    spinBoxNumberOfLanes->setEnabled(false);
    checkboxDoubleLane->setEnabled(false);
}

void eNetEditorMainWindow::on_ActionAddOrRemoveBusStop_triggered()
{
    // Check and enable or disable the appropriate flag
    if (actualProject->getFlag() == flagOperationAddOrRemoveBusStop)
    {
        actualProject->setFlag(flagOperationNoOperation);
        ui->ActionAddOrRemoveBusStop->setChecked(false);
    }
    else
    {
        actualProject->setFlag(flagOperationAddOrRemoveBusStop);
        ui->ActionAddOrRemoveBusStop->setChecked(true);
    }

    // Disable all other button actions
    ui->ActionAddorRemoveNodeOrEdgeOrLane->setChecked(false);
    ui->ActionAddOrRemoveConnection->setChecked(false);
    ui->ActionAddOrRemoveProhibition->setChecked(false);
    ui->ActionAddOrRemoveTrafficLight->setChecked(false);
    ui->ActionAddOrRemoveRoute->setChecked(false);
    ui->ActionAddOrRemoveChargingStation->setChecked(false);
    ui->ActionAddOrRemoveDetector->setChecked(false);

    // Disable SpinBox y checkbox
    spinBoxNumberOfLanes->setEnabled(false);
    checkboxDoubleLane->setEnabled(false);
}

void eNetEditorMainWindow::on_ActionAddOrRemoveChargingStation_triggered()
{
    // Check and enable or disable the appropriate flag
    if (actualProject->getFlag() == flagOperationAddOrRemoveChargingStation)
    {
        actualProject->setFlag(flagOperationNoOperation);
        ui->ActionAddOrRemoveChargingStation->setChecked(false);
    }
    else
    {
        actualProject->setFlag(flagOperationAddOrRemoveChargingStation);
        ui->ActionAddOrRemoveChargingStation->setChecked(true);
    }

    // Disable all other button actions
    ui->ActionAddorRemoveNodeOrEdgeOrLane->setChecked(false);
    ui->ActionAddOrRemoveConnection->setChecked(false);
    ui->ActionAddOrRemoveProhibition->setChecked(false);
    ui->ActionAddOrRemoveTrafficLight->setChecked(false);
    ui->ActionAddOrRemoveRoute->setChecked(false);
    ui->ActionAddOrRemoveBusStop->setChecked(false);
    ui->ActionAddOrRemoveDetector->setChecked(false);

    // Disable SpinBox y checkbox
    spinBoxNumberOfLanes->setEnabled(false);
    checkboxDoubleLane->setEnabled(false);
}

void eNetEditorMainWindow::on_ActionAddOrRemoveDetector_triggered()
{
    // Check and enable or disable the appropriate flag
    if (actualProject->getFlag() == flagOperationAddOrRemoveDetector)
    {
        actualProject->setFlag(flagOperationNoOperation);
        ui->ActionAddOrRemoveDetector->setChecked(false);
    }
    else
    {
        actualProject->setFlag(flagOperationAddOrRemoveDetector);
        ui->ActionAddOrRemoveDetector->setChecked(true);
    }

    // Disable all other button actions
    ui->ActionAddorRemoveNodeOrEdgeOrLane->setChecked(false);
    ui->ActionAddOrRemoveConnection->setChecked(false);
    ui->ActionAddOrRemoveProhibition->setChecked(false);
    ui->ActionAddOrRemoveTrafficLight->setChecked(false);
    ui->ActionAddOrRemoveRoute->setChecked(false);
    ui->ActionAddOrRemoveBusStop->setChecked(false);
    ui->ActionAddOrRemoveChargingStation->setChecked(false);

    // Disable SpinBox y checkbox
    spinBoxNumberOfLanes->setEnabled(false);
    checkboxDoubleLane->setEnabled(false);
}

void eNetEditorMainWindow::on_ActionEditVehicleTypes_triggered()
{
    // If the project was created
    if(actualProject != NULL)
    {
        vehicleTypeTableD->openTableDialog(actualProject->getDatabase()->getVehicleTypeTable());
    }
}

void eNetEditorMainWindow::on_ActionEditTrafficLights_triggered()
{
    // If the project was created
    if(actualProject != NULL)
    {
        trafficLightTableD->openTableDialog(actualProject->getDatabase()->getTrafficLightTable());
    }
}

void eNetEditorMainWindow::on_ActionEditEdgeTypes_triggered()
{
    // If the project was created
    if(actualProject != NULL)
    {
        edgeTypeTableD->openTableDialog(actualProject->getDatabase()->getEdgeTypeTable());
    }
}

void eNetEditorMainWindow::on_ActionShowTag_triggered()
{
    // If button show tag is checked
    if(ui->ActionShowTag->isChecked())
    {
        // Show Tags/Labels in the items
        actualProject->setShowLabels(true);
    }
    else
    {
        // Hidde Tags/Labels in the items
        actualProject->setShowLabels(false);
    }
}

void eNetEditorMainWindow::on_ActionShowSignals_triggered()
{
    // If button show icon is checked
    if(ui->ActionShowSignals->isChecked())
    {
        // Show icons in the items
        actualProject->setShowIcons(true);
    }
    else
    {
        // Show icons in the items
        actualProject->setShowIcons(false);
    }
}

void eNetEditorMainWindow::on_ActionAbout_triggered()
{
    // Open about dialog.
    aboutD->show();
}

void eNetEditorMainWindow::on_ActionCloseProject_triggered()
{
    closeProject();
}

void eNetEditorMainWindow::on_ActionSaveNetEditorProjectAs_triggered()
{
    /*
        QString fileName = QFileDialog::getSaveFileName(this,
             tr("Save eNetEditor project"), "",
             tr("Net editor project (*.eneproject);;All Files (*)"));
    */
}

void eNetEditorMainWindow::on_ActionExit_triggered()
{
    // close program.
    close();
}

void eNetEditorMainWindow::on_ActionPreferences_triggered()
{
    // Open preferences dialog
    configurationD->openDialog();
}

void eNetEditorMainWindow::on_ActionScalaPreferences_triggered()
{
    scalaD->openDialog(actualProject);
}

void eNetEditorMainWindow::on_ActionProjectPreferences_triggered()
{
    projectD->openDialog(actualProject);
}

void eNetEditorMainWindow::on_ActionConsole_triggered()
{
    if(ui->Console->isHidden())
    {
        ui->Console->show();
        ui->ActionConsole->setIcon(QIcon(":/main/closeConsole.ico"));
    }
    else
    {
        ui->Console->hide();
        ui->ActionConsole->setIcon(QIcon(":/main/openConsole.ico"));
    }
}

void eNetEditorMainWindow::on_ActionExecuteNetConvert_triggered()
{
    if(actualProject != NULL)
    {
        netConvertD->openDialog(actualProject);
    }
    else
    {
        netConvertD->openDialog(NULL);
    }
}

void eNetEditorMainWindow::on_ActionExecuteDfRouter_triggered()
{
    if(actualProject != NULL)
    {
        dfRoutertD->openDialog(actualProject);
    }
    else
    {
        dfRoutertD->openDialog(NULL);
    }
}

void eNetEditorMainWindow::on_ActionExecuteCadyts_triggered()
{
    if(actualProject != NULL)
    {
        cadytsD->openDialog(actualProject);
    }
    else
    {
        cadytsD->openDialog(NULL);
    }
}

void eNetEditorMainWindow::on_ActionExecuteDuaRouter_triggered()
{
    if(actualProject != NULL)
    {
        duaRoutertD->openDialog(actualProject);
    }
    else
    {
        duaRoutertD->openDialog(NULL);
    }
}

void eNetEditorMainWindow::on_ActionExecuteNetGenerator_triggered()
{
    if(actualProject != NULL)
    {
        netGeneratetD->openDialog(actualProject);
    }
    else
    {
        netGeneratetD->openDialog(NULL);
    }
}

void eNetEditorMainWindow::on_ActionExecuteJtrRouter_triggered()
{
    if(actualProject != NULL)
    {
        jtrRoutertD->openDialog(actualProject);
    }
    else
    {
        jtrRoutertD->openDialog(NULL);
    }
}

void eNetEditorMainWindow::on_ActionExecuteSumoSimulator_triggered()
{
    if(actualProject != NULL)
    {
        sumotD->openDialog(actualProject);
    }
    else
    {
        sumotD->openDialog(NULL);
    }
}

turnRatioTableDialog *eNetEditorMainWindow::getTurnRatioTableDialog() const
{
    return turnRatioTableD;
}

turnRatioIntervalTableDialog *eNetEditorMainWindow::getTurnRatioIntervalTableDialog() const
{
    return turnRatioIntervalTableD;
}

multiEntryExitE3DetectorTableDialog *eNetEditorMainWindow::getMultiEntryExitE3DetectorTableDialog() const
{
    return multiEntryExitE3DetectorTableD;
}

laneAreaE2DetectorTableDialog *eNetEditorMainWindow::getLaneAreaE2DetectorTableDialog() const
{
    return laneAreaE2DetectorTableD;
}

inductionLoopsE1DetectorTableDialog *eNetEditorMainWindow::getinductionLoopsE1DetectorTableDialog() const
{
    return inductionLoopsE1DetectorTableD;
}

flowMeasureTableDialog *eNetEditorMainWindow::getFlowMeasureTableDialog() const
{
    return flowMeasureTableD;
}

distributionFunctionTableDialog *eNetEditorMainWindow::getDistributionFunctionTableDialog() const
{
    return distributionFunctionTableD;
}

edgeTypeTableDialog *eNetEditorMainWindow::getEdgeTypeTableDialog() const
{
    return edgeTypeTableD;
}

flowTableDialog *eNetEditorMainWindow::getFlowTableDialog() const
{
    return flowTableD;
}

vehicleTableDialog *eNetEditorMainWindow::getVehicleTableDialog() const
{
    return vehicleTableD;
}

vehicleTypeTableDialog *eNetEditorMainWindow::getVehicleTypeTableDialog() const
{
    return vehicleTypeTableD;
}

chargingStationTableDialog *eNetEditorMainWindow::getChargingStationTableDialog() const
{
    return chargingStationTableD;
}

busStopTableDialog *eNetEditorMainWindow::getBusStopTableDialog() const
{
    return busStopTableD;
}

trafficLightTableDialog *eNetEditorMainWindow::getTrafficLightTableDialog() const
{
    return trafficLightTableD;
}

routeTableDialog *eNetEditorMainWindow::getRouteTableDialog() const
{
    return routeTableD;
}

prohibitionTableDialog *eNetEditorMainWindow::getProhibitionTableDialog() const
{
    return prohibitionTableD;
}

connectionTableDialog *eNetEditorMainWindow::getConnectionTableDialog() const
{
    return connectionTableD;
}

laneTableDialog *eNetEditorMainWindow::getLaneTableDialog() const
{
    return laneTableD;
}

edgeTableDialog *eNetEditorMainWindow::getEdgeTableDialog() const
{
    return edgeTableD;
}

nodeTableDialog *eNetEditorMainWindow::getNodeTableDialog() const
{
    return nodeTableD;
}

eNetEditorMessages *eNetEditorMainWindow::getMessages() const
{
    return messages;
}

QTextBrowser *eNetEditorMainWindow::getConsole() const
{
    return ui->Console;
}

eNetEditorProjectDialog *eNetEditorMainWindow::geteNetEditorProjectDialog() const
{
    return projectD;
}

eNetEditorProcessingDialog *eNetEditorMainWindow::getProcessingDialog() const
{
    return processingD;
}

void eNetEditorMainWindow::on_ActionImport_triggered()
{
    importNetD->show();
}

void eNetEditorMainWindow::on_ActionShowStatistics_triggered()
{
    if(actualProject != NULL)
    {
        statisticsD->openDialog(actualProject);
    }
}

void eNetEditorMainWindow::on_ActionEditVehicles_triggered()
{
    // If the project was created
    if(actualProject != NULL)
    {
        vehicleTableD->openTableDialog(actualProject->getDatabase()->getVehicleTable());
    }
}

void eNetEditorMainWindow::on_ActionEditFlows_triggered()
{
    // If the project was created
    if(actualProject != NULL)
    {
        flowTableD->openTableDialog(actualProject->getDatabase()->getFlowTable());
    }
}
