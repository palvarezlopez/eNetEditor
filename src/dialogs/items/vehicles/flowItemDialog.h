#ifndef FLOWDIALOG_H
#define FLOWDIALOG_H

#include "abstractVehicleItemDialog.h"


namespace Ui
{
class flowItemDialog;
}

class flowItemDialog : public abstractVehicleItemDialog
{
    Q_OBJECT

public:

    explicit flowItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~flowItemDialog();


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

    void on_TextCustomParameter1Value_textChanged();

    void on_TextCustomParameter2Value_textChanged();

    void on_TextCustomParameter3Value_textChanged();

    void on_ButtonCustomParameter1Name_released();

    void on_ButtonCustomParameter2Name_released();

    void on_ButtonCustomParameter3Name_released();

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

    void on_TextBegin_textChanged();

    void on_TextEnd_textChanged();

    void on_RadioButtonProbability_toggled(bool checked);

    void on_TextProbability_textChanged();

    void on_RadioButtonPeriod_toggled(bool checked);

    void on_TextPeriod_textChanged();

    void on_RadioButtonVehsPerHour_toggled(bool checked);

    void on_TextVehsPerHour_textChanged();

    void on_RadioButtonNumber_toggled(bool checked);

    void on_TextNumber_textChanged();


private:

    // UI
    Ui::flowItemDialog *ui;

    // Pointer to flow
    flowItem *f;

    // Temporal Vtype String
    QString tmpVT;

    // Temporal parameter 01 - This vehicle's color
    QString tmpColor;

    // Temporal parameter 02 - The lane on which the vehicle shall be inserted. [≥0, "random", "free", "allowed", "best", "first"]
    QString tmpDepartLane;

    // Temporal parameter 03 - The position at which the vehicle shall enter the net; ["random", "free", "random_free", "base", "pwagSimple", "pwagGeneric"]
    QString tmpDepartPos;

    // Temporal parameter 04 - The speed with which the vehicle shall enter the network. [≥0, "random", "max"]
    QString tmpDepartSpeed;

    // Temporal parameter 05 - The lane at which the vehicle shall leave the network [≥0,"current"]
    QString tmpArrivalLane;

    // Temporal parameter 06 - The position at which the vehicle shall leave the network [≥0(1), "random", "max"]
    QString tmpArrivalPos;

    // Temporal parameter 07 - The speed with which the vehicle shall leave the network [≥0,"current"]
    QString tmpArrivalSpeed;

    // Temporal parameter 08 - A string specifying the id of a public transport line which can be used when specifying person rides
    QString tmpLine;

    // Temporal parameter 90 - The number of occupied seats when the vehicle is inserted
    int tmpPersonNumber;

    // Temporal parameter 10 - The number of occupied container places when the vehicle is inserted
    int tmpContainerNumber;

    // Temporal parameter 11
    qreal tmpBegin;

    // Temporal parameter 12
    qreal tmpEnd;

    // Temporal parameter 13
    bool tmpVehsPerHourOption;

    // Temporal parameter 14
    qreal tmpVehsPerHour;

    // Temporal parameter 15
    bool tmpPeriodOption;

    // Temporal parameter 16
    qreal tmpPeriod;

    // Temporal parameter 17
    bool tmpProbabilityOption;

    // Temporal parameter 18
    qreal tmpProbability;

    // Temporal parameter 19
    bool tmpNumberOption;

    // Temporal parameter 20
    int tmpNumber;
};

#endif // FLOWDIALOG_H
