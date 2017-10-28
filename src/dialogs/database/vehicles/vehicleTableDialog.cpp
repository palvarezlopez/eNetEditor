#include "vehicleTableDialog.h"
#include "ui_vehicleTableDialog.h"

// Database
#include "../../../database/eNetEditorDatabase.h"
#include "../../../database/vehicles/vehicleTable.h"

// NetEditor project
#include "../../../project/eNetEditorProject.h"

// Scene project
#include "../../../project/eNetEditorScene.h"

// Item Dialog
#include "../../items/routeItemDialog.h"
#include "../../items/vehicles/vehicleItemDialog.h"

// Item
#include "../../../items/vehicles/vehicleItem.h"


vehicleTableDialog::vehicleTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::vehicleTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create vehicleItemDialog (parent is eNetEditorMain Window)
    vehicleItemD = new vehicleItemDialog(eNetEditorMainW);
}

vehicleTableDialog::~vehicleTableDialog()
{
    // Delete UI
    delete ui;

    // Delete vehicle Dialog
    delete vehicleItemD;
}

vehicleItemDialog *vehicleTableDialog::getVehicleItemDialog()
{
    return vehicleItemD;
}

void vehicleTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    vehicleT = dynamic_cast<vehicleTable *>(table);

    // If table is valid
    if (vehicleT)
    {
        // Link item dialog
        //vehicleItemD = getProject()->geteNetEditorScene()->getRouteItemDialog()->getVehicleDialog();

        // Connect finished signal of dialog with updateTable()
        //connect(vehicleItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void vehicleTableDialog::updateTable()
{
    // Add rows
    ui->Table->setRowCount(vehicleT->getDatabase()->getVehicleTable()->getNumberOfItems() + 1);
}

void vehicleTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void vehicleTableDialog::on_ButtonClose_released()
{

}

void vehicleTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
