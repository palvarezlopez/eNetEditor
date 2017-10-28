#ifndef FLOWMEASURETABLEDIALOG_H
#define FLOWMEASURETABLEDIALOG_H

#include "eNetEditorTableDialog.h"


namespace Ui
{
class flowMeasureTableDialog;
}

class flowMeasureTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit flowMeasureTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~flowMeasureTableDialog();

    flowMeasureItemDialog *getFlowMeasureItemDialog();


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::flowMeasureTableDialog *ui;

    flowMeasureItemDialog *flowMeasureItemD;

    flowMeasureTable *flowMeasureT;
};

#endif // FLOWMEASURETABLEDIALOG_H
