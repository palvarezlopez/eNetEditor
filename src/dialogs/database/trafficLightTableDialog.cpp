#include "trafficLightTableDialog.h"
#include "ui_trafficLightTableDialog.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// NetEditor project
#include "../../project/eNetEditorProject.h"

// Scene project
#include "../../project/eNetEditorScene.h"

// Item Dialog
#include "../items/trafficLightItemDialog.h"

// Table
#include "../../database/trafficLightTable.h"

// Item
#include "../../items/trafficLightItem.h"


trafficLightTableDialog::trafficLightTableDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorTableDialog(eNetEditorMainW), ui(new Ui::trafficLightTableDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create traffic Light dialog (parent is eNetEditorMain Window)
    trafficLightItemD = new trafficLightItemDialog(eNetEditorMainW);

    // Set pointer table to NULL
    trafficLightT = NULL;
}

trafficLightTableDialog::~trafficLightTableDialog()
{
    // Delete UI
    delete ui;

    // Delete traffic light dialog
    delete trafficLightItemD;
}

trafficLightItemDialog *trafficLightTableDialog::getTrafficLightItemDialog() const
{
    return trafficLightItemD;
}

void trafficLightTableDialog::openTableDialog(eNetEditorTable *table)
{
    // Cast table
    trafficLightT = dynamic_cast<trafficLightTable *>(table);

    // If table is valid
    if (trafficLightT)
    {
        // Link item dialog
        //trafficLightItemD = getProject()->geteNetEditorScene()->getTrafficLightItemDialog();

        // Connect finished signal of dialog with updateTable()
        connect(trafficLightItemD, SIGNAL(finished(int)), this, SLOT(updateTable()));

        // Fill(update) table
        updateTable();

        // Show Dialog
        show();
    }
}

void trafficLightTableDialog::updateTable()
{

}

void trafficLightTableDialog::on_Table_doubleClicked(const QModelIndex &index)
{

}

void trafficLightTableDialog::on_ButtonClose_released()
{

}

void trafficLightTableDialog::afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode)
{

}
