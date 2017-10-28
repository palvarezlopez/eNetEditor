#ifndef ABSTRACTPROJECTDIALOG_H
#define ABSTRACTPROJECTDIALOG_H

#include "../eNetEditorDialog.h"


class abstractProjectDialog : public eNetEditorDialog
{
public:

    abstractProjectDialog(eNetEditorMainWindow *eNetEditorMainW);

    virtual ~abstractProjectDialog();


    eNetEditorProject *getProject();

    void setProject(eNetEditorProject *newProject);


public slots:

    virtual void resetParameters() = 0;

    virtual void updateParameters() = 0;

    virtual void openDialog(eNetEditorProject *newProject) = 0;


private slots:

    virtual void on_ButtonAccept_released() = 0;

    virtual void on_ButtonCancel_released() = 0;

    virtual void on_ButtonReset_released() = 0;


private:

    eNetEditorProject *project;
};

#endif // ABSTRACTPROJECTDIALOG_H
