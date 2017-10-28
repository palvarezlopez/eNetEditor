#ifndef FLOWSTABLEDIALOG_H
#define FLOWSTABLEDIALOG_H

#include "../eNetEditorTableDialog.h"


namespace Ui
{
class flowTableDialog;
}

class flowTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit flowTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~flowTableDialog();

    flowItemDialog *getFlowItemDialog();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    // UI
    Ui::flowTableDialog *ui;

    // Flow Dialog
    flowItemDialog *flowItemD;

    //
    flowTable *flowT;
};

#endif // SETFLOWSDIALOG_H
