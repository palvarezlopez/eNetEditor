#ifndef NETGENERATORDIALOG_H
#define NETGENERATORDIALOG_H

#include "eNetEditorToolDialog.h"


namespace Ui
{
class netGenerateToolDialog;
}

class netGenerateToolDialog : public eNetEditorToolDialog
{
    Q_OBJECT

public:

    explicit netGenerateToolDialog(eNetEditorMainWindow *neweNetEditorMainW);

    ~netGenerateToolDialog();


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
    Ui::netGenerateToolDialog *ui;

    // netGenerate Tool
    netGenerateTool *netGenerateT;
};

#endif // NETGENERATORDIALOG_H
