#ifndef PROHIBITIONTABLEDIALOG_H
#define PROHIBITIONTABLEDIALOG_H

#include "eNetEditorTableDialog.h"


namespace Ui
{
class prohibitionTableDialog;
}

class prohibitionTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit prohibitionTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~prohibitionTableDialog();

    // Función terminada y documentada
    prohibitionItemDialog *getProhibitionItemDialog() const;


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::prohibitionTableDialog *ui;

    prohibitionItemDialog *prohibitionItemD;

    prohibitionTable *prohibitionT;
};

#endif // PROHIBITIONTABLEDIALOG_H
