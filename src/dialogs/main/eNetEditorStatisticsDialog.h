#ifndef ENETEDITORSTATISTICSDIALOG_H
#define ENETEDITORSTATISTICSDIALOG_H

#include "../eNetEditorDialog.h"


namespace Ui
{
class eNetEditorStatisticsDialog;
}

class eNetEditorStatisticsDialog : public eNetEditorDialog
{
    Q_OBJECT

public:

    explicit eNetEditorStatisticsDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~eNetEditorStatisticsDialog();


public slots:

    void openDialog(eNetEditorProject *newProject);


private slots:

    void on_ButtonAccept_released();


private:

    // Interface
    Ui::eNetEditorStatisticsDialog *ui;

    // Pointer to Project
    eNetEditorProject *project;
};

#endif // ENETEDITORSTATISTICSDIALOG_H
