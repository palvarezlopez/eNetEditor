#ifndef ENETEDITORTOOLDIALOG_H
#define ENETEDITORTOOLDIALOG_H

#include "../eNetEditorDialog.h"


class eNetEditorToolDialog : public eNetEditorDialog
{
public:

    eNetEditorToolDialog(eNetEditorMainWindow *neweNetEditorMainW);

    ~eNetEditorToolDialog();


    // GET FUNCTIONS

    eNetEditorMessages *getMessages() const;

    eNetEditorMainConfiguration *geteNetEditorConfiguration() const;

    eNetEditorProject *getProject() const;

    QVector<QString> *getInputParameters() const;

    QVector<QString> *getOutputParameters() const;

    QVector<QString> *getProcessingParameters() const;


    // SET FUNCTIONS

    void setProject(eNetEditorProject *newProject);


public slots:

    virtual void openDialog(eNetEditorProject *newProject) = 0;

    virtual void resetParameters() = 0;

    virtual void updateParameters() = 0;


private slots:

    virtual void setInputParameters() = 0;

    virtual void setOutputParameters() = 0;

    virtual void setProcessingParameters() = 0;

    virtual void on_ButtonAccept_released() = 0;

    virtual void on_ButtonCancel_released() = 0;

    virtual void on_ButtonReset_released() = 0;


private:

    // Pointer to main eNetEditorDialog
    eNetEditorMainWindow *eNetEditorD;

    // Pointer to Project
    eNetEditorProject *project;

    // List with the input parameters
    QVector<QString> *inputParameters;

    // List with the output parameters
    QVector<QString> *outputParameters;

    // List with the processing parameters
    QVector<QString> *processingParameters;
};

#endif // ENETEDITORTOOLDIALOG_H
