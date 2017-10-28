#include "eNetEditorToolDialog.h"

#include "../main/eNetEditorMainWindow.h"

eNetEditorToolDialog::eNetEditorToolDialog(eNetEditorMainWindow *neweNetEditorMainW) : eNetEditorDialog(neweNetEditorMainW)
{
    // Link eNetEditorDialog
    eNetEditorD = neweNetEditorMainW;

    // By default pointer to project is NULL
    project = NULL;

    // Create list with the input parameters
    inputParameters = new QVector<QString>;

    // Create lith the output parameters
    outputParameters = new QVector<QString>;

    // LCreate lith the processing parameters
    processingParameters = new QVector<QString>;
}

eNetEditorToolDialog::~eNetEditorToolDialog()
{
    // Delete lists
    delete inputParameters;
    delete outputParameters;
    delete processingParameters;
}

eNetEditorMessages *eNetEditorToolDialog::getMessages() const
{
    return eNetEditorD->getMessages();
}

eNetEditorMainConfiguration *eNetEditorToolDialog::geteNetEditorConfiguration() const
{
    return eNetEditorD->geteNetEditorConfiguration();
}

eNetEditorProject *eNetEditorToolDialog::getProject() const
{
    return project;
}

QVector<QString> *eNetEditorToolDialog::getInputParameters() const
{
    return inputParameters;
}

QVector<QString> *eNetEditorToolDialog::getOutputParameters() const
{
    return outputParameters;
}

QVector<QString> *eNetEditorToolDialog::getProcessingParameters() const
{
    return processingParameters;
}

void eNetEditorToolDialog::setProject(eNetEditorProject *newProject)
{
    project = newProject;
}
