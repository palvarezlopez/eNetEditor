#ifndef EDGETABLEDIALOG_H
#define EDGETABLEDIALOG_H

#include "abstractEdgeTableDialog.h"


namespace Ui
{
class edgeTableDialog;
}

class edgeTableDialog : public abstractEdgeTableDialog
{
    Q_OBJECT

public:

    explicit edgeTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~edgeTableDialog();

    // Función terminada y documentada
    edgeItemDialog *getEdgeItemDialog() const;


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    // UI
    Ui::edgeTableDialog *ui;

    // Edge item Dialog
    edgeItemDialog *edgeItemD;

    // Edge Table Dialog
    edgeTable *edgeT;
};

#endif // SETTYPESDIALOG_H
