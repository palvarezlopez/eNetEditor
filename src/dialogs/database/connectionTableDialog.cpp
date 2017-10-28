#include "connectionTableDialog.h"
#include "ui_connectionTableDialog.h"

#include "../../database/connectionTable.h"

#include "../items/connectionItemDialog.h"


connectionTableDialog::connectionTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::connectionTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create connection Dialog (parent is eNetEditorMain Window)
    connectionItemD = new connectionItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    connectionT = NULL;
}

connectionTableDialog::~connectionTableDialog()
{
    // Delete UI
    delete ui;

    // delete connection Dialog
    delete connectionItemD;
}

connectionItemDialog *connectionTableDialog::getConnectionItemDialog() const
{
    return connectionItemD;
}

void connectionTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    connectionT = dynamic_cast<connectionTable *>(table);

    // If table is valid
    if (connectionT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(connectionItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void connectionTableDialog::updateTable()
{

}

void connectionTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void connectionTableDialog::on_ButtonClose_released()
{

}

void connectionTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
