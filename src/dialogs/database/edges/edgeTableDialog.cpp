#include "edgeTableDialog.h"
#include "ui_edgeTableDialog.h"

// Database
#include "../../../database/eNetEditorDatabase.h"

// Project
#include "../../../project/eNetEditorProject.h"

// Scene project
#include "../../../project/eNetEditorScene.h"

// Item Dialog
#include "../../items/edges/edgeItemDialog.h"

// Table
#include "../../../database/edges/edgeTable.h"

// Item
#include "../../../items/edges/edgeTypeItem.h"


edgeTableDialog::edgeTableDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractEdgeTableDialog(eNetEditorMainW), ui(new Ui::edgeTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create edge dialog (parent is eNetEditorMain Window)
    edgeItemD = new edgeItemDialog(eNetEditorMainW);

    // Set table pointer to NULL
    edgeT = NULL;
}

edgeTableDialog::~edgeTableDialog()
{
    // Delete UI
    delete ui;

    // Delete edge Dialog
    delete edgeItemD;
}

edgeItemDialog *edgeTableDialog::getEdgeItemDialog() const
{
    return edgeItemD;
}

void edgeTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    edgeT = dynamic_cast<edgeTable *>(table);

    // If table is valid
    if (edgeT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(edgeItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void edgeTableDialog::updateTable()
{

}

void edgeTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void edgeTableDialog::on_ButtonClose_released()
{

}

void edgeTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
