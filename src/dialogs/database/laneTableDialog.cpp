#include "laneTableDialog.h"
#include "ui_laneTableDialog.h"

#include "../../database/laneTable.h"

#include "../items/laneItemDialog.h"


laneTableDialog::laneTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::laneTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create lane item dialog (parent is eNetEditorMain Window)
    laneItemD = new laneItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    laneT = NULL;
}

laneTableDialog::~laneTableDialog()
{
    // Delete UI
    delete ui;

    // Delete lane Dialog
    delete laneItemD;
}

laneItemDialog *laneTableDialog::getLaneItemDialog() const
{
    return laneItemD;
}


void laneTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    laneT = dynamic_cast<laneTable *>(table);

    // If table is valid
    if (laneT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(laneItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void laneTableDialog::updateTable()
{

}

void laneTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void laneTableDialog::on_ButtonClose_released()
{

}

void laneTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
