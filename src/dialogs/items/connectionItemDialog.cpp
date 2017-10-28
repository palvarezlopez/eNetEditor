#include "connectionItemDialog.h"
#include "ui_connectionItemDialog.h"

#include "../../database/eNetEditorDatabase.h"

#include "../../items/connectionItem.h"
#include "../../items/trafficLightItem.h"
#include "../../items/edges/edgeItem.h"
#include "../../items/laneItem.h"


connectionItemDialog::connectionItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorItemDialog(eNetEditorMainW), ui(new Ui::connectionItemDialog)
{
    // Setup UI
    ui->setupUi(this);

    // At beggin, the connection is null
    c = NULL;
}

connectionItemDialog::~connectionItemDialog()
{
    // delete UI
    delete ui;
}

void connectionItemDialog::resetParameters()
{
    // Temporal variable pass
    tmpPass = c->isPassEnabled();

    // Temporal vector of states
    vectorOfStates = c->getVectorOfStates();

    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(c->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(c->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(c->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(c->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(c->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(c->getExtraParameter3Value());
}

void connectionItemDialog::updateParameters()
{
    // Set Id
    ui->TextID->setText(c->getItemId());
    ui->TextID->setAlignment(Qt::AlignCenter);

    // Set edge origin
    ui->TextFromEdge->setText(c->getEdgeOrigin()->getItemId());
    ui->TextFromEdge->setAlignment(Qt::AlignCenter);

    // Set edge destiny
    ui->TextToEdge->setText(c->getEdgeDestiny()->getItemId());
    ui->TextToEdge->setAlignment(Qt::AlignCenter);

    // Set lane origin
    ui->TextFromLane->setText(c->getLaneOrigin()->getItemId());
    ui->TextFromLane->setAlignment(Qt::AlignCenter);

    // Set lane Destiny
    ui->TextToLane->setText(c->getLaneDestiny()->getItemId());
    ui->TextToLane->setAlignment(Qt::AlignCenter);

    // Set link index
    ui->TextLinkIndex->setText(QString::number(c->getIndexRegardingNode()));
    ui->TextLinkIndex->setAlignment(Qt::AlignCenter);

    // Set pass checkbox
    if(tmpPass)
    {
        // Check CheckBoxPass
        ui->CheckBoxPass->setChecked(true);
    }
    else
    {
        // Uncheck CheckBoxPass
        ui->CheckBoxPass->setChecked(false);
    }

    // if connection is part of a traffic light
    if (c->getTlight() == NULL)
    {
        // Clear Text of TextTrafficLight
        ui->TextTrafficLight->setText("");

        // Disable TextTrafficLight
        ui->TextTrafficLight->setEnabled(false);

        // Disable button ButtonEditTLStates
        ui->ButtonEditTLStates->setEnabled(false);
    }
    else
    {
        // Clear Text of TextTrafficLight
        ui->TextTrafficLight->setText(c->getTlight()->getItemId());

        // Disable TextTrafficLight
        ui->TextTrafficLight->setEnabled(true);

        // Disable button ButtonEditTLStates
        ui->ButtonEditTLStates->setEnabled(true);
    }

    // If custom parameter 1 was changed
    if(c->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(c->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(c->getExtraParameter1Value());
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
    if(c->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(c->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(c->getExtraParameter2Value());
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
    if(c->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(c->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(c->getExtraParameter3Value());
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

void connectionItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to Connection Item
    c = dynamic_cast<connectionItem *>(item);

    // If item is a connection
    if(c)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Open dialog
        show();
    }
}

void connectionItemDialog::on_ButtonEditTLStates_released()
{
    // Open Traffic light Dialog

    qDebug() << "Pendiente Puntero";
    //trafficLightPhaseD->openDialog(c);
}

void connectionItemDialog::on_ButtonAccept_released()
{
    // Set pass parameter
    c->setPass(tmpPass);

    // Set vectorOfStates
    c->setVectorOfStates(vectorOfStates);

    // If custom parameter 1 has been modified
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        // Set name and value of custom parameter 1 in the item
        c->setExtraParameter1Name(getTmpExtraParameter1Name());
        c->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // If custom parameter 2 has been modified
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        // Set name and value of custom parameter 2 in the item
        c->setExtraParameter2Name(getTmpExtraParameter2Name());
        c->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // If custom parameter 3 has been modified
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        // Set name and value of custom parameter 3 in the item
        c->setExtraParameter3Name(getTmpExtraParameter3Name());
        c->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close dialog
    close();
}

void connectionItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog
    close();
}

void connectionItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void connectionItemDialog::on_ButtonCustomParameter1Name_released()
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

void connectionItemDialog::on_ButtonCustomParameter2Name_released()
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

void connectionItemDialog::on_ButtonCustomParameter3Name_released()
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

void connectionItemDialog::on_TextCustomParameter1Value_textChanged()
{
    setTmpExtraParameter1Value(ui->TextCustomParameter1Value->toPlainText());
}

void connectionItemDialog::on_TextCustomParameter2Value_textChanged()
{
    setTmpExtraParameter2Value(ui->TextCustomParameter2Value->toPlainText());
}

void connectionItemDialog::on_TextCustomParameter3Value_textChanged()
{
    setTmpExtraParameter3Value(ui->TextCustomParameter3Value->toPlainText());
}
