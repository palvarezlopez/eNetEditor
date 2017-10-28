#include "eNetEditorStatisticsDialog.h"
#include "ui_eNetEditorStatisticsDialog.h"

// Main window
#include "eNetEditorMainWindow.h"
// Project
#include "../../database/eNetEditorDatabase.h"

#include "../../project/eNetEditorProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// Tables
#include "../../database/stops/busStopTable.h"
#include "../../database/stops/chargingStationTable.h"
#include "../../database/connectionTable.h"
#include "../../database/detectors/inductionLoopsE1DetectorTable.h"
#include "../../database/detectors/laneAreaE2DetectorTable.h"
#include "../../database/detectors/multiEntryExitE3DetectorTable.h"
#include "../../database/distributionFunctionTable.h"
#include "../../database/edges/edgeTable.h"
#include "../../database/edges/edgeTypeTable.h"
#include "../../database/flowMeasureTable.h"
#include "../../database/laneTable.h"
#include "../../database/nodeTable.h"
#include "../../database/prohibitionTable.h"
#include "../../database/routeTable.h"
#include "../../database/trafficLightTable.h"
#include "../../database/turnRatios/turnRatioTable.h"
#include "../../database/vehicleTypeTable.h"
#include "../../database/vehicles/flowTable.h"
#include "../../database/vehicles/vehicleTable.h"

//Messages
#include "../../main/eNetEditorMessages.h"

eNetEditorStatisticsDialog::eNetEditorStatisticsDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorDialog(eNetEditorMainW), ui(new Ui::eNetEditorStatisticsDialog)
{
    // Create UI
    ui->setupUi(this);
}

eNetEditorStatisticsDialog::~eNetEditorStatisticsDialog()
{
    delete ui;
}

void eNetEditorStatisticsDialog::openDialog(eNetEditorProject *newProject)
{
    // If a pointer to database was defined
    if(newProject != NULL)
    {
        // Link project
        project = newProject;

        // Fill dialog with all information of the database
        ui->TableDatabase->item(0, 0)->setText(QString::number(project->getDatabase()->getNodeTable()->getNumberOfItems()));
        ui->TableDatabase->item(1, 0)->setText(QString::number(project->getDatabase()->getEdgeTable()->getNumberOfItems()));
        ui->TableDatabase->item(2, 0)->setText(QString::number(project->getDatabase()->getLaneTable()->getNumberOfItems()));
        ui->TableDatabase->item(3, 0)->setText(QString::number(project->getDatabase()->getConnectionTable()->getNumberOfItems()));
        ui->TableDatabase->item(4, 0)->setText(QString::number(project->getDatabase()->getProhibitionTable()->getNumberOfItems()));
        ui->TableDatabase->item(5, 0)->setText(QString::number(project->getDatabase()->getBusStopTable()->getNumberOfItems()));
        ui->TableDatabase->item(6, 0)->setText(QString::number(project->getDatabase()->getChargingStationTable()->getNumberOfItems()));
        ui->TableDatabase->item(7, 0)->setText(QString::number(project->getDatabase()->getTrafficLightTable()->getNumberOfItems()));
        ui->TableDatabase->item(8, 0)->setText(QString::number(project->getDatabase()->getRouteTable()->getNumberOfItems()));
        ui->TableDatabase->item(9, 0)->setText(QString::number(project->getDatabase()->getVehicleTypeTable()->getNumberOfItems()));
        ui->TableDatabase->item(10, 0)->setText(QString::number(project->getDatabase()->getFlowTable()->getNumberOfItems()));
        ui->TableDatabase->item(11, 0)->setText(QString::number(project->getDatabase()->getVehicleTable()->getNumberOfItems()));
        ui->TableDatabase->item(12, 0)->setText(QString::number(project->getDatabase()->getEdgeTypeTable()->getNumberOfItems()));
        ui->TableDatabase->item(13, 0)->setText(QString::number(project->getDatabase()->getInductionLoopsE1Table()->getNumberOfItems()));
        ui->TableDatabase->item(14, 0)->setText(QString::number(project->getDatabase()->getLaneAreaE2Table()->getNumberOfItems()));
        ui->TableDatabase->item(15, 0)->setText(QString::number(project->getDatabase()->getMultiEntryExitE3Table()->getNumberOfItems()));
        ui->TableDatabase->item(16, 0)->setText(QString::number(project->getDatabase()->getDistributionFunctionTable()->getNumberOfItems()));
        ui->TableDatabase->item(17, 0)->setText(QString::number(project->getDatabase()->getFlowMeasureTable()->getNumberOfItems()));
        ui->TableDatabase->item(18, 0)->setText(QString::number(project->getDatabase()->getTurnRatioTable()->getNumberOfItems()));

        // Write information in the console
        geteNetEditorMainWindow()->getMessages()->writeInConsole("Opening statitics.");

        // Show dialog
        show();
    }
}

void eNetEditorStatisticsDialog::on_ButtonAccept_released()
{
    // Close Dialog
    close();
}
