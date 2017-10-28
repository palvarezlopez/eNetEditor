#include "multiEntryExitE3DetectorTableDialog.h"
#include "ui_multiEntryExitE3DetectorTableDialog.h"

#include "../../../database/detectors/multiEntryExitE3DetectorTable.h"

#include "../../items/detectors/multiEntryExitE3DetectorItemDialog.h"


multiEntryExitE3DetectorTableDialog::multiEntryExitE3DetectorTableDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractDetectorTableDialog(eNetEditorMainW), ui(new Ui::multiEntryExitE3DetectorTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create multiEntryExitE3DetectorTableDialog (parent is eNetEditorMain Window)
    multiEntryExitE3DetectorItemD = new multiEntryExitE3DetectorItemDialog(eNetEditorMainW);

    // Set table pointer to NULL
    multiEntryExitE3DetectorT = NULL;
}

multiEntryExitE3DetectorTableDialog::~multiEntryExitE3DetectorTableDialog()
{
    // Delet UI
    delete ui;

    // Delete multiEntryExitE3DetectorTableDialog
    delete multiEntryExitE3DetectorItemD;
}

multiEntryExitE3DetectorItemDialog *multiEntryExitE3DetectorTableDialog::getMultiEntryExitE3DetectorItemDialog()
{
    return multiEntryExitE3DetectorItemD;
}

void multiEntryExitE3DetectorTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    multiEntryExitE3DetectorT = dynamic_cast<multiEntryExitE3DetectorTable *>(table);

    // If table is valid
    if (multiEntryExitE3DetectorT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(multiEntryExitE3DetectorItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void multiEntryExitE3DetectorTableDialog::updateTable()
{

}

void multiEntryExitE3DetectorTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void multiEntryExitE3DetectorTableDialog::on_ButtonClose_released()
{

}

void multiEntryExitE3DetectorTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
