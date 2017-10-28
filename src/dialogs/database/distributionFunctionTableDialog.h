#ifndef DISTRIBUTIONFUNCTIONTABLEDIALOG_H
#define DISTRIBUTIONFUNCTIONTABLEDIALOG_H

#include "eNetEditorTableDialog.h"


namespace Ui
{
class distributionFunctionTableDialog;
}

class distributionFunctionTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit distributionFunctionTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~distributionFunctionTableDialog();

    distributionFunctionItemDialog *getDistributionFunctionItemDialog();


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::distributionFunctionTableDialog *ui;

    distributionFunctionItemDialog *distributionFunctionD;

    distributionFunctionTable *distributionFunctionT;
};

#endif // DISTRIBUTIONFUNCTIONTABLEDIALOG_H
