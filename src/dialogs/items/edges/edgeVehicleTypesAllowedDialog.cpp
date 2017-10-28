#include "edgeVehicleTypesAllowedDialog.h"
#include "ui_edgeVehicleTypesAllowedDialog.h"

#include "../../../configuration/items/vehicleTypeItemConfiguration.h"

#include "../laneItemDialog.h"

#include "../../../configuration/items/eNetEditorItemConfiguration.h"

#include "../../../database/eNetEditorDatabase.h"

#include "../../../items/vehicleTypeItem.h"


edgeVehicleTypesAllowedDialog::edgeVehicleTypesAllowedDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorDialog(eNetEditorMainW), ui(new Ui::edgeVehicleTypesAllowedDialog)
{
    // Create GUI
    ui->setupUi(this);

    // Set pointers to vehicles to NULL
    allowedVehicles = NULL;
    disallowedVehicles = NULL;
}

edgeVehicleTypesAllowedDialog::~edgeVehicleTypesAllowedDialog()
{
    delete ui;
}

void edgeVehicleTypesAllowedDialog::openDialog(QList<vehicleClass> *newAllowedVehicles, QList<vehicleClass> *newDisallowedVehicles, laneItemDialog *newLD)
{
    // If pointer to laneItemDialog is valid
    if(newLD != NULL)
    {
        // link laneItemDialog
        LD = newLD;

        // Copy the actual list of allowed vehicles
        allowedVehicles = newAllowedVehicles;

        // Copy the actual list of disallowed vehicles
        disallowedVehicles = newDisallowedVehicles;

        // Clear selected vehicles
        selectedVehicles.clear();

        // Declare iterator over the list of allowed vehicles
        QList<vehicleClass>::iterator i = newAllowedVehicles->begin();

        // Set signals
        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassUnknown))
        {
            selectedVehicles.push_back(true);

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassBicycle))
        {
            selectedVehicles.push_back(true);

            ui->Label01Bike->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label01Bike->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassMoped))
        {
            selectedVehicles.push_back(true);

            ui->Label02Scooter->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label02Scooter->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassMotorcycle))
        {
            selectedVehicles.push_back(true);

            ui->Label03Motorcycle->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label03Motorcycle->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassPrivate))
        {
            selectedVehicles.push_back(true);

            ui->Label04Car->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label04Car->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassHov))
        {
            selectedVehicles.push_back(true);

            ui->Label05HovCar->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label05HovCar->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassEvehicle))
        {
            selectedVehicles.push_back(true);

            ui->Label06ElectricCar->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label06ElectricCar->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassPassenger))
        {
            selectedVehicles.push_back(true);

            ui->Label07SmallBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label07SmallBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassCoach))
        {
            selectedVehicles.push_back(true);

            ui->Label08LargeBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label08LargeBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassBus))
        {
            selectedVehicles.push_back(true);

            ui->Label09ElectricBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label09ElectricBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassDelivery))
        {
            selectedVehicles.push_back(true);

            ui->Label10SmallTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label10SmallTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassTruck))
        {
            selectedVehicles.push_back(true);

            ui->Label11LargeTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label11LargeTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassTrailer))
        {
            selectedVehicles.push_back(true);

            ui->Label12HeavyTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label12HeavyTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassTaxi))
        {
            selectedVehicles.push_back(true);

            ui->Label13Taxi->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label13Taxi->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassEmergency))
        {
            selectedVehicles.push_back(true);

            ui->Label14Ambulance->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label14Ambulance->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        if((i != newAllowedVehicles->end()) && ((*i) == vehicleClassArmy))
        {
            selectedVehicles.push_back(true);

            ui->Label15Tank->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");

            i++;
        }
        else
        {
            selectedVehicles.push_back(false);

            ui->Label15Tank->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
        }

        // Show Dialog
        show();
    }
}

void edgeVehicleTypesAllowedDialog::on_ButtonAccept_released()
{
    // Clear lists
    allowedVehicles->clear();
    disallowedVehicles->clear();

    if(selectedVehicles[vehicleClassBicycle])
    {
        allowedVehicles->push_back(vehicleClassBicycle);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassBicycle);
    }

    if(selectedVehicles[vehicleClassMoped])
    {
        allowedVehicles->push_back(vehicleClassMoped);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassMoped);
    }

    if(selectedVehicles[vehicleClassMotorcycle])
    {
        allowedVehicles->push_back(vehicleClassMotorcycle);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassMotorcycle);
    }

    if(selectedVehicles[vehicleClassPrivate])
    {
        allowedVehicles->push_back(vehicleClassPrivate);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassPrivate);
    }

    if(selectedVehicles[vehicleClassHov])
    {
        allowedVehicles->push_back(vehicleClassHov);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassHov);
    }

    if(selectedVehicles[vehicleClassEvehicle])
    {
        allowedVehicles->push_back(vehicleClassEvehicle);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassEvehicle);
    }

    if(selectedVehicles[vehicleClassPassenger])
    {
        allowedVehicles->push_back(vehicleClassPassenger);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassPassenger);
    }

    if(selectedVehicles[vehicleClassCoach])
    {
        allowedVehicles->push_back(vehicleClassCoach);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassCoach);
    }

    if(selectedVehicles[vehicleClassBus])
    {
        allowedVehicles->push_back(vehicleClassBus);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassBus);
    }

    if(selectedVehicles[vehicleClassDelivery])
    {
        allowedVehicles->push_back(vehicleClassDelivery);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassDelivery);
    }

    if(selectedVehicles[vehicleClassTruck])
    {
        allowedVehicles->push_back(vehicleClassTruck);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassTruck);
    }

    if(selectedVehicles[vehicleClassTrailer])
    {
        allowedVehicles->push_back(vehicleClassTrailer);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassTrailer);
    }

    if(selectedVehicles[vehicleClassTaxi])
    {
        allowedVehicles->push_back(vehicleClassTaxi);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassTaxi);
    }

    if(selectedVehicles[vehicleClassEmergency])
    {
        allowedVehicles->push_back(vehicleClassEmergency);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassEmergency);
    }

    if(selectedVehicles[vehicleClassEmergency])
    {
        allowedVehicles->push_back(vehicleClassEmergency);
    }
    else
    {
        disallowedVehicles->push_back(vehicleClassEmergency);
    }

    // Update List of Vehicles
    LD->updateListVehicleTypes();

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close Dialog
    close();
}

void edgeVehicleTypesAllowedDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog
    close();
}

void edgeVehicleTypesAllowedDialog::on_Button01Bike_released()
{
    if(selectedVehicles[vehicleClassBicycle])
    {
        selectedVehicles[vehicleClassBicycle] = false;

        ui->Label01Bike->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassBicycle] = true;

        ui->Label01Bike->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button02Scooter_released()
{
    if(selectedVehicles[vehicleClassMoped])
    {
        selectedVehicles[vehicleClassMoped] = false;

        ui->Label02Scooter->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassMoped] = true;

        ui->Label02Scooter->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button03Motorcycle_released()
{
    if(selectedVehicles[vehicleClassMotorcycle])
    {
        selectedVehicles[vehicleClassMotorcycle] = false;

        ui->Label03Motorcycle->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassMotorcycle] = true;

        ui->Label03Motorcycle->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button04Car_released()
{
    if(selectedVehicles[vehicleClassPrivate])
    {
        selectedVehicles[vehicleClassPrivate] = false;

        ui->Label04Car->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassPrivate] = true;

        ui->Label04Car->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }

}

void edgeVehicleTypesAllowedDialog::on_Button05HovCar_released()
{
    if(selectedVehicles[vehicleClassHov])
    {
        selectedVehicles[vehicleClassHov] = false;

        ui->Label05HovCar->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassHov] = true;

        ui->Label05HovCar->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }

}

void edgeVehicleTypesAllowedDialog::on_Button06ElectricCar_released()
{
    if(selectedVehicles[vehicleClassEvehicle])
    {
        selectedVehicles[vehicleClassEvehicle] = false;

        ui->Label06ElectricCar->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassEvehicle] = true;

        ui->Label06ElectricCar->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button07SmallBus_released()
{
    if(selectedVehicles[vehicleClassPassenger])
    {
        selectedVehicles[vehicleClassPassenger] = false;

        ui->Label07SmallBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassPassenger] = true;

        ui->Label07SmallBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button08LargeBus_released()
{
    if(selectedVehicles[vehicleClassCoach])
    {
        selectedVehicles[vehicleClassCoach] = false;

        ui->Label08LargeBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassCoach] = true;

        ui->Label08LargeBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button09EmilBus_released()
{
    if(selectedVehicles[vehicleClassBus])
    {
        selectedVehicles[vehicleClassBus] = false;

        ui->Label09ElectricBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassBus] = true;

        ui->Label09ElectricBus->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button10SmallTruck_released()
{
    if(selectedVehicles[vehicleClassDelivery])
    {
        selectedVehicles[vehicleClassDelivery] = false;

        ui->Label10SmallTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassDelivery] = true;

        ui->Label10SmallTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button11LargeTruck_released()
{
    if(selectedVehicles[vehicleClassTruck])
    {
        selectedVehicles[vehicleClassTruck] = false;

        ui->Label11LargeTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassTruck] = true;

        ui->Label11LargeTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button12HeavyTruck_released()
{
    if(selectedVehicles[vehicleClassTrailer])
    {
        selectedVehicles[vehicleClassTrailer] = false;

        ui->Label12HeavyTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassTrailer] = true;

        ui->Label12HeavyTruck->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button13Taxi_released()
{
    if(selectedVehicles[vehicleClassTaxi])
    {
        selectedVehicles[vehicleClassTaxi] = false;

        ui->Label13Taxi->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassTaxi] = true;

        ui->Label13Taxi->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button14Ambulance_released()
{
    if(selectedVehicles[vehicleClassEmergency])
    {
        selectedVehicles[vehicleClassEmergency] = false;

        ui->Label14Ambulance->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassEmergency] = true;

        ui->Label14Ambulance->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}

void edgeVehicleTypesAllowedDialog::on_Button15Tank_released()
{
    if(selectedVehicles[vehicleClassArmy])
    {
        selectedVehicles[vehicleClassArmy] = false;

        ui->Label15Tank->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneDisallow.png) }");
    }
    else
    {
        selectedVehicles[vehicleClassArmy] = true;

        ui->Label15Tank->setStyleSheet("QLabel { image: url(:/items/trafficSigns/laneAllow.png) }");
    }
}


void edgeVehicleTypesAllowedDialog::resetParameters()
{
    qDebug() << "TERMINAR";
}

void edgeVehicleTypesAllowedDialog::updateParameters()
{
    qDebug() << "TERMINAR";
}
