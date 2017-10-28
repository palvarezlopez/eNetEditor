#ifndef SUMOSIMULATORDIALOG_H
#define SUMOSIMULATORDIALOG_H

#include "eNetEditorToolDialog.h"


namespace Ui
{
class sumoToolDialog;
}

class sumoToolDialog : public eNetEditorToolDialog
{
    Q_OBJECT

public:

    explicit sumoToolDialog(eNetEditorMainWindow *neweNetEditorMainW);

    ~sumoToolDialog();


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
    Ui::sumoToolDialog *ui;

    // sumo Tool
    sumoTool *sumoT;

};

#endif // SUMOSIMULATORDIALOG_H
