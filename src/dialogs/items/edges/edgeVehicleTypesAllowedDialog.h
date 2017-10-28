#ifndef VEHICLETYPESALLOWEDDIALOG_H
#define VEHICLETYPESALLOWEDDIALOG_H

#include "../eNetEditorItemDialog.h"


namespace Ui
{
class edgeVehicleTypesAllowedDialog;
}

class edgeVehicleTypesAllowedDialog : public eNetEditorDialog
{
    Q_OBJECT

public:

    explicit edgeVehicleTypesAllowedDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~edgeVehicleTypesAllowedDialog();


public slots:

    void resetParameters();

    void updateParameters();

    void openDialog(QList<vehicleClass> *newAllowedVehicles, QList<vehicleClass> *newDisallowedVehicles, laneItemDialog *newLD);


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


private slots:

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_Button01Bike_released();

    void on_Button02Scooter_released();

    void on_Button03Motorcycle_released();

    void on_Button04Car_released();

    void on_Button05HovCar_released();

    void on_Button06ElectricCar_released();

    void on_Button07SmallBus_released();

    void on_Button08LargeBus_released();

    void on_Button09EmilBus_released();

    void on_Button10SmallTruck_released();

    void on_Button11LargeTruck_released();

    void on_Button12HeavyTruck_released();

    void on_Button13Taxi_released();

    void on_Button14Ambulance_released();

    void on_Button15Tank_released();


private:

    // UI
    Ui::edgeVehicleTypesAllowedDialog *ui;

    // Pointer to database
    eNetEditorDatabase *database;

    // Pointer to laneItemDialog
    laneItemDialog *LD;

    QVector<bool> selectedVehicles;

    QList<vehicleClass> *allowedVehicles;

    QList<vehicleClass> *disallowedVehicles;
};

#endif // VEHICLETYPESALLOWEDDIALOG_H
