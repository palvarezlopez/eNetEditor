#include "nodeTableDialog.h"
#include "ui_nodeTableDialogledialog.h"

#include "../../database/nodeTable.h"

#include "../items/nodeItemDialog.h"



nodeTableDialog::nodeTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::nodeTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create node Item Dialog (parent is eNetEditorMain Window)
    nodeItemD = new nodeItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    nodeT = NULL;
}

nodeTableDialog::~nodeTableDialog()
{
    // Delete UI
    delete ui;

    // Delete nodeItemDialog
    delete nodeItemD;
}

nodeItemDialog *nodeTableDialog::getNodeItemDialog() const
{
    return nodeItemD;
}

void nodeTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    nodeT = dynamic_cast<nodeTable *>(table);

    // If table is valid
    if (nodeT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(nodeItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void nodeTableDialog::updateTable()
{

}

void nodeTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void nodeTableDialog::on_ButtonClose_released()
{

}

void nodeTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
