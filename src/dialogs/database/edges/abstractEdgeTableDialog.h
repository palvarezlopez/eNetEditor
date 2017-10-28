#ifndef ABSTRACTEDGETABLEDIALOG_H
#define ABSTRACTEDGETABLEDIALOG_H

#include "../eNetEditorTableDialog.h"


class abstractEdgeTableDialog : public eNetEditorTableDialog
{
public:

    abstractEdgeTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    virtual ~abstractEdgeTableDialog();


public slots:

    virtual void openTableDialog(eNetEditorTable *table) = 0;

    virtual void updateTable() = 0;


private slots:

    virtual void on_Table_doubleClicked(const QModelIndex &index) = 0;

    virtual void on_ButtonClose_released() = 0;

    virtual void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode) = 0;
};

#endif // ENETEDITOREDGETABLEDIALOG_H
