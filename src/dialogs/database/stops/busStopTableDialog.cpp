#include "busStopTableDialog.h"
#include "ui_busStopTableDialog.h"

#include "../../../database/stops/busStopTable.h"

#include "../../items/stops/busStopItemDialog.h"


busStopTableDialog::busStopTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::busStopTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create bus stop dialog (parent is eNetEditorMain Window)
    busStopItemD = new busStopItemDialog(eNetEditorMainW);

    // Set table pointer to NULL
    busStopT = NULL;
}

busStopTableDialog::~busStopTableDialog()
{
    // Delete UI
    delete ui;

    // Delete bus stop dialog
    delete busStopItemD;
}

busStopItemDialog *busStopTableDialog::getBusStopItemDialog() const
{
    return busStopItemD;
}

void busStopTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    busStopT = dynamic_cast<busStopTable *>(table);

    // If table is valid
    if (busStopT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(busStopItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void busStopTableDialog::updateTable()
{

}

void busStopTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void busStopTableDialog::on_ButtonClose_released()
{

}

void busStopTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
