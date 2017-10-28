#include "flowItemDialog.h"
#include "ui_flowItemDialog.h"

#include "../../../database/eNetEditorDatabase.h"
#include "../../../database/vehicleTypeTable.h"

#include "../../../items/vehicles/flowItem.h"
#include "../../../items/vehicleTypeItem.h"
#include "../../../items/routeItem.h"


flowItemDialog::flowItemDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractVehicleItemDialog(eNetEditorMainW), ui(new Ui::flowItemDialog)
{
    // Create Dialog
    ui->setupUi(this);

    // Set pointer to NULL
    f = NULL;
}

flowItemDialog::~flowItemDialog()
{
    // Delete UI
    delete ui;
}

void flowItemDialog::resetParameters()
{
    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(f->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(f->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(f->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(f->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(f->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(f->getExtraParameter3Value());
}

void flowItemDialog::updateParameters()
{
    /** TERMINAR **/

    // Clear ComboBoxType Vehicle Type
    ui->ComboBoxVType->clear();

    // Declare QStringList
    QStringList listOfVehicleTypes;

    // Fill QStringList with all Vehicle Types Ids
    for (int i = 0; i != f->getDatabase()->getVehicleTypeTable()->getNumberOfItems(); i++)
    {
        listOfVehicleTypes << f->getDatabase()->getVehicleTypeOfTable(i)->getItemId();
    }

    // Fill combo box
    ui->ComboBoxVType->insertItems(0, listOfVehicleTypes);

    // Set ID Text
    ui->TextFlowId->setText(f->getItemId());
    ui->TextFlowId->setAlignment(Qt::AlignCenter);

    // Set Vehicle type Text
    ui->ComboBoxVType->setCurrentText(f->getVehicleType()->getItemId());

    // Set Route Text
    ui->TextRoute->setText(f->getRoute()->getItemId());
    ui->TextRoute->setAlignment(Qt::AlignCenter);

    // Set Color Text
    ui->TextColor->setText(f->getColor());
    ui->TextColor->setAlignment(Qt::AlignCenter);

    // Set Line Text
    ui->TextLine->setText(f->getLine());
    ui->TextLine->setAlignment(Qt::AlignCenter);

    // Set Begin Text
    ui->TextBegin->setText(QString::number(f->getBegin()));
    ui->TextBegin->setAlignment(Qt::AlignCenter);

    // Set End Text
    ui->TextEnd->setText(QString::number(f->getEnd()));
    ui->TextEnd->setAlignment(Qt::AlignCenter);

    // Set ArrivalLane Text
    ui->ComboBoxArrivalLane;
    ui->TextArrivalLane->setText(f->getArrivalLane());
    ui->TextArrivalLane->setAlignment(Qt::AlignCenter);

    // Set Arrival Pos Text
    ui->ComboBoxArrivalPos;
    ui->TextArrivalPos->setText(f->getArrivalPos());
    ui->TextArrivalPos->setAlignment(Qt::AlignCenter);

    // Set Arrival Speed Text
    ui->ComboBoxArrivalSpeed;
    ui->TextArrivalSpeed->setText(f->getArrivalSpeed());
    ui->TextArrivalSpeed->setAlignment(Qt::AlignCenter);

    // Set Depart Lane Text
    ui->ComboBoxDepartLane;
    ui->TextDepartLane->setText(f->getDepartLane());
    ui->TextDepartLane->setAlignment(Qt::AlignCenter);

    // Set Depart Pos Text
    ui->ComboBoxDepartPos;
    ui->TextDepartPos->setText(f->getDepartPos());
    ui->TextDepartPos->setAlignment(Qt::AlignCenter);

    // Set Depart Speed Text
    ui->ComboBoxDepartSpeed;
    ui->TextDepartSpeed->setText(f->getDepartSpeed());
    ui->TextDepartSpeed->setAlignment(Qt::AlignCenter);

    // Enable or disable Radio button Vehs Per Hour Text
    if (ui->RadioButtonVehsPerHour->isChecked())
    {
        ui->TextVehsPerHour->setEnabled(true);
    }
    else
    {
        ui->TextVehsPerHour->setEnabled(false);
    }

    // Set Vehs Per Hour Text
    ui->TextVehsPerHour->setText(QString::number(f->getVehsPerHour()));
    ui->TextVehsPerHour->setAlignment(Qt::AlignCenter);

    // Enable or disable Radio button TextProbability
    if (ui->RadioButtonProbability->isChecked())
    {
        ui->TextProbability->setEnabled(true);
    }
    else
    {
        ui->TextProbability->setEnabled(false);
    }

    // Set Probability Text
    ui->TextProbability->setText(QString::number(f->getProbability()));
    ui->TextProbability->setAlignment(Qt::AlignCenter);

    // Enable or disable Radio button Period
    if (ui->RadioButtonPeriod->isChecked())
    {
        ui->TextPeriod->setEnabled(true);
    }
    else
    {
        ui->TextPeriod->setEnabled(false);
    }

    // Set Period Text
    ui->TextPeriod->setText(QString::number(f->getPeriod()));
    ui->TextPeriod->setAlignment(Qt::AlignCenter);

    // Enable or disable Radio button Number
    if (ui->RadioButtonNumber->isChecked())
    {
        ui->TextNumber->setEnabled(true);
    }
    else
    {
        ui->TextNumber->setEnabled(false);
    }

    // Set Number Text
    ui->TextNumber->setText(QString::number(f->getNumber()));
    ui->TextNumber->setAlignment(Qt::AlignCenter);

    // If custom parameter 1 was changed
    if(f->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(f->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(f->getExtraParameter1Value());
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
    if(f->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(f->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(f->getExtraParameter2Value());
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
    if(f->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(f->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(f->getExtraParameter3Value());
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

void flowItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to flow
    f = dynamic_cast<flowItem *>(item);

    // If item is a flow
    if(f)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Open Dialog
        show();
    }
}

void flowItemDialog::on_TextLine_textChanged()
{

}

void flowItemDialog::on_TextColor_textChanged()
{
    tmpColor = ui->TextColor->toPlainText();
}

void flowItemDialog::on_TextNumber_textChanged()
{

}

void flowItemDialog::on_TextBegin_textChanged()
{

}

void flowItemDialog::on_TextEnd_textChanged()
{

}

void flowItemDialog::on_TextDepartLane_textChanged()
{

}

void flowItemDialog::on_TextDepartPos_textChanged()
{

}

void flowItemDialog::on_TextDepartSpeed_textChanged()
{

}

void flowItemDialog::on_TextArrivalLane_textChanged()
{

}

void flowItemDialog::on_TextArrivalPos_textChanged()
{

}

void flowItemDialog::on_TextArrivalSpeed_textChanged()
{

}

void flowItemDialog::on_TextPeriod_textChanged()
{

}

void flowItemDialog::on_TextVehsPerHour_textChanged()
{

}

void flowItemDialog::on_TextProbability_textChanged()
{

}

void flowItemDialog::on_TextCustomParameter1Value_textChanged()
{

}

void flowItemDialog::on_TextCustomParameter2Value_textChanged()
{

}

void flowItemDialog::on_TextCustomParameter3Value_textChanged()
{

}

void flowItemDialog::on_ButtonCustomParameter1Name_released()
{

}

void flowItemDialog::on_ButtonCustomParameter2Name_released()
{

}

void flowItemDialog::on_ButtonCustomParameter3Name_released()
{

}

void flowItemDialog::on_ComboBoxDepartLane_currentTextChanged(const QString &arg1)
{
    tmpDepartLane = arg1;
}

void flowItemDialog::on_ComboBoxDepartPos_currentTextChanged(const QString &arg1)
{
    tmpDepartPos = arg1;
}

void flowItemDialog::on_ComboBoxDepartSpeed_currentTextChanged(const QString &arg1)
{
    tmpDepartSpeed = arg1;
}

void flowItemDialog::on_ComboBoxArrivalLane_currentTextChanged(const QString &arg1)
{
    tmpArrivalLane = arg1;
}

void flowItemDialog::on_ComboBoxArrivalPos_currentTextChanged(const QString &arg1)
{
    tmpArrivalPos = arg1;
}

void flowItemDialog::on_ComboBoxArrivalSpeed_currentTextChanged(const QString &arg1)
{
    tmpArrivalSpeed = arg1;
}

void flowItemDialog::on_RadioButtonPeriod_toggled(bool checked)
{
    tmpPeriod = checked;
}

void flowItemDialog::on_RadioButtonVehsPerHour_toggled(bool checked)
{
    tmpVehsPerHour = checked;
}

void flowItemDialog::on_RadioButtonProbability_toggled(bool checked)
{
    tmpProbability = checked;
}

void flowItemDialog::on_ButtonAccept_released()
{
    // If custom parameter 1 has been modified
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        // Set name and value of custom parameter 1 in the item
        f->setExtraParameter1Name(getTmpExtraParameter1Name());
        f->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // If custom parameter 2 has been modified
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        // Set name and value of custom parameter 2 in the item
        f->setExtraParameter2Name(getTmpExtraParameter2Name());
        f->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // If custom parameter 3 has been modified
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        // Set name and value of custom parameter 3 in the item
        f->setExtraParameter3Name(getTmpExtraParameter3Name());
        f->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close dialog
    close();
}

void flowItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog
    close();
}

void flowItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void flowItemDialog::on_ComboBoxVType_currentTextChanged(const QString &arg1)
{

}

void flowItemDialog::on_TextRoute_textChanged()
{

}

void flowItemDialog::on_TextPersonNumber_textChanged()
{

}

void flowItemDialog::on_TextContainerNumber_textChanged()
{

}

void flowItemDialog::on_RadioButtonNumber_toggled(bool checked)
{

}
