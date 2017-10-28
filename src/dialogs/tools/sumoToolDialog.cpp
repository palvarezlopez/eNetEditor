#include "sumoToolDialog.h"
#include "ui_sumoToolDialog.h"

// Project
#include "../../project/eNetEditorProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// sumo Tool
#include "../../tools/sumoTool.h"


sumoToolDialog::sumoToolDialog(eNetEditorMainWindow *neweNetEditorMainW) : eNetEditorToolDialog(neweNetEditorMainW), ui(new Ui::sumoToolDialog)
{
    // Set UI
    ui->setupUi(this);

    // Create tool
    sumoT = new sumoTool(getMessages(), geteNetEditorConfiguration(), this);
}

sumoToolDialog::~sumoToolDialog()
{
    // Delete UI
    delete ui;

    // Delete Tool
    delete sumoT;
}

void sumoToolDialog::openDialog(eNetEditorProject *newProject)
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

void sumoToolDialog::on_ButtonAccept_released()
{

}

void sumoToolDialog::on_ButtonCancel_released()
{
    // Close dialog
    close();
}

void sumoToolDialog::on_ButtonReset_released()
{
    // Reset all parameters of tool
    resetParameters();

    // Update all widgets
    updateParameters();
}
