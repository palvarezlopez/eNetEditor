#ifndef LANEDIALOG_H
#define LANEDIALOG_H

#include "eNetEditorItemDialog.h"


namespace Ui
{
class laneItemDialog;
}

class laneItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit laneItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~laneItemDialog();


public slots:

    void resetParameters();

    void updateParameters();

    void openItemDialog(eNetEditorItem *item);

    // Revisar esto

    void updateListVehicleTypes();

    void updateListOfElements();


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

    void on_TextSpeed_textChanged();

    void on_TextWidth_textChanged();

    void on_ListAllowVehicles_itemDoubleClicked(QListWidgetItem *item);

    void on_ListDisallowVehicles_itemDoubleClicked(QListWidgetItem *item);

    void on_ListConnections_itemDoubleClicked(QListWidgetItem *item);

    void on_ListProhibitions_itemDoubleClicked(QListWidgetItem *item);

    void on_ListBusStops_itemDoubleClicked(QListWidgetItem *item);

    void on_ListChargingStations_itemDoubleClicked(QListWidgetItem *item);

    void on_ListDetectorsE1_itemDoubleClicked(QListWidgetItem *item);

    void on_ListDetectorsE2_itemDoubleClicked(QListWidgetItem *item);

    void on_ListDetectorsE3_itemDoubleClicked(QListWidgetItem *item);


private:

    // Interface
    Ui::laneItemDialog *ui;

    // Vehicle dialog
    edgeVehicleTypesAllowedDialog *vehiclesDialog;

    // Lane
    laneItem *l;

    // Lane parameter 01 - Speed
    qreal tmpSpeed;

    // Lane parameter 02 - Width
    qreal tmpWidth;

    // Temporal list of vehicles
    QList<vehicleClass> *tmpListOfAllowedVehicles;
    QList<vehicleClass> *tmpListOfDisallowedVehicles;
};

#endif // LANEDIALOG_H
