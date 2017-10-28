#include "chargingStationTableDialog.h"
#include "ui_chargingStationTableDialog.h"

#include "../../../database/stops/chargingStationTable.h"

#include "../../items/stops/chargingStationItemDialog.h"


chargingStationTableDialog::chargingStationTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::chargingStationTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create chargin station dialog (parent is eNetEditorMain Window)
    chargingStationItemD = new chargingStationItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    chargingStationT = NULL;
}

chargingStationTableDialog::~chargingStationTableDialog()
{
    // Delete uI
    delete ui;

    // Delete charing station dialog
    delete chargingStationItemD;
}

chargingStationItemDialog *chargingStationTableDialog::getChargingStationItemDialog() const
{
    return chargingStationItemD;
}

void chargingStationTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    chargingStationT = dynamic_cast<chargingStationTable *>(table);

    // If table is valid
    if (chargingStationT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(chargingStationItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void chargingStationTableDialog::updateTable()
{

}

void chargingStationTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void chargingStationTableDialog::on_ButtonClose_released()
{

}

void chargingStationTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
