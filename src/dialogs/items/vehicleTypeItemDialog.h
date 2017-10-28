#ifndef NEWVEHICLEDIALOG_H
#define NEWVEHICLEDIALOG_H

#include "eNetEditorItemDialog.h"


namespace Ui
{
class vehicleTypeItemDialog;
}


class vehicleTypeItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit vehicleTypeItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~vehicleTypeItemDialog();


public slots:

    void resetParameters();

    void updateParameters();

    void openItemDialog(eNetEditorItem *item);


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


private slots:

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_ButtonReset_released();

    void on_ButtonCustomParameter1Name_released();

    void on_ButtonCustomParameter2Name_released();

    void on_ButtonCustomParameter3Name_released();

    void on_TextCustomParameter1Value_textChanged();

    void on_TextCustomParameter2Value_textChanged();

    void on_TextCustomParameter3Value_textChanged();

    void on_TextAccel_textChanged();

    void on_TextDecel_textChanged();

    void on_TextSigma_textChanged();

    void on_TextTau_textChanged();

    void on_TextLength_textChanged();

    void on_TextMinGap_textChanged();

    void on_TextMaxSpeed_textChanged();

    void on_TextSpeedFactor_textChanged();

    void on_TextSpeedDev_textChanged();

    void on_TextColor_textChanged();

    void on_TextWidth_textChanged();

    void on_TextImpatience_textChanged();

    void on_TextLaneChangeModel_textChanged();

    void on_TextActBatKap_textChanged();

    void on_TextMaxBatKap_textChanged();

    void on_TextPowerMax_textChanged();

    void on_TextMass_textChanged();

    void on_TextFrontSurfaceArea_textChanged();

    void on_TextAirDragCoefficient_textChanged();

    void on_TextInternalMomentOfInertia_textChanged();

    void on_TextRadialDragCoefficient_textChanged();

    void on_TextRollDragCoefficient_textChanged();

    void on_TextConstantPowerIntake_textChanged();

    void on_TextPropulsionEfficiency_textChanged();

    void on_TextRecuperationEfficiency_textChanged();

    void on_ButtonSearch_released();

    void on_ComboBoxVClass_currentIndexChanged(int index);

    void on_ComboBoxEmissionClass_currentTextChanged(const QString &arg1);

    void on_ComboBoxGuiShape_currentIndexChanged(int index);


private:

    // GUI
    Ui::vehicleTypeItemDialog *ui;

    // Pointer to new vehicle
    vehicleTypeItem *vt;

    // Temporal parameter - ID
    QString tmpId;

    // Temporal parameter - accel - The acceleration ability of vehicles of this type (in m/s^)
    qreal tmpAccel;

    // Temporal parameter - decel - The deceleration ability of vehicles of this type (in m/s^)
    qreal tmpDecel;

    // Temporal parameter - sigma Car-following model parameter, see below
    qreal tmpSigma;

    // Temporal parameter - tau - Car-following model parameter
    qreal tmpTau;

    // Temporal parameter - length - The vehicle's netto-length (length) (in m)
    qreal tmpLength;

    // Temporal parameter - minGap - Empty space after leader [m]
    qreal tmpMinGap;

    // Temporal parameter - maxSpeed - The vehicle's maximum velocity (in m/s)
    qreal tmpMaxSpeed;

    // Temporal parameter - speedFactor - The vehicles expected multiplicator for edge speed limits
    qreal tmpSpeedFactor;

    // Temporal parameter - speedDev - The deviation of the speedFactor
    qreal tmpSpeedDev;

    // Temporal parameter - color - This vehicle type's color
    QString tmpColor;

    // Temporal parameter - vClass - An abstract vehicle class (see below)
    vehicleClass tmpVClass;

    // Temporal parameter - emission Class - An abstract emission class
    QString tmpEmissionClass;

    // Temporal parameter - guiShape - How this vehicle is rendered (Will be implemented in other version)
    vehicleShape tmpGuiShape;

    // Temporal parameter - width - The vehicle's width [m] (only used for drawing)
    qreal tmpWidth;

    // Temporal parameter - filename - Image file for rendering vehicles of this type (should be grayscale to allow functional coloring)
    QString tmpFilename;

    // Temporal parameter - impatience - Willingess of drivers to impede vehicles with higher priority.
    qreal tmpImpatience;

    // Temporal parameter - edge Change Model - Edge changing model name
    QString tmpLaneChangeModel;

    // Temporal parameter - Actual battery capacity
    qreal tmpActBatKap;

    // Temporal parameter - Max battery capacity
    qreal tmpMaxBatKap;

    // Temporal parameter - Power Max
    qreal tmpPowerMax;

    // Temporal parameter - Mass of vehicle
    qreal tmpMass;

    // Temporal parameter - Front surface area
    qreal tmpFrontSurfaceArea;

    // Temporal parameter - Air drag coefficient
    qreal tmpAirDragCoefficient;

    // Temporal parameter - Internal moment of inertia
    qreal tmpInternalMomentOfInertia;

    // Temporal parameter - Radial drag coefficient
    qreal tmpRadialDragCoefficient;

    // Temporal parameter - Roll drag coefficient
    qreal tmpRollDragCoefficient;

    // Temporal parameter - Constant power intake
    qreal tmpConstantPowerIntake;

    // Temporal parameter - Propulsion Efficienciy
    qreal tmpPropulsionEfficiency;

    // Temporal parameter - Recuperation efficiency
    qreal tmpRecuperationEfficiency;

    // Function to set image of vehicle
    void setImage(vehicleClass vc);
};

#endif // NEWVEHICLEDIALOG_H
