#include "vehicleTypeTableDialog.h"
#include "ui_vehicleTypeTableDialog.h"

// Database
#include "../../database/eNetEditorDatabase.h"
#include "../../database/vehicleTypeTable.h"

// Project
#include "../../project/eNetEditorProject.h"

// Scene project
#include "../../project/eNetEditorScene.h"

// Item Dialog
#include "../items/vehicleTypeItemDialog.h"

// Item
#include "../../items/vehicleTypeItem.h"

// Configuration
#include "../../configuration/items/vehicleTypeItemConfiguration.h"
#include "../../configuration/project/eNetEditorProjectConfiguration.h"


vehicleTypeTableDialog::vehicleTypeTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::vehicleTypeTableDialog)
{
    // Create Dialog
    ui->setupUi(this);

    // Create Vehicle Type Dialog (parent is eNetEditorMain Window)
    vehicleTypeItemD = new vehicleTypeItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    vehicleTypeT = NULL;

    // By default pointer to new vehicle is NULL
    vt = NULL;

    // Connect Cancel button of vehicleTypeItemDialog with removeCreatedVehicleType
    connect(vehicleTypeItemD, SIGNAL(dialogClosed(eNetEditorItemDialogCloseType)), this, SLOT(afterItemDialogClosed(eNetEditorItemDialogCloseType)));
}

vehicleTypeTableDialog::~vehicleTypeTableDialog()
{
    // Delete UI
    delete ui;

    // Delete Vehicle Type Dialog
    delete vehicleTypeItemD;
}

vehicleTypeItemDialog *vehicleTypeTableDialog::getVehicleTypeItemDialog() const
{
    return vehicleTypeItemD;
}

void vehicleTypeTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    vehicleTypeT = dynamic_cast<vehicleTypeTable *>(table);

    // If table is valid
    if (vehicleTypeT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(vehicleTypeItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void vehicleTypeTableDialog::updateTable()
{
    // Clear contents of the table
    ui->Table->clearContents();

    // Add rows
    ui->Table->setRowCount(vehicleTypeT->getDatabase()->getVehicleTypeTable()->getNumberOfItems() + 1);

    // Declare rowCounter
    int rowCounter = 0;

    // Declare pointer to vehicle Type Item
    vehicleTypeItem *vtOfTable;

    // Iterate over table of vehicle types
    for (int i = 0; i != vehicleTypeT->getDatabase()->getVehicleTypeTable()->getNumberOfItems(); i++)
    {
        // Get pointer to vehicle type of table
        vtOfTable = vehicleTypeT->getDatabase()->getVehicleTypeOfTable(i);

        // If vehicle is removable
        if(vtOfTable->isRemovable())
        {
            // Declare remove cell
            QTableWidgetItem *removeCell =  new QTableWidgetItem("remove");

            // Declare Icon
            QIcon iconRemove;

            // Set File to icon
            iconRemove.addFile(QStringLiteral(":/main/remove.ico"), QSize(), QIcon::Normal, QIcon::Off);

            // Set icon to row
            removeCell->setIcon(iconRemove);

            // Set alignment to center
            removeCell->setTextAlignment(Qt::AlignCenter);

            // Add remove cell to table
            ui->Table->setItem(rowCounter, 0, removeCell);
        }
        else
        {
            // Declare remove cell
            QTableWidgetItem *notRemovableCell =  new QTableWidgetItem("not removable");

            // Declare Icon
            QIcon iconNotRemovable;

            // Set File to icon
            iconNotRemovable.addFile(QStringLiteral(":/main/cancel.ico"), QSize(), QIcon::Normal, QIcon::Off);

            // Set icon to row
            notRemovableCell->setIcon(iconNotRemovable);

            // Set alignment to center
            notRemovableCell->setTextAlignment(Qt::AlignCenter);

            // Add remove cell to table
            ui->Table->setItem(rowCounter, 0, notRemovableCell);
        }
        // Declare item with vehicle type parameter 01
        QTableWidgetItem *VTypeParameter01 = new QTableWidgetItem(vtOfTable->getItemId());

        // Set alignment to center
        VTypeParameter01->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 1, VTypeParameter01);

        // Declare item with vehicle type parameter 02
        QTableWidgetItem *VTypeParameter02 = new QTableWidgetItem(QString::number(vtOfTable->getAccel()));

        // Set alignment to center
        VTypeParameter02->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 2, VTypeParameter02);

        // Declare item with vehicle type parameter 03
        QTableWidgetItem *VTypeParameter03 = new QTableWidgetItem(QString::number(vtOfTable->getDecel()));

        // Set alignment to center
        VTypeParameter03->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 3, VTypeParameter03);

        // Declare item with vehicle type parameter 04
        QTableWidgetItem *VTypeParameter04 = new QTableWidgetItem(QString::number(vtOfTable->getSigma()));

        // Set alignment to center
        VTypeParameter04->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 4, VTypeParameter04);

        // Declare item with vehicle type parameter 05
        QTableWidgetItem *VTypeParameter05 = new QTableWidgetItem(QString::number(vtOfTable->getTau()));

        // Set alignment to center
        VTypeParameter05->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 5, VTypeParameter05);

        // Declare item with vehicle type parameter 06
        QTableWidgetItem *VTypeParameter06 = new QTableWidgetItem(QString::number(vtOfTable->getLength()));

        // Set alignment to center
        VTypeParameter06->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 6, VTypeParameter06);

        // Declare item with vehicle type parameter 07
        QTableWidgetItem *VTypeParameter07 = new QTableWidgetItem(QString::number(vtOfTable->getMinGap()));

        // Set alignment to center
        VTypeParameter07->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 7, VTypeParameter07);

        // Declare item with vehicle type parameter 08
        QTableWidgetItem *VTypeParameter08 = new QTableWidgetItem(QString::number(vtOfTable->getMaxSpeed()));

        // Set alignment to center
        VTypeParameter08->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 8, VTypeParameter08);

        // Declare item with vehicle type parameter 09
        QTableWidgetItem *VTypeParameter09 = new QTableWidgetItem(QString::number(vtOfTable->getSpeedFactor()));

        // Set alignment to center
        VTypeParameter09->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 9, VTypeParameter09);

        // Declare item with vehicle type parameter 10
        QTableWidgetItem *VTypeParameter10 = new QTableWidgetItem(QString::number(vtOfTable->getSpeedDev()));

        // Set alignment to center
        VTypeParameter10->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 10, VTypeParameter10);

        // Declare item with vehicle type parameter 11
        QTableWidgetItem *VTypeParameter11 = new QTableWidgetItem(vtOfTable->getColor());

        // Set alignment to center
        VTypeParameter11->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 11, VTypeParameter11);

        // Declare item with vehicle type parameter 12
        QTableWidgetItem *VTypeParameter12 = new QTableWidgetItem(vtOfTable->getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeClassValue(vtOfTable->getVClass()));

        // Set alignment to center
        VTypeParameter12->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 12, VTypeParameter12);

        // Declare item with vehicle type parameter 13
        QTableWidgetItem *VTypeParameter13 = new QTableWidgetItem(vtOfTable->getEmissionClass());

        // Set alignment to center
        VTypeParameter13->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 13, VTypeParameter13);

        // Declare item with vehicle type parameter 14
        QTableWidgetItem *VTypeParameter14 = new QTableWidgetItem(vtOfTable->getGuiShape());

        // Set alignment to center
        VTypeParameter14->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 14, VTypeParameter14);

        // Declare item with vehicle type parameter 15
        QTableWidgetItem *VTypeParameter15 = new QTableWidgetItem(QString::number(vtOfTable->getWidth()));

        // Set alignment to center
        VTypeParameter15->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 15, VTypeParameter15);

        // If getImgFilename() is NULL
        if(vtOfTable->getImgFilename() == "")
        {
            // Declare item with vehicle type parameter 16
            QTableWidgetItem *VTypeParameter16 = new QTableWidgetItem("-");

            // Set alignment to center
            VTypeParameter16->setTextAlignment(Qt::AlignCenter);

            // Set Parameter in the table
            ui->Table->setItem(rowCounter, 16, VTypeParameter16);
        }
        else
        {
            // Declare item with vehicle type parameter 16
            QTableWidgetItem *VTypeParameter16 = new QTableWidgetItem(vtOfTable->getImgFilename());

            // Set alignment to center
            VTypeParameter16->setTextAlignment(Qt::AlignCenter);

            // Set Parameter in the table
            ui->Table->setItem(rowCounter, 16, VTypeParameter16);
        }

        // Declare item with vehicle type parameter 17
        QTableWidgetItem *VTypeParameter17 = new QTableWidgetItem(QString::number(vtOfTable->getImpatience()));

        // Set alignment to center
        VTypeParameter17->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 17, VTypeParameter17);

        // Declare item with vehicle type parameter 18
        QTableWidgetItem *VTypeParameter18 = new QTableWidgetItem(vtOfTable->getLaneChangeModel());

        // Set alignment to center
        VTypeParameter18->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 18, VTypeParameter18);

        // Declare item with vehicle type parameter 19
        QTableWidgetItem *VTypeParameter19 = new QTableWidgetItem(QString::number(vtOfTable->getActBatKap()));

        // Set alignment to center
        VTypeParameter19->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 19, VTypeParameter19);

        // Declare item with vehicle type parameter 20
        QTableWidgetItem *VTypeParameter20 = new QTableWidgetItem(QString::number(vtOfTable->getMaxBatKap()));

        // Set alignment to center
        VTypeParameter20->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 20, VTypeParameter20);

        // Declare item with vehicle type parameter 21
        QTableWidgetItem *VTypeParameter21 = new QTableWidgetItem(QString::number(vtOfTable->getPowerMax()));

        // Set alignment to center
        VTypeParameter21->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 21, VTypeParameter21);

        // Declare item with vehicle type parameter 22
        QTableWidgetItem *VTypeParameter22 = new QTableWidgetItem(QString::number(vtOfTable->getMass()));

        // Set alignment to center
        VTypeParameter22->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 22, VTypeParameter22);

        // Declare item with vehicle type parameter 23
        QTableWidgetItem *VTypeParameter23 = new QTableWidgetItem(QString::number(vtOfTable->getFrontSurfaceArea()));

        // Set alignment to center
        VTypeParameter23->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 23, VTypeParameter23);

        // Declare item with vehicle type parameter 24
        QTableWidgetItem *VTypeParameter24 = new QTableWidgetItem(QString::number(vtOfTable->getAirDragCoefficient()));

        // Set alignment to center
        VTypeParameter24->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 24, VTypeParameter24);

        // Declare item with vehicle type parameter 25
        QTableWidgetItem *VTypeParameter25 = new QTableWidgetItem(QString::number(vtOfTable->getInternalMomentOfInertia()));

        // Set alignment to center
        VTypeParameter25->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 25, VTypeParameter25);

        // Declare item with vehicle type parameter 26
        QTableWidgetItem *VTypeParameter26 = new QTableWidgetItem(QString::number(vtOfTable->getRadialDragCoefficient()));

        // Set alignment to center
        VTypeParameter26->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 26, VTypeParameter26);

        // Declare item with vehicle type parameter 27
        QTableWidgetItem *VTypeParameter27 = new QTableWidgetItem(QString::number(vtOfTable->getRollDragCoefficient()));

        // Set alignment to center
        VTypeParameter27->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 27, VTypeParameter27);

        // Declare item with vehicle type parameter 28
        QTableWidgetItem *VTypeParameter28 = new QTableWidgetItem(QString::number(vtOfTable->getConstantPowerIntake()));

        // Set alignment to center
        VTypeParameter28->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 28, VTypeParameter28);

        // Declare item with vehicle type parameter 29
        QTableWidgetItem *VTypeParameter29 = new QTableWidgetItem(QString::number(vtOfTable->getPropulsionEfficiency()));

        // Set alignment to center
        VTypeParameter29->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 29, VTypeParameter29);

        // Declare item with vehicle type parameter 30
        QTableWidgetItem *VTypeParameter30 = new QTableWidgetItem(QString::number(vtOfTable->getRecuperationEfficiency()));

        // Set alignment to center
        VTypeParameter30->setTextAlignment(Qt::AlignCenter);

        // Set Parameter in the table
        ui->Table->setItem(rowCounter, 30, VTypeParameter30);

        // Update rowCounter
        rowCounter++;
    }


    // Declare add Cell
    QTableWidgetItem *addCell =  new QTableWidgetItem("Add");

    // Declare icon of add cell
    QIcon addIcon;

    // Load Icon
    addIcon.addFile(QStringLiteral(":/main/add.ico"), QSize(), QIcon::Normal, QIcon::Off);

    // Set Icon in the cell
    addCell->setIcon(addIcon);

    // Set add cell in the table
    ui->Table->setItem(vehicleTypeT->getDatabase()->getVehicleTypeTable()->getNumberOfItems(), 0, addCell);
}

void vehicleTypeTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{
    // If the selected cell is in the column 0
    if(index.column() == 0)
    {
        // If the table has only one row OR the selected cell is the last row (add cell)
        if((ui->Table->rowCount() == 1) || (index.row() == (vehicleTypeT->getDatabase()->getVehicleTypeTable()->getNumberOfItems())))
        {
            // Insert new vehicle typein dataBase
            vt = new vehicleTypeItem("", vehicleTypeT->getDatabase());

            // Edit the newly created vehicle type
            vehicleTypeItemD->openItemDialog(vt);
        }
        else
        {
            // Get vehicle type using the ID extracted of the table
            vehicleTypeItem *vehicleTypeToRemove = vehicleTypeT->getDatabase()->findVehicleTypeById(ui->Table->item(index.row(), 1)->text());

            // If vehicle was founded AND vehicle is removable
            if((vehicleTypeToRemove != NULL) && (vehicleTypeToRemove->isRemovable()))
            {
                // Erase vehicle of datbase
                delete vehicleTypeToRemove;

                // Update table
                updateTable();
            }
        }
    }
}

void vehicleTypeTableDialog::on_ButtonClose_released()
{

}

void vehicleTypeTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{
    // If vehicle was created, but the button Cancel in VehicleTypeItemDialog was pressed
    if(closeCode == eNetEditorItemDialogCloseCanceled && vt != NULL)
    {
        // Erase created vehicle
        delete vt;
    }

    // Set pointer to vt NULL
    vt = NULL;

    // Update Table
    updateTable();
}
