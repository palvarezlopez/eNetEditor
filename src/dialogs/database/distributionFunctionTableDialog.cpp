#include "distributionFunctionTableDialog.h"
#include "ui_distributionFunctionTableDialog.h"

#include "../../database/distributionFunctionTable.h"

#include "../items/distributionFunctionItemDialog.h"


distributionFunctionTableDialog::distributionFunctionTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::distributionFunctionTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create distributionFunctionItemDialog (parent is eNetEditorMain Window)
    distributionFunctionD = new distributionFunctionItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    distributionFunctionT = NULL;
}

distributionFunctionTableDialog::~distributionFunctionTableDialog()
{
    // Delete UI
    delete ui;

    // Delete distributionFunctionItemDialog
    delete distributionFunctionD;
}

distributionFunctionItemDialog *distributionFunctionTableDialog::getDistributionFunctionItemDialog()
{
    return distributionFunctionD;
}

void distributionFunctionTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    distributionFunctionT = dynamic_cast<distributionFunctionTable *>(table);

    // If table is valid
    if (distributionFunctionT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(distributionFunctionD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void distributionFunctionTableDialog::updateTable()
{

}

void distributionFunctionTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void distributionFunctionTableDialog::on_ButtonClose_released()
{

}

void distributionFunctionTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
