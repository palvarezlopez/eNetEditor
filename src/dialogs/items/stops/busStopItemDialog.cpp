#include "busStopItemDialog.h"
#include "ui_busStopItemDialog.h"

// Database
#include "../../../database/eNetEditorDatabase.h"

// Project
#include "../../../project/eNetEditorProject.h"

#include "../../../items/stops/busStopItem.h"
#include "../../../items/laneItem.h"


busStopItemDialog::busStopItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorItemDialog(eNetEditorMainW), ui(new Ui::busStopItemDialog)
{
    // Create Dialog
    ui->setupUi(this);

    // Set pointer to NULL
    bs = NULL;
}

busStopItemDialog::~busStopItemDialog()
{
    // Delete UI
    delete ui;
}

void busStopItemDialog::resetParameters()
{
    // Set temporal start position
    tmpStartPosition = bs->getStartPos();

    // Set temporal end position
    tmpEndPosition = bs->getEndPos();

    // Set temporal lines
    tmpLines = bs->getLines();

    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(bs->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(bs->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(bs->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(bs->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(bs->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(bs->getExtraParameter3Value());
}

void busStopItemDialog::updateParameters()
{
    // Set Text ID
    ui->TextId->setText(bs->getItemId());
    ui->TextId->setAlignment(Qt::AlignCenter);

    // Set Text Lane
    ui->TextLane->setText(bs->getLane()->getItemId());
    ui->TextLane->setAlignment(Qt::AlignCenter);

    // Set Text startPosition
    ui->TextStartPosition->setText(QString::number(bs->getStartPos()));
    ui->TextStartPosition->setAlignment(Qt::AlignCenter);

    // Set Text EndPosition
    ui->TextEndPosition->setText(QString::number(bs->getEndPos()));
    ui->TextEndPosition->setAlignment(Qt::AlignCenter);

    // Set Text Lines
    ui->TextLines->setText(bs->getLines());
    ui->TextLines->setAlignment(Qt::AlignCenter);

    // If custom parameter 1 was changed
    if(bs->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(bs->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(bs->getExtraParameter1Value());
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
    if(bs->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(bs->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(bs->getExtraParameter2Value());
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
    if(bs->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(bs->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(bs->getExtraParameter3Value());
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

void busStopItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to Bus Stop
    bs = dynamic_cast<busStopItem *>(item);

    // If item is a Bus Stop
    if(bs)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Open Dialog
        show();
    }
}

void busStopItemDialog::on_ButtonAccept_released()
{
    // Change start position
    bs->setStartPos(tmpStartPosition);

    // Change end Position
    bs->setEndPos(tmpEndPosition);

    // Change Lines
    bs->setLines(tmpLines);

    // If custom parameter 1 has been modified
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        // Set name and value of custom parameter 1 in the item
        bs->setExtraParameter1Name(getTmpExtraParameter1Name());
        bs->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // If custom parameter 2 has been modified
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        // Set name and value of custom parameter 2 in the item
        bs->setExtraParameter2Name(getTmpExtraParameter2Name());
        bs->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // If custom parameter 3 has been modified
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        // Set name and value of custom parameter 3 in the item
        bs->setExtraParameter3Name(getTmpExtraParameter3Name());
        bs->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Remake BusStop
    bs->make();

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close dialog
    close();
}

void busStopItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog
    close();
}

void busStopItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void busStopItemDialog::on_ButtonCustomParameter1Name_released()
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

void busStopItemDialog::on_ButtonCustomParameter2Name_released()
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

void busStopItemDialog::on_ButtonCustomParameter3Name_released()
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

void busStopItemDialog::on_TextCustomParameter1Value_textChanged()
{
    setTmpExtraParameter1Value(ui->TextCustomParameter1Value->toPlainText());
}

void busStopItemDialog::on_TextCustomParameter2Value_textChanged()
{
    setTmpExtraParameter2Value(ui->TextCustomParameter2Value->toPlainText());
}

void busStopItemDialog::on_TextCustomParameter3Value_textChanged()
{
    setTmpExtraParameter3Value(ui->TextCustomParameter3Value->toPlainText());
}

void busStopItemDialog::on_TextStartPosition_textChanged()
{
    // Set contents of Text to temporal variable
    tmpStartPosition = ui->TextStartPosition->toPlainText().toDouble();
}

void busStopItemDialog::on_TextEndPosition_textChanged()
{
    // Set contents of Text to temporal variable
    tmpEndPosition = ui->TextEndPosition->toPlainText().toDouble();
}

void busStopItemDialog::on_TextLines_textChanged()
{
    // Set contents of Text to temporal variable
    tmpLines = ui->TextLines->toPlainText();
}
