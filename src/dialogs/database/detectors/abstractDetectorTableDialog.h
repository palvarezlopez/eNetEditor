#ifndef DETECTORTABLEDIALOG_H
#define DETECTORTABLEDIALOG_H

#include "../eNetEditorTableDialog.h"


class abstractDetectorTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit abstractDetectorTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    virtual ~abstractDetectorTableDialog();


public slots:

    virtual void openTableDialog(eNetEditorTable *table) = 0;

    virtual void updateTable() = 0;


private slots:

    virtual void on_Table_doubleClicked(const QModelIndex &index) = 0;

    virtual void on_ButtonClose_released() = 0;

    virtual void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode) = 0;


private:

};

#endif // DETECTORTABLEDIALOG_H
