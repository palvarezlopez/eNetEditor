#ifndef NODETABLEDIALOG_H
#define NODETABLEDIALOG_H

#include "eNetEditorTableDialog.h"


namespace Ui
{
class nodeTableDialog;
}

class nodeTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit nodeTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~nodeTableDialog();

    // Función terminada y documentada
    nodeItemDialog *getNodeItemDialog() const;


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::nodeTableDialog *ui;

    nodeItemDialog *nodeItemD;

    nodeTable *nodeT;
};

#endif // NODETABLEDIALOG_H
