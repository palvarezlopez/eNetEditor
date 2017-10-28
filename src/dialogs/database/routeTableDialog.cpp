#include "routeTableDialog.h"
#include "ui_routeTableDialog.h"

#include "../../database/routeTable.h"

#include "../items/routeItemDialog.h"


routeTableDialog::routeTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::routeTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create route Dialog (parent is eNetEditorMain Window)
    routeItemD = new routeItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    routeT = NULL;
}

routeTableDialog::~routeTableDialog()
{
    // Delete UI
    delete ui;

    // Delete Route dialog
    delete routeItemD;
}

routeItemDialog *routeTableDialog::getRouteItemDialog() const
{
    return routeItemD;
}

void routeTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    routeT = dynamic_cast<routeTable *>(table);

    // If table is valid
    if (routeT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(routeItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void routeTableDialog::updateTable()
{

}

void routeTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void routeTableDialog::on_ButtonClose_released()
{

}

void routeTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
