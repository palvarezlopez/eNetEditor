#ifndef ENETEDITORTABLEDIALOG_H
#define ENETEDITORTABLEDIALOG_H

#include "../eNetEditorDialog.h"


class eNetEditorTableDialog : public eNetEditorDialog
{
public:

    eNetEditorTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~eNetEditorTableDialog();


public slots:

    virtual void openTableDialog(eNetEditorTable *table) = 0;

    virtual void updateTable() = 0;


private slots:

    virtual void on_Table_doubleClicked(const QModelIndex &index) = 0;

    virtual void on_ButtonClose_released() = 0;

    virtual void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode) = 0;


private:
};

#endif // ENETEDITORTABLEDIALOG_H
