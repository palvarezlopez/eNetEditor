#ifndef CHARGINGSTATIONDIALOG_H
#define CHARGINGSTATIONDIALOG_H

#include "../eNetEditorItemDialog.h"


namespace Ui
{
class chargingStationItemDialog;
}

class chargingStationItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit chargingStationItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~chargingStationItemDialog();


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

    void on_TextStartPosition_textChanged();

    void on_TextEndPosition_textChanged();

    void on_TextChargingPower_textChanged();

    void on_TextEfficiency_textChanged();

    void on_TextChargeDelay_textChanged();

    void on_CheckBoxChargeInTransit_toggled(bool checked);


private:

    // Interface
    Ui::chargingStationItemDialog *ui;

    // Pointer to charging station
    chargingStationItem *cs;

    // Temporal Start position
    int tmpStartPos;

    // Temporal End position
    int tmpEndPos;

    // Temporal Charging power
    long int tmpChrgPower;

    // Temporal Efficiency
    qreal tmpEfficiency;

    // Temporal Charge in transit
    bool tmpChargeInTransit;

    // Temporal ChargeDelay
    unsigned int tmpChargeDelay;
};

#endif // CHARGINGSTATIONDIALOG_H
