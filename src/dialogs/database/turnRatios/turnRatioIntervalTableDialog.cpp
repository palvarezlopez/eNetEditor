#include "turnRatioIntervalTableDialog.h"
#include "ui_turnRatioIntervalTableDialog.h"

// Main Window
#include "../../main/eNetEditorMainWindow.h"

// Project Dialog
#include "../../project/eNetEditorProjectDialog.h"

// Table
#include "../../../database/turnRatios/turnRatioIntervalTable.h"

// Dialogs
#include "../../items/turnRatios/turnRatioIntervalDialog.h"


turnRatioIntervalTableDialog::turnRatioIntervalTableDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractTurnRatioTableDialog(eNetEditorMainW), ui(new Ui::turnRatioIntervalTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create turnRatioIntervalDialog
    turnRatioIntervalD = new turnRatioIntervalDialog(eNetEditorMainW);

    // Set pointer table to NULL
    turnRatioIntervalT = NULL;

    // Connects Signal of turnRatioItemDialog
    connect(turnRatioIntervalD, SIGNAL(dialogClosed(eNetEditorItemDialogCloseType)), geteNetEditorMainWindow()->geteNetEditorProjectDialog(), SLOT(afterTurnRatioIntervalDialogClosed(eNetEditorItemDialogCloseType)));
}

turnRatioIntervalTableDialog::~turnRatioIntervalTableDialog()
{
    // Delete UI
    delete ui;

    // Delete dialog
    delete turnRatioIntervalD;
}

turnRatioIntervalDialog *turnRatioIntervalTableDialog::getTurnRatioIntervalDialog()
{
    return turnRatioIntervalD;
}

void turnRatioIntervalTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    turnRatioIntervalT = dynamic_cast<turnRatioIntervalTable *>(table);

    // If table is valid
    if (turnRatioIntervalT)
    {
        // Connect finished signal of dialog with updateTable()
        connect(turnRatioIntervalD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void turnRatioIntervalTableDialog::updateTable()
{

}

void turnRatioIntervalTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void turnRatioIntervalTableDialog::on_ButtonClose_released()
{

}

void turnRatioIntervalTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
