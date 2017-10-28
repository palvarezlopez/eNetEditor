#include "prohibitionTableDialog.h"
#include "ui_prohibitionTableDialog.h"

#include "../../database/prohibitionTable.h"

#include "../items/prohibitionItemDialog.h"


prohibitionTableDialog::prohibitionTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::prohibitionTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create prohibition dialog (parent is eNetEditorMain Window)
    prohibitionItemD = new prohibitionItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    prohibitionT = NULL;
}

prohibitionTableDialog::~prohibitionTableDialog()
{
    // Delete UI
    delete ui;

    // Delete prohibition dialog
    delete prohibitionItemD;
}

prohibitionItemDialog *prohibitionTableDialog::getProhibitionItemDialog() const
{
    return prohibitionItemD;
}

void prohibitionTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    prohibitionT = dynamic_cast<prohibitionTable *>(table);

    // If table is valid
    if (prohibitionT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(prohibitionItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void prohibitionTableDialog::updateTable()
{

}

void prohibitionTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void prohibitionTableDialog::on_ButtonClose_released()
{

}

void prohibitionTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
