#ifndef VEHICLEDIALOG_H
#define VEHICLEDIALOG_H

#include "abstractVehicleItemDialog.h"


namespace Ui
{
class vehicleItemDialog;
}

class vehicleItemDialog : public abstractVehicleItemDialog
{
    Q_OBJECT

public:

    explicit vehicleItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~vehicleItemDialog();


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

    void on_ComboBoxVType_currentTextChanged(const QString &arg1);

    void on_TextRoute_textChanged();

    void on_TextLine_textChanged();

    void on_TextColor_textChanged();

    void on_TextPersonNumber_textChanged();

    void on_TextContainerNumber_textChanged();

    void on_ComboBoxDepartLane_currentTextChanged(const QString &arg1);

    void on_ComboBoxDepartPos_currentTextChanged(const QString &arg1);

    void on_ComboBoxDepartSpeed_currentTextChanged(const QString &arg1);

    void on_ComboBoxArrivalLane_currentTextChanged(const QString &arg1);

    void on_ComboBoxArrivalPos_currentTextChanged(const QString &arg1);

    void on_ComboBoxArrivalSpeed_currentTextChanged(const QString &arg1);

    void on_TextDepartLane_textChanged();

    void on_TextDepartPos_textChanged();

    void on_TextDepartSpeed_textChanged();

    void on_TextArrivalLane_textChanged();

    void on_TextArrivalPos_textChanged();

    void on_TextArrivalSpeed_textChanged();

    void on_TextDepart_textChanged();

    void fillVehicleTypeList();


private:

    // UI
    Ui::vehicleItemDialog *ui;

    // Pointer to vehicle
    vehicleItem *v;

    // Temporal Vtype String
    QString tmpVT;

    // Temporal parameter 01 - This vehicle's color
    QString tmpColor;

    // Temporal parameter 02 - The time step at which the vehicle shall enter the network
    qreal tmpDepart;

    // Temporal parameter 03 - The lane on which the vehicle shall be inserted. [≥0, "random", "free", "allowed", "best", "first"]
    QString tmpDepartLane;

    // Temporal parameter 04 - The position at which the vehicle shall enter the net; ["random", "free", "random_free", "base", "pwagSimple", "pwagGeneric"]
    QString tmpDepartPos;

    // Temporal parameter 05 - The speed with which the vehicle shall enter the network. [≥0, "random", "max"]
    QString tmpDepartSpeed;

    // Temporal parameter 06 - The lane at which the vehicle shall leave the network [≥0,"current"]
    QString tmpArrivalLane;

    // Temporal parameter 07 - The position at which the vehicle shall leave the network [≥0(1), "random", "max"]
    QString tmpArrivalPos;

    // Temporal parameter 08 - The speed with which the vehicle shall leave the network [≥0,"current"]
    QString tmpArrivalSpeed;

    // Temporal parameter 09 - A string specifying the id of a public transport line which can be used when specifying person rides
    QString tmpLine;

    // Temporal parameter 10 - The number of occupied seats when the vehicle is inserted
    int tmpPersonNumber;

    // Temporal parameter 11 - The number of occupied container places when the vehicle is inserted
    int tmpContainerNumber;
};

#endif // VEHICLEDIALOG_H
