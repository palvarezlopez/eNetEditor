#include "inductionLoopsE1DetectorTableDialog.h"
#include "ui_inductionLoopsE1DetectorTableDialog.h"

#include "../../../database/detectors/inductionLoopsE1DetectorTable.h"

#include "../../items/detectors/inductionLoopsE1DetectorItemDialog.h"


inductionLoopsE1DetectorTableDialog::inductionLoopsE1DetectorTableDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractDetectorTableDialog(eNetEditorMainW), ui(new Ui::inductionLoopsE1DetectorTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create inductionLoopsE1DetectorItemDialog (parent is eNetEditorMain Window)
    inductionLoopsE1DetectorItemD = new inductionLoopsE1DetectorItemDialog(eNetEditorMainW);

    // Set table pointer to NULL
    inductionLoopsE1DetectorT = NULL;
}

inductionLoopsE1DetectorTableDialog::~inductionLoopsE1DetectorTableDialog()
{
    // Delete UI
    delete ui;

    // Delete inductionLoopsE1DetectorItemDialog
    delete inductionLoopsE1DetectorItemD;
}

inductionLoopsE1DetectorItemDialog *inductionLoopsE1DetectorTableDialog::getInductionLoopsE1DetectorItemDialog()
{
    return inductionLoopsE1DetectorItemD;
}

void inductionLoopsE1DetectorTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    inductionLoopsE1DetectorT = dynamic_cast<inductionLoopsE1DetectorTable *>(table);

    // If table is valid
    if (inductionLoopsE1DetectorT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(inductionLoopsE1DetectorItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void inductionLoopsE1DetectorTableDialog::updateTable()
{

}

void inductionLoopsE1DetectorTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void inductionLoopsE1DetectorTableDialog::on_ButtonClose_released()
{

}

void inductionLoopsE1DetectorTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
