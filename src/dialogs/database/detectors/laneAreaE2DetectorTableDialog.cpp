#include "laneAreaE2DetectorTableDialog.h"
#include "ui_laneAreaE2DetectorTableDialog.h"

#include "../../../database/detectors/laneAreaE2DetectorTable.h"

#include "../../items/detectors/laneAreaE2DetectorItemDialog.h"


laneAreaE2DetectorTableDialog::laneAreaE2DetectorTableDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractDetectorTableDialog(eNetEditorMainW), ui(new Ui::laneAreaE2DetectorTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create laneAreaE2DetectorItemDialog (parent is eNetEditorMain Window)
    laneAreaE2DetectorItemD = new laneAreaE2DetectorItemDialog(eNetEditorMainW);

    // Set table pointer to NULL
    laneAreaE2DetectorT = NULL;
}

laneAreaE2DetectorTableDialog::~laneAreaE2DetectorTableDialog()
{
    // Delete UI
    delete ui;

    // Delete laneAreaE2DetectorItemDialog
    delete laneAreaE2DetectorItemD;
}

laneAreaE2DetectorItemDialog *laneAreaE2DetectorTableDialog::getLaneAreaE2DetectorItemDialog()
{
    return laneAreaE2DetectorItemD;
}

void laneAreaE2DetectorTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    laneAreaE2DetectorT = dynamic_cast<laneAreaE2DetectorTable *>(table);

    // If laneAreaE2DetectorT is valid
    if (laneAreaE2DetectorT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(laneAreaE2DetectorItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void laneAreaE2DetectorTableDialog::updateTable()
{

}

void laneAreaE2DetectorTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void laneAreaE2DetectorTableDialog::on_ButtonClose_released()
{

}

void laneAreaE2DetectorTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
