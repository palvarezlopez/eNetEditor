#ifndef ABSTRACTTURNRATIOTABLEDIALOG_H
#define ABSTRACTTURNRATIOTABLEDIALOG_H

#include "../eNetEditorTableDialog.h"


class abstractTurnRatioTableDialog : public eNetEditorTableDialog
{
public:

    abstractTurnRatioTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    virtual ~abstractTurnRatioTableDialog();


public slots:

    virtual void openTableDialog(eNetEditorTable *table) = 0;

    virtual void updateTable() = 0;



private slots:

    virtual void on_Table_doubleClicked(const QModelIndex &index) = 0;

    virtual void on_ButtonClose_released() = 0;

    virtual void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode) = 0;


private:
};

#endif // ABSTRACTTURNRATIOTABLEDIALOG_H
