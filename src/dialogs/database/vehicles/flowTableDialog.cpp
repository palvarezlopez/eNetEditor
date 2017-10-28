#include "flowTableDialog.h"
#include "ui_flowTableDialog.h"

// Database
#include "../../../database/eNetEditorDatabase.h"

// Project
#include "../../../project/eNetEditorProject.h"

// Scene project
#include "../../../project/eNetEditorScene.h"

// Item Dialog
#include "../../items/routeItemDialog.h"
#include "../../items/vehicles/flowItemDialog.h"

// Tables
#include "../../../database/vehicles/flowTable.h"

// Item
#include "../../../items/vehicles/flowItem.h"


flowTableDialog::flowTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::flowTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create flowItemDialog (parent is eNetEditorMain Window)
    flowItemD = new flowItemDialog(eNetEditorMainW);
}

flowTableDialog::~flowTableDialog()
{
    // Delete UI
    delete ui;

    // Delete flowItemDialog
    delete flowItemD;
}

flowItemDialog *flowTableDialog::getFlowItemDialog()
{
    return flowItemD;
}

void flowTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void flowTableDialog::on_ButtonClose_released()
{

}

void flowTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    flowT = dynamic_cast<flowTable *>(table);

    // If table is valid
    if (flowT)
    {
        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void flowTableDialog::updateTable()
{

}

void flowTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
