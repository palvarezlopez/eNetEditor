#include "laneItemDialog.h"
#include "ui_laneItemDialog.h"

#include "edges/edgeVehicleTypesAllowedDialog.h"

#include "../../database/eNetEditorDatabase.h"
#include "../../database/trafficLightTable.h"

#include "../../project/eNetEditorProject.h"

#include "../../configuration/project/eNetEditorProjectConfiguration.h"

#include "../../configuration/items/vehicleTypeItemConfiguration.h"

#include "../../configuration/items/eNetEditorItemConfiguration.h"

#include "../../items/laneItem.h"
#include "../../items/connectionItem.h"
#include "../../items/prohibitionItem.h"
#include "../../items/vehicleTypeItem.h"
#include "../../items/stops/busStopItem.h"
#include "../../items/stops/chargingStationItem.h"
#include "../../items/detectors/inductionLoopsE1DetectorItem.h"
#include "../../items/detectors/laneAreaE2DetectorItem.h"
#include "../../items/detectors/multiEntryExitE3DetectorItem.h"


laneItemDialog::laneItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorItemDialog(eNetEditorMainW), ui(new Ui::laneItemDialog)
{
    // Set Interface
    ui->setupUi(this);

    // Create vehicle dialog
    vehiclesDialog = new edgeVehicleTypesAllowedDialog(eNetEditorMainW);

    // Create lists
    tmpListOfAllowedVehicles = new QList<vehicleClass>;
    tmpListOfDisallowedVehicles = new QList<vehicleClass>;

    // By default Lane is NULL
    l = NULL;
}

laneItemDialog::~laneItemDialog()
{
    // Delete GUI
    delete ui;

    // Delete vehicle Dialog
    delete vehiclesDialog;

    // Delete list of vehicles
    delete tmpListOfAllowedVehicles;
    delete tmpListOfDisallowedVehicles;
}

