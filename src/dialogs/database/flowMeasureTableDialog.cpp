#include "flowMeasureTableDialog.h"
#include "ui_flowMeasureTableDialog.h"

#include "../../database/flowMeasureTable.h"

#include "../items/flowMeasureItemDialog.h"


flowMeasureTableDialog::flowMeasureTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::flowMeasureTableDialog)
{
    // Create ui
    ui->setupUi(this);

    // Create flowMeasureItemDialog (parent is eNetEditorMain Window)
    flowMeasureItemD = new flowMeasureItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    flowMeasureT = NULL;
}

flowMeasureTableDialog::~flowMeasureTableDialog()
{
    // Delete UI
    delete ui;

    // Delete flowMeasureItemDialog
    delete flowMeasureItemD;
}

flowMeasureItemDialog *flowMeasureTableDialog::getFlowMeasureItemDialog()
{
    return flowMeasureItemD;
}

void flowMeasureTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    flowMeasureT = dynamic_cast<flowMeasureTable *>(table);

    // If table is valid
    if (flowMeasureT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(flowMeasureItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void flowMeasureTableDialog::updateTable()
{

}

void flowMeasureTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void flowMeasureTableDialog::on_ButtonClose_released()
{

}

void flowMeasureTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
