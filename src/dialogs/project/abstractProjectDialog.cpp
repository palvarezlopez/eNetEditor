#include "abstractProjectDialog.h"


abstractProjectDialog::abstractProjectDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorDialog(eNetEditorMainW)
{
    // By default, pointer is NULL
    project = NULL;
}

abstractProjectDialog::~abstractProjectDialog()
{
    // Nothing to erase
}

eNetEditorProject *abstractProjectDialog::getProject()
{
    return project;
}

void abstractProjectDialog::setProject(eNetEditorProject *newProject)
{
    project = newProject;
}

