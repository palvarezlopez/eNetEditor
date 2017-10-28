#ifndef TURNRATIOINTERVALTABLEDIALOG_H
#define TURNRATIOINTERVALTABLEDIALOG_H

#include "abstractTurnRatioTableDialog.h"


namespace Ui
{
class turnRatioIntervalTableDialog;
}

class turnRatioIntervalTableDialog : public abstractTurnRatioTableDialog
{
    Q_OBJECT

public:

    explicit turnRatioIntervalTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~turnRatioIntervalTableDialog();

    turnRatioIntervalDialog *getTurnRatioIntervalDialog();


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    // UI
    Ui::turnRatioIntervalTableDialog *ui;

    // Turn Ratio New Interval Dialog
    turnRatioIntervalDialog *turnRatioIntervalD;

    //
    turnRatioIntervalTable *turnRatioIntervalT;
};

#endif // TURNRATIOINTERVALTABLEDIALOG_H
