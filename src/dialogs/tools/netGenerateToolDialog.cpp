#include "netGenerateToolDialog.h"
#include "ui_netGenerateToolDialog.h"

// Project
#include "../../project/eNetEditorProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// netGenerate Tool
#include "../../tools/netGenerateTool.h"


netGenerateToolDialog::netGenerateToolDialog(eNetEditorMainWindow *neweNetEditorMainW) : eNetEditorToolDialog(neweNetEditorMainW), ui(new Ui::netGenerateToolDialog)
{
    // Set UI
    ui->setupUi(this);

    // Create tool
    netGenerateT = new netGenerateTool(getMessages(), geteNetEditorConfiguration(), this);
}

netGenerateToolDialog::~netGenerateToolDialog()
{
    // Delete UI
    delete ui;

    // Delete Tool
    delete netGenerateT;
}


void netGenerateToolDialog::openDialog(eNetEditorProject *newProject)
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

void netGenerateToolDialog::on_ButtonAccept_released()
{

}

void netGenerateToolDialog::on_ButtonCancel_released()
{
    // Close dialog
    close();
}

void netGenerateToolDialog::on_ButtonReset_released()
{
    // Reset all parameters of tool
    resetParameters();

    // Update all widgets
    updateParameters();
}
