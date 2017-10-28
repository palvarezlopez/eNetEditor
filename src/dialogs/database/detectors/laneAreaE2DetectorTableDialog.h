#ifndef LANEAREADETECTORE2ITEMTABLEDIALOG_H
#define LANEAREADETECTORE2ITEMTABLEDIALOG_H

#include "abstractDetectorTableDialog.h"


namespace Ui
{
class laneAreaE2DetectorTableDialog;
}

class laneAreaE2DetectorTableDialog : public abstractDetectorTableDialog
{
    Q_OBJECT

public:

    explicit laneAreaE2DetectorTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~laneAreaE2DetectorTableDialog();

    // Función terminada y documentada
    laneAreaE2DetectorItemDialog *getLaneAreaE2DetectorItemDialog();


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::laneAreaE2DetectorTableDialog *ui;

    laneAreaE2DetectorItemDialog *laneAreaE2DetectorItemD;

    laneAreaE2DetectorTable *laneAreaE2DetectorT;
};

#endif // LANEAREADETECTORE2ITEMTABLEDIALOG_H
