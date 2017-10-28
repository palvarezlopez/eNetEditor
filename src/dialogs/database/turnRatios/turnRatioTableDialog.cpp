#include "turnRatioTableDialog.h"
#include "ui_turnRatioTableDialog.h"

// Database
#include "../../../database/eNetEditorDatabase.h"

// Project
#include "../../../project/eNetEditorProject.h"

// Scene project
#include "../../../project/eNetEditorScene.h"

// Table
#include "../../../database/turnRatios/turnRatioTable.h"

// Items
#include "../../items/turnRatios/turnRatioItemDialog.h"



turnRatioTableDialog::turnRatioTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::turnRatioTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create turnRatioItemDialog
    turnRatioItemD = new turnRatioItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    turnRatioT = NULL;
}

turnRatioTableDialog::~turnRatioTableDialog()
{
    // Delete UI
    delete ui;
}

turnRatioItemDialog *turnRatioTableDialog::getTurnRatioItemDialog()
{
    return turnRatioItemD;
}

void turnRatioTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    turnRatioT = dynamic_cast<turnRatioTable *>(table);

    // If table is valid
    if (turnRatioT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(turnRatioItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void turnRatioTableDialog::updateTable()
{

}

void turnRatioTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void turnRatioTableDialog::on_ButtonClose_released()
{

}

void turnRatioTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
