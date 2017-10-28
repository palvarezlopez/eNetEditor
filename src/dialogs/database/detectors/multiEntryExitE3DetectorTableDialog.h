#ifndef MULTIENTRYEXITDETECTORSE3ITEMTABLEDIALOG_H
#define MULTIENTRYEXITDETECTORSE3ITEMTABLEDIALOG_H

#include "abstractDetectorTableDialog.h"


namespace Ui
{
class multiEntryExitE3DetectorTableDialog;
}

class multiEntryExitE3DetectorTableDialog : public abstractDetectorTableDialog
{
    Q_OBJECT

public:

    explicit multiEntryExitE3DetectorTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~multiEntryExitE3DetectorTableDialog();

    // Función terminada y documentada
    multiEntryExitE3DetectorItemDialog *getMultiEntryExitE3DetectorItemDialog();


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::multiEntryExitE3DetectorTableDialog *ui;

    multiEntryExitE3DetectorItemDialog *multiEntryExitE3DetectorItemD;

    multiEntryExitE3DetectorTable *multiEntryExitE3DetectorT;
};

#endif // MULTIENTRYEXITDETECTORSE3ITEMTABLEDIALOG_H
