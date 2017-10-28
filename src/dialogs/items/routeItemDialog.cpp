#include "routeItemDialog.h"
#include "ui_routeItemDialog.h"

#include "vehicles/vehicleItemDialog.h"
#include "vehicles/flowItemDialog.h"

#include "../../database/eNetEditorDatabase.h"

#include "../../items/routeItem.h"
#include "../../items/edges/edgeItem.h"
#include "../../items/vehicles/vehicleItem.h"
#include "../../items/vehicles/flowItem.h"


routeItemDialog::routeItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorItemDialog(eNetEditorMainW), ui(new Ui::routeItemDialog)
{
    // Create UI
    ui->setupUi(this);

    // Set pointer to route NULL
    r = NULL;

    // Set pointer to Vehicle NULL
    v = NULL;

    // Set pointer to Flow NULL
    f = NULL;
}

routeItemDialog::~routeItemDialog()
{
    // Delete UI
    delete ui;
}

void routeItemDialog::resetParameters()
{
    // Set temporal Color
    tmpColor = r->getColor();

    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(r->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(r->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(r->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(r->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(r->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(r->getExtraParameter3Value());
}

void routeItemDialog::updateParameters()
{
    // Set ID
    ui->TextRouteID->setText(r->getItemId());
    ui->TextRouteID->setAlignment(Qt::AlignCenter);

    // Set Color
    ui->TextColor->setText(tmpColor);
    ui->TextColor->setAlignment(Qt::AlignCenter);

    // Clear list of edges
    ui->ListOfEdges->clear();

    // Declare counter
    int edgeCounter = 0;

    // Fill list of lanes in the UI
    for (QList<edgeItem *>::iterator i = r->getListOfEdges()->begin(); i != r->getListOfEdges()->end(); i++)
    {
        // Add edge to list
        ui->ListOfEdges->addItem(new QListWidgetItem("Edge number " + QString::number(edgeCounter) + ": " + (*i)->getItemId()));

        // Update counter
        edgeCounter++;
    }

    // Clear list of vehicles
    ui->ListOfVehicles->clear();

    // Fill list of vehicles in the UI
    for (QList<vehicleItem *>::iterator i = r->getListOfVehicles()->begin(); i != r->getListOfVehicles()->end(); i++)
    {
        // Add vehicle to list
        ui->ListOfVehicles->addItem(new QListWidgetItem((*i)->getItemId()));
    }

    // Clear list of flows
    ui->ListOfFlows->clear();

    // Fill list of vehicles in the UI
    for (QList<flowItem *>::iterator i = r->getListOfFlows()->begin(); i != r->getListOfFlows()->end(); i++)
    {
        // Add vehicle to list
        ui->ListOfFlows->addItem(new QListWidgetItem((*i)->getItemId()));
    }

    // If custom parameter 1 was changed
    if(r->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(r->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(r->getExtraParameter1Value());
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
    if(r->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(r->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(r->getExtraParameter2Value());
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
    if(r->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(r->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(r->getExtraParameter3Value());
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
}

void routeItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to route
    r = dynamic_cast<routeItem *>(item);

    // If item is a route
    if(r)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Show Dialog
        show();
    }
}

void routeItemDialog::afterFlowItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{
    // If dialog was closed using cancel cancel and exists a flow
    if(closeCode == eNetEditorItemDialogCloseCanceled && f != NULL)
    {
        // Remove created flow of database
        delete f;
    }

    // Set flow NULL
    f = NULL;

    // Update parameters
    updateParameters();
}

void routeItemDialog::afterVehicleItemDialog(eNetEditorItemDialogCloseType closeCode)
{
    // If dialog was closed using cancel and exists a vehicle
    if(closeCode == eNetEditorItemDialogCloseCanceled && v != NULL)
    {
        // Remove created flow of database
        delete v;
    }

    // Set Vehicle NULL
    v = NULL;

    // Update parameters
    updateParameters();
}

void routeItemDialog::on_ButtonAddVehicle_released()
{
    // insert new vehicle in database
    v = new vehicleItem("", r->getDatabase()->getVehicleTypeOfTable(0), r, r->getDatabase());

    // Emit signal to pen Vehicle Dialog
    emit openVehicleItemDialog(dynamic_cast<eNetEditorItem *>(v));
}

void routeItemDialog::on_ButtonAddFlow_released()
{
    // insert new flow in database
    f = new flowItem("", r->getDatabase()->getVehicleTypeOfTable(0), r, r->getDatabase());

    // Emit signal to pen Vehicle Dialog
    emit openFlowItemDialog(dynamic_cast<eNetEditorItem *>(f));
}

void routeItemDialog::on_ButtonAccept_released()
{
    // Set new Color in route
    r->setColor(tmpColor);

    // If custom parameter 1 has been modified
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        // Set name and value of custom parameter 1 in the item
        r->setExtraParameter1Name(getTmpExtraParameter1Name());
        r->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // If custom parameter 2 has been modified
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        // Set name and value of custom parameter 2 in the item
        r->setExtraParameter2Name(getTmpExtraParameter2Name());
        r->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // If custom parameter 3 has been modified
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        // Set name and value of custom parameter 3 in the item
        r->setExtraParameter3Name(getTmpExtraParameter3Name());
        r->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    //Close dialog
    close();
}

void routeItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    //Close dialog
    close();
}

void routeItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void routeItemDialog::on_ButtonCustomParameter1Name_released()
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

void routeItemDialog::on_ButtonCustomParameter2Name_released()
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

void routeItemDialog::on_ButtonCustomParameter3Name_released()
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

void routeItemDialog::on_TextCustomParameter1Value_textChanged()
{
    setTmpExtraParameter1Value(ui->TextCustomParameter1Value->toPlainText());
}

void routeItemDialog::on_TextCustomParameter2Value_textChanged()
{
    setTmpExtraParameter2Value(ui->TextCustomParameter2Value->toPlainText());
}

void routeItemDialog::on_TextCustomParameter3Value_textChanged()
{
    setTmpExtraParameter3Value(ui->TextCustomParameter3Value->toPlainText());
}

void routeItemDialog::on_ListOfFlows_itemDoubleClicked(QListWidgetItem *item)
{
    // Remove flow
    delete (r->getDatabase()->findFlowById(item->text()));

    // Update parameters
    updateParameters();
}

void routeItemDialog::on_TextColor_textChanged()
{
    // Get text from Color
    tmpColor = ui->TextColor->toPlainText();
}
