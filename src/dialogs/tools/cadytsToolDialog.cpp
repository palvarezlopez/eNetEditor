#include "cadytsToolDialog.h"
#include "ui_cadytsToolDialog.h"

// Project
#include "../../project/eNetEditorProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// Cadyts Tool
#include "../../tools/cadytsTool.h"


cadytsToolDialog::cadytsToolDialog(eNetEditorMainWindow *neweNetEditorMainW) : eNetEditorToolDialog(neweNetEditorMainW), ui(new Ui::cadytsToolDialog)
{
    // Set UI
    ui->setupUi(this);

    // Create tool
    cadytsT = new cadytsTool(getMessages(), geteNetEditorConfiguration(), this);
}

cadytsToolDialog::~cadytsToolDialog()
{
    // Delete UI
    delete ui;

    // Delete tool
    delete cadytsT;
}


void cadytsToolDialog::openDialog(eNetEditorProject *newProject)
{
    // If pointer to project isn't NULL
    if(newProject != NULL)
    {
        // Link project
        setProject(newProject);

        // Reset parameters
        resetParameters();

        // Update Parameters in all Textbox, Checkboxs, etc...
        updateParameters();

        // Open Dialog
        show();
    }
}

void cadytsToolDialog::on_ButtonAccept_released()
{

}

void cadytsToolDialog::on_ButtonCancel_released()
{
    // Close dialog
    close();
}

void cadytsToolDialog::on_ButtonReset_released()
{
    // Reset all parameters of tool
    resetParameters();

    // Update all widgets
    updateParameters();
}
