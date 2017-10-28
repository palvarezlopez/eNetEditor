#ifndef CADYTSDIALOG_H
#define CADYTSDIALOG_H

#include "eNetEditorToolDialog.h"


namespace Ui
{
class cadytsToolDialog;
}

class cadytsToolDialog : public eNetEditorToolDialog
{
    Q_OBJECT

public:

    explicit cadytsToolDialog(eNetEditorMainWindow *neweNetEditorMainW);

    ~cadytsToolDialog();


public slots:

    void openDialog(eNetEditorProject *newProject);

    void resetParameters()
    {

    }

    void updateParameters()
    {

    }


private slots:

    void setInputParameters()
    {

    }

    void setOutputParameters()
    {

    }

    void setProcessingParameters()
    {

    }

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_ButtonReset_released();


private:

    // UI
    Ui::cadytsToolDialog *ui;

    // cadyts Tool
    cadytsTool *cadytsT;

    // PARAMETERS
};

#endif // CADYTSDIALOG_H
