#include "vehicleTypeItemDialog.h"
#include "ui_vehicleTypeItemDialog.h"

#include "../../configuration/items/vehicleTypeItemConfiguration.h"
#include "../../configuration/project/eNetEditorProjectConfiguration.h"

#include "../../project/eNetEditorProject.h"

#include "../../database/eNetEditorDatabase.h"
#include "../../database/vehicleTypeTable.h"

#include "../../items/vehicleTypeItem.h"



vehicleTypeItemDialog::vehicleTypeItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorItemDialog(eNetEditorMainW), ui(new Ui::vehicleTypeItemDialog)
{
    // Create Dialog
    ui->setupUi(this);

    // Set NULL pointer to newVehicle
    vt = NULL;
}

vehicleTypeItemDialog::~vehicleTypeItemDialog()
{
    // Delete UI
    delete ui;
}

void vehicleTypeItemDialog::resetParameters()
{
    // Set temporal ID
    tmpId = vt->getItemId();

    // Set temporal accel
    tmpAccel = vt->getAccel();

    // Set temporal Decel
    tmpDecel = vt->getDecel();

    // Set temporal Sigma
    tmpSigma = vt->getSigma();

    // Set temporal Tau
    tmpTau = vt->getTau();

    // Set temporal Lenght
    tmpLength = vt->getLength();

    // Set temporal MinGap
    tmpMinGap = vt->getMinGap();

    // Set temporal MaxSpeed
    tmpMaxSpeed = vt->getMaxSpeed();

    // Set temporal SpeedFactor
    tmpSpeedFactor = vt->getSpeedFactor();

    // Set temporal SpeedDev
    tmpSpeedDev = vt->getSpeedDev();

    // Set temporal Color
    tmpColor = vt->getColor();

    // Set temporal VClass
    tmpVClass = vt->getVClass();

    // Set temporal EmissionClass
    tmpEmissionClass = vt->getEmissionClass();

    // Set temporal GUIShape
    tmpGuiShape = vt->getGuiShape();

    // Set temporal Width
    tmpWidth = vt->getWidth();

    // Set temporal Img filename
    tmpFilename = vt->getImgFilename();

    // Set temporal Impatience
    tmpImpatience = vt->getImpatience();

    // Set temporal Lane change model
    tmpLaneChangeModel = vt->getLaneChangeModel();

    // Set temporal Act bat kap
    tmpActBatKap = vt->getActBatKap();

    // Set temporal Max bat kap
    tmpMaxBatKap = vt->getMaxBatKap();

    // Set temporal PowerMax
    tmpPowerMax = vt->getPowerMax();

    // Set temporal Mass
    tmpMass = vt->getMass();

    // Set temporal FrontSurfaceArea
    tmpFrontSurfaceArea = vt->getFrontSurfaceArea();

    // Set temporal AirDragCoefficient
    tmpAirDragCoefficient = vt->getAirDragCoefficient();

    // Set temporal Internal moment of inertia
    tmpInternalMomentOfInertia = vt->getInternalMomentOfInertia();

    // Set temporal Radial Drag Coefficient
    tmpRadialDragCoefficient = vt->getRadialDragCoefficient();

    // Set temporal Roll Drag Coefficient
    tmpRollDragCoefficient = vt->getRollDragCoefficient();

    // Set temporal Constant Power Intake
    tmpConstantPowerIntake = vt->getConstantPowerIntake();

    // Set temporal Propulsion Efficiency
    tmpPropulsionEfficiency = vt->getPropulsionEfficiency();

    // Set temporal Recuperation Efficiency
    tmpRecuperationEfficiency = vt->getRecuperationEfficiency();

    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(vt->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(vt->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(vt->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(vt->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(vt->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(vt->getExtraParameter3Value());
}

void vehicleTypeItemDialog::updateParameters()
{
    // Set ID in the label
    ui->TextID->setText(tmpId);

    // Set image
    setImage(tmpVClass);

    // Set Accel in the label
    ui->TextAccel->setText(QString::number(tmpAccel));

    // Set Decel in the label
    ui->TextDecel->setText(QString::number(tmpDecel));

    // Set Sigma in the label
    ui->TextSigma->setText(QString::number(tmpSigma));

    // Set Tau in the label
    ui->TextTau->setText(QString::number(tmpTau));

    // Set Lenght in the label
    ui->TextLength->setText(QString::number(tmpLength));

    // Set Min Gap in the label
    ui->TextMinGap->setText(QString::number(tmpMinGap));

    // Set Max Speed in the label
    ui->TextMaxSpeed->setText(QString::number(tmpMaxSpeed));

    // Set Speed Factor in the label
    ui->TextSpeedFactor->setText(QString::number(tmpSpeedFactor));

    // Set Speed Dev in the label
    ui->TextSpeedDev->setText(QString::number(tmpSpeedDev));

    // Set Color in the label
    ui->TextColor->setText(tmpColor);

    // Set Width in the label
    ui->TextWidth->setText(QString::number(tmpWidth));

    // Set Impatience in the label
    ui->TextImpatience->setText(QString::number(tmpImpatience));

    // Set Lane Change Model in the label
    ui->TextLaneChangeModel->setText(tmpLaneChangeModel);

    // Set Act Bat Kap in the label
    ui->TextActBatKap->setText(QString::number(tmpActBatKap));

    // Set Max Bat Kap in the label
    ui->TextMaxBatKap->setText(QString::number(tmpMaxBatKap));

    // Set Power Max in the label
    ui->TextPowerMax->setText(QString::number(tmpPowerMax));

    // Set Mass in the label
    ui->TextMass->setText(QString::number(tmpMass));

    // Set Front Surface Area in the label
    ui->TextFrontSurfaceArea->setText(QString::number(tmpFrontSurfaceArea));

    // Set Air Drag Coefficient in the label
    ui->TextAirDragCoefficient->setText(QString::number(tmpAirDragCoefficient));

    // Set Internal Moment Of Inertia in the label
    ui->TextInternalMomentOfInertia->setText(QString::number(tmpInternalMomentOfInertia));

    // Set Radial Drag Coeffcient in the label
    ui->TextRadialDragCoefficient->setText(QString::number(tmpRadialDragCoefficient));

    // Set Roll Drag Coefficient in the label
    ui->TextRollDragCoefficient->setText(QString::number(tmpRollDragCoefficient));

    // Set Const Power Intake in the label
    ui->TextConstantPowerIntake->setText(QString::number(tmpConstantPowerIntake));

    // Set Propulsion Efficiency in the label
    ui->TextPropulsionEfficiency->setText(QString::number(tmpPropulsionEfficiency));

    // Set Recuperation Efficiency in the label
    ui->TextRecuperationEfficiency->setText(QString::number(tmpRecuperationEfficiency));

    // Set Img File in the label
    ui->TextImgFile->setText(tmpFilename);

    // Set VClass in the label
    ui->ComboBoxVClass->setCurrentText(vt->getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeClassValue(tmpVClass));

    // Set GUI Shape in the label
    ui->ComboBoxGuiShape->setCurrentIndex(tmpGuiShape);

    // Set Emission Class in the label
    ui->ComboBoxEmissionClass->setCurrentText(tmpEmissionClass);

    // If custom parameter 1 was changed
    if(vt->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(vt->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(vt->getExtraParameter1Value());
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
    if(vt->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(vt->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(vt->getExtraParameter2Value());
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
    if(vt->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(vt->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(vt->getExtraParameter3Value());
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

void vehicleTypeItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to vehicle type
    vt = dynamic_cast<vehicleTypeItem *>(item);

    // If item is a vehicle type
    if(vt)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Show dialog
        show();
    }
}

void vehicleTypeItemDialog::on_TextAccel_textChanged()
{
    // Set tmp Accel
    tmpAccel = ui->TextAccel->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextDecel_textChanged()
{
    // Set tmp Decel
    tmpDecel = ui->TextDecel->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextSigma_textChanged()
{
    // Set tmp Sigma
    tmpSigma = ui->TextSigma->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextTau_textChanged()
{
    // Set tmp Tau
    tmpTau = ui->TextTau->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextLength_textChanged()
{
    // Set tmp Lenght
    tmpLength = ui->TextLength->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextMinGap_textChanged()
{
    // Set tmp minGap
    tmpMinGap = ui->TextMinGap->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextMaxSpeed_textChanged()
{
    // Set tmp MaxSpeed
    tmpMaxSpeed = ui->TextMaxSpeed->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextSpeedFactor_textChanged()
{
    // Set tmp Speed Factor
    tmpSpeedFactor = ui->TextSpeedFactor->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextSpeedDev_textChanged()
{
    // Set tmp Speed Dev
    tmpSpeedDev = ui->TextSpeedDev->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextColor_textChanged()
{
    // Set tmp Color
    tmpColor = ui->TextColor->toPlainText();
}

void vehicleTypeItemDialog::on_TextWidth_textChanged()
{
    // Set tmp Width
    tmpWidth = ui->TextWidth->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextImpatience_textChanged()
{
    // Set tmp Impatience
    tmpImpatience =  ui->TextImpatience->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextLaneChangeModel_textChanged()
{
    // Set tmp Lane Change Model
    tmpLaneChangeModel = ui->TextLaneChangeModel->toPlainText();
}

void vehicleTypeItemDialog::on_TextActBatKap_textChanged()
{
    // Set tmp Act Bat Kap
    tmpActBatKap = ui->TextActBatKap->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextMaxBatKap_textChanged()
{
    // Set tmp MaxBatKap
    tmpMaxBatKap = ui->TextMaxBatKap->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextPowerMax_textChanged()
{
    // Set tmp Power Max
    tmpPowerMax = ui->TextPowerMax->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextMass_textChanged()
{
    // Set Mass
    tmpMass = ui->TextMass->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextFrontSurfaceArea_textChanged()
{
    // Set tmp Front Surface Area
    tmpFrontSurfaceArea = ui->TextFrontSurfaceArea->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextAirDragCoefficient_textChanged()
{
    // Set tmp Air Drag Coefficient
    tmpAirDragCoefficient = ui->TextAirDragCoefficient->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextInternalMomentOfInertia_textChanged()
{
    // Set tmp Internal Moment Of Inertnia
    tmpInternalMomentOfInertia = ui->TextInternalMomentOfInertia->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextRadialDragCoefficient_textChanged()
{
    // Set tmp Radial Drag Coefficient
    tmpRadialDragCoefficient = ui->TextRadialDragCoefficient->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextRollDragCoefficient_textChanged()
{
    // Set tmp Roll Drag Coefficient
    tmpRadialDragCoefficient = ui->TextRollDragCoefficient->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextConstantPowerIntake_textChanged()
{
    // Set tmp Constant Powre Intake
    tmpConstantPowerIntake = ui->TextConstantPowerIntake->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextPropulsionEfficiency_textChanged()
{
    // Set temporal Propulsion Efficiency
    tmpPropulsionEfficiency = ui->TextPropulsionEfficiency->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_TextRecuperationEfficiency_textChanged()
{
    // Set Recuperation Efficiency
    tmpRecuperationEfficiency = ui->TextRecuperationEfficiency->toPlainText().toDouble();
}

void vehicleTypeItemDialog::on_ButtonSearch_released()
{
    qDebug() << "TERMINAR";
}


void vehicleTypeItemDialog::on_ComboBoxVClass_currentIndexChanged(int index)
{
    // get enum of vehicle selected
    tmpVClass = static_cast<vehicleClass>(index);

    // Set ID of the Vehicle
    tmpId = vt->getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeClassValue(tmpVClass) + QString::number(vt->getDatabase()->getVehicleTypeTable()->getNextVehicleTypeIndex(tmpVClass));

    // Set ID of the Vehicle in Dialog
    ui->TextID->setText(tmpId);
    ui->TextID->setAlignment(Qt::AlignCenter);

    //Set image of vehicle
    setImage(tmpVClass);
}

void vehicleTypeItemDialog::on_ComboBoxEmissionClass_currentTextChanged(const QString &arg1)
{
    // Set tmp Emission Class
    tmpEmissionClass = arg1;
}

void vehicleTypeItemDialog::on_ComboBoxGuiShape_currentIndexChanged(int index)
{
    // Set tmp GUI Shape
    tmpGuiShape = static_cast<vehicleShape>(index);
}

void vehicleTypeItemDialog::on_ButtonAccept_released()
{
    qDebug() << "TERMINAr resto de parametros";

    // Update indexes of Vehicle Type Table
    vt->getDatabase()->getVehicleTypeTable()->updateNextVehicleTypeIndex(vt->getVClass());

    // If custom parameter 1 has been modified
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        // Set name and value of custom parameter 1 in the item
        vt->setExtraParameter1Name(getTmpExtraParameter1Name());
        vt->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // If custom parameter 2 has been modified
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        // Set name and value of custom parameter 2 in the item
        vt->setExtraParameter2Name(getTmpExtraParameter2Name());
        vt->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // If custom parameter 3 has been modified
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        // Set name and value of custom parameter 3 in the item
        vt->setExtraParameter3Name(getTmpExtraParameter3Name());
        vt->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close Dialog
    close();
}

void vehicleTypeItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close Dialog
    close();
}

void vehicleTypeItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void vehicleTypeItemDialog::on_ButtonCustomParameter1Name_released()
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

void vehicleTypeItemDialog::on_ButtonCustomParameter2Name_released()
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

void vehicleTypeItemDialog::on_ButtonCustomParameter3Name_released()
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

void vehicleTypeItemDialog::on_TextCustomParameter1Value_textChanged()
{
    setTmpExtraParameter1Value(ui->TextCustomParameter1Value->toPlainText());
}

void vehicleTypeItemDialog::on_TextCustomParameter2Value_textChanged()
{
    setTmpExtraParameter2Value(ui->TextCustomParameter2Value->toPlainText());
}

void vehicleTypeItemDialog::on_TextCustomParameter3Value_textChanged()
{
    setTmpExtraParameter3Value(ui->TextCustomParameter3Value->toPlainText());
}

void vehicleTypeItemDialog::setImage(vehicleClass vc)
{
    // Set ID and Img Vehicle
    if( vc == vehicleClassUnknown )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/unknow.png);"));
    }
    else if( vc == vehicleClassBicycle )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/bicycle.png);"));
    }
    else if( vc == vehicleClassMoped )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/moped.png);"));
    }
    else if( vc == vehicleClassMotorcycle )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/motorcycle.png);"));
    }
    else if( vc == vehicleClassPrivate )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/private.png);"));
    }
    else if( vc == vehicleClassHov )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/hov.png);"));
    }
    else if( vc == vehicleClassEvehicle )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/evehicle.png);"));
    }
    else if( vc == vehicleClassPassenger )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/passenger.png);"));
    }
    else if (vc == vehicleClassCoach )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/coach.png);"));
    }
    else if( vc == vehicleClassBus )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/bus.png);"));
    }
    else if( vc == vehicleClassDelivery )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/delivery.png);"));
    }
    else if( vc == vehicleClassTruck )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/truck.png);"));
    }
    else if( vc == vehicleClassTrailer )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/trailer.png);"));
    }
    else if( vc == vehicleClassTaxi )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/taxi.png);"));
    }
    else if( vc == vehicleClassEmergency )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/emergency.png);"));
    }
    else if( vc == vehicleClassArmy )
    {
        ui->LabelImgVehicle->setStyleSheet(QStringLiteral("image: url(:/items/vehicleTypes/army.png);"));
    }
}
