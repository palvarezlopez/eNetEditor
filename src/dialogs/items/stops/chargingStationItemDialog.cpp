#include "chargingStationItemDialog.h"
#include "ui_chargingStationItemDialog.h"

#include "../../../database/eNetEditorDatabase.h"

#include "../../../items/stops/chargingStationItem.h"
#include "../../../items/laneItem.h"


chargingStationItemDialog::chargingStationItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorItemDialog(eNetEditorMainW), ui(new Ui::chargingStationItemDialog)
{
    // Create Dialog
    ui->setupUi(this);

    // Set pointer to Charging station to null
    cs = NULL;
}

chargingStationItemDialog::~chargingStationItemDialog()
{
    // Delete UI
    delete ui;
}

void chargingStationItemDialog::resetParameters()
{
    // Set start pos
    tmpStartPos = cs->getStartPos();

    // Set end pos
    tmpEndPos = cs->getEndPos();

    // Set charging power
    tmpChrgPower = cs->getChrgpower();

    // Set efficiency
    tmpEfficiency = cs->getEfficiency();

    // Set charge delay
    tmpChargeDelay = cs->getChargeDelay();

    // Set charge in transit
    tmpChargeInTransit = cs->getChargeInTransit();

    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(cs->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(cs->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(cs->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(cs->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(cs->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(cs->getExtraParameter3Value());
}

void chargingStationItemDialog::updateParameters()
{
    // Set Text ID
    ui->TextId->setText(cs->getItemId());
    ui->TextId->setAlignment(Qt::AlignCenter);

    // Set Text startPosition
    ui->TextStartPosition->setText(QString::number(cs->getStartPos()));
    ui->TextStartPosition->setAlignment(Qt::AlignCenter);

    // Set Text EndPosition
    ui->TextEndPosition->setText(QString::number(cs->getEndPos()));
    ui->TextEndPosition->setAlignment(Qt::AlignCenter);

    // Set Charging power
    ui->TextChargingPower->setText(QString::number(cs->getChrgpower()));
    ui->TextChargingPower->setAlignment(Qt::AlignCenter);

    // Set Efficiency
    ui->TextEfficiency->setText(QString::number(cs->getEfficiency()));
    ui->TextEfficiency->setAlignment(Qt::AlignCenter);

    // Set Efficiency
    ui->TextChargeDelay->setText(QString::number(cs->getChargeDelay()));
    ui->TextChargeDelay->setAlignment(Qt::AlignCenter);

    // Set Efficiency
    ui->TextChargingPower->setText(QString::number(cs->getChrgpower()));
    ui->TextChargingPower->setAlignment(Qt::AlignCenter);

    // If custom parameter 1 was changed
    if(cs->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(cs->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(cs->getExtraParameter1Value());
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
    if(cs->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(cs->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(cs->getExtraParameter2Value());
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
    if(cs->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(cs->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(cs->getExtraParameter3Value());
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

void chargingStationItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to chargingStation
    cs = dynamic_cast<chargingStationItem *>(item);

    // If item is a charging station
    if(cs)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Show Dialog
        show();
    }
}

void chargingStationItemDialog::on_TextStartPosition_textChanged()
{
    tmpStartPos = ui->TextStartPosition->toPlainText().toDouble();
}

void chargingStationItemDialog::on_TextEndPosition_textChanged()
{
    tmpEndPos = ui->TextEndPosition->toPlainText().toDouble();
}

void chargingStationItemDialog::on_TextChargingPower_textChanged()
{
    tmpChrgPower = ui->TextChargingPower->toPlainText().toDouble();
}

void chargingStationItemDialog::on_TextEfficiency_textChanged()
{
    tmpEfficiency = ui->TextEfficiency->toPlainText().toDouble();
}

void chargingStationItemDialog::on_TextChargeDelay_textChanged()
{
    tmpChargeDelay = ui->TextChargeDelay->toPlainText().toDouble();
}

void chargingStationItemDialog::on_ButtonAccept_released()
{
    // Set StartPos
    cs->setStartPos(tmpStartPos);

    // Set EndPos
    cs->setEndPos(tmpEndPos);

    // Set ChrgPower
    cs->setChrgpower(tmpChrgPower);

    // Set efficiency
    cs->setEfficiency(tmpEfficiency);

    // Set ChargeIntransit
    cs->setChargeInTransit(tmpChargeInTransit);

    // Set chargeDelay
    cs->setChargeDelay(tmpChargeDelay);

    // If custom parameter 1 has been modified
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        // Set name and value of custom parameter 1 in the item
        cs->setExtraParameter1Name(getTmpExtraParameter1Name());
        cs->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // If custom parameter 2 has been modified
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        // Set name and value of custom parameter 2 in the item
        cs->setExtraParameter2Name(getTmpExtraParameter2Name());
        cs->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // If custom parameter 3 has been modified
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        // Set name and value of custom parameter 3 in the item
        cs->setExtraParameter3Name(getTmpExtraParameter3Name());
        cs->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Make charging Station again
    cs->make();

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);


    // Close Dialog
    close();
}

void chargingStationItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close Dialog
    close();
}

void chargingStationItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void chargingStationItemDialog::on_ButtonCustomParameter1Name_released()
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

void chargingStationItemDialog::on_ButtonCustomParameter2Name_released()
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

void chargingStationItemDialog::on_ButtonCustomParameter3Name_released()
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

void chargingStationItemDialog::on_CheckBoxChargeInTransit_toggled(bool checked)
{
    tmpChargeInTransit = checked;
}

void chargingStationItemDialog::on_TextCustomParameter1Value_textChanged()
{
    setTmpExtraParameter1Value(ui->TextCustomParameter1Value->toPlainText());
}

void chargingStationItemDialog::on_TextCustomParameter2Value_textChanged()
{
    setTmpExtraParameter2Value(ui->TextCustomParameter2Value->toPlainText());
}

void chargingStationItemDialog::on_TextCustomParameter3Value_textChanged()
{
    setTmpExtraParameter3Value(ui->TextCustomParameter3Value->toPlainText());
}
