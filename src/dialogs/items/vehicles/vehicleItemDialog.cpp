#include "vehicleItemDialog.h"
#include "ui_vehicleItemDialog.h"

// Database
#include "../../../database/eNetEditorDatabase.h"
#include "../../../database/vehicleTypeTable.h"

// Item
#include "../../../items/vehicles/vehicleItem.h"
#include "../../../items/vehicleTypeItem.h"
#include "../../../items/routeItem.h"


vehicleItemDialog::vehicleItemDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractVehicleItemDialog(eNetEditorMainW), ui(new Ui::vehicleItemDialog)
{
    // Create UI
    ui->setupUi(this);

    // By default pointer to vehicle is NULL
    v = NULL;
}

vehicleItemDialog::~vehicleItemDialog()
{
    // Delete UI
    delete ui;
}

void vehicleItemDialog::resetParameters()
{
    // Set temporal Vehicle Type
    tmpVT = v->getVehicleType()->getItemId();

    // Set temporal Color
    tmpColor = v->getColor();

    // Set temporal depart
    tmpDepart = v->getDepart();

    // Set temporal lane
    tmpDepartLane = v->getDepartLane();

    // Set temporal depar Pos
    tmpDepartPos = v->getDepartPos();

    // Set temporal depart Speed
    tmpDepartSpeed = v->getDepartSpeed();

    // Set temporal Arrival Lane
    tmpArrivalLane = v->getArrivalLane();

    // Set temporal Arrival Pos
    tmpArrivalPos = v->getArrivalPos();

    // Set temporal Arrival Speed
    tmpArrivalSpeed = v->getArrivalSpeed();

    // Set temporal Line
    tmpLine = v->getLine();

    // Set temporal Person number
    tmpPersonNumber = v->getPersonNumber();

    // Set temporal container number
    tmpContainerNumber = v->getContainerNumber();

    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(v->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(v->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(v->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(v->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(v->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(v->getExtraParameter3Value());
}

void vehicleItemDialog::updateParameters()
{
    // Fill vehicle type list
    fillVehicleTypeList();

    // Set ID
    ui->TextId->setText(v->getItemId());

    // Set Vehicle Type
    ui->ComboBoxVType->setCurrentText(tmpVT);

    // Set Route
    ui->TextRoute->setText(v->getRoute()->getItemId());

    // Set Color
    ui->TextColor->setText(tmpColor);

    // Set Depart
    ui->TextDepart->setText(QString::number(tmpDepart));

    // If DepartLane is personaliced
    if(ui->ComboBoxDepartLane->findText(tmpDepartLane, Qt::MatchExactly) == -1)
    {
        // Set "Specific"
        ui->ComboBoxDepartLane->setCurrentText("specific");

        // Set depart lane
        ui->TextDepartLane->setText(tmpDepartLane);

        // Enablet extBox depart lane
        ui->TextDepartLane->setEnabled(true);
    }
    else
    {
        // Set departLane
        ui->ComboBoxDepartLane->setCurrentText(tmpDepartLane);

        // Clear textBox departlane
        ui->TextDepartLane->setText("");

        // Disable textBox departlane
        ui->TextDepartLane->setEnabled(false);
    }

    // If DepartPos is personaliced
    if(ui->ComboBoxDepartPos->findText(tmpDepartPos, Qt::MatchExactly) == -1)
    {
        // Set "Specific"
        ui->ComboBoxDepartPos->setCurrentText("specific");

        // Set depart lane
        ui->TextDepartPos->setText(tmpDepartPos);

        // Enablet extBox depart lane
        ui->TextDepartPos->setEnabled(true);
    }
    else
    {
        // Set DepartPos
        ui->ComboBoxDepartPos->setCurrentText(tmpDepartPos);

        // Clear textBox DepartPos
        ui->TextDepartPos->setText("");

        // Disable textBox DepartPos
        ui->TextDepartPos->setEnabled(false);
    }

    // If DepartSpeed is personaliced
    if(ui->ComboBoxDepartSpeed->findText(tmpDepartSpeed, Qt::MatchExactly) == -1)
    {
        // Set "Specific"
        ui->ComboBoxDepartSpeed->setCurrentText("specific");

        // Set depart lane
        ui->TextDepartSpeed->setText(tmpDepartSpeed);

        // Enablet extBox depart lane
        ui->TextDepartSpeed->setEnabled(true);
    }
    else
    {
        // Set DepartSpeed
        ui->ComboBoxDepartSpeed->setCurrentText(tmpDepartSpeed);

        // Clear textBox DepartSpeed
        ui->TextDepartSpeed->setText("");

        // Disable textBox DepartSpeed
        ui->TextDepartSpeed->setEnabled(false);
    }

    // If ArrivalLane is personaliced
    if(ui->ComboBoxArrivalLane->findText(tmpArrivalLane, Qt::MatchExactly) == -1)
    {
        // Set "Specific"
        ui->ComboBoxArrivalLane->setCurrentText("specific");

        // Set depart lane
        ui->TextArrivalLane->setText(tmpArrivalLane);

        // Enablet extBox depart lane
        ui->TextArrivalLane->setEnabled(true);
    }
    else
    {
        // Set ArrivalLane
        ui->ComboBoxArrivalLane->setCurrentText(tmpArrivalLane);

        // Clear textBox ArrivalLane
        ui->TextArrivalLane->setText("");

        // Disable textBox ArrivalLane
        ui->TextArrivalLane->setEnabled(false);
    }

    // If ArrivalSpeed is personaliced
    if(ui->ComboBoxArrivalSpeed->findText(tmpArrivalSpeed, Qt::MatchExactly) == -1)
    {
        // Set "Specific"
        ui->ComboBoxArrivalSpeed->setCurrentText("specific");

        // Set depart lane
        ui->TextArrivalSpeed->setText(tmpArrivalSpeed);

        // Enablet extBox depart lane
        ui->TextArrivalSpeed->setEnabled(true);
    }
    else
    {
        // Set ArrivalSpeed
        ui->ComboBoxArrivalSpeed->setCurrentText(tmpArrivalSpeed);

        // Clear textBox ArrivalSpeed
        ui->TextArrivalSpeed->setText("");

        // Disable textBox ArrivalSpeed
        ui->TextArrivalSpeed->setEnabled(false);
    }

    // If ArrivalPos is personaliced
    if(ui->ComboBoxArrivalPos->findText(tmpArrivalPos, Qt::MatchExactly) == -1)
    {
        // Set "Specific"
        ui->ComboBoxArrivalPos->setCurrentText("specific");

        // Set depart lane
        ui->TextArrivalPos->setText(tmpArrivalPos);

        // Enablet extBox depart lane
        ui->TextArrivalPos->setEnabled(true);
    }
    else
    {
        // Set ArrivalPos
        ui->ComboBoxArrivalPos->setCurrentText(tmpArrivalPos);

        // Clear textBox ArrivalPos
        ui->TextArrivalPos->setText("");

        // Disable textBox ArrivalPos
        ui->TextArrivalPos->setEnabled(false);
    }

    // Set Line
    ui->TextLine->setText(tmpLine);

    // Set person Number
    ui->TextPersonNumber->setText(QString::number(tmpPersonNumber));

    // Set Container Number
    ui->TextContainerNumber->setText(QString::number(tmpContainerNumber));

    // If custom parameter 1 was changed
    if(v->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(v->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(v->getExtraParameter1Value());
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
    if(v->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(v->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(v->getExtraParameter2Value());
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
    if(v->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(v->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(v->getExtraParameter3Value());
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

void vehicleItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to vehicle type
    v = dynamic_cast<vehicleItem *>(item);

    // If item is a vehicle type
    if(v)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Show dialog
        show();
    }
}

void vehicleItemDialog::on_ButtonAccept_released()
{
    qDebug() << "TERMINAR";

    // If custom parameter 1 has been modified
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        // Set name and value of custom parameter 1 in the item
        v->setExtraParameter1Name(getTmpExtraParameter1Name());
        v->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // If custom parameter 2 has been modified
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        // Set name and value of custom parameter 2 in the item
        v->setExtraParameter2Name(getTmpExtraParameter2Name());
        v->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // If custom parameter 3 has been modified
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        // Set name and value of custom parameter 3 in the itemº
        v->setExtraParameter3Name(getTmpExtraParameter3Name());
        v->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close dialog
    close();
}

void vehicleItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog
    close();
}

void vehicleItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void vehicleItemDialog::on_TextColor_textChanged()
{

}

void vehicleItemDialog::on_TextPersonNumber_textChanged()
{

}

void vehicleItemDialog::on_TextContainerNumber_textChanged()
{

}

void vehicleItemDialog::on_TextDepart_textChanged()
{

}

void vehicleItemDialog::on_ButtonCustomParameter1Name_released()
{

}

void vehicleItemDialog::on_ButtonCustomParameter2Name_released()
{

}

void vehicleItemDialog::on_ButtonCustomParameter3Name_released()
{

}

void vehicleItemDialog::on_TextCustomParameter1Value_textChanged()
{

}

void vehicleItemDialog::on_TextCustomParameter2Value_textChanged()
{

}

void vehicleItemDialog::on_TextCustomParameter3Value_textChanged()
{

}

void vehicleItemDialog::on_ComboBoxDepartLane_currentTextChanged(const QString &arg1)
{
    // If Depart Lane is personaliced
    if(arg1 == "specific")
    {
        // Enablet extBox depart lane
        ui->TextDepartLane->setEnabled(true);
    }
    else
    {
        // Clear textBox depart lane
        ui->TextDepartLane->setText("");

        // Disable textBox depart lane
        ui->TextDepartLane->setEnabled(false);
    }
}

void vehicleItemDialog::on_ComboBoxDepartPos_currentTextChanged(const QString &arg1)
{
    // If depart pos is personaliced
    if(arg1 == "specific")
    {
        // Enablet extBox depart Pos
        ui->TextDepartPos->setEnabled(true);
    }
    else
    {
        // Clear textBox depart pos
        ui->TextDepartPos->setText("");

        // Disable textBox depart pos
        ui->TextDepartPos->setEnabled(false);
    }
}

void vehicleItemDialog::on_ComboBoxDepartSpeed_currentTextChanged(const QString &arg1)
{
    // If depart Speed is personaliced
    if(arg1 == "specific")
    {
        // Enable textBox depart Speed
        ui->TextDepartSpeed->setEnabled(true);
    }
    else
    {
        // Clear textBox depart Speed
        ui->TextDepartSpeed->setText("");

        // Disable textBox depart Speed
        ui->TextDepartSpeed->setEnabled(false);
    }
}

void vehicleItemDialog::on_ComboBoxArrivalLane_currentTextChanged(const QString &arg1)
{
    // If Arrival Lane is personaliced
    if(arg1 == "specific")
    {
        // Enable textBox Arrival Lane
        ui->TextArrivalLane->setEnabled(true);
    }
    else
    {
        // Clear textBox Arrival Lane
        ui->TextArrivalLane->setText("");

        // Disable textBox Arrival Lane
        ui->TextArrivalLane->setEnabled(false);
    }
}

void vehicleItemDialog::on_ComboBoxArrivalPos_currentTextChanged(const QString &arg1)
{
    // If Arrival Pos is personaliced
    if(arg1 == "specific")
    {
        // Enable textBox Arrival Pos
        ui->TextArrivalPos->setEnabled(true);
    }
    else
    {
        // Clear textBox Arrival Pos
        ui->TextArrivalPos->setText("");

        // Disable textBox Arrival Pos
        ui->TextArrivalPos->setEnabled(false);
    }
}

void vehicleItemDialog::on_ComboBoxArrivalSpeed_currentTextChanged(const QString &arg1)
{
    // If Arrival Speed is personaliced
    if(arg1 == "specific")
    {
        // Enable textBox Arrival Speed
        ui->TextArrivalSpeed->setEnabled(true);
    }
    else
    {
        // Clear textBox Arrival Speed
        ui->TextArrivalSpeed->setText("");

        // Disable textBox Arrival Speed
        ui->TextArrivalSpeed->setEnabled(false);
    }
}

void vehicleItemDialog::on_TextDepartLane_textChanged()
{

}

void vehicleItemDialog::on_TextDepartPos_textChanged()
{

}

void vehicleItemDialog::on_TextDepartSpeed_textChanged()
{

}

void vehicleItemDialog::on_TextArrivalLane_textChanged()
{

}

void vehicleItemDialog::on_TextArrivalPos_textChanged()
{

}

void vehicleItemDialog::on_TextArrivalSpeed_textChanged()
{

}

void vehicleItemDialog::on_ComboBoxVType_currentTextChanged(const QString &arg1)
{

}

void vehicleItemDialog::on_TextRoute_textChanged()
{

}

void vehicleItemDialog::on_TextLine_textChanged()
{

}

void vehicleItemDialog::fillVehicleTypeList()
{
    // Clear combo box
    ui->ComboBoxVType->clear();

    // Declare counter
    int counter = 0;

    // Iterate over table of vehicle types
    for (int i = 0; i != v->getDatabase()->getVehicleTypeTable()->getNumberOfItems(); i++)
    {
        // Insert ID of vtype
        ui->ComboBoxVType->insertItem(counter, v->getDatabase()->getVehicleTypeOfTable(i)->getItemId());

        // Update counter
        counter++;
    }
}
