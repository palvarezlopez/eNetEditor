#include "edgeTypeTableDialog.h"
#include "ui_edgeTypeTableDialog.h"

#include "../../../database/edges/edgeTypeTable.h"

#include "../../items/edges/edgeTypeItemDialog.h"


edgeTypeTableDialog::edgeTypeTableDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractEdgeTableDialog(eNetEditorMainW), ui(new Ui::edgeTypeTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create edgeTypeItemDialog (parent is eNetEditorMain Window)
    edgeTypeItemD = new edgeTypeItemDialog(eNetEditorMainW);

    // Set table pointer to NULL
    edgeTypeT = NULL;
}

edgeTypeTableDialog::~edgeTypeTableDialog()
{
    // Delete UI
    delete ui;

    // edgeTypeItemDialog
    delete edgeTypeItemD;
}

edgeTypeItemDialog *edgeTypeTableDialog::getEdgeTypeItemDialog()
{
    return edgeTypeItemD;
}

void edgeTypeTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    edgeTypeT = dynamic_cast<edgeTypeTable *>(table);

    // If table is valid
    if (edgeTypeT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(edgeTypeItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void edgeTypeTableDialog::updateTable()
{

}

void edgeTypeTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void edgeTypeTableDialog::on_ButtonClose_released()
{

}

void edgeTypeTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
