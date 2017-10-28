#ifndef CONNECTIONTABLEDIALOG_H
#define CONNECTIONTABLEDIALOG_H

#include "eNetEditorTableDialog.h"


namespace Ui
{
class connectionTableDialog;
}

class connectionTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit connectionTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~connectionTableDialog();

    // Función terminada y documentada
    connectionItemDialog *getConnectionItemDialog() const;


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::connectionTableDialog *ui;

    connectionItemDialog *connectionItemD;

    connectionTable *connectionT;
};

#endif // CONNECTIONTABLEDIALOG_H
