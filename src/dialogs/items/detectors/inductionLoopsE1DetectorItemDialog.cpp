#include "inductionLoopsE1DetectorItemDialog.h"
#include "ui_inductionLoopsE1DetectorItemDialog.h"

#include "../../../items/detectors/inductionLoopsE1DetectorItem.h"
#include "../../../items/flowMeasureItem.h"


inductionLoopsE1DetectorItemDialog::inductionLoopsE1DetectorItemDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractDetectorItemDialog(eNetEditorMainW), ui(new Ui::inductionLoopsE1DetectorItemDialog)
{
    // Create UI
    ui->setupUi(this);

    // By default pointer to element is NULL
    E1 = NULL;
}

inductionLoopsE1DetectorItemDialog::~inductionLoopsE1DetectorItemDialog()
{
    // Delete UI
    delete ui;
}

void inductionLoopsE1DetectorItemDialog::updateParameters()
{
    // Set text ID
    ui->TextId->setText(E1->getItemId());
    ui->TextId->setAlignment(Qt::AlignCenter);

    // Set Filename
    ui->TextFilename->setText(E1->getFileName());
    ui->TextFilename->setAlignment(Qt::AlignCenter);

    // Set Frequency
    ui->TextFrequency->setText(QString::number(E1->getFrequency()));
    ui->TextFrequency->setAlignment(Qt::AlignCenter);

    // Set Position
    ui->TextPosition->setText(QString::number(E1->getPosDetector()));
    ui->TextPosition->setAlignment(Qt::AlignCenter);

    // Set CheckBox friendly pos
    ui->CheckBoxFriendlyPosition->setChecked(E1->isFriendlyPosEnabled());

    // Set CheckBox split by type
    ui->CheckBoxSplitByType->setChecked(E1->isSplitByTypeEnabled());

    // Clear contents of the table
    ui->ListFlowMeasures->clear();

    // Declare listCounter
    int listCounter = 0;

    // Iterate over table of vehicle types
    for(QList<flowMeasureItem *>::iterator i = E1->flowMeasuresBegin(); i != E1->flowMeasuresEnd(); i++)
    {
        // Create QListWidgetItem
        QListWidgetItem *flowMeasure = new QListWidgetItem((*i)->toString());

        // Insert item in list
        ui->ListFlowMeasures->insertItem(listCounter, flowMeasure);

        // Update list counter
        listCounter++;
    }

    // If custom parameter 1 was changed
    if(E1->getExtraParameter1Name() != "")
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(E1->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(E1->getExtraParameter1Value());
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
    if(E1->getExtraParameter2Name() != "")
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(E1->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(E1->getExtraParameter2Value());
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
    if(E1->getExtraParameter3Name() != "")
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(E1->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(E1->getExtraParameter3Value());
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

void inductionLoopsE1DetectorItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to Induction Loop
    E1 = dynamic_cast<inductionLoopsE1DetectorItem *>(item);

    // If item is an Induction Loop
    if(E1)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Open Dialog
        show();
    }
}

void inductionLoopsE1DetectorItemDialog::on_ButtonAccept_released()
{
    // Set new Filename in detector
    E1->setFileName(tmpFileName);

    // Set new Pos in detector
    E1->setPosInLane(tmpPos);

    // Set new Frecuency in detector
    E1->setFrequency(tmpFrecuency);

    // Set new Friendly Pos in detector
    E1->setFriendlyPos(tmpFriendlyPos);

    // Set new Split By type in detector
    E1->setSplitByType(tmpSplitByType);

    // Remake detector
    E1->make();

    // Close Dialog
    close();
}

void inductionLoopsE1DetectorItemDialog::on_ButtonCancel_released()
{
    // Close Dialog
    close();
}

void inductionLoopsE1DetectorItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void inductionLoopsE1DetectorItemDialog::resetParameters()
{
    // Set temporal filename
    tmpFileName = E1->getFileName();

    // Set temporal frequency
    tmpFrecuency = E1->getFrequency();

    // Set temporal pos
    tmpPos = E1->getPosDetector();

    // Set temporal friendly Pos
    tmpFriendlyPos = E1->isFriendlyPosEnabled();

    // Set temporal split by type
    tmpSplitByType = E1->isSplitByTypeEnabled();

    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(E1->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(E1->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(E1->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(E1->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(E1->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(E1->getExtraParameter3Value());
}

void inductionLoopsE1DetectorItemDialog::on_ButtonCustomParameter1Name_released()
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

void inductionLoopsE1DetectorItemDialog::on_ButtonCustomParameter2Name_released()
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

void inductionLoopsE1DetectorItemDialog::on_ButtonCustomParameter3Name_released()
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

void inductionLoopsE1DetectorItemDialog::on_TextCustomParameter1Value_textChanged()
{
    setTmpExtraParameter1Value(ui->TextCustomParameter1Value->toPlainText());
}

void inductionLoopsE1DetectorItemDialog::on_TextCustomParameter2Value_textChanged()
{
    setTmpExtraParameter2Value(ui->TextCustomParameter2Value->toPlainText());
}

void inductionLoopsE1DetectorItemDialog::on_TextCustomParameter3Value_textChanged()
{
    setTmpExtraParameter3Value(ui->TextCustomParameter3Value->toPlainText());
}

void inductionLoopsE1DetectorItemDialog::on_TextPosition_textChanged()
{
    tmpPos = ui->TextPosition->toPlainText().toDouble();
}

void inductionLoopsE1DetectorItemDialog::on_TextFrequency_textChanged()
{
    tmpFrecuency = ui->TextFrequency->toPlainText().toDouble();
}

void inductionLoopsE1DetectorItemDialog::on_TextFilename_textChanged()
{
    /**
        // Get variable to get directory of Detectors
        QString detectorsDirectory = E1->getFileName();

        // Open search Dialog
        QString filename = QFileDialog::getExistingDirectory(
                                this,
                                tr("Set detector directory"),
                                detectorsDirectory.replace(QString("/" + E1->getId() + ".xml"), ""));

        // If filename is valid
        if(filename != "")
        {
            // Set fileName
            ui->TextFile->setText(filename + "/" + E1->getId() + ".xml");
        }
    **/

    tmpFileName = ui->TextFilename->toPlainText();
}

void inductionLoopsE1DetectorItemDialog::on_CheckBoxFriendlyPosition_toggled(bool checked)
{
    tmpFriendlyPos = checked;
}

void inductionLoopsE1DetectorItemDialog::on_CheckBoxSplitByType_toggled(bool checked)
{
    tmpSplitByType = checked;
}


