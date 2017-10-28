#ifndef ENETEDITORCONFIGURATIONDIALOG_H
#define ENETEDITORCONFIGURATIONDIALOG_H

#include "../eNetEditorDialog.h"


namespace Ui
{
class eNetEditorConfigurationDialog;
}

class eNetEditorConfigurationDialog : public eNetEditorDialog
{
    Q_OBJECT

public:

    explicit eNetEditorConfigurationDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~eNetEditorConfigurationDialog();


public slots:

    void openDialog();


private slots:

    void on_ButtonSearchSimulator_released();

    void on_ButtonSearchNetconvert_released();

    void on_ButtonSearchNetgenerate_released();

    void on_ButtonSearchDfrouter_released();

    void on_ButtonSearchDuarouter_released();

    void on_ButtonSearchJtrrouter_released();

    void on_ButtonSearchCadyts_released();

    void on_ButtonAccept_released();


private:

    // Interface
    Ui::eNetEditorConfigurationDialog *ui;
};

#endif