void laneItemDialog::resetParameters()
{
    // Speed value can be changed
    tmpSpeed = l->getSpeed();

    // Width can be changed
    tmpWidth = l->getWidth();

    // Set list of vehicles
    tmpListOfAllowedVehicles = l->getListOfAllowedVehicles();
    tmpListOfDisallowedVehicles = l->getListOfDisallowedVehicles();

    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(l->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(l->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(l->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(l->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(l->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(l->getExtraParameter3Value());
}

void laneItemDialog::updateParameters()
{
    // Set ID
    ui->TextLaneID->setText(l->getItemId());
    ui->TextLaneID->setAlignment(Qt::AlignCenter);

    // Set Index
    ui->TextLaneIndex->setText(QString::number(l->getIndex()));
    ui->TextLaneIndex->setAlignment(Qt::AlignCenter);

    // Set speed
    ui->TextSpeed->setText(QString::number(tmpSpeed));
    ui->TextSpeed->setAlignment(Qt::AlignCenter);

    // Set Width
    ui->TextWidth->setText(QString::number(tmpWidth));
    ui->TextWidth->setAlignment(Qt::AlignCenter);

    // If custom parameter 1 was changed
    if(l->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(l->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(l->getExtraParameter1Value());
        ui->TextCustomParameter1Value->setAlignment(Qt::AlignCenter);
    }
    else
    {
        // Change Button text to default
        ui->ButtonCustomParameter1Name->setText("Custom parameter 1");

        // Disable Text
        ui->TextCustomParameter1Value->setEnabled(false);

        // Remove Text
        ui->TextCustomParameter1Value->setText("");
        ui->TextCustomParameter1Value->setAlignment(Qt::AlignCenter);
    }

    // If custom parameter 2 was changed
    if(l->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(l->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(l->getExtraParameter2Value());
        ui->TextCustomParameter2Value->setAlignment(Qt::AlignCenter);
    }
    else
    {
        // Change Button text to default
        ui->ButtonCustomParameter2Name->setText("Custom parameter 2");

        // Disable Text
        ui->TextCustomParameter2Value->setEnabled(false);

        // Remove Text
        ui->TextCustomParameter2Value->setText("");
        ui->TextCustomParameter2Value->setAlignment(Qt::AlignCenter);
    }

    // If custom parameter 3 was changed
    if(l->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(l->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(l->getExtraParameter3Value());
        ui->TextCustomParameter3Value->setAlignment(Qt::AlignCenter);
    }
    else
    {
        // Change Button text to default
        ui->ButtonCustomParameter3Name->setText("Custom parameter 3");

        // Disable Text
        ui->TextCustomParameter3Value->setEnabled(false);

        // Remove Text
        ui->TextCustomParameter3Value->setText("");
        ui->TextCustomParameter3Value->setAlignment(Qt::AlignCenter);
    }

    // Update list of vehicles
    updateListVehicleTypes();

    // Update rest of list of elements
    updateListOfElements();
}

void laneItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to lane
    l = dynamic_cast<laneItem *>(item);

    // if item is a lane
    if(l)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Show Dialog
        show();
    }
}

void laneItemDialog::updateListVehicleTypes()
{
    // Clear UI list of vehicles
    ui->ListAllowVehicles->clear();
    ui->ListDisallowVehicles->clear();

    // Set temporal list of allowedvehicles
    for (QList<vehicleClass>::iterator i = tmpListOfAllowedVehicles->begin(); i != tmpListOfAllowedVehicles->end(); i++)
    {
        ui->ListAllowVehicles->addItem(new QListWidgetItem(l->getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeClassValue(*i)));
    }

    // Set Label
    ui->LabelAllowVehicles->setText("Allowed vehicles: " + QString::number(tmpListOfAllowedVehicles->size()));
    ui->LabelAllowVehicles->setAlignment(Qt::AlignCenter);

    // Set temporal list of disallowedvehicles
    for (QList<vehicleClass>::iterator i = tmpListOfDisallowedVehicles->begin(); i != tmpListOfDisallowedVehicles->end(); i++)
    {
        ui->ListDisallowVehicles->addItem(new QListWidgetItem(l->getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeClassValue(*i)));
    }

    // Set Label
    ui->LabelDisallowVehicles->setText("Disallowed vehicles: " + QString::number(tmpListOfDisallowedVehicles->size()));
    ui->LabelDisallowVehicles->setAlignment(Qt::AlignCenter);
}

void laneItemDialog::on_ButtonCustomParameter1Name_released()
{
    // Get QString with the name of parameter
    setTmpExtraParameter1Name(QInputDialog::getText(this, "Custom parameter 1", "Name of custom parameter 1"));

    // If tmpExtraParameter1Name != ""
    if(getTmpExtraParameter1Name() != "")
    {
        // Enable custom parameter value
        ui->TextCustomParameter1Value->setEnabled(true);

        // Set text in button
        ui->ButtonCustomParameter1Name->setText(getTmpExtraParameter1Name());
    }
    else
    {
        // Disable custom parameter value
        ui->TextCustomParameter1Value->setEnabled(false);

        // Clear text
        ui->TextCustomParameter1Value->setText("");

        // Set text in button
        ui->ButtonCustomParameter1Name->setText("Custom parameter 1");
    }
}

void laneItemDialog::on_ButtonCustomParameter2Name_released()
{
    // Get QString with the name of parameter
    setTmpExtraParameter2Name(QInputDialog::getText(this, "Custom parameter 2", "Name of custom parameter 2"));

    // If tmpExtraParameter2Name != ""
    if(getTmpExtraParameter2Name() != "")
    {
        // Enable custom parameter value
        ui->TextCustomParameter2Value->setEnabled(true);

        // Set text in button
        ui->ButtonCustomParameter2Name->setText(getTmpExtraParameter2Name());
    }
    else
    {
        // Disable custom parameter value
        ui->TextCustomParameter2Value->setEnabled(false);

        // Clear text
        ui->TextCustomParameter2Value->setText("");

        // Set text in button
        ui->ButtonCustomParameter2Name->setText("Custom parameter 2");
    }
}

void laneItemDialog::on_ButtonCustomParameter3Name_released()
{
    // Get QString with the name of parameter
    setTmpExtraParameter3Name(QInputDialog::getText(this, "Custom parameter 3", "Name of custom parameter 3"));

    // If tmpExtraParameter3Name != ""
    if(getTmpExtraParameter3Name() != "")
    {
        // Enable custom parameter value
        ui->TextCustomParameter3Value->setEnabled(true);

        // Set text in button
        ui->ButtonCustomParameter3Name->setText(getTmpExtraParameter3Name());
    }
    else
    {
        // Disable custom parameter value
        ui->TextCustomParameter3Value->setEnabled(false);

        // Clear text
        ui->TextCustomParameter3Value->setText("");

        // Set text in button
        ui->ButtonCustomParameter3Name->setText("Custom parameter 3");
    }
}

void laneItemDialog::on_TextCustomParameter1Value_textChanged()
{
    setTmpExtraParameter1Value(ui->TextCustomParameter1Value->toPlainText());
}

void laneItemDialog::on_TextCustomParameter2Value_textChanged()
{
    setTmpExtraParameter2Value(ui->TextCustomParameter2Value->toPlainText());
}

void laneItemDialog::on_TextCustomParameter3Value_textChanged()
{
    setTmpExtraParameter3Value(ui->TextCustomParameter3Value->toPlainText());
}

void laneItemDialog::on_TextSpeed_textChanged()
{
    // Set speed from Text to tmpSpeed
    tmpSpeed = ui->TextSpeed->toPlainText().toDouble();
}

void laneItemDialog::on_TextWidth_textChanged()
{
    // Set width from Text to tmpWidth
    tmpWidth = ui->TextWidth->toPlainText().toDouble();
}

void laneItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog without saving
    close();
}

void laneItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void laneItemDialog::on_ButtonAccept_released()
{
    // Set new Speed.
    l->setSpeed(tmpSpeed);

    // Set new width
    l->setWidth(tmpWidth);

    // If custom parameter 1 has been modified
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        // Set name and value of custom parameter 1 in the item
        l->setExtraParameter1Name(getTmpExtraParameter1Name());
        l->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // If custom parameter 2 has been modified
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        // Set name and value of custom parameter 2 in the item
        l->setExtraParameter2Name(getTmpExtraParameter2Name());
        l->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // If custom parameter 3 has been modified
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        // Set name and value of custom parameter 3 in the item
        l->setExtraParameter3Name(getTmpExtraParameter3Name());
        l->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Set new list of vehicles
    l->setListOfAllowedVehicles(*tmpListOfAllowedVehicles);
    l->setListOfDisalllowedVehicles(*tmpListOfDisallowedVehicles);

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close when all parameters were saved
    close();
}

void laneItemDialog::on_ListAllowVehicles_itemDoubleClicked(QListWidgetItem *item)
{
    // In this case QListWidgetItem is not neccesary
    Q_UNUSED(item);

    vehiclesDialog->openDialog(tmpListOfAllowedVehicles, tmpListOfDisallowedVehicles, this);
}

void laneItemDialog::on_ListDisallowVehicles_itemDoubleClicked(QListWidgetItem *item)
{
    // In this case QListWidgetItem is not neccesary
    Q_UNUSED(item);

    vehiclesDialog->openDialog(tmpListOfAllowedVehicles, tmpListOfDisallowedVehicles, this);
}

void laneItemDialog::on_ListConnections_itemDoubleClicked(QListWidgetItem *item)
{

}

void laneItemDialog::on_ListProhibitions_itemDoubleClicked(QListWidgetItem *item)
{

}

void laneItemDialog::on_ListBusStops_itemDoubleClicked(QListWidgetItem *item)
{

}

void laneItemDialog::on_ListChargingStations_itemDoubleClicked(QListWidgetItem *item)
{

}

void laneItemDialog::on_ListDetectorsE1_itemDoubleClicked(QListWidgetItem *item)
{

}

void laneItemDialog::on_ListDetectorsE2_itemDoubleClicked(QListWidgetItem *item)
{

}

void laneItemDialog::on_ListDetectorsE3_itemDoubleClicked(QListWidgetItem *item)
{

}

void laneItemDialog::updateListOfElements()
{
    // Declare list of id's of items
    QStringList idsOfItems;

    // Get List of incomings Connections
    for (QList<connectionItem *>::iterator i = l->iteratorIncomingsConnectionsBegin(); i != l->iteratorIncomingsConnectionsEnd(); i++)
    {
        idsOfItems << (*i)->getItemId();
    }

    // Get List of outcomings Connections
    for (QList<connectionItem *>::iterator i = l->iteratorOutcomingsConnectionsBegin(); i != l->iteratorOutcomingsConnectionsBegin(); i++)
    {
        idsOfItems << (*i)->getItemId();
    }

    // Set number of connections in the Label
    ui->LabelConnections->setText("Connections: " + QString::number(idsOfItems.size()));
    ui->LabelConnections->setAlignment(Qt::AlignCenter);

    // Clear list
    ui->ListConnections->clear();

    // Set list of connections
    for (QStringList::iterator i = idsOfItems.begin(); i != idsOfItems.end(); i++)
    {
        ui->ListConnections->addItem(new QListWidgetItem((*i)));
    }

    // Clear list of id's
    idsOfItems.clear();

    // Get List of incomings Prohibitions
    for (QList<prohibitionItem *>::iterator i = l->iteratorIncomingsProhibitionsBegin(); i != l->iteratorIncomingsProhibitionsEnd(); i++)
    {
        idsOfItems << (*i)->getItemId();
    }

    // Get List of outcomings Prohibitions
    for (QList<prohibitionItem *>::iterator i = l->iteratorOutcomingsProhibitionsBegin(); i != l->iteratorOutcomingsProhibitionsEnd(); i++)
    {
        idsOfItems << (*i)->getItemId();
    }

    // Set number of Prohibitions in the Label
    ui->LabelProhibions->setText("Prohibitions: " + QString::number(idsOfItems.size()));
    ui->LabelProhibions->setAlignment(Qt::AlignCenter);

    // Clear list
    ui->ListProhibitions->clear();

    // Set list of Prohibitions
    for (QStringList::iterator i = idsOfItems.begin(); i != idsOfItems.end(); i++)
    {
        ui->ListProhibitions->addItem(new QListWidgetItem((*i)));
    }

    // Clear list of id's
    idsOfItems.clear();

    // Get List of Bus Stops
    for (QList<busStopItem *>::iterator i = l->iteratorBusStopsBegin(); i != l->iteratorBusStopsEnd(); i++)
    {
        idsOfItems << (*i)->getItemId();
    }

    // Set number of Bus Stops in the Label
    ui->LabelBusStops->setText("Bus Stops: " + QString::number(idsOfItems.size()));
    ui->LabelBusStops->setAlignment(Qt::AlignCenter);

    // Clear list
    ui->ListBusStops->clear();

    // Set list of Bus Stops
    for (QStringList::iterator i = idsOfItems.begin(); i != idsOfItems.end(); i++)
    {
        ui->ListBusStops->addItem(new QListWidgetItem((*i)));
    }

    // Clear list of id's
    idsOfItems.clear();

    // Get List of Charging Stations
    for (QList<chargingStationItem *>::iterator i = l->iteratorChargingStationsBegin(); i != l->iteratorChargingStationsEnd(); i++)
    {
        idsOfItems << (*i)->getItemId();
    }

    // Set number of Charging Stations in the Label
    ui->LabelChargingStations->setText("Charging Stations: " + QString::number(idsOfItems.size()));
    ui->LabelChargingStations->setAlignment(Qt::AlignCenter);

    // Clear list
    ui->ListChargingStations->clear();

    // Set list of Charging Stations
    for (QStringList::iterator i = idsOfItems.begin(); i != idsOfItems.end(); i++)
    {
        ui->ListChargingStations->addItem(new QListWidgetItem((*i)));
    }

    // Clear list of id's
    idsOfItems.clear();

    // Get List of E1 Detectors
    for (QList<inductionLoopsE1DetectorItem *>::iterator i = l->iteratorInductionLoopsE1DetectorBegin(); i != l->iteratorInductionLoopsE1DetectorEnd(); i++)
    {
        idsOfItems << (*i)->getItemId();
    }

    // Set number E1 Detectors in the Label
    ui->LabelDetectorsE1->setText("Induction Loop E1: " + QString::number(idsOfItems.size()));
    ui->LabelDetectorsE1->setAlignment(Qt::AlignCenter);

    // Clear list
    ui->ListDetectorsE1->clear();

    // Set list of E1 Detectors
    for (QStringList::iterator i = idsOfItems.begin(); i != idsOfItems.end(); i++)
    {
        ui->ListDetectorsE1->addItem(new QListWidgetItem((*i)));
    }

    // Clear list of id's
    idsOfItems.clear();

    // Get List of E2 Detectors
    for (QList<laneAreaE2DetectorItem *>::iterator i = l->iteratorLaneAreaE2DetectorBegin(); i != l->iteratorLaneAreaE2DetectorEnd(); i++)
    {
        idsOfItems << (*i)->getItemId();
    }

    // Set number of Charging Stations in the Label
    ui->LabelDetectorsE2->setText("Lane Area E2: " + QString::number(idsOfItems.size()));
    ui->LabelDetectorsE2->setAlignment(Qt::AlignCenter);

    // Clear list
    ui->ListDetectorsE2->clear();

    // Set list of E2 Detectors
    for (QStringList::iterator i = idsOfItems.begin(); i != idsOfItems.end(); i++)
    {
        ui->ListDetectorsE2->addItem(new QListWidgetItem((*i)));
    }

    // Clear list of id's
    idsOfItems.clear();

    // Get List of E3 Detectors
    for (QList<multiEntryExitE3DetectorItem *>::iterator i = l->iteratorMultiEntryExitE3DetectorBegin(); i != l->iteratorMultiEntryExitE3DetectorEnd(); i++)
    {
        idsOfItems << (*i)->getItemId();
    }

    // Set number of E3 Detectors in the Label
    ui->LabelDetectorsE3->setText("Multi Entry Exit E3: " + QString::number(idsOfItems.size()));
    ui->LabelDetectorsE3->setAlignment(Qt::AlignCenter);

    // Clear list
    ui->ListDetectorsE3->clear();

    // Set list of Charging Stations
    for (QStringList::iterator i = idsOfItems.begin(); i != idsOfItems.end(); i++)
    {
        ui->ListDetectorsE3->addItem(new QListWidgetItem((*i)));
    }
}
