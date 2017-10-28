#ifndef INDUCTIONLOOPSDETECTORE1ITEMTABLEDIALOG_H
#define INDUCTIONLOOPSDETECTORE1ITEMTABLEDIALOG_H

#include "abstractDetectorTableDialog.h"


namespace Ui
{
class inductionLoopsE1DetectorTableDialog;
}

class inductionLoopsE1DetectorTableDialog : public abstractDetectorTableDialog
{
    Q_OBJECT

public:

    explicit inductionLoopsE1DetectorTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~inductionLoopsE1DetectorTableDialog();

    // Función terminada y documentada
    inductionLoopsE1DetectorItemDialog *getInductionLoopsE1DetectorItemDialog();


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::inductionLoopsE1DetectorTableDialog *ui;

    inductionLoopsE1DetectorItemDialog *inductionLoopsE1DetectorItemD;

    inductionLoopsE1DetectorTable *inductionLoopsE1DetectorT;
};

#endif // INDUCTIONLOOPSDETECTORE1ITEMTABLEDIALOG_H
